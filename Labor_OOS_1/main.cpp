#include <string>
#include <ctime>
#include <iostream>

using namespace std;

// Aufzählungstyp für wählbare Objekte
// STEIN - 0, SCHERE - 1, PAPIER - 2
enum class Object
{
    ROCK,
    SCISSORS,
    PAPER
};

// Aufzählungstyp für mögliche Spielausgänge
enum class Result
{
    PLAYER_ONE_WINS,
    PLAYER_TWO_WINS,
    DRAW
};

// Struktur für einen Spieler bestehend aus Name und Wahl des Spielers
struct Player
{
    string name;
    Object choice;
};

// Name des Spielers eingeben
string insert_name()
{
    Player player;

    cout << "Name des Spielers: ";
    cin.clear();
    getline(cin, player.name);
    return player.name;

}

Object determine_choice(string choice)
{
    if (choice.compare("CoderunnerTestValueROCK") == 0)
    {
        return Object::ROCK;
    }
    else if (choice.compare("CoderunnerTestValueSCISSORS") == 0)
    {
        return Object::SCISSORS;
    }
    else if (choice.compare("CoderunnerTestValuePAPER") == 0)
    {
        return Object::PAPER;
    }
    else
    {
        // Den Computer zufällig waehlen lassen.

        // HIER beantworten Sie folgende Fragen:
        // Was bewirkt die funktion srand?
        /*Initalisiert den Zufallszahlen-Generator. (Legt den Startwert/seed fest)
         * Ist diser konstant, wiederholen sich Zufallszahlen.
         * */
        // Warum wird hier die Zeit (time) als Eingabe für die Funktion srand verwendet?
        /* Um sicherzustellen, dass bei jedem Programmstart eine unterschiedliche Zahlensequenz generiert wird. Da sich
         * die Zeit ständig ändert, wird auch jedes Mal ein anderer Seed verwendet.*/
        // Wie funktioniert die funktion rand?
        /*Erzeugt eine Zufallszahl.*/
        // Warum wird hier modulo 3 verwendet?
        /*Um sicherzustellen, dass die Zufallszahl immer zwischen 0 und 2 liegt. Dies ist hier erforderlich, da es 3
         * verschiedene Optionen gibt. Schere, Stein und Papier. (Option 0, 1, 2)*/

        srand(static_cast<int>(time(nullptr)));
        int choice = rand() % 3;
        return static_cast<Object>(choice);
    }
}

// Die Wahl von Stein etc. als String zurückgeben lassen
string get_name(Object object)
{

    // HIER programmieren:
    switch(object){
        case Object::ROCK: return "Stein";
        case Object::SCISSORS: return "Schere";
        case Object::PAPER: return "Papier";
        default: return "Error";
    }

}

// Einen Text mit dem Namen des Spielers und seiner Wahl ausgeben
void print_choice(Player player)
{
    string choice = get_name(player.choice);
    cout << player.name << " hat das Objekt " << choice << " gewählt" << endl;
}

// Die Wahl des Spielers abfragen
Object choose()
{
    int choice;

    do{
        cout << "Bitte Objektwahl eingeben (1 = Stein, 2 = Schere, 3 = Papier): ";
        cin >> choice;
    }while(choice != 1 && choice != 2 && choice != 3);

    switch(choice){
        case 1: return Object::ROCK;
        case 2: return Object::SCISSORS;
        case 3: return Object::PAPER;
        default: return static_cast<Object>(0);
    }
}

Result determine_result(Player player_1, Player player_2) {
    // Ergebnis bestimmen (Differenzberechnung z.B. p1: 1, p2: 2 -> 1 == (2+1)%3 -> 1 == 1 p2 win)
    if (static_cast<int>(player_1.choice) == static_cast<int>(player_2.choice)) {
        return Result::DRAW;
    } else if (static_cast<int>(player_1.choice) == ((static_cast<int>(player_2.choice))+1)%3) {
        return Result::PLAYER_TWO_WINS;
    } else {
        return Result::PLAYER_ONE_WINS;
    }
}

void print_result(Player player_1, Player player_2)
{
    Result result = determine_result(player_1, player_2);
    switch(result){
        case Result::PLAYER_ONE_WINS: cout << "Spieler " << player_1.name << " hat gewonnen." << endl;
            break;
        case Result::PLAYER_TWO_WINS: cout << "Spieler " << player_2.name << " hat gewonnen." << endl;
            break;
        case Result::DRAW: cout << "Unentschieden" << endl;
            break;
    }

}

int main(int argc, char *argv[])
{
    Player player_1, player_2;
    player_1.name = "Computer";
    player_2.name = insert_name();
    player_1.choice = determine_choice(player_2.name);
    cout << "Der Computer hat seine Wahl getroffen." << endl;
    player_2.choice = choose();
    print_choice(player_1);
    print_choice(player_2);
    print_result(player_1, player_2);

    return 0;
}

