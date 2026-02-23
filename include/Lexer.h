#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

typedef struct
{
    char* input;
    int index;
    int start;
    int end;
    int line;
    int column;
}Lexer;