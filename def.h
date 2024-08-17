// Def.h
//

#pragma once

#include <Windows.h>

// prevent WinAPI from overriding our functions
#undef PlaySound
#undef DrawText

#define _DEMO			FALSE	// TRUE=demo, FALSE=complet
#define _INTRO			FALSE	// TRUE si images d'introduction
#define _EGAMES			FALSE	// TRUE version pour eGames
#define _SE				FALSE	// TRUE eGames Special Edition
#define _NOCD			TRUE

#define MAXGAMER		8

#define LXIMAGE			640		// dimensions de la fenêtre de jeu
#define LYIMAGE			480

#define MAXCELX			100		// nb max de cellules d'un monde
#define MAXCELY			100

#define DIMOBJX			64		// dimensions d'un objet
#define DIMOBJY			64

#define DIMEXPLOX		128
#define DIMEXPLOY		128

#define DIMBLUPIX		60		// dimensions de blupi
#define DIMBLUPIY		60

#define DIMEXPLOX		128
#define DIMEXPLOY		128

#define DIMBUTTONX		40		// dimensions d'un button
#define DIMBUTTONY		40

#define DIMJAUGEX		124		// dimensions de la jauge
#define DIMJAUGEY		22

#define POSSTATX		12
#define POSSTATY		220

#define DIMSTATX		60
#define DIMSTATY		30

#define DIMTEXTX		16		// dimensions max d'un caractère
#define DIMTEXTY		16

#define DIMLITTLEX		16		// dimensions max d'un petit caractère
#define DIMLITTLEY		12

#define CHDECOR			0
#define CHOBJECT		1
#define CHBLUPI			2
#define CHBACK			3
#define CHBUTTON		4
#define CHJAUGE			5
#define CHTEXT			6
#define CHLITTLE		7
#define CHMAP			8
#define CHEXPLO			9
#define CHELEMENT		10
#define CHBLUPI1		11
#define CHBLUPI2		12
#define CHBLUPI3		13
#define CHTEMP			14

namespace Ch {
	enum Ch {
		Decor = 0,
		Object,
		Blupi,
		Back,
		Button,
		Jauge,
		Text,
		Little,
		Map,
		Explo,
		Element,
		Blupi_1,
		Blupi_2,
		Blupi_3,
		Temp
	};
};

#define MESS_RESUME 0
#define MESS_PAUSE 1
#define MESS_LOBBY 4
#define MESS_LEAVE 8
#define MESS_LOST 9
#define MESS_START 10
#define MESS_PAUSE2 12
#define MESS_OBJECTSTART 20
#define MESS_OBJECTDELETE 21
#define MESS_MODIFDECOR 30
#define MESS_PLAYSOUND 40
#define MESS_STOPSOUND 41
#define MESS_ASCENSEURSTART 50
#define MESS_ASCENSEUREND 51
#define MESS_STOPCLOUD 60

#define MAXNETMESSAGE		20

// Directions :

#define DIR_LEFT	1
#define DIR_RIGHT	2

namespace Dir {
	enum Dir {
		Left = 1,
		Right
	};
};


// Actions :


#define ACTION_STOP 1
#define ACTION_MARCH 2
#define ACTION_TURN 3
#define ACTION_JUMP 4
#define ACTION_AIR 5
#define ACTION_DOWN 6
#define ACTION_UP 7
#define ACTION_VERTIGO 8
#define ACTION_RECEDE 9
#define ACTION_ADVANCE 10
#define ACTION_CLEAR1 11
#define ACTION_SET 12
#define ACTION_WIN 13
#define ACTION_PUSH 14
#define ACTION_STOPHELICO 15
#define ACTION_MARCHHELICO 16
#define ACTION_TURNHELICO 17
#define ACTION_STOPNAGE 18
#define ACTION_MARCHNAGE 19
#define ACTION_TURNNAGE 20
#define ACTION_STOPSURF 21
#define ACTION_MARCHSURF 22
#define ACTION_TURNSURF 23
#define ACTION_DROWN 24
#define ACTION_STOPJEEP 25
#define ACTION_MARCHJEEP 26
#define ACTION_TURNJEEP 27
#define ACTION_STOPPOP 28
#define ACTION_POP 29
#define ACTION_BYE 30
#define ACTION_STOPSUSPEND 31
#define ACTION_MARCHSUSPEND 32
#define ACTION_TURNSUSPEND 33
#define ACTION_JUMPSUSPEND 34
#define ACTION_HIDE 35
#define ACTION_JUMPAIE 36
#define ACTION_STOPSKATE 37
#define ACTION_MARCHSKATE 38
#define ACTION_TURNSKATE 39
#define ACTION_JUMPSKATE 40
#define ACTION_AIRSKATE 41
#define ACTION_TAKESKATE 42
#define ACTION_DEPOSESKATE 43
#define ACTION_OUF1a 44
#define ACTION_OUF1b 45
#define ACTION_OUF2 46
#define ACTION_OUF3 47
#define ACTION_OUF4 48
#define ACTION_SUCETTE 49
#define ACTION_STOPTANK 50
#define ACTION_MARCHTANK 51
#define ACTION_TURNTANK 52
#define ACTION_FIRETANK 53
#define ACTION_GLU 54
#define ACTION_DRINK 55
#define ACTION_CHARGE 56
#define ACTION_ELECTRO 57
#define ACTION_HELICOGLU 58
#define ACTION_TURNAIR 59
#define ACTION_STOPMARCH 60
#define ACTION_STOPJUMP 61
#define ACTION_STOPJUMPh 62
#define ACTION_MOCKERY 63
#define ACTION_MOCKERYi 64
#define ACTION_OUF5 65
#define ACTION_BALLOON 66
#define ACTION_STOPOVER 67
#define ACTION_MARCHOVER 68
#define ACTION_TURNOVER 69
#define ACTION_RECEDEq 70
#define ACTION_ADVANCEq 71
#define ACTION_STOPECRASE 72
#define ACTION_MARCHECRASE 73
#define ACTION_TELEPORTE 74
#define ACTION_CLEAR2 75
#define ACTION_CLEAR3 76
#define ACTION_CLEAR4 77
#define ACTION_CLEAR5 78
#define ACTION_CLEAR6 79
#define ACTION_CLEAR7 80
#define ACTION_CLEAR8 81
#define ACTION_SWITCH 82
#define ACTION_MOCKERYp 83
#define ACTION_NON 84
#define ACTION_SLOWDOWNSKATE 85
#define ACTION_TAKEDYNAMITE 86
#define ACTION_PUTDYNAMITE 87

