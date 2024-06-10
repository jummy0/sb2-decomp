// Event.cpp
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
#include "movie.h"
#include "button.h"
#include "menu.h"
#include "jauge.h"
#include "event.h"
#include "action.h"
#include "text.h"
#include "misc.h"

/////////////////////////////////////////////////////////////////////////////

static Phase table[] =
{
	{
		WM_PHASE_TESTCD,
		"init.blp",
		FALSE,
		{
			{
				0
			}
		}
	},
	
	{
		WM_PHASE_INIT,
		"init.blp",
		FALSE,
		{
			{
				WM_PHASE_GAMER,
				0, {1, 0x30},
				86, 410,
				{1, TX_BUTTON_PLAY}
			},
			{
				WM_PHASE_DEMO,
				0, {1, 0x54},
				128, 410,
				{1, TX_BUTTON_DEMO}
			},
			{
#if _EGAMES
				WM_CLOSE,
#else
				WM_PHASE_BYE,
#endif
				0, {1, 6},
				520, 410,
				{1, TX_BUTTON_QUIT}
			},
		},
	}
}