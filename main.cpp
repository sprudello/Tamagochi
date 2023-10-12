#include <iostream>
#include <string>
using namespace std;

class Tamagotchi {
private:
    int hunger, happiness, energy, thirst, love, age, turns;
    string hungerDisplay, happinessDisplay, energyDisplay, thirstDisplay, loveDisplay, causeOfDeath;

public:
    Tamagotchi() : hunger(50), happiness(50), energy(50), thirst(50), love(50), age(0), turns(0) {}

    void feed() { hunger -= 20; energy += 5; happiness -= 5; thirst += 5;}
    void play() { happiness += 20; energy -= 5; hunger += 5; thirst += 5;}
    void rest() { energy += 20; hunger += 5; happiness -= 5; thirst += 5;}
    void drink() { thirst -= 20; energy += 5; hunger -= 10; happiness -= 5;}
    void cuddle() { love += 20; hunger += 5; energy += 5; thirst += 5; happiness += 15;}

    void update() {
        turns++;
        hunger += 5;
        happiness -= 5;
        energy -= 5;
        thirst += 5;
        love -= 5;
        if (turns % 5 == 0) {
            age++;
        }

        if (thirst >= 100)
            causeOfDeath = "died of thirst";
        else if (hunger >= 100)
            causeOfDeath = "died of hunger";
        else if (love <= 0)
            causeOfDeath = "died of loneliness";
        else if (happiness <= 0)
            causeOfDeath = "died of sadness";
        else if (energy <= 0)
            causeOfDeath = "died of lack of energy";
    }

    [[nodiscard]] bool isAlive() const {
        return thirst < 100 && hunger < 100 && love > 0 && happiness > 0 && energy > 0;
    }

    void displayStats() {
        // Determine hunger display
        if (hunger >= 75)
            hungerDisplay = "little hungry  ";
        else if (hunger >= 50)
            hungerDisplay = "normal         ";
        else if (hunger >= 25)
            hungerDisplay = "very full      ";
        else
            hungerDisplay = "very hungry    ";

        // Determine happiness display
        if (happiness >= 75)
            happinessDisplay = "happy          ";
        else if (happiness >= 50)
            happinessDisplay = "normal         ";
        else if (happiness >= 25)
            happinessDisplay = "sad            ";
        else
            happinessDisplay = "very happy";

        // Determine energy display
        if (energy >= 75)
            energyDisplay = "much energy    ";
        else if (energy >= 50)
            energyDisplay = "normal         ";
        else if (energy >= 25)
            energyDisplay = "little energy  ";
        else
            energyDisplay = "too much energy";

        // Determine thirst display
        if (thirst >= 100)
            thirstDisplay = "very thirsty   ";
        else if (thirst >= 75)
            thirstDisplay = "little thirsty ";
        else if (thirst >= 50)
            thirstDisplay = "normal         ";
        else
            thirstDisplay = "not thirsty    ";

        // Determine love display
        if (love >= 75)
            loveDisplay = "loving         ";
        else if (love >= 50)
            loveDisplay = "normal         ";
        else if (love >= 25)
            loveDisplay = "lonely         ";
        else
            loveDisplay = "loves you      ";

        if (hunger > 100 || love > 100 || energy > 100 || happiness > 100 || thirst > 100) {

            if (hunger > 100)
                hunger = 100;
            if (love > 100)
                love = 100;
            if (energy > 100)
                energy = 100;
            if (happiness > 100)
                happiness = 100;
            if (thirst > 100)
                thirst = 100;
        }
        else if (hunger < 0 || love < 0 || energy < 0 || happiness < 0 || thirst < 0) {
            if (hunger < 0)
                hunger = 0;
            if (love < 0)
                love = 0;
            if (energy < 0)
                energy = 0;
            if (happiness < 0)
                happiness = 0;
            if (thirst < 0)
                thirst = 0;
        }

        // Display the stats
        // Display the stats in a table format
        cout << "-----------------------------------------------------------\n";
        cout << "|   Stat     |   Display        |   Percentage   |\n";
        cout << "-----------------------------------------------------------\n";
        cout << "|  Hunger    |   " << hungerDisplay << "|      " << hunger << "%        |\n";
        cout << "|  Happiness |   " << happinessDisplay << "|      " << happiness << "%        |\n";
        cout << "|  Energy    |   " << energyDisplay << "|      " << energy << "%        |\n";
        cout << "|  Thirst    |   " << thirstDisplay << "|      " << thirst << "%        |\n";
        cout << "|  Love      |   " << loveDisplay << "|      " << love << "%        |\n";
        cout << "|  Age       |   " << age << "              |  not available  |\n";
        cout << "-----------------------------------------------------------\n";
    }


