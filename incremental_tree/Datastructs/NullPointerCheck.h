#include <stdlib.h>
#include <stdio.h>

void NullPointerCheck(void* check, const char* function_name) {
    if (check == NULL) {
        fprintf(stderr, "Allocation failed in: %s", function_name);
        exit(1);
    }
}