#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <limits>
using namespace std;
/**
 *  @file main.cpp
 *
 *  @brief Tamagotchi game implementation in C++
 *
 *  This C++ program simulates a Tamagotchi game where the user can interact with a virtual pet.
 *
 *  @author Keanu Koelewijn, Stefan Jesenko, Julius Burlet
 *  @date 27.10.2023
 */
class Tamagotchi {
private:
    string hungerDisplay, happinessDisplay, energyDisplay, thirstDisplay, loveDisplay, causeOfDeath, chanceDisplay;

public:
    int hunger, happiness, energy, thirst, love, age, turns, chance;

    /// <summary>
    /// Constructor for the Tamagotchi class. Initializes the values of the Tamagotchi instance.
    /// </summary>
    Tamagotchi() : hunger(50), happiness(50), energy(50), thirst(50), love(50), age(0), turns(0), chance(0) {}

    /// <summary>
    /// These methods allow the user to interact with the Tamagotchi by feeding, playing, resting, giving a drink,and cuddling with it. Each action affects the Tamagotchi's hunger, happiness, energy, thirst, and love levels.
    /// </summary>
    void feed() {
        hunger = max(0, hunger - 20);
        energy = max(0, energy + 5);
        happiness = max(0, happiness - 5);
        thirst = max(0, thirst + 5);
    }

    void play() {
        happiness = max(0, happiness + 20);
        energy = max(0, energy - 5);
        hunger = max(0, hunger + 5);
        thirst = max(0, thirst + 5);
    }

    void rest() {
        energy = max(0, energy + 20);
        hunger = max(0, hunger + 5);
        happiness = max(0, happiness - 5);
        thirst = max(0, thirst + 5);
    }

    void drink() {
        thirst = max(0, thirst - 20);
        energy = max(0, energy + 5);
        hunger = max(0, hunger - 10);
        happiness = max(0, happiness - 5);
    }

    void cuddle() {
        love = max(0, love + 20);
        hunger = max(0, hunger + 5);
        energy = max(0, energy + 5);
        thirst = max(0, thirst + 5);
        happiness = max(0, happiness + 10);
    }

    int generateRandomNumber(double probability) {
        int randomNumber = rand() % 101;

        if (randomNumber < probability * 100) {
            return 2;
        } else {
            return 1;
        }
    }

