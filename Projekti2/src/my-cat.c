#include <stdio.h>
#include <stdlib.h>

/* funktioiden esittelyt */
void tulostaTiedosto(FILE *pTiedosto);

/* pääohjelma */
int main(int argc, char *argv[]){
    FILE *pTiedosto = NULL;
    int i = 0;

    /* ei tiedostoja, lopeta */
    if(argc == 1){
        return(0);
    }

    /* käy tiedostot läpi */
    for(i = 1; i < argc; i++){

        /* avaa tiedosto */
        if((pTiedosto = fopen(argv[i], "r")) == NULL){
            fprintf(stderr, "my-cat: cannot open file\n");
            exit(1);
        }

        /* tulosta tiedosto */
        tulostaTiedosto(pTiedosto);

        /* sulje tiedosto */
        fclose(pTiedosto);
    }

    return(0);
}

/* Aliohjelmat */

/* tulostaa tiedoston sisällön */
void tulostaTiedosto(FILE *pTiedosto){
    char aRivi[4096];

    /* lue tiedosto rivi riviltä */
    while(fgets(aRivi, sizeof(aRivi), pTiedosto) != NULL)
    {
        printf("%s", aRivi);
    }

    return;
}