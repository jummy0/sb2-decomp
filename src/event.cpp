// Event.cpp
//

#pragma once

using namespace std;

#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <ddraw.h>
#include <direct.h>
#include "def.h"
#include "resource.h"
#include "pixmap.h"
#include "sound.h"
#include "decor.h"
#include "movie.h"
#include "button.h"
#include "menu.h"
#include "jauge.h"
#include "event.h"
#include "text.h"
#include "misc.h"
#include "network.h"

#pragma warning (disable : 4996)
#pragma warning (disable : 4700)

#define DEF_TIME_HELP  10000
#define DEF_TIME_DEMO  1000
#define MAXDEMO        2000
#define MAXINDEX	   20


typedef struct
{
	short majRev;
	short minRev;
	short reserve1[9];
	char name[100];
	short mission;
	short speed;
	short bMovie;
	short bHiliInfoButton;
	short audioVolume;
	short midiVolume;
	short bBuildOfficialMissions;
	short prive;
	short skillUnused;
	short multi;
	short reserve2[92];
	short nbVies;
	BYTE doors[200];
}
DescInfo;

// Toutes les premi�res lettres doivent
// �tre diff�rentes !

static char cheat_code[25][60] =
{
	"XMISSION",		// 0 (xnjttjpo)
	"OPENDOORS",	// 1
	"CLEANALL",		// 2
	"MEGABLUPI",	// 3
	"LAYEGG",		// 4
	"KILLEGG",		// 5
	"FUNSKATE",		// 6
	"GIVECOPTER",	// 7
	"JEEPDRIVE",	// 8 
	"ALLTREASURE",
	"ENDGOAL",
	"SHOWSECRET",
	"ROUNDSHIELD",
	"QUICKLOLLIPOP",
	"TENBOMBS",
	"BIRDLIME",
	"DRIVETANK",
	"POWERCHARGE",
	"HIDEDRINK",
	"NETPACKED",
	"ZNETDEBUG",
	"YNOSMOOTH",
	"IOVERCRAFT",
	"UDYNAMITE",
	"WELLKEYS",
};



/////////////////////////////////////////////////////////////////////////////

