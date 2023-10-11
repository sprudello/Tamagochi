#include <iostream>
#include <string>
using namespace std;

class Tamagotchi {
private:
    int hunger, happiness, energy, thurst, love, age, turns;
    string hungerdisplay, happinessdisplay, energydisplay, thurstdisplay, lovedisplay, causeOfDeath;

public:
    Tamagotchi() : hunger(50), happiness(50), energy(50), thurst(50), love(50), age(0), turns(0) {}

    void feed() { hunger -= 20; energy += 5; happiness -= 5; thurst += 5;}
    void play() { happiness += 20; energy -= 5; hunger += 5; thurst += 5;}
    void rest() { energy += 20; hunger += 5; happiness -= 5; thurst += 5;}
    void drink() { thurst -= 20; energy += 5; hunger -= 10; happiness -= 5;}
    void cuddle() { love += 20; hunger += 5; energy += 5; thurst += 5; happiness += 15;}

    void update() {
        turns++;
        hunger += 5;
        happiness -= 5;
        energy -= 5;
        thurst += 5;
        love -= 5;
        if (turns % 5 == 0) {
            age++;
        }

        if (thurst >= 100)
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

    bool isAlive() {
        return thurst < 100 && hunger < 100 && love > 0 && happiness > 0 && energy > 0;
    }

    void displayStats() {
        // Determine hunger display
        if (hunger < 25)
            hungerdisplay = "very full";
        else if (hunger <= 50)
            hungerdisplay = "normal";
        else if (hunger < 75)
            hungerdisplay = "little hungry";
        else
            hungerdisplay = "very hungry";

        // Determine happiness display
        if (happiness < 25)
            happinessdisplay = "sad";
        else if (happiness <= 50)
            happinessdisplay = "normal";
        else if (happiness < 75)
            happinessdisplay = "happy";
        else
            happinessdisplay = "very happy";

        // Determine energy display
        if (energy < 25)
            energydisplay = "almost dead";
        else if (energy <= 50)
            energydisplay = "normal";
        else if (energy < 75)
            energydisplay = "much energy";
        else
            energydisplay = "too much energy";

        // Determine thirst display
        if (thurst > 100)
            thurstdisplay = "very thirsty";
        else if (thurst > 75)
            thurstdisplay = "little thirsty";
        else if (thurst >= 50)
            thurstdisplay = "normal";
        else
            thurstdisplay = "not thirsty at all";

        // Determine love display
        if (love < 25)
            lovedisplay = "lonely";
        else if (love <= 50)
            lovedisplay = "normal";
        else if (love < 75)
            lovedisplay = "loving";
        else
            lovedisplay = "loves you very much";

        // Display the stats
        cout << "---------------------------------------------------------------------------------------------------------------------\n";
        cout << "Hunger: " << hungerdisplay << "(" << hunger << ")" << " | Happiness: " << happinessdisplay << "(" << happiness << ")" << " | Energy: " << energydisplay << "(" << energy << ")" << " | Thurst: " << thurstdisplay << "(" << thurst << ")" << " | Love: " << lovedisplay << "(" << love << ")" << " | Age: " << age << "\n";
        cout << "---------------------------------------------------------------------------------------------------------------------\n";
        cout << "\n";
    }


    string chooseTamagotchi() {
        cout << "1. Fish\n2. Cat\n3. Pickmin\n4. Kermit\n5. Amoeba\nWhich Tamagotchi would you like?:\n";
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

public: int getAge() const {
        return age;
    }

public: string getCauseOfDeath() const {
        return causeOfDeath;
    }
};

int main() {
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
        cout << "Your " << tamagotchi << " reacts with: " << reaction << "\n";
        pet.update();
    }

    cout << "Your " << tamagotchi << " has passed away at age " << pet.getAge() << " due to " << pet.getCauseOfDeath() << ". Game over.\n";
    return 0;
}