#ifndef INSTS_H
#define INSTS_H

#include "../lexer/lexer.h"

typedef struct Inst {
  Token mne;
  Token reg;
  short num;
} Inst;

typedef struct Section {
  Inst *items;
  size_t count;
  size_t capacity;
} Section;

void sections_put(Section *sect, Inst item);

#endif