static Phase table[] =
{
	{
		WM_PHASE_TESTCD,
		"init.blp",
		FALSE,
		FALSE,
		{ 0 }
	},
	{
		WM_PHASE_INTRO1,
		"intro1.blp",
		FALSE,
		FALSE,
		{ 0 }
	},
	{
		WM_PHASE_INTRO2,
		"intro2.blp",
		FALSE,
		FALSE,
		{ 0 }
	},
	{
		WM_PHASE_INIT,
		"init.blp",
		FALSE,
		FALSE,
		{
			{
				WM_PHASE_GAMER,
				0,{ 1, 48 },
				86, 410,
				{ 1, 109 }
			},
			{
				WM_PHASE_DEMO,
				0,{ 1, 84 },
				128, 410,
				{ 1, 212 }
			},
			{
				WM_PHASE_BYE,
				0,{ 1, 6 },
				540, 410,
				{ 1, 106 }
			},
			{ 0 }
		},
	},
	{
		WM_PHASE_GAMER,
		"gamer.blp",
		FALSE,
		FALSE,
		{
			{
				WM_BUTTON1,
				0,{ 0 },
				60, 58,
				{ 1, 117 }
			},
			{
				WM_BUTTON2,
				0,{ 0 },
				60, 98,
				{ 1, 117 }
			},
			{
				WM_BUTTON3,
				0,{ 0 },
				60, 138,
				{ 1, 117 }
			},
			{
				WM_BUTTON4,
				0,{ 0 },
				60, 178,
				{ 1, 117 }
			},
			{
				WM_BUTTON5,
				0,{ 0 },
				60, 218,
				{ 1, 117 }
			},
			{
				WM_BUTTON6,
				0,{ 0 },
				60, 258,
				{ 1, 117 }
			},
			{
				WM_BUTTON7,
				0,{ 0 },
				60, 298,
				{ 1, 117 }
			},
			{
				WM_BUTTON8,
				0,{ 0 },
				60, 338,
				{ 1, 117 }
			},
			{
				WM_PHASE_NAMEGAMER,
				0,{ 1, 46 },
				546, 178,
				{ 1, 118 }
			},
			{
				WM_PHASE_CLEARGAMER,
				0,{ 1, 36 },
				546, 220,
				{ 1, 127 }
			},
			{
				WM_PHASE_DOPLAY,
				0,{ 1, 48 },
				65, 414,
				{ 1, 195 }
			},
			{
				WM_PHASE_SERVICE,
				0,{ 1, 83 },
				107, 414,
				{ 1, 196 }
			},
			{
				WM_PHASE_PRIVATE,
				0,{ 1, 49 },
				149, 414,
				{ 1, 188 }
			},
			{
				WM_PHASE_GREAD,
				0,{ 1, 52 },
				191, 414,
				{ 1, 264 }
			},
			{
				WM_PHASE_SETUP,
				0,{ 1, 47 },
				330, 414,
				{ 1, 128 }
			},
			{
				WM_PHASE_INIT,
				0,{ 1, 40 },
				540, 414,
				{ 1, 111 }
			},
			{ 0 }
		},
	},
	{
		WM_PHASE_NAMEGAMER,
		"name.blp",
		FALSE,
		FALSE,
		{
			{
				WM_PHASE_DONAMEGAMER,
				0,{ 1, 18 },
				222, 326,
				{ 1, 174 }
			},
			{
				WM_PHASE_GAMER,
				0,{ 1, 36 },
				378, 326,
				{ 1, 175 }
			},
			{ 0 }
		},
	},
	{
		WM_PHASE_CLEARGAMER,
		"clear.blp",
		FALSE,
		FALSE,
		{
			{
				WM_PHASE_DOCLEARGAMER,
				0,{ 1, 18 },
				222, 326,
				{ 1, 176 }
			},
			{
				WM_PHASE_GAMER,
				0,{ 1, 36 },
				378, 326,
				{ 1, 177 }
			},
			{ 0 }
		},
	},
	{
		WM_PHASE_SERVICE,
		"service.blp",
		FALSE,
		FALSE,
		{
			{
				WM_BUTTON1,
				0,{ 1, 51 },
				140, 110,
				{ 0 }
			},
			{
				WM_BUTTON2,
				0,{ 1, 51 },
				140, 150,
				{ 0 }
			},
			{
				WM_BUTTON3,
				0,{ 1, 51 },
				140, 190,
				{ 0 }
			},
			{
				WM_BUTTON4,
				0,{ 1, 51 },
				140, 230,
				{ 0 }
			},
			{
				WM_BUTTON5,
				0,{ 1, 51 },
				140, 270,
				{ 0 }
			},
			{
				WM_BUTTON6,
				0,{ 1, 51 },
				140, 310,
				{ 0 }
			},
			{
				WM_BUTTON10,
				0,{ 1, 72 },
				466, 110,
				{ 1, 242 }
			},
			{
				WM_BUTTON11,
				0,{ 1, 73 },
				466, 310,
				{ 1, 241 }
			},
			{
				WM_PHASE_DP_DOSERVICE,
				0,{ 1, 18 },
				222, 389,
				{ 1, 174 }
			},
			{
				WM_PHASE_DP_CANCELSERVICE,
				0,{ 1, 36 },
				380, 389,
				{ 1, 175 }
			},
			{ 0 }
		},
	},
	{
		WM_PHASE_SESSION,
		"session.blp",
		FALSE,
		FALSE,
		{
			{
				WM_BUTTON1,
				0,{ 1, 51 },
				120, 110,
				{ 0 }
			},
			{
				WM_BUTTON2,
				0,{ 1, 51 },
				120, 150,
				{ 0 }
			},
			{
				WM_BUTTON3,
				0,{ 1, 51 },
				120, 190,
				{ 0 }
			},
			{
				WM_BUTTON4,
				0,{ 1, 51 },
				120, 230,
				{ 0 }
			},
			{
				WM_BUTTON5,
				0,{ 1, 51 },
				120, 270,
				{ 0 }
			},
			{
				WM_BUTTON6,
				0,{ 1, 51 },
				120, 310,
				{ 0 }
			},
			{
				WM_BUTTON10,
				0,{ 1, 72 },
				490, 110,
				{ 1, 246 }
			},
			{
				WM_BUTTON11,
				0,{ 1, 73 },
				490, 310,
				{ 1, 245 }
			},
			{
				WM_PHASE_DP_JOIN,
				0,{ 1, 45 },
				120, 389,
				{ 1, 247 }
			},
			{
				WM_PHASE_DP_CREATELOBBY,
				0,{ 1, 43 },
				162, 389,
				{ 1, 248 }
			},
			{
				WM_PHASE_DP_REFRESH,
				0,{ 1, 72 },
				260, 389,
				{ 1, 249 }
			},
			{
				WM_PHASE_DP_CANCELSESSION,
				0,{ 1, 36 },
				485, 389,
				{ 1, 175 }
			},
			{ 0 }
		},
	},
	{
		WM_PHASE_CREATE,
		"create.blp",
		FALSE,
		FALSE,
		{
			{
				WM_PHASE_DP_DOCREATE,
				0,{ 1, 18 },
				222, 326,
				{ 1, 174 }
			},
			{
				WM_PHASE_DP_CANCELCREATE,
				0,{ 1, 36 },
				378, 326,
				{ 1, 175 }
			},
			{ 0 }
		},
	},
	{
		WM_PHASE_MULTI,
		"multi.blp",
		FALSE,
		FALSE,
		{
			{
				WM_BUTTON1,
				0,{ 0 },
				80, 98,
				{ 1, 207 }
			},
			{
				WM_BUTTON2,
				0,{ 0 },
				80, 140,
				{ 1, 207 }
			},
			{
				WM_BUTTON3,
				0,{ 0 },
				80, 182,
				{ 1, 207 }
			},
			{
				WM_BUTTON4,
				0,{ 0 },
				80, 224,
				{ 1, 207 }
			},
			{
				WM_BUTTON11,
				0,{ 1, 36 },
				288, 98,
				{ 1, 208 }
			},
			{
				WM_BUTTON12,
				0,{ 1, 36 },
				288, 140,
				{ 1, 208 }
			},
			{
				WM_BUTTON13,
				0,{ 1, 36 },
				288, 182,
				{ 1, 208 }
			},
			{
				WM_BUTTON14,
				0,{ 1, 36 },
				288, 224,
				{ 1, 208 }
			},
			{
				WM_BUTTON20,
				0,{ 1, 94 },
				404, 388,
				{ 1, 262 }
			},
			{
				WM_PREV,
				0,{ 1, 50 },
				438, 249,
				{ 1, 107 }
			},
			{
				WM_NEXT,
				0,{ 1, 51 },
				480, 249,
				{ 1, 108 }
			},
			{
				WM_PHASE_DP_STARTMULTI,
				0,{ 1, 48 },
				508, 389,
				{ 1, 252 }
			},
			{
				WM_PHASE_DP_CANCELMULTI,
				0,{ 1, 36 },
				508, 330,
				{ 1, 175 }
			},
			{ 0 }
		},
	},
	{
		WM_PHASE_INFO,
		"info.blp",
		FALSE,
		TRUE,
		{
			{
				WM_PHASE_WRITEDESIGN,
				0,{ 1, 53 },
				188, 306,
				{ 1, 113 }
			},
			{
				WM_PHASE_READDESIGN,
				0,{ 1, 52 },
				232, 306,
				{ 1, 112 }
			},
			{
				WM_PHASE_CLEARDESIGN,
				0,{ 1, 36 },
				276, 306,
				{ 1, 183 }
			},
			{
				WM_PREV,
				0,{ 1, 50 },
				188, 398,
				{ 1, 107 }
			},
			{
				WM_PHASE_PLAYMOVIE,
				0,{ 1, 48 },
				232, 398,
				{ 1, 109 }
			},
			{
				WM_NEXT,
				0,{ 1, 51 },
				276, 398,
				{ 1, 108 }
			},
			{
				WM_PHASE_BUILD,
				0,{ 1, 49 },
				422, 98,
				{ 1, 110 }
			},
			{
				WM_PHASE_REGION,
				0,{ 1, 22 },
				422, 195,
				{ 1, 144 }
			},
			{
				WM_PHASE_NAMEDESIGN,
				0,{ 1, 46 },
				422, 239,
				{ 1, 185 }
			},
			{
				WM_PHASE_MUSIC,
				0,{ 1, 44 },
				422, 283,
				{ 1, 129 }
			},
			{
				WM_PHASE_GAMER,
				0,{ 1, 40 },
				422, 398,
				{ 1, 111 }
			},
			{ 0 }
		},
	},
	{
		WM_PHASE_PLAY,
		"",
		FALSE,
		FALSE,
		{
			{ 0 }
		},
	},
	{
		WM_PHASE_PLAYTEST,
		"",
		FALSE,
		FALSE,
		{
			{ 0 }
		},
	},
	{
		WM_PHASE_STOP,
		"stop.blp",
		FALSE,
		FALSE,
		{
			{
				WM_PHASE_GWRITE,
				0,{ 1, 53 },
				187, 178,
				{ 1, 263 }
			},
			{
				WM_PHASE_GREADp,
				0,{ 1, 52 },
				187, 296,
				{ 1, 264 }
			},
			{
				WM_PHASE_SETUPp,
				0,{ 1, 47 },
				350, 156,
				{ 1, 128 }
			},
			{
				WM_PHASE_HELP,
				0,{ 1, 86 },
				391, 156,
				{ 1, 267 }
			},
			{
				WM_PHASE_QUITPLAY,
				0,{ 1, 78 },
				413, 262,
				{ 1, 266 }
			},
			{
				WM_PHASE_PLAY,
				0,{ 1, 77 },
				413, 323,
				{ 1, 265 }
			},
			{ 0 }
		},
	},
	{
		WM_PHASE_HELP,
		"help.blp",
		FALSE,
		FALSE,
		{
			{
				WM_PHASE_PLAY,
				0,{ 1, 18 },
				442, 358,
				{ 1, 174 }
			},
			{ 0 }
		},
	},
	{
		WM_PHASE_GREAD,
		"gread.blp",
		FALSE,
		TRUE,
		{
			{
				WM_BUTTON1,
				0,{ 0 },
				280, 110,
				{ 0 }
			},
			{
				WM_BUTTON2,
				0,{ 0 },
				280, 150,
				{ 0 }
			},
			{
				WM_BUTTON3,
				0,{ 0 },
				280, 190,
				{ 0 }
			},
			{
				WM_BUTTON4,
				0,{ 0 },
				280, 230,
				{ 0 }
			},
			{
				WM_BUTTON5,
				0,{ 0 },
				280, 270,
				{ 0 }
			},
			{
				WM_BUTTON6,
				0,{ 0 },
				280, 310,
				{ 0 }
			},
			{
				WM_BUTTON20,
				0,{ 1, 18 },
				330, 387,
				{ 1, 174 }
			},
			{
				WM_PHASE_GAMER,
				0,{ 1, 36 },
				458, 387,
				{ 1, 175 }
			},
			{ 0 }
		},
	},
	{
		WM_PHASE_GREADp,
		"gread.blp",
		FALSE,
		FALSE,
		{
			{
				WM_BUTTON1,
				0,{ 0 },
				280, 110,
				{ 0 }
			},
			{
				WM_BUTTON2,
				0,{ 0 },
				280, 150,
				{ 0 }
			},
			{
				WM_BUTTON3,
				0,{ 0 },
				280, 190,
				{ 0 }
			},
			{
				WM_BUTTON4,
				0,{ 0 },
				280, 230,
				{ 0 }
			},
			{
				WM_BUTTON5,
				0,{ 0 },
				280, 270,
				{ 0 }
			},
			{
				WM_BUTTON6,
				0,{ 0 },
				280, 310,
				{ 0 }
			},
			{
				WM_BUTTON20,
				0,{ 1, 18 },
				330, 387,
				{ 1, 174 }
			},
			{
				WM_PHASE_STOP,
				0,{ 1, 36 },
				458, 387,
				{ 1, 175 }
			},
			{ 0 }
		},
	},
	{
		WM_PHASE_GWRITE,
		"gwrite.blp",
		FALSE,
		FALSE,
		{
			{
				WM_BUTTON1,
				0,{ 0 },
				280, 110,
				{ 0 }
			},
			{
				WM_BUTTON2,
				0,{ 0 },
				280, 150,
				{ 0 }
			},
			{
				WM_BUTTON3,
				0,{ 0 },
				280, 190,
				{ 0 }
			},
			{
				WM_BUTTON4,
				0,{ 0 },
				280, 230,
				{ 0 }
			},
			{
				WM_BUTTON5,
				0,{ 0 },
				280, 270,
				{ 0 }
			},
			{
				WM_BUTTON6,
				0,{ 0 },
				280, 310,
				{ 0 }
			},
			{
				WM_BUTTON20,
				0,{ 1, 18 },
				330, 387,
				{ 1, 174 }
			},
			{
				WM_PHASE_STOP,
				0,{ 1, 36 },
				458, 387,
				{ 1, 175 }
			},
			{ 0 }
		},
	},
	{
		WM_PHASE_SETUP,
		"setup.blp",
		FALSE,
		FALSE,
		{
			{
				WM_BUTTON1,
				0,{ 1, 50 },
				70, 110,
				{ 1, 130 }
			},
			{
				WM_BUTTON2,
				0,{ 1, 51 },
				110, 110,
				{ 1, 131 }
			},
			{
				WM_BUTTON3,
				0,{ 1, 50 },
				70, 220,
				{ 1, 132 }
			},
			{
				WM_BUTTON4,
				0,{ 1, 51 },
				110, 220,
				{ 1, 133 }
			},
			{
				WM_BUTTON5,
				0,{ 1, 133 },
				70, 330,
				{ 1, 154 }
			},
			{
				WM_BUTTON6,
				0,{ 1, 134 },
				110, 330,
				{ 1, 155 }
			},
			{
				WM_BUTTON13,
				0,{ 1, 135 },
				170, 330,
				{ 1, 305 }
			},
			{
				WM_BUTTON14,
				0,{ 1, 136 },
				210, 330,
				{ 1, 306 }
			},
			{
				WM_BUTTON7,
				0,{ 0 },
				370, 110,
				{ 1, 156 }
			},
			{
				WM_BUTTON8,
				0,{ 0 },
				370, 150,
				{ 1, 157 }
			},
			{
				WM_BUTTON9,
				0,{ 0 },
				370, 190,
				{ 1, 157 }
			},
			{
				WM_BUTTON10,
				0,{ 0 },
				370, 230,
				{ 1, 157 }
			},
			{
				WM_BUTTON11,
				0,{ 0 },
				370, 270,
				{ 1, 157 }
			},
			{
				WM_BUTTON12,
				0,{ 0 },
				370, 310,
				{ 1, 157 }
			},
			{
				WM_PHASE_GAMER,
				0,{ 1, 18 },
				541, 411,
				{ 1, 174 }
			},
			{ 0 }
		},
	},
	{
		WM_PHASE_SETUPp,
		"setup.blp",
		FALSE,
		FALSE,
		{
			{
				WM_BUTTON1,
				0,{ 1, 50 },
				70, 110,
				{ 1, 130 }
			},
			{
				WM_BUTTON2,
				0,{ 1, 51 },
				110, 110,
				{ 1, 131 }
			},
			{
				WM_BUTTON3,
				0,{ 1, 50 },
				70, 220,
				{ 1, 132 }
			},
			{
				WM_BUTTON4,
				0,{ 1, 51 },
				110, 220,
				{ 1, 133 }
			},
			{
				WM_BUTTON5,
				0,{ 1, 133 },
				70, 330,
				{ 1, 154 }
			},
			{
				WM_BUTTON6,
				0,{ 1, 134 },
				110, 330,
				{ 1, 155 }
			},
			{
				WM_BUTTON13,
				0,{ 1, 135 },
				170, 330,
				{ 1, 305 }
			},
			{
				WM_BUTTON14,
				0,{ 1, 136 },
				210, 330,
				{ 1, 306 }
			},
			{
				WM_BUTTON7,
				0,{ 0 },
				370, 110,
				{ 1, 156 }
			},
			{
				WM_BUTTON8,
				0,{ 0 },
				370, 150,
				{ 1, 157 }
			},
			{
				WM_BUTTON9,
				0,{ 0 },
				370, 190,
				{ 1, 157 }
			},
			{
				WM_BUTTON10,
				0,{ 0 },
				370, 230,
				{ 1, 157 }
			},
			{
				WM_BUTTON11,
				0,{ 0 },
				370, 270,
				{ 1, 157 }
			},
			{
				WM_BUTTON12,
				0,{ 0 },
				370, 310,
				{ 1, 157 }
			},
			{
				WM_PHASE_PLAY,
				0,{ 1, 18 },
				541, 411,
				{ 1, 174 }
			},
			{ 0 }
		},
	},
	{
		WM_PHASE_LOST,
		"lost.blp",
		FALSE,
		FALSE,
		{
			{
				WM_PHASE_PLAY,
				0,{ 1, 18 },
				541, 411,
				{ 1, 174 }
			},
			{ 0 }
		},
	},
	{
		WM_PHASE_LOSTDESIGN,
		"lost.blp",
		FALSE,
		FALSE,
		{
			{
				WM_PHASE_INFO,
				0,{ 1, 18 },
				541, 411,
				{ 1, 174 }
			},
			{ 0 }
		},
	},
	{
		WM_PHASE_LOSTMULTI,
		"lost.blp",
		FALSE,
		FALSE,
		{
			{
				WM_PHASE_GAMER,
				0,{ 1, 18 },
				541, 411,
				{ 1, 174 }
			},
			{ 0 }
		},
	},
	{
		WM_PHASE_WIN,
		"win.blp",
		FALSE,
		FALSE,
		{
			{
				WM_PHASE_GAMER,
				0,{ 1, 18 },
				541, 411,
				{ 1, 174 }
			},
			{ 0 }
		},
	},
	{
		WM_PHASE_WINDESIGN,
		"win.blp",
		FALSE,
		FALSE,
		{
			{
				WM_PHASE_INFO,
				0,{ 1, 18 },
				541, 411,
				{ 1, 174 }
			},
			{ 0 }
		},
	},
	{
		WM_PHASE_WINMULTI,
		"win.blp",
		FALSE,
		FALSE,
		{
			{
				WM_PHASE_GAMER,
				0,{ 1, 18 },
				541, 411,
				{ 1, 174 }
			},
			{ 0 }
		},
	},
	{
		WM_PHASE_BUILD,
		"",
		FALSE,
		FALSE,
		{
			{
				WM_DECOR1,
				0,{ 1, 6 },
				11, 11,
				{ 1, 1000 }
			},
			{
				WM_DECOR2,
				0,{ 11, 31, 29, 32, 69, 33, 37, 82, 130, 139, 30, 142 },
				11, 53,
				{ 11, 2030, 1023, 2072, 1042, 2047, 1026, 1049, 1076, 1080, 1021, 1082 }
			},
			{
				WM_DECOR3,
				0,{ 8, 0, 1, 2, 27, 34, 35, 67, 106 },
				11, 95,
				{ 8, 1001, 1002, 1003, 1020, 1024, 1025, 1038, 1062 }
			},
			{
				WM_DECOR4,
				0,{ 10, 22, 59, 68, 118, 127, 100, 128, 129, 39, 38 },
				11, 137,
				{ 10, 2033, 1032, 1037, 1067, 1075, 1061, 1074, 1076, 2038, 2041 }
			},
			{
				WM_DECOR5,
				0,{ 10, 137, 138, 65, 66, 112, 58, 23, 80, 81, 79 },
				11, 179,
				{ 10, 1079, 1080, 1039, 1040, 1065, 1031, 1015, 1047, 1048, 1022 }
			},
			{
				WM_DECOR6,
				0,{ 12, 8, 9, 107, 26, 42, 41, 131, 143, 132, 101, 120, 122 },
				11, 221,
				{ 12, 1006, 1007, 1063, 1018, 1028, 1027, 1077, 1083, 1078, 1064, 1069, 1071 }
			},
			{
				WM_DECOR7,
				0,{ 13, 21, 20, 19, 28, 121, 16, 55, 60, 113, 140, 54, 95, 99 },
				11, 263,
				{ 13, 1009, 1010, 1011, 1019, 1070, 1012, 1030, 1033, 1066, 1081, 1029, 1059, 1060 }
			},
			{
				WM_DECOR8,
				0,{ 9, 7, 10, 75, 74, 89, 88, 93, 92, 87 },
				11, 305,
				{ 9, 1004, 1005, 1046, 1045, 1052, 1051, 1054, 1053, 2007 }
			},
			{
				WM_DECOR9,
				0,{ 10, 125, 126, 144, 124, 56, 70, 123, 141, 17, 76 },
				11, 347,
				{ 10, 1036, 1035, 1084, 1073, 1041, 1043, 1072, 2044, 1013, 1014 }
			},
			{
				WM_DECOR10,
				0,{ 5, 119, 24, 71, 57, 85 },
				11, 389,
				{ 5, 1068, 1016, 1044, 2004, 1050 }
			},
			{
				WM_DECOR11,
				0,{ 8, 11, 5, 96, 97, 98, 63, 62, 64 },
				11, 431,
				{ 8, 1008, 1055, 1056, 1057, 1058, 1035, 1034, 1036 }
			},
			{
				WM_PHASE_PLAYTEST,
				0,{ 1, 48 },
				544, 431,
				{ 1, 124 }
			},
			{
				WM_PHASE_INFO,
				0,{ 1, 40 },
				586, 431,
				{ 1, 119 }
			},
			{ 0 }
		},
	},
	{
		WM_PHASE_MUSIC,
		"music.blp",
		FALSE,
		FALSE,
		{
			{
				WM_BUTTON1,
				0,{ 1, 40 },
				200, 130,
				{ 1, 134 }
			},
			{
				WM_BUTTON2,
				0,{ 1, 44 },
				290, 130,
				{ 1, 135 }
			},
			{
				WM_BUTTON3,
				0,{ 1, 44 },
				290, 170,
				{ 1, 136 }
			},
			{
				WM_BUTTON4,
				0,{ 1, 44 },
				290, 210,
				{ 1, 137 }
			},
			{
				WM_BUTTON5,
				0,{ 1, 44 },
				290, 250,
				{ 1, 138 }
			},
			{
				WM_BUTTON6,
				0,{ 1, 44 },
				290, 290,
				{ 1, 139 }
			},
			{
				WM_BUTTON7,
				0,{ 1, 44 },
				350, 130,
				{ 1, 140 }
			},
			{
				WM_BUTTON8,
				0,{ 1, 44 },
				350, 170,
				{ 1, 141 }
			},
			{
				WM_BUTTON9,
				0,{ 1, 44 },
				350, 210,
				{ 1, 142 }
			},
			{
				WM_BUTTON10,
				0,{ 1, 44 },
				350, 250,
				{ 1, 143 }
			},
			{
				WM_BUTTON11,
				0,{ 1, 44 },
				350, 290,
				{ 1, 171 }
			},
			{
				WM_PHASE_INFO,
				0,{ 1, 18 },
				540, 410,
				{ 1, 174 }
			},
			{ 0 }
		},
	},
	{
		WM_PHASE_REGION,
		"region.blp",
		FALSE,
		FALSE,
		{
			{
				WM_BUTTON3,
				0,{ 0 },
				48, 58,
				{ 1, 217 }
			},
			{
				WM_BUTTON28,
				0,{ 0 },
				48, 98,
				{ 1, 300 }
			},
			{
				WM_BUTTON22,
				0,{ 0 },
				48, 138,
				{ 1, 236 }
			},
			{
				WM_BUTTON19,
				0,{ 0 },
				48, 178,
				{ 1, 233 }
			},
			{
				WM_BUTTON21,
				0,{ 0 },
				48, 218,
				{ 1, 235 }
			},
			{
				WM_BUTTON20,
				0,{ 0 },
				48, 258,
				{ 1, 234 }
			},
			{
				WM_BUTTON7,
				0,{ 0 },
				48, 298,
				{ 1, 221 }
			},
			{
				WM_BUTTON10,
				0,{ 0 },
				48, 338,
				{ 1, 224 }
			},
			{
				WM_BUTTON1,
				0,{ 0 },
				148, 58,
				{ 1, 215 }
			},
			{
				WM_BUTTON15,
				0,{ 0 },
				148, 98,
				{ 1, 229 }
			},
			{
				WM_BUTTON14,
				0,{ 0 },
				148, 138,
				{ 1, 228 }
			},
			{
				WM_BUTTON11,
				0,{ 0 },
				148, 178,
				{ 1, 225 }
			},
			{
				WM_BUTTON8,
				0,{ 0 },
				148, 218,
				{ 1, 222 }
			},
			{
				WM_BUTTON23,
				0,{ 0 },
				148, 258,
				{ 1, 237 }
			},
			{
				WM_BUTTON13,
				0,{ 0 },
				148, 298,
				{ 1, 227 }
			},
			{
				WM_BUTTON6,
				0,{ 0 },
				148, 338,
				{ 1, 220 }
			},
			{
				WM_BUTTON17,
				0,{ 0 },
				248, 58,
				{ 1, 231 }
			},
			{
				WM_BUTTON18,
				0,{ 0 },
				248, 98,
				{ 1, 232 }
			},
			{
				WM_BUTTON12,
				0,{ 0 },
				248, 138,
				{ 1, 226 }
			},
			{
				WM_BUTTON27,
				0,{ 0 },
				248, 178,
				{ 1, 299 }
			},
			{
				WM_BUTTON16,
				0,{ 0 },
				248, 218,
				{ 1, 230 }
			},
			{
				WM_BUTTON2,
				0,{ 0 },
				248, 258,
				{ 1, 216 }
			},
			{
				WM_BUTTON30,
				0,{ 0 },
				248, 298,
				{ 1, 302 }
			},
			{
				WM_BUTTON29,
				0,{ 0 },
				248, 338,
				{ 1, 301 }
			},
			{
				WM_BUTTON32,
				0,{ 0 },
				348, 58,
				{ 1, 304 }
			},
			{
				WM_BUTTON5,
				0,{ 0 },
				348, 98,
				{ 1, 219 }
			},
			{
				WM_BUTTON9,
				0,{ 0 },
				348, 138,
				{ 1, 223 }
			},
			{
				WM_BUTTON31,
				0,{ 0 },
				348, 178,
				{ 1, 303 }
			},
			{
				WM_BUTTON26,
				0,{ 0 },
				348, 218,
				{ 1, 298 }
			},
			{
				WM_BUTTON24,
				0,{ 0 },
				348, 258,
				{ 1, 238 }
			},
			{
				WM_BUTTON4,
				0,{ 0 },
				348, 298,
				{ 1, 218 }
			},
			{
				WM_BUTTON25,
				0,{ 0 },
				348, 338,
				{ 1, 297 }
			},
			{
				WM_DIMS1,
				0,{ 1, 15 },
				521, 135,
				{ 1, 121 }
			},
			{
				WM_DIMS2,
				0,{ 1, 13 },
				521, 175,
				{ 1, 122 }
			},
			{
				WM_DIMS3,
				0,{ 1, 14 },
				521, 215,
				{ 1, 123 }
			},
			{
				WM_DIMS4,
				0,{ 1, 61 },
				521, 255,
				{ 1, 126 }
			},
			{
				WM_PHASE_INFO,
				0,{ 1, 18 },
				540, 411,
				{ 1, 174 }
			},
			{ 0 }
		},
	},
	{
		WM_PHASE_NAMEDESIGN,
		"name.blp",
		FALSE,
		FALSE,
		{
			{
				WM_PHASE_DONAMEDESIGN,
				0,{ 1, 18 },
				222, 326,
				{ 1, 174 }
			},
			{
				WM_PHASE_INFO,
				0,{ 1, 36 },
				378, 326,
				{ 1, 175 }
			},
			{ 0 }
		},
	},
	{
		WM_PHASE_WRITEDESIGN,
		"write.blp",
		FALSE,
		FALSE,
		{
			{
				WM_BUTTON10,
				0,{ 1, 72 },
				420, 112,
				{ 1, 193 }
			},
			{
				WM_BUTTON11,
				0,{ 1, 73 },
				420, 252,
				{ 1, 192 }
			},
			{
				WM_PHASE_DOWRITEDESIGN,
				0,{ 1, 18 },
				222, 387,
				{ 1, 174 }
			},
			{
				WM_PHASE_INFO,
				0,{ 1, 36 },
				380, 387,
				{ 1, 175 }
			},
			{ 0 }
		},
	},
	{
		WM_PHASE_READDESIGN,
		"read.blp",
		FALSE,
		FALSE,
		{
			{
				WM_BUTTON1,
				0,{ 1, 51 },
				190, 110,
				{ 0 }
			},
			{
				WM_BUTTON2,
				0,{ 1, 51 },
				190, 150,
				{ 0 }
			},
			{
				WM_BUTTON3,
				0,{ 1, 51 },
				190, 190,
				{ 0 }
			},
			{
				WM_BUTTON4,
				0,{ 1, 51 },
				190, 230,
				{ 0 }
			},
			{
				WM_BUTTON5,
				0,{ 1, 51 },
				190, 270,
				{ 0 }
			},
			{
				WM_BUTTON6,
				0,{ 1, 51 },
				190, 310,
				{ 0 }
			},
			{
				WM_BUTTON10,
				0,{ 1, 72 },
				420, 110,
				{ 1, 193 }
			},
			{
				WM_BUTTON11,
				0,{ 1, 73 },
				420, 310,
				{ 1, 192 }
			},
			{
				WM_PHASE_DOREADDESIGN,
				0,{ 1, 18 },
				222, 387,
				{ 1, 174 }
			},
			{
				WM_PHASE_INFO,
				0,{ 1, 36 },
				380, 387,
				{ 1, 175 }
			},
			{ 0 }
		},
	},
	{
		WM_PHASE_CLEARDESIGN,
		"clear.blp",
		FALSE,
		FALSE,
		{
			{
				WM_PHASE_DOCLEARDESIGN,
				0,{ 1, 18 },
				222, 326,
				{ 1, 176 }
			},
			{
				WM_PHASE_INFO,
				0,{ 1, 36 },
				378, 326,
				{ 1, 177 }
			},
			{ 0 }
		},
	},
	{
		WM_PHASE_PLAYMOVIE,
		"movie.blp",
		FALSE,
		FALSE,
		{
			{ 0 }
		},
	},
	{
		WM_PHASE_PLAYMOVIE,
		"movie.blp",
		FALSE,
		FALSE,
		{
			{ 0 }
		},
	},
	{
		WM_PHASE_WINMOVIEDESIGN,
		"movie.blp",
		FALSE,
		FALSE,
		{
			{ 0 }
		},
	},
	{
		WM_PHASE_WINMOVIEMULTI,
		"movie.blp",
		FALSE,
		FALSE,
		{
			{ 0 }
		},
	},
	{
		WM_PHASE_BYE,
		"bye.blp",
		FALSE,
		FALSE,
		{
			{ 0 }
		},
	},
	{
		WM_PHASE_INSERT,
		"insert.blp",
		FALSE,
		FALSE,
		{
			{
				WM_PHASE_GAMER,
				0,{ 1, 40 },
				16, 424,
				{ 1, 106 }
			},
			{ 0 }
		},
	},
	{ 0 }
};

