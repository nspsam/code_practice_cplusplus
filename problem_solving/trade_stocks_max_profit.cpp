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

  getMaxProfit(stockPricesYesterday);
  // returns 6 (buying for $5 and selling for $11)
 */

#include <iostream>
#include <vector>
#include <iterator>

//int getMaxProfit(std::vector<int> stockprices) {
//  return 0;
//}
  
int main() {
   std::vector<int> stockprices = {10, 7, 5, 8, 11, 9};
    
  //std::cout << "MaxProfit: " << getMaxProfit(stockprices);
  
  return 0;
}