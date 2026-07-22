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
- Toteutus - kesken
- Testaus - kesken
- Dokumentointi - kesken

### my-zip
- Toteutus - kesken
- Testaus - kesken
- Dokumentointi - kesken

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