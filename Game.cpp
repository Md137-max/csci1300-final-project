#include "Game.h"

Game::Game(Student P, Friend fL[5], string Loc[6], string bI[8])
    : player(P), friendList{fL[0], fL[1], fL[2], fL[3], fL[4]} {
    for (int i = 0; i < 5; i++) {
        friendList[i] = fL[i];
    }
    for (int i = 0; i < 6; i++) {
        locations[i] = Loc[i];
    }
    for (int i = 0; i < 8; i++) {
        bundleItems[i] = bI[i];
    }
}

void Game::CreatePlayer(Student P) {
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
            P.setName("Straight A Student");
            break;
        case 2:
            P.setName("Social Butterfly");
            break;
        case 3:
            P.setName("Sleepy Student");
            break;
        case 4:
            P.setName("Caffeine Addict");
            break;
        case 5:
            P.setName("Overachiever");
            break;
        default:
            cout << "Invalid choice. Defaulting to 'Straight A Student'." << endl;
            P.setName("Straight A Student");
    }
cout << "Hello, " << P.getName() << "! You start with " << P.getEnergy() << " energy points and " << P.getFriendship() << " friendship points." << endl;
cout << "Let's begin your journey to survive midterms!" << endl;
}



void Game::startGame() {
   cout << "Welcome to midterm season!" << endl;
   cout << "You are a student trying to survive midterms while maintaining your energy and friendship points." << endl;
   cout << "You must manage your time wisely, study, and interact with friends over the course of the week to succeed." << endl;
   cout << "You start with " << player.getEnergy() << " energy points and "<< player.getFriendship() << " friendship points." << endl;
   cout << "your goal is to reach at least 15 friendship points and 20 study hours by the end of day 7." << endl;
   cout << "If your energy points drop to 0, or if you reach day 8, you will fail." << endl;
   cout << "If you become too tired from doing extra credit work or drinking too much caffeine, you will also fail." << endl;
   cout << "Good luck!" << endl;
}



void Game::introduceCharacters() {
    cout << "Meet the other characters in the game:" << endl;
    cout << "1. Eleanor - A studious friend who loves to read in the library." << endl;
    cout << "2. Daniel - A friendly and outgoing friend who enjoys socializing in the dining hall." << endl;
    cout << "3. Maya - A fitness enthusiast who is always at the gym." << endl;
    cout << "4. Professor Mosunov - A strict but fair professor that holds study hall sessions in the classroom." << endl;
    cout << "5. Kayra - A laid-back roommate who enjoys relaxing in the dorm." << endl;
}

