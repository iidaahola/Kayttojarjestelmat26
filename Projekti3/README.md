# Projekti 3 dokumentointi
Tässä tiedostossa käydään projektin 3 valmistus, toteutus, toiminta, käyttö ja testaus

## Kolmas projekti perustuu kurssin ohjeistukseen ja kurssikirjan materiaaleihin
https://github.com/remzi-arpacidusseau/ostep-projects/tree/master/processes-shell

## Status:
- Interaktiivinen tila - valmis 25.7.2026 3:45pm
- Syötteen lukeminen getline()-funktiolla - valmis 25.7.2026 3:45pm
- exit-komento - valmis 25.7.2026 3:45pm
- Komentojen jäsentäminen - valmis 26.7.2026 11:30pm
- Ulkoisten ohjelmien suoritus - valmis 26.7.2026 11:30pm
- Built-in komennot - kesken
    - exit - valmis 26.7.2026 11:30pm
    - cd - valmis 26.7.2026 11:30pm
    - path - valmis 27.7.2026 7:30pm 
- Batch mode - valmis 27.7.2026 9:30pm
- Redirection - valmis 27.7.2026 9:30pm
- Parallel commands - valmis 27.7.2026 9:30pm
- Dokumentointi - valmis 27.7.2026 10:00pm

## Toteutus:
Ohjelmassa käytetään funktioita:
- getline()
- strtok_r()
- strcmp()
- strdup()
- fork()
- excev()
- waitpid()
- chdir()
- access()
- open()
- dup2()
- free()

## Ohjelman toiminta:
Oletuspolkuna on /bin
Interaktiivisessa tilassa ohjelma tulostaa wish>
Tuetut ominaisuudet:
- tavallisten komentojen suoritus
- usean komennon suoritus rinnakkain käyttäen &
- ulostulon ohjaus tiedostoon käyttäen >
- batch mode
- sisäänrakennetut komennot

# Sisäänrakennetut komennot
- exit - sulkee shellin
- cd - vaihtaa hakemiston
- path - muokkaa hakupolkuja
- redirection - tulostuksen ohjaus tiedostoon
- parallel commands - useita komentoja käsitellään rinnakkain &


# Ohjelman käyttö: 
Käännä ohjelma: make
Käynnistä shell: ./wish
Poistu ohjelmasta: exit tai ctrl+D

# Testaus
Ohjelmaa testattiin seuraavilla komennoilla:
./wish
pwd
whoami
date
ls
ls -l
exit
./wish
ctrl+D

# Virheenkäsittely
Tuloste: An error has occured
## Liian monta argumenttia: 
./wish a b
## Väärä komento: 
exit now
wish pwd
cd
cd a b
cd olematon
siili
## Path: 
path
ls
path /bin
ls

## Redirection:
ls > lista.txt
pwd > polku.txt
ls>out.txt
pwd>abc.txt
ls >
ls > a b
ls > a > b

## Parallel commands
pwd & whoami
pwd & whoami & date

## Batch mode
./wish test/batch.txt

# Lähteeet
Tehtävänanto:
https://github.com/remzi-arpacidusseau/ostep-projects/tree/master/processes-shell

Linux manuaalit:
https://man7.org/linux/man-pages/man2/fork.2.html
https://man7.org/linux/man-pages/man3/exec.3.html
https://man7.org/linux/man-pages/man2/waitpid.2.html
https://man7.org/linux/man-pages/man2/dup.2.html
https://man7.org/linux/man-pages/man2/open.2.html
https://man7.org/linux/man-pages/man3/getline.3.html
https://man7.org/linux/man-pages/man3/strtok.3.html
https://man7.org/linux/man-pages/man2/access.2.html
https://man7.org/linux/man-pages/man2/chdir.2.html

Stack overflow:
https://stackoverflow.com/questions/31519435/program-stuck-pipe-file-descriptor-open-when-shouldnt
https://stackoverflow.com/questions/48970420/creating-a-shell-in-c-how-would-i-implement-input-and-output-redirection
https://stackoverflow.com/questions/7218625/what-are-the-differences-between-strtok-and-strsep-in-c
https://stackoverflow.com/questions/900411/how-to-properly-wait-for-foreground-background-processes-in-my-own-shell-in-c