namespace Action {
	enum Action {
		Stop = 1,
		March,
		Turn,
		Jump,
		Air,
		Down,
		Up,
		Vertigo,
		Recede,
		Advance,
		Clear_1,
		Set,
		Win,
		Push,
		StopHelico,
		MarchHelico,
		TurnHelico,
		StopNage,
		MarchNage,
		TurnNage,
		StopSurf,
		MarchSurf,
		TurnSurf,
		Drown,
		StopJeep,
		MarchJeep,
		TurnJeep,
		StopPop,
		Pop,
		Bye,
		StopSuspend,
		MarchSuspend,
		TurnSuspend,
		JumpSuspend,
		Hide,
		JumpAie,
		StopSkate,
		MarchSkate,
		TurnSkate,
		JumpSkate,
		AirSkate,
		TakeSkate,
		DeposeSkate,
		Ouf_1a,
		Ouf_1b,
		Ouf_2,
		Ouf_3,
		Ouf_4,
		Sucette,
		StopTank,
		MarchTank,
		TurnTank,
		FireTank,
		Glu,
		Drink,
		Charge,
		Electro,
		HelicoGlu,
		TurnAir,
		StopMarch,
		StopJump,
		StopJump_H,
		Mockery,
		Mockery_I,
		Ouf_5,
		Balloon,
		StopOver,
		MarchOver,
		TurnOver,
		Recede_Q,
		Advance_Q,
		StopEcrase,
		MarchEcrase,
		Teleporte,
		Clear_2,
		Clear_3,
		Clear_4,
		Clear_5,
		Clear_6,
		Clear_7,
		Clear_8,
		Switch,
		Mockery_P,
		Non,
		SlowDownSkate,
		TakeDynamite,
		PutDynamite
	};
};

// Sécurités :

#define SEC_SHIELD 1
#define SEC_POWER 2
#define SEC_CLOUD 3
#define SEC_HIDE 4

namespace Sec {
	enum Sec {
		Shield = 1,
		Power,
		Cloud,
		Hide
	};
}


// Types :

#define TYPE_ASCENSEUR 1
#define TYPE_BOMBEDOWN 2
#define TYPE_BOMBEUP 3
#define TYPE_BULLDOZER 4
#define TYPE_TRESOR 5
#define TYPE_EGG 6
#define TYPE_GOAL 7
#define TYPE_EXPLO1 8
#define TYPE_EXPLO2 9
#define TYPE_EXPLO3 10
#define TYPE_EXPLO4 11
#define TYPE_CAISSE 12
#define TYPE_HELICO 13
#define TYPE_PLOUF 14
#define TYPE_BLUP 15
#define TYPE_BOMBEMOVE 16
#define TYPE_POISSON 17
#define TYPE_TOMATES 18
#define TYPE_JEEP 19
#define TYPE_OISEAU 20
#define TYPE_CLE 21
#define TYPE_DOOR 22
#define TYPE_BALLE 23
#define TYPE_SKATE 24
#define TYPE_SHIELD 25
#define TYPE_POWER 26
#define TYPE_MAGICTRACK 27
#define TYPE_TANK 28
#define TYPE_BULLET 29
#define TYPE_DRINK 30
#define TYPE_CHARGE 31
#define TYPE_BLUPIHELICO 32
#define TYPE_BLUPITANK 33
#define TYPE_GLU 34
#define TYPE_TIPLOUF 35
#define TYPE_POLLUTION 36
#define TYPE_CLEAR 37
#define TYPE_ELECTRO 38
#define TYPE_TRESORTRACK 39
#define TYPE_INVERT 40
#define TYPE_INVERTSTART 41
#define TYPE_INVERTSTOP 42
#define TYPE_GUEPE 44
#define TYPE_OVER 46
#define TYPE_ASCENSEURs 47
#define TYPE_ASCENSEURsi 48
#define TYPE_CLE1 49
#define TYPE_CLE2 50
#define TYPE_CLE3 51
#define TYPE_BRIDGE 52
#define TYPE_TENTACULE 53
#define TYPE_CREATURE 54
#define TYPE_DYNAMITE 55
#define TYPE_DYNAMITEf 56
#define TYPE_SHIELDTRACK 57
#define TYPE_HIDETRACK 58
#define TYPE_EXPLO5 90
#define TYPE_EXPLO6 91
#define TYPE_EXPLO7 92
#define TYPE_EXPLO8 93
#define TYPE_EXPLO9 94
#define TYPE_EXPLO10 95
#define TYPE_BOMBEFOLLOW1 96
#define TYPE_BOMBEFOLLOW2 97
#define TYPE_SPLOUTCH1 98
#define TYPE_SPLOUTCH2 99
#define TYPE_SPLOUTCH3 100
#define TYPE_BOMBEPERSO1 200
#define TYPE_BOMBEPERSO2 201
#define TYPE_BOMBEPERSO3 202
#define TYPE_BOMBEPERSO4 203

