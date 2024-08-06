// Decor.h

#pragma once

#include <Windows.h>
#include <minwindef.h>

#include "DEF.H"
#include "JAUGE.H"
#include "SOUND.H"
#include "PIXMAP.H"
#include "network.h"
#include "jauge.h"
#include "event.h"

/////////////////////////////////////////////////////////////////////////////

#define MAXNETMESSAGE 20
#define MAXMOVEOBJECT	200

// Descripteur d'une cellule du décor.
typedef struct
{
	short icon;
}
Cellule;
// Cette structure doit être la plus petite possible, car
// il en existe un tableau de 100x100 = 10'000 cellules !


typedef struct
{
	short   type;
	short   stepAdvance;
	short   stepRecede;
	short   timeStopStart;
	short	timeStopEnd;
	short	unknown1;
	POINT	posStart;
	POINT	posEnd;
	POINT	posCurrent;
	short	step;
	short	time;
	short	phase;
	short	channel;
	short	icon;
	short	unknown2;
}
MoveObject;

typedef struct
{
}
GameData;

typedef struct
{
	char type;
	char data1;
	short x;
	short y;
	short channel;
}
NetMessage;

class CDecor
{
public:
	CDecor();
	~CDecor();

	// Decor.cpp
	void	SetShiftOffset(POINT offset);
	POINT	ConvCelToPos(POINT cel);
	POINT	ConvPosToCel(POINT pos, BOOL bMap=FALSE);
	POINT	ConvPosToCel2(POINT pos);

	void	Create(HWND hWnd, CSound *pSound, CPixmap *pPixmap, CNetwork *pNetwork);
	BOOL	LoadImages();
	void	InitGamer();
	BOOL	AddLinkCaisse(int rank);
	void	InitDecor(int channel, int icon);
	void	InitAfterBuild();
	void	SetTime(int time);
	int	    GetTime();
	void	PlayPrepare(BOOL bTest);
	void	BuildPrepare();
	int		IsTerminated();
	void	MoveStep();
	int		GetBlupiChannelStandard();
	int		GetBlupiChannelActual();
	int		GetIconPerso();
	BOOL	BlitzActif(int celx, int cely);
	void	Build(RECT rect);
	void	DrawInfo();
	POINT	DecorNextAction();
	void	TreatInput(UINT input);
	void	SetSpeedX(double speed);
	void	SetSpeedY(double speed);
	int		SoundEnviron(int sound, int obstacle);
	void	StopSound(CSound sound);
	void	AdaptMotorVehicleSound();
	BOOL	TestPushCaisse(int i, POINT pos, BOOL bPop);
	void	SearchLinkCaisse(int rank, BOOL bPop);
	void	ResetHili();
	BOOL	LoadImages();
	BOOL	LoadBackgroundImages();
	BOOL	TestPushOneCaisse(int i, POINT move, int b);
	void	ClearFog();
	void	ClearFire();
	void	SetBuild(BOOL bBuild);
	void	EnableFog(BOOL bEnable);
	BOOL	GetInvincible();
	void	SetInvincible(BOOL bInvincible);
	BOOL	GetSuper();
	void	SetSuper(BOOL bSuper);
	void	FlipOutline();
	BOOL	PutFloor(POINT cel, int channel, int icon);
	BOOL	PutObject(POINT cel, int channel, int icon);
	BOOL	GetFloor(POINT cel, int &channel, int &icon);
	BOOL	GetObject(POINT cel, int &channel, int &icon);
	BOOL	SetFire(POINT cel, BOOL bFire);

	void	SetCoin(POINT coin, BOOL bCenter=FALSE);
	POINT	GetCoin();
	POINT	GetHome();
	void	MemoPos(int rank, BOOL bRecord);

	void	SetTime(int time);
	int		GetTime();

	void	SetMusic(int music);
	int		GetMusic();

	void	SetSkill(int skill);
	int		GetSkill();

	void	SetRegion(int region);
	int		GetRegion();

	void	SetInfoMode(BOOL bInfo);
	BOOL	GetInfoMode();
	void	SetInfoHeight(int height);
	int		GetInfoHeight();

	int 	GetTargetLevel();
	void	GetBlupiInfo(BOOL bHelico, BOOL bJeep, BOOL bSkate, BOOL bNage);

	char*	GetButtonExist();

	void	BuildPutBlupi();
	void	BuildMoveFloor(int x, int y, POINT pos, int rank);
	void	BuildMoveObject(int x, int y, POINT pos, int rank);
	void	BuildGround(RECT clip);
	void	Build(RECT clip, POINT posMouse);
	void	NextPhase(int mode);

