// CDecor.cpp
//

#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <ddraw.h>
#include "def.h"
#include "resource.h"
#include "pixmap.h"
#include "sound.h"
#include "decor.h"
#include "text.h"
#include "misc.h"
#include "DECMOVE.h"
#include "event.h"


////////////////////////////////////////////////////////////////////////////////

#define MAXMOVEOBJECT	200
#define MAXQUART		441
#define SCROLL_SPEED	8
#define SCROLL_MARGX	80
#define SCROLL_MARGY	40

#define BLUPIFLOOR		2
#define BLUPIOFFY		4 + BLUPIFLOOR
#define BLUPISURF		12
#define BLUPISUSPEND	12
#define OVERHEIGHT		80

#define TEXTDELAY	   10 // tooltip popup delay

// Constructor
// Possibly incomplete

CDecor::CDecor()
{
	int i;

	// unknown_library_function_2bd90(m_jauges, sizeof(CJauge), 2, CJauge::CJauge);
	m_hWnd = NULL;
	m_pSound = NULL;
	m_pPixmap = NULL;

	for (i = 0; i < 200; i++)
	{
		m_lastDecorIcon[i] = 0;
	}
	m_time = 0;
	m_bCheatDoors = FALSE;
	m_bSuperBlupi = FALSE;
	m_bDrawSecret = FALSE;
	m_buildOfficialMissions = FALSE;
	m_bNetPacked = FALSE;
	m_bNetMovePredict = TRUE;
	m_bNetDebug = FALSE;
	m_bMulti = FALSE;
	m_team = 0;
	m_netPacketsSent = 0;
	m_netPacketsSent2 = 0;
	m_netPacketsReceived = 0;
	m_netPacketsReceived2 = 0;
}

CDecor::~CDecor()
{
	// unknown_library_function_2be30(m_jauges, sizeof(CJauge), 2, OutputDebug);
}

void CDecor::Create(HWND hWnd, CSound* pSound, CPixmap* pPixmap, CNetwork* pNetwork)
{
	POINT pos;

	m_hWnd = hWnd;
	m_pSound = pSound;
	m_pPixmap = pPixmap;
	m_pNetwork = pNetwork;
	m_keyPress = 0;
	m_lastKeyPress = 0;
	m_blupiSpeedX = 0;
	m_bHelicopterFlying = FALSE;
	m_bHelicopterStationary = FALSE;
	m_bCarMoving = FALSE;
	m_bCarStationary = FALSE;
	InitDecor();

	pos.x = 169;
	pos.y = 450;
	m_jauges[0].Create(m_hWnd, m_pPixmap, m_pSound, pos, 1, FALSE);
	m_jauges[0].SetHide(TRUE);
	pos.x += DIMJAUGEX + 2;
	m_jauges[1].Create(m_hWnd, m_pPixmap, m_pSound, pos, 3, FALSE);
	m_jauges[1].SetHide(TRUE);
	FUN_15fa0();
	FlushNotificationMessages();
}

BOOL CDecor::LoadImages()
{
	POINT totalDim, iconDim;
	char filename[52];

	if (m_lastRegion == m_region) return TRUE;
	m_lastRegion = m_region;

	totalDim.x = LXIMAGE;
	totalDim.y = LYIMAGE;
	iconDim.x = 0;
	iconDim.y = 0;
	sprintf(filename, "decor%.3d.blp", m_region);

	return m_pPixmap->Cache1(CHBACK, filename, totalDim, iconDim, 0);
}

void CDecor::InitGamer()
{
	m_nbVies = 3;
	BYTE *ptr = m_doors;
	for (int i = 50; i != 0; i--) {
		*(int *)ptr = 0x01010101;
		ptr += 4;
	}
}

void CDecor::InitDecor()
{
	m_posDecor.x = 0;
	m_posDecor.y = 0;
	m_dimDecor.x = 100;
	m_dimDecor.y = 100;
	m_music = 1;
	m_region = 2;
	m_missionTitle[0] = '\0';
	m_decorAction = 0;
	for (int i = 0; i < MAXCELY; i++)
	{
		for (int j = 0; j < MAXCELX; j++)
		{
			m_decor[i][j].icon = -1;
			m_bigDecor[i][j].icon = -1;
		}
	}
	m_decor[3][4].icon = 40;
	m_decor[4][4].icon = 38;
	m_decor[5][4].icon = 39;
	for (int k = MAXMOVEOBJECT; k != 0; k--)
	{
		m_moveObject[k]->type = 0;
	}
	FlushBalleTraj();
	FlushMoveTraj();
	m_moveObject[0].type = TYPE_TRESOR;
	m_moveObject[0].stepAdvance = 1;
	m_moveObject[0].stepRecede = 1;
	m_moveObject[0].timeStopStart = 0;
	m_moveObject[0].timeStopEnd = 0;
	m_moveObject[0].posStart.x = 258;
	m_moveObject[0].posStart.y = 196;
	m_moveObject[0].posEnd = m_moveObject[0].posStart;
	m_moveObject[0].posCurrent = m_moveObject[0].posStart;
	m_moveObject[0].phase = 0;
	m_moveObject[0].step = STEP_STOPSTART;
	m_moveObject[0].time = 0;
	m_moveObject[0].channel = CHELEMENT;
	m_moveObject[0].icon = 0;

	m_moveObject[1].type = TYPE_GOAL;
	m_moveObject[1].stepAdvance = 1;
	m_moveObject[1].timeStopStart = 0;
	m_moveObject[1].timeStopEnd = 0;
	m_moveObject[1].posStart.x = 450;
	m_moveObject[1].posStart.y = 196;
	m_moveObject[1].posEnd = m_moveObject[1].posStart;
	m_moveObject[1].posCurrent = m_moveObject[1].posStart;
	m_moveObject[1].phase = 0;
	m_moveObject[1].step = STEP_STOPSTART;
	m_moveObject[1].time = 0;
	m_moveObject[1].channel = CHELEMENT;
	m_moveObject[1].icon = 29;
	//TODO: iterate setting blupi fifo positions
	m_blupiStartPos.x = 66;
	m_blupiStartPos.y = 192 + BLUPIOFFY;
	m_blupiStartDir = DIR_RIGHT;
	m_blupiAction = ACTION_STOP;
	m_blupiPhase = 0;
	m_blupiIcon = 0;
	m_blupiChannel = 2;
	m_blupiFocus = TRUE;
	m_blupiAir = FALSE;
	m_blupiHelico = FALSE;
	m_blupiOver = FALSE;
	m_blupiJeep = FALSE;
	m_blupiTank = FALSE;
	m_blupiSkate = FALSE;
	m_blupiNage = FALSE;
	m_blupiSurf = FALSE;
	m_blupiSuspend = FALSE;
	m_blupiJumpAie = FALSE;
	m_blupiShield = FALSE;
	m_blupiPower = FALSE;
	m_blupiCloud = FALSE;
	m_blupiHide = FALSE;
	m_blupiInvert = FALSE;
	m_blupiBalloon = FALSE;
	m_blupiEcrase = FALSE;
	m_blupiPosHelico.x = -1;
	m_blupiActionOuf = 0;
	m_blupiTimeNoAsc = 0;
	m_blupiTimeMockery = 0;
	m_blupiVitesse.x = 0;
	m_blupiVitesse.y = 0;
	m_blupiValidPos = m_blupiStartPos;
	m_blupiEnergyUnused = 100;
	m_blupiFront = FALSE;
	m_blupiBullet = 0;
	m_blupiCle = 0;
	m_blupiPerso = 0;
	m_blupiDynamite = 0;
	m_nbTresor = 0;
	m_totalTresor = 1;
	m_goalPhase = 0;
	m_scrollPoint = m_blupiStartPos;
	m_scrollAdd.x = 0;
	m_scrollAdd.y = 0;
	m_term = 0;
	m_CC20 = -1;
}

