#include <stdio.h>
#include <stdlib.h>

/* funktioiden esittelyt */
void puraTiedosto(FILE *pTiedosto);

/* pääohjelma */
int main(int argc, char *argv[]){
    FILE *pTiedosto = NULL;
    int i = 0;

    /* tarkista argumentit */
    if(argc < 2){
        fprintf(stderr, "my-unzip: file1 [file2 ...]\n");
        exit(1);
    }

    /* käy tiedostot läpi */
    for(i = 1; i < argc; i++){

        /* avaa tiedosto */
        if((pTiedosto = fopen(argv[i], "rb")) == NULL){
            fprintf(stderr, "my-unzip: cannot open file\n");
            exit(1);
        }

        /* pura tiedosto */
        puraTiedosto(pTiedosto);

        /* sulje tiedosto */
        fclose(pTiedosto);
    }

    return(0);
}

/* Aliohjelmat*/

/* purkaa pakatun tiedoston */
void puraTiedosto(FILE *pTiedosto)
{
    int iLkm = 0;
    char cMerkki = '\0';
    int i = 0;

    /* lue yksi pakkausjakso kerrallaan */
    while(fread(&iLkm, sizeof(int), 1, pTiedosto) == 1){

        if(fread(&cMerkki, sizeof(char), 1, pTiedosto) != 1){
            break;
        }

        /* tulosta merkki iLkm kertaa */
        for(i = 0; i < iLkm; i++){
            printf("%c", cMerkki);
        }
    }

    return;
}