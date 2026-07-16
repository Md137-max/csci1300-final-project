#include "Game.h"
#include <fstream> //For using file I/O
#include <vector>

Game::Game(Student P, Friend fL[5], string Loc[6], string bI[8])
    : player(P), friendList{fL[0], fL[1], fL[2], fL[3], fL[4]} {
    for (int i = 0; i < 5; i++) { //Five other friends
        friendList[i] = fL[i];
    }
    for (int i = 0; i < 6; i++) { //Six available locations
        locations[i] = Loc[i];
    }
    for (int i = 0; i < 8; i++) { //Eight needed backpack bundle items
        bundleItems[i] = bI[i];
    }
}



void Game::CreatePlayer() { // customize your player name, several options are available
    cout << "Choose a name for your character: " << endl;
    cout << "1. Straight A Student" << endl;
    cout << "2. Social Butterfly" << endl;
    cout << "3. Sleepy Student" << endl;
    cout << "4. Caffeine Addict" << endl;
    cout << "5. Overachiever" << endl;
    cout << "Enter the number corresponding to your choice: ";
    int playerName;
    cin >> playerName;
    switch (playerName) {
        case 1:
            player.setName("Straight A Student");
            break;
        case 2:
            player.setName("Social Butterfly");
            break;
        case 3:
            player.setName("Sleepy Student");
            break;
        case 4:
            player.setName("Caffeine Addict");
            break;
        case 5:
            player.setName("Overachiever");
            break;
        default:
            cout << "Invalid choice. Defaulting to 'Straight A Student'." << endl;
            player.setName("Straight A Student");
    }
cout << "Hello, " << player.getName() << "! You start with " << player.getEnergy() << " energy points and " << player.getFriendship() << " friendship points." << endl;
cout << "Let's begin your journey to survive midterms!" << endl;
}



void Game::startGame() { //Provides introduction
   cout << "Welcome to midterm season!" << endl;
   cout << "You are a student trying to survive midterms while maintaining your energy and friendship points." << endl;
   cout << "You must manage your time wisely, study, and interact with friends over the course of the week to succeed." << endl;
   cout << "You start with " << player.getEnergy() << " energy points and "<< player.getFriendship() << " friendship points." << endl;
   cout << "your goal is to reach at least 15 friendship points and 20 study hours by the end of day 7." << endl;
   cout << "If your energy points drop to 0, or if you reach day 8, you will fail." << endl;
   cout << "If you become too tired from doing extra credit work, you will also fail." << endl;
   cout << "Good luck!" << endl;
   
}



void Game::introduceCharacters() { //Give character context
    cout << "Meet the other characters in the game:" << endl;
    cout << "1. Eleanor - A studious friend who loves to read in the library." << endl;
    cout << "2. Daniel - A friendly and outgoing friend who enjoys socializing in the dining hall." << endl;
    cout << "3. Maya - A fitness enthusiast who is always at the gym." << endl;
    cout << "4. Professor Mosunov - A strict but fair professor that holds study hall sessions in the classroom." << endl;
    cout << "5. Kayra - A laid-back roommate who enjoys relaxing in the dorm." << endl;
}



void Game::introduceItems() { //Give item context
    cout << "Here are the items you need to collect in the game:" << endl;
    cout << "1. Textbook - Helps you study and increase your study hours." << endl;
    cout << "2. Laptop - Essential for completing assignments and studying." << endl;
    cout << "3. Notebook - Useful for taking notes during study sessions." << endl;
    cout << "4. Pen - A basic tool for writing and note-taking." << endl;
    cout << "5. Calculator - Helps with solving mathematical problems." << endl;
    cout << "6. Charger - Keeps your devices powered up and levels up your friendship points." << endl;
    cout << "7. Water Bottle - Keeps you hydrated and energized." << endl;
    cout << "8. Sandwich - Provides a quick energy boost when you're hungry." << endl;

    cout << "Collect all 8 items to complete your backpack and increase your chances of surviving midterms!" << endl;
    cout << "You can find these items in various locations throughout the game, such as the store, library, and dining hall." << endl;
}


void Game::introduceLocations() { //Give the player game context
    cout << "Here are the places you can go in the game:" << endl;
    cout << "1. Library - go here to gain study hours. It will cost you energy." << endl;
    cout << "2. Dorm - go here to rest and gain enery." << endl;
    cout << "3. Dining Hall - go here to eat/drink and gain energy." << endl;
    cout << "4. Classroom - go here to gain study hours." << endl;
    cout << "5. Store - go here to buy items and complete your backpack bundle." << endl;
}



