# Projekt-Dokumentation

Swaggy guys🤙🏼( Julius V. Burlet, Keanu M. Koelewijn, Stefan Jesenko)

| Date       | Version | Summary                                                                                                     |
|------------|---------|-------------------------------------------------------------------------------------------------------------|
| 15.09.2023 | 0.0.0   | Wir waren im Codingcamp, deshalb konnten wir nicht daran arbeiten.|
| 22.09.2023 | 0.0.1   | Wir haben darüber nachgedacht, was wir machen könnten, und uns schliesslich für eine Schere, Stein, Papier KI entschieden.|
| 29.09.2023 | 0.6.1   | Wir haben uns umentschieden und programmieren nun einen Tamagotchi in C++. Wir haben bereits damit begonnen und eine einfache Version des Tamagotchis erstellt.|
| 27.10.2023 | 1.0.0   | Wir haben die letzten Funktionen und Bugfixes implementiert. Der Tamagotchi ist nun vollständig mit allen Funktionen realisiert.|

## 1 Inform

### 1.1 Our Project

Unser Ziel ist es, ein Tamagotchi ähnliches Spiel in C++ zu programmieren.

### 1.2 User Stories

| US-№ | Liability | Type | Description                                 |
| ---- | --------------- | ---- | ------------------------------------------- |
| 1    |Muss|Funktional|Als Nutzer möchte ich mich um einen Tamagotchi kümmern, um Verantwortung zu übernehmen.|
| 2    |Muss|Funktional|Als Nutzer möchte ich zwischen verschiedenen Tamagotchis auswählen können, um Abwechslung im Spiel zu haben.|
| 3    |Muss|Funktional|Als Nutzer möchte ich den Tamagotchi füttern können, damit er keinen Hunger mehr hat.|
| 4    |Muss|Funktional|Als Nutzer möchte ich dem Tamagotchi Wasser geben können, damit er keinen Durst mehr hat.|
| 5    |Muss|Funtkional|Als Nutzer möchte ich mit dem Tamagotchi spielen können, damit es nicht mehr traurig ist.|
| 6    |Muss|Funktional|Als Nutzer möchte ich den Tamagotchi ausruhen lassen können, damit er sich erholen kann.|
| 7    |Muss|Funktional|Als Nutzer möchte ich alle Werte des Tamagotchis ausbalancieren müssen, damit der Tamagotchi überlegt, um das Spiel herausfordernd zu gestalten.|
| 8    |Kann|Qualität|Als Nutzer möchte ich, dass der Tamagotchi auf jede Aktion eine spezifische Antwort gibt, die zur Art des Tamagotchis passt, um das Spiel interaktiver zu gestalten.|
| 9   |Kann|Qualität|Als Nutzer möchte ich den Tamagotchi auf die Suche nach einem Spielzeug schicken können, um mehr Optionen für die Interaktion mit dem Tamagotchi zu haben.|
|10  |Muss|Funktional|Als Nutzer möchte ich nach einer Runde entscheiden können, ob ich nochmal spielen oder das Spiel schließen möchte.| 

### 1.3 Test cases

