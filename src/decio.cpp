// DecIO.cpp
//

#include "def.h"
#include "decor.h"
#include "misc.h"

void CDecor::GetMissionPath(char* str, int user, int mission, BOOL bUser)
{
	if (bUser != 0)
	{
		sprintf(str, "data\\%.3d-%.3d.blp", user, mission);
		AddUserPath(str);
		return;
	}
	sprintf(str, "data\\world%.3d.blp", mission);
	AddUserPath(str);
	return;
}

BOOL CDecor::DeleteMission(int user, int mission, BOOL bUser)
{
	char filename[FILENAME_MAX];

	GetMissionPath(filename, user, mission, bUser);
	remove(filename);
	return TRUE;
}

BOOL CDecor::Write(int gamer, int mission, BOOL bUser)
{
	char filename[FILENAME_MAX];
	DescFile* pBuffer = NULL;
	FILE* file;
	int* blupiDir;
	POINT* blupiPos;
	int nb;
	int i;


	GetMissionPath(filename, gamer, mission, bUser);

	
	file = fopen(filename, "wb");
	if (file == NULL) goto error;
	
	pBuffer = (DescFile*)malloc(sizeof(DescFile));
	if (pBuffer == NULL) goto error;
	memset(pBuffer, 0, sizeof(DescFile));

	i = 4;
	pBuffer->majRev = 1;
	pBuffer->minRev = 3;
	*pBuffer->reserve1 = 0;
	pBuffer->posDecor = m_posDecor;
	pBuffer->dimDecor = m_dimDecor;
	pBuffer->music = m_music;
	pBuffer->region = m_region;
	blupiDir = m_blupiStartDir;
	strcpy(pBuffer->name, m_missionTitle);
	blupiPos = m_blupiStartPos;

	for (i = 0; i < 4; i++)
	{
		pBuffer->blupiPos[i] = m_blupiStartPos[i];
	}

	for (i = 0; i < 4; i++)
	{
		pBuffer->blupiDir[i] = m_blupiStartDir[i];
	}

	nb = fwrite(pBuffer, sizeof(DescFile), 1, file);
	if (nb < 1) goto error;

	nb = fwrite(m_decor, sizeof(Cellule), MAXCELX * MAXCELY / 4, file);
	if (nb < MAXCELX * MAXCELY / 4) goto error;

	nb = fwrite(m_bigDecor, sizeof(Cellule), MAXCELX * MAXCELY / 4, file);
	if (nb < MAXCELX * MAXCELY / 4) goto error;

	nb = fwrite(m_moveObject, sizeof(MoveObject), MAXMOVEOBJECT, file);
	if (nb < MAXMOVEOBJECT) goto error;

	free(pBuffer);
	fclose(file);
	return TRUE;

error: 
	if (pBuffer != NULL) free(pBuffer);
	if (file != NULL) fclose(file);
	return FALSE;
}