namespace Type {
	enum Type {
		Empty = 0,
		Ascenseur,
		BombeDown,
		BombeUp,
		Bulldozer,
		Tresor,
		Egg,
		Goal,
		Explo_1,
		Explo_2,
		Explo_3,
		Explo_4,
		Caisse,
		Helico,
		Plouf,
		Blup,
		BombeMove,
		Poisson,
		Tomates,
		Jeep,
		Oiseau,
		Cle,
		Door,
		Balle,
		Skate,
		Shield,
		Power,
		MagicTrack,
		Tank,
		Bullet,
		Drink,
		Charge,
		BlupiHelico,
		BlupiTank,
		Glu,
		Tiplouf,
		Pollution,
		Clear,
		Electro,
		TresorTrack,
		Invert,
		InvertStart,
		InvertStop,
		Unk_43,
		Guepe,
		Over,
		Ascenseur_S,
		Ascenseur_SI,
		Cle_1,
		Cle_2,
		Cle_3,
		Bridge,
		Tentacule,
		Creature,
		Dynamite,
		Dynamite_F,
		ShieldTrack,
		HideTrack,
		Explo_5,
		Explo_6,
		Explo_7,
		Explo_8,
		Explo_9,
		Explo_10,
		BombeFollow_1,
		BombeFollow_2,
		Sploutch_1,
		Sploutch_2,
		Sploutch_3,

		BombePerso_1 = 200,
		BombePerso_2,
		BombePerso_3,
		BombePerso_4
	};
};


// Steps :

#define STEP_STOPSTART 1
#define STEP_ADVANCE 2
#define STEP_STOPEND 3
#define STEP_RECEDE 4

namespace Step {
	enum Step {
		StopStart = 1,
		Advance,
		StopEnd,
		Recede
	};
}


// Sons :

#define SOUND_CLICK 0
#define SOUND_JUMP1 1
#define SOUND_JUMP2 2
#define SOUND_JUMPEND 3
#define SOUND_JUMPTOC 4
#define SOUND_TURN 5
#define SOUND_VERTIGO 6
#define SOUND_DOWN 7
#define SOUND_FALL 8
#define SOUND_NEW 9
#define SOUND_BOUM 10
#define SOUND_TRESOR 11
#define SOUND_EGG 12
#define SOUND_ENDKO 13
#define SOUND_ENDOK 14
#define SOUND_HELICOSTART 15
#define SOUND_HELICOHIGH 16
#define SOUND_HELICOSTOP 17
#define SOUND_HELICOLOW 18
#define SOUND_LASTTRESOR 19
#define SOUND_UP 20
#define SOUND_LOOKUP 21
#define SOUND_JUMP0 22
#define SOUND_PLOUF 23
#define SOUND_BLUP 24
#define SOUND_SURF 25
#define SOUND_DROWN 26
#define SOUND_ERROR 27
#define SOUND_JEEPSTART 28
#define SOUND_JEEPHIGH 29
#define SOUND_JEEPSTOP 30
#define SOUND_JEEPLOW 31
#define SOUND_BYE 32
#define SOUND_DOOR 33
#define SOUND_SUSPENDTOC 34
#define SOUND_SUSPENDJUMP 35
#define SOUND_SINGE 36
#define SOUND_PATIENT 37
#define SOUND_PUSH 38
#define SOUND_POP 39
#define SOUND_JUMPAIE 40
#define SOUND_RESSORT 41
#define SOUND_STARTSHIELD 42
#define SOUND_STOPSHIELD 43
#define SOUND_STARTPOWER 44
#define SOUND_STOPPOWER 45
#define SOUND_OUF1 46
#define SOUND_OUF2 47
#define SOUND_OUF3 48
#define SOUND_OUF4 49
#define SOUND_SUCETTE 50
#define SOUND_GLU 51
#define SOUND_FIREOK 52
#define SOUND_FIREKO 53
#define SOUND_TAKEGLU 54
#define SOUND_STARTCLOUD 55
#define SOUND_STOPCLOUD 56
#define SOUND_DRINK 57
#define SOUND_CHARGE 58
#define SOUND_ELECTRO 59
#define SOUND_PERSOTAKE 60
#define SOUND_PERSOPOSE 61
#define SOUND_STARTHIDE 62
#define SOUND_STOPHIDE 63
#define SOUND_TIPLOUF 64
#define SOUND_MOCKERY 65
#define SOUND_INVERTSTART 66
#define SOUND_INVERTSTOP 67
#define SOUND_OVERSTOP 68
#define SOUND_BLITZ 69
#define SOUND_ECRASE 70
#define SOUND_TELEPORTE 71
#define SOUND_BRIDGE1 72
#define SOUND_BRIDGE2 73
#define SOUND_ANGEL 74
#define SOUND_SCIE 75
#define SOUND_SWITCHOFF 76
#define SOUND_SWITCHON 77
#define SOUND_JUMPENDb 78
#define SOUND_JUMPTOCb 79
#define SOUND_JUMPENDm 80
#define SOUND_JUMPTOCm 81
#define SOUND_JUMPENDg 82
#define SOUND_JUMPTOCg 83
#define SOUND_JUMPENDo 84
#define SOUND_JUMPTOCo 85
#define SOUND_JUMPENDk 86
#define SOUND_JUMPTOCk 87
#define SOUND_JUMPENDf 88
#define SOUND_JUMPTOCf 89
#define SOUND_JUMPENDh 90
#define SOUND_JUMPTOCh 91
#define SOUND_FOLLOW 92

