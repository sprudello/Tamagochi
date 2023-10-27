# Projekt-Documentation

Swaggy guys🤙🏼( Julius V. Burlet, Keanu M. Koelewijn, Stefan Jesenko)

| Date       | Version | Summary                                                                                                     |
|------------|---------|-------------------------------------------------------------------------------------------------------------|
| 15.09.2023 | 0.0.0   | We were at the coding camp, so we couldn't work on it.|
| 22.09.2023 | 0.0.1   | We brainstormed what we could potentially do and settled on a C++ project with AI.|
| 29.09.2023 | 0.0.1.1 | We have changed our minds and now want to make a Tamagotchi in C++.|

## 1 Inform

### 1.1 Our Project

Our goal is to make a Tamagotchi. 

### 1.2 User Stories

| US-№ | Liability | Type | Description                                 |
| ---- | --------------- | ---- | ------------------------------------------- |
| 1    |Muss|Funktional|Als User möchte ich mich um einen Tamagotchi kümmern, damit ich verantwortung üben kann.|
| 2    |Muss|Funktional|Als User möchte ich zwischen verschiedenen Tamagotchis auswählen können, damit es abwächslung in dem Spiel gibt.|
| 3    |Muss|Funktional|Als User möchte ich den Tamagotchi füttern können, damit der Tamagotchi keinen hunger mehr hat.|
| 4    |Muss|Funktional|Als User möchte ich dem Tamagotchi Wasser geben, damit der Tamagotchi kein durst mehr hat.|
| 5    |Muss|Funtkional|Als User möchte ich mit dem Tamagotchi Spielen, damit der Tamagotchi nicht mehr traurig ist.|
| 6    |Muss|Funktional|Als User möchte ich den Tamagotchi ausruhen lassen, damit er sich erhohlen kann.|
| 7    |Muss|Funktional|Als User möchte ich das ich alle Werte des Tamagotchis balancieren muss, damit der Tamagotchi überlegt, um das Spiel herausfordernd zu machen.|
| 8    |Kann|Qualität|Als User möchte ich das der Tamagotchi mir auf jede Aktion eine Antwort gibt die spezifisch zur art des Tamagotchis ist, damit das Spiel interaktiver ist.|
| 9   |Kann|Qualität|Als User möchte ich den Tamagotchi auf suche nach einem Spielzeug schicken kann, damit es mehr optionen gibt wie ich mit dem Tamagotchi interagieren kann.|
|10  |Muss|Funktional|Als User möchte möchte ich nach einer Runde entsscheiden ob ich nochmal spielen oder ob ich das Spiel schliessen will.| 

### 1.3 Test cases

| TC-№ | Initial situation | Input | Expected output |
| ---- | ------------ | ------- | ----------------- |
| 1.1  |Game wurde gestartet| - |Optionen um sich um den Tamagotchi zu kümmern erscheinen.|
| 2.1  |Game wurde gestartet| - |"1. Fish / 2. Cat / 3. Pickmin / 4. Kermit / 5. Amoeba /Which Tamagotchi would you like?:"|
| 2.2  |Wahl der Tamagotchis wurde ausgegeben| 1 | Du hast den Fisch als Tamagotchi gewählt.|
| 3.1  |Tamagotchi wurde gewählt| - |"1. Feed / 2. Play / 3. Rest / 4. Give drink / 5. Cuddle / 6. Find something for Pet outdoors."|
| 3.2  |Tamagotchi wurde gewählt| 1 |"BLUB yummy BLUB!"|
| 3.3  |Tamagotchi wurde gefüttert| - |" /Hunger         /   very full      /      35%        /"| 
| 4.1  |Tamagotchi wurde gewählt| - |"1. Feed / 2. Play / 3. Rest / 4. Give drink / 5. Cuddle / 6. Find something for Pet outdoors."|
| 4.2  |Tamagotchi wurde gewählt| 4 |"BLUB GLUG GLUG BLUB"|
| 4.3  |Tamagotchi wurde zutrinken gegeben| - |"/  Thirst         /   normal         /      45%        /"|
| 5.1  |Tamagotchi wurde gewählt| - |"1. Feed / 2. Play / 3. Rest / 4. Give drink / 5. Cuddle / 6. Find something for Pet outdoors."|
| 5.2  |Tamagotchi wurde gewählt| 2 |"BLUB BLUB BLUB!"|
| 5.3  |Mit Tamagotchi wurde gespielt| - |"/  Happiness      /   normal         /      45%        /"|
| 6.1  |Tamagotchi wurde gewählt| - |"1. Feed / 2. Play / 3. Rest / 4. Give drink / 5. Cuddle / 6. Find something for Pet outdoors."|
| 6.2  |Tamagotchi wurde gewählt| 3 |"ZZZZZ BLUB ZZZZZ!"|
| 6.3  |Tamagotchi hat geschlafen| - |"/  Energy         /   normal         /      40%        /"|
| 7.1  |Spiel leuft| - |Tamagotchi lebt wenn keiner der Werte einen kritischen Punkt überschreitet.|
| 7.2  |Spiel leuft| - |Kritischer Punkt überschritten: "Your Fish has passed away at age 1 and died of thirst. Game over."|
| 8.1  |Spiel leuft| 1 |"BLUB yummy BLUB!"|
| 9.1  |Spiel leuft| 6 |"You found Nothing, your Chances drop to find something for your Pet."|
| 9.2  |Spiel leuft| 6 |"You found a Sparkling Water bowl! Your Kermit gets -10 Thirst!"|
|10.1  |Tamagotchi ist gestorben| - |"/ 1. Play again / 2. Close Game /"|
|10.2  |Tamagotchi ist gestorben| 1 |Neues Game wird gestartet.|
|10.3  |Tamgaotchi ist gestorben| 2 |Game wird geschlossen|
### 1.4 Diagrams

