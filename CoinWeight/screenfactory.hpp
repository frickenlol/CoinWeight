//
//  screenfactory.hpp
//  CoinWeight
//
//  Created by Gian Cordana Sanjaya on 2020-05-15.
//  Copyright © 2020 -. All rights reserved.
//

#ifndef screenfactory_hpp
#define screenfactory_hpp

#include <memory>
#include "gamescreen.hpp"

class ScreenFactory final {
public:
    static std::unique_ptr<ModelState>
        createTitleScreen();
    
    static std::unique_ptr<ModelState>
        createInstructionScreen();
        
    static std::unique_ptr<ModelState>
        createCreditScreen();
        
    static std::unique_ptr<ModelState>
        createGameSettingsScreen();
        
    static std::unique_ptr<ModelState>
        createGamePlayHumanScreen(const size_t nCoinsTotal,
        const size_t nRowsDisplay, const size_t nCoinsPerRow);
        
    static std::unique_ptr<ModelState>
        createGamePlayComputerScreen(const size_t nCoinsTotal,
        const size_t nRowsDisplay, const size_t nCoinsPerRow);
        
    static std::unique_ptr<ModelState>
        createGameOverScreen(const bool isWin);
};


#endif
