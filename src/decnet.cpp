// DecNet.cpp
//

#include "def.h"
#include "decor.h"
#include "misc.h"
#include "network.h"

void CDecor::NetStopCloud(int rank)
{
	NetMessage msg;

	msg.type = MESS_STOPCLOUD;
	msg.data1 = 0;
	msg.data2 = 0;
	msg.data3 = 0;
	msg.data4 = rank;
	NetMessagePush(&msg);
	return;
}

void CDecor::NetPlaySound(short channel, POINT pos)
{
	NetMessage msg;

	msg.type = MESS_PLAYSOUND;
	msg.data1 = 0;
	msg.data2 = pos.x;
	msg.data3 = pos.y;
	msg.data4 = channel;
	NetMessagePush(&msg);
	return;
}

void CDecor::NetStopSound(short channel)
{
	NetMessage msg;

	msg.type = MESS_STOPSOUND;
	msg.data1 = 0;
	msg.data2 = 0;
	msg.data3 = 0;
	msg.data4 = channel;
	NetMessagePush(&msg);
}

void CDecor::NetDataFlush()
{
	for (int i = 0; i < MAXNETPLAYER; i++)
	{
		m_netBlupiPos[i].x = 0;
		m_netBlupiPos[i].y = 0;
		m_netBlupiIcon[i] = -1;
		m_netBlupiSec[i] = 0;
		m_netBlupiTransport[i] = 0;
		m_netTransports[i] = 0;
		m_netTimes[i] = 0;
		m_netPrevTimes[i] = 0;
		m_netTimeSincePacket[i] = 0;
		m_netVitesses[i].x = 0;
		m_netVitesses[i].y = 0;
		m_netBlupiPrevPos[i].x = 0;
		m_netBlupiPrevPos[i].y = 0;
	}
	m_netPacketsSent = 0;
	m_netPacketsSent2 = 0;
	m_netPacketsReceived = 0;
	m_netPacketsReceived2 = 0;
	m_netPacketIcon = -1;
	NetMessageIndexFlush();
}

void CDecor::NetSendBarePacket(BYTE type, short num)
{
	char data[4];
	data[0] = 4;
	data[1] = type;
	data[2] = num & 0xff;
	data[3] = num >> 8;
	m_pNetwork->Send(&data, 4, DPSEND_GUARANTEED);
	return;
}