✍️ Hier können Sie PAPs, Use Case- und Gantt-Diagramme oder Ähnliches einfügen.

## 2 Planings

| AP-№ | Frist | Zuständig | Beschreibung | geplante Zeit |
| ---- | ----- | --------- | ------------ | ------------- |
| 1.A  |29.09.2023|Keanu Koelewijn|Tamagotchi can be cared for|45min|
| 1.B  |29.09.2023|Keanu Koelewijn|Tamagotchi can be cared for|45min|
| 2.A  |29.09.2023|Stefan Jesenko|Tamagotchi can be chosen from a List of Tamagotchis|30min|
| 3.A  |29.09.2023|Julius Burlet|Tamagotchi can be feed|45min|
| 4.A  |29.09.2023|Keanu Koelewijn|Tamagotchi can drink|45min|
| 5.A  |29.09.2023|Stefan Jesenko|Tamagotchi can play|45min|
| 6.A  |29.09.2023|Julius Burlet|Tamagotchi can rest|45min|
| 7.A  |29.09.2023|Keanu Koelewijn|The stats of the Tamagotchi have to be balanced|45min|
| 7.B  |29.09.2023|Stefan Jesenko|The stats of the Tamagotchi have to be balanced|45min|
| 8.A  |29.09.2023|Julius Burlet|Every Tamagotchi has unique reactions to the users actions.|45min|
| 8.B  |27.10.2023|Keanu Koelewijn|Every Tamagotchi has unique reactions to the users actions.|45min|
| 9.A  |27.10.2023|Stefan Jesenko|Tamagotchi can find toys.|45min|
| 9.B  |27.10.2023|Julius Burlet|Tamagotchi can find toys.|45min|
|10.A  |27.10.2023|Keanu Koelewijn|restart of the game.|30min|





## 3 Decisions

Wir haben uns dazu entschieden einen Tamagotchi in C++ zu prgroammieren, wir wollen diesen mit den oben stehenden Funktionen Implementieren.

✍️ Dokumentieren Sie hier Ihre Entscheidungen und Annahmen, die Sie im Bezug auf Ihre User Stories und die Implementierung getroffen haben

## 4 Realize

| AP-№ | Datum | Zuständig | geplante Zeit | tatsächliche Zeit |
| ---- | ----- | --------- | ------------- | ----------------- |
| 1.A  |       |           |               |                   |
| ...  |       |           |               |                   |

✍️ Tragen Sie jedes Mal, wenn Sie ein Arbeitspaket abschließen, hier ein, wie lang Sie effektiv dafür hatten.

## 5 Check

### 5.1 Test protocol

| TC-№ | Datum | Resultat | Tester |
| ---- | ----- | -------- | ------ |
| 1.1  |       |          |        |
| ...  |       |          |        |

✍️ Vergessen Sie nicht, ein Fazit hinzuzufügen, welches das Test-Ergebnis einordnet.

### 5.2 Exploratory testing

| BR-№ | Ausgangslage | Eingabe | Erwartete Ausgabe | Tatsächliche Ausgabe |
| ---- | ------------ | ------- | ----------------- | -------------------- |
| I    |              |         |                   |                      |
| ...  |              |         |                   |                      |

✍️ Verwenden Sie römische Ziffern für Ihre Bug Reports, also I, II, III, IV etc.

## 6 Evaluate

✍️ Fügen Sie hier eine Verknüpfung zu Ihrem Lern-Bericht ein.
