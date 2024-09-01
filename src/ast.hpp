#pragma once

#include <string>
#include <vector>

#include "token.hpp"
class INode {
 public:
  virtual ~INode() {};
  virtual std::string tokenLiteral() = 0;
};

class IStatement : public INode {
 public:
  ~IStatement() {};
  virtual std::string tokenLiteral() = 0;
};

class IExpression : public INode {
 public:
  ~IExpression() {};
  virtual std::string tokenLiteral() = 0;
};

class Program : INode {
 public:
  ~Program();
  std::string tokenLiteral() override;

  std::vector<IStatement*> statements;
};

class Identifier : public IExpression {
 public:
  Identifier(Token token, std::string value);
  std::string tokenLiteral() override;

  Token token;
  std::string value;
};

class LetStatement : public IStatement {
 public:
  ~LetStatement() {
    delete name;
    delete value;
  };
  std::string tokenLiteral() override;

  Token token;
  Identifier* name;
  IExpression* value;
};
