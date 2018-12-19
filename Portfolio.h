/***
 * Excerpted from "Modern C++ Programming with Test-Driven Development",
 * published by The Pragmatic Bookshelf.
 * Copyrights apply to this code. It may not be used to create training material, 
 * courses, books, articles, and the like. Contact us if you are in doubt.
 * We make no guarantees that this code is fit for any purpose. 
 * Visit http://www.pragmaticprogrammer.com/titles/lotdd for more book information.
***/
#ifndef Portfolio_h
#define Portfolio_h

#include <string>
#include <exception>
#include <unordered_map>
#include <vector>
#include <boost/date_time/gregorian/gregorian_types.hpp>
#include "PurchaseRecord.h"

class InvalidSellException: public std::exception { };

class ShareCountCannotBeZeroException: public std::exception { };

class Portfolio
{
public:
    void Transact(const std::string& symbol, int shareCharge,
            const boost::gregorian::date& transactionDate);
    static const boost::gregorian::date FIXED_PURCHASE_DATE;
    bool IsEmpty() const;
    void Purchase(const std::string& symbol, unsigned int shareCount,
            const boost::gregorian::date& transactionDate = Portfolio::FIXED_PURCHASE_DATE);
    void Sell(const std::string& symbol, unsigned int shareCount,
            const boost::gregorian::date& transactionDate = Portfolio::FIXED_PURCHASE_DATE);
    unsigned int ShareCount(const std::string& symbol) const;
    std::vector<PurchaseRecord> Purchases(const std::string& symbol) const;

    void UpdateShareCount(const std::string& symbol, int shareChange);
    void AddPurchaseRecord(int shareChange, const boost::gregorian::date& date);
    void ThrowIfShareCountIsZero(int shareChange) const;

    void AddPurchaseRecord(const std::string& symbol, int shareCount,
            const boost::gregorian::date& date);

private:
    std::unordered_map<std::string, unsigned int> holdings_;
    std::vector<PurchaseRecord> purchases_;
    std::unordered_map<std::string, std::vector<PurchaseRecord>> purchaseRecords_;

};

#endif
