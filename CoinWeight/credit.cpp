//
//  credit.cpp
//  CoinWeight
//
//  Created by Gian Cordana Sanjaya on 2020-04-22.
//  Copyright © 2020 -. All rights reserved.
//

#include "credit.hpp"
#include "model.hpp"
#include "viewx11.hpp"
#include "x11color.hpp"
#include "x11renderutil.hpp"

using namespace CoinWeight::X11;

//************************** Constructor
CreditScreen::CreditScreen() {}



//************************** Arrow button handling
void CreditScreen::onArrowUp() {}

void CreditScreen::onArrowDown() {}

void CreditScreen::onArrowLeft() {}

void CreditScreen::onArrowRight() {}



//************************** Character input handling
void CreditScreen::onCharInput(const char inputChar) {}



//************************** Return button handling
void CreditScreen::onReturnButton(Model &model) {
    model.switchToTitle();
}



//************************** UI display
void CreditScreen::triggerDisplay(Renderer &view) const {
    view.clearWindow();
    view.setForeground(Color::Default);
    
    view.drawString(300, 300, "---");
    
    const std::string &returnStr = "Return";
    view.drawString(300 + RenderUtil::border, 500 + RenderUtil::total_string_height - RenderUtil::border, returnStr);
    view.drawRectangle(300, 500, RenderUtil::total_string_width(returnStr.size()), RenderUtil::total_string_height);
    
    view.flushDisplay();
}
