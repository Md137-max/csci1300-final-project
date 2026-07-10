#include "Friend.h"

Friend::Friend(string n, string Loc, int FL) : Character(n, Loc) {
    friendshipLevel = FL;
}

void Friend::setFriendshipLevel(int level) {
    friendshipLevel = level;
}

int Friend::getFriendshipLevel() { //show player's current friendship points
    return friendshipLevel;
}