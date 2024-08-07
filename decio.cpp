// DecIO.cpp
//

#include "def.h"
#include "decor.h"
#include "misc.h"

void CDecor::GetMissionPath(char* str, int user, int mission, BOOL bUser)
{
	if (bUser != 0)
	{
		sprintf(str, "data\%.3d-%.3d.blp", user, mission);
		AddUserPath(str);
		return;
	}
	sprintf(str, "data\world%.3d.blp", mission);
	AddUserPath(str);
	return;
}

BOOL CDecor::CurrentWrite(int gamer, int mission, BOOL bUser)
{
	char		filename[MAX_PATH];
	FILE*		file = NULL;
	DescFile*	pBuffer = NULL;
	int			nb, i;

	InitDecor();
	GetMissionPath(filename, gamer, mission, bUser);

	file = fopen(filename, "wb");
	if (file == NULL) goto error;

	pBuffer = (DescFile*)malloc(sizeof(DescFile));
	if (pBuffer == NULL) goto error;
	memset(pBuffer, 0, sizeof(DescFile));

	pBuffer->cameraPos = m_posDecor;
	pBuffer->worldDim = m_dimDecor;
	pBuffer->music = m_music;
	pBuffer->region = m_region;

	for (i = 0; i < MAXBUTTON; i++)
	{
		pBuffer->ButtonExist[i] = m_buttonExist[i];
	}
	for (i = 0; i < 4; i++)
	{
		pBuffer->memoPos[i] = m_memoPos[i];
	}

error:
	if (pBuffer != NULL) free(pBuffer);
	if (file != NULL)	 fclose(file);
	return FALSE;
}

BOOL CDecor::CurrentRead(int gamer, int mission, BOOL bUser)
{
	char		filename[MAX_PATH];
	FILE* file = NULL;
	DescFile* pBuffer = NULL;
	int			majRev, minRev;
	int			nb, i, x, y;
	OldBlupi	oldBlupi;

	Init(-1, -1);

	if (bUser)
	{
		sprintf(filename, "data\\user%.3d.blp", rank);
		AddUserPath(filename);
	}
	else
	{
		sprintf(filename, "data\\world%.3d.blp", rank);
		if (rank < 200)
		{
			AddCDPath(filename);
		}
	}

	file = fopen(filename, "rb");
	if (file == NULL)  goto error;

	pBuffer = (DescFile*)malloc(sizeof(DescFile));
	if (pBuffer == NULL)  goto error;

	nb = fread(pBuffer, sizeof(DescFile), 1, file);
	if (nb < 1)  goto error;

	majRev = pBuffer->majRev;
	minRev = pBuffer->minRev;

	if (majRev == 1 && minRev == 0)  goto error;

	if (majRev == 1 && minRev == 3)
	{
		if (pBuffer->nbDecor != MAXCELX * MAXCELY ||
			pBuffer->lgDecor != sizeof(Cellule) ||
			pBuffer->nbBlupi != MAXBLUPI ||
			pBuffer->lgBlupi != sizeof(OldBlupi) ||
			pBuffer->nbMove != MAXMOVE ||
			pBuffer->lgMove != sizeof(Move))  goto error;
	}
	else
	{
		if (pBuffer->nbDecor != MAXCELX * MAXCELY ||
			pBuffer->lgDecor != sizeof(Cellule) ||
			pBuffer->nbBlupi != MAXBLUPI ||
			pBuffer->lgBlupi != sizeof(Blupi) ||
			pBuffer->nbMove != MAXMOVE ||
			pBuffer->lgMove != sizeof(Move))  goto error;
	}

	SetCoin(pBuffer->celCoin);
	if (bUser)
	{
		world = pBuffer->world;
		time = pBuffer->time;
		total = pBuffer->totalTime;
	}
	m_celHome = pBuffer->celCoin;
	m_term = pBuffer->term;
	m_music = pBuffer->music;
	m_region = pBuffer->region;

	if (bUser)
	{
		m_skill = pBuffer->skill;
	}

	for (i = 0; i < MAXBUTTON; i++)
	{
		m_buttonExist[i] = pBuffer->buttonExist[i];
	}

	for (i = 0; i < 4; i++)
	{
		m_memoPos[i] = pBuffer->memoPos[i];
	}

	nb = fread(m_decor, sizeof(Cellule), MAXCELX * MAXCELY / 4, file);
	if (nb < MAXCELX * MAXCELY / 4)  goto error;
	if (majRev == 1 && minRev < 5)
	{
		for (x = 0; x < MAXCELX / 2; x++)
		{
			for (y = 0; y < MAXCELY / 2; y++)
			{
				if (m_decor[x][y].objectIcon >= 128 &&
					m_decor[x][y].objectIcon <= 130)
				{
					m_decor[x][y].objectIcon -= 128 - 17;
				}
			}
		}
	}

	if (majRev == 1 && minRev == 3)
	{
		memset(m_blupi, 0, sizeof(Blupi) * MAXBLUPI);
		for (i = 0; i < MAXBLUPI; i++)
		{
			nb = fread(&oldBlupi, sizeof(OldBlupi), 1, file);
			if (nb != 1)  goto error;
			memcpy(m_blupi + i, &oldBlupi, sizeof(OldBlupi));
			ListFlush(i);
		}
	}
	else
	{
		nb = fread(m_blupi, sizeof(Blupi), MAXBLUPI, file);
		if (nb < MAXBLUPI)  goto error;
	}

	nb = fread(m_move, sizeof(Move), MAXMOVE, file);
	if (nb < MAXMOVE)  goto error;

	nb = fread(m_lastDrapeau, sizeof(POINT), MAXLASTDRAPEAU, file);
	if (nb < MAXLASTDRAPEAU)
	{
		InitDrapeau();
	}

	BlupiDeselect();

	free(pBuffer);
	fclose(file);
	return TRUE;

error:
	if (pBuffer != NULL)  free(pBuffer);
	if (file != NULL)  fclose(file);

	Flush();
	return FALSE;
}

BOOL CDecor::SomethingMissionPath(int gamer, int mission, BOOL bUser)
{

}

BOOL CDecor::MissionStart(int gamer, int mission, BOOL bUser)
{

}

BOOL CDecor::Read(int gamer, int mission, BOOL *pbMission, BOOL *pbPrivate)
{

}

BOOL CDecor::Write(int gamer, int mission, char* param3)
{

}
