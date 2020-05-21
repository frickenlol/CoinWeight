//
//  model.cpp
//  CoinWeight
//
//  Created by Gian Cordana Sanjaya on 2020-05-21.
//  Copyright © 2020 -. All rights reserved.
//

#include "model.hpp"
#include "modelstatefactory.hpp"

using namespace CoinWeight;

//************************** Constructor
Model::Model(const size_t coinDisplayRows, const size_t coinDisplayColumns) :
coinDisplayRows(coinDisplayRows), coinDisplayColumns(coinDisplayColumns) {
    switchToTitle();
}



//************************** Input handling
void Model::onArrowUp() {
    screen->highlightUp();
}

void Model::onArrowDown() {
    screen->highlightDown();
}

void Model::onArrowLeft() {
    screen->highlightLeft();
}

void Model::onArrowRight() {
    screen->highlightRight();
}

void Model::onCharInput(const char inputChar) {
    screen->onCharInput(inputChar);
}

void Model::onReturnButton() {
    screen->onReturnButton(*this);
}



//************************** Screen switching
void Model::switchToTitle() {
    screen = ScreenFactory::createTitleScreen();
}

void Model::switchToInstruction() {
    screen = ScreenFactory::createInstructionScreen();
}

void Model::switchToCredit() {
    screen = ScreenFactory::createCreditScreen();
}

void Model::switchToGameSettings() {
    screen = ScreenFactory::createGameSettingsScreen();
}

void Model::switchToGamePlay(const size_t numOfCoins,
const GameLevel level, const bool isHumanMode) {
    if (isHumanMode) {
        screen = ScreenFactory::createGamePlayHumanScreen(
            numOfCoins, level, coinDisplayRows, coinDisplayColumns);
    } else {
        screen = ScreenFactory::createGamePlayComputerScreen(
            numOfCoins, level, coinDisplayRows, coinDisplayColumns);
    }
}

void Model::switchToGameOver(const bool isWin) {
    screen = ScreenFactory::createGameOverScreen(isWin);
}



//************************** View updating
void Model::updateView(View &view) {
    screen->triggerDisplay(view);
}
