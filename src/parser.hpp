#pragma once

#include "ast.hpp"
#include "lexer.hpp"
#include "token.hpp"
class Parser {
 public:
  Parser(Lexer* lexer);
  Program* parseProgarm();
  std::vector<std::string> getErrors();

 private:
  void nextToken();
  IStatement* parseStatement();
  LetStatement* parseLetStatement();
  bool expectPeek(TokenType type);
  bool curTokenIs(TokenType type);
  bool peekTokenIs(TokenType type);
  void peekError(TokenType type);

  Lexer* lexer;
  Token curToken;
  Token peekToken;
  std::vector<std::string> errors;
};
