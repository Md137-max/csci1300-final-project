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
        Friend friendList[5];
        string locations[6];
        string bundleItems[8];
    
    public:
        Game(Student player, Friend friendList[5], string locations[6], string bundleItems[8]);

        void startGame();
        void CreatePlayer();
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
        bool isBundleComplete();
        void displayEnding();
        void talkToFriend(string friendName);
        bool CheckIfCompleteBundle();

};//update 7/9

#endif