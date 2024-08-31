#include "parser.hpp"

Parser::Parser(Lexer* lexer) : lexer(lexer) {
  // Read two tokens, so curToken and peekToken are both set
  this->nextToken();
  this->nextToken();
}

Program* Parser::ParseProgarm() { return nullptr; }

void Parser::nextToken() {
  this->curToken = this->peekToken;
  this->peekToken = this->lexer->nextToken();
}