namespace Sound {
	enum Sound {
		Click,
		Jump_1,
		Jump_2,
		JumpEnd,
		JumpToc,
		Turn,
		Vertigo,
		Down,
		Fall,
		New,
		Boum,
		Tresor,
		Egg,
		End_KO,
		End_OK,
		HelicoStart,
		HelicoHigh,
		HelicoStop,
		HelicoLow,
		LastTresor,
		Up,
		LookUp,
		Jump_0,
		Plouf,
		Blup,
		Surf,
		Drown,
		Error,
		JeepStart,
		JeepHigh,
		JeepStop,
		JeepLow,
		Bye,
		Door,
		SuspendToc,
		SuspendJump,
		Singe,
		Patient,
		Push,
		Pop,
		JumpAie,
		Ressort,
		StartShield,
		StopShield,
		StartPower,
		StopPower,
		Ouf_1,
		Ouf_2,
		Ouf_3,
		Ouf_4,
		Sucette,
		Glu,
		Fire_OK,
		Fire_KO,
		TakeGlu,
		StartCloud,
		StopCloud,
		Drink,
		Charge,
		Electro,
		PersoTake,
		PersoPose,
		StartHide,
		StopHide,
		Tiplouf,
		Mockery,
		InvertStart,
		InvertStop,
		OverStop,
		Blitz,
		Ecrase,
		Teleporte,
		Bridge_1,
		Bridge_2,
		Angel,
		Scie,
		SwitchOff,
		SwitchOn,
		JumpEnd_B, // bois
		JumpToc_B,
		JumpEnd_M, // metal
		JumpToc_M,
		JumpEnd_G, // grotte
		JumpToc_G,
		JumpEnd_O, // végétaux organiques
		JumpToc_O,
		JumpEnd_K, // kids stuff
		JumpToc_K,
		JumpEnd_F, // fromage
		JumpToc_F,
		JumpEnd_H, // herbe
		JumpToc_H,
		Follow
	};
};

// 

#define KEY_LEFT	(1 << 0)
#define KEY_RIGHT	(1 << 1)
#define KEY_UP		(1 << 2)
#define KEY_DOWN	(1 << 3)
#define KEY_JUMP	(1 << 4)
#define KEY_FIRE	(1 << 5)
#define KEY_NONE	0

namespace Key {
	enum Key {
		Left  = 1 << 0,
		Right = 1 << 1,
		Up    = 1 << 2,
		Down  = 1 << 3,
		Jump  = 1 << 4,
		Fire  = 1 << 5
	};
};


// Boutons (play) :

#define MAXBUTTON			40

#define BUTTON_GO			0
#define BUTTON_STOP			1
#define BUTTON_MANGE		2
#define BUTTON_CARRY		3
#define BUTTON_DEPOSE		4
#define BUTTON_ABAT			5
#define BUTTON_ROC			6
#define BUTTON_CULTIVE		7
#define BUTTON_BUILD1		8
#define BUTTON_BUILD2		9
#define BUTTON_BUILD3		10
#define BUTTON_BUILD4		11
#define BUTTON_BUILD5		12
#define BUTTON_BUILD6		13
#define BUTTON_MUR			14
#define BUTTON_PALIS		15
#define BUTTON_ABATn		16
#define BUTTON_ROCn			17
#define BUTTON_PONT			18
#define BUTTON_TOUR			19
#define BUTTON_BOIT			20
#define BUTTON_LABO			21
#define BUTTON_FLEUR		22
#define BUTTON_FLEURn		23
#define BUTTON_DYNAMITE		24
#define BUTTON_BATEAU		25
#define BUTTON_DJEEP		26
#define BUTTON_DRAPEAU		27
#define BUTTON_EXTRAIT		28
#define BUTTON_FABJEEP		29
#define BUTTON_FABMINE		30
#define BUTTON_FABDISC		31
#define BUTTON_REPEAT		32
#define BUTTON_DARMURE		33
#define BUTTON_FABARMURE	34


