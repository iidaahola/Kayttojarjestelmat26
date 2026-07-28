# Projekti 1 dokumentointi
Tässä tiedostossa käydään projektin 1 valmistus, toteutus, toiminta, käyttö ja testaus

## Ensimmäinen projekti perustuu kurssin ohjeistukseen ja kurssikirjan materiaaleihin
https://github.com/remzi-arpacidusseau/ostep-projects/tree/master/initial-reverse

## Status:
- Read input - valmis 21.7.2026 2:50pm
- Store lines - valmis 21.7.2026 2:50pm
- Reverse output - valmis 21.7.2026 2:50pm
- Error handling - valmis 21.7.2026 2:50pm
- Finish documentation - valmis 21.7.2026 10:30pm

## Toteutus:
Ohjelmassa käytetään funktioita:
- getline()
- malloc()
- realloc()
- free ()
- fprint()

## Ohjelman toiminta:
- Syöte luetaan riveittäin getline() funktiolla
- Rivit kopioidaan dynaamiseen muistitaulukkoon
- Rivit tulostetaan taulukon lopusta alkuun
- Dynaaminen muisti vapautetaan ennen ohjelman päättymistä

# Ohjelman käyttö: 
Ohjelmaa voidaan käyttää 3 tavalla

## 1: Syöte näppäimistöltä
Ohjelma käynnistetään ilman komentoriviargumentteja:
./reverse
Kirjoita terminaaliin rivit, syötteen lopuksi ctr + D
Tuloste antaa rivit käänteisessä järjestössä

## 2: Syöte tiedostosta
./reverse <input>
Ohjelma lukee tiedoston ja tulostaa käännetyn sisällön terminaaliin

## 3: Syöte tiedostosta ja tulostus tiedostoon
./reverse <input> <output>
Ohjelma lukee tiedoston <input> ja kirjoittaa käännetyn sisällön tiedostoon <output>
Tuloksen voi tarkistaa comennolla cat <output>

# Testaus
Ohjelmaa testattiin seuraavilla komennoilla:
./reverse test/input.txt
./reverse test/input.txt test/output.txt
./reverse

# Virheenkäsittely
## Liian monta argumenttia
Komento: ./reverse a b c
Tuloste: usage: reverse <input> <output>

## Input- ja output-tiedosto ovat samat
Komento: ./reverse test/input.txt test/input.txt
Tuloste: Input and output file must differ

## Tiedostoa ei voida avata
Komento: ./reverse missing.txt
Tuloste: error: cannot open file 'missing.txt'

## Muistinvaraus epäonnistui
Jos dynaaminen muistinvaraus epäonnistuu, ohjelma tulostaa
malloc failed
ja lopettaa suorituksen virhekoodilla 1

# Lähteeet
Tehtävänanto:
https://github.com/remzi-arpacidusseau/ostep-projects/tree/master/initial-reverse

Linux manuaalit:
https://man7.org/linux/man-pages/man3/getline.3.html
https://man7.org/linux/man-pages/man3/fopen.3.html
https://man7.org/linux/man-pages/man3/malloc.3.html
https://man7.org/linux/man-pages/man3/strcpy.3.html
https://man7.org/linux/man-pages/man3/strlen.3.html
https://man7.org/linux/man-pages/man3/strcmp.3.html
https://man7.org/linux/man-pages/man3/strchr.3.html
https://man7.org/linux/man-pages/man3/fprintf.3.html
https://man7.org/linux/man-pages/man3/stdin.3.html

Stack overflow:
https://stackoverflow.com/questions/7563308/dynamic-array-in-c-realloc
https://stackoverflow.com/questions/1986538/how-to-handle-realloc-when-it-fails-due-to-memory
https://stackoverflow.com/questions/3536153/c-dynamically-growing-array
https://stackoverflow.com/questions/3501338/c-read-file-line-by-line
https://stackoverflow.com/questions/2550774/what-is-size-t-in-c