void CDecor::SetTime(int time)
{
	m_time = time;
}

int CDecor::GetTime()
{
	return m_time;
}

void CDecor::PlayPrepare(BOOL bTest)
{
	if (bTest)
	{
		m_nbVies = 3;
	}

	if (!m_bMulti) {
		m_blupiPos = m_blupiStartPos;
		m_blupiDir = m_blupiStartDir;
	}
	else
	{
		/* todo: set depending on team
		m_nbVies = 10;
		m_blupiPos = m_blupiStartPos;
		m_blupiDir = m_blupiStartDir;
		*/

	}
	if (m_blupiDir == DIR_LEFT)
	{
		m_blupiIcon = 4;
	}
	else
	{
		m_blupiIcon = 0;
	}
	m_blupiAction = ACTION_STOP;
	m_blupiPhase = 0;
	m_blupiFocus = TRUE;
	m_blupiAir = FALSE;
	m_blupiHelico = FALSE;
	m_blupiOver = FALSE;
	m_blupiJeep = FALSE;
	m_blupiTank = FALSE;
	m_blupiSkate = FALSE;
	m_blupiNage = FALSE;
	m_blupiSurf = FALSE;
	m_blupiSuspend = FALSE;
	m_blupiJumpAie = FALSE;
	m_blupiShield = FALSE;
	m_blupiPower = FALSE;
	m_blupiCloud = FALSE;
	m_blupiHide = FALSE;
	m_blupiInvert = FALSE;
	m_blupiBalloon = FALSE;
	m_blupiEcrase = FALSE;
	m_blupiActionOuf = 0;
	m_blupiTimeNoAsc = 0;
	m_blupiTimeMockery = 0;
	m_blupiValidPos = m_blupiPos;
	m_blupiEnergyUnused = 100;
	m_blupiBullet = 0;
	m_blupiCle = 0;
	m_blupiPerso = 0;
	m_blupiDynamite = 0;
	m_nbTresor = 0;
	m_totalTresor = 0;
	for (int i = MAXMOVEOBJECT; i != 0; i--)
	{
		if (m_moveObject[i].type == TYPE_TRESOR)
		{
			m_totalTresor++;
		}
		m_moveObject[i].posCurrent = m_moveObject[i].posStart;
		m_moveObject[i].step = STEP_STOPSTART;
		m_moveObject[i].phase = 0;
		m_moveObject[i].time = 0;
		if (m_moveObject[i].type == TYPE_TRESOR ||
			m_moveObject[i].type == TYPE_EGG ||
			m_moveObject[i].type == TYPE_SHIELD ||
			m_moveObject[i].type == TYPE_POWER ||
			m_moveObject[i].type == TYPE_INVERT ||
			m_moveObject[i].type == TYPE_BOMBEDOWN ||
			m_moveObject[i].type == TYPE_BOMBEUP ||
			m_moveObject[i].type == TYPE_BOMBEFOLLOW1 ||
			m_moveObject[i].type == TYPE_BOMBEFOLLOW2)
		{
			m_moveObject[i].phase = rand() % 23;
		}
		if (m_moveObject[i].type == TYPE_BALLE)
		{
			m_moveObject[i].type = 0;
		}
		if ((m_bMulti != FALSE) &&
			(m_moveObject[i].type == TYPE_CAISSE) ||
			(m_moveObject[i].type == TYPE_GOAL) ||
			(m_moveObject[i].type == TYPE_CLE) ||
			(m_moveObject[i].type == TYPE_BLUPIHELICO) ||
			(m_moveObject[i].type == TYPE_BLUPITANK))
		{
			m_moveObject[i]->type = 0;
		}
	}
	m_goalPhase = 0;
	MoveObjectSort();
	UpdateCaisse();
	m_scrollPoint = m_blupiPos;
	m_scrollAdd.x = 0;
	m_scrollAdd.y = 0;
	m_blupiPosHelico.x = -1;
	m_nbLinkCaisse = 0;
	m_bHelicopterFlying = FALSE;
	m_bHelicopterStationary = FALSE;
	m_bCarMoving = FALSE;
	m_bCarStationary = FALSE;
	m_blupiFront = FALSE;
	m_blupiNoBarre = 0;
	m_blupiValidPos = m_blupiPos;
	m_blupiFifoNb = 0;
	m_blupiTimeFire = 0;
	FUN_15580();
	FlushNotificationMessages();
	m_voyageIcon = -1;
	m_jauges[0].SetHide(TRUE);
	m_jauges[1].SetHide(TRUE);
	m_bFoundCle = FALSE;
	m_term = 0;
	m_time = 0;
	m_bPause = FALSE;
}

void CDecor::BuildPrepare()
{
	for (int i = 0; i < MAXMOVEOBJECT; i++)
	{
		m_moveObject[i].posCurrent = m_moveObject[i].posStart;
		m_moveObject[i].step = STEP_STOPSTART;
		m_moveObject[i].time = 0;
		m_moveObject[i].phase = 0;
		if (m_moveObject[i].type == TYPE_BALLE)
		{
			m_moveObject[i].type = 0;
		}
	}
	m_voyageIcon = -1;
	m_selectedCelPos.x = -1;
	// field cc20 = -1
	m_time = 0;
	m_bPause = FALSE;
	FUN_15580();
}

int CDecor::IsTerminated()
{
	return m_term;
}

