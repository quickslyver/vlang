#include "Lexer.h"
#include "Ast.h"
#include <cassert>

class Parser{
  Lexer& lexer;
  TokenKind curTok; ///current token
  TokenKind getNextToken(){
    curTok=lexer.Lex();
    return curTok;
  }
  void eatToken(TokenKind expectedToken){
    if(curTok != expectedToken)
      std::cerr << "Warning: Expected a " << toString(expectedToken) << " but got a " << toString(curTok) << "\n";
    getNextToken();
  }

  /*void continueOnError(TokenKind token){
	while(curTok != token && curTok!= tok_eof)
      getNextToken();
  }*/
  PackageDeclarationAST*  ParsePackageDeclarationAST();
  PrimaryUnitAST*         ParsePrimaryUnit();
  SecondaryUnitAST*       ParseSecondaryUnit();
  ContextClauseAST*       ParseContextClause();
  LibraryUnitAST*         ParseLibraryUnit();
  DesignUnitAST*          ParseDesignUnit();
public:
  Parser(Lexer& lexer):lexer(lexer){}
  DesignFileAST*          ParseDesignFile();
};
