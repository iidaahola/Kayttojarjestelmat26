# Projekti 2 dokumentointi
Tässä tiedostossa käydään projektin 2 valmistus, toteutus, toiminta, käyttö ja testaus

## Toinen projekti perustuu kurssin ohjeistukseen ja kurssikirjan materiaaleihin
https://github.com/remzi-arpacidusseau/ostep-projects/tree/master/initial-utilities

Projektissa toteutetaan neljä Unix-apuohjelmaa C-kielellä:
- my-cat
- my-grep
- my-zip
- my-unzip

Kaikki ohjelmat on toteutettu omiin lähdetiedostoihin

## Status:

### my-cat
- Toteutus - valmis 22.07.2026 4:00pm
- Testaus - valmis 22.07.2026 4:00pm
- Dokumentointi - valmis 22.07.2026 4:00pm


### my-grep
- Toteutus - valmis 22.07.2026 10:00pm
- Testaus - valmis 22.07.2026 10:00pm
- Dokumentointi - valmis 22.07.2026 10:00pm

### my-zip
- Toteutus 
    - 24.07.2026 3:00pm - Toimii yhdellä input tiedostolla
    - valmis 24.07.2026 9:30pm
- Testaus 
    - 24.07.2026 3:00pm
    - valmis 24.07.2026 9:30pm
- Dokumentointi 
    - 24.07.2026 3:00pm - Aloitettu
    - valmis 24.07.2026 10:00

### my-unzip
- Toteutus - valmis 24.07.2026 9:30pm
- Testaus - valmis 24.07.2026 9:30pm
- Dokumentointi - valmis 24.07.2026 10:00pm

# my-cat

## Toteutus:
Ohjelma lukee yhden tai useamman tiedoston ja tulostaa sisällön standard outputiin.

Ohjelmassa käytetään funktioita:
- fopen()
- fgets()
- printf()
- fclose()

## Ohjelman toiminta:
- Käydään komentorivin tiedostot läpi
- Avataan kaikki tiedostot
- Luetaan tiedosto riveittäin
- Tulostetaan luetut rivit
- Suljetaan tiedosto

Note: Jos viimeisellä rivillä ei ole input tiedostosssa rivinvaihtoa, tuloste jatkuu suoraan perään. Tämä ilmeisesti toivottu tapa?

## Ohjelman käyttö:

Ei tiedostoja: ./my-cat
Yksi tiedosto: ./my-cat test/<input>
Useita tiedostoja: ./my-cat test/<input> test/<input>

## Testaus:
Ohjelmaa testattiin näillä komennoilla:
./my-cat
./my-cat test/input.txt
./my-cat test/input.txt test/input2.txt
./my-cat test/eiole.txt
./my-cat test/input.txt test/eiole.txt

## Virheenkäsittely:
Jos tiedostoa ei voida avata: my-cat: cannot open file
Loppuu virhekoodilla 1

# my-grep

## Toteutus:
Ohjelma etsii hakusanan yhdestä tai useammasta tiedostosta ja tulostaa kaikki hakusanan sisältävät rivit standard outputiin.

Ohjelmassa käytetään funktioita:
- fopen()
- getline()
- strstr()
- printf()
- fclose()

## Ohjelman toiminta:
- Luetaan hakusana komentoriviltä
- Käydään kaikki tiedostot läpi
- Avataan tiedosto
- Luetaan tiedosto riveittäin
- Tarkistetaan sisältääkö rivi hakusanan
- Tulostetaan hakusanan sisältävät rivit
- Suljetaan tiedosto

Note: case sensitive, grep, Grep ja GREP ovat eri hakusanat

## Ohjelman käyttö:

Ei hakusanaa: ./my-grep

Hakusana standard inputista: ./my-grep <hakusana>

Yksi tiedosto: ./my-grep <hakusana> test/<input>

Useita tiedostoja: ./my-grep <hakusana> test/<input> test/<input>

## Testaus:

