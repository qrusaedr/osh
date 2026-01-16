#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

#define INPUT_BUFFER 512
#define MAX_ARGS 64

void init_shell();
int tokenize_cmd(char *buf[], char *input);
void exec_process(const char *cmd[]);

int main() {
    init_shell();
    return 0;
}

// init_shell when called starts an infinite loop, prompt the user
// and waits for users input.
void init_shell() {
    const size_t buffer_size = INPUT_BUFFER;
    while (true) {
        char input[buffer_size];
        char *command[MAX_ARGS];

        printf("$: "); // prompt
        fgets(input, buffer_size, stdin);

        // remove newline from input
        size_t input_len = strlen(input);
        input[input_len - 1] = '\0';

        int token_len;
        token_len = tokenize_cmd(command, input); // tokenize command

        // print command tokens to stdout
        for (int i = 0; i < token_len - 1; i++) {
            printf("%s\n", command[i]);
        }

    }
}

/* tokenize_cmd breaks input strings into an array of tokens.
 * NULL pointer is appended to the end of the array
*/
int tokenize_cmd(char *buf[], char *input) {
    const char *delim = " ";
    char *token =  strtok((char *)input, delim);

    int i = 0;
    while (token != NULL) {
        buf[i] = token;
        token = strtok(NULL, delim);
        i++;
    }

    buf[i++] = NULL;
    return i;
}

/*
 * Creates and Replaces the new process with cmd specifies in cmd
 * cmd is a NULL terminated array where cmd[0] is the program name
 */
void exec_process(const char *cmd[]) {

}