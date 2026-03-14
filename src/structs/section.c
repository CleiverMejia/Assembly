#include <stdio.h>
#include "section.h"

void sections_put(Section *sect, Inst item) {
  if (sect->count == sect->capacity) {
    sect->capacity += 8;

    sect->items = realloc(sect->items, sizeof(Inst[sect->capacity]));
  }

  sect->items[sect->count++] = item;
}