	int		CountFloor(int channel, int icon);
	int		CelOkForAction(POINT cel, int action, int rank,
						   int   icons[4][4],
						   POINT &celOutline1,
						   POINT &celOutline2);
	int		CelOkForAction(POINT cel, int action, int rank);
	int		GetHiliRankBlupi(int nb);
	void	CelHili(POINT pos, int action);
	void	CelHiliButton(POINT cel, int button);
	void	CelHiliRepeat(int list);
	int		GetResHili(POINT posMouse);
	void	HideTooltips(BOOL bHide);

	void	UndoOpen();
	void	UndoClose();
	void	UndoCopy();
	void	UndoBack();
	BOOL	IsUndo();
	BOOL	GetShowSecret();
	BOOL	GetNetPacked();
	BOOL	GetNetMovePredict();
	UINT	GetPhase();
	char	GetMissionTitle();
	void	SetRegion(int region);
	int		GetMusic();
	void	SetMusic(int music);
	void	GetDims(POINT* ptr);
	void	SetDims(POINT dims);
	int		GetNbVies();
	void	SetNbVies(int nbVies);
	BOOL	GetPause();
	void	SetPause(BOOL bPause);
	void	GetDoors(int doors);
	void	InitalizeDoors();
	void	SetAllMissions(BOOL CheatDoors);
	void	CheatAction(int cheat, MoveObject moveObject);
	void	SetAccessBuild(BOOL build);
	void	SetNetPacked(BOOL net);
	void	SetNetMovePredict(BOOL netmove);
	BOOL	GetNetDebug();
	void	SetNetDebug(BOOL bNetDebug);
	void	UpdateNetDebug(char *str);
	void	SetMulti(BOOL bMulti);
	void	SetTeam(int team);
	void	BlupiSearchIcon();
	BOOL	BlupiIsGround();
	RECT	BlupiRect(POINT pos);
	void	BlupiAdjust();
	BOOL	BlupiBloque(POINT pos, int dir);
	void	BlupiStep();
	void	BlupiDead(int action, int action2);
	POINT	GetPosDecor(POINT pos);
	void	BlupiAddFifo(POINT pos);
	BOOL	DecorDetect(RECT rect, BOOL bCaisse);
	BOOL	TestPath(RECT rect, POINT start, POINT *end);
	void	MoveObjectPollution();
	void	MoveObjectPlouf(POINT pos);
	void	MoveObjectTiplouf(POINT pos);
	int		GetBlupiChannelStandard();
	void	MoveObjectBlup(POINT pos);
	void	ActiveSwitch(BOOL bState, POINT cel);
	BOOL	IsLave(POINT pos);
	BOOL	IsPiege(POINT pos);
	BOOL	IsGoutte(POINT pos, BOOL bAlways);
	BOOL	IsScie(POINT pos);
	BOOL	IsSwitch(POINT pos, POINT *celSwitch);
	BOOL	IsEcraseur(POINT pos);
	BOOL	IsBlitz(POINT pos, BOOL bAlways);
	BOOL	IsRessort(POINT pos);
	BOOL	IsTemp(POINT pos);
	BOOL	IsBridge(POINT pos, POINT *celBridge);
	int		IsDoor(POINT pos, POINT *celPorte);
	int		IsTeleporte(POINT pos);
	BOOL	SearchTeleporte(POINT pos, POINT *newpos);
	BOOL	IsSurfWater(POINT pos);
	BOOL	IsDeepWater(POINT pos);
	BOOL	IsOutWater(POINT pos);
	BOOL	IsPassIcon(int icon);
	BOOL	IsBlocIcon(int icon);
	void	FlushBalleTraj();
	void	SetBalleTraj(POINT pos);
	BOOL	IsBalleTraj(POINT pos);
	void	FlushMoveTraj();
	void	SetMoveTraj(POINT pos);
	BOOL	IsMoveTraj(POINT pos);
	int		SearchDistRight(POINT pos, POINT dir, int type);
	BOOL	IsVentillo(POINT pos);
	void	NetStopCloud(int rank);
	void	StartSploutchGlu(POINT pos);
	BOOL	ObjectStart(POINT pos, int type, int speed, int _foo);
	BOOL	ObjectDelete(POINT pos, int type, int _foo);
	void	ModifDecor(POINT pos, int icon, BOOL _foo);
	void	NetPlaySound(short channel, POINT pos);
	void	NetStopSound(short channel);
	void	NetDataFlush();
	void	FUN_155e0(byte _foo, short _bar);
	void	TreatNetData();
	void	DoNetSmooth(int player);
	void	NetFUN_15d50();
	void	FUN_15da0(int rank, short phase);
	void	NetPlayerCollide(POINT pos, int &result);
	void	NetMessageIndexFlush();
	BOOL	NetMessagePush(NetMessage *message);
	BOOL	NetMessagePop(NetMessage *message);
	void	NotifFlush();
	void	NotifPop();
	void	NotifPush(char *str);
	void	NotifStep();
	void	MoveObjectStep();
	void	MoveObjectStepLine(int i);
	void*	MoveObjectStepIcon(int i);
	void	DynamiteStart(int i, int dx, int dy);
	int		AscenseurDetect(RECT rect, POINT oldpos, POINT newpos);
	int		AscenseurVertigo(int i, BOOL *bVertigoLeft, BOOL *bVertigoRight);
	BOOL	AscenseurShift(int i);
	void	AscenseurSynchro(int i);
	
