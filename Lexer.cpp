#include "Lexer.h"
#include <cassert>
#include <sstream>

// [a-zA-Z]
static bool isAlpha(char c){
  return (c>='A' && c<='Z') || (c>='a' && c<='z');
}

// [0-9]
static bool isNum(char c){
  return (c>='0' && c<='9');
}

// [a-zA-Z0-9]
static bool isAlphaNum(char c){
  return(isAlpha(c) || isNum(c));
}

static bool toLower(char c){
  if(c>='A' && c<='Z')
    return c -'A' + 'a';
  return c;
}


//get a token:
//  * token kind
//  * line
//  * col
//  * string
TokenKind Lexer::Lex(){
  TokenKind tok=tok_invalid;
  do{
    tok=ParseToken();
  }while(tok==tok_comment || tok==tok_newline);//remove comments and newline from token stream;
  return tok;
}


TokenKind Lexer::ParseToken(){
  if(curline.empty() || curline.size()==pos ){
    char c;
    curline.clear();
    do{
      istr.get(c);
      if(istr.eof())
        return tok_eof;
      curline+=c;
    }while(c!='\n');
    pos=0;
  }
  //convert the string to a null terminated string
  // => so if linestr[pos]/=0 then linestr[pos+1] is valid
  const char* linestr=curline.c_str();
  
  //eliminate blanks
  while(linestr[pos]==' ' || linestr[pos]=='\t')
    pos++;
  
  //alpha (identifier/keyword):
  if(isalpha(linestr[pos])){
    std::string ident;
    ident.reserve(64);
    //eat until end of alphanum
    while(1){
      char c=linestr[pos];
      if(!isAlphaNum(c))
        break;
      ident+=c;
      pos++;
    }
    //check for keyword
    for(unsigned i=0;i<keywordTable.size();i++)
      if(keywordTable[i]==ident)
        return (TokenKind)(i+tok_kw_abs);
    //ident
    std::cerr << "(" << ident <<")";
    return tok_identifier;
  }

  //lex special chars:
  switch(linestr[pos++]){
    default:
      std::cerr << "(" << (int)linestr[pos-1] <<")";
      return tok_invalid;
    case '&':
      return tok_ampersand;
    case '\'':
      return tok_tick;
    case '(':
      return tok_lparen;
    case ')':
      return tok_rparen;
    case '*':
      if(linestr[pos]=='*'){ // **
        pos++;return tok_exp;
      }
      return tok_mul;
    case '+':
      return tok_plus;
    case ',':
      return tok_comma;
    case '-':
      if(linestr[pos]=='-'){// -- comment
        pos=curline.size();
        return tok_comment;
      }
      return tok_minus;
    case '.':
      return tok_dot;
    case '/':
      if(linestr[pos]=='='){
        pos++;return tok_inequal; // /=
      }
      return tok_divide;
    case ':':
      if(linestr[pos]=='='){
        pos++;return tok_var_assign; // :=
      }
      return tok_colon;
    case ';':
      return tok_semicolon;
    case '<':
      if(linestr[pos]=='='){
        pos++;return tok_less_or_equal_or_assign; // <=
      }
      if(linestr[pos]=='>'){
        pos++;return tok_box; // <>
      }
      return tok_less;
    case '=':
      if(linestr[pos]=='>'){  // =>
        pos++;return tok_arrow;
      }
      return tok_equal;
    case '>':
      if(linestr[pos]=='='){
        pos++;return tok_greater_or_equal; // >=
      }
      return tok_greater;
    case '|':
      return tok_vertical_line;
    case '[':
      return tok_lbracket;
    case ']':
      return tok_rbracket;
    case '\n':
      return tok_newline;
    case '"':
      assert(0 && "TODO");
      //parse string
  }
  assert(0 && "unexpected");
  return tok_invalid;
}