BOOL CDecor::Read(int gamer, int mission, BOOL bUser)
{
	char filename[FILENAME_MAX];
	FILE* file;
	DescFile* pBuffer;
	short majRev, minRev;
	short obj;
	Cellule(*objects)[100];
	POINT* startPos;
	POINT* blupiPos;
	int nb;
	int i = 4;
	int x, y;
	int* startDir;
	int* blupiDir;

	pBuffer = 0;
	InitDecor();
	GetMissionPath(filename, gamer, mission, bUser);
	
	file = fopen(filename, "rb");
	if (file == NULL) goto error;
	
	pBuffer = (DescFile*)malloc(sizeof(DescFile));
	if (pBuffer == NULL) goto error;

	nb = fread(pBuffer, sizeof(DescFile), 1, file);
	if (nb < 1) goto error;
		
	majRev = pBuffer->majRev;
	minRev = pBuffer->minRev;
	m_posDecor = pBuffer->posDecor;
	m_dimDecor = pBuffer->dimDecor;
	m_music = pBuffer->music;
	m_region = pBuffer->region;
	if (majRev >= 1 && minRev >= 3)
	{
		strcpy(m_missionTitle,pBuffer->name);
	}
	startDir = m_blupiStartDir;
	blupiDir = pBuffer->blupiDir;
	startPos = m_blupiStartPos;
	blupiPos = pBuffer->blupiPos;

	for (i = 0; i < MAXNETPLAYER; i++)
	{
		m_blupiStartPos[i] = pBuffer->blupiPos[i];
		m_blupiStartDir[i] = pBuffer->blupiDir[i];
	}

	nb = fread(m_decor, sizeof(Cellule), MAXCELX * MAXCELY, file);
	if (nb < MAXCELX * MAXCELY) goto error;
	
#if !_DREAM
	for (x = 0; x < MAXCELX; x++)
	{
		for (y = 0; y < MAXCELY; y++)
		{
			if (m_decor[x][y].icon >= Object::Dream_1 &&
				m_decor[x][y].icon <= Object::Dream_20)
			{
				m_decor[x][y].icon = Object::KidsSquare_10;
			}
		}
	}
#endif

	if (majRev == 1 && minRev >= 1)
	{
		nb = fread(m_bigDecor, sizeof(Cellule), MAXCELX * MAXCELY, file);
		if (nb < MAXCELX * MAXCELY) goto error;
	}

	memset(m_moveObject, 0, sizeof(MoveObject) * MAXMOVEOBJECT);
	if (majRev == 1 && minRev >= 2)
	{
		nb = fread(m_moveObject, sizeof(MoveObject), MAXMOVEOBJECT, file);
		if (nb < MAXMOVEOBJECT) goto error;
	}
	else
	{
		nb = fread(m_moveObject, sizeof(MoveObject), MAXMOVEOBJECT / 2, file);
		if (nb < MAXMOVEOBJECT / 2) goto error;
	}

	free(pBuffer);
	fclose(file);
	return TRUE;
error:
	if (pBuffer != NULL) free(pBuffer);
	if (file != NULL) fclose(file);

	InitDecor();
	return FALSE;
}

BOOL CDecor::SomethingMissionPath(int gamer, int mission, BOOL bUser)
{
	return FALSE; 
}

