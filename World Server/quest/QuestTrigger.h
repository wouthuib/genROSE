/*
    Rose Online Server Emulator
    Copyright (C) 2006,2007 OSRose Team http://www.dev-osrose.com

    This program is free software; you can redistribute it and/or
    modify it under the terms of the GNU General Public License
    as published by the Free Software Foundation; either version 2
    of the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

    depeloped with Main erose/hrose source server + some change from the original eich source
*/
// Props to ExJam for this code :D Ported to OSpRose by Drakia
class CQuestTrigger {
public:
	struct SQuestDatum {
		int size;
		int opcode;
		BYTE* data;
	};

	strings TriggerName;
	DWORD TriggerHash;

	BYTE CheckNext;
	DWORD id;

	DWORD ConditionCount;
	SQuestDatum** Conditions;

	DWORD ActionCount;
	SQuestDatum** Actions;
private:
};

struct STR_NPCVAR {
	DWORD iNpcNo;
	WORD nVarNo;
	WORD unused;
};

struct STR_ITEM_DATA {
	DWORD uiItemSN;
	DWORD iWhere;
	DWORD iRequestCnt;
	BYTE btOp;
};

struct STR_QUEST_DATA {
	union {
		DWORD iType;
		struct {
			short m_wVarNO;
			WORD m_wVarTYPE;
		};
	};
	WORD nValue;
	BYTE btOp;
};

struct STR_ABIL_DATA {
	DWORD iType;
	int iValue;
	BYTE btOp;
};

#define QUEST_FAILURE 6
#define QUEST_SUCCESS 5
template <class T> int OperateValues(BYTE btOp, T* value1PTR, T value2){
	T value1 = *value1PTR;
	switch(btOp){
		case 0:
			return (value1 == value2);
		case 1:
			return (value1 > value2);
		case 2:
			return (value1 >= value2);
		case 3:
			return (value1 < value2);
		case 4:
			return (value1 <= value2);
		case 5:
			(*value1PTR) = value2;
			return 1;
		case 6:
			(*value1PTR) = value1 + value2;
			return 1;
		case 7:
			(*value1PTR) = value1 - value2;
			return 1;
		case 9:
			(*value1PTR) += 1;
			return 1;
		case 10:
			return (value1 != value2);
		default:
			Log(MSG_WARNING, "OperateValues unknown btOp='%u'", btOp);
			return 0;
	}
}
DWORD GetRewardValue(DWORD function, DWORD amount, CPlayer* client, WORD nDupCNT);

//LMA: AIP
DWORD GetRewardValue(DWORD function, DWORD amount, CCharacter* client, WORD nDupCNT);

#include "QuestConditions.h"
#include "QuestActions.h"
