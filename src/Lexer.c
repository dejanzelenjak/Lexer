#include <Lexer.h>
#include <Tokenizer.h>

static void skip_whitespace(Lexer* lexer);
static char advance(Lexer* lexer);
static char peek(Lexer* lexer);
static bool at_end(Lexer* lexer);
static Token make_token(Lexer* lexer, TOKEN_TYPE type);

int main()
{
    printf("Hello World\n");
    fflush(stdout);
}

Token next_token(Lexer *lexer)
{
    skip_whitespace(lexer);

    if(at_end(lexer))
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
        
        TOKEN_TYPE type = parse_str_into_token(buf, length);
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

    return make_token(lexer, parse_keychar(c));
}

// Helpers
void skip_whitespace(Lexer* lexer)
{
    if(lexer->input[lexer->index] == ' ')
        lexer->index++;
}

char advance(Lexer* lexer)
{
    lexer->column++;
    if(lexer->input[lexer->index] == '\n')
        lexer->line++;
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