	void	UpdateCaisse();
	BOOL	TestPushCaisse(int i, POINT pos, BOOL bPop);
	BOOL	TestPushOneCaisse(int i, POINT move, int b);
	void	SearchLinkCaisse(int rank, BOOL bPop);
	BOOL	AddLinkCaisse(int rank);
	int		CaisseInFront();
	int		CaisseGetMove(int max);
	BOOL	MockeryDetect(POINT pos);
	BOOL	BlupiElectro(POINT pos);
	void	MoveObjectFollow(POINT pos);
	int		MoveObjectDetect(POINT pos, BOOL *pbNear);
	int		MoveAscenseurDetect(POINT pos, int height);
	int		MoveChargeDetect(POINT pos);
	int		MovePersoDetect(POINT pos);
	int		MoveObjectSomething(POINT pos);
	int		MoveObjectDelete(POINT pos);
	int		MoveObjectFree();
	int		SortGetType(int type);
	void	MoveObjectSort();
	void	MoveObjectPriority(int i);
	int		MoveObjectSearch(POINT pos, int type);
	void	VoyageGetPosVie(POINT *out, int nbVies);
	void	VoyageInit(POINT start, POINT end, int icon, int channel);
	void	VoyageStep();
	void	VoyageDraw();
	BOOL	IsRightBorder(int x, int y, int dx, int dy);
	BOOL	IsFromage(int x, int y);
	BOOL	IsGrotte(int x, int y);
	void	AdaptMidBorder(int x, int y);
	void	AdaptBorder(POINT cel);
	BOOL	MultiplayerCameraSomething(int foo, int bar);
	void	GetMissionPath(char *out, int gamer, int mission, BOOL bUser);
	BOOL	CurrentWrite(int gamer, int mission, BOOL bUser);
	BOOL	CurrentRead(int gamer, int mission, BOOL bUser);
	BOOL	MissionPathSomething(int gamer, int mission, BOOL bUser);
	BOOL	Read(int gamer, int mission, BOOL bUser);
	BOOL	FUN_1bad0(int foo, int bar, void *baz, void *qux);
	BOOL	FUN_1c190(int foo, int bar, char *str);
	BOOL	SearchWorld(int world, POINT *blupi, int *dir);
	BOOL	SearchDoor(int n, POINT *cel, POINT *blupi);
	BOOL	AdaptDoors(BOOL bPrivate, int mission);
	void	OpenDoorsTresor();
	void	OpenDoor(POINT cel);
	void	OpenDoorsWin();
	void	OpenGoldsWin();
	void	DoorsLost();

	void	SetMission(int mission);

	// ?
	void	GetMissionsCleared();
	void	SetDemoState(BOOL demoState);
	BOOL	CurrentWrite(int gamer, int mission, BOOL bUser);
	BOOL	CurrentRead(int gamer, int mission, BOOL bUser);
	void	SetJoystickEnable(BOOL bJoystick);
	BOOL	GetShowSecret();

	void	MemorizeDoors(BYTE* doors);


	// Network Related Functions
	void	NetMessageIndexFlush();
	void	NotifFlush();
	void	NetDataFlush();
	void	NetPlaySound(short channel, POINT pos);
	void	NetStopCloud(int rank);
	BOOL	NetMessagePush(NetMessage* message);
	BOOL	DrawMap(BOOL bPlay, int player);
	void	NetSendData(BYTE bufferSize, UCHAR send);
	void	NetPlayerCollide(POINT pos, int* out);
	void	TreatNetData();
	void	OutputNetDebug(char* text);


protected:
	HWND		m_hWnd;
	CSound*		m_pSound;
	CPixmap*	m_pPixmap;
    CNetwork*	m_pNetwork;
    Cellule		m_decor[MAXCELX][MAXCELY];
	Cellule		m_bigDecor[MAXCELX][MAXCELY];
	byte		m_balleTraj[MAXCELX][MAXCELY/8+1];
	byte		m_moveTraj[MAXCELX][MAXCELY/8+1];
    MoveObject  m_moveObject[MAXMOVEOBJECT];
    int         m_keyPress;
    int         m_lastKeyPress;
    POINT       m_posDecor;
    POINT       m_dimDecor;
    POINT       m_posCelHili;
	POINT		m_dimCelHili;
	int			m_2ndPositionCalculationSlot;