BOOL CDecor::MissionStart(int gamer, int mission, BOOL bUser)
{
	char filename[MAX_PATH];
	FILE* file = NULL;
	DescSave* pBuffer = NULL;
	int nb, i, x, y;
	int majRev, minRev;

	sprintf(filename, "data\\s%.3d-%.3d.blp", gamer, mission);
	AddUserPath(filename);

	file = fopen(filename, "wb");
	if (file == NULL) goto error;

	pBuffer = (DescSave*)malloc(sizeof(DescSave));
	if (pBuffer == NULL) goto error;

	memset(pBuffer, 0, sizeof(DescSave));
	pBuffer->lg = sizeof(DescSave);
	pBuffer->majRev = 1;
	pBuffer->minRev = 4;
	pBuffer->reserve1[0] = 0;
	memcpy(pBuffer->decor, m_decor, sizeof(pBuffer->decor));
	memcpy(pBuffer->bigDecor, m_bigDecor, sizeof(pBuffer->bigDecor));
	memcpy(pBuffer->balleTraj, m_balleTraj, sizeof(pBuffer->balleTraj));
	memcpy(pBuffer->moveTraj, m_moveTraj, sizeof(pBuffer->moveTraj));
	memcpy(pBuffer->moveObject, m_moveObject, sizeof(pBuffer->moveObject));
	pBuffer->posDecor = m_posDecor;
	pBuffer->dimDecor = m_dimDecor;
	pBuffer->phase = m_phase;
	pBuffer->term = m_term;
	pBuffer->music = m_music;
	pBuffer->region = m_region;
	pBuffer->time = m_time;
	memcpy(pBuffer->missionTitle, m_missionTitle, sizeof(pBuffer->missionTitle));
	pBuffer->nbRankCaisse = m_nbRankCaisse;
	memcpy(pBuffer->rankCaisse, m_rankCaisse, sizeof(pBuffer->rankCaisse));
	pBuffer->nbLinkCaisse = m_nbLinkCaisse;
	memcpy(pBuffer->linkCaisse, m_linkCaisse, sizeof(pBuffer->linkCaisse));
	pBuffer->blupiPos = m_blupiPos;
	pBuffer->blupiValidPos = m_blupiValidPos;
	pBuffer->blupiAction = m_blupiAction;
	pBuffer->blupiDir = m_blupiDir;
	pBuffer->blupiPhase = m_blupiPhase;
	pBuffer->blupiVitesse = m_blupiVitesse;
	pBuffer->blupiIcon = m_blupiIcon;
	pBuffer->blupiSec = m_blupiSec;
	pBuffer->blupiChannel = m_blupiChannel;
	pBuffer->blupiVector = m_blupiVector;
	pBuffer->blupiTransport = m_blupiTransport;
	pBuffer->blupiFocus = m_blupiFocus;
	pBuffer->blupiAir = m_blupiAir;
	pBuffer->blupiHelico = m_blupiHelico;
	pBuffer->blupiOver = m_blupiOver;
	pBuffer->blupiJeep = m_blupiJeep;
	pBuffer->blupiTank = m_blupiTank;
	pBuffer->blupiSkate = m_blupiSkate;
	pBuffer->blupiNage = m_blupiNage;
	pBuffer->blupiSurf = m_blupiSurf;
	pBuffer->blupiVent = m_blupiVent;
	pBuffer->blupiSuspend = m_blupiSuspend;
	pBuffer->blupiJumpAie = m_blupiJumpAie;
	pBuffer->blupiShield = m_blupiShield;
	pBuffer->blupiPower = m_blupiPower;
	pBuffer->blupiCloud = m_blupiCloud;
	pBuffer->blupiHide = m_blupiHide;
	pBuffer->blupiInvert = m_blupiInvert;
	pBuffer->blupiBalloon = m_blupiBalloon;
	pBuffer->blupiEcrase = m_blupiEcrase;
	pBuffer->blupiPosHelico = m_blupiPosHelico;
	pBuffer->blupiPosMagic = m_blupiPosMagic;
	pBuffer->blupiRestart = m_blupiRestart;
	pBuffer->blupiFront = m_blupiFront;
	pBuffer->blupiBullet = m_blupiBullet;
	pBuffer->blupiCle = m_blupiCle;
	pBuffer->blupiPerso = m_blupiPerso;
	pBuffer->blupiDynamite = m_blupiDynamite;
	pBuffer->blupiNoBarre = m_blupiNoBarre;
	pBuffer->blupiTimeShield = m_blupiTimeShield;
	pBuffer->blupiTimeFire = m_blupiTimeFire;
	pBuffer->blupiTimeNoAsc = m_blupiTimeNoAsc;
	pBuffer->blupiTimeOuf = m_blupiTimeOuf;
	pBuffer->blupiActionOuf = m_blupiActionOuf;
	pBuffer->blupiFifoNb = m_blupiFifoNb;
	memcpy(pBuffer->blupiFifoPos, m_blupiFifoPos, sizeof(pBuffer->blupiFifoPos));
	memcpy(pBuffer->blupiStartPos, m_blupiStartPos, sizeof(pBuffer->blupiStartPos));
	pBuffer->blupiStartDir[0] = m_blupiStartDir[0];
	pBuffer->blupiStartDir[1] = m_blupiStartDir[1];
	pBuffer->blupiStartDir[2] = m_blupiStartDir[2];
	pBuffer->blupiStartDir[3] = m_blupiStartDir[3];
	pBuffer->jaugeHide[0] = m_jauges[0].GetHide();
	pBuffer->jaugeHide[1] = m_jauges[1].GetHide();
	pBuffer->jaugeType[0] = m_jauges[0].GetType();
	pBuffer->jaugeType[1] = m_jauges[1].GetType();
	pBuffer->jaugeLevel[0] = m_jauges[0].GetLevel();
	pBuffer->jaugeLevel[1] = m_jauges[1].GetLevel();
	pBuffer->blupiLevel = m_blupiLevel;
	pBuffer->energyUnused = m_blupiEnergyUnused;
	pBuffer->bHelicoMarch = m_bHelicoMarch;
	pBuffer->bHelicoStop = m_bHelicoStop;
	pBuffer->bJeepMarch = m_bJeepMarch;
	pBuffer->bJeepStop = m_bJeepStop;
	pBuffer->bFoundCle = m_bFoundCle;
	pBuffer->bPrivate = m_bPrivate;
	pBuffer->bCheatDoors = m_bCheatDoors;
	pBuffer->bSuperBlupi = m_bSuperBlupi;
	pBuffer->bDrawSecret = m_bDrawSecret;
	pBuffer->bJoystick = m_bJoystick;
	pBuffer->mission = m_mission;
	memcpy(pBuffer->doors, m_doors, sizeof(pBuffer->doors));
	pBuffer->nbVies = m_nbVies;
	pBuffer->nbTresor = m_nbTresor;
	pBuffer->totalTresor = m_totalTresor;
	pBuffer->goalPhase = m_goalPhase;
	pBuffer->d8f8 = m_D8F8;
	pBuffer->scrollPoint = m_scrollPoint;
	pBuffer->scrollAdd = m_scrollAdd;
	pBuffer->voyageIcon = m_voyageIcon;
	pBuffer->voyageChannel = m_voyageChannel;
	pBuffer->voyagePhase = m_voyagePhase;
	pBuffer->voyageTotal = m_voyageTotal;
	pBuffer->voyageStart = m_voyageStart;
	pBuffer->voyageEnd = m_voyageEnd;
	pBuffer->decorAction = m_decorAction;
	pBuffer->decorPhase = m_decorPhase;

	if (fwrite(pBuffer, sizeof(DescSave), 1, file) >= 1)
	{
		free(pBuffer);
		fclose(file);
		return TRUE;
	}

error:
	if (pBuffer != NULL) free(pBuffer);
	if (file != NULL) fclose(file);
	return FALSE;

}

