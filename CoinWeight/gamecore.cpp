//
//  gamecore.cpp
//  CoinWeight
//
//  Created by Gian Cordana Sanjaya on 2020-02-22.
//  Copyright © 2020 -. All rights reserved.
//

#include "gamecore.hpp"

//***************************************************** Helper functions
// Computes ceiling(log_n k)
template <size_t n> const size_t log_ceil(size_t k) {
	if (k == 0) exit(100);
	size_t res = 0;
	while (k > 1) {
		k = (k - 1) / n + 1;
		++res;
	}
	return res;
}



//***************************************************** Private static const variable
const std::map<GameCore::Level, std::string> GameCore::levelToStringConversionTable {
    {GameCore::Level::Easy,   "Easy"},
    {GameCore::Level::Medium, "Medium"},
    {GameCore::Level::Hard,   "Hard"}
};



//***************************************************** Private static method
const size_t GameCore::maxComparisons(size_t numOfCoins, GameCore::Level level) {
	switch (level) {
		case GameCore::Level::Easy:
			return numOfCoins;
		case GameCore::Level::Medium:
			return 2 * log_ceil<3>(numOfCoins) + 3;
		case GameCore::Level::Hard:
			return log_ceil<3>(numOfCoins) + log_ceil<3>((numOfCoins + 1) / 2);
		default:
			throw;
	}
}



//***************************************************** Constructor
GameCore::GameCore(int numOfCoins, Level level) :
	setOfCoins(std::make_unique<CoinSet>(numOfCoins)) , level(level),
	numOfWeighingsCounter(maxComparisons(numOfCoins, level)) {}
	


//***************************************************** Field accessors
const size_t GameCore::numOfCoins() const {
    return setOfCoins->size();
}

const size_t GameCore::numOfFakes() const {
    return setOfCoins->numOfFakeCoins;
}

const GameCore::Level GameCore::gameLevel() const {
    return level;
}

const size_t GameCore::numOfWeighingsLeft() const {
    return numOfWeighingsCounter;
}

const size_t GameCore::numOfWeighingsCap() const {
    return maxComparisons(setOfCoins->size(), level);
}



//***************************************************** Other public methods
const WeighResult GameCore::compareWeight(const CoinStates &weighing) {
    if (numOfWeighingsCounter == 0) {
        throw GameCoreFailure("No more comparisons.");
    }
    const WeighResult result = setOfCoins->compareWeight(weighing);
    --numOfWeighingsCounter;
    return result;
}

const bool GameCore::guessFakeCoins(const CoinStates &guess) const {
    return setOfCoins->guessFakeCoins(guess);
}

const std::string GameCore::levelToString(const GameCore::Level level) {
    return levelToStringConversionTable.at(level);
}



//***************************************************** Game Core Failure
GameCoreFailure::GameCoreFailure(std::string coreMessage) :
    Exception(coreMessage) {}

const std::string GameCoreFailure::headerMessage() const {
    return "Game Core: ";
}