// Lutins pour la souris

#define SPRITE_ARROW		1
#define SPRITE_POINTER		2
#define SPRITE_MAP			3
#define SPRITE_ARROWU		4
#define SPRITE_ARROWD		5
#define SPRITE_ARROWL		6
#define SPRITE_ARROWR		7
#define SPRITE_ARROWUL		8
#define SPRITE_ARROWUR		9
#define SPRITE_ARROWDL		10
#define SPRITE_ARROWDR		11
#define SPRITE_WAIT			12
#define SPRITE_EMPTY		13
#define SPRITE_FILL			14


// User define message

#define WM_UPDATE				(WM_USER+1)

#define WM_DECOR1				(WM_USER+20)
#define WM_DECOR2				(WM_USER+21)
#define WM_DECOR3				(WM_USER+22)
#define WM_DECOR4				(WM_USER+23)
#define WM_DECOR5				(WM_USER+24)

#define WM_BUTTON0				(WM_USER+200)
#define WM_BUTTON1				(WM_USER+201)
#define WM_BUTTON2				(WM_USER+202)
#define WM_BUTTON3				(WM_USER+203)
#define WM_BUTTON4				(WM_USER+204)
#define WM_BUTTON5				(WM_USER+205)
#define WM_BUTTON6				(WM_USER+206)
#define WM_BUTTON7				(WM_USER+207)
#define WM_BUTTON8				(WM_USER+208)
#define WM_BUTTON9				(WM_USER+209)
#define WM_BUTTON10				(WM_USER+210)
#define WM_BUTTON11				(WM_USER+211)
#define WM_BUTTON12				(WM_USER+212)
#define WM_BUTTON13				(WM_USER+213)
#define WM_BUTTON14				(WM_USER+214)
#define WM_BUTTON15				(WM_USER+215)
#define WM_BUTTON16				(WM_USER+216)
#define WM_BUTTON17				(WM_USER+217)
#define WM_BUTTON18				(WM_USER+218)
#define WM_BUTTON19				(WM_USER+219)
#define WM_BUTTON20				(WM_USER+220)
#define WM_BUTTON21				(WM_USER+221)
#define WM_BUTTON22				(WM_USER+222)
#define WM_BUTTON23				(WM_USER+223)
#define WM_BUTTON24				(WM_USER+224)
#define WM_BUTTON25				(WM_USER+225)
#define WM_BUTTON26				(WM_USER+226)
#define WM_BUTTON27				(WM_USER+227)
#define WM_BUTTON28				(WM_USER+228)
#define WM_BUTTON29				(WM_USER+229)
#define WM_BUTTON30				(WM_USER+230)
#define WM_BUTTON31				(WM_USER+231)
#define WM_BUTTON32				(WM_USER+232)
#define WM_BUTTON33				(WM_USER+233)
#define WM_BUTTON34				(WM_USER+234)
#define WM_BUTTON35				(WM_USER+235)
#define WM_BUTTON36				(WM_USER+236)
#define WM_BUTTON37				(WM_USER+237)
#define WM_BUTTON38				(WM_USER+238)
#define WM_BUTTON39				(WM_USER+239)

#define WM_READ0				(WM_USER+300)
#define WM_READ1				(WM_USER+301)
#define WM_READ2				(WM_USER+302)
#define WM_READ3				(WM_USER+303)
#define WM_READ4				(WM_USER+304)
#define WM_READ5				(WM_USER+305)
#define WM_READ6				(WM_USER+306)
#define WM_READ7				(WM_USER+307)
#define WM_READ8				(WM_USER+308)
#define WM_READ9				(WM_USER+309)

#define WM_WRITE0				(WM_USER+310)
#define WM_WRITE1				(WM_USER+311)
#define WM_WRITE2				(WM_USER+312)
#define WM_WRITE3				(WM_USER+313)
#define WM_WRITE4				(WM_USER+314)
#define WM_WRITE5				(WM_USER+315)
#define WM_WRITE6				(WM_USER+316)
#define WM_WRITE7				(WM_USER+317)
#define WM_WRITE8				(WM_USER+318)
#define WM_WRITE9				(WM_USER+319)

