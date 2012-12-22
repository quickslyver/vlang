#include "Lexer.h"
#include "Parser.h"
#include <iostream>
#include <fstream>
#include "Ast.h"

int main(int argc,char** argv)
{
  if(argc != 2)
    return 1;
  std::ifstream file(argv[1]);
  
  Lexer Lex(file);
  Parser Parse(Lex);
  Parse.ParseDesignFile();
  /*TokenKind tok;
  do{
    tok=Lex.Lex();
    std::cout << toString(tok) << '\n';
  }while(tok!=tok_eof);*/
  
  return 0;
}
