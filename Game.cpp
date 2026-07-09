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

void Game::startGame() {
    // Implementation for starting the game
}

void Game::displayDashboard() {
    // Implementation for displaying the dashboard
}

void Game::displayMap() {
    // Implementation for displaying the map
}

void Game::showMainMenu() {
    // Implementation for showing the main menu
}
void Game::processChoice(int choice) {
    // Implementation for processing choice
}
void Game::movePlayer() {
    //move character on map
}
void Game::talkToCharacter() {
    // Implementation for talking to character
}
void Game::endDay() {
    // Implementation for ending the day
}
bool Game::checkWin() {
    if (player.getFriendship() >= 15 && player.getStudyHours() >= 20) {
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
    // Implementation for displaying ending
}