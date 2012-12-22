#ifndef AST_H
#define AST_H

class AST{
};

template<typename ElmtType> class ElementsArrayAST:public AST{
  std::vector<ElmtType*> elements;
  public:
  void addElement(ElmtType* elmt){
    elements.push_back(elmt);
  }
};


class PackageDeclarativeItemAST:public AST{
};

class PrimaryUnitAST:AST{
};


class PackageDeclarativePartAST:public ElementsArrayAST<PackageDeclarativeItemAST>{
};

class PackageDeclarationAST:public PrimaryUnitAST{
  std::string identifier;
  PackageDeclarativePartAST* packageDeclPart;
  public:
  PackageDeclarationAST(
    std::string identifier,
    PackageDeclarativePartAST* packageDeclPart
  ):
    identifier(identifier),
    packageDeclPart(packageDeclPart){}
};

class SecondaryUnitAST:public AST{
};

class LibraryUnitAST:public AST{
public:
  PrimaryUnitAST*   primaryUnit;
  SecondaryUnitAST* secondaryUnit;
  public:
  LibraryUnitAST(PrimaryUnitAST   *primaryUnit,
                SecondaryUnitAST *secondaryUnit
                ):primaryUnit(primaryUnit),secondaryUnit(secondaryUnit){}
};

class ContextItemAST:public AST{
};

class ContextClauseAST:public ElementsArrayAST<ContextItemAST>{
};

class DesignUnitAST:public AST{
public:
  ContextClauseAST* contextClause;
  LibraryUnitAST*   libraryUnit;
  public:
  DesignUnitAST(ContextClauseAST *contextClause,
                LibraryUnitAST   *libraryUnit
                ):contextClause(contextClause),libraryUnit(libraryUnit){}
};

class DesignFileAST:public ElementsArrayAST<DesignUnitAST>{
};

#endif