// Constructor

CEvent::CEvent()
{
	int     i;


	m_somethingJoystick = 0;
	m_bFullScreen = TRUE;
	m_mouseType = MOUSETYPEGRA;
	m_index = -1;
	m_exercice = 0;
	m_mission = 1;
	m_private = 1;
	m_maxMission = 0;
	m_phase = 0;
	m_bSchool = FALSE;
	m_bPrivate = FALSE;
	m_bBuildOfficialMissions = FALSE;
	m_bRunMovie = FALSE;
	m_bBuildModify = FALSE;
	m_bMousePress = FALSE;
	m_bMouseDown = FALSE;
	m_oldMousePos.x = 0;
	m_oldMousePos.y = 0;
	m_mouseSprite = 0;
	m_bFillMouse = FALSE;
	m_bWaitMouse = FALSE;
	m_bHideMouse = FALSE;
	m_bShowMouse = FALSE;
	m_bMouseRelease = FALSE;
	m_tryPhase = 0;
	m_rankCheat = -1;
	m_posCheat = 0;
	m_speed = 1;
	m_bMovie = TRUE;
	m_bAllMissions = FALSE;
	m_bHiliInfoButton = TRUE;
	m_bSpeed = FALSE;
	m_bHelp = FALSE;
	m_bChangeCheat = FALSE;
	m_scrollSpeed = 1;
	m_bPause = FALSE;
	m_bShift = FALSE;
	m_shiftPhase = 0;
	m_movieToStart[0] = 0;
	m_bInfoHelp = FALSE;
	m_bDemoRec = FALSE;
	m_bDemoPlay = FALSE;
	m_pDemoBuffer = NULL;
	m_demoTime = 0;
	m_bCtrlDown = FALSE;
	m_keyPress = 0;
	m_menuIndex = 0;
	ZeroMemory(m_menuDecor, sizeof(m_menuDecor));

	return;
}

// Destructor

CEvent::~CEvent()
{
    WriteInfo(m_gamer);
}

void CEvent::Create(HINSTANCE hInstance, HWND hWnd, CPixmap *pPixmap, CDecor *pDecor,
                    CSound *pSound, CNetwork *pNetwork, CMovie *pMovie )
{
    POINT   pos;

	m_hInstance = hInstance;
    m_hWnd    = hWnd;
    m_pPixmap = pPixmap;
    m_pDecor  = pDecor;
    m_pSound  = pSound;
    m_pMovie  = pMovie;
	m_pNetwork = pNetwork;
	m_gamer = 1;

    ReadInfo(1);
	return;
}

int CEvent::GetButtonIndex(int button)
{
    int         i=0;

    while ( table[m_index].buttons[i].message != 0 )
    {
        if ( (UINT)button == table[m_index].buttons[i].message )
        {
            return i;
        }
        i ++;
    }

    return -1;
}

int CEvent::GetState(int button)
{
    int     index;

    index = GetButtonIndex(button);
    if ( index < 0 ) return 0;

    return m_buttons[index].GetState();
}

// Returns the mouse position

POINT CEvent::GetMousePos()
{
    POINT       pos;

    GetCursorPos(&pos);
    ScreenToClient(m_hWnd, &pos);

    return pos;
}

void CEvent::SetFullScreen(BOOL bFullScreen)
{
    m_bFullScreen = bFullScreen;
}

// Initializes the mouse type.

void CEvent::SetMouseType(int mouseType)
{
    m_mouseType = mouseType;
}

// Creates the event handler.



// Returns the index of the button.



void CEvent::SetState(int button, int state)
{
    int     index;

    index = GetButtonIndex(button);
    if ( index < 0 ) return;

    m_buttons[index].SetState(state);
}

BOOL CEvent::GetEnable(int button)
{
    int     index;

    index = GetButtonIndex(button);
    if ( index < 0 ) return 0;

    return FALSE;
}

void CEvent::SetEnable(int button, int bEnable)
{
    int      index;

    index = GetButtonIndex(button);
    if ( index < 0 ) return;

    m_buttons[index].SetEnable(bEnable);
}

/*
BOOL CEvent::GetHide(int button)
{
	int		index;

	index = GetButtonIndex(button);
	if (index < 0)  return 0;

	return m_buttons[index].GetHide();
}
*/

void CEvent::SetHide(int button, BOOL bHide)
{
	int index;

	index = GetButtonIndex(button);
	if (index < 0) return;

	m_buttons[index].SetHide(bHide);
}

int CEvent::GetMenu(int button)
{
    int     index;

    index = GetButtonIndex(button);
    if ( index < 0 ) return 0;

    return m_buttons[index].GetMenu();
}

void CEvent::SetMenu(int button, int menu)
{
    int     index;

    index = GetButtonIndex(button);
    if ( index < 0 ) return;

    m_buttons[index].SetMenu(menu);
}

// Restore the game after activation in fullScreen mode.

void CEvent::RestoreGame()
{
    int     i;

	if (m_phase == WM_PHASE_PLAY || m_phase == WM_PHASE_PLAYTEST)
	{
		HideMouse(FALSE);
		WaitMouse(TRUE);
		WaitMouse(FALSE);
		return;
	}
	FillMouse(TRUE);
	return;
    
}

void CEvent::FlushInput()
{
	m_keyPress = 0;
	
	m_pDecor->SetInput(0);
	return;

}

BOOL CEvent::CreateButtons()
{
	int		message;
	int*	iconMenu;
	POINT	pos;
	BOOL	bMinimizeRedraw = FALSE;

	
	for (int i = 0; table[m_index].buttons[i].message != 0; i++)
	{
		pos.x = table[m_index].buttons[i].x;
		pos.y = table[m_index].buttons[i].y;
		message = table[m_index].buttons[i].message;

		m_buttons[i].Create(m_hWnd, m_pPixmap, m_pSound, pos,
			table[m_index].buttons[i].type,
			bMinimizeRedraw, message);

		iconMenu = table[m_index].buttons[i].iconMenu;
		if (!m_bBuildOfficialMissions && m_phase == WM_PHASE_BUILD && message == WM_DECOR11)
		{
			iconMenu++;
		}

		m_buttons[i].SetIconMenu(&table[m_index].buttons[i].iconMenu[1], iconMenu[0]);
		m_buttons[i].SetToolTips(&table[m_index].buttons[i].toolTips[1], table[m_index].buttons[i].toolTips[0]);
	}
	return TRUE;
}

void CEvent::ReadInput()
{
	BOOL something;
	MMRESULT joyPos;
	int  i;
	UINT keyInput;
	JOYINFOEX* joyInfo;
	BOOL bSkateboard;
	BOOL bHelicopter;
	BOOL bCar;
	BOOL bWater;
	JOYINFOEX joy;
	UINT bJoyID;


	if (m_bMulti != FALSE)
	{
		//m_pDecor->TreatNetData();
	}
	
	if ((m_somethingJoystick == NULL) || (m_bDemoPlay != FALSE)) 
	{
		m_pDecor->SetJoystickEnable(FALSE);
	}
	else
	{
		m_pDecor->GetBlupiInfo(&bHelicopter, &bCar, &bSkateboard, &bWater);
		something = TRUE;

		if (((bHelicopter != FALSE) || (bCar != FALSE)) || (bSkateboard != FALSE))
		{
			something = FALSE;
		}
		bJoyID = m_joyID;
		joyInfo = &joy;

		for (i != 0; i = 13; i++)
		{
			joyInfo->dwSize = 0;
			joyInfo = (JOYINFOEX*)&joyInfo->dwFlags;
		}
		joy.dwSize = 52;
		joy.dwFlags = 255;

		joyPos = joyGetPosEx(bJoyID, &joy);

		if (joyPos == 0)
		{
			m_keyPress = 0;

			if ((int)joy.dwXpos < 16384)
			{
				m_keyPress = KEY_LEFT;
			}
			if ((m_keyPress == KEY_NONE) && ((int)joy.dwYpos < 16384))
			{
				m_keyPress = KEY_UP;
			}
			if (((m_keyPress == KEY_NONE) || (something)) && (49152 < (int)joy.dwYpos))
			{
				m_keyPress = m_keyPress | KEY_DOWN;
			}
			if (((BYTE)joy.dwButtons & JOY_BUTTON1) != 0)
			{
				m_keyPress = m_keyPress & ~(KEY_DOWN | KEY_UP) | KEY_JUMP;
			}
			if (((BYTE)joy.dwButtons & JOY_BUTTON2) != 0)
			{
				if (bSkateboard == FALSE)
				{
					keyInput = m_keyPress & ~KEY_DOWN | KEY_UP | KEY_JUMP;
				}
				else
				{
					keyInput = m_keyPress & ~(KEY_DOWN | KEY_UP) | KEY_JUMP;
				}
				m_keyPress = keyInput;
			}
			if (((BYTE)joy.dwButtons & JOY_BUTTON3) != 0)
			{
				if (bHelicopter == FALSE)
				{
					if (bSkateboard == FALSE)
					{
						keyInput = m_keyPress | KEY_DOWN | KEY_JUMP;
					}
					else
					{
						keyInput = m_keyPress & ~(KEY_DOWN | KEY_UP) | KEY_JUMP;
					}
				}
				else
				{
					keyInput = m_keyPress | KEY_DOWN;
				}
				m_keyPress = keyInput;
				m_keyPress = keyInput & ~KEY_UP;
			}
			if (((BYTE)joy.dwButtons & JOY_BUTTON4) != 0)
			{
				m_keyPress = m_keyPress & ~(KEY_DOWN | KEY_UP) | KEY_FIRE;
			}
			m_pDecor->SetInput(m_keyPress);
			m_pDecor->SetJoystickEnable(TRUE);
			return;
		}
	}
	return;
}


// CNetwork function needs to be implemented 

void CEvent::NetSetPause(BOOL bPause, int players)
{
	BOOL bPause_;
	
	bPause_ = bPause;
	m_pDecor->SetPause(bPause);
	if ((m_phase == WM_PHASE_PLAY) || (m_phase == WM_PHASE_PLAYTEST))
	{
		if (bPause_ == FALSE)
		{
			m_pSound->RestartMusic();
		}
		else
		{
			m_pSound->SuspendMusic();
		}
	}
	if ((m_bMulti != FALSE) && (players != 0))
	{
		m_pNetwork->Send(&bPause, 3, DPSEND_GUARANTEED);
	}
	return;
}

void CEvent::NetSendLobby()
{
	NetPlayer* player;
	UCHAR (packet)[132];
	CNetwork* pNetwork;

	*(UCHAR*)packet = m_multi;
	pNetwork = m_pNetwork;
	packet[0] = 132;
	packet[1] = MESS_LOBBY;
	player = pNetwork->m_players;
	memcpy(packet, pNetwork, 128);
	pNetwork->Send(packet, 132, DPSEND_GUARANTEED);
	return;
}

int	CEvent::NetSearchPlayer(DPID dpid)
{
	int i;
	BYTE* pDpid;
	
	i = 0;
	for (pDpid = (BYTE*)m_pNetwork->m_players[0].dpid; !pDpid[-4] == 0 || (dpid != *pDpid); pDpid += 32)
	{
		if (i++ >= 4)
		{
			return -1;
		}
	}
	return i;
}

void CEvent::NetStartPlay()
{
	BOOL host;
	int i;
	int* player;
	char message[2];
	char str[52];
	CNetwork* pNetwork;

	OutputNetDebug("CEvent::NetStartPlay");
	host = m_pNetwork->IsHost();

	if (host != FALSE)
	{
		message[0] = '\x02';
		message[1] = '\a';
		m_pNetwork->Send(message, 2, DPSEND_GUARANTEED);
		OutputNetDebug("Sending_MESS_START");
	}
	m_pDecor->SetTeam(0);
	pNetwork = m_pNetwork;

	i = 0;
	player = (int*) & pNetwork->m_players[0].dpid;
	
	while ((((NetPlayer*)(player + -1))->bIsPresent == FALSE || (pNetwork->m_dpid != (DPID)player)))
	{
		i++;
		player = player + 8;
		if (3 < i)
		{
			m_bMulti = TRUE;
			m_bPrivate = FALSE;
			m_pDecor->SetMulti(TRUE);
			return;
		}
	}
	m_pDecor->SetTeam((int)pNetwork->m_players[i].team);
	sprintf(str, "color=%d", (int)m_pNetwork->m_players[i].team);
	OutputNetDebug(str);
}

void CEvent::NetSend(int message, USHORT data)
{
	UCHAR packet[4];

	packet[2] = '\0';
	packet[3] = '\0';
	packet[1] = message;
	packet[0] = 4;
	*(USHORT*)packet = data;
	m_pNetwork->Send(packet, 4, DPSEND_GUARANTEED);
	return;
}

