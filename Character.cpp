#include "Character.h"


Character::Character(string n, string loc) {
    name = n;
    location = loc;
}
    
    string Character::getLocation() {
            return location;
        }
    string Character::getName() {
            return name;
        }
    void Character::setName(string newName) {
            name = newName;
        }

    void Character::setLocation(string newLocation) {
            location = newLocation;
        }
        //updated 7/9