void Game::displayDashboard() { // Display current stats
    cout << "----- Game Status -----" << endl;
    cout << "Day: " << player.getCurrentDay() << " / 7" << endl;
    cout << "Energy Points: " << player.getEnergy() << endl;
    cout << "Friendship Points: " << player.getFriendship() << " / 15" << endl;
    cout << "Study Hours: " << player.getStudyHours() << " / 20" << endl;
    cout << "Current Location: " << player.getCurrentLocation() << endl;
    cout << "Burnout Level: " << player.getTiredStudent() << " / 3" << endl;
    cout << "Inventory: ";
    
    int progress = 0;
    for (int i = 0; i < player.getInventorySize(); i++) {
    string item = player.getInventory(i);
    cout << item << ", ";
        if (item != "") progress++;
    }
    cout << endl;
    cout << "Backpack progress: " << progress << " / 8" << endl;
    cout << endl;
}



#include <fstream> //use file I/O here

void Game::displayMap() { //Displaying a map with a starred current location
    ifstream inFile("Map.txt");

    if (!inFile.is_open()) { //check if file is open
        cout << "Could not open Map.txt" << endl;
        return;
    }

    struct Location {
        string name;
        string description;
    };

    vector<Location> mapLocations; //Make a new vector for mapLocations
    Location temp;

    while (getline(inFile, temp.name) &&
           getline(inFile, temp.description)) {
        mapLocations.push_back(temp);
    }

    inFile.close();

    cout << "--- CORNELL UNIVERSITY MAP ---" << endl;

    for (size_t i = 0; i < mapLocations.size(); i++) {
        if (mapLocations[i].name == player.getCurrentLocation()) {
            cout << "[*] ";
        } else {
            cout << "[ ] ";
        }

        cout << mapLocations[i].name
             << " - "
             << mapLocations[i].description
             << endl;
    }

    cout << "* = You are here" << endl;
}



void Game::showMainMenu() { //Main options for user, pops up after every completed task
    int choice;

    cout << "What would you like to do (pick a number 1-5)?" << endl;
    cout << "1. Move to a new location" << endl;
    cout << "2. Talk to a character" << endl;
    cout << "3. View your inventory" << endl;
    cout << "4. View your backpack progress" << endl;
    cout << "5. End the day" << endl;
    cout << "6. Sell a backpack item" << endl;

   
    if(!(cin >> choice)) { //Validate input from main menu options
        cin.clear();
        cin.ignore(100000, '\n');
        cout << "Invald answer - try again!" << endl;
        return;
    }

    processChoice(choice);
}



void Game::displayInventory() {
    player.displayInventory();
}



void Game::processChoice(int choice) { //Process player choices from main menu, leading to a branch of following functions
    if (choice == 1) {
        movePlayer();
    } else if (choice == 2) {
        talkToCharacter();
    } else if (choice == 3) {
        player.displayInventory();
    } else if (choice == 4) {
        cout << "Checking backpack..." << endl;
        int progress = 0;
        for (int i = 0; i < 8; i++) {
            string item = player.getInventory(i);
            if (item != "") progress++;
        }
        cout << "Backpack progress: " << progress << " / 8" << endl;
    } else if (choice == 5) {
        cout << "We are ending the day! See you tomorrow" << endl;
        endDay(); }
    else if (choice == 6) {
        cout << "You chose to sell an item" << endl;
        SellingItems();
    }
    
     else {
        cout << "Invalid choice. Please try again." << endl;
    }
}




void Game::movePlayer() { //Move location, this is also displayed on the map
    string newLocation;
    cout << "Where would you like to move? (Dorm, Library, Dining Hall, Gym, Classroom, Store). Please type only one option exactly as shown." << endl;
    cin.ignore(10000, '\n');
    getline(cin, newLocation);
    player.moveTo(newLocation);
    cout << "You moved to " << newLocation << "." << endl;
    locationMenu(newLocation);
}



