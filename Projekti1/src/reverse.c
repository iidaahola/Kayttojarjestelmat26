#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Funktioiden esittelyt */
char **lueRivit(FILE *pInput, size_t *pLkm);
void kirjoitaRivit(FILE *pOutput, char **ppRivit, size_t iLkm);
void vapautaRivit(char **ppRivit, size_t iLkm);

/* Pääohjelma */
int main(int argc, char *argv[])
{
    FILE *pInput = stdin;
    FILE *pOutput = stdout;

    char **ppRivit = NULL;
    size_t iLkm = 0;

    /* tarkista argumentit */
    if(argc > 3){
        fprintf(stderr, "usage: reverse <input> <output>\n");
        exit(1);
    }

    /* input ja output eivät saa olla sama tiedosto */
    if(argc == 3 && strcmp(argv[1], argv[2]) == 0){
        fprintf(stderr, "Input and output file must differ\n");
        exit(1);
    }

    /* avaa input tiedosto */
    if(argc >= 2){
        if((pInput = fopen(argv[1], "r")) == NULL)
        {
            fprintf(stderr, "error: cannot open file '%s'\n", argv[1]);
            exit(1);
        }
    }

    /* avaa output tiedosto */
    if(argc == 3){
        if((pOutput = fopen(argv[2], "w")) == NULL)
        {
            fprintf(stderr, "error: cannot open file '%s'\n", argv[2]);

            if(pInput != stdin)
            {
                fclose(pInput);
            }

            exit(1);
        }
    }

    ppRivit = lueRivit(pInput, &iLkm); /* luetaan kaikki rivit muistiin */
    kirjoitaRivit(pOutput, ppRivit, iLkm); /* tulostetaan rivit käänteisessä järjestyksessä */
    vapautaRivit(ppRivit, iLkm); /* vapautetaan varattu muisti */

    /* suljetaan tiedostot */
    if(pInput != stdin){
        fclose(pInput);
    }

    if(pOutput != stdout){
        fclose(pOutput);
    }

    return(0);
}

/* Aliohjelmat */

/* lueRivit() lukee tiedoston rivit dynaamiseen taulukkoon.
 * jokainen taulukon alkio sisältää yhden rivin.
 */
char **lueRivit(FILE *pInput, size_t *pLkm)
{
    char **ppRivit = NULL;
    char *pRivi = NULL;

    size_t iPituus = 0;
    size_t iKoko = 10;

    /* varataan alkuperäinen tila riveille */
    if((ppRivit = malloc(iKoko * sizeof(*ppRivit))) == NULL){
        fprintf(stderr, "malloc failed\n");
        exit(1);
    }

    /* luetaan rivejä yksi kerrallaan */
    while(getline(&pRivi, &iPituus, pInput) != -1){
        /* kasvatetaan taulukkoa tarvittaessa */
        if(*pLkm == iKoko){
            char **ppUusi = NULL;

            iKoko *= 2;

            ppUusi = realloc(ppRivit, iKoko * sizeof(*ppRivit));

            if(ppUusi == NULL)
            {
                fprintf(stderr, "malloc failed\n");
                exit(1);
            }

            ppRivit = ppUusi;
        }

        /* varataan muistia yksittäiselle riville */
        ppRivit[*pLkm] = malloc(strlen(pRivi) + 1);

        if(ppRivit[*pLkm] == NULL){
            fprintf(stderr, "malloc failed\n");
            exit(1);
        }

        strcpy(ppRivit[*pLkm], pRivi); /* kopioidaan luettu rivi omaan muistiin */
        (*pLkm)++; /* kasvatetaan tallennettujen rivien määrää */

    }

    /* vapautetaan getline-funktion käyttämä puskuri */
    free(pRivi);
    return(ppRivit);
}

/* kirjoitaRivit() tulostaa rivit käänteisessä järjestyksessä
 */
void kirjoitaRivit(FILE *pOutput, char **ppRivit, size_t iLkm){
    int i = 0;

    /* käydään taulukko lopusta alkuun */
    for(i = (int)iLkm - 1; i >= 0; i--)
    {
        fprintf(pOutput, "%s", ppRivit[i]);

        if(strchr(ppRivit[i], '\n') == NULL){
            fprintf(pOutput, "\n");
        }
    }

    return;
}

/* vapautaRivit() vapauttaa kaikki dynaamisesti varatut muistialueet
 */
void vapautaRivit(char **ppRivit, size_t iLkm){
    size_t i = 0;

    /* vapautetaan jokainen yksittäinen rivi */
    for(i = 0; i < iLkm; i++)
    {
        free(ppRivit[i]);
    }

    /* vapautetaan rivien osoitintaulukko */
    free(ppRivit);

    return;
}