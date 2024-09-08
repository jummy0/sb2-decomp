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

BOOL CDecor::Write(int gamer, int mission, BOOL bUser)
{
	return FALSE; //TODO
}

BOOL CDecor::Read(int gamer, int mission, BOOL bUser)
{
	return FALSE; //TODO
}

BOOL CDecor::SomethingMissionPath(int gamer, int mission, BOOL bUser)
{
	return FALSE; //TODO
}

BOOL CDecor::MissionStart(int gamer, int mission, BOOL bUser)
{
	return FALSE; //TODO
}

BOOL CDecor::CurrentRead(int gamer, int mission, BOOL *pbMission, BOOL *pbPrivate)
{
	return FALSE; //TODO
}

BOOL CDecor::CurrentWrite(int gamer, int mission, char* param3)
{
	return FALSE; //TODO
}
