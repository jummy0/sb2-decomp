/***********************************************
 * Sound related stuff, I dunno
************************************************/

#ifndef WAVE_H
#define WAVE_H

#include <dsound.h>

void LoadWave(HINSTANCE hinst, int ResourceID,
              LPDIRECTSOUND lpds,
              LPDIRECTSOUNDBUFFER &lpDSB);

#endif