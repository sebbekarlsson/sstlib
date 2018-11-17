#include <string.h>
#include <ctype.h>


int ss_is_int(char* str) {
    int i = 0;

    if (str[0] == '-' || str[0] == '+')
        i++; // skip one char

    for (;i < strlen(str); i++)
        if (!isdigit(str[i]))
            return 0;

    return 1;
};
