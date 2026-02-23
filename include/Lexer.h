
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