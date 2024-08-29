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
  TokenType type;
  std::string literal;
  Token();
  Token(TokenType type, std::string literal);
  TokenType LookupIdent(std::string ident);
  friend std::ostream& operator<<(std::ostream& out, const Token& token);
};
