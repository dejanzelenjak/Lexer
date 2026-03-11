#ifndef LEXER_H
#define LEXER_H

#include <Tokenizer.h>

typedef struct
{
    char* input;
    int index;
    int start;
    int end;
    int line;
    int column;
}Lexer;

Token next_token(Lexer *lexer);

#endif