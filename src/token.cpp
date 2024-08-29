#include "token.hpp"

#include <map>
#include <ostream>
#include <string>
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

std::ostream& operator<<(std::ostream& out, const TokenType& tokenType) {
  switch (tokenType) {
    case TokenType::Illegal:
      out << "Illegal";
      break;
    case TokenType::Eof:
      out << "EndOfFile";
      break;
    case TokenType::Ident:
      out << "Ident";
      break;
    case TokenType::Int:
      out << "Int";
      break;
    case TokenType::Assign:
      out << "Assign";
      break;
    case TokenType::Plus:
      out << "Plus";
      break;
    case TokenType::Minus:
      out << "Minus";
      break;
    case TokenType::Bang:
      out << "Bang";
      break;
    case TokenType::Asterisk:
      out << "Asterisk";
      break;
    case TokenType::Slash:
      out << "Slash";
      break;
    case TokenType::LT:
      out << "LT";
      break;
    case TokenType::GT:
      out << "GT";
      break;
    case TokenType::Eq:
      out << "Eq";
      break;
    case TokenType::NotEq:
      out << "NotEq";
      break;
    case TokenType::Comma:
      out << "Comma";
      break;
    case TokenType::Semicolon:
      out << "Semicolon";
      break;
    case TokenType::LParen:
      out << "LParen";
      break;
    case TokenType::RParen:
      out << "RParen";
      break;
    case TokenType::LBrace:
      out << "LBrace";
      break;
    case TokenType::RBrace:
      out << "RBrace";
      break;
    case TokenType::Function:
      out << "Function";
      break;
    case TokenType::Let:
      out << "Let";
      break;
    case TokenType::True:
      out << "True";
      break;
    case TokenType::False:
      out << "False";
      break;
    case TokenType::If:
      out << "If";
      break;
    case TokenType::Else:
      out << "Else";
      break;
    case TokenType::Return:
      out << "Return";
      break;
  }
  return out;
}

std::ostream& operator<<(std::ostream& out, const Token& token) {
  out << "Type: " << token.type << ", Literal: " << token.literal;
  return out;
}
