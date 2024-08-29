#include "lexer.hpp"

#include <gtest/gtest.h>

#include "token.hpp"

TEST(TestLexer, TestNextToken1) {
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

TEST(TestLexer, TestNextToken2) {
  std::string input = R"(let five = 5;
let ten = 10;

let add = fn(x, y) {
    x + y;
};

let result = add(five, ten);
!-/*5;
5 < 10 > 5;

if (5 < 10) {
    return true;
} else {
    return false;
}

10 == 10;
10 != 9;
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
      {TokenType::Bang, "!"},      {TokenType::Minus, "-"},
      {TokenType::Slash, "/"},     {TokenType::Asterisk, "*"},
      {TokenType::Int, "5"},       {TokenType::Semicolon, ";"},
      {TokenType::Int, "5"},       {TokenType::LT, "<"},
      {TokenType::Int, "10"},      {TokenType::GT, ">"},
      {TokenType::Int, "5"},       {TokenType::Semicolon, ";"},
      {TokenType::If, "if"},       {TokenType::LParen, "("},
      {TokenType::Int, "5"},       {TokenType::LT, "<"},
      {TokenType::Int, "10"},      {TokenType::RParen, ")"},
      {TokenType::LBrace, "{"},    {TokenType::Return, "return"},
      {TokenType::True, "true"},   {TokenType::Semicolon, ";"},
      {TokenType::RBrace, "}"},    {TokenType::Else, "else"},
      {TokenType::LBrace, "{"},    {TokenType::Return, "return"},
      {TokenType::False, "false"}, {TokenType::Semicolon, ";"},
      {TokenType::RBrace, "}"},    {TokenType::Int, "10"},
      {TokenType::Eq, "=="},       {TokenType::Int, "10"},
      {TokenType::Semicolon, ";"}, {TokenType::Int, "10"},
      {TokenType::NotEq, "!="},    {TokenType::Int, "9"},
      {TokenType::Semicolon, ";"}, {TokenType::Eof, ""}};

  Lexer l{input};

  for (const Token& t : tests) {
    Token tok = l.nextToken();

    EXPECT_EQ(tok.type, t.type);
    EXPECT_EQ(tok.literal, t.literal);
  }
}
