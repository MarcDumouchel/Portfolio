//
// Created by CCEClass1 on 12/19/2018.
//

#ifndef FIRSTEXAMPLE_PURCHASERECORD_H
#define FIRSTEXAMPLE_PURCHASERECORD_H

#include <boost/date_time/gregorian/gregorian_types.hpp>

struct PurchaseRecord
{
    PurchaseRecord(unsigned int shareCount, const boost::gregorian::date& date)
            : ShareCount(shareCount), Date(date){}

    int ShareCount;
    boost::gregorian::date Date;
};
#endif //FIRSTEXAMPLE_PURCHASERECORD_H
