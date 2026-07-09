#ifndef FRIEND_H
#define FRIEND_H

#include <iostream>
#include <string>
#include "Character.h"

using namespace std;

class Friend : public Character {
    private:
        int friendshipLevel;
    public:
        Friend(string name, string location, int friendshipLevel);
        void setFriendshipLevel(int level);
        int getFriendshipLevel();
};


#endif