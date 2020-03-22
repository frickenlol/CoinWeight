//
//  gameviewx11.hpp
//  CoinWeight
//
//  Created by Gian Cordana Sanjaya on 2020-03-03.
//  Copyright © 2020 -. All rights reserved.
//

#ifndef gameviewx11_hpp
#define gameviewx11_hpp

#include <memory>
#include "gameview.hpp"
#include "x11graphics.hpp"
#include <string>
#include <vector>

class GameViewX11 : public GameView {
	X11Graphics coreGraphics;
    void drawCoin(int coinState, size_t coinIndex);
    static const int coinRadius = 30;

public:
    GameViewX11();
    void drawMainScreen(int screenHighlight) override;
    void drawInstructionScreen() override;
    void drawCreditScreen() override;
    void drawGameOptionScreen(int screenHighlight, size_t numOfCoins,
            std::string gameLevel, bool isHuman) override;
    void drawGamePlayScreen(
        std::vector<int> coinStates,
        int highlightedCoin,
        size_t numOfComparisonsLeft,
        size_t numOfComparisonsCap,
        std::vector<Record> gameHistory
        ) override;
    void drawGameOverScreen(
        bool isWin,
        size_t numOfComparisonsLeft,
        size_t numOfComparisonsCap,
        std::vector<size_t> finalGuess) override;
    void receiveInput() override;
    const Input lastInput() const override;
};

#endif