void CDecor::MoveStep()
{
	MoveObjectStep();
	if (m_phase == WM_PHASE_PLAY || m_phase == WM_PHASE_PLAYTEST) {
		BlupiStep();
		FUN_15d50();
		FUN_161a0();
	}

	if (m_phase == WM_PHASE_BUILD) {
		if (m_keyPress & KEY_RIGHT) {
			m_posDecor.x += 50;
			int max = (m_dimDecor.x > 0) ? (m_dimDecor.x - LXIMAGE) : 0;
			if (m_posDecor.x > max) {
				m_posDecor.x = max;
			}
			m_selectedCelPos.x = -1;
		}
		if (m_keyPress & KEY_LEFT) {
			m_posDecor.x -= 50;
			if (m_posDecor.x < 0) {
				m_posDecor.x = 0;
			}
			m_selectedCelPos.x = -1;
		}
		if (m_keyPress & KEY_DOWN) {
			m_posDecor.y += 50;
			int max = (m_dimDecor.y > 0) ? (m_dimDecor.y - LYIMAGE) : 0;
			if (m_posDecor.y > max) {
				m_posDecor.y = max;
			}
			m_selectedCelPos.x = -1;
		}
		if (m_keyPress & KEY_UP) {
			m_posDecor.x -= 50;
			if (m_posDecor.x < 0) {
				m_posDecor.x = 0;
			}
			m_selectedCelPos.x = -1;
		}
	}
}

int CDecor::GetBlupiChannelStandard()
{
	if (m_bMulti && m_blupiChannel == CHBLUPI && m_team > 0) {
		return m_team + CHBLUPI1 - 1;
	}
	return m_blupiChannel;
}

int CDecor::GetBlupiChannelActual()
{
	if (m_bMulti && m_team > 0) {
		return m_team + CHBLUPI1 - 1;
	}
	return CHBLUPI;
}

int CDecor::GetIconPerso()
{
	if (m_bMulti) {
		return m_team + 108;
	}
	return 108;
}

BOOL CDecor::BlitzActif(int celx, int cely)
{
	POINT pos;
	pos.x = celx * DIMOBJX;
	pos.y = cely * DIMOBJY;

	//TODO: rewrite from ghidra. winphone code is too different
	int num = m_time % 100;

	if (m_decor[celx][cely - 1].icon == 304 && (num == 0 || num == 7 || num == 18 || num == 25 || num == 33 || num == 44) && cely > 0)
	{
		PlaySound(SOUND_BLITZ, pos, 0);
	}
	return num % 2 == 0 && num < 50;
}

/*
void CDecor::Build(RECT rect)
{
	POINT posDecor = DecorNextAction();
	POINT pos;
	pos.x = posDecor.x * 2 / 3 % LXIMAGE;
	pos.y = posDecor.y * 2;
	int num = 1;
	POINT tinyPoint;
	tinyPoint.x = 0;
	RECT clipRect;
	rect.left = pos.x % LXIMAGE;
	rect.right = LXIMAGE;

	clipRect = m_pPixmap->GetClipping();
	//TODO: more^

	for (int i = 0; i < 3; i++)
	{
		tinyPoint.y = 0;
		for (int j = 0; j < 2; j++)
		{
			rect.top = pos.y / 3 % LYIMAGE;
			rect.left = pos.x;
			rect.right = LXIMAGE;
			rect.bottom = LYIMAGE;
			m_pPixmap->DrawPart(-1, 3, tinyPoint, rect, 1, 0);
			tinyPoint.y += LYIMAGE - rect.top;
		}
		tinyPoint.x += LXIMAGE - pos.x;
		pos.x = 0;
	}
		if (tinyPoint.x > LXIMAGE)
		{
			break;
		}
		tinyPoint.x = m_drawBounds.left - posDecor.x % 64 - 64;
		for (int i = posDecor.x / 64 - 1; i < posDecor.x / 64 + (m_drawBounds.right - m_drawBounds.left) / 64 + 3; i++) {
			tinyPoint.y = m_drawBounds.top - posDecor.y % 64 + 2 - 64;
			for (int j = posDecor.y / 64 - 1; j < posDecor.y / 64 + (m_drawBounds.bottom - m_drawBounds.top) / 64 + 2; j++)
			{
				if (i >= 0 && i < 100 && j >= 0 && j < 100)
				{
					int num2 = m_bigDecor[i][j].icon;
				}
			}
		}
	}
}
*/
// i have gone completely insane

