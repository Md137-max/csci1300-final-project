#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>
#include "Character.h"
#include "Friend.h"
#include "Item.h"
#include "Student.h"

using namespace std;

class Game {
    private:
        Student player;
        Friend friendList[5] = {
            Friend("Eleanor", "Library", 10),
            Friend("Daniel", "Dining Hall", 10),
            Friend("Maya", "Gym", 10),
            Friend("Professor Mosunov", "Classroom", 10),
            Friend("Kayra", "Dorm", 10)
        };
        
        string locations[6] = {"Dorm", "Library", "Dining Hall", "Gym", "Classroom", "Store"};
        string bundleItems[8] = {"Textbook", "Laptop", "Notebook", "Pen", "Calculator", "Charger", "Water Bottle", "Sandwich"};
    
    public:
        Game(Student player, Friend friendList[5], string locations[6], string bundleItems[8]);

        void startGame();
        void CreatePlayer(Student P);
        void introduceCharacters();
        void introduceItems();
        void introduceLocations();
        void displayDashboard();
        void displayMap();
        void showMainMenu();
        void processChoice(int choice);
        void locationMenu(string location);
        void movePlayer();
        void ProcessStoreChoice(int choice);
        void displayInventory();
        void talkToCharacter();
        void endDay();
        bool checkWin();
        bool checkBurnout();
        bool checkLoss();
        void displayEnding();
        void talkToFriend(string friendName);

};

#endif