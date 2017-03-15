#include <iostream>

/*
 * Introduction to templates
 * 
 * a) Template has side effect  code bloat
 * b) Template should be used responsibly, overuse or abuse hit the 
 * code size
 * c) Difference between class templates and functon templates is, functon
 * templates can infer the data type from its parameter, no need for 
 * explicit tell to compiler. 
 * But class templates, you have to specific what data type you are gonna use
 */

template <typename T>
T square(T x) {
  return x*x;
}

template <typename T>
class BoVector {
  T array[1000];
  int size;
public:
  BoVector() : size(0) {}
  
  void push(T x) { array[size]=x; ++size; }
  
  void print() const {
    for(int i=0; i<size; i++) {
      std::cout << array[i] << std::endl;
    }
  }
  
  T get(int index) const { return array[index];  }
  int getsize() const { return size; };
};

// Operator modifier for BoVector
template <typename T>
BoVector<T> operator*(const BoVector<T>& rhs1, const BoVector<T>& rhs2) {
  BoVector<T> ret;
  
  for(int i=0; i<rhs1.getsize(); ++i) {
   ret.push(rhs1.get(i) * rhs2.get(i)) ;
  }
  
  return ret;
} 

int main() {
  //std::cout << square(5) << std::endl;
  //std::cout << square(5.5) << std::endl;
  
  BoVector<int> bv;
  bv.push(5);
  bv.push(10);
  bv.push(16);
  bv.push(2);
  bv.print();
  
  std::cout << "Print BoVector square: " << std::endl;
  bv = square(bv);
  bv.print();
  
  return 0;
}