void CDecor::Build(RECT rect)
{
	short *pShort1;
	short short2;
	int mobType;
	POINT dest;
	RECT rect_00;
	POINT pos;
	RECT clip;
	RECT clip_00;
	RECT *pRV4;
	int int5;
	int int6;
	int int7;
	int *pint8;
	int uint9;
	BOOL BV10;
	int int11;
	int int12;
	int uint13;
	int int14;
	int uint15;
	int uint16;
	int int17;
	int int18;
	int int19;
	int int20;
	MoveObject *pMob;
	int int22;
	LONG LV23;
	LONG LV24;
	int int25;
	int L_48;
	int L_40;
	int L_3c;
	int *L_38;
	int L_34;
	RECT rect_3;
	RECT rect_2;
	RECT rect_1;

	rect_2 = m_pPixmap->GetClipping();
	rect_1 = rect_2;
	clip.top = rect.top;
	clip.left = rect.left;
	clip.right = rect.right;
	clip.bottom = rect.bottom;
	m_pPixmap->SetClipping(clip);
	pRV4 = &rect;
	DecorNextAction((POINT *)pRV4);
	rect_3.right = 0;
	rect_3.left = 2;
	rect_2.left = pRV4->left;
	rect_2.top = pRV4->top;
	int20 = rect_2.top * 2;
	int12 = rect_2.left * 2 / 3 % LXIMAGE;
	do {
		int17 = 0;
		rect.left = 2;
		int22 = int20 / 3 % LYIMAGE;
		do {
			dest.y = int17;
			dest.x = rect_3.right;
			rect_00.top = int22;
			rect_00.left = int12;
			rect_00.right = LXIMAGE;
			rect_00.bottom = LYIMAGE;
			m_pPixmap->DrawPart(-1, 3, dest, rect_00, 1, 0);
			int11 = LYIMAGE - int22;
			int22 = 0;
			int17 += int11;
			rect.left--;
		} while (rect.left != 0);
		int22 = LXIMAGE - int12;
		int12 = 0;
		rect_3.right += int22;
		rect_3.left--;
	} while (rect_3.left != 0);
	int22 = rect_2.left % DIMOBJX;
	rect_3.right = -DIMOBJX - int22;
	int12 = (int)(rect_2.left + (uint13 & 0x3f)) >> 6;
	int20 = int12 - 1;
	rect.left = 0;
	if (int20 < int12 + 13) {
		// int3 = -(_posDecor.y % 64 + 64 - 2);
		uint13 = rect_2.top >> 0x1f;
		int5 = -(rect_2.top % DIMOBJY + DIMOBJY - 2);
		int6 = (int)(rect_2.top + (uint13 & 0x3f)) >> 6;
		rect.left = (int12 + 13) - int20;
		int17 = int6 + -1;
		int20 = int20 * 100 + 10008;
		int11 = int5;
		int19 = int17;
		do {
			for (; int19 < int6 + 9; int19 = int19 + 1) {
				if (10007 < int20 && int20 < 20008 && -1 < int19 && int19 < 100) {
					int7 = 9;
					int14 = (int)*(short *)((int)(m_decor + -1) + (int19 + int20) * 2 + 184);
					if (int14 != -1) {
						if (int14 == 203) {
							int7 = 1;
							int14 = table_marine[m_time / 3 % 11];
						}
						int18 = int11;
						if ((65 < int14) && (int14 < 69)) {
							int18 = int11 + -13;
						}
						if ((86 < int14) && (int14 < 90)) {
							int18 += -2;
						}
						pos.y = int18;
						pos.x = rect_3.right;
						m_pPixmap->QuickIcon(int7, int14, pos);
					}
				}
				int11 = int11 + 64;
			}
			rect_3.right += 64;
			int20 += 100;
			rect.left--;
			int11 = int5;
			int19 = int17;
		} while (rect.left != 0);
	}
	int22 = -int22;
	int20 = int12 + 12;
	if (int12 < int20) {
		uint13 = rect_2.top >> 0x1f;
		int5 = -(((rect_2.top ^ uint13) - uint13 & 0x3f ^ uint13) - uint13);
		int6 = (int)(rect_2.top + (uint13 & 0x3f)) >> 6;
		rect.left = int20 - int12;
		int17 = int12 * 100 + 8;
		int11 = int5;
		int19 = int6;
		rect_3.right = int22;
		do {
			for (; int19 < int6 + 9; int19++) {
				if ((((7 < int17) && (int17 < 10008)) && (-1 < int19)) &&
					(((int19 < 100 &&
					(short2 = *(short *)((int)(m_decor + -1) + (int19 + int17) * 2 + 184),
						short2 != -1)) && ((int14 = (int)short2, int14 == 0x180 || (int14 == 0x181)))))) {
					pos.y = int11;
					pos.x = rect_3.right;
					m_pPixmap->QuickIcon(CHOBJECT, int14, pos);
				}
				int11 = int11 + 0x40;
			}
			rect_3.right += 0x40;
			int17 += 100;
			rect.left += -1;
			int11 = int5;
			int19 = int6;
		} while (rect.left != 0);
	}
	if (m_phase == WM_PHASE_BUILD) {
		L_38 = &m_D43C;
		rect.left = 3;
		pint8 = &m_D42C;
		do {
			int17 = 2;
			if (0 < rect.left) {
				int17 = rect.left + 10;
			}
			int11 = 4;
			if (*L_38 == 2) {
				int11 = 0;
			}
			int5 = pint8[-1] - rect_2.left;
			int19 = *pint8 - rect_2.top;
			pos.y = int19;
			pos.x = int5;
			m_pPixmap->QuickIcon(int17, int11, pos);
			if (m_buildOfficialMissions != 0) {
				pos.y = int19 + -0x14;
				pos.x = (int)pint8 + int5 + (-54294 - (int)this);
				m_pPixmap->QuickIcon(4, rect.left + 0x78, pos);
			}
			rect.left += -1;
			L_38 = L_38 + -1;
			pint8 = pint8 + -2;
		} while (-1 < rect.left);
	}
	if (m_bMulti && m_phase != WM_PHASE_BUILD) {
		rect.left = 0;
		L_40 = 0;
		pint8 = &m_D488;
		L_38 = &m_D45C;
		do {
			int17 = pint8[-4];
			if ((int17 != -1) && (((int17 < 0x114 || (0x11c < int17)) && (*pint8 != 4)))) {
				int17 = L_38[-1] - rect_2.left;
				int11 = *L_38 - rect_2.top;
				if (*pint8 == 1) {
					uint13 = m_time / 2;
					uint15 = (int)uint13 >> 0x1f;
					pos.y = int11 + -2;
					pos.x = int17;
					m_pPixmap->QuickIcon(CHELEMENT,
						(&DAT_00435568)[((uint13 ^ uint15) - uint15 & 0xf ^ uint15) - uint15],
						pos);
					pos.y = int11;
					pos.x = int17;
					m_pPixmap->QuickIcon(CHELEMENT, (&DAT_004356a8)[(m_time / 2) % 5],
						pos);
				}
				if (*pint8 == 2) {
					pos.y = int11;
					pos.x = int17;
					m_pPixmap->QuickIcon(CHELEMENT, (&table_magicloop)[(m_time / 2) % 5],
						pos);
				}
				if (*pint8 == 3) {
					int19 = 0;
					do {
						pos.y = int11 + -0x22;
						pos.x = int17 + -0x22;
						m_pPixmap->QuickIcon(CHEXPLO,
							(rect.left + int19 + m_time) % 6 + 0x30, pos);
						int19 += 1;
					} while (int19 < 3);
				}
				int19 = pint8[4];
				int5 = (int)*(short *)(m_pNetwork->m_players[0].name + L_40 + -2);
				if ((int19 == 2) && (0 < int5)) {
					int19 = int5 + 10;
				}
				pos.y = int11;
				pos.x = int17;
				m_pPixmap->QuickIcon(int19, pint8[-4], pos);
				pos.y = int11 + -0x14;
				pos.x = int17 + 10;
				m_pPixmap->QuickIcon(4, int5 + 0x78, pos);
			}
			rect.left += 1;
			pint8 = pint8 + 1;
			L_40 += 0x20;
			L_38 = L_38 + 2;
		} while (L_40 < 0x80);
	}
	if ((m_phase == WM_PHASE_BUILD) || (m_blupiSec = 0, m_blupiFront != 0))
		goto LAB_00404781;
	int11 = (m_blupiPos).x - rect_2.left;
	int17 = (m_blupiPos).y - rect_2.top;
	if (m_blupiShield == 0) {
		if (m_blupiPower != 0) {
			m_blupiSec = 2;
			if ((m_blupiTimeShield < 26) &&
				(uint13 = m_time >> 0x1f,
					1 < (int)(((m_time ^ uint13) - uint13 & 3 ^ uint13) - uint13))) goto LAB_004052d0;
			pos.y = int17;
			pos.x = int11;
			m_pPixmap->QuickIcon(CHELEMENT, (&table_magicloop)[(m_time / 2) % 5], pos
			);
			int25 = m_blupiIcon;
			goto LAB_00404771;
		}
		if (m_blupiCloud) {
			m_blupiSec = 3;
			if ((25 < m_blupiTimeShield) ||
				(uint13 = m_time >> 0x1f,
				(int)(((m_time ^ uint13) - uint13 & 3 ^ uint13) - uint13) < 2)) {
				int19 = 0;
				do {
					pos.y = int17 + -0x22;
					pos.x = int11 + -0x22;
					m_pPixmap->QuickIcon(CHEXPLO, (int19 + m_time) % 6 + 0x30, pos);
					int19 += 1;
				} while (int19 < 3);
			}
		LAB_00404768:
			int25 = m_blupiIcon;
			goto LAB_00404771;
		}
		if (m_blupiHide == 0) goto LAB_00404768;
		m_blupiSec = 4;
		if ((m_blupiTimeShield < 26) &&
			(uint13 = m_time >> 0x1f,
				1 < (int)(((m_time ^ uint13) - uint13 & 3 ^ uint13) - uint13))) goto LAB_004052d0;
		m_pPixmap->DrawIcon(0xe, 1, 0xf5, (POINT)0x0, 0, 1);
		int25 = m_blupiIcon;
		BV10 = 0;
		int5 = 1;
		LV24 = 0;
		LV23 = 0;
		int19 = GetBlupiChannel_1();
		pos.y = LV24;
		pos.x = LV23;
		m_pPixmap->DrawIcon(0xe, int19, (int)int25, pos, int5, BV10);
		m_pPixmap->DrawIcon(0xe, 1, 0xed, (POINT)0x0, 0, 1);
		int25 = (Icon4)0x0;
		int19 = 0xe;
	}
	else {
		m_blupiSec = 1;
		if ((m_blupiTimeShield < 0x1a) &&
			(uint13 = m_time >> 0x1f,
				1 < (int)(((m_time ^ uint13) - uint13 & 3 ^ uint13) - uint13))) {
		LAB_004052d0:
			int25 = m_blupiIcon;
		}
		else {
			uint13 = m_time / 2;
			uint15 = (int)uint13 >> 0x1f;
			pos.y = int17 + -2;
			pos.x = int11;
			m_pPixmap->QuickIcon(CHELEMENT,
				(&DAT_00435568)[((uint13 ^ uint15) - uint15 & 0xf ^ uint15) - uint15],
				pos);
			pos.y = int17;
			pos.x = int11;
			m_pPixmap->QuickIcon(CHELEMENT, (&DAT_004356a8)[(m_time / 2) % 5], pos);
			int25 = m_blupiIcon;
		}
	LAB_00404771:
		int19 = GetBlupiChannel_1();
	}
	pos.y = int17;
	pos.x = int11;
	m_pPixmap->QuickIcon(int19, (int)int25, pos);
LAB_00404781:
	pMob = m_moveObject + 199;
	rect.left = MAXMOVEOBJECT;
	do {
		mobType = pMob->type;
		if (((((((mobType != TYPE_empty) &&
			(int17 = (pMob->posCurrent).x, (int)(rect_2.left - 64U) <= int17)) &&
			(int11 = (pMob->posCurrent).y, (int)(rect_2.top - 64U) <= int11)) &&
			((int17 <= (int)(rect_2.left + LXIMAGE) && (int11 <= (int)(rect_2.top + LYIMAGE)))))
			&& (((short)mobType < 8 || (11 < (short)mobType)))) &&
			(((short)mobType < 90 || (95 < (short)mobType)))) &&
			((((short)mobType < 98 || (100 < (short)mobType)) &&
			((((mobType != TYPE_TENTACULE && (mobType != TYPE_ASCENSEUR)) && (mobType != TYPE_ASCENSUERs)) &&
				(mobType != TYPE_ASCENSEURsi)))))) {
			int17 -= rect_2.left;
			int11 -= rect_2.top;
			if (((mobType == TYPE_BULLDOZER) || (mobType == TYPE_BLUPIHELICO)) || (mobType == TYPE_BLUPITANK)) {
				int17 += 2;
				int11 += 6;
			}
			if (mobType == TYPE_CREATURE) {
				int11 += 6;
			}
			pos.y = int11;
			pos.x = int17;
			m_pPixmap->QuickIcon((int)pMob->channel, (int)pMob->icon, pos);
			if (((m_bDrawSecret != 0) || (m_phase != WM_PHASE_PLAY)) &&
				((pMob->type == TYPE_CAISSE &&
				(((short2 = pMob->icon, short2 != obj_woodencase0 && (short2 != obj_woodencase1)) &&
					(short2 != obj_woodencase2)))))) {
				pos.y = int11;
				pos.x = int17;
				m_pPixmap->QuickIcon(CHOBJECT, 0xd6, pos);
			}
		}
		pMob = pMob + -1;
		rect.left += -1;
	} while (rect.left != 0);
	if (int12 < int20) {
		uint13 = rect_2.top >> 0x1f;
		int5 = -(((rect_2.top ^ uint13) - uint13 & 0x3f ^ uint13) - uint13);
		int6 = (int)(rect_2.top + (uint13 & 0x3f)) >> 6;
		rect.left = int12 * 7;
		L_34 = int20 - int12;
		int17 = int12 * 100 + 8;
		int11 = int5;
		int19 = int6;
		rect_3.right = int22;
		do {
			for (; int19 < int6 + 9; int19 = int19 + 1) {
				if (((7 < int17) && (int17 < 10008)) &&
					((-1 < int19 &&
					((int19 < 100 &&
						(short2 = *(short *)((int)(m_decor + -1) + (int19 + int17) * 2 + 0xb8),
							short2 != -1)))))) {
					int14 = (int)short2;
					if (((106 < int14) && (int14 < 110)) || (int7 = int11, int14 == 0x9d)) {
						int7 = int11 + -7;
					}
					if (int14 == 211) {
						uint13 = m_time / 2 + rect.left;
						uint15 = (int)uint13 >> 0x1f;
						int14 = table_ressort[((uint13 ^ uint15) - uint15 & 7 ^ uint15) - uint15];
					}
					if (((int14 == 214) && (m_bDrawSecret == 0)) && (m_phase == WM_PHASE_PLAY)) {
						int14 = -1;
					}
					if (int14 == 364) {
						int7 += -2;
					}
					if ((((int14 != obj_lava) && (int14 != 0x5b)) &&
						((int14 != obj_watersurface && ((int14 != obj_lightning && (int14 != obj_crusher)))
							))) && ((int14 != obj_crusher6 &&
							((((((int14 != 0x175 && (int14 != 0x194)) && (int14 != 0x19a)) &&
								((int14 != 0x17a && (int14 != 0x180)))) && (int14 != 0x181)) &&
								((int14 < obj_wind_left || (0x89 < int14)))))))) {
						pos.y = int7;
						pos.x = rect_3.right;
						m_pPixmap->QuickIcon(CHOBJECT, int14, pos);
					}
				}
				int11 = int11 + 64;
			}
			rect_3.right += 64;
			int17 += 100;
			rect.left += 7;
			L_34 += -1;
			int11 = int5;
			int19 = int6;
		} while (L_34 != 0);
	}
	pMob = m_moveObject;
	rect.left = 200;
	do {
		mobType = pMob->type;
		if ((((mobType == TYPE_ASCENSEUR) || (mobType == TYPE_ASCENSUERs)) || (mobType == TYPE_ASCENSEURsi))
			&& (((int17 = (pMob->posCurrent).x, (int)(rect_2.left - 64U) <= int17 &&
			(int11 = (pMob->posCurrent).y, (int)(rect_2.top - 0x40U) <= int11)) &&
				((int17 <= (int)(rect_2.left + LXIMAGE) && (int11 <= (int)(rect_2.top + LYIMAGE))))
				))) {
			pos.y = int11 - rect_2.top;
			pos.x = int17 - rect_2.left;
			m_pPixmap->QuickIcon((int)pMob->channel, (int)pMob->icon, pos);
		}
		uint13 = rect_2.top;
		if ((m_phase == WM_PHASE_BUILD) &&
			((((mobType = pMob->type, mobType == TYPE_ASCENSEUR || (mobType == TYPE_ASCENSUERs)) ||
			(((mobType == TYPE_ASCENSEURsi ||
				(((mobType == TYPE_BOMBEMOVE || (mobType == TYPE_BULLDOZER)) || (mobType == TYPE_POISSON)))) ||
				(((mobType == TYPE_OISEAU || (mobType == TYPE_GUEPE)) || (mobType == TYPE_CREATURE)))))) ||
				((mobType == TYPE_BLUPIHELICO || (mobType == TYPE_BLUPITANK)))))) {
			int11 = (pMob->posEnd).x;
			int17 = rect_2.left - 64;
			if ((int17 <= int11) &&
				(((int19 = (pMob->posEnd).y, (int)(rect_2.top - 0x40U) <= int19 &&
				(int11 <= (int)(rect_2.left + LXIMAGE))) && (int19 <= (int)(rect_2.top + LYIMAGE)))
					)) {
				pos.y = int19 - rect_2.top;
				pos.x = int11 - rect_2.left;
				m_pPixmap->QuickIcon(1, 0x1f, pos);
			}
			int11 = (pMob->posStart).x;
			if (((int17 <= int11) && (int17 = (pMob->posStart).y, (int)(uint13 - 0x40) <= int17))
				&& ((int11 <= (int)(rect_2.left + LXIMAGE) && (int17 <= (int)(uint13 + LYIMAGE))))) {
				pos.y = int17 - uint13;
				pos.x = int11 - rect_2.left;
				m_pPixmap->QuickIcon(1, 0x1e, pos);
			}
		}
		pMob = pMob + 1;
		rect.left += -1;
	} while (rect.left != 0);
	if (int12 < int20) {
		uint15 = rect_2.top >> 0x1f;
		uint13 = rect_2.top ^ uint15;
		int17 = (int)(rect_2.top + (uint15 & 0x3f)) >> 6;
		L_48 = int12 * 0xd;
		L_3c = int12 * 100 + 8;
		rect_3.right = int22;
		do {
			if (int17 < int17 + 9) {
				rect.left = int17 * 7;
				L_38 = (int *)int17;
				rect_3.bottom = -((uint13 - uint15 & 0x3f ^ uint15) - uint15);
				do {
					if (((7 < L_3c) && (L_3c < 10008)) && ((-1 < rect.left && (rect.left < 700)))) {
						pShort1 = (short *)((int)(m_decor + -1) + ((int)L_38 + L_3c) * 2 + 0xb8);
						if (*pShort1 != -1) {
							int22 = (int)*pShort1;
							if (int22 == obj_lava) {
								uint9 = m_time / 3 + L_48 + rect.left;
								uint16 = (int)uint9 >> 0x1f;
								int22 = (&table_decor_lave)[((uint9 ^ uint16) - uint16 & 7 ^ uint16) - uint16];
								pos.y = rect_3.bottom;
								pos.x = rect_3.right;
								m_pPixmap->QuickIcon(CHOBJECT, int22, pos);
							}
							if (int22 == 0x175) {
								int22 = m_time;
								if (m_blupiFocus == 0) {
									uint9 = int22 / 2 + L_48 + rect.left;
									uint16 = (int)uint9 >> 0x1f;
									int22 = (&table_decor_piege2)[((uint9 ^ uint16) - uint16 & 3 ^ uint16) - uint16];
								}
								else {
									uint9 = ((int)(int22 + (int22 >> 0x1f & 3U)) >> 2) + L_48 + rect.left;
									uint16 = (int)uint9 >> 0x1f;
									int22 = (&table_decor_piege1)
										[((uint9 ^ uint16) - uint16 & 0xf ^ uint16) - uint16];
								}
								pos.y = rect_3.bottom;
								pos.x = rect_3.right;
								m_pPixmap->QuickIcon(1, int22, pos);
							}
							if ((int22 == 404) || (int11 = rect_3.bottom, int22 == 410)) {
								int22 = *(int *)(&table_decor_goutte +
									((m_time / 2 + L_48 + rect.left) % 0x30) * 4);
								int11 = rect_3.bottom + -9;
								pos.y = int11;
								pos.x = rect_3.right;
								m_pPixmap->QuickIcon(1, int22, pos);
								if ((int22 < 404) || (407 < int22)) {
									*pShort1 = 410;
								}
								else {
									*pShort1 = 404;
								}
							}
							if (int22 == obj_crusher) {
								int22 = table_decor_ecraseur[(m_time / 3) % 10];
								pos.y = int11;
								pos.x = rect_3.right;
								m_pPixmap->QuickIcon(1, int22, pos);
							}
							if (int22 == 0x17a) {
								int22 = table_decor_scie[(m_time + L_48 + rect.left) % 6];
								pos.y = int11;
								pos.x = rect_3.right;
								m_pPixmap->QuickIcon(1, int22, pos);
							}
							if (int22 == obj_crusher6) {
								int22 = m_time + (m_time >> 0x1f & 3U);
								int22 = table_decor_temp[(int)(CONCAT44(int22 >> 0x1f, int22 >> 2) % 0x14)];
								pos.y = int11;
								pos.x = rect_3.right;
								m_pPixmap->QuickIcon(1, int22, pos);
							}
							if (int22 == obj_watersurface) {
								uint9 = m_time / 3 + L_48 + rect.left;
								uint16 = (int)uint9 >> 0x1f;
								int22 = (&table_decor_eau1)[((uint9 ^ uint16) - uint16 & 3 ^ uint16) - uint16];
								pos.y = int11;
								pos.x = rect_3.right;
								m_pPixmap->QuickIcon(1, int22, pos);
							}
							if (int22 == 0x5b) {
								uint9 = m_time / 3 + L_48 + rect.left;
								uint16 = (int)uint9 >> 0x1f;
								int22 = (&table_decor_eau2)[((uint9 ^ uint16) - uint16 & 3 ^ uint16) - uint16];
								pos.y = int11;
								pos.x = rect_3.right;
								m_pPixmap->QuickIcon(1, int22, pos);
							}
							if ((int22 == obj_lightning) &&
								(BV10 = BlitzActif(this, int12, (int)L_38), BV10 != 0)) {
								int22 = *(int *)(&table_decor_lightning +
									((m_time + L_48 + rect.left) % 0x32) * 4);
								pos.y = int11;
								pos.x = rect_3.right;
								m_pPixmap->QuickIcon(1, int22, pos);
							}
							if (int22 == obj_wind_left) {
								uint9 = m_time >> 0x1f;
								int22 = (&table_decor_ventg)[((m_time ^ uint9) - uint9 & 3 ^ uint9) - uint9];
								pos.y = int11;
								pos.x = rect_3.right;
								m_pPixmap->QuickIcon(1, int22, pos);
							}
							if (int22 == obj_wind_right) {
								uint9 = m_time >> 0x1f;
								int22 = (&table_decor_ventd)[((m_time ^ uint9) - uint9 & 3 ^ uint9) - uint9];
								pos.y = int11;
								pos.x = rect_3.right;
								m_pPixmap->QuickIcon(1, int22, pos);
							}
							if (int22 == obj_wind_up) {
								uint9 = m_time >> 0x1f;
								int22 = (&table_decor_venth)[((m_time ^ uint9) - uint9 & 3 ^ uint9) - uint9];
								pos.y = int11;
								pos.x = rect_3.right;
								m_pPixmap->QuickIcon(1, int22, pos);
							}
							if (int22 == obj_wind_down) {
								uint9 = m_time >> 0x1f;
								int22 = (&table_decor_ventb)[((m_time ^ uint9) - uint9 & 3 ^ uint9) - uint9];
								pos.y = int11;
								pos.x = rect_3.right;
								m_pPixmap->QuickIcon(1, int22, pos);
							}
							if (int22 == obj_fan_left) {
								int22 = (&table_decor_ventillog)[(m_time / 2) % 3];
								pos.y = int11;
								pos.x = rect_3.right;
								m_pPixmap->QuickIcon(1, int22, pos);
							}
							if (int22 == obj_fan_right) {
								int22 = (&table_decor_ventillod)[(m_time / 2) % 3];
								pos.y = int11;
								pos.x = rect_3.right;
								m_pPixmap->QuickIcon(1, int22, pos);
							}
							if (int22 == obj_fan_up) {
								int22 = (&table_decor_ventilloh)[(m_time / 2) % 3];
								pos.y = int11;
								pos.x = rect_3.right;
								m_pPixmap->QuickIcon(1, int22, pos);
							}
							if (int22 == obj_fan_down) {
								pos.y = int11;
								pos.x = rect_3.right;
								m_pPixmap->QuickIcon(1,
									(&table_decor_ventillob)[(m_time / 2) % 3], pos);
							}
						}
					}
					rect_3.bottom += 64;
					L_38 = (int *)((int)L_38 + 1);
					rect.left += 7;
				} while ((int)L_38 < int17 + 9);
			}
			rect_3.right += 64;
			int12 += 1;
			L_3c += 100;
			L_48 += 13;
		} while (int12 < int20);
	}
	uint13 = rect_2.left;
	pMob = m_moveObject;
	rect.left = 200;
	do {
		mobType = pMob->type;
		if (((((mobType != TYPE_empty) && (int20 = (pMob->posCurrent).x, (int)(uint13 - 64) <= int20)
			) && (int12 = (pMob->posCurrent).y, (int)(rect_2.top - 0x40U) <= int12)) &&
			((int20 <= (int)(uint13 + LXIMAGE) && (int12 <= (int)(rect_2.top + LYIMAGE))))) &&
			(((((7 < (short)mobType && ((short)mobType < 0xc)) ||
			((0x59 < (short)mobType && ((short)mobType < 0x60)))) ||
				((0x61 < (short)mobType && ((short)mobType < 0x65)))) || (mobType == TYPE_TENTACULE)))) {
			pos.y = int12 - rect_2.top;
			pos.x = int20 - uint13;
			m_pPixmap->QuickIcon((int)pMob->channel, (int)pMob->icon, pos);
		}
		pMob = pMob + 1;
		rect.left += -1;
	} while (rect.left != 0);
	if ((m_blupiFront != 0) && (m_phase != WM_PHASE_BUILD)) {
		int22 = (m_blupiPos).y - rect_2.top;
		int20 = (m_blupiPos).x - uint13;
		int25 = m_blupiIcon;
		int12 = GetBlupiChannel_1();
		pos.y = int22;
		pos.x = int20;
		m_pPixmap->QuickIcon(int12, (int)int25, pos);
	}
	DrawInfo();
	VoyageDraw();
	clip_00.top = rect_1.top;
	clip_00.left = rect_1.left;
	clip_00.right = rect_1.right;
	clip_00.bottom = rect_1.bottom;
	CPixmap::SetClipping(m_pPixmap, clip_00);
	int20 = m_time + 1;
	m_time = int20;
	if (32767 < int20) {
		m_time = 0;
	}
	return;
}