void Game::locationMenu(string newLocation) { //Choices at different locations, use integer matching. Display a menu for each chosen option.


    int choice;

    if (newLocation == "Dorm") {
        cout << "You are in the Dorm. You can rest here to regain energy (+8 energy)." << endl;
        player.setEnergy(player.getEnergy() + 8);
        cout << "Your roommate Kayra is here. Would you like to talk to her and increase your friendship points (-1 Energy point)?" << endl;
    
        cout << "What would you like to do?" << endl;
        cout << "1. Rest (+8 energy)" << endl;
        cout << "2. Talk to Kayra" << endl;
        cout << "3. Leave" << endl;

        cin >> choice;

        if (choice == 1) {
            player.setEnergy(player.getEnergy() + 8);
        }
        else if (choice == 2) {
            talkToFriend("Kayra");
            cout << "You talked to Kayra and increased your friendship points!" << endl;
        }
    }

           

    else if (newLocation == "Library") {
        cout << "You are in the Library. You can study here to increase your study hours." << endl;
        cout << "Your friend Eleanor is here. You can study with her to increase your friendship points." << endl;
        cout << "What would you like to do?" << endl;
        cout << "1. Study (+4 study hours, -6 energy)" << endl;
        cout << "2. Talk to Eleanor (+2 friendship, -energy)" << endl;
        cout << "3. Leave" << endl;

        int choice;
        cin >> choice;

        if (choice == 1) {
            player.setStudyHours(player.getStudyHours() + 4);
            player.setEnergy(player.getEnergy() - 6);
            cout << "You studied in the library." << endl;
            
        }
        else if (choice == 2) {
            talkToFriend("Eleanor");
            player.setEnergy(player.getEnergy() - 1);
            cout << "You talked to Eleanor." << endl;
        }
        else if (choice == 3) {
            cout << "Leaving the library." << endl;
        }
    }


    else if (newLocation == "Dining Hall") {
        cout << "You are in the Dining Hall. You can eat here to regain energy." << endl;
        cout << "Your friend Daniel is here. You can eat with him to increase your friendship points." << endl;
        cout << "What would you like to do?" << endl;
        cout << "1. Talk to Daniel and increase your friendship points (-2 energy, +2 friendship)" << endl;
        cout << "2. Eat a meal (+8 energy points)" << endl;
        cout << "3. Leave" << endl;

        cin >> choice;

        if (choice == 1) {
            player.setFriendship(player.getFriendship() + 2);
            player.setEnergy(player.getEnergy() - 2);
            cout << "You talked about your exams with Daniel" << endl;
        }
        else if (choice == 2) {
            player.setEnergy(player.getEnergy() + 8);
            cout << "You ate a yummy meal and feel refreshed." << endl;
        }
        else if (choice == 3) {
            cout << "Leaving the Dining Hall." << endl;
        }
    }

    else if (newLocation == "Gym") {
        cout << "You are in the Gym. You can exercise here with your friend Maya to increase your friendship points." << endl;
        cout << "Talk to Maya (-2 energy, +3 friendship)?" << endl;
        cout << "1. Yes" << endl;
        cout << "2. No" << endl;
        int choice;
        cin >> choice;
        if (choice == 1) {
            cout << "Hello, Maya! Let's exercise together! " << endl;
            talkToFriend("Maya");
            player.setEnergy(player.getEnergy() - 2);
            player.setFriendship(player.getFriendship() + 3);
        }
        else if (choice == 2) {
            cout << "Enjoy some alone time" << endl;
        }
        }

          

     else if (newLocation == "Classroom") {
        cout << "You are in the Classroom. You attend study hall here to increase your study hours (-1 energy, +2 study hours)." << endl;
        player.setStudyHours(player.getStudyHours() + 2);
        player.setEnergy(player.getEnergy() - 1);
        cout << "You attended study hall and increased your study hours!" << endl;

        cout << "Your professor, Prof. Mosunov, is here. You can talk to him to get an extra credit opportunity." << endl;
         if(1 <= player.getCurrentDay() && player.getCurrentDay() <= 7) {
        cout << "Hello, Would you like to do extra credit work (Costs 4 energy points, increases study hours by 4)?" << endl;
        cout << "1. Yes please!" << endl;
        cout << "2. No, thank you Prof. Mosunov" << endl;
        int choice;
        cin >> choice;
        if(choice == 1) {
            if (player.getEnergy() >= 5) {
                player.setEnergy(player.getEnergy() - 4);
                player.setStudyHours(player.getStudyHours() + 4);
                player.setTiredStudent(player.getTiredStudent() + 1);
                cout << "You did extra credit work! Your study hours increased by 2, but you lost 5 energy points." << endl;
                cout << "Your burnout level increased +1" << endl;
            } else {

                cout << "You don't have enough energy to do extra credit work." << endl;
            }
        } else {
            cout << "You chose not to do extra credit work. Get back to studying!" << endl;
        }
    }

    } else if (newLocation == "Store") {
        cout << "You are in the Store. You can buy items here to add to your inventory." << endl;
        cout << "Please respond with a number (1-9). Available items: " << endl;
        cout << "1. Textbook (5 energy points)" << endl;
        cout << "2. Laptop (10 energy points)" << endl;
        cout << "3. Notebook (5 energy points)" << endl;
        cout << "4. Pen (2 energy points)" << endl;
        cout << "5. Calculator (8 energy points)" << endl;
        cout << "6. Charger (3 energy points)" << endl;
        cout << "7. Water Bottle (4 energy points)" << endl;
        cout << "8. Sandwich (3 energy points)" << endl;
        cout << "9. I don't want to buy anything, exit Store." << endl;
        int itemChoice;
        cin >> itemChoice;
        ProcessStoreChoice(itemChoice);
    } else {
        cout << "Invalid location. Try again next time." << endl;
        cout << "Returning to main menu" << endl;
    }
}





