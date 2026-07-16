#include "Friend.h"

Friend::Friend(string n, string Loc) : Character(n, Loc) {
    
}

void Friend::setFriendshipLevel(int level) {
    friendshipLevel = level;
}

int Friend::getFriendshipLevel() { //show player's current friendship points
    return friendshipLevel;
}