void CDecor::TreatNetData()
{
	NetPacket pack;
	NetMessage* pMsg;
	int i, j, dt;
	int flag = 0;
	int player;
	int foo;
	char res[100];
	char text[100];

	BOOL recentSenders[MAXNETPLAYER];

	if ((m_netMessageIndex1 != 0 ||
		m_blupiIcon != m_netPacketIcon ||
		m_blupiPos != m_netPacketPos) &&
		!m_bNetPacked || m_time % 2 == 0)
	{
		m_netPacketPos = m_blupiPos;
		m_netPacketIcon = m_blupiIcon;
		pack.time = m_time;
		pack.keyPress = m_keyPress;
		pack.blupiPosX = m_blupiPos.x;
		pack.blupiPosY = m_blupiPos.y;
		pack.blupiIcon = m_blupiIcon;
		pack.size = sizeof(pack);
		pack.type = 1;
		pack.blupiSec = m_blupiSec;
		pack.blupiChannel = m_blupiChannel;
		pack.blupiTransport = m_blupiTransport;
		pack.nbMessages = 0;
		for (i = 0; i < MAXMESSAGEPERPACKET; i++)
		{
			if (!NetMessagePop(&pack.messages[i]))
			{
				break;
			}
			pack.nbMessages++;
			if (pack.messages[i].type == MESS_OBJECTSTART ||
				pack.messages[i].type == MESS_OBJECTDELETE)
			{
				if (pack.messages[i].data4 != TYPE_EXPLO1 &&
					pack.messages[i].data4 != TYPE_EXPLO2 &&
					pack.messages[i].data4 != TYPE_EXPLO3 &&
					pack.messages[i].data4 != TYPE_EXPLO4 &&
					pack.messages[i].data4 != TYPE_EXPLO5 &&
					pack.messages[i].data4 != TYPE_EXPLO6 &&
					pack.messages[i].data4 != TYPE_EXPLO7 &&
					pack.messages[i].data4 != TYPE_EXPLO8 &&
					pack.messages[i].data4 != TYPE_EXPLO9 &&
					pack.messages[i].data4 != TYPE_EXPLO10 &&
					pack.messages[i].data4 != TYPE_SPLOUTCH1 &&
					pack.messages[i].data4 != TYPE_SPLOUTCH2 &&
					pack.messages[i].data4 != TYPE_SPLOUTCH3 &&
					pack.messages[i].data4 != TYPE_TENTACULE &&
					pack.messages[i].data4 != TYPE_PLOUF &&
					pack.messages[i].data4 != TYPE_BLUP &&
					pack.messages[i].data4 != TYPE_MAGICTRACK &&
					pack.messages[i].data4 != TYPE_SHIELDTRACK &&
					pack.messages[i].data4 != TYPE_TRESORTRACK &&
					pack.messages[i].data4 != TYPE_TIPLOUF &&
					pack.messages[i].data4 != TYPE_INVERTSTART &&
					pack.messages[i].data4 != TYPE_INVERTSTOP &&
					pack.messages[i].data4 != TYPE_POLLUTION)
				{
					flag = 1;
				}
			}
		}
		pack.unk12 = flag;
		m_pNetwork->Send(&pack, sizeof(NetMessage) * pack.nbMessages + 20, flag);
		m_netPacketsSent++;
		if (flag) m_netPacketsSent2++;
	}

	ZeroMemory(&recentSenders, sizeof(recentSenders));

	for (i = 0; i < 10; i++)
	{
		if (!m_pNetwork->Receive(&pack, sizeof(pack), (LPDWORD)&player))
		{
			break;
		}

		if (pack.type == 1)
		{
			m_netPacketsReceived++;
			if (pack.unk12) m_netPacketsReceived2++;

			if (player < MAXNETPLAYER)
			{
				if (pack.time > m_netTimes[player])
				{
					m_netPrevTimes[player] = m_netTimes[player];
					recentSenders[player] = TRUE;
					m_netTimes[player] = pack.time;
					m_netBlupiPos[player].x = pack.blupiPosX;
					m_netBlupiPos[player].y = pack.blupiPosY;
					m_netBlupiIcon[player] = pack.blupiIcon;
					m_netBlupiSec[player] = pack.blupiSec;
					m_netBlupiTransport[player] = pack.blupiTransport;
					dt = pack.time - m_netPrevTimes[player];
					if (dt <= 0)
					{
						m_netVitesses[player] = POINT(0, 0);
					}
					else
					{
						m_netVitesses[player] = (m_netBlupiPos[player] - m_netBlupiPrevPos[player]) / dt;
					}
					m_netBlupiPrevPos[player] = m_netBlupiPos[player];
					m_netTimeSincePacket[player] = 0;
				}
			}
			for (j = 0; j < pack.nbMessages; j++)
			{
				pMsg = &pack.messages[j];
				switch (pMsg->type)
				{
				case MESS_OBJECTSTART:
					ObjectStart(POINT(pMsg->data2, pMsg->data3), pMsg->data4, pMsg->data1, FALSE);
					break;
				case MESS_OBJECTDELETE:
					ObjectDelete(POINT(pMsg->data2, pMsg->data3), pMsg->data4, FALSE);
					break;
				case MESS_MODIFDECOR:
					ModifDecor(POINT(pMsg->data2, pMsg->data3), pMsg->data4, FALSE);
					break;
				case MESS_PLAYSOUND:
					m_pSound->PlayImage(pMsg->data4, POINT(pMsg->data2, pMsg->data3) - m_posDecor, -1);
					break;
				case MESS_STOPSOUND:
					m_pSound->StopSound(pMsg->data4);
					break;
				case MESS_ASCENSEURSTART:
					NetAscenseurSynchro(pMsg->data4, STEP_STOPSTART);
					break;
				case MESS_ASCENSEUREND:
					NetAscenseurSynchro(pMsg->data4, STEP_STOPEND);
					break;
				case MESS_STOPCLOUD:
					if (pMsg->data4 == m_team)
					{
						m_blupiCloud = FALSE;
						m_jauges[JAUGE_POWER].SetHide(TRUE);
					}
					break;
				}
			}
		}
		if (pack.type == PK_LEAVE)
		{
			LoadString(257, res, 100);
			sprintf(text, res, m_pNetwork->m_players[player].name);
			NotifPush(text);
			m_pNetwork->m_players[player].bIsPresent = 0;
			m_netBlupiIcon[player] = -1;
		}
		if (pack.type == PK_LOST)
		{
			LoadString(258, res, 100);
			sprintf(text, res, m_pNetwork->m_players[player].name);
			NotifPush(text);
			m_pNetwork->m_players[player].bIsPresent = 0;
			m_netBlupiIcon[player] = -1;
		}
		if (pack.type == PK_DIE)
		{
			if (pack.keyPress == 0)
			{
				LoadString(261, res, 100);
			}
			else if (pack.keyPress == 1)
			{
				LoadString(260, res, 100);
			}
			else
			{
				LoadString(259, res, 100);
			}
			sprintf(text, res, m_pNetwork->m_players[player].name, pack.keyPress);
			NotifPush(text);
		}
		if (pack.type == PK_PAUSE)
		{
			m_bPause = pack.keyPress;
		}
	}

	for (i = 0; i < MAXNETPLAYER; i++)
	{
		if (!recentSenders[i])
		{
			DoNetSmooth(i);
		}
	}
}

void CDecor::DoNetSmooth(int player)
{
	POINT start, end;
	RECT rect;

	if (m_bNetMovePredict && m_netBlupiIcon[player] != -1)
	{
		if (m_netTimeSincePacket[player] < 5)
		{
			start = m_netBlupiPos[player];
			end = start + m_netVitesses[player];
			rect = RECT(start.x + 12, start.y + 11, start.x + DIMBLUPIX - 12, start.y + DIMBLUPIY - 2);
			TestPath(rect, start, &end);
			m_netBlupiPos[player] = end;
		}
		m_netTimeSincePacket[player]++;
	}
}

