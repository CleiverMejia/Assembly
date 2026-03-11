#ifndef TOKEN_H
#define TOKEN_H

#include <stdio.h>
#include <stdlib.h>

typedef enum {
  MNEMONIC,
  REGISTER,
  COMMA,
  NUMBER,
  WORD,
  HALF,
  SYSCALL
} TokenType;

typedef struct Token {
  TokenType type;
  union {
    char text[5];
    short n;
  };
} Token;

typedef struct Tokens {
  Token *items;
  size_t count;
  size_t capacity;
} Tokens;

void tk_put(Tokens *tokens, Token item);

#endif // !TOKEN_H
