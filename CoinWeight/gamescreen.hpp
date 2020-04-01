//
//  gamescreen.hpp
//  CoinWeight
//
//  Created by Gian Cordana Sanjaya on 2020-03-30.
//  Copyright © 2020 -. All rights reserved.
//

#ifndef gamescreen_hpp
#define gamescreen_hpp

#include "exception.hpp"

class GameScreen {
public:
    enum class Page {
        Main,               // Play, Instruction, Credit
        Instruction,
        Credit,
        GameOption,         // Number of coins, Difficulty, Human/Computer mode
        GamePlayHuman,      // Coins, Weigh, Guess
        GamePlayComputer,   // Next Step
        GameOver
    };

private:
    Page page;
    int highlight;

    // Modifier functions (private)
    const int minHighlight();
    const int maxHighlight();
    void resetHighlight();

public:
    GameScreen(Page page = Page::Main, int highlight = 0);
    
    const Page currentScreen() const;
    const int currentHighlight() const;
    
    // Modifier functions (public)
    void incrementHighlight();
    void decrementHighlight();
    void transition(const Page nextScreen);
    

};

class GameScreenFailure : public Exception {
    const std::string headerMessage() const override;
public:
    GameScreenFailure(std::string coreMessage);
};

#endif