void CDecor::NetAdjustToLift()
{
	for (int i = 0; i < MAXNETPLAYER; i++)
	{
		if (m_netBlupiPos[i].x != -1 && m_netTransports[i] >= 0 && m_netTransports[i] < MAXMOVEOBJECT)
		{
			m_netBlupiPos[i].y = m_moveObject[m_netTransports[i]].posCurrent.y - (DIMBLUPIY - 2);
		}
	}
}

void CDecor::NetAscenseurSynchro(int index, short step)
{
	int i;
	POINT delta;
	MoveObject* otherMob;
	MoveObject* mob = &m_moveObject[index];

	mob->step = step;
	mob->time = 0;
	delta.x = abs(mob->posEnd.x - mob->posStart.x);
	delta.y = abs(mob->posEnd.y - mob->posStart.y);

	for (i = 0; i < MAXMOVEOBJECT; i++)
	{
		otherMob = &m_moveObject[i];
		if (i != index && otherMob->type == mob->type)
		{
			if (otherMob->stepAdvance == mob->stepAdvance &&
				otherMob->stepRecede == mob->stepRecede &&
				otherMob->timeStopStart == mob->timeStopStart &&
				otherMob->timeStopEnd == mob->timeStopEnd)
			{
				otherMob->step = step;
				otherMob->time = 0;
			}
		}
	}
}


void CDecor::NetPlayerCollide(POINT pos, int* out)
{
	int i;
	RECT	rect1;
	RECT	rect2;
	RECT	rect3;

	rect2.left = pos.x + 16;
	rect2.top = pos.y + 11;
	rect2.right = pos.x + DIMBLUPIX - 16;
	rect2.bottom = pos.y + DIMBLUPIY - 2;

	for (i = 0; i < MAXNETPLAYER; i++)
	{
		if (m_netBlupiIcon[i] != -1)
		{
			if (m_netBlupiSec[i] != SEC_HIDE)
			{
				rect1.left = m_netBlupiPos[i].x + 16;
				rect1.top = m_netBlupiPos[i].y + 11;
				rect1.right = m_netBlupiPos[i].x + DIMBLUPIX - 16;
				rect1.bottom = m_netBlupiPos[i].y + DIMBLUPIY - 2;
			}
			if (IntersectRect(&rect3, &rect1, &rect2))
			{
				*out = i;
			}
		}
	}
	*out = -1;
}

void CDecor::NetMessageIndexFlush()
{
	m_netMessageIndex1 = 0;
	m_netMessageIndex2 = 0;
	m_netMessageIndex3 = 0;
	return;
}

BOOL CDecor::NetMessagePush(NetMessage* message)
{
	NetMessage* messages;
	BYTE		data;
	short		pos;
	int			i;

	if (m_netMessageIndex1 == MAXNETMESSAGE) return FALSE;

	CopyMemory(&m_netMessages[m_netMessageIndex2], message, sizeof(NetMessage));
	m_netMessageIndex1++;
	m_netMessageIndex2++;
	if (m_netMessageIndex2 == MAXNETMESSAGE)
	{
		m_netMessageIndex2 = 0;
	}
	return TRUE;
}

BOOL CDecor::NetMessagePop(NetMessage* out_msg)
{
	int i;

	if (m_netMessageIndex1 == 0) return FALSE;

	CopyMemory(out_msg, &m_netMessages[m_netMessageIndex3], sizeof(NetMessage));
	m_netMessageIndex1--;
	m_netMessageIndex3++;
	if (m_netMessageIndex3 == MAXNETMESSAGE)
	{
		m_netMessageIndex3 = 0;
	}
	return TRUE;
}

void CDecor::NotifFlush()
{
	for (int i = 0; i < MAXNOTIF; i++)
	{
		m_notifText[i][0] = '\0';
	}

	m_notifTime = 0;
}

void CDecor::NotifPop()
{
	for (int i = MAXNOTIF; i > 0; --i)
	{
		//strcpy()
			m_notifText[MAXNOTIF - 1][0] = '\0';
		m_notifTime = NOTIFDELAY; // idk
	}
}

void CDecor::NotifPush(char *str)
{
	int i;
	for (i = 0; i < MAXNOTIF; i++)
	{
		if (m_notifText[i][0] != '\0') break;
	}
	if (i >= MAXNOTIF)
	{
		NotifPop();
		i = MAXNOTIF - 1;
	}
	strcpy(m_notifText[i], str);
	m_notifTime = NOTIFDELAY;
	m_pSound->PlayImage(SOUND_TRESOR, POINT( LXIMAGE / 2, LYIMAGE / 2 ), -1);
}

void CDecor::NotifStep()
{
	if (m_notifTime == 0)
	{
		NotifPop();
	}
	else {
		m_notifTime--;
	}
}

