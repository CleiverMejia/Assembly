#include "code.h"
#include "../parser/parser.h"
#include <stdio.h>
#include <string.h>

void code(Insts *ast) {
  FILE *output = fopen("./output/a.bin", "w");
  char byte = 0;

  for (size_t i = 0; i < ast->count; i++)
  {
    char *text = ast->items[i].mne.text;

    //printf("%s\n", text);

    if (strcmp(text, "half") == 0)  {
      byte = 0x0A;
      fputc(byte, output);

      printf("0x%x\n", byte);
      continue;
    }

    if (strcmp(text, "sys") == 0)  {
      byte = 0x0B;
      fputc(byte, output);

      printf("0x%x\n", byte);
      continue;
    }

    if (strcmp(text, "je") == 0)  {
      byte = 0x18;
      fputc(byte, output);

      printf("0x%x\n", byte);
      continue;
    }

    if (strcmp(text, "load") == 0) byte = 0x00;
    if (strcmp(text, "store") == 0) byte = 0x04;
    if (strcmp(text, "add") == 0) byte = 0x0C;
    if (strcmp(text, "sub") == 0) byte = 0x10;
    if (strcmp(text, "cmp") == 0) byte = 0x14;
    if (strcmp(text, "lea") == 0) byte = 0x1C;

    short n = ast->items[i].num;
    byte += ast->items[i].reg.text[0] - 'a'; // 

    printf("0x%x\n", byte);
    printf("0x%x\n", n);
    printf("0x%x\n", n >> 8);

    fputc(byte, output);
    fputc(n, output);
    fputc(n >> 8, output);
  }

  fclose(output);
}