    int		    m_phase;
    int         m_term;
	int			m_music;
	int			m_region;
	int			m_lastRegion;

	int			m_iconLift;

	int			m_time;
	char		m_missionTitle[100];
	BOOL		m_bPause;
    int			m_nbRankCaisse;
	int			m_rankCaisse[MAXMOVEOBJECT];
	int			m_nbLinkCaisse;
	int			m_linkCaisse[MAXMOVEOBJECT];
    POINT       m_blupiPos;
    POINT       m_blupiValidPos;
    int			m_blupiAction;
    int         m_blupiDir;
    int         m_blupiPhase;
    POINT       m_blupiVitesse;
    int			m_blupiIcon;
	int			m_blupiSec;
	int			m_blupiChannel;
	POINT		m_blupiVector;
	int			m_blupiTransport;
	BOOL		m_blupiFocus;
    BOOL        m_blupiAir;
    BOOL*       m_blupiHelico;
    BOOL        m_blupiOver;
    BOOL        m_blupiJeep;
    BOOL        m_blupiTank;
    BOOL        m_blupiSkate;
    BOOL        m_blupiNage;
    BOOL        m_blupiSurf;
    BOOL        m_bInWind;
	BOOL		m_blupiVent;
    BOOL        m_blupiSuspend;
    BOOL        m_blupiJumpAie;
    BOOL        m_blupiShield;
    BOOL        m_blupiPower;
    BOOL        m_blupiCloud;
    BOOL        m_blupiHide;
	BOOL        m_blupiInvert;
    BOOL        m_blupiBalloon;
    BOOL        m_blupiEcrase;
	POINT		m_blupiPosHelico;
	POINT		m_blupiPosMagic;
	BOOL		m_blupiRestart;
	BOOL		m_blupiFront;
	int			m_blupiBullet;
	int			m_blupiCle;
	int			m_blupiPerso;
	int			m_blupiDynamite;
	int			m_blupiNoBarre;
	int			m_blupiTimeShield;
	int			m_blupiTimeFire;
	int			m_blupiTimeNoAsc;
	int			m_blupiTimeMockery;
	int			m_blupiTimeOuf;
	int			m_blupiActionOuf;
	int			m_blupiFifoNb;
	POINT		m_blupiFifoPos[10];
	POINT		m_blupiStartPos[4];
	int			m_blupiStartDir[4];
	int			m_D42C;
	int			m_jaugeSomething1;
	int			m_jaugeSomething2;
	int			m_jaugeSomething3;
	int			m_jaugeSomething4;
	BOOL		m_bMulti;
	int			m_team;
	int			m_netPacketsSent;
	int			m_netPacketsSent2;
	int			m_netPacketsReceived;
	int			m_netPacketsReceived2;

	int			unknown[55];

	NetMessage	m_netMessages[MAXNETMESSAGE];
	int			m_soundEventIndex1;
	int			m_soundEventIndex2;

	int			m_D5DC;

	char		m_messages[4][100];

	int			m_D770;

	CJauge		m_jauges[2];
	int			m_blupiLevel;
	int			m_blupiEnergyUnused;
	BOOL		m_bHelicoMarch;
	BOOL		m_bHelicoStop;
	BOOL		m_bJeepMarch;
	BOOL		m_bJeepStop;
	BOOL		m_bFoundCle;
	BOOL		m_bPrivate;
	BOOL		m_bCheatDoors;		// opendoors
	BOOL		m_bSuperBlupi;		// megablupi
	BOOL        m_bDrawSecret;  	// showsecret
    BOOL        m_bBuildOfficialMissions; 	// xmission/xnjttjpo
    BOOL        m_bNetPacked;		// netpacked
    BOOL        m_bNetMovePredict;  // ynosmooth
    BOOL        m_bNetDebug;		// znetdebug
	BOOL		m_bJoystick;
	int			m_bD814;
    int         m_mission;
	BYTE        m_doors[200];
    int         m_nbVies;
    int         m_nbTresor;
    int         m_totalTresor;
	int			m_goalPhase;
	int			m_detectIcon;

	int			m_D8F8;

    POINT       m_scrollPoint;
    POINT       m_scrollAdd;
    int         m_voyageIcon;
    int         m_voyageChannel;
    int         m_voyagePhase;
    int         m_voyageTotal;
    POINT       m_voyageStart;
    POINT       m_voyageEnd;
	int 		m_decorAction;
	int 		m_decorPhase;
	int 		m_lastDecorIndexes[200];
	
	int			reserve[11];

	BYTE 		dummy[100000];
};

POINT GetCel (int x, int y);
POINT GetCel (POINT cel, int x, int y);
BOOL IsValidCel (POINT cel);
POINT GetVector (int direct);