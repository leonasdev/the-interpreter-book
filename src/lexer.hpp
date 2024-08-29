#pragma once
#include <string>

#include "token.hpp"

class Lexer {
 public:
  Lexer(std::string input);
  Token nextToken();

 private:
  std::string input;
  unsigned int position;
  unsigned int readPosition;
  char ch;

  void readChar();
  char peekChar();
  void skipWhiteSpace();
  std::string readIdentifier();
  std::string readNumber();
};
