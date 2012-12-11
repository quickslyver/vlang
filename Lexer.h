#include <string>
#include <vector>
#include <iostream>

#include "TokenKind.h"
class Lexer{

  std::istream& istr;

public:
  Lexer(std::istream istr):istr(istr){

  }
  
  TokenKind Lex(Token& tok);
  
}