    /// <summary>
    /// Updates the values of the Tamagotchi instance after each turn.
    /// </summary>
    void update() {
        turns++;
        love = max(0, love - 5);
        hunger = max(0, hunger + 5);
        energy = max(0, energy - 5);
        thirst = max(0, thirst + 5);
        happiness = max(0, happiness - 5);
        chance = min(100, max(0, chance));
        chance += 10;
        int randomNum = rand() % 2 + 1;
        switch (randomNum) {
            case 1:
                chance += 5;
                break;
            case 2:
                chance -= 5;
                break;
        }
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

    /// <summary>
    /// Checks if the Tamagotchi is still alive.
    /// </summary>
    /// <returns>True if the Tamagotchi is alive, otherwise false.</returns>
    bool isAlive(){
        if (thirst > 99 || hunger > 99 || love < 1 || happiness < 1 || energy < 1){
            return false;
        }
        else{
            return true;
        }
    }

    /// <summary>
    /// Displays the current statistics of the Tamagotchi, including hunger, happiness, energy, thirst, love, and age.
    /// </summary>
    void displayStats() {
        // Determine chance display
        if (chance >= 85)
            chanceDisplay = "High Chance    ";
        else if (chance >= 65)
            chanceDisplay = "strong Chance  ";
        else if (chance >= 40)
            chanceDisplay = "mid Chance     ";
        else if (chance <= 40)
            chanceDisplay = "Low Chance     ";

        // Determine hunger display
        if (hunger >= 85)
            hungerDisplay = "very hungry    ";
        else if (hunger >= 65)
            hungerDisplay = "hungry         ";
        else if (hunger >= 40)
            hungerDisplay = "normal         ";
        else if (hunger <= 40)
            hungerDisplay = "very full      ";

        // Determine happiness display
        if (happiness >= 85)
            happinessDisplay = "very happy     ";
        else if (happiness >= 65)
            happinessDisplay = "happy          ";
        else if (happiness >= 40)
            happinessDisplay = "normal         ";
        else if (happiness <= 40)
            happinessDisplay = "sad            ";

        // Determine energy display
        if (energy >= 85)
            energyDisplay = "too much energy";
        else if (energy >= 65)
            energyDisplay = "much energy    ";
        else if (energy >= 40)
            energyDisplay = "normal         ";
        else if (energy <= 40)
            energyDisplay = "little energy  ";

        // Determine thirst display
        if (thirst >= 85)
            thirstDisplay = "very thirsty   ";
        if (thirst >= 65)
            thirstDisplay = "little thirsty ";
        else if (thirst >= 40)
            thirstDisplay = "normal         ";
        else if (thirst <= 40)
            thirstDisplay = "not thirsty    ";

        // Determine love display
        if (love >= 85)
            loveDisplay = "loves you      ";
        if (love >= 65)
            loveDisplay = "loving         ";
        else if (love >= 40)
            loveDisplay = "normal         ";
        else if (love <= 40)
            loveDisplay = "lonely         ";

        cout << "\n-----------------------------------------------------------\n"
                "|   Stat          |   Display        |   Percentage    |\n"
                "-----------------------------------------------------------\n"
                "|  Hunger         |   " << hungerDisplay << "|      " << hunger << "%        |\n"
                "|  Happiness      |   " << happinessDisplay << "|      " << happiness << "%        |\n"
                "|  Energy         |   " << energyDisplay << "|      " << energy << "%        |\n"
                "|  Thirst         |   " << thirstDisplay << "|      " << thirst << "%        |\n"
                "|  Love           |   " << loveDisplay << "|      " << love << "%        |\n"
                "|  Age            |   " << age << "              |  not available  |\n"
                "|  Chance to find |   " << chanceDisplay << "|       " << chance << "%        |\n"
                "-----------------------------------------------------------\n";
    }

    /// <summary>
    /// Static method that prompts the user to choose a Tamagotchi and returns the selected type as a string.
    /// </summary>
    /// <returns>The selected Tamagotchi type as a string.</returns>
    static string chooseTamagotchi() {
        while(true) {
            cout << "\n.---------.--------.------------.-----------.-----------.\n"
                    "| 1. Fish | 2. Cat | 3. Pickmin | 4. Kermit | 5. Amoeba |\n"
                    "'---------'--------'------------'-----------'-----------'\nWhich Tamagotchi would you like?:\n";
            int choice;
            string tamagotchi;

            // I don't know what this does exactly, but it fixes an issue with cin in loops
            if (!(cin >> choice)) {
                cout << "Invalid input. Please enter a number." << std::endl;
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            switch (choice) {
                case 1:
                    tamagotchi = "Fish";
                    return tamagotchi;
                case 2:
                    tamagotchi = "Cat";
                    return tamagotchi;
                case 3:
                    tamagotchi = "Pickmin";
                    return tamagotchi;
                case 4:
                    tamagotchi = "Kermit";
                    return tamagotchi;
                case 5:
                    tamagotchi = "Amoeba";
                    return tamagotchi;
                default:
                    cout << "Invalid choice. Try again.\n";
                    continue;
            }
        }
    }

    /// <summary>
    /// Returns the age of the Tamagotchi.
    /// </summary>
    /// <returns>The age of the Tamagotchi.</returns>
    [[nodiscard]] int getAge() const {
        return age;
    }

    /// <summary>
    /// Returns the cause of death of the Tamagotchi.
    /// </summary>
    /// <returns>The cause of death of the Tamagotchi as a string.</returns>
    [[nodiscard]] string getCauseOfDeath() const {
        return causeOfDeath;
    }
};

class Game {
public:
    static void GameLogic() {
        /// <summary>
        /// Main logic of the Tamagotchi game. Creates a Tamagotchi, lets the user interact, and monitors the end of the game.
        /// </summary>
        Tamagotchi pet;
        cout << "Welcome to Tamagotchi Console Game!\n";
        string tamagotchi = pet.chooseTamagotchi();

        while (pet.isAlive()) {
            while(true){
                pet.displayStats();
                cout << ".---------.---------.---------.---------------.-----------.-------------------------------------.\n"
                        "| 1. Feed | 2. Play | 3. Rest | 4. Give drink | 5. Cuddle | 6. Find something for Pet outdoors. |\n"
                        "'---------'---------'---------'---------------'-----------'-------------------------------------'\n"
                        "Enter your choice: \n";
                int choice;
                if (!(cin >> choice)) {
                    cout << "Invalid input. Please enter a number." << std::endl;
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    continue;
                }
                string reaction;

                switch (choice) {
                    case 1:
                        pet.feed();
                        if (tamagotchi == "Fish")
                            reaction = "BLUB yummy BLUB!\n";
                        else if (tamagotchi == "Cat")
                            reaction = "Nom nom purr!\n";
                        else if (tamagotchi == "Pickmin")
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
                        else if (tamagotchi == "Pickmin")
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
                        else if (tamagotchi == "Pickmin")
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
                        else if (tamagotchi == "Pickmin")
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
                        else if (tamagotchi == "Pickmin")
                            reaction = "Pikmin enjoys the cuddle!\n";
                        else if (tamagotchi == "Kermit")
                            reaction = "Feels warm and cuddly, ribbit!\n";
                        else if (tamagotchi == "Amoeba")
                            reaction = "Amoeba quivers in a cuddly embrace!\n";
                        break;

                    case 6: {
                        srand(static_cast<unsigned int>(time(nullptr)));
                        double probabilityOfTwo = static_cast<double>(pet.chance) / 100.0;
                        int randomNum = pet.generateRandomNumber(probabilityOfTwo);

                        if (randomNum == 1) {
                            cout << "You found Nothing, your Chances drop to find something for your Pet.";
                            if (pet.chance > 15)
                                pet.chance = 15;
                            else
                                pet.chance = 0;
                        } else if (randomNum == 2) {
                            int effect;
                            string stat;
                            string item;
                            srand(time(0));
                            int random = rand() % 5;
                            switch (random) {
                                case 0:
                                    item = "Cozy Pillow";
                                    stat = "Energy";
                                    effect = 10;
                                    pet.energy += effect;
                                    break;
                                case 1:
                                    item = "Juicy Fruit Snack";
                                    stat = "Hunger";
                                    effect = -10;
                                    pet.hunger += effect;
                                    break;
                                case 2:
                                    item = "Miniature Ball Pit";
                                    stat = "Happiness";
                                    effect = 10;
                                    pet.happiness += effect;
                                    break;
                                case 3:
                                    item = "Sparkling Water bowl";
                                    stat = "Thirst";
                                    effect = -10;
                                    pet.thirst += effect;
                                    break;
                                case 4:
                                    item = "Cuddle Plushie";
                                    stat = "Love";
                                    effect = 10;
                                    pet.love += effect;
                                    break;
                                default:
                                    cout << "Invalid choice. Try again.\n";
                                    break;
                            }
                            cout << "You found a " << item << "! Your " << tamagotchi << " gets " << effect << " " << stat << "!";
                            if (pet.chance > 15)
                                pet.chance = 15;
                            else
                                pet.chance = 0;
                        }
                        break;
                    }
                    default:
                        cout << "Invalid choice. Try again.\n";
                        bool validChoice = false;
                        break;
                }
                if (choice == 1 || choice == 2 || choice == 3 || choice == 4 || choice == 5) {
                    cout << "-------------------------------------------------------------\n"
                            "Your " << tamagotchi << " reacted with: " << reaction << "";
                }
                pet.update();
                break;
            }
        }
        while(true){
            cout << "\n-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_\n"
                    "Your " << tamagotchi << " has passed away at age " << pet.getAge() << " and " << pet.getCauseOfDeath() << ". Game over.\n"
                    "-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_\n"
                    "\n"
                    ".---------------.---------------.\n"
                    "| 1. Play again | 2. Close Game |\n"
                    "'---------------'---------------'\n"
                    "Enter your choice: \n";
            int choice;
            if (!(cin >> choice)) {
                cout << "Invalid input. Please enter a number." << std::endl;
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            switch (choice) {
                case 1:
                    GameLogic();
                    break;
                case 2:
                    return;
                    break;
                default:
                    cout << "Invalid choice. Try again.\n";
                    bool validChoice = false;
                    break;
            }
        }

    }
};

int main() {
    srand(time(0));
    Game::GameLogic();
    return 0;
}