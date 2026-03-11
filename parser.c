#include <stdio.h>
#include "parser.h"
#include "token.h"

size_t pos = 0;
Tokens *toks;
Token tok = {};

Token peek();
Token consume(TokenType type);
Inst mnemonic();
Inst half();

void parser(Tokens *tokens, Insts *ast) {
  toks = tokens;
  tok = tokens->items[0];

  while (pos < tokens->count) {
    switch (tok.type) {
      case HALF:
        inst_put(ast, half());
        break;
      default:
        inst_put(ast, mnemonic());
        break;
    }
  }
}

Token peek() {
  tok = toks->items[pos + 1];
  return toks->items[pos++];
}

Token consume(TokenType type) {
  if (tok.type == type) {
    return peek();
  }
}

Inst mnemonic() {
  Token mne = consume(MNEMONIC);
  Token reg = consume(REGISTER);

  consume(COMMA);

  short n = consume(NUMBER).n;

  Inst instruction = {
    .mne = mne,
    .reg = reg,
    .num = n
  };

  return instruction;
}

Inst half() {
  Token mne = consume(SYSCALL);

  Inst instruction = {
    .mne = mne
  };

  return instruction;
}

void inst_put(Insts *insts, Inst item){
  if (insts->count == insts->capacity) {
    insts->capacity += 8;

    insts->items = realloc(insts->items, sizeof(Inst[insts->capacity]));
  }

  insts->items[insts->count++] = item;
}
