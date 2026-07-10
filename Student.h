#ifndef STUDENT_H
#define STUDENT_H

#include "Character.h"
#include "Item.h"
#include <vector>
#include <string>
//Child class of Character
class Student : public Character {
    private:
        int studyHours;
        int EnergyPoints;
        int FriendshipPoints;
        int CurrentDay;
        int TiredStudent; //use to measure EC and burnout 
        string currentLocation;
        vector<string> inventory; //Keep track of stuff bought from store
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
        void setInventory(string item);
        string getInventory(int index);

        void moveTo(string locationName);//change location (option 1)
        string getCurrentLocation();

        void addItem(Item item); //Add things to backpack
        void displayInventory();

        bool hasItem(string itemName); //chech backpack contents
        void removeItem(string itemName);

        int getTiredStudent(); //Track burnout
        void setTiredStudent(int amount);

        int getInventorySize(); //How many items?
};
#endif
