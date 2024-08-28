#pragma once
#include <string>

class Lexer {
 public:
  Lexer(std::string input);

 private:
  std::string input;
  unsigned int position;
  unsigned int readPosition;
  char ch;
  void readChar();
};