void CEvent::NetDraw()
{
	int player;

	player = NetSearchPlayer(m_pNetwork->m_dpid);
	//m_pDecor->DrawMap(TRUE, player);
	return;
}

void CEvent::ChatSend()
{
	int		netplay;
	UINT	i;
	char*	text;
	char	end[4];
	POINT*  pos;
	DPID	dpid;
	LPVOID	data[25];
	char	textInput[100];

	text = m_textInput;
	if (m_textInput[0] != '\0')
	{
		netplay = NetSearchPlayer(m_pNetwork->m_dpid);
		strcpy(textInput, "<");
	}
	if (netplay != -1)
	{
		strcat(textInput, (const char*)m_pNetwork->m_players[netplay].name);
		strcat(textInput, "> ");
		strcat(textInput, text);
		//ChatMessageSound((char*)textInput);
		end[0] = 108;
		end[1] = 11;
		dpid = m_pNetwork->m_dpid;
		m_pNetwork->Send(&end, 108, 1);
		text = 0;
		pos[132].x = 0;
		pos[132].y = strlen(text);
		pos[133].x = 0;
		m_textHiliEnd = i - 1;
		m_textCursorIndex = 0;
		SetEnable(WM_BUTTON20, 0);
	}
	return;
}

/*
void CEvent::ChatMessageSound(char* data)
{
	int num;
	char (*chatZone);
	char(*chat)[5];
	POINT pos;

	num = 3;
	chatZone = m_chatZone[0];
	do
	{
		if (chatZone = '\0')
		{
			chat = m_chatZone + num * 20;
			goto error;
		}
		num++;
		chatZone = chatZone + 100;
	} while (num < 6);
	HandleChatBuffer();
	chat = (char(*) [5])m_text;
	return;

error:
	strcpy((char*)chat, data);
	pos.x = 320;
	pos.y = 240;
	m_pSound->PlayImage(11, pos, -1);
}
*/

void CEvent::HandleChatBuffer()
{
	char (*chatZone)[5];
	int num;
	int result;
	char* text;

	num = 5;
	chatZone = m_chatZone;
	do
	{
		result = strlen((const char*)chatZone + 100) + 1;
		text = (char*)chatZone;
		chatZone += 100;
		memcpy(text, chatZone, result);
		--num;
	} while (num);
	*((BYTE*)m_text) = 0;
	return;
}

void CEvent::OutputNetDebug(const char* str)
{
	char* stream;
	FILE* streamf;
	UINT  element;

	streamf = (FILE*)m_pDecor->GetNetDebug();

	if (m_pDecor->GetNetDebug() != FALSE)
	{
		if (fopen("debug.txt", "ab") != (FILE*)0)
		{
			fwrite(str, 1, strlen(str), streamf);
			streamf = (FILE*)fclose(streamf);
		}
	}
	return;
}

void AddCheatCode(char *pDst, char *pSrc)
{
    int     i, j;

    if ( pDst[0] != 0 ) strcat(pDst, " / ");

    i = 0;
    j = strlen(pDst);
    while ( pSrc[i] != 0 )
    {
        pDst[j++] = tolower(pSrc[i++]);
    }
    pDst[j] = 0;
}


void CEvent::DrawTextCenter(int res, int x, int y, int font)
{
    char    text[100];
    POINT   pos;

    LoadString(res, text, 100);
    pos.x = x;
    pos.y = y;
    ::DrawTextCenter(m_pPixmap, pos, text, font);
}

BOOL CEvent::DrawButtons()
{
    int         i;
    int         levels[2];
    int         types[2];
    int         world, time, lg, button, volume, pente, icon, sound;
	int			nice;
	BOOL		soundEnabled;
    char        res[100];
	char		textLeft[24];
    char        text[100];
	char		pText[100];
    POINT       pos;
    RECT        rect;
    BOOL        bEnable;
	int     	phase;

    if ( m_phase != WM_PHASE_INSERT && m_phase != WM_PHASE_BYE )
    {
        m_bChangeCheat = FALSE;

        text[0] = 0;
		if (m_bBuildOfficialMissions)
		{
			AddCheatCode(text, cheat_code[0]);
		}
		if (m_bAllMissions)
		{
			AddCheatCode(text, cheat_code[1]);
		}
        if ( m_pDecor->GetSuperBlupi() )
        {
            AddCheatCode(text, cheat_code[3]);
        }
		if ( m_pDecor->GetDrawSecret() )
		{
			AddCheatCode(text, cheat_code[11]);
		}
		if ( m_pDecor->GetNetPacked() )
		{
			AddCheatCode(text, cheat_code[19]);
		}
		if (!m_pDecor->GetNetMovePredict())
		{
			AddCheatCode(text, cheat_code[21]);
		}
    }
	m_pDecor->OutputNetDebug(text);

	phase = m_phase;

	if (phase != WM_PHASE_PLAY && phase != WM_PHASE_PLAYTEST && phase != WM_PHASE_BUILD)
	{
		rect.right = 302;
		rect.left = 2;
		rect.top = 2;
		rect.bottom = 14;
		pos.x = 2;
		pos.y = 2;
		m_pPixmap->DrawPart(-1, 0, pos, rect, 1, FALSE);
	}
	DrawTextLeft(m_pPixmap, pos, text, FONTLITTLE);

	if (m_phase == WM_PHASE_INIT)
	{
		DrawText(m_pPixmap, { 414, 446 }, "Version 2.2", FONTLITTLE);
	}
	
	for (int i = 0; table[m_index].buttons[i].message != 0; i++)
	{
		m_buttons[i].Draw();
	}

	if (m_phase == WM_PHASE_GAMER)
	{
		LoadString(TX_CHOOSEGAMER, res, 100);
		lg = GetTextWidth(res, 0);
		pos.y = 26;
		pos.x = LXIMAGE / 2 - lg / 2;
		DrawTextLeft(m_pPixmap, pos, res, 1);
		*(char*)pText = m_gamerNameList[10][100];
		lg = 8;
		nice = 69;
		do
		{
			pos.y = 69;
			pos.x = 110;
			DrawText(m_pPixmap, pos, pText, 0);
			nice = 69 + 40;
			*(char*)pText += 100;
			lg--;
		} while (lg != 0);
		SetEnable(WM_PHASE_CLEARGAMER, (int)(m_filenameBuffer + -1) + m_gamer * 4 + 212);
	}

	if (m_phase == WM_PHASE_PLAY && m_phase == WM_PHASE_PLAYTEST && m_phase == WM_PHASE_BUILD)
		m_pPixmap->DrawPart(-1, 0, pos, rect, 1, 0);
	if (m_phase == WM_PHASE_CREATE)
	{
		LoadString(TX_MULTI_CREATE, res, 50);
		lg=GetTextWidth(res);
		pos.x = (320 - lg) / 2;
		pos.y = 103;
		DrawTextLeft(m_pPixmap, pos, res, FONTSLIM);
		LoadString(TX_MULTI_GNAME, res, 100);
		pos.x = (320 - lg) / 2;
		pos.y = 190;
		DrawTextLeft(m_pPixmap, pos, res, FONTSLIM);
	}
	if (m_phase == WM_PHASE_SETUP || m_phase == WM_PHASE_SETUPp)
	{
		sound = m_pSound->GetAudioVolume();
		soundEnabled = TRUE;
		if ((sound == 0) || (m_pSound->GetEnable()) == FALSE)
		{
			soundEnabled = FALSE;
		}
	}
	if (m_phase == WM_PHASE_PLAY || m_phase == WM_PHASE_PLAYTEST)
	{
		if (m_pDecor->GetPause() == 0)
		{
			if (m_bDemoRec != 0)
			{
				LoadString(TX_DEMOREC, res, 100);
				DrawTextLeft(m_pPixmap, pos, res, FONTRED);
			}
			if (m_bDemoPlay != 0)
			{
				LoadString(TX_DEMOPLAY, res, 100);
				DrawTextLeft(m_pPixmap, pos, res, FONTRED);
			}
		}
		else
		{
			if (m_pDecor->GetTime() % 20 < 15)
			{
				DrawTextCenter(TX_PAUSE, 320, 240, 0);
			}
		}
		if (m_speed > 1)
		{
			sprintf(res, "x%d", m_speed);
			DrawTextLeft(m_pPixmap, pos, res, FONTWHITE);
		}
	}
	if (m_phase == WM_PHASE_STOP)
	{
		LoadString(TX_GAMEPAUSE, res, 100);
		lg = GetTextWidth(res);
		pos.x = (319 - lg) / 2;
		pos.y = 103;
		DrawTextLeft(m_pPixmap, pos, res, FONTRED);
	}
	if (m_phase == WM_PHASE_MUSIC)
	{
		LoadString(TX_MUSIC, res, 100);
		lg=GetTextWidth(res);
		pos.x = (320 - lg) / 2;
		pos.y = 84;
		DrawTextLeft(m_pPixmap, pos, res, FONTRED);
	}
	if (m_phase == WM_PHASE_REGION)
	{
		LoadString(TX_REGION, res, 100);
		lg = GetTextWidth(res);
		pos.x = (320 - lg) / 2;
		pos.y = 26;
		DrawTextLeft(m_pPixmap, pos, res, FONTRED);
	}
	if (m_phase == WM_PHASE_LOST || m_phase == WM_PHASE_LOSTDESIGN || m_phase == WM_PHASE_WINMULTI)
	{
		LoadString(TX_LOST1 + GetWorld() % 5, res, 50);
		DrawTextLeft(m_pPixmap, pos, res, FONTWHITE);
	}
	if (m_phase == WM_PHASE_WIN || m_phase == WM_PHASE_WINDESIGN || m_phase == WM_PHASE_LOSTMULTI)
	{
		LoadString(TX_WIN1 + GetWorld() % 5, res, 50);
		DrawTextLeft(m_pPixmap, pos, res, FONTWHITE);
	}
	if (m_phase == WM_PHASE_READDESIGN)
	{

	}
	if (m_phase == WM_PHASE_GREAD || m_phase == WM_PHASE_GREADp || m_phase == WM_PHASE_GWRITE)
	{
		if (m_phase == WM_PHASE_GREAD)
		{
			LoadString(TX_SAVE_CGAME, res, 50);
		}
		else
		{
			LoadString(TX_LOAD_CGAME, res, 50);
		}
	}
	if (m_phase == WM_PHASE_BYE)
	{
		LoadString(TX_FULL_END1, res, 100);
		lg = GetTextWidth(res);
		pos.x = (320 - lg) / 2;
		pos.y = 20;
		DrawTextLeft(m_pPixmap, pos, res, FONTRED);
		LoadString(TX_FULL_END2, res, 100);
		lg = GetTextWidth(res);
		pos.x = (320 - lg) / 2;
		pos.y = 40;
		DrawTextLeft(m_pPixmap, pos, res, FONTRED);
		LoadString(TX_FULL_END3, res, 100);
		lg = GetTextWidth(res);
		pos.x = (320 - lg) / 2;
		pos.y = 430;
		DrawTextLeft(m_pPixmap, pos, res, FONTRED);
		LoadString(TX_FULL_END4, res, 100);
		lg = GetTextWidth(res);
		pos.x = (320 - lg) / 2;
		pos.y = 450;
		DrawTextLeft(m_pPixmap, pos, res, FONTRED);
	}
	if (m_phase == WM_PHASE_INSERT)
	{
		DrawTextCenter(TX_INSERT, LXIMAGE / 2, 20);
	}
	if (m_textToolTips[0] != '\0')
	{
		DrawTextLeft(m_pPixmap, m_posToolTips, m_textToolTips, FONTWHITE);
	}
	if (m_phase == WM_PHASE_CLEARGAMER)
	{
		LoadString(TX_CHOOSEGAMER, res, 100);
		lg = GetTextWidth((char*)res, 0);
		pos.y = 102;
		pos.x = 320 - lg / 2;
		DrawTextLeft(m_pPixmap, pos, (char*)res, 1);
		LoadString(TX_DISCARDGAME, res, 100);
		lg = GetTextWidth(res, 0);
		strcpy(text, (const char*)m_gamerName);
		strcat(text, "?");
		lg = GetTextWidth(text, 0);
		DrawTextLeft(m_pPixmap, pos, res, 0);
	}
	if (m_phase == WM_PHASE_CLEARDESIGN)
	{
		LoadString(TX_DESIGNMISSION, res, 100);
		lg = GetTextWidth(res, 0);
		pos.y = 104;
		pos.x = 320 - lg / 2;
		DrawTextLeft(m_pPixmap, pos, res, 1);
		LoadString(TX_DELETEMISSION, res, 100);
		GetWorld();
		sprintf(text, res);
		lg = GetTextWidth(text, 0);
		pos.y = 210;
		pos.x = 320 - lg / 2;
		DrawTextLeft(m_pPixmap, pos, text, 0);
		strcpy(text, (char*)m_pDecor->GetMissionTitle());
		
		if (text[0] == '\0')
		{
			LoadString(TX_NONAME, res, 100);
		}
		strcat(text, "?");
		lg = GetTextWidth(text, 0);
		pos.y = 230;
		pos.x = 320 - lg / 2;
		DrawTextLeft(m_pPixmap, pos, res, 0);
	}
	if (m_phase == WM_PHASE_INFO)
	{
		LoadString(TX_DESIGNMISSION, res, 100);
		lg = GetTextWidth(res, 0);
		pos.y = 37;
		pos.x = 320 - lg / 2;
		DrawTextLeft(m_pPixmap, pos, res, 0);
		// Unknown Field
		// DrawIcon
		// End of if function
		LoadString(TX_MISSIONNUM, res, 100);
		sprintf(text, res);
		lg = GetTextWidth(text, 0);
		pos.y = 106;
		pos.x = 250 - lg / 2;
		DrawTextLeft(m_pPixmap, pos, text, 1);
		strcpy(text, (char*)m_pDecor->GetMissionTitle());
		if (res[0] == '\0')
		{
			LoadString(TX_NONAME, res, 100);
		}
		lg = GetTextWidth(res, 0);
		pos.y = 269;
		pos.x = 250 - lg / 2;
		DrawTextLeft(m_pPixmap, pos, res, 0);
	}
	
	return TRUE;
}

void CEvent::PutTextInputBox(POINT pos)
{
	char textInput[100];
	char* textConst;
	int	 text;
	CPixmap* pPixmap;
	int  num;
	UINT textHili;
	LONG posD;

	text = GetTextWidth(m_textInput, 0);
	posD = pos.x - text / 2;
	textHili = m_textHiliStart;

	if (0 < (int)textHili)
	{
		memcpy(textInput, textConst, textHili);
		pPixmap = m_pPixmap;
		textInput[textHili] = 0;
		DrawTextLeft(pPixmap, pos, textInput, 0);
		text += GetTextWidth(textInput, 0);
	}
	if (m_textHiliStart < m_textHiliEnd)
	{
		textHili = m_textHiliEnd - m_textHiliStart;
		memcpy(textInput, m_textInput + m_textHiliStart, text);
		pPixmap = m_pPixmap;
		textInput[textHili] = 0;
		DrawTextLeft(pPixmap, pos, textInput, 2);
		text += GetTextWidth(textInput, 0);
	}
	if (m_textCursorIndex % 16 < 8)
	{
		pPixmap = m_pPixmap;
		DrawTextLeft(pPixmap, pos, (char*)"|", 0);
	}
	num = m_textCursorIndex;

	if (num < (int)strlen((const char*)m_textInput))
	{
		pPixmap = m_pPixmap;
		strcpy(textInput, num + m_textInput);
		DrawTextLeft(pPixmap, pos, textInput, 0);
	}
	m_textCursorIndex = m_textCursorIndex + 1;
	return;
}

/*
BOOL CEvent::TextSomething()
{
	int textHiliStart;
	char pText;

	m_textHiliStart = textHiliStart;

	if (m_textHiliEnd < textHiliStart)
	{
		return 0;
	}

	do {
		m_textInput[textHiliStart] =
			m_textHiliEnd + textHiliStart;
		pText = m_textInput + textHiliStart;
		textHiliStart = textHiliStart + 1;
	} while (pText != '\0');
	m_textHiliEnd = m_textHiliStart;
	return 1;
}
*/

