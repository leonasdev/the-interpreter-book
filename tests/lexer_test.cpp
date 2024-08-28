#include <gtest/gtest.h>

#include "token.hpp"

TEST(TestLexer, TestNextToken) {
  std::string input = "=+(){};";

  std::vector<Token> tests{
      {TokenType::Assign, "="},
      {TokenType::Plus, "+"},
      {TokenType::LParen, "("},
      {TokenType::RParen, ")"},
      {TokenType::LBrace, "{"},
      {TokenType::RBrace, "}"},
      {TokenType::Semicolon, ";"},
  };

  Lexer l(input);

  for (const Token& t : tests) {
    tok = l.NextToken();

    EXPECT_EQ(tok.type, t.type) << "token type wrong";
    EXPECT_EQ(tok.literal, t.literal);
  }
}
