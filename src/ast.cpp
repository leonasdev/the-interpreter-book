#include "ast.hpp"

#include <string>

Program::~Program() {
  for (IStatement* s : this->statements) {
    delete s;
  }
}

std::string Program::tokenLiteral() {
  if (statements.size() > 0) {
    return statements[0]->tokenLiteral();
  }

  return "";
}

Identifier::Identifier(Token token, std::string value)
    : token(token), value(value) {}

std::string Identifier::tokenLiteral() { return this->token.literal; }

std::string LetStatement::tokenLiteral() { return this->token.literal; }