POINT CEvent::GetLastMousePos()
{
	return m_oldMousePos;
}

BOOL CEvent::TreatEvent(UINT message, WPARAM wParam, LPARAM lParam)
{
	if (m_bDemoPlay)
	{
		if (message == WM_KEYDOWN ||
			message == WM_KEYUP ||
			message == WM_LBUTTONUP ||
			message == WM_RBUTTONUP)
		{
			DemoPlayStop();
			return TRUE;
		}
		if (message == WM_MOUSEMOVE)
		{
			return TRUE;
		}
	}

	return TreatEventBase(message, wParam, lParam);
}

BOOL CEvent::TreatEventBase(UINT message, WPARAM wParam, LPARAM lParam)
{
	POINT	pos;
	int		fwKeys;
	int		i, sound;
	char	c;
	BOOL	bEnable;

	pos = ConvLongToPos(lParam);
	fwKeys = wParam;

	switch (message)
	{
	case WM_KEYDOWN:

		switch (wParam)
		{
		case VK_END:
			DemoRecStop();
			return TRUE;
		case VK_ESCAPE:
			if (m_bRunMovie)
			{
				StopMovie();
				m_pSound->SetSuspendSkip(1);
				return TRUE;
			}
			if (m_phase != WM_PHASE_PLAYTEST)
			{
				if (m_phase != WM_PHASE_SETUP)
				{
					if (m_phase != WM_PHASE_NAMEGAMER)
					{
						if (m_phase == WM_PHASE_NAMEDESIGN)
						{
							m_pDecor->SetMissionTitle(m_textInput);
							ChangePhase(WM_PHASE_INFO);
							return TRUE;
						}

						if (m_phase == WM_PHASE_INIT || m_phase == WM_PHASE_WINMULTI) ChangePhase(WM_PHASE_GAMER); return TRUE;
						if (m_phase == WM_PHASE_BUILD || m_phase == WM_PHASE_LOSTDESIGN || m_phase == WM_PHASE_LOST) ChangePhase(WM_PHASE_INFO); return TRUE;
						if (m_phase != WM_PHASE_INFO && m_phase != WM_PHASE_STOP && m_phase != WM_PHASE_HELP)
						{
							if (m_phase == WM_PHASE_SERVICE)
							{
								ChangePhase(WM_PHASE_DP_DOSERVICE);
								return TRUE;
							}
							if (m_phase == WM_PHASE_CREATE)
							{
								ChangePhase(WM_PHASE_DP_DOCREATE);
								return TRUE;
							}
							if (m_phase == WM_PHASE_MULTI)
							{
								ChatSend();
								return TRUE;
							}
							if ((m_phase != WM_PHASE_GREAD && m_phase != WM_PHASE_GREADp) || m_choiceIndex < 0 || !LoadState(m_choiceIndex))
							{
								if (m_phase != WM_PHASE_GWRITE) return TRUE;

								if (m_choiceIndex < 0) return TRUE;

								if (!SaveState(m_choiceIndex)) return TRUE;
							}
						}
					}
				}
				strcpy(m_gamerName, m_textInput);
			}
		}

		if (m_phase != WM_PHASE_PLAY && m_phase != WM_PHASE_PLAYTEST)
		{
			return FALSE;
		}
		// Unknown Function

	case WM_LBUTTONDOWN:
	case WM_RBUTTONDOWN:
		m_bMouseDown = TRUE;
		MouseSprite(pos);
		if (EventButtons(message, wParam, lParam)) return TRUE;
		if (m_phase == WM_PHASE_BUILD)
		{
			//if (BuildDown(pos, fwKeys)) return TRUE;
		}
		if (m_phase == WM_PHASE_PLAY)
		{
			//	if (PlayDown(pos, fwKeys)) return TRUE;
		}
		break;
	case WM_MOUSEMOVE:
		if (m_mouseType == MOUSETYPEGRA)
		{
			if (m_bShowMouse)
			{
				ShowCursor(FALSE);  // cache la souris
				m_pPixmap->MouseShow(TRUE);  // montre sprite
				m_bShowMouse = FALSE;
			}
		}
		if (m_mouseType == MOUSETYPEWINPOS &&
			(pos.x != m_oldMousePos.x ||
				pos.y != m_oldMousePos.y))
		{
			m_oldMousePos = pos;
			ClientToScreen(m_hWnd, &m_oldMousePos);
			SetCursorPos(m_oldMousePos.x, m_oldMousePos.y);  // (*)
		}
		m_oldMousePos = pos;

		MouseSprite(pos);
		if (EventButtons(message, wParam, lParam))  return TRUE;
		if (m_phase == WM_PHASE_BUILD)
		{
			//if (BuildMove(pos, fwKeys))  return TRUE;
		}
		if (m_phase == WM_PHASE_PLAY)
		{
			//if (PlayMove(pos, fwKeys))  return TRUE;
		}
		break;

	case WM_NCMOUSEMOVE:
		if (m_mouseType == MOUSETYPEGRA)
		{
			if (!m_bShowMouse)
			{
				ShowCursor(TRUE);  // montre la souris
				m_pPixmap->MouseShow(FALSE);  // cache sprite
				m_bShowMouse = TRUE;
			}
		}
		break;

	case WM_LBUTTONUP:
	case WM_RBUTTONUP:
		m_bMousePress = FALSE;
		if (EventButtons(message, wParam, lParam))  return TRUE;
		if (m_phase == WM_PHASE_BUILD)
		{
			//if (BuildUp(pos, fwKeys))  return TRUE;
		}
		if (m_phase == WM_PHASE_PLAY)
		{
			//if (PlayUp(pos, fwKeys))  return TRUE;
		}
		if (m_phase == WM_PHASE_BYE)
		{
			PostMessage(m_hWnd, WM_CLOSE, 0, 0);
		}
		break;
	case WM_PHASE_INTRO1:
	case WM_PHASE_INTRO2:
	case WM_PHASE_INIT:
	case WM_PHASE_PLAY:
	case WM_PHASE_BUILD:
	case WM_PHASE_NAMEGAMER:
	case WM_PHASE_CLEARGAMER:
	case WM_PHASE_INFO:
	case WM_PHASE_PLAYTEST:
	case WM_PHASE_SETUP:
	case WM_PHASE_MUSIC:
	case WM_PHASE_PLAYMOVIE:
	case WM_PHASE_WINMOVIE:
	case WM_PHASE_SETUPp:
	case WM_PHASE_REGION:
	case WM_PHASE_GAMER:
	case WM_PHASE_WINMOVIEDESIGN:
	case WM_PHASE_WINMOVIEMULTI:
	case WM_PHASE_BYE:
	case WM_PHASE_NAMEDESIGN:
	case WM_PHASE_WRITEDESIGN:
	case WM_PHASE_READDESIGN:
	case WM_PHASE_CLEARDESIGN:
	case WM_PHASE_SERVICE:
	case WM_PHASE_DP_DOSERVICE:
	case WM_PHASE_DP_CANCELSERVICE:
	case WM_PHASE_SESSION:
	case WM_PHASE_DP_JOIN:
	case WM_PHASE_DP_CREATELOBBY:
	case WM_PHASE_DP_REFRESH:
	case WM_PHASE_DP_CANCELSESSION:
	case WM_PHASE_MULTI:
	case WM_PHASE_DP_STARTMULTI:
	case WM_PHASE_DP_CANCELMULTI:
	case WM_PHASE_CREATE:
	case WM_PHASE_DP_DOCREATE:
	case WM_PHASE_DP_CANCELCREATE:
	case WM_PHASE_STOP:
	case WM_PHASE_HELP:
	case WM_PHASE_GWRITE:
	case WM_PHASE_GREADp:
	case WM_PHASE_GREAD:
	case WM_PHASE_QUITPLAY:
	case WM_PHASE_1588:
		if (ChangePhase(message))  return TRUE;
		break;
	case WM_PHASE_DOPLAY:
		m_bPrivate = FALSE;
		m_mission = 1;
		if (CheckCDForWorld1())
		{
			return ChangePhase(WM_PHASE_PLAY);
		}
		else
		{
			m_tryInsertCount = 40;
			m_tryPhase = WM_PHASE_PLAY;
			return ChangePhase(WM_PHASE_INSERT);
		}
		break;
	case WM_PHASE_PRIVATE:
		m_bPrivate = true;
		return ChangePhase(WM_PHASE_INFO);
		break;
	case WM_PHASE_DEMO:
		m_demoNumber = 0;
		DemoPlayStart();
		return FALSE;
		break;
	case WM_PHASE_DONAMEGAMER:
	case WM_PHASE_DOCLEARGAMER:
	case WM_PHASE_DONAMEDESIGN:
	case WM_PHASE_DOWRITEDESIGN:
	case WM_PHASE_DOREADDESIGN:
	case WM_PHASE_DOCLEARDESIGN:
		ChangeButtons(message);
		return FALSE;
	case WM_PREV:
		i = (m_keyPress & KEY_JUMP) ? 10 : 1;
		if (m_phase == WM_PHASE_MULTI)
		{
			m_multi -= i;
			if (m_multi < 1) m_multi = 1;

			m_b6D34 = m_pDecor->Read(m_gamer, m_multi + 200, FALSE);
			if (m_b6D34) DrawMap();

			NetSendLobby();
			NetAdjustLobbyButtons();
			return TRUE;
		}
		
		if (m_bPrivate)
		{
			m_private -= i;
			if (m_private < 1) m_private = 1;

			return ChangePhase(WM_PHASE_INFO);
		}
		else
		{
			m_mission -= i;
			if (m_mission < 1) m_mission = 1;

			return ChangePhase(WM_PHASE_INFO);
		}
		break;
	case WM_NEXT:
		i = (m_keyPress & KEY_JUMP) ? 10 : 1;
		if (m_phase == WM_PHASE_MULTI)
		{
			m_multi += i;
			if (m_multi > 12) m_multi = 12;

			m_b6D34 = m_pDecor->Read(m_gamer, m_multi + 200, FALSE);
			if (m_b6D34) DrawMap();

			NetSendLobby();
			NetAdjustLobbyButtons();
			return TRUE;
		}

		if (m_bPrivate || !m_bBuildOfficialMissions)
		{
			m_private += i;
			if (m_private > 20) m_private = 20;

			return ChangePhase(WM_PHASE_INFO);
		}
		else
		{
			m_mission += i;
			if (m_mission > 320) m_mission = 320;

			return ChangePhase(WM_PHASE_INFO);
		}
		break;
	case WM_MOVIE:
		StartMovie("movie\\essai.avi");
		ChangePhase(WM_PHASE_INIT);
		return FALSE;
	case WM_DECOR1:
		SetState(WM_DECOR1, 1);
		SetState(WM_DECOR2, 0);
		SetState(WM_DECOR3, 0);
		SetState(WM_DECOR4, 0);
		SetState(WM_DECOR5, 0);
		SetState(WM_DECOR6, 0);
		SetState(WM_DECOR7, 0);
		SetState(WM_DECOR8, 0);
		SetState(WM_DECOR9, 0);
		SetState(WM_DECOR10, 0);
		SetState(WM_DECOR11, 0);

		i = GetMenu(WM_DECOR1);
		m_pDecor->SetFieldCC38AndStuff(1, i);
		m_menuIndex = 0;
		m_menuDecor[0] = i;
		break;

	case WM_DECOR2:
		SetState(WM_DECOR1, 0);
		SetState(WM_DECOR2, 1);
		SetState(WM_DECOR3, 0);
		SetState(WM_DECOR4, 0);
		SetState(WM_DECOR5, 0);
		SetState(WM_DECOR6, 0);
		SetState(WM_DECOR7, 0);
		SetState(WM_DECOR8, 0);
		SetState(WM_DECOR9, 0);
		SetState(WM_DECOR10, 0);
		SetState(WM_DECOR11, 0);

		i = GetMenu(WM_DECOR2);
		m_pDecor->SetFieldCC38AndStuff(2, i);
		m_menuIndex = 1;
		m_menuDecor[1] = i;
		break;

	case WM_DECOR3:
		SetState(WM_DECOR1, 0);
		SetState(WM_DECOR2, 0);
		SetState(WM_DECOR3, 1);
		SetState(WM_DECOR4, 0);
		SetState(WM_DECOR5, 0);
		SetState(WM_DECOR6, 0);
		SetState(WM_DECOR7, 0);
		SetState(WM_DECOR8, 0);
		SetState(WM_DECOR9, 0);
		SetState(WM_DECOR10, 0);
		SetState(WM_DECOR11, 0);

		i = GetMenu(WM_DECOR3);
		m_pDecor->SetFieldCC38AndStuff(3, i);
		m_menuIndex = 2;
		m_menuDecor[2] = i;
		break;

	case WM_DECOR4:
		SetState(WM_DECOR1, 0);
		SetState(WM_DECOR2, 0);
		SetState(WM_DECOR3, 0);
		SetState(WM_DECOR4, 1);
		SetState(WM_DECOR5, 0);
		SetState(WM_DECOR6, 0);
		SetState(WM_DECOR7, 0);
		SetState(WM_DECOR8, 0);
		SetState(WM_DECOR9, 0);
		SetState(WM_DECOR10, 0);
		SetState(WM_DECOR11, 0);

		i = GetMenu(WM_DECOR4);
		m_pDecor->SetFieldCC38AndStuff(4, i);
		m_menuIndex = 3;
		m_menuDecor[3] = i;
		break;

	case WM_DECOR5:
		SetState(WM_DECOR1, 0);
		SetState(WM_DECOR2, 0);
		SetState(WM_DECOR3, 0);
		SetState(WM_DECOR4, 0);
		SetState(WM_DECOR5, 1);
		SetState(WM_DECOR6, 0);
		SetState(WM_DECOR7, 0);
		SetState(WM_DECOR8, 0);
		SetState(WM_DECOR9, 0);
		SetState(WM_DECOR10, 0);
		SetState(WM_DECOR11, 0);

		i = GetMenu(WM_DECOR5);
		m_pDecor->SetFieldCC38AndStuff(5, i);
		m_menuIndex = 4;
		m_menuDecor[4] = i;
		break;

	case WM_DECOR6:
		SetState(WM_DECOR1, 0);
		SetState(WM_DECOR2, 0);
		SetState(WM_DECOR3, 0);
		SetState(WM_DECOR4, 0);
		SetState(WM_DECOR5, 0);
		SetState(WM_DECOR6, 1);
		SetState(WM_DECOR7, 0);
		SetState(WM_DECOR8, 0);
		SetState(WM_DECOR9, 0);
		SetState(WM_DECOR10, 0);
		SetState(WM_DECOR11, 0);

		i = GetMenu(WM_DECOR6);
		m_pDecor->SetFieldCC38AndStuff(6, i);
		m_menuIndex = 5;
		m_menuDecor[5] = i;
		break;

	case WM_DECOR7:
		SetState(WM_DECOR1, 0);
		SetState(WM_DECOR2, 0);
		SetState(WM_DECOR3, 0);
		SetState(WM_DECOR4, 0);
		SetState(WM_DECOR5, 0);
		SetState(WM_DECOR6, 0);
		SetState(WM_DECOR7, 1);
		SetState(WM_DECOR8, 0);
		SetState(WM_DECOR9, 0);
		SetState(WM_DECOR10, 0);
		SetState(WM_DECOR11, 0);

		i = GetMenu(WM_DECOR7);
		m_pDecor->SetFieldCC38AndStuff(7, i);
		m_menuIndex = 6;
		m_menuDecor[6] = i;
		break;

	case WM_DECOR8:
		SetState(WM_DECOR1, 0);
		SetState(WM_DECOR2, 0);
		SetState(WM_DECOR3, 0);
		SetState(WM_DECOR4, 0);
		SetState(WM_DECOR5, 0);
		SetState(WM_DECOR6, 0);
		SetState(WM_DECOR7, 0);
		SetState(WM_DECOR8, 1);
		SetState(WM_DECOR9, 0);
		SetState(WM_DECOR10, 0);
		SetState(WM_DECOR11, 0);

		i = GetMenu(WM_DECOR8);
		m_pDecor->SetFieldCC38AndStuff(8, i);
		m_menuIndex = 7;
		m_menuDecor[7] = i;
		break;

	case WM_DECOR9:
		SetState(WM_DECOR1, 0);
		SetState(WM_DECOR2, 0);
		SetState(WM_DECOR3, 0);
		SetState(WM_DECOR4, 0);
		SetState(WM_DECOR5, 0);
		SetState(WM_DECOR6, 0);
		SetState(WM_DECOR7, 0);
		SetState(WM_DECOR8, 0);
		SetState(WM_DECOR9, 1);
		SetState(WM_DECOR10, 0);
		SetState(WM_DECOR11, 0);

		i = GetMenu(WM_DECOR9);
		m_pDecor->SetFieldCC38AndStuff(9, i);
		m_menuIndex = 8;
		m_menuDecor[8] = i;
		break;

	case WM_DECOR10:
		SetState(WM_DECOR1, 0);
		SetState(WM_DECOR2, 0);
		SetState(WM_DECOR3, 0);
		SetState(WM_DECOR4, 0);
		SetState(WM_DECOR5, 0);
		SetState(WM_DECOR6, 0);
		SetState(WM_DECOR7, 0);
		SetState(WM_DECOR8, 0);
		SetState(WM_DECOR9, 0);
		SetState(WM_DECOR10, 1);
		SetState(WM_DECOR11, 0);

		i = GetMenu(WM_DECOR10);
		m_pDecor->SetFieldCC38AndStuff(10, i);
		m_menuIndex = 9;
		m_menuDecor[9] = i;
		break;

	case WM_DECOR11:
		SetState(WM_DECOR1, 0);
		SetState(WM_DECOR2, 0);
		SetState(WM_DECOR3, 0);
		SetState(WM_DECOR4, 0);
		SetState(WM_DECOR5, 0);
		SetState(WM_DECOR6, 0);
		SetState(WM_DECOR7, 0);
		SetState(WM_DECOR8, 0);
		SetState(WM_DECOR9, 0);
		SetState(WM_DECOR10, 0);
		SetState(WM_DECOR11, 1);

		i = GetMenu(WM_DECOR11);
		m_pDecor->SetFieldCC38AndStuff(11, i);
		m_menuIndex = 10;
		m_menuDecor[10] = i;
		break;

	case WM_BUTTON0:
	case WM_BUTTON1:
	case WM_BUTTON2:
	case WM_BUTTON3:
	case WM_BUTTON4:
	case WM_BUTTON5:
	case WM_BUTTON6:
	case WM_BUTTON7:
	case WM_BUTTON8:
	case WM_BUTTON9:
	case WM_BUTTON10:
	case WM_BUTTON11:
	case WM_BUTTON12:
	case WM_BUTTON13:
	case WM_BUTTON14:
	case WM_BUTTON15:
	case WM_BUTTON16:
	case WM_BUTTON17:
	case WM_BUTTON18:
	case WM_BUTTON19:
	case WM_BUTTON20:
	case WM_BUTTON21:
	case WM_BUTTON22:
	case WM_BUTTON23:
	case WM_BUTTON24:
	case WM_BUTTON25:
	case WM_BUTTON26:
	case WM_BUTTON27:
	case WM_BUTTON28:
	case WM_BUTTON29:
	case WM_BUTTON30:
	case WM_BUTTON31:
	case WM_BUTTON32:
	case WM_BUTTON33:
	case WM_BUTTON34:
	case WM_BUTTON35:
	case WM_BUTTON36:
	case WM_BUTTON37:
	case WM_BUTTON38:
	case WM_BUTTON39:
		ChangeButtons(message);
		break;
	}

	return FALSE;
}