void Game::ProcessStoreChoice(int choice) { //Processing the choices made at the store (adding to inventory)
    if (choice == 1) {
        cout << "You chose to buy a Textbook." << endl;
        if (player.getEnergy() < 5) { //Checking if they have enough energy to buy items
            cout << "You don't have enough energy points to buy a Textbook." << endl;
            return;
        }
        else {
            player.addItem(Item("Textbook", "bundle")); //Add item to bundle after purchase
            cout << "You spent 5 energy points." << endl;
        player.setEnergy(player.getEnergy() - 5);
        }
        

    } 
    else if (choice == 2) {
        cout << "You chose to buy a Laptop." << endl;
        if (player.getEnergy() < 10) {
            cout << "You don't have enough energy points to buy a Laptop." << endl;
            return;
        }
        else {
            player.addItem(Item("Laptop", "bundle"));
            cout << "You spent 10 energy points." << endl;
        player.setEnergy(player.getEnergy() - 10);
        }
        
    }
    else if (choice == 3) {
        cout << "You chose to buy a Notebook." << endl;
        if (player.getEnergy() < 5) {
            cout << "You don't have enough energy points to buy a Notebook." << endl;
            return;
        }
        else {
            player.addItem(Item("Notebook", "bundle"));
            cout << "You spent 5 energy points." << endl;
            player.setEnergy(player.getEnergy() - 5);
        }
    }
    else if (choice == 4) { 
        cout << "You chose to buy a Pen." << endl;
        if (player.getEnergy() < 2) {
            cout << "You don't have enough energy points to buy a Pen." << endl;
            return;
        }
        else {
            player.addItem(Item("Pen", "bundle"));
            cout << "You spent 2 energy points." << endl;
            player.setEnergy(player.getEnergy() - 2);
        }
        
    }
    else if (choice == 5) {
        cout << "You chose to buy a Calculator." << endl;
        if (player.getEnergy() < 8) {
            cout << "You don't have enough energy points to buy a Calculator." << endl;
            return;
        }
        else {
            player.addItem(Item("Calculator", "bundle"));
            cout << "You spent 8 energy points." << endl;
            player.setEnergy(player.getEnergy() - 8);
        }
    }
    else if (choice == 6) {
        cout << "You chose to buy a Charger." << endl;
        if (player.getEnergy() < 3) {
            cout << "You don't have enough energy points to buy a Charger." << endl;
            return;
        }
        else {
            player.addItem(Item("Charger", "bundle"));
            cout << "You spent 3 energy points." << endl;
            player.setEnergy(player.getEnergy() - 3);
        }
    }
    else if (choice == 7) { 
        cout << "You chose to buy a Water Bottle." << endl;
        if (player.getEnergy() < 4) {
            cout << "You don't have enough energy points to buy a Water Bottle." << endl;
            return;
        }
        else {
            player.addItem(Item("Water Bottle", "bundle"));
            cout << "You spent 4 energy points." << endl;
            player.setEnergy(player.getEnergy() - 4);
        }
    }
    else if (choice == 8) {
        cout << "You chose to buy a Sandwich." << endl;
        if (player.getEnergy() < 3) {
            cout << "You don't have enough energy points to buy a Sandwich." << endl;
            return;
        }
        else {
            player.addItem(Item("Sandwich", "bundle"));
            cout << "You spent 3 energy points." << endl;
            player.setEnergy(player.getEnergy() - 3);
        }
    }
    else if (choice == 9) {
        cout << "You chose not to buy anything." << endl;

    } else {
        cout << "Invalid item choice. Please choose a valid item." << endl;
    }
}




