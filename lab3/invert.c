#include <stdio.h>
#include <string.h>
#include "invert.h"

void invert_string(char* string) {
    for (int i = 0; i < strlen(string) / 2; i++) {
        char tmp = string[i];
        string[i] = string[strlen(string) - i - 1];
        string[strlen(string) - i - 1] = tmp;
    }
}
