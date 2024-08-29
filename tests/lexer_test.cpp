#include "lexer.hpp"

#include <gtest/gtest.h>

#include "token.hpp"

TEST(TestLexer, TestNextToken) {
  std::string input = R"(let five = 5;
let ten = 10;

let add = fn(x, y) {
    x + y;
};

let result = add(five, ten);
)";

  std::vector<Token> tests{
      {TokenType::Let, "let"},     {TokenType::Ident, "five"},
      {TokenType::Assign, "="},    {TokenType::Int, "5"},
      {TokenType::Semicolon, ";"}, {TokenType::Let, "let"},
      {TokenType::Ident, "ten"},   {TokenType::Assign, "="},
      {TokenType::Int, "10"},      {TokenType::Semicolon, ";"},
      {TokenType::Let, "let"},     {TokenType::Ident, "add"},
      {TokenType::Assign, "="},    {TokenType::Function, "fn"},
      {TokenType::LParen, "("},    {TokenType::Ident, "x"},
      {TokenType::Comma, ","},     {TokenType::Ident, "y"},
      {TokenType::RParen, ")"},    {TokenType::LBrace, "{"},
      {TokenType::Ident, "x"},     {TokenType::Plus, "+"},
      {TokenType::Ident, "y"},     {TokenType::Semicolon, ";"},
      {TokenType::RBrace, "}"},    {TokenType::Semicolon, ";"},
      {TokenType::Let, "let"},     {TokenType::Ident, "result"},
      {TokenType::Assign, "="},    {TokenType::Ident, "add"},
      {TokenType::LParen, "("},    {TokenType::Ident, "five"},
      {TokenType::Comma, ","},     {TokenType::Ident, "ten"},
      {TokenType::RParen, ")"},    {TokenType::Semicolon, ";"},
      {TokenType::Eof, ""}};

  Lexer l{input};

  for (const Token& t : tests) {
    Token tok = l.nextToken();

    EXPECT_EQ(tok.type, t.type);
    EXPECT_EQ(tok.literal, t.literal);
  }
}
