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
#ifndef __ROSE_PARY__
#define __ROSE_PARY__
#include "worldserver.h"
#include "datatypes.h"

class CParty
{
    public:
        CParty( );
        ~CParty( );

        unsigned int PartyId;
        void RefreshMax();
        CPlayer* GetMember( unsigned int id );
        CPlayer* GetMemberByCharID( DWORD charid );
        void SendToMembers( CPacket* pak, CPlayer* exclient=NULL );
        void SendToVisible( CPacket* pak, CPlayer* thisclient );
        bool AddPlayer( CPlayer* player );
        bool RemovePlayer( CPlayer* player );

        unsigned int PartyLevel;
        //unsigned int Exp;
        unsigned long long Exp;
        unsigned int Option;
        unsigned int LastItem;
        unsigned int LastETC;
        unsigned int LastZulies;
        unsigned int Capacity;
        vector<CPlayer*> Members;
        //CPartyExp* PartyExp;
};

#endif
