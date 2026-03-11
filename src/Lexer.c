#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <Lexer.h>

static bool skip_whitespace(Lexer* lexer);
static char advance(Lexer* lexer);
static char peek(Lexer* lexer);
static bool at_end(Lexer* lexer);
static Token make_token(Lexer* lexer, TOKEN_TYPE type);

int main()
{
    Lexer myLexer;
    char input[256];
    
    (void)fgets(input, sizeof(input), stdin);
    // Cut input buffer
    input[255] = '\0';

    // Init lexer struct
    myLexer.input = malloc(sizeof(char) * 256);
    myLexer.index  = 0;
    myLexer.start  = 0;
    myLexer.end    = strlen(input);
    myLexer.line   = 0;
    myLexer.column = 0;

    // Get input buffer into lexer
    memcpy(myLexer.input, input, sizeof(input));

    // Initialize tokens
    Token token;
    token.length = 0;
    token.start = 0;
    token.type = ENUMERATION_SIZE;

    // Call lexer in loop until EOF
    do
    {
        token = next_token(&myLexer);
        printf("%s ", token_type_to_string(token.type));
    }
    while(token.type != TOKEN_EOF);

    return 0;
}

Token next_token(Lexer *lexer)
{
    if(at_end(lexer))
        return make_token(lexer, TOKEN_EOF);

    if(skip_whitespace(lexer))
        return make_token(lexer, TOKEN_EOF);

    lexer->start = lexer->index;
    char c = peek(lexer);

    if(isalpha(c))
    {
        while (isalpha(peek(lexer)) || isdigit(peek(lexer)) || peek(lexer) == '_')
            advance(lexer);

        int length = lexer->index - lexer->start;
        char buf[256];
        memcpy(buf, lexer->input + lexer->start, length);
        buf[length] = '\0';
        
        TOKEN_TYPE type = parse_keyword(buf);
        if(type == TOKEN_NONE)
            type = TOKEN_IDENTIFIER;

        return make_token(lexer, type);
    }
    else if(isdigit(c))
    {
        while(isdigit(peek(lexer)))
            advance(lexer);

        TOKEN_TYPE type = TOKEN_INT_LITERAL;
        if(peek(lexer) == '.')
        {
            advance(lexer);
            while(isdigit(peek(lexer)))
                advance(lexer);
            
            type = TOKEN_FLOAT_LITERAL;
        }

        return make_token(lexer, type);
    }

    // If no alpha/digit char is detected, advance lexer and check for keychar
    advance(lexer);
    return make_token(lexer, parse_keychar(c));
}

// Helpers
bool skip_whitespace(Lexer* lexer)
{
    if(!at_end(lexer))
    {
        while(isspace(lexer->input[lexer->index]))
            advance(lexer);
        return at_end(lexer);
    }

    return false;
}

char advance(Lexer* lexer)
{
    lexer->column++;
    if(lexer->input[lexer->index] == '\n')
    {
        lexer->line++;
        lexer->column = 0;
    }
    return lexer->input[lexer->index++];
}

char peek(Lexer* lexer)
{
    return lexer->input[lexer->index];
}

bool at_end(Lexer* lexer)
{
    return (lexer->index == lexer->end || lexer->input[lexer->index] == '\0') ? true : false;
}

Token make_token(Lexer* lexer, TOKEN_TYPE type)
{
    Token token;
    token.type = type;
    token.start = lexer->input + lexer->start;
    token.length = lexer->index - lexer->start;
    return token;
}