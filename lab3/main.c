#define ERROR_EXIT -1

#include <stdlib.h>
#include <string.h>
#include "invert.h"

int main(int argc, char* argv[]) {
    if (argc < 2 || argc > 3) {
        printf("Wrong number of arguments.\n");
        return ERROR_EXIT;
    }
    
    char* input_file_name = argv[1];
    char* output_file_name;
    if (argc == 3) {
        output_file_name = argv[2];
    }
    else {
        output_file_name = "output.txt";
    }

    FILE* input_file = fopen(input_file_name, "r");
    if (input_file == NULL) {
        printf("Can't open input file.\n");
        return ERROR_EXIT;
    }

    FILE* output_file = fopen(output_file_name, "w");
    if (output_file == NULL) {
        printf("Can't open output file.\n");
        fclose(input_file);
        return ERROR_EXIT;
    }

    char* line = (char*)malloc(MAX_STRING_LENGTH * sizeof(char));
    if (line == NULL) {
        printf("Can't allocate memory.\n");
        fclose(input_file);
        fclose(output_file);
        return ERROR_EXIT;
    }

    while (fgets(line, MAX_STRING_LENGTH, input_file) != NULL) {
        if (strlen(line) > 0) {
            if (line[strlen(line) - 1] == '\n') {
                line[strlen(line) - 1] = '\0';
                invert_string(line);
                fputs(line, output_file);
                fputs("\n", output_file);
            }
            else {
                invert_string(line);
                fputs(line, output_file);
            }
        }
    }

    fclose(input_file);
    fclose(output_file);
    free(line);
    return 0;
}
