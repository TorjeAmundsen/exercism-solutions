#include "binary.h"

int convert (const char *input)
{
    int out = 0;
    int i = 0;
    int len = 0;

    while (input[i] != '\0')
    {
        ++i;
        ++len;
        if (len > 32)
            return INVALID;
    }

    for (i = 0; i < len; ++i)
    {
        if (input[i] == '\0')
            break;
        if (input[i] == '1')
        {
            out = (1 << (len - i - 1)) | out;
        }
        else if (input[i] != '0')
        {
            return INVALID;
        }
    }
    return out;
}