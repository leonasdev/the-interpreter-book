#pragma once

#include <string>

enum class TokenType {
  Illegal,
  Eof,

  // Identifier + literals
  Ident,
  Int,

  // Operators
  Assign,
  Plus,

  // Delimiters
  Comma,
  Semicolon,

  LParen,
  RParen,
  LBrace,
  RBrace,

  // Keywords
  Function,
  Let,
};

class Token {
public:
  std::string type;
  std::string literal;
};
