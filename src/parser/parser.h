#ifndef PARSER_H
#define PARSER_H

#include "../structs/token.h"

typedef struct Inst {
  Token mne;
  Token reg;
  short num;
} Inst;

typedef struct Insts {
  Inst *items;
  size_t count;
  size_t capacity;
} Insts;

void inst_put(Insts *insts, Inst item);
void parser(Tokens *tokens, Insts *insts);

#endif // !PARSER_H
