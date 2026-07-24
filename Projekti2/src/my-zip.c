#include <stdio.h>
#include <stdlib.h>

/* funktioiden esittelyt */
void pakkaaTiedosto(FILE *pTiedosto);

/* pääohjelma */
int main(int argc, char *argv[]){
    FILE *pTiedosto = NULL;
    int i = 0;

    /* tarkista argumentit */
    if(argc < 2){
        fprintf(stderr, "my-zip: file1 [file2 ...]\n");
        exit(1);
    }

    /* käy tiedostot läpi */
    for(i = 1; i < argc; i++){

        /* avaa tiedosto */
        if((pTiedosto = fopen(argv[i], "r")) == NULL){
            fprintf(stderr, "my-zip: cannot open file\n");
            exit(1);
        }

        /* pakkaa tiedosto */
        pakkaaTiedosto(pTiedosto);

        /* sulje tiedosto */
        fclose(pTiedosto);
    }

    return(0);
}

/* Aliohjelmat */

/* pakkaa tiedoston sisältö */
void pakkaaTiedosto(FILE *pTiedosto){
    int cMerkki = 0;
    int cEdellinen = EOF;
    int iLkm = 0;

    /* lue merkki kerralla */
    while((cMerkki = fgetc(pTiedosto)) != EOF){

        /* ensimmäinen merkki */
        if(cEdellinen == EOF){
            cEdellinen = cMerkki;
            iLkm = 1;
        }

        /* sama merkki*/
        else if(cMerkki == cEdellinen){
            iLkm++;
        }

        /* merkki vaihto */
        else{
            fwrite(&iLkm, sizeof(int), 1, stdout);
            fwrite(&cEdellinen, sizeof(char), 1, stdout);

            cEdellinen = cMerkki;
            iLkm = 1;
        }
    }

    /* kirjoita viimeinen jakso */
    if(iLkm > 0){
        fwrite(&iLkm, sizeof(int), 1, stdout);
        fwrite(&cEdellinen, sizeof(char), 1, stdout);
    }

    return;
}