BOOL CEvent::LoadState(BOOL save)
{
	BOOL saveNum;
	CEvent* pEvent;

	saveNum = save;

	if (m_pDecor->CurrentRead(m_gamer, save, (BOOL*)&pEvent, &save) == FALSE)
	{
		return FALSE;
	}
	m_bPrivate = save;
	SetMission((int)pEvent);
	m_saveIndex = saveNum;
	return TRUE;
}

int CEvent::MousePosToSprite(POINT pos)
{
	int sprite;

	sprite = SPRITE_POINTER;

	if (m_phase == WM_PHASE_PLAY ||
		m_phase == WM_PHASE_PLAYTEST ||
		m_phase == WM_PHASE_BUILD ||
		m_phase == WM_PHASE_BYE ||
		!MouseOnButton(pos))
	{
		sprite = SPRITE_POINTER;
	}
	if (m_bWaitMouse)
	{
		sprite = SPRITE_WAIT;
	}
	if (m_bHideMouse)
	{
		sprite = SPRITE_EMPTY;
	}
	if (m_bFillMouse)
	{
		sprite = SPRITE_FILL;
	}

	return sprite;
}

void CEvent::MouseSprite(POINT pos)
{
	m_mouseSprite = MousePosToSprite(pos);

	m_pPixmap->SetMousePosSprite(pos, m_mouseSprite, m_bDemoPlay);
	ChangeSprite(m_mouseSprite);
}

void CEvent::WaitMouse(BOOL bWait)
{
	m_bWaitMouse = bWait;

	if ( bWait )
	{
		m_mouseSprite = SPRITE_WAIT;
	}
	else
	{
		m_mouseSprite = MousePosToSprite(GetMousePos());
	}
	m_pPixmap->SetMouseSprite(m_mouseSprite, m_bDemoPlay);
	ChangeSprite(m_mouseSprite);
}

void CEvent::HideMouse(BOOL bHide)
{
	m_bWaitMouse = bHide;

	if ( bHide )
	{
		m_mouseSprite = SPRITE_EMPTY;
	}
	else
	{
		m_mouseSprite = MousePosToSprite(GetMousePos());
	}
	m_pPixmap->SetMouseSprite(m_mouseSprite, m_bDemoPlay);
	ChangeSprite(m_mouseSprite);
}

void CEvent::FillMouse(int bFill)
{
	m_bFillMouse = bFill;

	if (bFill)
	{
		m_mouseSprite = SPRITE_FILL;
	}
	else
	{
		m_mouseSprite = MousePosToSprite(GetMousePos());
	}
	m_pPixmap->SetMouseSprite(m_mouseSprite, m_bDemoPlay);
	ChangeSprite(m_mouseSprite);
}

BOOL CEvent::EventButtons(UINT message, WPARAM wParam, LPARAM lParam)
{
	POINT		pos, test;
	int			i, lg, oldx, sound, res;
	UINT uid;

	m_textToolTips[0] = 0;
	oldx = m_posToolTips.x;
	m_posToolTips.x = -1;
	if (m_phase != WM_PHASE_PLAY && m_phase != WM_PHASE_PLAYTEST)
	{
		for (i = 0; i < 2; i++)
		{
			if (!m_jauges[i].GetHide())
			{

				uid = 0xFFFFFFF;

				if (uid < 0)
				{
					LoadString(TX_NOTINDEMO + i, m_textToolTips, 50);
					lg = GetTextWidth(m_textToolTips);
					test.x += (DIMJAUGEX - lg) / 2;
					test.y += 4;
					m_posToolTips = test;
					break;
				}
			}
		}
		if (oldx != m_posToolTips.x)
		{
			for (i = 0; i < 2; i++)
			{
				m_jauges[i].Redraw();
			}
		}
	}
	else
	{
		i = 0;
		while (table[m_index].buttons[i].message != 0)
		{
			res = m_buttons[i].GetToolTips(pos);
			if (res != -1)
			{
				LoadString(res, m_textToolTips, 50);
				lg = GetTextWidth(m_textToolTips);
				pos.x += 10;
				pos.y += 20;
				if (pos.x > LXIMAGE - lg) pos.x = LXIMAGE - lg;
				if (pos.y > LYIMAGE - 14) pos.y = LYIMAGE - 14;
				m_posToolTips = pos;
				break;
			}
			i++;
		}
	}
	i = 0;
	while (table[m_index].buttons[i].message != 0)
	{
		if (m_buttons[i].TreatEvent(message, wParam, lParam)) return TRUE;
		i++;
	}
	if (m_phase == WM_PHASE_PLAY || m_phase == WM_PHASE_PLAYTEST)
	{
		if (m_menu.TreatEvent(message, wParam, lParam)) return TRUE;
	}
	return FALSE;
}

BOOL CEvent::MouseOnButton(POINT pos)
{
	int 	i;

	i = 0;
	while ( table[m_index].buttons[i].message != 0 )
	{
		if ( m_buttons[i].MouseOnButton(pos) ) return TRUE;
		i ++;
	}

	return FALSE;
}

int CEvent::SearchPhase(UINT phase)
{
	int		i = 0;

	while (table[i].phase != 0)
	{
		if (table[i].phase == phase) return i;
		i++;
	}

	return -1;
}

int CEvent::GetWorld()
{
	//m_mission = mission;
	if (m_bPrivate) return m_bPrivate;
	if (m_bMulti)	return m_multi+200;
	else			return m_mission;
}

int CEvent::GetPhysicalWorld()
{
	if ( m_bPrivate ) return m_bPrivate;
	if ( m_bMulti   ) return m_multi+200;
	else 			  return m_mission;
}

BOOL CEvent::IsPrivate()
{
	return m_bPrivate;
}

BOOL CEvent::IsMulti()
{
	return m_bMulti;
}

int CEvent::GetWorldGroup()
{
	int mission;
	m_mission = mission;
	
	if (m_mission % 10 != 0 && m_mission != 99)
	{
		m_mission = (mission / 10) * 10;
		return -(m_mission >> 31);
	}
	m_mission = 1;
	return m_mission / 10;
}

void CEvent::SetMission(int index)
{
	if (m_bPrivate != 0)
	{
		m_private = index;
		return;
	}
	if (m_bMulti != 0)
	{
		m_multi = index;
		return;
	}
	m_mission = index;
	return;
}

UINT CEvent::GetPhase()
{
	return m_phase;
}

void CEvent::TryInsert()
{
	if ( m_tryInsertCount == 0 )
	{
		ChangePhase(m_tryPhase);
	}
	else
	{
		m_tryInsertCount --;
	}
}

void CEvent::ReadAll()
{
	BOOL mission;
	BOOL read;
	BOOL bUser;
	BOOL bPrivate;
	BOOL bMission;

	if ((-1 < m_choiceIndex) && (*(int*)((int)(m_filenameBuffer + -1) + m_choiceIndex * 4 + 216) != 0))
	{
		//mission = m_pDecor->MissionStart(m_gamer, 999, bUser);
		
		if (mission != FALSE)
		{
			read = m_pDecor->CurrentRead(m_gamer, m_choiceIndex, &bMission, &bPrivate);
			
			if (read != FALSE)
			{
				//m_pDecor->DrawMap(FALSE, -1);
			}
			m_pDecor->CurrentRead(m_gamer, 999, &bMission, &bPrivate);
		}
	}
	return;
}

BOOL CEvent::SaveState(int rank)
{
	BOOL bMission;
	BOOL bUser;
	char str[100];

	//bMission = m_pDecor->MissionStart(m_gamer, rank, bUser);

	if (bMission == FALSE)
	{
		return FALSE;
	}
	LoadString(TX_GAMESAVED, str, 100);
	m_pDecor->NotifPush(str);
	// m_field959_0x6d10 = rank;
	return TRUE;
}

void CEvent::SomethingUserMissions(char* lpFilename, LPCSTR fileSomething)
{
	UINT buffer;
	char* folderName;

	mkdir("\\User");
	strcpy(lpFilename, "\\User\\");
	strcat(lpFilename, fileSomething);

	if ((folderName = strstr(folderName, ".xch")) || ((buffer = 0, folderName - lpFilename != strlen(lpFilename) - 4)))
	{
		buffer = 0;
		strcat(lpFilename, ".xch");
	}
	return;
}

// Add SomethingHubWorld once figured out.

// Very rough code, needs improvement

