/*
    Open Source Rose Online Team - http://www.dev-osrose.com
    note: the Server is develop with erose source server + eich source
*/
#ifndef __ROSE_DATATYPES__
#define __ROSE_DATATYPES__
#include "../common/sockets.h"
// List of clan members
struct CClanMembers
{
    //UINT id;
    DWORD id;
    char name[50];
    int clan_rank;
};

// An item (for figuring out what a user is wearing)
struct CItem {
	unsigned int owner;
	unsigned int itemnum;
	unsigned int itemtype;
	unsigned int refine;
	unsigned int durability;
	unsigned int lifespan;
};

// A single client character
struct CCharacter {
	char char_name[17];
	unsigned int level;
	unsigned int face;
	unsigned int hairStyle;
	int sex;
	unsigned int classid;
	unsigned int id;
	unsigned long int DeleteTime;
};

//LMA: people in the chatroom.
struct CPeople
{
    DWORD charid;
    WORD account_id;
    string charname;
    bool is_active;
};

//LMA: Chatroom structure.
struct CChatroom
{
    string chatroom_name;
	WORD chatroom_id;
	time_t creation_time;
	bool is_protected;
	string password;
	BYTE nb_max;
	vector<CPeople*> People_list;
};

// List of friends
struct CFriendList
{
    //int id;
    DWORD id;
    char name[17];
};

// List of clan
struct CClans
{
    int id;
    int logo;
    unsigned int siglogo;       //LMA: logos.
    int back;
    int grade;
    unsigned int cp;
    char name[17];
    char slogan[30];
    char news[260];
    unsigned int rankingpoints;          //LMA: ranking points.
    vector<CClanMembers*> ClanMembers;
};

// Channel list
struct CChanels
{
    unsigned int id;
    char* ip;
    unsigned int port;
    SOCKET sock;
};
#endif

