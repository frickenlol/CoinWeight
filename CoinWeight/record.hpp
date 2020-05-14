//
//  record.hpp
//  CoinWeight
//
//  Created by Gian Cordana Sanjaya on 2020-03-22.
//  Copyright © 2020 -. All rights reserved.
//

#ifndef record_hpp
#define record_hpp

#include "coinstates.hpp"
#include "weighresult.hpp"

class Record {
    CoinSelection weighStates;
    WeighResult weighResult;
    
public:
    Record(CoinSelection weighStates, WeighResult weighResult);
    // Accessor functions
    const CoinSelection coinStates() const;
    const WeighResult result() const;
};

#endif
