#define _POSIX_C_SOURCE 200809L
#define EXIT_COMMAND -100
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <limits.h>

/* virheilmoitus */
char error_message[] = "An error has occurred\n";

void error(void)
{
    write(STDERR_FILENO, error_message, strlen(error_message));
}

/* Komennon suorittaminen */

pid_t suorita_komento(char *pKomento, char *pPolut[], int *iPolkuLkm){
    /* taulukko komentorivin argumenteille */
    char *pArgumentit[100];
    int i = 0;

    /* osoitin */
    char *pTallennus2 = NULL;

    char *pToken = strtok_r(pKomento, " \t", &pTallennus2);

    /* lue argumentit taulukkoon */
    while (pToken != NULL)
    {
        /* taulukko ei saa ylittyä*/
        if (i >= 99) {
            error();
            return -1;
        }

        pArgumentit[i++] = pToken;
        pToken = strtok_r(NULL, " \t", &pTallennus2);
    }

    pArgumentit[i] = NULL;

    /* ohita tyhjät rivi */
    if (pArgumentit[0] == NULL) {
        return -1;
    }

    /* exit */
    if (strcmp(pArgumentit[0], "exit") == 0) {

        /* ei ota argumentteja */
        if (i != 1) {
            error();
            return -1;
        }

        return EXIT_COMMAND;
    }

    /* cd */
    if (strcmp(pArgumentit[0], "cd") == 0) {

        /* yksi argumentti */
        if (i != 2) {
            error();
            return -1;
        }

        /* vaihda hakemisto */
        if (chdir(pArgumentit[1]) != 0) {
            error();
        }

        return -1;
    }

    /* tarkista redirection */
    char *pTiedosto = NULL;
    int iNuoli = -1;
    int virhe = 0;

    /* etsi > argumenteista */
    for (int j = 0; j < i; j++) {

        if (strcmp(pArgumentit[j], ">") == 0) {

            /* enemmän kuin yksi > */
            if (iNuoli != -1) {
                error();
                virhe = 1;
                break;
            }

            iNuoli = j; /* tallenna sijainti */
        }
    }

    if (virhe) {
        return -1;
    }

    /* path */
    if (strcmp(pArgumentit[0], "path") == 0) {

        /* polkujen enimmäismäärä */
        if (i - 1 >= 100) {
            error();
            return -1;
        }

        /* vapauta vanhat polut */
        for (int j = 0; j < *iPolkuLkm; j++) {
            if (pPolut[j] != NULL)
                free(pPolut[j]);
        }

        *iPolkuLkm = i - 1; /* päivitä polkujen määrä */

        /* kopioi uudet polut */
        for (int j = 0; j < *iPolkuLkm; j++) {
            pPolut[j] = strdup(pArgumentit[j + 1]);

            if (pPolut[j] == NULL) {
                error();
                return -1;
            }
        }

        return -1;
    }

    /* jos rivillä on uudelleenohjaus */
    if (iNuoli != -1) {

        /* muodon oltava: cmd > tiedosto */
        if (iNuoli == 0 || iNuoli != i - 2) {
            error();
            return -1;
        }

        pTiedosto = pArgumentit[i - 1]; /* tallenna kohdetiedosto */
        pArgumentit[iNuoli] = NULL; /* katkaise argumentti ennen >*/
    }

    /* rakenna polku */
    char cPolku[PATH_MAX];
    int loytyi = 0;

    /* käy läpi hakemistot*/
    for (int j = 0; j < *iPolkuLkm; j++) {

        /* rakenna polku hakemisto/komento */
        snprintf(cPolku,
                sizeof(cPolku),
                "%s/%s",
                pPolut[j],
                pArgumentit[0]);

        /* tarkista löytyykö tiedosto */
        if (access(cPolku, X_OK) == 0) {
            loytyi = 1;
            break;
        }
    }

    /* komento ei löydy*/
    if (!loytyi) {
        error();
        return -1;
    }

    /* lapsiprosessi */
    pid_t pid = fork();

    if (pid < 0) {
        error();
        return -1;
    }

    /* suorita komento */
    if (pid == 0) {

        /* tulosteen redirection */
        if (pTiedosto != NULL) {

            /* avaa / luo kohdetiedosto */
            int fd = open(pTiedosto,
                        O_WRONLY | O_CREAT | O_TRUNC,
                        0666);

            if (fd < 0) {
                error();
                exit(1);
            }

            /* ohjaa stdout ja stderr tiedostoon */
            if (dup2(fd, STDOUT_FILENO) == -1 ||
                dup2(fd, STDERR_FILENO) == -1) {                    
                error();
                close(fd);
                exit(1);
            }

            close(fd);
        }
        
        /* korvaa lapsiprosessi uudella ohjelmalla */
        execv(cPolku, pArgumentit);

        error();
        exit(1);

    } else {
        return pid; /* palauttaa lapsiprosessin tunnuksen*/
    }

    return -1;
}