void CDecor::DrawInfo()
{
	POINT pos;
	char text[100];

	if (m_phase == WM_PHASE_PLAY || WM_PHASE_PLAYTEST)
	{
		for (int i = 4; i != 0; i--) {
			if (m_messages[i] != '\0') {
				pos.x = 10;
				pos.y = 10;
				DrawText(m_pPixmap, pos, *m_messages[i], 0);
			}
		}

		if (m_nbVies > 0) {
			pos.x = -15;
			for (int i = 0; i < m_nbVies; i++) {
				pos.y = 417;
				m_pPixmap->QuickIcon(GetStandardBlupiChannel(), 48, pos);
				pos.x += 16;
			}
		}

		if (m_blupiBullet > 0) {
			pos.x = -15;
			pos.y = 398;
			for (int i = 0; i < m_blupiBullet; i++) {
				m_pPixmap->QuickIcon(CHELEMENT, 176, pos);
				pos.x += 4;
			}
		}

		//TODO: more
	}
}

POINT CDecor::DecorNextAction()
{
	int num = 0;
	if (m_decorAction == 0 || m_bPause)
	{
		m_posDecor;
	}
	POINT posDecor = m_posDecor;
	while (tables->table_decor_action[num] != 0)
	{
		if (m_decorAction == tables->table_decor_action[num])
	}
}

