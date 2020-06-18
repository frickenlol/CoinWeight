//
//  instruction.cpp
//  CoinWeight
//
//  Created by Gian Cordana Sanjaya on 2020-04-21.
//  Copyright © 2020 -. All rights reserved.
//

#include "instruction.hpp"
#include "model.hpp"
#include "viewx11.hpp"
#include "renderconst.hpp"

#include <vector>

using namespace CoinWeight::X11;

//************************** Constructor
InstructionScreen::InstructionScreen() {}



//************************** Arrow button handling
void InstructionScreen::onArrowUp() {}

void InstructionScreen::onArrowDown() {}

void InstructionScreen::onArrowLeft() {}

void InstructionScreen::onArrowRight() {}



//************************** Character input handling
void InstructionScreen::onCharInput(const char inputChar) {}



//************************** Return button handling
void InstructionScreen::onReturnButton(Model &model) {
    model.switchToTitle();
}



//************************** UI display
void InstructionScreen::triggerDisplay(Renderer &view) const {
    view.clearWindow();
    view.setForeground(RenderConst::defaultFGColor);

    const int x_pos_page_name = 300;
    int y_pos = 100;
    const int x_pos_page_instr = 320;
    const int y_pos_incr = 20;
    
    
    std::vector<std::vector<std::string>> displayStrings;
    
    displayStrings.emplace_back(std::vector<std::string>{
        "Main Page:",
        "Press Up/Down to select buttons.",
        "Press Enter/Return to switch page."
    });
    
    displayStrings.emplace_back(std::vector<std::string>{
        "Option Page:",
        "Press Left/Right to change selected option.",
        "Press Enter/Return to start game."
    });
    
    displayStrings.emplace_back(std::vector<std::string>{
        "Game Play Page (Human play):",
        "Press arrow keys to select coins.",
        "Press '0' to deselect a coin.",
        "Press '1' to move selected coin to the red (left) set.",
        "Press '2' to move selected coin to the blue (right) set.",
        "Press '3' to move selected coin to the green (guess) set.",
        "Press 'w' to weigh.",
        "Press 'g' to guess.",
        "Press 'h' to switch to history."
    });
    
    displayStrings.emplace_back(std::vector<std::string>{
        "Game Play Page (Computer play):",
        "Press Enter/Return to trigger the computer's move.",
        "Press 'h' to switch to history."
    });
    
    displayStrings.emplace_back(std::vector<std::string>{
        "Game History Page:",
        "Press Enter/Return to go back to the game play page.",
        "Press Left/Right to switch between previous moves."
    });
    
        
    for (auto pageStrList : displayStrings) {
        for (int i = 0; i < pageStrList.size(); ++i) {
            view.drawString(i == 0 ? x_pos_page_name : x_pos_page_instr, y_pos,
                pageStrList[i]);
            y_pos += y_pos_incr;
        }
    }
    
    const std::string &returnStr = "Return";
    view.drawString(300 + RenderConst::border, 550 + RenderConst::total_string_height - RenderConst::border, returnStr);
    view.drawRectangle(300, 550, RenderConst::total_string_width(returnStr.size()), RenderConst::total_string_height);
    
    view.flushDisplay();
}