| TC-№ | Initial situation | Input | Expected output |
| ---- | ------------ | ------- | ----------------- |
| 1.1  |Das Spiel wurde gestartet.| - |Optionen um sich um den Tamagotchi zu kümmern erscheinen.|
| 2.1  |Das Spiel wurde gestartet.| - |"1. Fish / 2. Cat / 3. Pickmin / 4. Kermit / 5. Amoeba /Which Tamagotchi would you like?:"|
| 2.2  |Die Auswahl der Tamagotchis wurde angezeigt.| 1 | Du hast den Fisch als Tamagotchi gewählt.|
| 3.1  |Das Tamagotchi wurde ausgewählt.| - |"1. Feed / 2. Play / 3. Rest / 4. Give drink / 5. Cuddle / 6. Find something for Pet outdoors."|
| 3.2  |Das Tamagotchi wurde ausgewählt.| 1 |"BLUB yummy BLUB!"|
| 3.3  |Das Tamagotchi wurde ausgewählt.| - |" /Hunger         /   very full      /      35%        /"| 
| 4.1  |Das Tamagotchi wurde ausgewählt.| - |"1. Feed / 2. Play / 3. Rest / 4. Give drink / 5. Cuddle / 6. Find something for Pet outdoors."|
| 4.2  |Das Tamagotchi wurde ausgewählt.| 4 |"BLUB GLUG GLUG BLUB"|
| 4.3  |Tamagotchi wurde zutrinken gegeben| - |"/  Thirst         /   normal         /      45%        /"|
| 5.1  |Das Tamagotchi wurde ausgewählt.| - |"1. Feed / 2. Play / 3. Rest / 4. Give drink / 5. Cuddle / 6. Find something for Pet outdoors."|
| 5.2  |Das Tamagotchi wurde ausgewählt. 2 |"BLUB BLUB BLUB!"|
| 5.3  |Mit Tamagotchi wurde gespielt| - |"/  Happiness      /   normal         /      45%        /"|
| 6.1  |Das Tamagotchi wurde ausgewählt.| - |"1. Feed / 2. Play / 3. Rest / 4. Give drink / 5. Cuddle / 6. Find something for Pet outdoors."|
| 6.2  |Tamagotchi wurde gewählt| 3 |"ZZZZZ BLUB ZZZZZ!"|
| 6.3  |Tamagotchi hat geschlafen| - |"/  Energy         /   normal         /      40%        /"|
| 7.1  |Spiel läuft| - |Tamagotchi lebt wenn keiner der Werte einen kritischen Punkt überschreitet.|
| 7.2  |Spiel läuft| - |Kritischer Punkt überschritten: "Your Fish has passed away at age 1 and died of thirst. Game over."|
| 8.1  |Spiel läuft| 1 |"BLUB yummy BLUB!"|
| 9.1  |Spiel läuft| 6 |"You found Nothing, your Chances drop to find something for your Pet."|
| 9.2  |Spiel läuft| 6 |"You found a Sparkling Water bowl! Your Kermit gets -10 Thirst!"|
|10.1  |Tamagotchi ist gestorben| - |"/ 1. Play again / 2. Close Game /"|
|10.2  |Tamagotchi ist gestorben| 1 |Neues Game wird gestartet.|
|10.3  |Tamgaotchi ist gestorben| 2 |Game wird geschlossen|
### 1.4 Diagrams