void CDecor::UpdateCaisse()
{
	m_nbRankCaisse = 0;
	for (int i = 0; i < MAXMOVEOBJECT; i++)
	{
		if (m_moveObject[i]->type == 12)
		{
			m_rankCaisse[m_nbRankCaisse++] = i;
		}
	}
}

BOOL CDecor::TestPushCaisse(int i, POINT pos, BOOL bPop)
{
	POINT move;

	move.x = pos.x - m_moveObject[i]->posCurrent.x;
	move.y = 0;
	SearchLinkCaisse(i, bPop);
	int y = m_moveObject[i]->posCurrent.y;
	for (int j = 0; j < m_nbLinkCaisse; j++)
	{
		i = m_linkCaisse[j];
		if (!TestPushOneCaisse(i, move, y))
		{
			return FALSE;
		}
	}
	for (int j = 0; j < m_nbLinkCaisse; j++)
	{
		i = m_linkCaisse;
		int num = i;
		m_moveObject[num]->posCurrent.x = m_moveObject[num]->posCurrent.x + move.x;
		m_moveObject[num]->posStart.x = m_moveObject[num]->posStart.x + move.x;
		int num2 = i;
		m_moveObject[num]->posEnd.x = m_moveObject[num]->posEnd.x + move.x;
	}
	return TRUE;
}