BOOL CEvent::ChangePhase(UINT phase)
{
	int	  index, world, time, total, music, i, max, mission;
	POINT totalDim, iconDim;
	char  str[MAX_PATH];
	char* pButtonExist;
	BOOL  bEnable, bHide;
	char* playerName;

	sprintf(str, "CEvent::ChangePhase [Begin] --- %d\r\n", phase - WM_USER);
	OutputNetDebug(str);
	if (phase == WM_PHASE_1588)
	{
	    PostMessage(m_hWnd, WM_CLOSE, 0, 0);
		return TRUE;
	}
	m_pDecor->SetDemoPlay(m_bDemoPlay);
	if (m_mouseType == MOUSETYPEGRA && m_bFullScreen)
	{
		m_bShowMouse = FALSE;
	}
	if (phase == WM_PHASE_QUITPLAYTEST)
	{
		m_pDecor->Read(m_gamer, 999, TRUE);
		phase = WM_PHASE_BUILD;
	}

	if (!m_bDemoPlay &&
		phase == WM_PHASE_PLAY ||
		m_phase == WM_PHASE_PLAY ||
		phase == WM_PHASE_STOP ||
		phase == WM_PHASE_SETUP ||
		phase == WM_PHASE_HELP ||
		phase == WM_PHASE_GREAD ||
		phase == WM_PHASE_GREADp ||
		phase == WM_PHASE_GWRITE)
	{
		m_pSound->StopMusic();
	}

	m_textToolTips[0] = 0;
	m_posToolTips.x = -1;
	m_pDecor->SetPause(FALSE);
	m_bHili = FALSE;
	m_bCtrlDown = FALSE;
	m_bMouseDown = FALSE;
	m_bInfoHelp = FALSE;


	if (phase == WM_PHASE_INIT)
	{
		m_demoTime = 0;
	}
	if (phase == WM_PHASE_PLAY)
	{
		if (!m_bDemoPlay && GetWorld() > 299 && GetWorld() < 320)
		{
			DemoRecStart();
		}
	}
	else
	{
		DemoRecStop();
	}

	if (phase == WM_PHASE_QUITPLAY)
	{
		if (!m_bPrivate)
		{
			if (!m_bMulti)
			{
				mission = m_mission;
				if (mission != 1)
				{
					if (mission == 99 || mission % 10 == 0)
					{
						mission = 1;
					}
					else
					{
						mission = (mission / 10) * 10;
					}
					SetMission(mission);
					m_phase = WM_PHASE_PLAY;

					return ChangePhase(WM_PHASE_PLAY);
				}
			}
		}
		else if (!m_bMulti)
		{
			return ChangePhase(WM_PHASE_INFO);
		}
	}
	if (phase == WM_PHASE_DP_DOSERVICE)
	{
		// ...
	}
	if (phase == WM_PHASE_DP_CANCELSERVICE)
	{
		// ...
	}
	if (phase == WM_PHASE_DP_JOIN)
	{
		// ...
	}
	if (phase == WM_PHASE_DP_CREATELOBBY)
	{
		// ...
	}
	if (phase == WM_PHASE_DP_REFRESH)
	{
		// ...
	}
	if (phase == WM_PHASE_DP_CANCELSESSION)
	{
		// ...
	}
	if (phase == WM_PHASE_DP_DOCREATE)
	{
		// ...
	}
	if (phase == WM_PHASE_DP_CANCELCREATE)
	{
		// ...
	}
	if (phase == WM_PHASE_DP_STARTMULTI)
	{
		// ...
	}
	if (phase == WM_PHASE_DP_CANCELMULTI)
	{
		// ...
	}

	if (SearchPhase(phase) < 0)
	{
		return 0;
	}
	m_pPixmap->MouseInvalidate();
	HideMouse(FALSE);
	WaitMouse(TRUE);

	if (phase == WM_PHASE_GAMER || phase == WM_PHASE_PLAY)
	{
		OutputNetDebug("CEvent::ChangePhase_[WriteInfo]\r\n");
		WriteInfo(m_gamer);
	}

	int oldPhase = m_phase;
	if ((oldPhase == WM_PHASE_BUILD && phase == WM_PHASE_INFO) || oldPhase == WM_PHASE_REGION || oldPhase == WM_PHASE_NAMEDESIGN || oldPhase == WM_PHASE_MUSIC)
	{
		m_pDecor->Write(m_gamer, GetWorld(), !m_bBuildOfficialMissions);
	}
	
	m_phase = phase;
	m_index = SearchPhase(phase);
	if (table[m_index].bUnk && !CheckCDForWorld1())
	{
		m_tryInsertCount = 40;
		m_tryPhase = m_phase;
		return ChangePhase(WM_PHASE_INSERT);
	}

	if (table[m_index].backName[0] != '\0')
	{
		strcpy(str, table[m_index].backName);
		if (str[0] != '\0')
		{
			if (table[m_index].bCDrom)
			{
				AddCDPath(str);
			}
			if (!m_pPixmap->BackgroundCache(0, str, { LXIMAGE, LYIMAGE }, { 0,0 }, FALSE))
			{
				OutputNetDebug("CEvent::ChangePhase [Cache error]\r\n");
				WaitMouse(FALSE);
				m_tryInsertCount = 40;
				m_tryPhase = m_phase;
				return ChangePhase(WM_PHASE_INSERT);
			}
		}
	}

	if (m_phase == WM_PHASE_PLAY && !m_bPrivate &&
		oldPhase != WM_PHASE_SETUPp &&
		oldPhase != WM_PHASE_HELP &&
		oldPhase != WM_PHASE_GREAD &&
		oldPhase != WM_PHASE_GREADp &&
		oldPhase != WM_PHASE_GWRITE &&
		oldPhase != WM_PHASE_STOP)
	{
		sprintf(str, "CEvent::ChangePhase [Read] %d, %d\r\n", m_gamer, GetWorld());
		OutputNetDebug(str);

		if (!m_pDecor->Read(m_gamer, GetWorld(), FALSE))
		{
			OutputNetDebug("CEvent::ChangePhase [Read error]\r\n");
			m_tryInsertCount = 40;
			m_tryPhase = m_phase;
			return ChangePhase(WM_PHASE_INSERT);
		}
		m_pDecor->DrawMap(TRUE, -1);
	}

	if (m_phase == WM_PHASE_INFO && m_bPrivate)
	{
		m_b6D34 = m_pDecor->Read(m_gamer, GetWorld(), !m_bBuildOfficialMissions);
		if (m_b6D34)
		{
			m_pDecor->DrawMap(TRUE, -1);
		}
	}

	if ((m_phase == WM_PHASE_PLAY || m_phase == WM_PHASE_PLAYTEST) &&
		oldPhase != WM_PHASE_SETUPp &&
		oldPhase != WM_PHASE_HELP &&
		oldPhase != WM_PHASE_GREAD &&
		oldPhase != WM_PHASE_GREADp &&
		oldPhase != WM_PHASE_GWRITE &&
		oldPhase != WM_PHASE_STOP)
	{
		m_pDecor->AdaptDoors(m_bPrivate, GetWorld());
	}

	if (m_phase == WM_PHASE_TESTCD)
	{
		if (m_pDecor->Read(1, 1, FALSE))
		{
			return ChangePhase(WM_PHASE_INIT);
		}
		else
		{
			m_tryInsertCount = 40;
			m_tryPhase = m_phase;
			return ChangePhase(WM_PHASE_INSERT);
		}
	}

	if (m_phase == WM_PHASE_PLAYTEST)
	{
		m_pDecor->Write(m_gamer, 999, TRUE);
		m_pDecor->PlayPrepare(TRUE);
	}

	if (m_phase == WM_PHASE_PLAY &&
		oldPhase != WM_PHASE_SETUPp &&
		oldPhase != WM_PHASE_HELP &&
		oldPhase != WM_PHASE_GREAD &&
		oldPhase != WM_PHASE_GREADp &&
		oldPhase != WM_PHASE_GWRITE &&
		oldPhase != WM_PHASE_STOP)
	{
		if (m_bPrivate || m_bMulti)
		{
			m_pDecor->PlayPrepare(TRUE);
		}
		else
		{
			m_pDecor->PlayPrepare(FALSE);
			m_pDecor->SetNbVies(m_nbVies);
		}
	}

	if (m_phase == WM_PHASE_BUILD)
	{
		m_pDecor->BuildPrepare();
	}

	CreateButtons();
	m_96B4 = 0;
	m_menu.Delete();
	if (m_phase == WM_PHASE_BUILD)
	{
		SetState(m_menuIndex + WM_DECOR1, 1);
		SetMenu(WM_DECOR1, m_menuDecor[0]);
		SetMenu(WM_DECOR2, m_menuDecor[1]);
		SetMenu(WM_DECOR3, m_menuDecor[2]);
		SetMenu(WM_DECOR4, m_menuDecor[3]);
		SetMenu(WM_DECOR5, m_menuDecor[4]);
		SetMenu(WM_DECOR6, m_menuDecor[5]);
		SetMenu(WM_DECOR7, m_menuDecor[6]);
		SetMenu(WM_DECOR8, m_menuDecor[7]);
		SetMenu(WM_DECOR9, m_menuDecor[8]);
		SetMenu(WM_DECOR10, m_menuDecor[9]);
		SetMenu(WM_DECOR11, m_menuDecor[10]);
		m_pDecor->SetFieldCC38AndStuff(m_menuIndex + 1, GetMenu(m_menuIndex + WM_DECOR1));
	}
	if (m_phase == WM_PHASE_PLAY || m_phase == WM_PHASE_PLAYTEST || m_phase == WM_PHASE_BUILD)
	{
		OutputNetDebug("CEvent::ChangePhase [LoadImages]\r\n");
		m_pDecor->LoadImages();
	}
	if (m_phase == WM_PHASE_INFO)
	{
		SetEnable(WM_PREV, GetWorld() != 1);
		if (m_bBuildOfficialMissions)
		{
			SetEnable(WM_NEXT, GetWorld() < 319);
		}
		else
		{
			SetEnable(WM_NEXT, GetWorld() < 20);
		}
		SetHide(WM_PHASE_BUILD, FALSE);
		SetEnable(WM_PHASE_WRITEDESIGN, m_b6D34);
		SetEnable(WM_PHASE_READDESIGN, !m_b6D34);
		SetEnable(WM_PHASE_CLEARDESIGN, m_b6D34);
		SetEnable(WM_PHASE_PLAYMOVIE, m_b6D34);
	}
	if (m_phase == WM_PHASE_GAMER)
	{
		WriteInfo(m_gamer);
		// ...
	}
	if (m_phase == WM_PHASE_NAMEGAMER)
	{
		// ...
	}
	if (m_phase == WM_PHASE_NAMEDESIGN)
	{
		// ...
	}
	if (m_phase == WM_PHASE_MUSIC)
	{
		int music = m_pDecor->GetMusic();
		for (int i = 0; i < 11; i++)
		{
			SetState(WM_BUTTON1 + i, i == music);
		}
	}
	if (m_phase == WM_PHASE_REGION)
	{
		int region = m_pDecor->GetRegion();
		for (int i = 0; i < 32; i++)
		{
			SetState(WM_BUTTON1 + i, i == region);
		}
		POINT dim = m_pDecor->GetDim();
		if (dim.x == MAXCELX)
		{
			if (dim.y == MAXCELY)
			{
				SetState(WM_DIMS1, 1);
				SetState(WM_DIMS2, 0);
				SetState(WM_DIMS3, 0);
				SetState(WM_DIMS4, 0);
			}
			if (dim.y == 0)
			{
				SetState(WM_DIMS1, 0);
				SetState(WM_DIMS2, 1);
				SetState(WM_DIMS3, 0);
				SetState(WM_DIMS4, 0);
			}
		}
		else if (dim.y == MAXCELY)
		{
			SetState(WM_DIMS1, 0);
			SetState(WM_DIMS2, 0);
			SetState(WM_DIMS3, 1);
			SetState(WM_DIMS4, 0);
		}
		else
		{
			SetState(WM_DIMS1, 0);
			SetState(WM_DIMS2, 0);
			SetState(WM_DIMS3, 0);
			SetState(WM_DIMS4, 1);
		}
	}
	if (m_phase == WM_PHASE_SERVICE)
	{
		m_pNetwork->EnumProviders();
		m_nbChoices = m_pNetwork->GetNbProviders();
		m_choicePageOffset = 0;
		m_choiceIndex = 0;
		SetHide(WM_BUTTON10, TRUE);
		// ...
	}
	if (m_phase == WM_PHASE_SESSION)
	{
		// ...
	}
	if (m_phase == WM_PHASE_MULTI)
	{
		// ...
	}
	if (m_phase == WM_PHASE_CREATE)
	{
		// ...
	}
	if (m_phase == WM_PHASE_STOP && m_bMulti)
	{
		SetEnable(WM_PHASE_GWRITE, 0);
		SetEnable(WM_PHASE_GREADp, 0);
	}
	if (m_phase == WM_PHASE_WRITEDESIGN || m_phase == WM_PHASE_READDESIGN)
	{
		// ...
	}
	if (m_phase == WM_PHASE_READDESIGN)
	{
		// ...
	}
	if (m_phase == WM_PHASE_WRITEDESIGN)
	{
		// ...
	}
	if (m_phase == WM_PHASE_GWRITE || m_phase == WM_PHASE_GREADp || m_phase == WM_PHASE_GREAD)
	{
		// ...
	}
	if (m_phase == WM_PHASE_SETUP || m_phase == WM_PHASE_SETUPp)
	{
		m_0008 = 0;
		// ...
	}
	if ((m_phase == WM_PHASE_PLAY || m_phase == WM_PHASE_PLAYTEST || m_phase == WM_PHASE_MUSIC) && !m_bDemoPlay)
	{
		if (!m_pSound->IsPlayingMusic())
		{
			int music = m_pDecor->GetMusic();
			if (music > 0)
			{
				m_pSound->PlayMusic(m_hWnd, music);
			}
		}
		else
		{
			m_pSound->AdaptVolumeMusic();
		}
	}
	if (m_phase == WM_PHASE_PLAYMOVIE)
	{
		sprintf(m_movieToStart, "movie\\play%.3d.avi", GetWorld());
		AddCDPath(m_movieToStart);
		m_phaseAfterMovie = WM_PHASE_PLAY;
	}
	if (m_phase == WM_PHASE_WINMOVIE)
	{
		sprintf(m_movieToStart, "movie\\win%.3d.avi", GetWorld());
		AddCDPath(m_movieToStart);
		m_phaseAfterMovie = WM_PHASE_WIN;
	}
	if (m_phase == WM_PHASE_WINMOVIEDESIGN)
	{
		sprintf(m_movieToStart, "movie\\win%.3d.avi", GetWorld());
		AddCDPath(m_movieToStart);
		m_phaseAfterMovie = WM_PHASE_WINDESIGN;
	}
	if (m_phase == WM_PHASE_WINMOVIEMULTI)
	{
		sprintf(m_movieToStart, "movie\\win%.3d.avi", GetWorld());
		AddCDPath(m_movieToStart);
		m_phaseAfterMovie = WM_PHASE_LOSTMULTI; // ?
	}
	WaitMouse(FALSE);
	if (m_phase == WM_PHASE_PLAY || m_phase == WM_PHASE_PLAYTEST)
	{
		FillMouse(TRUE);
	}
	m_pDecor->VehicleSoundsPhase(phase);
	OutputNetDebug("CEvent::ChangePhase [End]");
	
	return TRUE;

}

// Implement LoadLevel

void CEvent::MovieToStart()
{
	if (m_movieToStart[0] != 0)
	{
		HideMouse(TRUE);

		if (StartMovie(m_movieToStart))
		{
			m_phase = m_phaseAfterMovie;
		}
		else
		{
			ChangePhase(m_phaseAfterMovie);
		}

		m_movieToStart[0] = 0;
	}
}

void CEvent::MouseRelease()
{
	m_bMouseRelease = TRUE;
	ShowCursor(TRUE);
	return;
}

void CEvent::MouseCapture()
{
	m_bMouseRelease = FALSE;
	ShowCursor(FALSE);
	return;
}

BOOL CEvent::NetCreate(int session)
{
	BOOL created;

	MouseRelease();
	created = m_pNetwork->CreateProvider(session);
	MouseCapture();
	return created;
}

BOOL CEvent::NetEnumSessions()
{
	BOOL enumSess;

	MouseRelease();
	enumSess = m_pNetwork->EnumProviders();
	MouseCapture();
	return enumSess;
}

BOOL CEvent::BuildUp(POINT pos, int fwKeys)
{
	return TRUE;
}

/*
void CEvent::TryPhase()
{
	m_tryPhase = 1;
	ShowCursor(1);
}

void CEvent::UnTryPhase()
{
	m_tryPhase = 0;
	ShowCursor(1);
}

int CEvent::GetTryPhase()
{
	return m_tryPhase;
}

void CEvent::GetDoors(int doors)
{
	for (int i = 0; i < 200; i++)
	{
		doors[i] = (int)data[Gamer];
	}
}


void CEvent::TableSomething()
{
	char filename[MAX_PATH];

	if (strstr(filename, table[m_index].backName))
	{
		AddCDPath(filename);
	}
	if (!m_pPixmap->CacheAll(CHBACK, filename, totalDim, iconDim, FALSE, GetRegion()))
	{
		return;
	}
}
*/



BOOL CEvent::StartMovie(char* pFilename)
{
	RECT	 rect;
	char	 filename[MAX_PATH];

	if (!m_pMovie->GetEnable()) return FALSE;
	if (!m_bMovie) return FALSE;

	if (!m_pMovie->IsExist(pFilename)) return FALSE;

	rect.left = 1;
	rect.top = 1;
	rect.right = LXIMAGE - 2;
	rect.bottom = LYIMAGE - 2;

	m_pSound->StopMusic();
	m_pPixmap->SavePalette();

	strcpy(filename, pFilename);
	strcpy(filename + strlen(filename) - 4, ".blp");
	m_pSound->Cache(SOUND_MOVIE, filename);

	if (m_pMovie->Play(m_hWnd, rect, pFilename)) return FALSE;
	m_bRunMovie = TRUE;
	m_pSound->Play(SOUND_MOVIE, 0, 0);
	return TRUE;
}

void CEvent::StopMovie()
{
	m_pMovie->Stop(m_hWnd);
	m_pPixmap->RestorePalette();
	m_pPixmap->MouseInvalidate();
	m_pSound->Flush(SOUND_MOVIE);
	ChangePhase(m_phase);
	m_bRunMovie = FALSE;
}

BOOL CEvent::IsMovie()
{
	return m_bRunMovie;
}

BOOL CEvent::IsMouseRelease()
{
	return m_bMouseRelease;
}

BOOL CEvent::ReadLibelle(int world, BOOL bSchool, BOOL bHelp)
{
	FILE* file = NULL;
	char* pBuffer = NULL;
	char* pText;
	char* pDest;
	char  indic;
	int	  nb, h1, h2;

	pBuffer = (char*)malloc(sizeof(char) * 2560);
	if (pBuffer == NULL) goto error;
	memset(pBuffer, 0, sizeof(char) * 2560);

	//file = fopen


error:
	if (pBuffer != NULL) free(pBuffer);
	if (file	!= NULL) fclose(file);
	return FALSE;
}

void CEvent::SetLives(int lives)
{
	m_lives = lives;
}

void CEvent::SetSpeed(int speed)
{
	if ( speed > 2 ) speed = 2;
	
	m_speed = speed;
}

int CEvent::GetSpeed()
{
	return m_speed;
}

BOOL CEvent::GetPause()
{
	return m_bPause;
}

int CEvent::MissionBack()
{
	int num = m_mission;

	if (num % 10 == 0 ||
		num == 99)
	{
		m_mission = 1;
		return num / 10;
	}
	else
	{
		m_mission = num / 10 * 10;
		return (num < 0);
	}
}

