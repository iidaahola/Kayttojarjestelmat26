# Projekti 3 dokumentointi
Tässä tiedostossa käydään projektin 3 valmistus, toteutus, toiminta, käyttö ja testaus

## Kolmas projekti perustuu kurssin ohjeistukseen ja kurssikirjan materiaaleihin
https://github.com/remzi-arpacidusseau/ostep-projects/tree/master/processes-shell

## Status:
- Interaktiivinen tila - valmis 25.7.2026 3:45pm
- Syötteen lukeminen getline()-funktiolla - valmis 25.7.2026 3:45pm
- exit-komento - valmis 25.7.2026 3:45pm
- Komentojen jäsentäminen - kesken 25.7.2026
- Ulkoisten ohjelmien suoritus - kesken 25.7.2026
- Built-in komennot - kesken 25.7.2026
- Redirection - kesken 25.7.2026
- Parallel commands - kesken 25.7.2026
- Dokumentointi - aloitettu 25.7.2026 3:45pm

## Toteutus:
Ohjelmassa käytetään funktioita:
- getline()
- strcmp()
- printf()
- fflush()
- free()
- strtok()
- fork()
- execv()
- wait()
- chdir()
- access

## Ohjelman toiminta:
- Kännistäessä ohjelma tulostaa wish>
- Käyttäjän syöte luetaan getline()-funktiolla
- Käyttäjän kirjoittaessa exit ohjelma päättyy
- ctrl+D sulkee ohjelman

# Ohjelman käyttö: 
Käännä ohjelma: make
Käynnistä shell: ./wish
Poistu ohjelmasta: exit tai ctrl+D

# Testaus
Ohjelmaa testattiin seuraavilla komennoilla:
./wish
hello
ls
exit
./wish
ctrl+D

# Virheenkäsittely
## Liian monta argumenttia
Komento: ./wish a b
Tuloste: An error has occured
lopettaa suorituksen virhekoodilla 1
