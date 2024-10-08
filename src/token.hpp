#pragma once

#include <ostream>
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
  Minus,
  Bang,
  Asterisk,
  Slash,

  LT,
  GT,

  Eq,
  NotEq,

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
  True,
  False,
  If,
  Else,
  Return,
};

std::ostream& operator<<(std::ostream& out, const TokenType& tokenType);

class Token {
 public:
  Token();
  friend std::ostream& operator<<(std::ostream& out, const Token& token);
  Token(TokenType type, std::string literal);
  TokenType LookupIdent(std::string ident);

  TokenType type;
  std::string literal;
};
