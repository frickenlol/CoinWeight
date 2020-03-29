//
//  coinset.hpp
//  CoinWeight
//
//  Created by Gian Cordana Sanjaya on 2020-02-21.
//  Copyright © 2020 -. All rights reserved.
//

#ifndef coinset_hpp
#define coinset_hpp

#include <vector>
#include "coinstates.hpp"
#include "weighresult.hpp"
#include "exception.hpp"

class CoinSet {
    // Fake coins are lighter than real coins and denoted by [false]
	std::vector<bool> coins;

public:
    // Constructor
	CoinSet(int numOfCoins);
    
    // Static constant
	static const size_t numOfFakeCoins;
	
    // Field accessor
	const size_t size() const;
	
	// Game functions
	const WeighResult compareWeight(const CoinStates &weighing) const;
	const bool guessFakeCoins(const CoinStates &guess) const;
};



//***************************************************** Coin Set Failure
class CoinSetFailure : public Exception {
    const std::string headerMessage() const override;
public:
	CoinSetFailure(std::string coreMessage);
};

#endif
