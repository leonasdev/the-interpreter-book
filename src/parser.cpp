#include "parser.hpp"

#include <sstream>

#include "ast.hpp"
#include "token.hpp"

Parser::Parser(Lexer* lexer) : lexer(lexer) {
  // Read two tokens, so curToken and peekToken are both set
  this->nextToken();
  this->nextToken();
}

Program* Parser::parseProgarm() {
  Program* program = new Program();
  for (; !curTokenIs(TokenType::Eof);) {
    IStatement* stmt = this->parseStatement();
    if (stmt != nullptr) {
      program->statements.push_back(stmt);
    }
    this->nextToken();
  }

  return program;
}

std::vector<std::string> Parser::getErrors() { return this->errors; }

void Parser::peekError(TokenType type) {
  std::ostringstream msg;
  msg << "expected next token to be " << type << ", got "
      << this->peekToken.type << " instead";
  this->errors.push_back(msg.str());
}

void Parser::nextToken() {
  this->curToken = this->peekToken;
  this->peekToken = this->lexer->nextToken();
}

IStatement* Parser::parseStatement() {
  switch (this->curToken.type) {
    case TokenType::Let:
      return this->parseLetStatement();
      break;
    default:
      return nullptr;
  }
}

LetStatement* Parser::parseLetStatement() {
  LetStatement* stmt = new LetStatement();
  stmt->token = this->curToken;

  if (!this->expectPeek(TokenType::Ident)) {
    return nullptr;
  }

  stmt->name = new Identifier(this->curToken, this->curToken.literal);

  if (!this->expectPeek(TokenType::Assign)) {
    return nullptr;
  }

  // TODO: We're skipping the expression until we encounter a semicolon
  for (; !curTokenIs(TokenType::Semicolon);) {
    this->nextToken();
  }

  return stmt;
}

bool Parser::curTokenIs(TokenType type) { return this->curToken.type == type; }

bool Parser::peekTokenIs(TokenType type) {
  return this->peekToken.type == type;
}

bool Parser::expectPeek(TokenType type) {
  if (this->peekTokenIs(type)) {
    this->nextToken();
    return true;
  } else {
    this->peekError(type);
    return false;
  }
}
