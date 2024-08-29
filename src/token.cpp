#include "token.hpp"

#include <unordered_map>

std::unordered_map<std::string, TokenType> keywords = {
    {"fn", TokenType::Function},
    {"let", TokenType::Let},
    {"true", TokenType::True},
    {"false", TokenType::False},
    {"if", TokenType::If},
    {"else", TokenType::Else},
    {"return", TokenType::Return},
};

Token::Token(TokenType type, std::string literal)
    : type(type), literal(literal) {};

Token::Token() {};

TokenType Token::LookupIdent(std::string ident) {
  if (keywords.find(ident) != keywords.end()) {
    return keywords[ident];
  }

  return TokenType::Ident;
}
