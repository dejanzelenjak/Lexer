#include <Tokenizer.h>

TOKEN_TYPE parse_keychar(const char keychar)
{
    TOKEN_TYPE result = TOKEN_NONE;
    switch (keychar)
    {
        case TOKEN_KEYCHAR_ADDITION:
            result = KEYCHAR_ADDITION;
            break;
        case TOKEN_KEYCHAR_SUBSTRACTION:
            result = KEYCHAR_SUBSTRACTION;
            break;
        case TOKEN_KEYCHAR_DIVISION:
            result = KEYCHAR_DIVISION;
            break;
        case TOKEN_KEYCHAR_MULTIPLICATION:
            result = KEYCHAR_MULTIPLICATION;
            break;
        case TOKEN_KEYCHAR_SEMICOLON:
            result = KEYCHAR_SEMICOLON;
            break;
        case TOKEN_KEYCHAR_START_PARANTHESIS:
            result = KEYCHAR_START_PARANTHESIS;
            break;
        case TOKEN_KEYCHAR_STOP_PARANTHESIS:
            result = KEYCHAR_STOP_PARANTHESIS;
            break;
        case TOKEN_KEYCHAR_START_SCOPE:
            result = KEYCHAR_START_SCOPE;
            break;
        case TOKEN_KEYCHAR_STOP_SCOPE:
            result = KEYCHAR_STOP_SCOPE;
            break;
        case TOKEN_KEYCHAR_COMMA:
            result = KEYCHAR_COMMA;
            break;
        case TOKEN_KEYCHAR_ASSIGNMENT:
            result = KEYCHAR_ASSIGNMENT;
            break;
    }

    return result;
}

TOKEN_TYPE parse_keyword(char const* keyword)
{
    TOKEN_TYPE result = TOKEN_NONE;

    if(strcmp("int", keyword) == 0)
        result = KEYWORD_INT;
    else if(strcmp("float", keyword) == 0)
        result = KEYWORD_FLOAT;
    else if(strcmp("return", keyword) == 0)
        result = KEYWORD_RETURN;

    return result;
}

const char* token_type_to_string(TOKEN_TYPE type)
{
    switch(type)
    {
        case TOKEN_NONE: return "TOKEN_NONE";
        case KEYWORD_INT: return "KEYWORD_INT";
        case KEYWORD_FLOAT: return "KEYWORD_FLOAT";
        case KEYWORD_RETURN: return "KEYWORD_RETURN";
        case KEYCHAR_ADDITION: return "KEYCHAR_ADDITION";
        case KEYCHAR_SUBSTRACTION: return "KEYCHAR_SUBSTRACTION";
        case KEYCHAR_DIVISION: return "KEYCHAR_DIVISION";
        case KEYCHAR_MULTIPLICATION: return "KEYCHAR_MULTIPLICATION";
        case KEYCHAR_SEMICOLON: return "KEYCHAR_SEMICOLON";
        case KEYCHAR_START_PARANTHESIS: return "KEYCHAR_START_PARANTHESIS";
        case KEYCHAR_STOP_PARANTHESIS: return "KEYCHAR_STOP_PARANTHESIS";
        case KEYCHAR_START_SCOPE: return "KEYCHAR_START_SCOPE";
        case KEYCHAR_STOP_SCOPE: return "KEYCHAR_STOP_SCOPE";
        case KEYCHAR_COMMA: return "KEYCHAR_COMMA";
        case KEYCHAR_ASSIGNMENT: return "KEYCHAR_ASSIGNMENT";
        case TOKEN_EOF: return "TOKEN_EOF";
        case TOKEN_ERROR: return "TOKEN_ERROR";
        case TOKEN_IDENTIFIER: return "TOKEN_IDENTIFIER";
        case TOKEN_INT_LITERAL: return "TOKEN_INT_LITERAL";
        case TOKEN_FLOAT_LITERAL: return "TOKEN_FLOAT_LITERAL";
        default: return "UNKNOWN";
    }
}