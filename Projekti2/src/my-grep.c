#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* funktioiden esittelyt */
void etsiRivit(FILE *pTiedosto, char *pHakusana);

/* pääohjelma */
int main(int argc, char *argv[])
{
    FILE *pTiedosto = NULL;
    int i = 0;

    /* tarkista argumentit */
    if(argc < 2){
        fprintf(stderr, "my-grep: searchterm [file ...]\n");
        exit(1);
    }

    /* ei tiedostoja, lue stdin */
    if(argc == 2){
        etsiRivit(stdin, argv[1]);
        return(0);
    }

    /* käy tiedostot läpi */
    for(i = 2; i < argc; i++){

        /* avaa tiedosto */
        if((pTiedosto = fopen(argv[i], "r")) == NULL){
            fprintf(stderr, "my-grep: cannot open file\n");
            exit(1);
        }

        /* etsi hakusanaa */
        etsiRivit(pTiedosto, argv[1]);

        fclose(pTiedosto);
    }

    return(0);
}

/* Aliohjelmat */

/* tulostaa hakusanan sisältävät rivit */
void etsiRivit(FILE *pTiedosto, char *pHakusana)
{
    char *pRivi = NULL;
    size_t iPituus = 0;

    /* lue rivi kerrallaan */
    while(getline(&pRivi, &iPituus, pTiedosto) != -1){

        /* tarkista hakusana */
        if(strstr(pRivi, pHakusana) != NULL){
            printf("%s", pRivi);

            /* lisää rivinvaihto */
            if(strchr(pRivi, '\n') == NULL){
                printf("\n");
            }
        }
    }

    /* vapauta puskuri */
    free(pRivi);

    return;
}