/*
 Problem: You have a vector of integers, and for each index you want 
to find the product of every integer except the integer at that index.

Write a function getProductsOfAllIntsExceptAtIndex() that takes a vector 
of integers and returns a vector of the products.

For example, given:
  [1, 7, 3, 4]

your function would return:
  [84, 12, 28, 21]

by calculating:
  [7 * 3 * 4,  1 * 3 * 4,  1 * 7 * 4,  1 * 7 * 3]

Do not use division in your solution.

Gotchas
Does your function work if the input vector contains zeroes? Remember—no division.
We can do this in O(n)O(n)O(n) time and O(n)O(n)O(n) space!
We only need to allocate one new vector of size nnn.
 */

#include <cstdio>
#include <iostream>
#include <vector>

vector<int> getProductsOfAllIntsExceptAtIndex_interviewCake(const vector<int>& intVector)
{
    // make sure we have at least 2 numbers
    if (intVector.size() < 2) {
        throw invalid_argument("Getting the product of numbers at"
            " other indices requires at least 2 numbers");
    }

    // we make an array with the length of the input array to hold our products
    vector<int> productsOfAllIntsExceptAtIndex(intVector.size());

    // for each integer, we find the product of all the integers
    // before it, storing the total product so far each time
    int productSoFar = 1;
    for (size_t i = 0; i < intVector.size(); ++i) {
        productsOfAllIntsExceptAtIndex[i] = productSoFar;
        productSoFar *= intVector[i];
    }

    // for each integer, we find the product of all the integers
    // after it. since each index in products already has the
    // product of all the integers before it, now we're storing
    // the total product of all other integers
    productSoFar = 1;
    for (size_t i = intVector.size(); i > 0; --i) {
        size_t j = i - 1;
        productsOfAllIntsExceptAtIndex[j] *= productSoFar;
        productSoFar *= intVector[j];
    }

    return productsOfAllIntsExceptAtIndex;
}

std::vector<int> getProductsOfAllIntsExceptAtIndex(const std::vector<int>& input) {
  
  if(input.size() < 2) {
    throw std::invalid_argument("invalid input size is < 2");
  }

  std::vector<int> output(input.size());

  output[0] = 1;
  for(int indx=1; indx<input.size(); ++indx) {
    output[indx] = output[indx-1] * input[indx-1];
  }

  int productSoFar = 1;
  for(int indx=(input.size()-2); indx>=0; --indx) {
     productSoFar *= input[indx+1];
     output[indx] *= productSoFar;
  }

  return output;
}

int main()
{
  std::vector<int> input = {2,4,10};//{1, 3, 2, 2, 4, 5};
  std::vector<int> output = getProductsOfAllIntsExceptAtIndex(input);

  for(auto it: output)
    std::cout << it << std::endl;
  
  return 0;
}