void CEvent::DemoRecStart()
{
	m_pDemoBuffer = (DemoEvent*)malloc(MAXDEMO*sizeof(DemoEvent));
	if ( m_pDemoBuffer == NULL ) return;
	memset(m_pDemoBuffer, 0, MAXDEMO*sizeof(DemoEvent));

	m_demoTime  = 0;
	m_demoIndex = 0;
	m_bDemoRec  = TRUE;
	m_bDemoPlay = FALSE;

	InitRandom();
	m_pDecor->SetTime(0);
	m_speed = 1;
}

void CEvent::DemoRecStop()
{
	FILE* 		 file = NULL;
	DemoHeader   header;

	if ( m_bDemoPlay ) return;

	if ( m_pDemoBuffer != NULL )
	{
		DeleteFileA("data\\demo.3d.blp");
		file = fopen("data\\demo.3d.blp", "wb");
		if ( file != NULL )
		{
			memset(&header, 0, sizeof(DemoHeader));
			header.majRev 	= 1;
			header.minRev   = 0;
			header.bSchool  = m_bSchool;
			header.bPrivate = m_bPrivate;
			fwrite(&header, sizeof(DemoHeader), 1, file);
			fwrite(m_pDemoBuffer, sizeof(DemoEvent), m_demoIndex, file);
			fclose(file);
		}
		free(m_pDemoBuffer);
		m_pDemoBuffer = NULL;
	}

	m_bDemoRec = FALSE;
	m_demoTime = 0;
}

BOOL CEvent::DemoPlayStart()
{
	char		filename[MAX_PATH];
	FILE* file = NULL;
	DemoHeader	header;
	int			nb, world, time, total, mission;

	m_pDemoBuffer = (DemoEvent*)malloc(MAXDEMO * sizeof(DemoEvent));
	if (m_pDemoBuffer == NULL)  return FALSE;
	memset(m_pDemoBuffer, 0, MAXDEMO * sizeof(DemoEvent));

	sprintf(filename, "data\\demo%.3d.blp", m_demoNumber);
	AddCDPath(filename);  // ajoute l'acc�s au CD-Rom
	file = fopen(filename, "rb");
	if (file == NULL)
	{
		DemoPlayStop();
		return FALSE;
	}

	nb = fread(&header, sizeof(DemoHeader), 1, file);
	if (nb < 1)
	{
		DemoPlayStop();
		return FALSE;
	}
	m_bSchool = header.bSchool;
	m_bPrivate = header.bPrivate;
	//m_pDecor->SetSkill(header.skill);

	m_demoEnd = fread(m_pDemoBuffer, sizeof(DemoEvent), MAXDEMO, file);
	fclose(file);

	m_demoTime = 0;
	m_demoIndex = 0;
	m_bDemoPlay = TRUE;
	m_bDemoRec = FALSE;

	/*
	if (!m_pDecor->CurrentRead(m_gamer, mission, FALSE))
	{
		DemoPlayStop();
		return FALSE;
	}
	ChangePhase(WM_PHASE_PLAY);
	InitRandom();
	m_pDecor->SetTime(0);
	m_speed = 1;
	*/
	return TRUE;
}

void CEvent::DemoPlayStop()
{
	if (m_pDemoBuffer != NULL)
	{
		free(m_pDemoBuffer);
		m_pDemoBuffer = NULL;
	}
	m_bDemoPlay = FALSE;
	m_bDemoRec = FALSE;
	m_demoTime = 0;
	m_keyPress = 0;
	m_pDecor->SetInput(0);
	m_private = 1;
	ChangePhase(WM_PHASE_INIT);
}

void CEvent::DemoStep()
{
	int			time;
	UINT		message;
	WPARAM		wParam;
	LPARAM		lParam;
	POINT		pos;

	if (m_phase == WM_PHASE_INIT)
	{
		if (m_demoTime > DEF_TIME_DEMO)  // ~30 secondes �coul�es ?
		{
			m_demoNumber = 0;
			DemoPlayStart();  // d�marre une d�mo automatique
		}
	}

	if (m_bDemoPlay &&  // d�mo en lecture ?
		m_pDemoBuffer != NULL)
	{
		while (TRUE)
		{
			time = m_pDemoBuffer[m_demoIndex].time;
			if (time > m_demoTime)  break;

			message = m_pDemoBuffer[m_demoIndex].message;
			wParam = m_pDemoBuffer[m_demoIndex].wParam;
			lParam = m_pDemoBuffer[m_demoIndex].lParam;
			m_demoIndex++;

			if (message == WM_MOUSEMOVE &&
				m_mouseType == MOUSETYPEWIN)
			{
				pos = ConvLongToPos(lParam);
				ClientToScreen(m_hWnd, &pos);
				SetCursorPos(pos.x, pos.y);
			}

			TreatEventBase(message, wParam, lParam);

			if (m_demoIndex >= m_demoEnd)
			{
				m_demoNumber++;  // d�mo suivante
				if (!DemoPlayStart())  // d�marre la d�mo suivante
				{
					m_demoNumber = 0;  // premi�re d�mo
					DemoPlayStart();   // d�marre la d�mo
				}
				return;
			}
		}
	}

	m_demoTime++;
}

void CEvent::DemoRecEvent(UINT message, UINT input, WPARAM wParam, LPARAM lParam)
{
	if (m_demoIndex > 0 &&
		m_pDemoBuffer[m_demoIndex - 1].time == m_demoTime &&
		m_pDemoBuffer[m_demoIndex - 1].input == m_keyPress)

		m_demoIndex++;
	if (m_demoIndex >= MAXDEMO)
	{
		DemoRecStop();
	}
}

BOOL CEvent::WriteInfo(int gamer)
{
	char		filename[MAX_PATH];
	FILE*		file = NULL;
	DescInfo	info;
	int			nb;
	int			doors;
	char		text[100];

	sprintf(filename, "data\\info%.3d.blp", gamer);
	AddUserPath(filename);
	file = fopen(filename, "wb");
	if (file == NULL) goto error;

	strcpy(text, m_gamerName);

	info.majRev = 1;
	info.minRev = 0;
	info.prive = m_private;
	info.mission = m_mission;
	info.multi = m_multi;
	info.nbVies = m_nbVies;
	info.speed = m_speed;
	info.bMovie = m_bMovie;
	info.bHiliInfoButton = m_bHiliInfoButton;
	info.bBuildOfficialMissions = m_bBuildOfficialMissions;

	info.audioVolume = m_pSound->GetAudioVolume();
	info.midiVolume = m_pSound->GetMidiVolume();

	m_pDecor->InitializeDoors(info.doors);

	nb = fwrite(&info, sizeof(DescInfo), 1, file);
	if (nb < 1) goto error;

	fclose(file);
	return TRUE;

error:
	if (file != NULL) fclose(file);
	return FALSE;
}

BOOL CEvent::ReadInfo(int gamer)
{
	char	 filename[MAX_PATH];
	FILE*	 file = NULL;
	DescInfo info;
	int		 nb;
	BYTE	 doors[200];
	char	 buffer[100];


	m_pDecor->InitGamer();
	m_lives = 3;
	m_mission = 1;
	m_private = 1;
	m_multi = 1;

	LoadString(TX_READINFO, buffer, 100);
	sprintf(m_gamerName, buffer, gamer);
	sprintf(filename, "data\\info%.3d.blp", gamer);
	AddUserPath(filename);


	file = fopen(filename, "rb");
	if (file == NULL) goto error;
	
	nb = fread(&info, sizeof(DescInfo), 1, file);
	if (nb < 1) goto error;

	if ((BYTE*)m_gamerName)
	{
		strcpy((char*)m_gamerName, buffer);
	}

	info.majRev = 1;
	m_private = info.prive;
	m_multi = info.multi;
	m_nbVies = info.nbVies;
	m_bMovie = info.bMovie;
	m_mission = info.mission;
	m_bHiliInfoButton = info.bHiliInfoButton;
	m_speed = info.speed;
	m_bBuildOfficialMissions = info.bBuildOfficialMissions;

	m_pDecor->SetBuildOfficialMissions(info.bBuildOfficialMissions);
	m_pSound->SetAudioVolume(info.audioVolume);
	m_pSound->SetMidiVolume(info.midiVolume);
	m_pDecor->MemorizeDoors(doors);
	fclose(file);
	return TRUE;

error:
	if (file != NULL) fclose(file);
	return FALSE;
}

BOOL CEvent::ReadPlayer()
{
	char filename[MAX_PATH];

	m_playerIndex = 0;

	strcpy(filename, "data\\info%.3d.blp");
	AddUserPath(filename);
	remove(filename);
	return TRUE;
}

void CEvent::ChangeButtons(int message)
{
	if (m_phase == WM_PHASE_GAMER && message >= WM_BUTTON1 && message <= WM_BUTTON10)
	{
		m_gamer = message - WM_BUTTON0;
		for (int i = 0; i < 10; i++)
		{
			SetState(WM_BUTTON1 + i, i == m_gamer - 1);
		}
		ReadInfo(m_gamer);
	}
	if (m_phase == WM_PHASE_NAMEGAMER && message == WM_PHASE_DONAMEGAMER)
	{
		WriteInfo(m_gamer);
		ChangePhase(WM_PHASE_GAMER);
	}
	if (m_phase == WM_PHASE_NAMEDESIGN && message == WM_PHASE_DONAMEDESIGN)
	{
		m_pDecor->SetMissionTitle(m_textInput);
		ChangePhase(WM_PHASE_INFO);
	}
	if (m_phase == WM_PHASE_CLEARGAMER && message == WM_PHASE_DOCLEARGAMER)
	{
		ClearGamer(m_gamer);
		ChangePhase(WM_PHASE_GAMER);
	}
	if (m_phase == WM_PHASE_CLEARDESIGN && message == WM_PHASE_DOCLEARDESIGN)
	{
		m_pDecor->SomethingMissionPath(m_gamer, GetWorld(), !m_bBuildOfficialMissions);
		ChangePhase(WM_PHASE_INFO);
	}
	if (m_phase == WM_PHASE_MUSIC)
	{
		m_pDecor->SetMusic(message - WM_BUTTON0);
		ChangePhase(m_phase);
	}
	if (m_phase == WM_PHASE_REGION)
	{
		if (message >= WM_BUTTON1 && message <= WM_BUTTON32)
		{
			m_pDecor->SetRegion(message - WM_BUTTON1);
		}
		if (message >= WM_DIMS1 && message <= WM_DIMS4)
		{
			SetState(WM_DIMS1, 0);
			SetState(WM_DIMS2, 0);
			SetState(WM_DIMS3, 0);
			SetState(WM_DIMS4, 0);
			SetState(message, 1);
			if (message == WM_DIMS1) m_pDecor->SetDim({ MAXCELX, MAXCELY });
			if (message == WM_DIMS2) m_pDecor->SetDim({ MAXCELX, 0 });
			if (message == WM_DIMS3) m_pDecor->SetDim({ 0, MAXCELY });
			if (message == WM_DIMS4) m_pDecor->SetDim({ 0, 0 });
		}
	}
	if (m_phase == WM_PHASE_SERVICE)
	{
		if (message >= WM_BUTTON1 && message <= WM_BUTTON6)
		{
			m_choiceIndex = message - WM_BUTTON1 + m_choicePageOffset;
		}
		if (message == WM_BUTTON10)
		{
			m_choicePageOffset -= 6;
			if (m_choicePageOffset < 0) m_choicePageOffset = 0;
		}
		if (message == WM_BUTTON11)
		{
			m_choicePageOffset += 6;
		}
		SetHide(WM_BUTTON10, m_choicePageOffset == 0);
		SetHide(WM_BUTTON11, (m_nbChoices + 5) / 6 * 6 <= m_choicePageOffset + 6);
		for (int i = 0; i < 6; i++)
		{
			if (m_choicePageOffset + i < m_nbChoices)
			{
				SetHide(WM_BUTTON1 + i, FALSE);
				SetState(WM_BUTTON1 + i, m_choicePageOffset == m_choiceIndex);
			}
			else
			{
				SetHide(WM_BUTTON1 + i, TRUE);
			}
		}
	}
	if (m_phase == WM_PHASE_SESSION)
	{
		if (message >= WM_BUTTON1 && message <= WM_BUTTON6)
		{
			m_choiceIndex = message - WM_BUTTON1 + m_choicePageOffset;
		}
		if (message == WM_BUTTON10)
		{
			m_choicePageOffset -= 6;
			if (m_choicePageOffset < 0) m_choicePageOffset = 0;
		}
		if (message == WM_BUTTON11)
		{
			m_choicePageOffset += 6;
		}
		SetHide(WM_BUTTON10, m_choicePageOffset == 0);
		SetHide(WM_BUTTON11, (m_nbChoices + 5) / 6 * 6 <= m_choicePageOffset + 6);
		for (int i = 0; i < 6; i++)
		{
			if (m_choicePageOffset + i < m_nbChoices)
			{
				SetHide(WM_BUTTON1 + i, FALSE);
				SetState(WM_BUTTON1 + i, m_choicePageOffset == m_choiceIndex);
			}
			else
			{
				SetHide(WM_BUTTON1 + i, TRUE);
			}
		}
	}
	if (m_phase == WM_PHASE_MULTI)
	{
		if (message >= WM_BUTTON1 && message <= WM_BUTTON4)
		{
			if (m_pNetwork->m_players[message - WM_BUTTON1].team >= MAXNETPLAYER)
			{
				m_pNetwork->m_players[message - WM_BUTTON1].team = 0;
			}

			if (m_pNetwork->IsHost())
			{
				NetSendLobby();
			}
			else
			{
				//TODO
				//m_pNetwork->Send(...
			}
			//DrawMap();
			//NetAdjustLobbyButtons();
		}
		if (message >= WM_BUTTON11 && message <= WM_BUTTON14)
		{
			m_pNetwork->m_players[message - WM_BUTTON11].ready ^= 1; // toggle ready
			if (m_pNetwork->IsHost())
			{
				NetSendLobby();
			}
			else
			{
				//TODO
				//m_pNetwork->Send(...
			}
			//NetAdjustLobbyButtons();
		}
		if (message == WM_BUTTON20)
		{
			ChatSend();
		}
	}
	if (m_phase == WM_PHASE_READDESIGN)
	{
		//TODO
	}
	if (m_phase == WM_PHASE_WRITEDESIGN)
	{
		//TODO
	}
	if (m_phase == WM_PHASE_GREAD || m_phase == WM_PHASE_GREADp)
	{
		//TODO
	}
	if (m_phase == WM_PHASE_GWRITE)
	{
		//TODO
	}
	if (m_phase == WM_PHASE_SETUP || m_phase == WM_PHASE_SETUPp)
	{
		//TODO
	}
}

BOOL CEvent::ClearGamer(int gamer)
{
	char filename[260];

	m_6D30 = 0;
	sprintf(filename, "data\\info%.3d.blp", gamer);
	AddUserPath(filename);
	remove(filename);
	return TRUE;
}

BOOL CEvent::CheckCDForWorld1()
{
	// TODO
	return TRUE;
}

void CEvent::DrawMap()
{
	//TODO
}

void CEvent::NetAdjustLobbyButtons()
{
	//TODO
}

BOOL CEvent::CopyMission(char *srcFileName, char *dstFileName)
{
	FILE *srcFile = NULL;
	FILE *destFile = NULL;
	size_t num;
	BOOL bOK = TRUE;
	void *buffer = malloc(2560);

	if (buffer)
	{
		srcFile = fopen(srcFileName, "rb");
		if (!srcFile) goto die;
		destFile = fopen(dstFileName, "wb");
		if (destFile)
		{
			do
			{
				num = fread(buffer, 1, 2560, srcFile);
				if (ferror(srcFile)) break; // *
				if (num <= 0)
				{
					bOK = FALSE;
					break;
				}
				fwrite(buffer, 1, num, destFile);
			} while (!ferror(destFile)); // *
		}
	}
	if (srcFile) fclose(srcFile);
die:
	if (destFile) fclose(destFile);
	if (buffer) free(buffer);
	return bOK;

	// *
	// original code relies on undefined behavior specific to older msvc :
	// if (srcFile->_flag & _IOERR)
	// while (!(destFile->_flag & _IOERR))
}