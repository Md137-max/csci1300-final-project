#include <iostream>
#include <string>
#include <vector>

#include "Character.h"
#include "Friend.h"
#include "Item.h"
#include "Student.h"
#include "Game.h"

using namespace std;

int main() {
    // Start game
    // Create player
    // Create items, characters, locations, and bundle
    // Repeat until win or loss:
    //     Display dashboard
    //     Ask player what they want to do
    // Process player choice
    // Update player stats
    // Update inventory or bundle progress
    // Check win/loss condition
    // Display final ending
    
//Start game

         
        Friend friends[5] = {
            Friend ("Eleanor", "Library", 10),
            Friend("Daniel", "Dining Hall", 10),
            Friend("Maya", "Gym", 10),
            Friend("Professor Mosunov", "Classroom", 10),
            Friend("Kayra", "Dorm", 10)
        };
        string locations[6] = {
              "Dorm", "Library", "Dining Hall", "Gym", "Classroom", "Store"};
        string bundleItems[8] =
              {"Textbook", "Laptop", "Notebook", "Pen", "Calculator", "Charger", "Water Bottle", "Sandwich"};

        Game game(Student("Player", "Dorm"), friends, locations, bundleItems);
    
game.startGame();
game.CreatePlayer();
game.introduceCharacters();
game.introduceItems();
game.introduceLocations();


int TimesChoice = 0;

while (true) {
    // Display dashboard / inventory / map
    game.displayDashboard();
    game.displayInventory();
    game.displayMap(); //Will add later

    
    // Ask player what they want to do and process choice
    game.showMainMenu();

    TimesChoice++;


    // Check win/loss condition
    if (game.checkWin()) {
        game.displayEnding();
        break;
    }
     if (game.checkBurnout()) {
        game.displayEnding();
        break;
    } 
    
    if (game.checkLoss()) {
        game.displayEnding();
        break;
    }

    //Manage time based on activities
    if (TimesChoice >= 5) {
        game.endDay();
        TimesChoice = 0;
        
    }
}

return 0;
}