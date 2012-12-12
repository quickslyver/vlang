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
  TokenKind eatToken(TokenKind expectedToken){
    assert(curTok == expectedToken);
    return getNextToken();
  }
  
  PackageDeclarationAST*  ParsePackageDeclarationAST();
  PrimaryUnitAST*         ParsePrimaryUnit();
  SecondaryUnitAST*       ParseSecondaryUnit();
  ContextClauseAST*       ParseContextClause();
  LibraryUnitAST*         ParseLibraryUnit();
  DesignUnitAST*          ParseDesignUnit();
  DesignFileAST*          ParseDesignFile();
public:
  Parser(Lexer& lexer):lexer(lexer){}
};
