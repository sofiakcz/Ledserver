# LED-Server-Programm

## Vorbereitung
1. Logge dich auf deinem Account auf github über den Webbrowser ein.
2. Navigiere mit dem Browser zu diesem Repository:
https://github.com/eneukirchner/Ledserver
3. Erstelle einen Fork davon auf deinem github-Account (fork-Button rechts oben auf der github-Website)
4. Kopiere den Fork auf deinen Raspberry: `git clone git@github.com:<dein Accountname>/Ledserver.git`.
In dem dadurch erzeugten Ordner befindet sich das Projekt.

## Aufgabenstellung
Modifiziere im vorgegebenen Programmgerüst **nur** das File `ledserver.cpp` so, dass ein Server (Konsolenprogramm)
mit folgender Funktionalität entsteht:
1. Nach dem Start soll der Server auf allen Interfaces auf Port 1234 empfangsbereit sein.
2. Ablauf der Kommunikation Client-Server:
    - Client verbindet sich mit dem Server: `nc localhost 1234`
    - Server sendet zum Client den Textstring: `Bitte Zahl von 0 bis 15 eingeben: `
    - Client sendet eine passende Zahl.
    - Wenn die Zahl im erlaubten Bereich liegt, antwortet der Server mit `OK` und zeigt die Zahl im Dualcode über die
    LEDs an (MSB = GPIO18, LSB = GPIO25). Andernfalls ignoriert er die Nachricht vom Client.
    - Solange der Client die Verbindung nicht trennt, sendet der Server erneut den Textstring
    `Bitte Zahl von 0 bis 15 eingeben: `
    - Wenn der Client die Verbindung mit <kbd>Ctrl</kbd> <kbd>c</kbd> abbricht, schaltet der Server alle LEDs aus
    und ist bereit für neue Client-Verbindungen.

<em>Tipps:
- Verwende `QString` als Datentyp für die Nachricht, die das Programm vom Client empfängt.
- Im Unterverzeichnis `bin` befindet sich ein lauffähiges Beispielprogramm.</em>

## Abgabe via Github
**Ab 10 Minuten vor Schluss (wird angesagt). Frühere Abgaben werden nicht gewertet, spätere nach Abgabeschluss
ebenso wenig!**
Versionierung des Projektes mit git und Upload des Repositorys `Ledserver` auf den eigenen github-Account.




