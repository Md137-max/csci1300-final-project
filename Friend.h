#ifndef FRIEND_H
#define FRIEND_H

#include <iostream>
#include <string>
#include "Character.h"

using namespace std;
// Child class or character
class Friend : public Character {
    private:
        int friendshipLevel;
    public:
        Friend(string name, string location);
        void setFriendshipLevel(int level);
        int getFriendshipLevel();
};

//updated 7/9
#endif