#include <string>
#include <vector>
#include <iostream>

#include "TokenKind.h"
class Lexer{

  std::istream& istr;
  std::string curline;
  unsigned pos; 
  TokenKind ParseToken();
public:
  std::vector<std::string> keywordTable;
  Lexer(std::istream& istr):istr(istr){
    //initialize keyword table
    keywordTable.resize(tok_kw_xor+1-tok_kw_abs);
    for(unsigned i=tok_kw_abs;i<=tok_kw_xor;i++)
      keywordTable.at(i-tok_kw_abs)=std::string(toString((TokenKind)i)).substr(3); //(remove 4 first char "kw_")
  }
  
  TokenKind Lex();
  
};
