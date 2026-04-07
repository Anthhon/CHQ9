#ifndef MAIN_H_
#define MAIN_H_

#define FLAG_ARG_FILE "-f"
#define FLAG_ARG_FILE_LENGTH (sizeof(FLAG_ARG_FILE) - 1)
#define FLAG_ARG_CODE "-c"
#define FLAG_ARG_CODE_LENGTH (sizeof(FLAG_ARG_CODE) - 1)

void code_interpret(char *code);
void read_from_file(char *filename);
void print_usage(const char* program_name);

#endif // MAIN_H_