#define WM_PHASE_INIT			(WM_USER+500)
#define WM_PHASE_PLAY			(WM_USER+501)
#define WM_PHASE_BUILD			(WM_USER+502)
#define WM_PHASE_READ			(WM_USER+503)
#define WM_PHASE_WRITE			(WM_USER+504)
#define WM_PHASE_INFO			(WM_USER+505)
#define WM_PHASE_BUTTON			(WM_USER+506)
#define WM_PHASE_TERM			(WM_USER+507)
#define WM_PHASE_WIN			(WM_USER+508)
#define WM_PHASE_LOST			(WM_USER+509)
#define WM_PHASE_STOP			(WM_USER+510)
#define WM_PHASE_SETUP			(WM_USER+511)
#define WM_PHASE_MUSIC			(WM_USER+512)
#define WM_PHASE_PLAYMOVIE		(WM_USER+513)
#define WM_PHASE_WINMOVIE		(WM_USER+514)
#define WM_PHASE_SCHOOL			(WM_USER+515)
#define WM_PHASE_MISSION		(WM_USER+516)
#define WM_PHASE_LASTWIN		(WM_USER+517)
#define WM_PHASE_WRITEp			(WM_USER+518)
#define WM_PHASE_SETUPp			(WM_USER+519)
#define WM_PHASE_REGION			(WM_USER+520)
#define WM_PHASE_INSERT			(WM_USER+521)
#define WM_PHASE_HISTORY0		(WM_USER+522)
#define WM_PHASE_HISTORY1		(WM_USER+523)
#define WM_PHASE_HELP			(WM_USER+524)
#define WM_PHASE_H0MOVIE		(WM_USER+525)
#define WM_PHASE_H1MOVIE		(WM_USER+526)
#define WM_PHASE_H2MOVIE		(WM_USER+527)
#define WM_PHASE_TESTCD			(WM_USER+528)
#define WM_PHASE_MANUEL			(WM_USER+529)
#define WM_PHASE_PRIVATE		(WM_USER+530)
#define WM_PHASE_UNDO			(WM_USER+531)
#define WM_PHASE_BYE			(WM_USER+532)
#define WM_PHASE_SKILL1			(WM_USER+533)
#define WM_PHASE_SKILL2			(WM_USER+534)
#define WM_PHASE_DEMO			(WM_USER+535)
#define WM_PHASE_INTRO1			(WM_USER+536)
#define WM_PHASE_INTRO2			(WM_USER+537)
#define WM_PHASE_PLAYTEST       (WM_USER+538)
#define WM_PHASE_WINMOVIEDESIGN (WM_USER+539)
#define WM_PHASE_WINMOVIEMULTI  (WM_USER+540)

#define WM_PREV					(WM_USER+600)
#define WM_NEXT					(WM_USER+601)
#define WM_MOVIE				(WM_USER+602)
#define WM_PHASE_CREATE 1579
#define WM_PHASE_608	1544

#define WM_PHASE_WINd   1546
#define	WM_PHASE_LOSTd  1547
#define WM_PHASE_WINm   1549
#define WM_PHASE_LOSTm	1550
#define WM_PHASE_READd  1560
#define WM_PHASE_634	1588
#define WM_PHASE_GREAD  1586
#define WM_PHASE_GREADp 1585
#define WM_PHASE_GWRITE 1584
#define WM_PHASE_DOQUIT 1587
#define WM_PHASE_GAMER  1545

#define WM_PHASE_CLEARGAMER 1528

// Types de gestion de la souris.

#define MOUSETYPEGRA			1
#define MOUSETYPEWIN			2
#define MOUSETYPEWINPOS			3

