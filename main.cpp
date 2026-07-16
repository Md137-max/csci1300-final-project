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
    //Main flow/Outline:
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
        Friend friends[5] = { //Set friends and the locations they have 
            Friend ("Eleanor", "Library"),
            Friend("Daniel", "Dining Hall"),
            Friend("Maya", "Gym"),
            Friend("Professor Mosunov", "Classroom"),
            Friend("Kayra", "Dorm")
        };
        string locations[6] = {
              "Dorm", "Library", "Dining Hall", "Gym", "Classroom", "Store"};
        string bundleItems[8] =
              {"Textbook", "Laptop", "Notebook", "Pen", "Calculator", "Charger", "Water Bottle", "Sandwich"};

        Game game(Student("Player", "Dorm"), friends, locations, bundleItems);
   
        
game.startGame(); //introduction
game.CreatePlayer(); //customize name

game.introduceCharacters(); //Summary of characters
game.introduceItems(); //Summary of items
game.introduceLocations(); //Sumary of locations


int TimesChoice = 0; //Keep track of actions (only 5 per day)

while (true) {
    // Display dashboard 
    game.displayDashboard();
   
    //Display map
    game.displayMap(); //Use file I/O

    // Ask player what they want to do and process choice
    game.showMainMenu();

    TimesChoice++; //Keep track of actions


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