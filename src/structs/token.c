#include "token.h"

void tk_put(Tokens *tokens, Token item){
  if (tokens->count == tokens->capacity) {
    tokens->capacity += 8;

    tokens->items = realloc(tokens->items, sizeof(Token[tokens->capacity]));
  }

  tokens->items[tokens->count++] = item;
}