void Game::introduceItems() {
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

void Game::introduceLocations() {
    cout << "Here are the places you can go in the game:" << endl;
    cout << "1. Library - go here to gain study hours. It will cost you energy." << endl;
    cout << "2. Dorm - go here to rest and gain enery." << endl;
    cout << "3. Dining Hall - go here to eat/drink and gain energy." << endl;
    cout << "4. Classroom - go here to gain study hours." << endl;
    cout << "5. Store - go here to buy items and complete your backpack bundle." << endl;
}
void Game::displayDashboard() {
    cout << "Day: " << player.getCurrentDay() << " / 7" << endl;
    cout << "Energy Points: " << player.getEnergy() << endl;
    cout << "Friendship Points: " << player.getFriendship() << " / 15" << endl;
    cout << "Study Hours: " << player.getStudyHours() << " / 20" << endl;
    cout << "Current Location: " << player.getCurrentLocation() << endl;
    cout << "Burnout Level: " << player.getTiredStudent() << " / 3" << endl;
    cout << "Inventory: ";
    
    int progress = 0;
    for (int i = 0; i < 8; i++) {
        string item = player.getInventory(i);
        cout << item;
        if (i < 7) cout << ", ";
        if (item != "") progress++;
    }
    cout << endl;
    cout << "Backpack progress: " << progress << " / 8" << endl;
    cout << endl;
}




void Game::displayMap() {


}



void Game::showMainMenu() {
     int dispalyOption;
    cout << "What would you like to do?" << endl;
    cout << "1. Move to a new location" << endl;
    cout << "2. Talk to a character" << endl;
    cout << "3. View your inventory" << endl;
    cout << "4. View your backpack progress" << endl;
    cout << "5. End the day" << endl;

   
    cin >> dispalyOption;
    processChoice(dispalyOption);
}



void Game::processChoice(int choice) {
    if (choice == 1) {
        movePlayer();
    } else if (choice == 2) {
        talkToCharacter();
    } else if (choice == 3) {
        player.displayInventory();
    } else if (choice == 4) {
        int progress = 0;
        for (int i = 0; i < 8; i++) {
            string item = player.getInventory(i);
            if (item != "") progress++;
        }
        cout << "Backpack progress: " << progress << " / 8" << endl;
    } else if (choice == 5) {
        endDay(); }
    
     else {
        cout << "Invalid choice. Please try again." << endl;
    }
}




void Game::movePlayer() {
    string newLocation;
    cout << "Where would you like to move? (Dorm, Library, Dining Hall, Gym, Classroom, Store)" << endl;
    cin >> newLocation;
    player.moveTo(newLocation);
    cout << "You moved to " << newLocation << "." << endl;
}




void Game::locationMenu(string location) {

    if (location == "Dorm") {
        cout << "You are in the Dorm. You can rest here to regain energy." << endl;
        player.setEnergy(player.getEnergy() + 5);
        cout << "Your roommate Kayra is here. Would you like to talk to her and increase your friendship points (-1 Energy point)?" << endl;
        cout << "1. Yes" << endl;
        cout << "2. No" << endl;
        int choice;
        cin >> choice;
        if (choice == 1) {
            talkToFriend("Kayra");
            player.setEnergy(player.getEnergy() - 1);
            cout << "You talked to Kayra and increased your friendship points!" << endl;
        }


    } else if (location == "Library") {
        cout << "You are in the Library. You can study here to increase your study hours." << endl;
        cout << "Your friend Eleanor is here. You can study with her to increase your friendship points." << endl;
        player.setStudyHours(player.getStudyHours() + 2);
        player.setEnergy(player.getEnergy() - 2);
        cout << "Would you like to talk to Eleanor and increase your friendship points (-1 Energy point)?" << endl;
        cout << "1. Yes" << endl;
        cout << "2. No" << endl;
        int choice;
        cin >> choice;
        if (choice == 1) {
            talkToFriend("Eleanor");
            cout << "You studied with Eleanor and increased your friendship points!" << endl;
            player.setEnergy(player.getEnergy() - 1);
        }
        player.setFriendship(player.getFriendship() + 1);


    } else if (location == "Dining Hall") {
        cout << "You are in the Dining Hall. You can eat here to regain energy." << endl;
        cout << "Your friend Daniel is here. You can eat with him to increase your friendship points." << endl;
        cout << "Would you like to talk to Daniel and increase your friendship points (-1 Energy point)?" << endl;
        cout << "1. Yes" << endl;
        cout << "2. No" << endl;
        int choice;
        cin >> choice;
        if (choice == 1) {
            talkToFriend("Daniel");
            cout << "You ate with Daniel and increased your friendship points!" << endl;
            player.setEnergy(player.getEnergy() - 1);
        }
        player.setEnergy(player.getEnergy() + 3);


    } else if (location == "Gym") {
        cout << "You are in the Gym. You can exercise here with your friend Maya to increase your friendship points." << endl;
        cout << "Talk to Maya (-2 Energy points)?" << endl;
        cout << "1. Yes" << endl;
        cout << "2. No" << endl;
        int choice;
        cin >> choice;
        if (choice == 1) {
            cout << "Hello, Maya! Let's exercise together! " << endl;
            talkToFriend("Maya");
            player.setEnergy(player.getEnergy() - 2);
        }

        player.setFriendship(player.getFriendship() + 3);
        


    } else if (location == "Classroom") {
        cout << "You are in the Classroom. You can attend study hall here to increase your study hours (-1 Energy point)." << endl;
        player.setStudyHours(player.getStudyHours() + 1);
        player.setEnergy(player.getEnergy() - 1);
        cout << "You attended study hall and increased your study hours!" << endl;

        cout << "Your professor, Prof. Mosunov, is here. You can talk to him to get an extra credit opportunity." << endl;
         if(1 <= player.getCurrentDay() && player.getCurrentDay() <= 7) {
        cout << "Hello, Would you like to do extra credit work (Costs 5 energy points, increases study hours by 2)?" << endl;
        cout << "1. Yes please!" << endl;
        cout << "2. No, thank you Prof. Mosunov" << endl;
        int choice;
        cin >> choice;
        if(choice == 1) {
            if (player.getEnergy() >= 5) {
                player.setEnergy(player.getEnergy() - 5);
                player.setStudyHours(player.getStudyHours() + 2);
                cout << "You did extra credit work! Your study hours increased by 2, but you lost 5 energy points." << endl;
            } else {
                cout << "You don't have enough energy to do extra credit work." << endl;
            }
        } else {
            cout << "You chose not to do extra credit work. Get back to studying!" << endl;
        }
    }

    } else if (location == "Store") {
        cout << "You are in the Store. You can buy items here to add to your inventory." << endl;
        cout << "Available items: " << endl;
        cout << "1. Textbook (10 energy points)" << endl;
        cout << "2. Laptop (15 energy points)" << endl;
        cout << "3. Notebook (5 energy points)" << endl;
        cout << "4. Pen (5 energy points)" << endl;
        cout << "5. Calculator (10 energy points)" << endl;
        cout << "6. Charger (5 energy points)" << endl;
        cout << "7. Water Bottle (5 energy points)" << endl;
        cout << "8. Sandwich (5 energy points)" << endl;
        cout << "9. I don't want to buy anything, exit Store." << endl;
        int itemChoice;
        cin >> itemChoice;
        ProcessStoreChoice(itemChoice);
    } else {
        cout << "Invalid location." << endl;
    }
}





void Game::ProcessStoreChoice(int choice) {
    if (choice == 1) {
        cout << "You chose to buy a Textbook." << endl;
        if (player.getEnergy() < 10) {
            cout << "You don't have enough energy points to buy a Textbook." << endl;
            return;
        }
        else {
            player.addItem(Item("Textbook", "bundle"));
            cout << "You spent 10 energy points." << endl;
        player.setEnergy(player.getEnergy() - 10);
        }
        

    } 
    else if (choice == 2) {
        cout << "You chose to buy a Laptop." << endl;
        if (player.getEnergy() < 15) {
            cout << "You don't have enough energy points to buy a Laptop." << endl;
            return;
        }
        else {
            player.addItem(Item("Laptop", "bundle"));
            cout << "You spent 15 energy points." << endl;
        player.setEnergy(player.getEnergy() - 15);
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
        if (player.getEnergy() < 5) {
            cout << "You don't have enough energy points to buy a Pen." << endl;
            return;
        }
        else {
            player.addItem(Item("Pen", "bundle"));
            cout << "You spent 5 energy points." << endl;
            player.setEnergy(player.getEnergy() - 5);
        }
        
    }
    else if (choice == 5) {
        cout << "You chose to buy a Calculator." << endl;
        if (player.getEnergy() < 10) {
            cout << "You don't have enough energy points to buy a Calculator." << endl;
            return;
        }
        else {
            player.addItem(Item("Calculator", "bundle"));
            cout << "You spent 10 energy points." << endl;
            player.setEnergy(player.getEnergy() - 10);
        }
    }
    else if (choice == 6) {
        cout << "You chose to buy a Charger." << endl;
        if (player.getEnergy() < 5) {
            cout << "You don't have enough energy points to buy a Charger." << endl;
            return;
        }
        else {
            player.addItem(Item("Charger", "bundle"));
            cout << "You spent 5 energy points." << endl;
            player.setEnergy(player.getEnergy() - 5);
        }
    }
    else if (choice == 7) { 
        cout << "You chose to buy a Water Bottle." << endl;
        if (player.getEnergy() < 5) {
            cout << "You don't have enough energy points to buy a Water Bottle." << endl;
            return;
        }
        else {
            player.addItem(Item("Water Bottle", "bundle"));
            cout << "You spent 5 energy points." << endl;
            player.setEnergy(player.getEnergy() - 5);
        }
    }
    else if (choice == 8) {
        cout << "You chose to buy a Sandwich." << endl;
        if (player.getEnergy() < 5) {
            cout << "You don't have enough energy points to buy a Sandwich." << endl;
            return;
        }
        else {
            player.addItem(Item("Sandwich", "bundle"));
            cout << "You spent 5 energy points." << endl;
            player.setEnergy(player.getEnergy() - 5);
        }
    }
    else if (choice == 9) {
        cout << "You chose not to buy anything." << endl;

    } else {
        cout << "Invalid item choice. Please choose a valid item." << endl;
    }
}





void Game::talkToFriend(string friendName) {
    for (int i = 0; i < 5; i++) {
        if (friendList[i].getName() == friendName) {
            cout << "Talking to " << friendList[i].getName() << "..." << endl;
            player.setFriendship(player.getFriendship() + 1);
            return;
        }
    }
    cout << "Friend not found." << endl;
}





void Game::talkToCharacter() {
    if (player.getCurrentLocation() == "Library") {
        talkToFriend("Eleanor");
    } else if (player.getCurrentLocation() == "Dining Hall") {
        talkToFriend("Daniel");
    } else if (player.getCurrentLocation() == "Gym") {
        talkToFriend("Maya");
    } else if (player.getCurrentLocation() == "Classroom") {
        talkToFriend("Professor Mosunov");
    } else if (player.getCurrentLocation() == "Dorm") {
        talkToFriend("Kayra");
    } else {
        cout << "There is no one to talk to here." << endl;
    }
}




void Game::endDay() {
    cout << "Ending the day..." << endl;
   player.setCurrentDay(player.getCurrentDay() + 1);
}




bool Game::checkWin() {
    if (player.getFriendship() >= 15 && player.getStudyHours() >= 20) {
        return true;
    }
    return false;
}



bool Game::checkBurnout() {
    if (player.getTiredStudent() > 3) {
        return true;
    }
    return false;
}




bool Game::checkLoss() {
    if (player.getEnergy() <= 0 || player.getCurrentDay() > 7 || player.getTiredStudent() > 3) {
        return true;
    }
    return false;
}




void Game::displayEnding() {
    if (checkWin()) {
        cout << "Congratulations! You have survived midterms!" << endl;
    } else if (checkLoss()) {
        cout << "Game Over! You have lost the game!" << endl;
    } else if (checkBurnout()) {
        cout << "You have burned out! Better luck next time!" << endl;
    } else {
        cout << "The game is still ongoing." << endl;
    }
}