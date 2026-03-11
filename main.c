#include <stdio.h>
#include <stdlib.h>
#include "lexer.h"
#include "token.h"
#include "parser.h"
#include "code.h"

int main()
{
  Tokens tokens = {};
  Insts ast = {};

  lexer("test.asm", &tokens);
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