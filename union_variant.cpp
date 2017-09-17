#include <string>
#include <algorithm>
#include <stdexcept>
#include <cassert>
#include <iostream>

// This version of variant uses a tagged union
// manual memory allocation is needed since
// only types with trivial constructors can be
// members of a union. std::string is not such a type
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
    num = n;
  };

  Variant(std::string s){
    type = SymbolType;
    symbol_len = s.size();
    copy_str(s);
  };

  Variant(const Variant & x){
    if(x.type == NumberType){
      type = NumberType;
      num = x.num;
    }
    else if(x.type == SymbolType){
      type = SymbolType;
      symbol_len = x.symbol_len;
      str = new char[symbol_len];
      std::copy(x.str, x.str + x.symbol_len + 1, str);
    }
    else{
      type = NoneType;
    }
  };

  Variant & operator=(const Variant & x){
    if(type == SymbolType){
      delete [] str;
    }
    if(x.type == NumberType){
      type = NumberType;
      num = x.num;
    }
    else if(x.type == SymbolType){
      type = SymbolType;
      symbol_len = x.symbol_len;
      str = new char[symbol_len];
      std::copy(x.str, x.str + x.symbol_len + 1, str);
    }
    else{
      type = NoneType;
    }
    
    return *this;
  };
  
  ~Variant(){
    if(type == SymbolType){
      delete [] str;
    }
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

  //anonymous union
  union {
    int num;
    char * str;
  };

  Type type;
  std::size_t symbol_len;

  void copy_str(const std::string & s){
    str = new char[s.size()];
    std::copy(s.begin(), s.end(), str);
  }
  
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
