#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

        /* tulosta kehote */
        printf("wish> ");
        fflush(stdout);

        /* lue käyttäjän syöte */
        if (getline(&pRivi, &iKoko, stdin) == -1) {
            free(pRivi);
            exit(0);
        }

        /* poista rivinvaihto */
        pRivi[strcspn(pRivi, "\n")] = '\0';

        /* exit lopettaa ohjelman */
        if (strcmp(pRivi, "exit") == 0) {
            free(pRivi);
            exit(0);
        }
    }

    return 0;
}