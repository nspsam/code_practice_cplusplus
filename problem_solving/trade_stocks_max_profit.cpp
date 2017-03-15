/*
  Writing programming interview questions hasn't made me rich. Maybe trading Apple stocks will.
  Suppose we could access yesterday's stock prices as a vector, where:

  The values are the price in dollars of Apple stock.
  A higher index indicates a later time.
  So if the stock cost $500 at 10:30am and $550 at 11:00am, then:

  stockPricesYesterday[60] = 500;

  Write an efficient function that takes stockPricesYesterday and returns the 
  best profit I could have made from 1 purchase and 1 sale of 1 Apple stock yesterday.
 
  For example:
  vector<int> stockPricesYesterday{10, 7, 5, 8, 11, 9};
  -3 -2 3 2 -2

  {10, 7, 5, 4, 3, 1};
  -3 -2 -1 -1 -2

  getMaxProfit(stockPricesYesterday);
  // returns 6 (buying for $5 and selling for $11)
 */

#include <iostream>
#include <vector>
#include <iterator>
#include <climits>

int getMaxProfit(const std::vector<int>& stockPricesYesterday)
{
  // make sure we have at least 2 prices
  if (stockPricesYesterday.size() < 2) {
    throw std::invalid_argument("Getting a profit requires at least 2 prices");
  }

  // we'll greedily update minPrice and maxProfit, so we initialize
  // them to the first price and the first possible profit
  int minPrice = stockPricesYesterday[0];
  int maxProfit = stockPricesYesterday[1] - stockPricesYesterday[0];

  // start at the second (index 1) time
  // we can't sell at the first time, since we must buy first,
  // and we can't buy and sell at the same time!
  // if we started at index 0, we'd try to buy *and* sell at time 0.
  // this would give a profit of 0, which is a problem if our
  // maxProfit is supposed to be *negative*--we'd return 0!
  for (size_t i = 1; i < stockPricesYesterday.size(); ++i) {
    int currentPrice = stockPricesYesterday[i];
    
    // see what our profit would be if we bought at the
    // min price and sold at the current price
    int potentialProfit = currentPrice - minPrice;
    
    // update maxProfit if we can do better
    maxProfit = std::max(maxProfit, potentialProfit);
    
    // update minPrice so it's always
    // the lowest price we've seen so far
    minPrice = std::min(minPrice, currentPrice);
  }

  return maxProfit;
}

int getMaxProfit_practice(const std::vector<int>& stockPricesYesterday) {
  if(stockPricesYesterday.size() < 2) {
    throw std::invalid_argument("atleast two prices are needed in input");
  }

  int minPrice = stockPricesYesterday[0];
  int maxProfit = stockPricesYesterday[1] - minPrice;

  for(size_t indx=1; indx<stockPricesYesterday.size(); ++indx) {
    int currentPrice = stockPricesYesterday[indx];

    int potentialProfit = currentPrice - minPrice;
    
    maxProfit = std::max(maxProfit, potentialProfit);
    minPrice = std::min(minPrice, currentPrice);
  }
}

int main() {
  int astp[] = {10, 7, 5, 8, 11, 9};
  //int astp[] = {10, 7, 5, 4, 3, 1};
  
  std::vector<int> stockprices(std::begin(astp), std::end(astp));
  std::cout << "MaxProfit: " << getMaxProfit(stockprices) << std::endl;
  
  return 0;
}
