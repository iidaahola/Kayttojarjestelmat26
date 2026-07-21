# Ensimmäinen projekti perustuu kurssin ohjeistukseen ja kurssikirjan materiaaleihin
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