BOOL CDecor::TestPushOneCaisse(int i, POINT move, int b)
{

}

void CDecor::SearchLinkCaisse(int rank, BOOL bPop)
{
	m_nbLinkCaisse = 0;
	AddLinkCaisse(rank);
	POINT posCurrent = m_moveObject;

	BOOL flag;
	do
	{
		flag = FALSE;
		for (int i = 0; i < m_nbLinkCaisse; i++)
		{
			int num = m_linkCaisse[i];
			if (m_moveObject[num]->posCurrent.y <=
				posCurrent.y && (!bPop || (m_moveObject
					[num]->posCurrent.x >= posCurrent.x - 32 &&
					m_moveObject[num]->posCurrent.x <=
					posCurrent.x + 32)))
			{

			}
		}
	}
}

BOOL CDecor::AddLinkCaisse(int rank)
{

}


BOOL CDecor::LoadImages()
{
	char filename[52];
	POINT totalDim, iconDim;

	if (m_region == m_lastRegion) return TRUE;
	m_lastRegion == m_region;

	totalDim.x = DIMCELX * 2 * 16;
	totalDim.y = DIMCELY * 2 * 6;
	iconDim.x = DIMCELX * 2;
	iconDim.y = DIMCELY * 2;
	sprintf(filename, "image\\decor%.3d.blp", m_region);
	if (!m_pPixmap->Cache(CHFLOOR, filename, totalDim, iconDim, FALSE))
		return FALSE;

	return TRUE;
}




