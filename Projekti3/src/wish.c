#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/* pääohjelma */
int main(int argc, char *argv[])
{
    char *pRivi = NULL;
    size_t iKoko = 0;

    /* tarkista argumentit */
    if (argc > 2) {
        fprintf(stderr, "An error has occurred\n");
        exit(1);
    }

    /* interaktiivinen tila */
    while (1) {
        printf("wish> ");
        fflush(stdout);

        if (getline(&pRivi, &iKoko, stdin) == -1) {
            free(pRivi);
            exit(0);
        }

        pRivi[strcspn(pRivi, "\n")] = '\0';

        /* exit */
        if (strcmp(pRivi, "exit") == 0) {
            free(pRivi);
            exit(0);
        }

        /* pilko komentorivi argumenteiksi */
        char *pArgumentit[100];
        int i = 0;

        char *pToken = strtok(pRivi, " \t");

        while (pToken != NULL) {
            pArgumentit[i++] = pToken;
            pToken = strtok(NULL, " \t");
        }

        pArgumentit[i] = NULL;

        /* tyhjä rivi */
        if (pArgumentit[0] == NULL) {
            continue;
        }

        /* cd */
        if (strcmp(pArgumentit[0], "cd") == 0) {

            if (i != 2) {
                fprintf(stderr, "An error has occurred\n");
                continue;
            }

            if (chdir(pArgumentit[1]) != 0) {
                fprintf(stderr, "An error has occurred\n");
            }

            continue;
        }

        /* rakenna polku */
        char cPolku[256];

        snprintf(cPolku, sizeof(cPolku), "/bin/%s", pArgumentit[0]);

        if (access(cPolku, X_OK) != 0) {
            fprintf(stderr, "An error has occurred\n");
            continue;
        }

        /* lapsiprosessi */
        pid_t pid = fork();

        if (pid == 0) {

            execv(cPolku, pArgumentit);

            fprintf(stderr, "An error has occurred\n");
            exit(1);

        } else {

            waitpid(pid, NULL, 0);

        }
    }

    free(pRivi);
    return 0;
}