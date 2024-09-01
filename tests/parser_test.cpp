#include "parser.hpp"

#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "ast.hpp"
#include "lexer.hpp"

void testLetStatement(IStatement* stmt, std::string name) {
  EXPECT_EQ(stmt->tokenLiteral().compare("let"), 0)
      << "statement.tokenLiteral not \"let\". got: " << stmt->tokenLiteral();

  EXPECT_EQ(typeid(*stmt), typeid(LetStatement)) << "stmt is not LetStatement.";
  LetStatement* letStmt = dynamic_cast<LetStatement*>(stmt);
  EXPECT_EQ(letStmt->name->value, name);
  EXPECT_EQ(letStmt->name->tokenLiteral(), name);
}

bool checkParserErrors(Parser* parser) {
  std::vector<std::string> errors = parser->getErrors();
  if (errors.empty()) {
    return true;
  }

  ADD_FAILURE() << "parser has " << errors.size() << " errors";

  for (std::string error : errors) {
    ADD_FAILURE() << "parser error: " << error;
  }

  return false;
}

TEST(TestParser, TestLetStatements1) {
  std::string input = R"(let x = 5;
let y = 10;
let foobar = 838383;
)";

  Lexer lexer{input};
  Parser parser{&lexer};
  Program* program = parser.parseProgarm();

  ASSERT_NE(program, nullptr);
  EXPECT_EQ(program->statements.size(), 3);

  std::vector<std::string> expectedIdentifiers{"x", "y", "foobar"};

  int i = 0;
  for (std::string tt : expectedIdentifiers) {
    IStatement* stmt = program->statements[i];
    testLetStatement(stmt, tt);
    i++;
  }
}

TEST(TestParser, TestLetStatements2) {
  std::string input = R"(let x 5;
let = 10;
let 838383;
)";

  Lexer lexer{input};
  Parser parser{&lexer};
  Program* program = parser.parseProgarm();
  if (!checkParserErrors(&parser)) {
    FAIL();
  }

  ASSERT_NE(program, nullptr);
  EXPECT_EQ(program->statements.size(), 3);

  std::vector<std::string> expectedIdentifiers{"x", "y", "foobar"};

  int i = 0;
  for (std::string tt : expectedIdentifiers) {
    IStatement* stmt = program->statements[i];
    testLetStatement(stmt, tt);
    i++;
  }
}
