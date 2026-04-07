#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

/* Windows-specific adjustments */
#ifdef _WIN32
    #define WIN32_LEAN_AND_MEAN
    #include <windows.h>
    /* For ftell compatibility with large files on Windows */
    #define fseek _fseeki64
    #define ftell _ftelli64
    /* Windows doesn't have long long printf specifier consistently, use long */
    typedef long file_offset_t;
#else
    typedef long file_offset_t;
#endif

void code_interpret(char *code)
{
    char* entire_code = code;
    int accum = 0;
    while (*code) {
        char curr_char = *code;
        switch (curr_char) {
            case 'H': // print 'hello world'
                fprintf(stdout, "Hello, World!\n");
                break;
            case 'Q': // print entire source code of itself
                fprintf(stdout, "%s\n", entire_code);
                break;
            case '9': // print '99 bottles' lyrics
                for (int i = 99; i >= 0; --i) {
                    fprintf(stdout, "%i bottles of beer on the wall\n", i);
                }
                break;
            case '+': // increases accumulator
                ++accum;
                break;
            case ' ': case '\n': case '\t': // ignores spaces, newlines e tabs
                break;
            default: // deals with invalid input
                fprintf(stderr, "[ERROR] Invalid output from code\n");
                exit(EXIT_FAILURE);
                break;
        }
        ++code;
    }
}

void read_from_file(char *filename)
{
    FILE* fp = fopen(filename, "rb"); /* "rb" for Windows binary mode */
    if (!fp) {
        fprintf(stderr, "[ERROR] Could not open '%s' file\n", filename);
        exit(EXIT_FAILURE);
    }
    
    /* Get file size in a cross-platform way */
#ifdef _WIN32
    _fseeki64(fp, 0, SEEK_END);
    long long file_size = _ftelli64(fp);
#else
    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
#endif
    
    char* buffer = malloc(sizeof(*buffer) * (size_t)file_size + 1);
    if (!buffer) {
        fprintf(stderr, "[ERROR] Could not allocate memory to '%s' file\n", filename);
        fclose(fp);
        exit(EXIT_FAILURE);
    }
    
    rewind(fp);
    size_t len = fread(buffer, 1, (size_t)file_size, fp);
    buffer[len] = '\0';
    fclose(fp);
    
    code_interpret(buffer);
    free(buffer);
}

void print_usage(const char* program_name)
{
    fprintf(stderr, "Usage: %s [OPTIONS] [INPUT]\n", program_name);
    fprintf(stderr, "Options:\n");
    fprintf(stderr, "  " FLAG_ARG_FILE " <file>    Read code from file\n");
    fprintf(stderr, "  " FLAG_ARG_CODE " <code>    Execute inline code\n");
    fprintf(stderr, "  -h, --help   Show this help message\n");
    fprintf(stderr, "\nExamples:\n");
    fprintf(stderr, "  %s " FLAG_ARG_FILE " program.hq9\n", program_name);
    fprintf(stderr, "  %s " FLAG_ARG_CODE " HHQ9Q\n", program_name);
}

int main(int argc, char** argv)
{
    /* Check for input */
    char* program_name = argv[0];
    if (argc < 2 || argc > 3) {
        print_usage(program_name);
        exit(EXIT_SUCCESS);
    }

    /* Check for valid option */
    if (strncmp(FLAG_ARG_CODE, argv[1], FLAG_ARG_CODE_LENGTH) == 0 && argc == 3) {
        /* '-c' input */
        code_interpret(argv[2]);
    } else if (strncmp(FLAG_ARG_FILE, argv[1], FLAG_ARG_FILE_LENGTH) == 0 && argc == 3) {
        /* '-f' input */
        read_from_file(argv[2]);
    } else {
        print_usage(program_name);
    }
    
    return 0;
}
