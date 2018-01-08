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
#define QUESTREWD(reward) int QUEST_REWD_ ## reward (class CWorldServer* server, class CPlayer* client, BYTE* raw)
typedef int (*fpQuestRewd)(class CWorldServer*, class CPlayer*, BYTE*);

//LMA: AIP
#define QUESTREWDC(reward) int QUEST_REWDC_ ## reward (class CWorldServer* server, class CCharacter* client, BYTE* raw)
typedef int (*fpQuestRewdC)(class CWorldServer*, class CCharacter*, BYTE*);

#define GETREWDDATA(rewd) STR_REWD_ ## rewd * data = (STR_REWD_ ## rewd *)raw

QUESTREWD(000);QUESTREWD(001);QUESTREWD(002);
QUESTREWD(003);QUESTREWD(004);QUESTREWD(005);
QUESTREWD(006);QUESTREWD(007);QUESTREWD(008);
QUESTREWD(009);QUESTREWD(010);QUESTREWD(011);
QUESTREWD(012);QUESTREWD(013);QUESTREWD(014);
QUESTREWD(015);QUESTREWD(016);QUESTREWD(017);
QUESTREWD(018);QUESTREWD(019);QUESTREWD(020);
QUESTREWD(021);QUESTREWD(022);QUESTREWD(023);
QUESTREWD(024);QUESTREWD(025);QUESTREWD(026);
QUESTREWD(027);QUESTREWD(028);QUESTREWD(029);
QUESTREWD(034);

//LMA: For AIP
QUESTREWDC(000);QUESTREWDC(001);QUESTREWDC(002);
QUESTREWDC(003);QUESTREWDC(004);QUESTREWDC(005);
QUESTREWDC(006);QUESTREWDC(007);QUESTREWDC(008);
QUESTREWDC(009);QUESTREWDC(010);QUESTREWDC(011);
QUESTREWDC(012);QUESTREWDC(013);QUESTREWDC(014);
QUESTREWDC(015);QUESTREWDC(016);QUESTREWDC(017);
QUESTREWDC(018);QUESTREWDC(019);QUESTREWDC(020);
QUESTREWDC(021);QUESTREWDC(022);QUESTREWDC(023);
QUESTREWDC(024);QUESTREWDC(025);QUESTREWDC(026);
QUESTREWDC(027);QUESTREWDC(028);QUESTREWDC(029);
QUESTREWDC(034);


struct STR_REWD_000 {
	DWORD iQuestSN;
	BYTE btOp;
};

struct STR_REWD_001 {
	DWORD uiItemSN;
	union {
		BYTE btOp;
		WORD nOp;
	};
	WORD nDupCNT;
	BYTE btPartyOpt;
};

struct STR_REWD_002 {
	DWORD iDataCnt;
	STR_QUEST_DATA* CheckData;
};

struct STR_REWD_003 {
	DWORD iDataCnt;
	STR_ABIL_DATA* CheckData;
	BYTE btPartyOpt;
};

struct STR_REWD_004 {
	DWORD iDataCnt;
	STR_QUEST_DATA* CheckData;
};

struct STR_REWD_005 {
	BYTE btTarget;
	union {
		BYTE btEquation;
		WORD nEquation;
	};
	int iValue;
	DWORD iItemSN;
	union {
		BYTE btPartyOpt;
		WORD nPartyOpt;
	};
	WORD nItemOpt;
};

struct STR_REWD_006 {
	DWORD iPercentOfHP;
	DWORD iPercentOfMP;
	BYTE btPartyOpt;
};

struct STR_REWD_007 {
	DWORD iZoneSN;
	DWORD iX;
	DWORD iY;
	BYTE btPartyOpt;
};

struct STR_REWD_008 {
	DWORD iMonsterSN;
	DWORD iHowMany;
	union {
		BYTE btWho;
		int iWho;
	};
	DWORD iZoneSN;
	DWORD iX;
	DWORD iY;
	DWORD iRange;
	DWORD iTeamNo;
};

struct STR_REWD_009 {
	WORD shNameLen;
	string szNextTriggerSN;
};

struct STR_REWD_010 {
};

struct STR_REWD_011 {
	union	{
		BYTE btWho;
		WORD usWho;
	};
	WORD nVarNo;
	int iValue;
	BYTE btOp;
};

struct STR_REWD_012 {
	union {
		BYTE btMsgType;
		int iMsgType;
	};
	DWORD iStrID;
};

struct STR_REWD_013 {
	union {
		BYTE btWho;
		int iWho;
	};
	DWORD iSec;
	WORD nNameLength;
	string szTriggerName;
	DWORD m_HashNextTrigger;
};

struct STR_REWD_014 {
	union {
		BYTE btOp;
		int iOp;
	};
	DWORD iSkillNo;
};

struct STR_REWD_015 {
	WORD nSN;
	BYTE btOp;
};

struct STR_REWD_016 {
	WORD nGroupSN;
};

struct STR_REWD_017 {
};

struct STR_REWD_018 {
	DWORD iStrID;
	WORD nCnt;
	string Data;
};

struct STR_REWD_019 {
	WORD nZoneNo;
	WORD nTeamNo;
	WORD nTriggerLength;
	string TriggerName;
	//WORD m_HashTrigger;
};

struct STR_REWD_020 {
	BYTE btNoType;
};

struct STR_REWD_021 {
	DWORD iX;
	DWORD iY;
};

struct STR_REWD_022 {
	WORD nZonNo;
	BYTE btOp;
};

struct STR_REWD_023 {
};

struct STR_REWD_024 {
	int iMONEY;
	BYTE btOP;
};

struct STR_REWD_025 {
	//short nPOINT;
	int nPOINT;
	BYTE btOP;
};

struct STR_REWD_026 {
	WORD nSkillNo;
	BYTE btOP;
};

struct STR_REWD_027 {
	short nCONT;
	BYTE btOP;
};

struct STR_REWD_028 {
	DWORD iRange;
	WORD nZoneNo;
	DWORD iX;
	DWORD iY;
};

// use LUA function
//LMA: used now.
struct STR_REWD_029 {
    WORD unk1;
    WORD unk2;
    string LuaName;
};

// skill reset
struct STR_REWD_030 {
};

// unknown start
struct STR_REWD_031 {
};

struct STR_REWD_032 {
};

struct STR_REWD_033 {
};
// unknown end

// unspawn NPC
struct STR_REWD_034 {
    BYTE btOP;
};