    static string chooseTamagotchi() {
        cout << "\n.---------.--------.------------.-----------.-----------.\n";
        cout << "| 1. Fish | 2. Cat | 3. Pickmin | 4. Kermit | 5. Amoeba |\n";
        cout << "'---------'--------'------------'-----------'-----------'\nWhich Tamagotchi would you like?:\n";
        int choice;
        string tamagotchi;
        cin >> choice;
        switch (choice) {
            case 1: tamagotchi = "Fish"; break;
            case 2: tamagotchi = "Cat"; break;
            case 3: tamagotchi = "Pickmin"; break;
            case 4: tamagotchi = "Kermit"; break;
            case 5: tamagotchi = "Amoeba"; break;
            default: cout << "Invalid choice. Try again.\n"; break;
        }
        return tamagotchi;
    }
    public: [[nodiscard]] int getAge() const {
        return age;
    }

    public: [[nodiscard]] string getCauseOfDeath() const {
        return causeOfDeath;
    }
};

class Game {
    public: static void GameLogic() {
        Tamagotchi pet;
        cout << "Welcome to Tamagotchi Console Game!\n";
        string tamagotchi = pet.chooseTamagotchi();

        while (pet.isAlive()) {
            pet.displayStats();
            cout << ".---------.---------.---------.---------------.-----------.\n";
            cout << "| 1. Feed | 2. Play | 3. Rest | 4. Give drink | 5. Cuddle |\n";
            cout << "'---------'---------'---------'---------------'-----------'\n";
            cout << "Enter your choice: \n";
            int choice;
            cin >> choice;
            string reaction;

            switch (choice) {
                case 1:
                    pet.feed();
                    if (tamagotchi == "Fish")
                        reaction = "BLUB yummy BLUB!\n";
                    else if (tamagotchi == "Cat")
                        reaction = "Nom nom purr!\n";
                    else if (tamagotchi == "Pikmin")
                        reaction = "Pikmin happily eats!\n";
                    else if (tamagotchi == "Kermit")
                        reaction = "Munch munch ribbit!\n";
                    else if (tamagotchi == "Amoeba")
                        reaction = "Amoeba engulfs nutrients!\n";
                    break;

                case 2:
                    pet.play();
                    if (tamagotchi == "Fish")
                        reaction = "BLUB BLUB BLUB!\n";
                    else if (tamagotchi == "Cat")
                        reaction = "Purrrrrr!\n";
                    else if (tamagotchi == "Pikmin")
                        reaction = "Pikmin happily frolics!\n";
                    else if (tamagotchi == "Kermit")
                        reaction = "Jump and croak!\n";
                    else if (tamagotchi == "Amoeba")
                        reaction = "Amoeba undulates in excitement!\n";
                    break;

                case 3:
                    pet.rest();
                    if (tamagotchi == "Fish")
                        reaction = "ZZZZZ BLUB ZZZZZ!\n";
                    else if (tamagotchi == "Cat")
                        reaction = "Purrrrrr, nap time!\n";
                    else if (tamagotchi == "Pikmin")
                        reaction = "Pikmin takes a little nap!\n";
                    else if (tamagotchi == "Kermit")
                        reaction = "Resting and dreaming of flies!\n";
                    else if (tamagotchi == "Amoeba")
                        reaction = "Amoeba takes a break from dividing!\n";
                    break;

                case 4:
                    pet.drink();
                    if (tamagotchi == "Fish")
                        reaction = "BLUB GLUG GLUG BLUB";
                    else if (tamagotchi == "Cat")
                        reaction = "Slurp, purr!\n";
                    else if (tamagotchi == "Pikmin")
                        reaction = "Pikmin sips some nectar!\n";
                    else if (tamagotchi == "Kermit")
                        reaction = "Gulp gulp, ribbit!\n";
                    else if (tamagotchi == "Amoeba")
                        reaction = "Amoeba absorbs water!\n";
                    break;

                case 5:
                    pet.cuddle();
                    if (tamagotchi == "Fish")
                        reaction = "BLUB loves the cuddles!\n";
                    else if (tamagotchi == "Cat")
                        reaction = "Purrs and snuggles!\n";
                    else if (tamagotchi == "Pikmin")
                        reaction = "Pikmin enjoys the cuddle!\n";
                    else if (tamagotchi == "Kermit")
                        reaction = "Feels warm and cuddly, ribbit!\n";
                    else if (tamagotchi == "Amoeba")
                        reaction = "Amoeba quivers in a cuddly embrace!\n";
                    break;

                default:
                    cout << "Invalid choice. Try again.\n";
                    break;
            }
            cout << "-------------------------------------------------------------\n";
            cout << "Your " << tamagotchi << " reacts with: " << reaction << "\n";
            cout << "-------------------------------------------------------------\n";
            pet.update();
        }
        cout << "-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_\n";
        cout << "Your " << tamagotchi << " has passed away at age " << pet.getAge() << " due to " << pet.getCauseOfDeath() << ". Game over.\n";
        cout << "-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_\n";
        cout << "\n";
        cout << ".---------------.---------------.\n";
        cout << "| 1. Play again | 2. Close Game |\n";
        cout << "'---------------'---------------'\n";
        cout << "Enter your choice: \n";
        int choice;
        cin >> choice;
        switch (choice) {
            case 1:
                GameLogic();
                break;
            case 2:
                return;
                break;
        }
    }
};

int main() {
    Game::GameLogic();
    return 0;
}