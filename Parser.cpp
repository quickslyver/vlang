#include "Parser.h"
#include <cassert>

ContextClauseAST* Parser::ParseContextClause(){
  //TODO
  return new ContextClauseAST();
}

/* package_declaration ::=
 *   package identifier is
 *   package_declarative_part
 *   end [ package ] [ package_simple_name ] ;
 */
PackageDeclarationAST* Parser::ParsePackageDeclarationAST(){
  eatToken(tok_package);
  eatToken(tok_identifier);
  eatToken(tok_is);
  eatToken(tok_end);
  if(curTok==package)
    eatToken(tok_package);
  if(curTok==tok_identifier);
    eatToken(tok_identifier);
  eatToken(tok_semicolon);
  return new PackageDeclarationAST("",Parse);
}

/* primary_unit ::=
 *   entity_declaration 
 *   | configuration_declaration 
 *   | package_declaration
 */
PrimaryUnitAST* Parser::ParsePrimaryUnit(){
  if(curTok == tok_kw_entity)
    assert(0 && "TODO");
  if(curTok == tok_kw_configuration)
    assert(0 && "TODO");
  
  if(curTok == tok_kw_package)
    return ParsePackageDeclarationAST();
  return new PrimaryUnitAST; //empty primary unit
}

SecondaryUnitAST* Parser::ParseSecondaryUnit(){
  //TODO
  return new SecondaryUnitAST();
}


LibraryUnitAST*   Parser::ParseLibraryUnit(){
  PrimaryUnitAST*   primaryUnit   = ParsePrimaryUnit();
  SecondaryUnitAST* secondaryUnit = ParseSecondaryUnit();
  return new LibraryUnitAST(primaryUnit,secondaryUnit);
}


DesignUnitAST* Parser::ParseDesignUnit(){
  ContextClauseAST* contextClause = ParseContextClause();
  LibraryUnitAST*   libraryUnit   = ParseLibraryUnit();
  return new DesignUnitAST(contextClause,libraryUnit);
}

DesignFileAST* Parser::ParseDesignFile(){
  DesignFileAST* designFile= new DesignFileAST();
  //eat first file token:
  getNextToken();
  while(curTok != tok_eof){
    designFile->addElement(ParseDesignUnit());
  }
  return designFile;
}
