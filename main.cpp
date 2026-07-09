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
    
    Game game(Student("Player", "Dorm", 20, 0, 1, 0),
              {Friend("Eleanor", "Library", 10),
               Friend("Daniel", "Dining Hall", 10),
               Friend("Maya", "Gym", 10),
               Friend("Professor Mosunov", "Classroom", 10),
               Friend("Kayra", "Dorm", 10)},
              {"Dorm", "Library", "Dining Hall", "Gym", "Classroom", "Store"},
              {"Textbook", "Laptop", "Notebook", "Pen", "Calculator", "Charger", "Water Bottle", "Sandwich"});

    game.startGame();


int TimesChoice = 0;

while (true) {
    // Display dashboard / inventory / map
    game.displayDashboard();
    game.displayInventory();
    game.displayMap();

    // Ask player what they want to do and process choice
    game.showMainMenu();
    int choice = 0;
    cin >> choice;
    game.processChoice(choice);
    TimesChoice++;

    // Check win/loss condition
    if (game.checkWin()) {
        game.displayEnding();
        break;
    } else if (game.checkBurnout()) {
        game.displayEnding();
        break;
    } else if (game.checkLoss()) {
        game.displayEnding();
        break;
    }

    if (TimesChoice > 4) {
        game.endDay();
        break;
    }
}



return 0;
}