Ohjelmaa testattiin näillä komennoilla:

./my-grep
./my-grep grep
./my-grep grep test/input.txt
./my-grep grep test/input.txt test/input2.txt
./my-grep grep test/eiole.txt

## Virheenkäsittely:

Ei hakusanaa: my-grep: searchterm [file ...]

Jos tiedostoa ei voida avata: my-grep: cannot open file

Loppuu virhekoodilla 1

# my-zip

## Toteutus:
Ohjelma pakkaa yhden tai useamman tiedoston RLE -pakkausta käyttäen. Kirjoittaa pakatun datan standard outputtiin.

Ohjelmassa käytetään funktioita:
- fopen()
- fgetc()
- fwrite()
- fclose()

## Ohjelman toiminta:
- Käydään komentorivin tiedostot läpi
- Luetaan tiedosto merkeittäin
- Lasketaan peräkkäisten samanlaisten merkkien määärä
- Kirjoitetaan jokaisesta jaksosta 4 tavun kokonaisluku ja 1 merkki
- Useita tiedostoja käsitellään yhtenä jatkuvuutena

## Ohjelman käyttö:

Ei tiedostoja: ./my-zip
Yksi tiedosto: ./my-zip test/<input> > test/<output>
Useita tiedostoja: ./my-zip test/<input> test/<input> > test/<output>

## Testaus:
Ohjelmaa testattiin näillä komennoilla:
./my-zip
./my-zip test/input3.txt > test/output.z
xxd test/output.z
./my-zip test/input3.txt test/input4.txt > test/output2.z
./my-zip test/eiole.txt

## Virheenkäsittely:
Ei tiedostoja: my-zip: file1 [file2 ...]
Jos tiedostoa ei voida avata: my-zip: cannot open file

Loppuu virhekoodilla 1

# my-unzip

## Toteutus:
Ohjelma purkaa my-zip ohjelman tuottaman RLE tiedoston ja tulostaa alkuperäisen sisällön standard outputtiin

Ohjelmassa käytetään funktioita:
- fopen()
- fread()
- printf()
- fclose()

## Ohjelman toiminta:
- Käydään komentorivin tiedostot läpi
- Luetaan yksi pakkausjakso kerrallaan
- Luetaan ensin 4 tavun kokonaisluku, sitten seuraava merkki
- Tulostetaan merkki luetun määrän verran
- Jatketaan loppuun saakka

## Ohjelman käyttö:

Ei tiedostoja: ./my-unzip
Yksi tiedosto: ./my-unzip test/<output>
Useita tiedostoja: ./my-unzip test/<output> test/<output>

## Testaus:
Ohjelmaa testattiin näillä komennoilla:
./my-unzip
./my-unzip test/output.z
./my-unzip test/output2.z
./my-unzip test/eiole.z

## Virheenkäsittely:
Ei tiedostoja: my-unzip: file1 [file2 ...]
Jos tiedostoa ei voida avata: my-unzip: cannot open file

Loppuu virhekoodilla 1

# Lähteeet
Tehtävänanto:
https://github.com/remzi-arpacidusseau/ostep-projects/tree/master/initial-utilities

Linux manuaalit:
https://man7.org/linux/man-pages/man3/fopen.3.html
https://man7.org/linux/man-pages/man3/fgets.3p.html
https://man7.org/linux/man-pages/man3/getline.3.html
https://man7.org/linux/man-pages/man3/strstr.3.html
https://man7.org/linux/man-pages/man3/fgetc.3.html
https://man7.org/linux/man-pages/man3/fread.3.html

POSIX standardi
https://pubs.opengroup.org/onlinepubs/9699919799/

Stack overflow:
https://stackoverflow.com/questions/2409504/using-c-filestreams-fstream-how-can-you-determine-the-size-of-a-file
https://stackoverflow.com/questions/18277304/using-stdcout-in-multiple-threads
https://stackoverflow.com/questions/12784766/check-substring-exists-in-a-string-in-c