void Game::SellingItems() { //Can sell itmes once they are in your inventory, a good way to get study hours 
    cout << "What item would you like to sell? (+4 study hours)" << endl;
    cout << "If you've decided not to sell anything, enter: NO " << endl;
    cout << "Available items to sell (enter exactly as shown): " << endl;
    player.displayInventory();
    string SellItem;
    cin.ignore(100000, '\n');
    getline (cin, SellItem);

    if (SellItem == "Textbook" || SellItem == "Laptop" || SellItem == "Pen" || SellItem == "Charger" || SellItem == "Sandwich" || SellItem == "Calculator" || SellItem == "Water Bottle" || SellItem == "Notebook") {
        if(player.hasItem(SellItem)) {
        cout << "You have sold: " << SellItem << " for 4 study hours" << endl;
        player.setStudyHours(player.getStudyHours() + 4);
        player.removeItem(SellItem);
        }
        else {
            cout << "You don't have that item" << endl;
        }
    }
    else if (SellItem == "NO") {
        cout << "You have not sold anything" << endl;
        return;
    }
    else {
        cout << "That is not a valid item" << endl;
    }
    }





void Game::talkToFriend(string friendName) { //Talk to other characters for friendship points
    for (int i = 0; i < 5; i++) {
        if (friendList[i].getName() == friendName) {
            cout << "Talking to " << friendList[i].getName() << "..." << endl;
            player.setFriendship(player.getFriendship() + 2);
            return;
        }
    }
    cout << "Friend not found." << endl;
}





void Game::talkToCharacter() { //Talk to other characters if they are in the same location as the player
    if (player.getCurrentLocation() == "Library") {
        cout << "Let's talk to Eleanor! You gain 2 friendship points, but it costs you one energy point." << endl;
        cout << "Eleanor loves to spend time reading in the library and drinking coffee" << endl;
        talkToFriend("Eleanor");
    } else if (player.getCurrentLocation() == "Dining Hall") {
        cout <<  "Let's talk to Daniel! You gain 2 friendship points, but it costs you one energy point." << endl;
        talkToFriend("Daniel");
    } else if (player.getCurrentLocation() == "Gym") {
        cout <<  "Let's talk to Maya! You gain 2 friendship points, but it costs you one energy point." << endl;
        talkToFriend("Maya");
    } else if (player.getCurrentLocation() == "Classroom") {
         cout <<  "Let's talk to Prof. Mosunov! You gain 2 friendship points, but it costs you one energy point." << endl;
        talkToFriend("Professor Mosunov");
    } else if (player.getCurrentLocation() == "Dorm") {
         cout <<  "Let's talk to Kayra! You gain 2 friendship points, but it costs you one energy point." << endl;
        talkToFriend("Kayra");
    } else {
        cout << "There is no one to talk to here." << endl;
    }
}




void Game::endDay() { //Start a new day, time control 
    int currentDay = player.getCurrentDay();
    cout << "Ending the day..." << endl;
     player.setCurrentDay(currentDay + 1);
     cout << "Day " << player.getCurrentDay() << " begins!" << endl;
}




bool Game::checkWin() { //Did you meet the winning conditions?
    if (player.getFriendship() >= 15 && player.getStudyHours() >= 20 && CheckIfCompleteBundle() && player.getEnergy() > 0) {
        return true;
    }
    return false;
}



bool Game::checkBurnout() { //Did you exceed EC points?
    if (player.getTiredStudent() > 3) {
        return true;
    }
    return false;
}



bool Game::isBundleComplete() { //Did you collect all itmes?
    if (player.getInventorySize() < 8) {
        return false;
    }

    if( player.hasItem("Laptop") &&
           player.hasItem("Notebook") &&
           player.hasItem("Pen") &&
           player.hasItem("Charger") &&
           player.hasItem("Water Bottle") &&
           player.hasItem("Sandwich") &&
           player.hasItem("Textbook") &&
           player.hasItem("Calculator")
) {
    return true;
}
return false;
}




bool Game::checkLoss() { //Check win/loss conditions
    if (player.getEnergy() < 0 || player.getCurrentDay() > 7 || player.getTiredStudent() > 3) {
        return true;
    }
    return false;
}




bool Game::CheckIfCompleteBundle(){ //Is your backpack bundle complete?
    if (isBundleComplete()) {
        return true;
    }
    return false;
}



void Game::displayEnding() { //Show outcomes
    if (checkWin()) {
        cout << "Game Over! Congratulations, you have survived midterms!" << endl;
    }  else if (checkBurnout()) {
        cout << "Game Over! You have burned out. You may not use the extra credit option more than 3 times. Better luck next time!" << endl;
    }
     else if (!CheckIfCompleteBundle()) {
        cout << "Game Over! Backpack items missing, you have failed midterms! Better luck next time" << endl;
    }
    else if (checkLoss()) {
        cout << "Game Over! You have lost the game. You must complete you tasks in less than 8 days without going below 0 energy. Better luck next time." << endl;
    }

     else {
        cout << "The game is still ongoing." << endl;
    }
}