BOOL CDecor::CurrentRead(int gamer, int mission, BOOL *pbMission, BOOL *pbPrivate)
{
	char filename[MAX_PATH];
	FILE* file = NULL;
	DescFile* pBuffer = NULL;
	int majRev, minRev;
	int nb, i, x, y;

	sprintf(filename, "data\\s%.3d-%.3d.blp", gamer, mission);
	AddUserPath(filename);

	file = fopen(filename, "rb");
	if (file == NULL) goto error;

	pBuffer = (DescFile*)malloc(sizeof(DescFile));
	if (pBuffer == NULL) goto error;

	nb = fread(pBuffer, sizeof(DescFile), 1, file);
	if (nb < 1) goto error;

	majRev = pBuffer->majRev;

	return TRUE;

error:
	if (pBuffer != NULL) free(pBuffer);
	if (file != NULL) fclose(file);
	return FALSE;
}

BOOL CDecor::CurrentWrite(int gamer, int mission, char* param3)
{
	char filename[MAX_PATH];
	FILE* file = NULL;
	DescFile* pBuffer = NULL;
	int majRev, minRev;
	int nb, i, x, y;

	sprintf(filename, "data\\s%.3d-%.3d.blp", gamer, mission);
	AddUserPath(filename);
	file = fopen(filename, "wb");
	if (file == NULL) goto error;

	pBuffer = (DescFile*)malloc(sizeof(DescFile));
	if (pBuffer == NULL) goto error;

	return TRUE;

error:
	if (pBuffer != NULL) free(pBuffer);
	if (file != NULL) fclose(file);
	return FALSE;
}