![image](https://github.com/sprudello/Tamagotchi/assets/110892250/41850f02-6835-448a-b2fd-8ed1754e400e)


## 2 Planings

| AP-№ | Frist | Zuständig | Beschreibung | geplante Zeit |
| ---- | ----- | --------- | ------------ | ------------- |
| 1.A  |29.09.2023|Keanu Koelewijn|Man kann sich um den Tamagotchi kümmern.|45min|
| 1.B  |29.09.2023|Keanu Koelewijn|Man kann sich um den Tamagotchi kümmern.|45min|
| 2.A  |29.09.2023|Stefan Jesenko|Tamagotchi kann aus einer Liste ausgewählt werden.|30min|
| 3.A  |29.09.2023|Julius Burlet|Tamagotchi kann gefüttert werden.|45min|
| 4.A  |29.09.2023|Keanu Koelewijn|Tamagotchi kann Trinken.|45min|
| 5.A  |29.09.2023|Stefan Jesenko|Tamagotchi kann Spielen|45min|
| 6.A  |29.09.2023|Julius Burlet|Tamagotchi kann sich ausruhen|45min|
| 7.A  |29.09.2023|Keanu Koelewijn|Die Werte des Tamagotchis müssen ausgeglichen sein.|45min|
| 7.B  |29.09.2023|Stefan Jesenko|Die Werte des Tamagotchis müssen ausgeglichen sein.|45min|
| 8.A  |29.09.2023|Julius Burlet|Jeder Tamagotchi hat spezielle Reaktionen auf Aktionen.|45min|
| 8.B  |27.10.2023|Keanu Koelewijn|Jeder Tamagotchi hat spezielle Reaktionen auf Aktionen.|45min|
| 9.A  |27.10.2023|Stefan Jesenko|Tamagotchi kann Spielzeuge finden.|45min|
| 9.B  |27.10.2023|Julius Burlet|Tamagotchi kann Spielzeuge finden.|45min|
|10.A  |27.10.2023|Keanu Koelewijn|Spiel kann neugestartet werden.|30min|





## 3 Decisions

Wir haben uns entschieden ein Tamagotchi in C++ zu programmieren, Wir wollen das machen indem wir die Userstorys von oben implementieren.

## 4 Realize

| AP-№ | Datum | Zuständig | geplante Zeit | tatsächliche Zeit |
| ---- | ----- | --------- | ------------- | ----------------- |
| 1.A  |29.09.2023|Keanu Koelewijn|45min|60min|
| 1.B  |29.09.2023|Keanu Koelewijn|45min|30min|
| 2.A  |29.09.2023|Stefan Jesenko|30min|40min|
| 3.A  |29.09.2023|Julius Burlet|45min|30min|
| 4.A  |29.09.2023|Keanu Koelewijn|45min|20min|
| 5.A  |29.09.2023|Stefan Jesenko|45min|40min|
| 6.A  |29.09.2023|Julius Burlet|45min|20min|
| 7.A  |29.09.2023|Keanu Koelewijn|45min|60min|
| 7.B  |29.09.2023|Stefan Jesenko|45min|40min|
| 8.A  |29.09.2023|Julius Burlet|45min|60min|
| 8.B  |27.10.2023|Keanu Koelewijn|45min|40min|
| 9.A  |27.10.2023|Stefan Jesenko|45min|30min|
| 9.B  |27.10.2023|Julius Burlet|45min|30min|
|10.A  |27.10.2023|Keanu Koelewijn|30min|20min|

## 5 Check

### 5.1 Test protocol

| TC-№ | Datum | Resultat | Tester |
| ---- | ----- | -------- | ------ |
| 1.1  |27.10.2023|OK|Stefan Jesenko|
| 2.1  |27.10.2023|OK|Stefan Jesenko|
| 2.2  |27.10.2023|OK|Stefan Jesenko|
| 3.1  |27.10.2023|OK|Stefan Jesenko|
| 3.2  |27.10.2023|OK|Stefan Jesenko|
| 3.3  |27.10.2023|OK|Stefan Jesenko|
| 4.1  |27.10.2023|OK|Stefan Jesenko|
| 4.2  |27.10.2023|OK|Stefan Jesenko|
| 4.3  |27.10.2023|OK|Stefan Jesenko|
| 5.1  |27.10.2023|OK|Stefan Jesenko|
| 5.2  |27.10.2023|OK|Stefan Jesenko|
| 5.3  |27.10.2023|OK|Stefan Jesenko|
| 6.1  |27.10.2023|OK|Stefan Jesenko|
| 6.2  |27.10.2023|OK|Stefan Jesenko|
| 6.3  |27.10.2023|OK|Stefan Jesenko|
| 7.1  |27.10.2023|OK|Stefan Jesenko|
| 7.2  |27.10.2023|OK|Stefan Jesenko|
| 8.1  |27.10.2023|OK|Stefan Jesenko|
| 9.1  |27.10.2023|OK|Stefan Jesenko|
| 9.2  |27.10.2023|OK|Stefan Jesenko|
|10.1  |27.10.2023|OK|Stefan Jesenko|
|10.2  |27.10.2023|OK|Stefan Jesenko|
|10.3  |27.10.2023|OK|Stefan Jesenko|

## 6 Evaluate

Dies finden sie in unseren Portfolios.
Stefan Jesenko: https://portfolio.bbbaden.ch/user/s-jesenko-inf22/portfolio-stefan-jesenko-tamagotchi-c
