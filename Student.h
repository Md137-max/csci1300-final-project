#ifndef STUDENT_H
#define STUDENT_H

#include "Character.h"
#include "Item.h"
#include <vector>
#include <string>

class Student : public Character {
    private:
        int studyHours;
        int EnergyPoints;
        int FriendshipPoints;
        int CurrentDay;
        int TiredStudent;
        string currentLocation;
        vector<string> inventory;
    public:

        Student(string name, string location);
        void setEnergy(int amount);
        int getEnergy();
        void setFriendship(int amount);
        int getFriendship();
        void setCurrentDay(int day);
        int getCurrentDay();
        void setStudyHours(int hours);
        int getStudyHours();
        void setInventory(string item, int index);
        string getInventory(int index);

        void moveTo(string locationName);
        string getCurrentLocation();

        void addItem(Item item);
        void displayInventory();

        bool hasItem(string itemName);
        void removeItem(string itemName);

        int getTiredStudent();
        void setTiredStudent(int amount);
};
#endif