int CDecor::SetBlupiChannel()
{
	if (m_bMulti = 0 ||
		m_blupiChannel == ch_blupi00 ||
		m_team > 0); {
		return m_team + 10;
	}
	return m_blupiChannel;
}

int CDecor::GetBlupiChannel()
{
	int m_blupiChannel = CHBLUPI000;


	if (m_bMulti != 0 ||
		m_team > 0); {
		return m_team + 10;
	}
	return CHBLUPI000;
}



int CDecor::GetIconPerso()
{
	if (m_bMulti) {
		return m_team + ICON_BUTTON_PERSONALBOMBICON;
	}
	return ICON_BUTTON_PERSONALBOMBICON;
}


void CDecor::SetTime(int time)
{
	m_time = time;
}

int CDecor::GetTime()
{
	return m_time;
}

int CDecor::GetTargetLevel(int mission)
{
	m_targetMission = mission;
}

int CDecor::GetRegion()
{
	return m_region;
}

void CDecor::SetRegion(int region)
{
	m_region = region;
}

int CDecor::GetMusic()
{
	return m_music;
}

void CDecor::SetMusic(int music)
{
	m_music = music;
}

void CDecor::GetDims(POINT* ptr)
{
	ptr->x = m_dimDecor.x;
	ptr->y = m_dimDecor.y;
	return;
}

void CDecor::SetDims(POINT dims)
{
	m_dimDecor.x = dims.x;
	m_dimDecor.y = dims.y;
}

int CDecor::GetLives()
{
	return m_lives;
}

void CDecor::SetLives(int lives)
{
	m_lives = lives;
}

BOOL CDecor::GetInvincible()
{
	return m_bSuperBlupi;
}

void CDecor::SetInvincible(BOOL invincible)
{
	m_bSuperBlupi = invincible;
}

BOOL CDecor::GetShowSecret()
{
	return m_bDrawSecret;
}

void CDecor::SetShowSecret(BOOL secret)
{
	m_bDrawSecret = secret;
}

void CDecor::SetAccessBuild(BOOL build)
{
	m_bAccessBuild = build;
}

BOOL CDecor::GetNetPacked()
{
	return m_bNetPacked;
}

void CDecor::SetNetPacked(BOOL net)
{
	m_bNetPacked = net;
}

BOOL CDecor::GetNetMovePredict()
{
	return m_bNetMovePredict;
}

void CDecor::SetNetMovePredict(BOOL netmove)
{
	m_bNetMovePredict = netmove;
}

BOOL CDecor::GetNetDebug()
{
	return m_bNetDebug;
}

void CDecor::SetMulti(int multi)
{
	m_bMulti = multi;
}

void CDecor::SetTeam(int team)
{
	m_team = team;
}

void CDecor::GetBlupiInfo(BOOL bHelico, BOOL bJeep, BOOL bSkate, BOOL bNage)
{
	bHelico = m_blupiHelico;
	bJeep = (m_blupiJeep | m_blupiTank);
	bSkate = m_blupiSkate;
	bNage = (m_blupiNage | m_blupiSurf);
}

void CDecor::MoveObjectSort()
{
	CDecor.MoveObject src = default(CDecor->MoveObject);
	int num = 0;
	for (int i = 0; i < MAXMOVEOBJECT; i++)
}

int CDecor::GetMissionTitle()
{
	return m_missionTitle;
}

void CDecor::GetMissionsCleared()
{

}

void CDecor::SetDemoState(BOOL demoState)
{
	m_demoState = demoState;
}