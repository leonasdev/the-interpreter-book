#include "lexer.hpp"

#include <string>

#include "token.hpp"
Lexer::Lexer(std::string input)
    : input(input), position(0), readPosition(0), ch(input[0]) {
  this->readChar();
}

bool isLetter(char ch) {
  return ('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z') || (ch == '_');
}

bool isDigit(char ch) { return ch >= '0' && ch <= '9'; }

Token Lexer::nextToken() {
  Token tok;
  this->skipWhiteSpace();
  switch (this->ch) {
    case '=':
      tok = {TokenType::Assign, std::string{this->ch}};
      break;
    case ';':
      tok = {TokenType::Semicolon, std::string{this->ch}};
      break;
    case '(':
      tok = {TokenType::LParen, std::string{this->ch}};
      break;
    case ')':
      tok = {TokenType::RParen, std::string{this->ch}};
      break;
    case ',':
      tok = {TokenType::Comma, std::string{this->ch}};
      break;
    case '+':
      tok = {TokenType::Plus, std::string{this->ch}};
      break;
    case '{':
      tok = {TokenType::LBrace, std::string{this->ch}};
      break;
    case '}':
      tok = {TokenType::RBrace, std::string{this->ch}};
      break;
    case '\0':
      tok = {TokenType::Eof, ""};
      break;
    default:
      if (isLetter(this->ch)) {
        tok.literal = this->readIdentifier();
        tok.type = tok.LookupIdent(tok.literal);
        return tok;
      } else if (isDigit(this->ch)) {
        tok.type = TokenType::Int;
        tok.literal = this->readNumber();
        return tok;
      } else {
        tok = {TokenType::Illegal, std::string{this->ch}};
      }
      break;
  }

  this->readChar();

  return tok;
}

void Lexer::readChar() {
  if (this->readPosition >= this->input.size()) {
    this->ch = 0;
  } else {
    this->ch = this->input[this->readPosition];
  }
  this->position = this->readPosition;
  this->readPosition += 1;
}

std::string Lexer::readIdentifier() {
  unsigned int beginPosition = this->position;
  for (; isLetter(this->ch);) {
    this->readChar();
  }
  return this->input.substr(beginPosition, this->position - beginPosition);
}

std::string Lexer::readNumber() {
  unsigned int beginPosition = this->position;
  for (; isDigit(this->ch);) {
    this->readChar();
  }
  return this->input.substr(beginPosition, this->position - beginPosition);
}

void Lexer::skipWhiteSpace() {
  for (; this->ch == ' ' || this->ch == '\t' || this->ch == '\n' ||
         this->ch == '\r';) {
    this->readChar();
  }
}
