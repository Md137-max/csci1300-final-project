#include "Student.h"

Student::Student(string n, string loc) 
: Character(n, loc) {
    EnergyPoints = 20;
    FriendshipPoints = 0;
    CurrentDay = 1;
    studyHours = 0;
    TiredStudent = 0;
}

void Student::setEnergy(int amount) {
    EnergyPoints = amount;
}

int Student::getEnergy() {
    return EnergyPoints;
}

void Student::setFriendship(int amount) {
    FriendshipPoints = amount;
}

int Student::getFriendship() {
    return FriendshipPoints;
}

void Student::setCurrentDay(int day) {
    CurrentDay = day;
}
int Student::getCurrentDay() {
    return CurrentDay;
}
void Student::setStudyHours(int hours) {
    studyHours = hours;
}
int Student::getStudyHours() {
    return studyHours;
}
void Student::setInventory(string item, int index) {
    inventory[index] = item;
}
string Student::getInventory(int index) {
    return inventory[index];
}

void Student::moveTo(string locationName) {
    setLocation(locationName);
}
string Student::getCurrentLocation() {
    return getLocation();
}

void Student::addItem(Item item) {
    inventory.push_back(item.getName());
}
void Student::displayInventory() {
    cout << "Inventory: " << endl;
    for (int i = 0; i < inventory.size(); i++) {
        if (inventory[i] != "") {
            cout << "- " << inventory[i] << endl;
        }
    }
    
}

bool Student::hasItem(string itemName) {
    for (int i = 0; i < inventory.size(); i++) {
        if (inventory[i] == itemName) {
            return true;
        }
    }
    return false;
}
void Student::removeItem(string itemName) {
    for (int i = 0; i < inventory.size(); i++) {
        if (inventory[i] == itemName) {
            inventory[i] = "";
            break;
        }
    }
}

 int Student::getTiredStudent() {
    return TiredStudent;
}
void Student::setTiredStudent(int amount) {
    TiredStudent = amount;
}