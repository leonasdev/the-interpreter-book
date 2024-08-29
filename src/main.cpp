#include <unistd.h>

#include <cstdlib>
#include <iostream>
#include <string>

#include "lexer.hpp"
#include "token.hpp"

int main() {
  std::cout << "Hello " << getenv("USER")
            << "! This is Monkey programming langueage!" << std::endl;
  std::cout << "Feel free to type in commands\n" << std::endl;

  for (;;) {
    std::cout << ">> ";
    std::string input;
    std::getline(std::cin, input);
    Lexer l = {input};
    for (Token tok = l.nextToken(); tok.type != TokenType::Eof;
         tok = l.nextToken()) {
      std::cout << tok << std::endl;
    }
  }
  return 0;
}