namespace Object {
	enum Object {
		Empty = -1,
		Hili,
		TechSquare_1,
		TechSquare_2,
		TechSquare_3,
		TechSquare_4,
		TechSquare_5,
		TechSquare_6,
		TechSquare_7,
		TechSquare_8,
		TechSquare_9,
		TechSquare_10,
		TechSquare_11,
		TechSquare_12,
		TechSquare_13,
		TechSquare_14,
		TechTriRight_1,
		TechTriRight_2, // 16
		TechTriLeft_1,
		TechTriLeft_2,
		TechSpecial_1,
		TechSpecial_2,
		TechSpecial_3,
		TechSecret_1,
		TechSpecial_4,
		TechSpecial_5,
		TechSpecial_6,
		TechSpecial_7,
		TechSpecial_8,
		TechSpecial_9,
		TechSpecial_10,
		LiftPoint_1,
		LiftPoint_2,
		Caisse_1, // 32
		Caisse_2,
		Caisse_3,
		RockSquare_1,
		RockSquare_2,
		RockSquare_3,
		RockSquare_4,
		RockSquare_5,
		RockSquare_6,
		WoodWall_1,
		WoodWall_2,
		WoodWall_3,
		WoodWall_4,
		WoodWall_5,
		WoodWall_6,
		WoodWall_7,
		Dream_1, // 48
		Dream_2,
		Dream_3,
		Dream_4,
		Dream_5,
		Dream_6,
		Dream_7,
		Dream_8,
		Dream_9,
		Dream_10,
		Dream_11,
		Dream_12,
		Dream_13,
		Dream_14,
		Dream_15,
		Dream_16,
		Dream_17,  // 64
		Dream_18,
		Dream_19,
		Dream_20,
		Lava_1,
		Lava_2,
		Lava_3,
		Lava_4,
		Lava_5,
		TechSecret_2,
		RockTriLeft_1,
		RockTriRight_1,
		Support_1,
		Support_2,
		MechSquare_1,
		MechSquare_2,
		MechSquare_3, // 80
		MechSquare_4,
		MechSquare_5,
		MechSquare_6,
		MechSquare_7,
		MechSecret_1,
		MechSecret_2,
		MechSpecial_1,
		MechSpecial_2,
		MechSpecial_3,
		MechSpecial_4,
		WaterSquare_1,
		WaterSurf_1,
		WaterSurf_2,
		WaterSurf_3,
		WaterSurf_4,
		WaterSquare_2, // 96
		WaterSquare_3,
		WaterSquare_4,
		Splash_1,
		Splash_2,
		Splash_3,
		Splash_4,
		Bubble_1,
		Bubble_2,
		Bubble_3,
		Bubble_4,
		GrassSquare_1,
		GrassLeft,
		GrassRight,
		WindLeft_1,
		WindLeft_2, // 112
		WindLeft_3,
		WindLeft_4,
		WindRight_1,
		WindRight_2,
		WindRight_3,
		WindRight_4,
		WindUp_1,
		WindUp_2,
		WindUp_3,
		WindUp_4,
		WindDown_1,
		WindDown_2,
		WindDown_3,
		WindDown_4,
		FanLeft_1,
		FanLeft_2, // 128
		FanLeft_3,
		FanRight_1,
		FanRight_2,
		FanRight_3,
		FanUp_1,
		FanUp_2,
		FanUp_3,
		FanDown_1,
		FanDown_2,
		FanDown_3,
		Bar_1,
		Bookshelf_1,
		Bookshelf_2,
		Bookshelf_3,
		Bookshelf_4,
		Bookshelf_5,
		RockSquare_7, // 144
		RockSquare_8,
		RockSquare_9,
		RockSquare_10,
		RockSquare_11,
		RockSquare_12,
		RockSquare_13,
		RockSquare_14,
		RockSquare_15,
		RockSquare_16,
		RockTriLeft_2,
		RockTriRight_2,
		RockSquare_17,
		GrassSquare_2,
		Course_1,
		Course_2,
		Course_3, // 160
		Course_4,
		Course_5,
		Course_6,
		Course_7,
		Course_8,
		CourseDone_1,
		CourseDone_2,
		CourseDone_3,
		CourseDone_4,
		CourseDone_5,
		CourseDone_6,
		CourseDone_7,
		CourseDone_8,
		Level_1,
		Level_2,
		Level_3, // 176
		Level_4,
		Level_5,
		Level_6,
		Level_7,
		Level_8,
		DoorLevel,
		DoorCourse,
		CourseBack,
		RockSecret,
		Facade_1,
		Facade_2,
		Facade_3,
		Facade_4,
		Facade_5,
		Facade_6,
		Facade_7, // 192
		Roof_1,
		Roof_2,
		Roof_3,
		Roof_4,
		Roof_5,
		Support_3,
		Support_4,
		Support_5,
		Support_6,
		Bar_2,
		Marine_1,
		Marine_2,
		Marine_3,
		Marine_4,
		Marine_5,
		Marine_6, // 208
		Spring_1,
		Spring_2,
		Spring_3,
		Spring_4,
		Spring_5,
		Invisible,
		KidsSquare_1,
		KidsSquare_2,
		KidsSquare_3,
		KidsSquare_4,
		KidsSquare_5,
		KidsSquare_6,
		KidsSquare_7,
		KidsSquare_8,
		KidsSpecial_1,
		KidsSpecial_2, // 224
		KidsSpecial_3,
		KidsSpecial_4,
		KidsSpecial_5,
		KidsSpecial_6,
		KidsSpecial_7,
		KidsSquare_9,
		KidsSquare_10,
		KidsSpecial_8,
		KidsSquare_11,
		KidsSquare_12,
		Support_7,
		Support_8,
		DitherMask,
		Charger_1,
		Charger_2,
		Charger_3, // 240
		Charger_4,
		Charger_5,
		Charger_6,
		Splash_5,
		Unk_F5,
		CheeseSquare_1,
		CheeseSquare_2,
		CheeseSquare_3,
		CheeseSquare_4,
		Pipes_1,
		Pipes_2,
		Pipes_3,
		Pipes_4,
		Pipes_5,
		Pipes_6,
		Pipes_7, // 256
		Pipes_8,
		Pipes_9,
		Pipes_10,
		Pipes_11,
		Bricks_1,
		Bricks_2,
		Bricks_3,
		CheeseSupport_1,
		CheeseSupport_2,
		CheeseSupport_3,
		CheeseSupport_4,
		CheeseSupport_5,
		CheeseSupport_6,
		CheeseSupport_7,
		CheeseSupport_8,
		CheeseSupport_9, // 272
		CheeseSupport_10,
		CheeseSupport_11,
		CheeseSupport_12,
		CheeseSupport_13,
		CheeseSupport_14,
		CheeseSupport_15,
		CheeseSupport_16,
		CheeseSupport_17,
		CheeseSupport_18,
		CheeseSupport_19,
		Bricks_4,
		Cave_1,
		CaveSupport_1,
		CaveSupport_2,
		CaveSupport_3,
		CaveSupport_4, // 288
		CaveSupport_5,
		CaveSupport_6,
		CaveSupport_7,
		CaveSupport_8,
		CaveSupport_9,
		CaveSupport_10,
		CaveSupport_11,
		CaveSupport_12,
		CaveSupport_13,
		CaveSupport_14,
		CaveSupport_15,
		CaveSupport_16,
		Cave_2,
		CaveSupport_17,
		CaveSupport_18,
		LightningMachine, // 304
		Lightning_1,
		Lightning_2,
		Lightning_3,
		Lightning_4,
		Course_9,
		CourseDone_9,
		Conveyor_1,
		Conveyor_2,
		Conveyor_3,
		Conveyor_4,
		Conveyor_5,
		Conveyor_6,
		Crusher_1,
		Crusher_2,
		Crusher_3,
		Crusher_4, // 320
		Crusher_5,
		Crusher_6,
		Crusher_7,
		Vanish_1,
		Vanish_2,
		Vanish_3,
		Vanish_4,
		Vanish_5,
		Vanish_6,
		Teleporter_1,
		Teleporter_2,
		Teleporter_3,
		Teleporter_4,
		DoorRed,
		DoorGreen,
		DoorBlue, // 336
		CaveSecret,
		Cave_3,
		CheeseSecret,
		CheeseSquare_5,
		Slime_1,
		Slime_2,
		Slime_3,
		Slime_4,
		Slime_5,
		Slime_6,
		Slime_7,
		Slime_8,
		Slime_9,
		Slime_10,
		Slime_11,
		Slime_12, // 352
		Slime_13,
		Slime_14,
		Slime_15,
		Slime_16,
		Slime_17,
		Slime_18,
		Slime_19,
		Slime_20,
		Slime_21,
		Slime_22,
		Slime_23,
		FragileBridge_1,
		FragileBridge_2,
		FragileBridge_3,
		FragileBridge_4,
		FragileBridge_5, // 368
		FragileBridge_6,
		FragileBridge_7,
		FragileBridge_8,
		FragileBridge_9,
		SlimeTrapFloor_1,
		SlimeTrapFloor_2,
		Support_9,
		Support_10,
		Support_11,
		Saw_1,
		Saw_2,
		Saw_3,
		Saw_4,
		Saw_5,
		Saw_6,
		SawSwitchOn, // 382
		SawSwitchOff,
		Palace_1,
		Palace_2,
		Palace_3,
		Palace_4,
		Palace_5,
		Palace_6,
		Palace_7,
		Palace_8,
		Palace_9,
		Palace_10,
		Palace_11,
		Palace_12,
		PalaceElement_1,
		PalaceElement_2,
		PalaceElement_3, // 398
		SpiderWeb_1,
		SpiderWeb_2,
		SpiderWeb_3,
		SlimeTrapCeiling_1,
		SlimeTrapCeiling_2,
		SlimeTrapCeiling_3,
		SlimeTrapCeiling_4,
		SlimeTrapCeiling_5,
		SlimeTrapCeiling_6,
		SlimeTrapCeiling_7,
		Course_10,
		Course_11,
		Course_12,
		Course_13,
		Course_14,
		CourseDone_10, // 414
		CourseDone_11,
		CourseDone_12,
		CourseDone_13,
		CourseDone_14,
		DoorTreasure_1,
		DoorTreasure_2,
		DoorTreasure_3,
		DoorTreasure_4,
		DoorTreasure_5,
		DoorTreasure_6,
		DoorTreasure_7,
		DoorTreasure_8,
		DoorTreasure_9,
		DoorTreasure_10,
		DoorTreasure_11,
		DoorTreasure_12,	// 430
		DoorTreasure_13,
		DoorTreasure_14,
		DoorTreasure_15,
		DoorTreasure_16,
		DoorTreasure_17,
		DoorTreasure_18,
		DoorTreasure_19,
		DoorTreasure_20
	};
}

