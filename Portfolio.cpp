#include "Portfolio.h"
#include "PurchaseRecord.h"
using namespace boost::gregorian;
using namespace std;

bool Portfolio::IsEmpty() const
{
   return 0 == holdings_.size(); 
}

void Portfolio::Purchase(const string& symbol, unsigned int shareCount, const date& transactionDate)
{
   int shareChange = shareCount;
   Transact(symbol, shareChange, transactionDate);
}

void Portfolio::Sell(const std::string& symbol, unsigned int shareCount, const date& transactionDate)
{
   if (shareCount > ShareCount(symbol))
      throw InvalidSellException();
   int shareChange = -shareCount;
   Transact(symbol, shareChange, transactionDate);
}

unsigned int Portfolio::ShareCount(const string& symbol) const
{
   auto it = holdings_.find(symbol);
   if (it == holdings_.end()) return 0;
   return it->second;
}

std::vector<PurchaseRecord> Portfolio::Purchases(const std::string &symbol) const
{
   return purchaseRecords_.find(symbol)->second;
}

void Portfolio::Transact(const std::string &symbol, int shareCharge, const boost::gregorian::date &transactionDate)
{
   ThrowIfShareCountIsZero(shareCharge);
UpdateShareCount(symbol, shareCharge);
AddPurchaseRecord(symbol, shareCharge, transactionDate);
}

void Portfolio::UpdateShareCount(const std::string &symbol, int shareChange) {
   holdings_[symbol] = ShareCount(symbol) + shareChange;
}

void Portfolio::AddPurchaseRecord(int shareChange, const boost::gregorian::date &date) {
   purchases_.push_back(PurchaseRecord(shareChange, date));
}

void Portfolio::ThrowIfShareCountIsZero(int shareChange) const {
   if(0 == shareChange)
      throw ShareCountCannotBeZeroException();
}

void Portfolio::AddPurchaseRecord(const std::string &symbol, int shareCount,
        const boost::gregorian::date &date) {
purchases_.push_back(PurchaseRecord(shareCount, date));
auto it = purchaseRecords_.find(symbol);
if(it == purchaseRecords_.end()) {
    purchaseRecords_[symbol] = vector<PurchaseRecord>();
}
purchaseRecords_[symbol].push_back(PurchaseRecord(shareCount, date));

}
