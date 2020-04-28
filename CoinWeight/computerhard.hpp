//
//  computerhard.hpp
//  CoinWeight
//
//  Created by Gian Cordana Sanjaya on 2020-02-23.
//  Copyright © 2020 -. All rights reserved.
//

#ifndef computerhard_hpp
#define computerhard_hpp

#include "computer.hpp"
#include <vector>
#include <memory>

class ComputerHard : public Computer {
public:
	ComputerHard(size_t numOfCoins);
	~ComputerHard();
 
private:

	// States and strategy: How the results are handled
	struct State {
		std::vector<std::vector<size_t>> partition;
		enum class Type;
		Type type;
        
		State(size_t numOfCoins);
	};
	
	enum class Strategy;
	
	std::unique_ptr<State> state;
	Strategy strategy;
	
    // Overriding functions
	void beforeWeigh() override;
	const CoinStates pickToWeigh() const override;
	void afterWeigh(const WeighResult weighResult) override;
	const CoinStates pickToGuess() const override;
    const bool readyToGuess() const override;
};

#endif
