#include "main.h"

/**
 * main - Main function to run a simple shell
 *
 * Return: Always 0
 */
int main(void)
{
    char buffer[BUFFER_SIZE];
    FILE *fp;
    char *input = NULL;
    size_t len = 0;
    ssize_t read;
    char *args[MAX_ARGS];
    char *token;
    int i;
    char *cmd_path;
    pid_t pid;
    int mode = 0;

    while (1) {
        if (mode == 0) {
            if (fgets(buffer, BUFFER_SIZE, stdin) != NULL) {
                buffer[strcspn(buffer, "\n")] = 0;
                fp = popen(buffer, "r");
                if (fp == NULL) {
                    perror("Error executing command");
                    exit(EXIT_FAILURE);
                }
                while (fgets(buffer, BUFFER_SIZE, fp) != NULL) {
                    printf("%s", buffer);
                }
                pclose(fp);
            } else {
                perror("Error reading command");
                exit(EXIT_FAILURE);
            }
        } else {
            write(STDOUT_FILENO, "\033[0;36mhsh# \033[0m", 16);
            read = getline(&input, &len, stdin);

            if (read < 2) {
                if (feof(stdin)) {
                    printf("\n");
                    break;
                } else {
                    perror("getline");
                    exit(EXIT_FAILURE);
                }
            }

            if (input[read - 1] == '\n') {
                input[read - 1] = '\0';
            }

            if (strcmp(input, "exit") == 0) {
                break;
            }

            token = strtok(input, " ");
            i = 0;
            while (token != NULL && i < MAX_ARGS - 1) {
                args[i] = token;
                token = strtok(NULL, " ");
                i++;
            }
            args[i] = NULL;

            cmd_path = find_command_path(args[0]);

            if (cmd_path == NULL) {
                printf("%s: command not found\n", args[0]);
            } else {
                pid = fork();
                if (pid == -1) {
                    perror("Fork failed");
                    exit(EXIT_FAILURE);
                } else if (pid == 0) {
                    if (execve(cmd_path, args, NULL) == -1) {
                        printf("%s: command not found\n", input);
                        exit(EXIT_FAILURE);
                    }
                } else {
                    wait(NULL);
                }
            }
        }
    }

    free(input);
    return 0;
}
