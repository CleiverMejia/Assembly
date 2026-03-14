#include <stdio.h>
#include <stdlib.h>
#include "lexer/lexer.h"
#include "structs/token.h"
#include "parser/parser.h"
#include "code/code.h"

int main(int argc, char const *argv[])
{
  Tokens tokens = {};
  Insts ast = {};

  lexer(argv[1], &tokens);
  parser(&tokens, &ast);
  code(&ast);

  return EXIT_SUCCESS;
}

/* for (size_t i = 0; i < tokens.count; i++) {
    printf("%lld. type: ", i+1);

    switch (tokens.items[i].type) {
      case MNEMONIC:
        printf("MNEMONIC, value: %s\n", tokens.items[i].text);
        break;
      case NUMBER:
        printf("NUMBER, value: %d\n", tokens.items[i].n);
        break;
      case COMMA:
        printf("COMMA, value: %s\n", tokens.items[i].text);
        break;
      case REGISTER:
        printf("REGISTER, value: %s\n", tokens.items[i].text);
        break;
      default:
        break;
    }
  } */