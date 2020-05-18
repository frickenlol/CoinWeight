//
//  gamescreen.hpp
//  CoinWeight
//
//  Created by Gian Cordana Sanjaya on 2020-03-30.
//  Copyright © 2020 -. All rights reserved.
//

#ifndef gamescreen_hpp
#define gamescreen_hpp

#include <memory>

class GameController;
class GameUI;

class GameScreen {
public:
    virtual ~GameScreen() = default;

    // Action on arrow button press
    // Generally, does not change the view itself other than the screen
    virtual void highlightUp(GameController &view) = 0;
    virtual void highlightDown(GameController &view) = 0;
    virtual void highlightLeft(GameController &view) = 0;
    virtual void highlightRight(GameController &view) = 0;
    
    // Action on character input press
    virtual void onCharInput(GameController &view, const char inputChar) = 0;
    
    // Action on return button press (most certainly screen switching)
    virtual void onReturnButton(GameController &view) = 0;
    
    // Triggers View and UI for displaying the current screen
    virtual void triggerDisplay(GameController &view, GameUI &interface) = 0;
    
};

#endif
