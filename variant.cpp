#include <string>
#include <algorithm>
#include <stdexcept>
#include <cassert>
#include <iostream>

// This version of variant uses a struct to hold every possible type.
// This is a little memory inefficient but simple.
// See union_variant.cpp for a solution
class Variant{
public:
  enum Type {NoneType, NumberType, SymbolType};
  typedef int Number;
  typedef std::string Symbol;

  Variant(){
    type = NoneType;
  };
  
  Variant(Number n){
    type = NumberType;
    data.num = n;
  };

  Variant(std::string s){
    type = SymbolType;
    data.str = s;
  };

  bool is_number(){
    return type == NumberType;
  };

  bool is_symbol(){
    return type == SymbolType;
  };

  bool is_none(){
    return type == NoneType;
  };

  // one might want to overload operator== and stream operator as well
  
private:

  struct Data{
    int num;
    std::string str;
  };

  Type type;
  Data data;  
};

int main(int argc, char *argv[])
{
  Variant a1;
  std::cout << sizeof(a1) << " bytes" << std::endl;
  Variant a2(4);
  Variant a3(std::string("foo"));

  assert(a1.is_none());
  assert(a2.is_number());
  assert(a3.is_symbol());
  
  Variant a4 = a1;
  Variant a5 = a2;
  Variant a6 = a3;

  assert(a4.is_none());
  assert(a5.is_number());
  assert(a6.is_symbol());
  
  Variant a7, a8, a9;

  a7 = a1;
  a8 = a2;
  a9 = a3;

  assert(a7.is_none());
  assert(a8.is_number());
  assert(a9.is_symbol());
  
  return 0;
}
