#include "lexer.hpp"
Lexer::Lexer(std::string input) : input(input) { this->readChar(); }

void Lexer::readChar() {
  if (this->readPosition >= this->input.size()) {
    this->ch = 0;
  } else {
    this->ch = this->input[this->readPosition];
  }
  this->position = this->readPosition;
  this->readPosition += 1;
}
