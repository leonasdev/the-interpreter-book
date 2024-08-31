#include "parser.hpp"

#include <gtest/gtest.h>

#include <string>

#include "ast.hpp"
#include "lexer.hpp"

void testLetStatement(IStatement* stmt, std::string name) {
  EXPECT_EQ(stmt->tokenLiteral().compare("let"), 0)
      << "statement.tokenLiteral not \"let\". got: " << stmt->tokenLiteral();

  EXPECT_EQ(typeid(*stmt), typeid(LetStatement)) << "stmt is not LetStatement.";
  LetStatement* letStmt = dynamic_cast<LetStatement*>(stmt);
  EXPECT_EQ(letStmt->name->value, name);
  EXPECT_EQ(letStmt->tokenLiteral(), name);
}

TEST(TestParser, TestLetStatements) {
  std::string input = R"(let x = 5;
let y = 10;
let foobar = 838383;
)";

  Lexer lexer{input};
  Parser parser{&lexer};
  Program* program = parser.ParseProgarm();

  ASSERT_NE(program, nullptr);
  EXPECT_EQ(program->statements.size(), 3);

  std::vector<std::string> tests{"x", "y", "foobar"};

  int i = 0;
  for (std::string tt : tests) {
    IStatement* stmt = program->statements[i];
    testLetStatement(stmt, tt);
    i++;
  }
}
