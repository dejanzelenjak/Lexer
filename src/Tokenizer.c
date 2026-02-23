#include <Tokenizer.h>

TOKEN_TYPE parse_str_into_token(char const* element, int len)
{
    TOKEN_TYPE result_token = TOKEN_NONE;

    if(len > 1)
    {
        result_token = parse_keyword(element);
    }
    else
    {
        char single_element = element[0];
        result_token = parse_keychar(single_element);
    }

    return result_token;
}

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
        case TOKEN_KEYCHAR_COMMA:
            result = KEYCHAR_COMMA;
            break;
        case KEYCHAR_ASSIGNMENT:
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