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
- Toteutus - kesken 27.07.2026 3:00pm - Toimii yhdellä input tiedostolla
- Testaus - kesken 27.07.2026 3:00pm - Toimii yhdellä input tiedostolla
- Dokumentointi - kesken 27.07.2026 3:00pm - Aloitettu

### my-unzip
- Toteutus - kesken
- Testaus - kesken
- Dokumentointi - kesken

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

Note: Jos viimeisellä rivillä ei ole input tiedostosssa rivinvaihtoa, tuloste jatkuu suoraan perään. Tämä ilmeisesti toivottu tapa? Ei tarvitse sisällyttää ohjelmaan rivinvaihtoa loppuun?

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

Note: Jos viimeisellä rivillä ei ole input tiedostosssa rivinvaihtoa, tuloste jatkuu suoraan perään. Tämä ilmeisesti toivottu tapa? Ei tarvitse sisällyttää ohjelmaan rivinvaihtoa loppuun?

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