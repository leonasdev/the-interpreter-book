#pragma once

#include "ast.hpp"
#include "lexer.hpp"
#include "token.hpp"
class Parser {
 public:
  Parser(Lexer* lexer);
  Program* ParseProgarm();

 private:
  void nextToken();

  Lexer* lexer;
  Token curToken;
  Token peekToken;
};
