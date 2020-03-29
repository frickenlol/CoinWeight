//
//  weighresult.cpp
//  CoinWeight
//
//  Created by Gian Cordana Sanjaya on 2020-03-28.
//  Copyright © 2020 -. All rights reserved.
//

#include "weighresult.hpp"

const std::string toString(const WeighResult weighResult) {
    switch (weighResult) {
        case WeighResult::Balance:
            return "Both sets have the same weight.";
        case WeighResult::LeftHeavy:
            return "Red set is heavier.";
        case WeighResult::RightHeavy:
            return "Blue set is heavier.";
    }
}