#define CLE_RED (1 << 0)
#define CLE_GREEN (1 << 1)
#define CLE_BLUE (1 << 2)

struct POINT
{
	int x;
	int y;

	POINT operator+(const POINT& a) const
	{
		return { a.x + x, a.y + y };
	}

	POINT operator-(const POINT& a) const
	{
		return { a.x - x, a.y - y };
	}

	POINT operator*(const POINT& a) const
	{
		return { a.x * x, a.y * y };
	}

	POINT operator/(const POINT& a) const
	{
		return { a.x / x, a.y / y };
	}

	POINT operator*(const int& a) const
	{
		return { x * a, y * a };
	}

	POINT operator/(const int& a) const
	{
		return { x / a, y / a };
	}

	POINT operator+=(const POINT& a)
	{
		return { x += a.x, y += a.y };
	}

	POINT operator-=(const POINT& a)
	{
		return { x -= a.x, y -= a.y };
	}

	POINT operator*=(const POINT& a)
	{
		return { x *= a.x, y *= a.y };
	}

	POINT operator/=(const POINT& a)
	{
		return { x /= a.x, y /= a.y };
	}

	POINT operator*=(const int& a)
	{
		return { x *= x, y *= a };
	}

	POINT operator/=(const int& a)
	{
		return { x /= a, y /= a };
	}
};