#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "lexer.h"
#include "../structs/token.h"

bool isLetter(char *character);
bool isNumber(char *character);

void lexer(const char *path, Tokens *tokens)
{
  FILE *file = fopen(path, "r");

  if (file == NULL)
  {
    printf("Error opening file\n");
    return;
  }

  char c = fgetc(file);
  char text[5] = {0};
  Token tok = {};

  while (c != EOF)
  {
    for (size_t i = 0; i < 5; i++)
    {
      text[i] = '\0';
    }

    if (c == '#') // Comentarios
      while (c != '\n')
        c = fgetc(file);

    if (isLetter(&c))
    {
      for (size_t i = 0; i < 5; i++)
      {
        if (!isLetter(&c))
          break;

        text[i] = c;
        c = fgetc(file);
      }

      // printf("Palabra: %s\n", text);

      if (strcmp(text, "sect") == 0)
      {
        /* code */
      }
      

      if (strcmp(text, "a") == 0 ||
          strcmp(text, "b") == 0 ||
          strcmp(text, "c") == 0 ||
          strcmp(text, "d") == 0)
        tok.type = REGISTER;
      else
        tok.type = MNEMONIC;

      for (size_t i = 0; i < 5; i++)
        tok.text[i] = text[i];

      tk_put(tokens, tok);
      continue;
    }

    if (isNumber(&c))
    {
      for (size_t i = 0; i < 5; i++)
      {
        if (!isNumber(&c))
          break;

        text[i] = c;
        c = fgetc(file);
      }

      // printf("Numero: %s\n", text);
      tok.type = NUMBER;
      tok.n = atoi(text);

      tk_put(tokens, tok);
      continue;
    }

    if (c == '\'')
    {
      c = fgetc(file);

      tok.type = NUMBER;
      tok.n = c;

      c = fgetc(file);

      tk_put(tokens, tok);
    }

    if (c == ',')
    {
      // printf("Coma: ,\n");
      tok.type = COMMA;
      tok.text[0] = c;

      tk_put(tokens, tok);
    }

    c = fgetc(file);
  }

  fclose(file);
}

bool isLetter(char *character)
{
  return *character >= 0x61 && *character <= 0x79;
}

bool isNumber(char *character)
{
  return *character >= 0x30 && *character <= 0x39;
}
