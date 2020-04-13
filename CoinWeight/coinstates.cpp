//
//  coinstates.cpp
//  CoinWeight
//
//  Created by Gian Cordana Sanjaya on 2020-03-24.
//  Copyright © 2020 -. All rights reserved.
//

#include "coinstates.hpp"
#include "exception.hpp"

//***************************************************** Constructor
CoinStates::CoinStates(size_t numOfCoins) :
    content(numOfCoins, Value::NoSelect) {}



//***************************************************** Field accessors
const size_t CoinStates::size() const {
    return content.size();
}

CoinStates::Value &CoinStates::operator[](size_t index) {
    return content[index];
}

const CoinStates::Value CoinStates::at(size_t index) const {
    if (content.size() <= index) {
        throw Exception<CoinStates>("Out of range exception.");
    } else {
        return content[index];
    }
}



//***************************************************** Reset function
void CoinStates::resetStates() {
    for (int i = 0; i < content.size(); ++i) {
        content[i] = Value::NoSelect;
    }
}



//***************************************************** Coin States Exception header message
template<> const std::string exceptionHeaderMessage<CoinStates>() {
    return "Coin States Failure: ";
}