/* pääohjelma */
int main(int argc, char *argv[])
{
    /* syöterivi getline - funktiolle*/
    char *pRivi = NULL;
    size_t iKoko = 0;

    /* komentojen hakupolut */
    char *pPolut[100] = {NULL};
    int iPolkuLkm = 1;

    /* lapsiprosessien tunnukset */
    pid_t pidit[100];
    int pidLkm = 0;

    /* oletuspolku */
    pPolut[0] = strdup("/bin");
    if (pPolut[0] == NULL) {
        error();
        exit(1);
    }

    /* tarkista argumentit */
    if (argc > 2) {
        error();
        exit(1);
    }

    /* lue näppäimistöltä */
    FILE *pSyote = stdin;

    /* batch tila, avaa syötetiedosto */
    if (argc == 2) {
        pSyote = fopen(argv[1], "r");

        if (pSyote == NULL) {
            error();
            exit(1);
        }
    }

    /* interaktiivinen tila */
    while (1) {

        /* tulosta kehote */
        if (pSyote == stdin) {
            printf("wish> ");
            fflush(stdout);
        }

        /* lue seuraava rivi */
        if (getline(&pRivi, &iKoko, pSyote) == -1) {
            free(pRivi);

            /* sulje tiedosto*/
            if (pSyote != stdin)
                fclose(pSyote);

            /* vapauta hakupolut*/
            for (int i = 0; i < iPolkuLkm; i++) {
                if (pPolut[i] != NULL)
                    free(pPolut[i]);
            }

            exit(0);
        }

        /* poista rivinvaihto */
        pRivi[strcspn(pRivi, "\n")] = '\0';

        /* lisää välilyönnit > ympärille */
        char uusi[3 * strlen(pRivi) + 1];
        int j = 0;

        for (int i = 0; pRivi[i] != '\0'; i++) {

            if (pRivi[i] == '>') {
                uusi[j++] = ' ';
                uusi[j++] = '>';
                uusi[j++] = ' ';
            } else {
                uusi[j++] = pRivi[i];
            }
        }

        /* päätä uusi merkkijono */
        uusi[j] = '\0';

        /* korvaa alkuperäinen komentorivi */
        strcpy(pRivi, uusi);

        /* pilko rinnakkaiset komennot */
        char *pKomento;
        char *pTallennus = NULL;

        pKomento = strtok_r(pRivi, "&", &pTallennus);

        int poistu = 0;

        /* suorita rivin komennot */
        while (pKomento != NULL) {

            pid_t pid;

            /* suorita yksi komento */
            pid = suorita_komento(pKomento, pPolut, &iPolkuLkm);

            if (pid == EXIT_COMMAND) {
                poistu = 1;
            }

            /* tallenna lapsiprosessin tunnus */
            if (pid > 0 && pidLkm < 100) {
                pidit[pidLkm++] = pid;
            }

            /* seuraava komento */
            pKomento = strtok_r(NULL, "&", &pTallennus);
        }

        /* odota lapsiprosessien valmistumista */
        for (int i = 0; i < pidLkm; i++) {

            waitpid(pidit[i], NULL, 0);

        }

        /* lopeta shell */
        if (poistu) {

            /* sulje tiedosto */
            if (pSyote != stdin)
                fclose(pSyote);

            /* vapauta muisti */
            free(pRivi);

            /* vapauta hakupolut */
            for (int i = 0; i < iPolkuLkm; i++) {
                if (pPolut[i] != NULL)
                    free(pPolut[i]);
            }

            exit(0);
        }

        /* tyhjennä prosessilista*/
        pidLkm = 0;
    }

    /* vapauta syöterivi */
    free(pRivi);

    /* vapauta hakupolut */
    for (int i = 0; i < iPolkuLkm; i++) {
        if (pPolut[i] != NULL)
            free(pPolut[i]);
    }

    /* sulje syötetiedosto */
    if (pSyote != stdin)
        fclose(pSyote);

    return 0;
}