//
// Created by hvalle on 12/17/2018.
//

#include "Portfolio.h"
using namespace std;
Portfolio::Portfolio()
        : isEmpty_{true}
        , shareCount_{0u} {
}


bool Portfolio::IsEmpty() const {
    return 0 == shareCount_;
}

void Portfolio::Purchase(const string& symbol, unsigned int shareCount) {
    isEmpty_ = false;
    shareCount_ = shareCount;
}

unsigned int Portfolio::ShareCount(const string& symbol) const {
    return shareCount_;
}