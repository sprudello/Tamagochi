#include <iostream>
using namespace std;

class Tamagotchi {
private:
    int hunger;
    int happiness;
    int energy;
    int thurst;
    int walk;

public:
    Tamagotchi() : hunger(50), happiness(50), energy(50), thurst(50), walk(50){}


    void feed() {
        hunger -= 20;
    }

    void play() {
        happiness += 20;
        energy -= 5;
    }

    void rest() {
        energy += 20;
        hunger += 5;
    }
    void drink() {
        thurst -= 20;
    }

    void go_walk() {
        walk += 20;
    }

    void update() {

        hunger += 5;
        happiness -= 5;
        energy -= 5;
        thurst += 5;
        walk -= 5;
    }

    bool isAlive() {
        return thurst > 0 && hunger > 0 && walk > 0 && happiness > 0 && energy > 0;
    }

    void displayStats() {
        cout << "Hunger: " << hunger << " | Happiness: " << happiness << " | Energy: " << energy << " | Thurst: "<< thurst << " | Wants to go for a Walk: "<< walk <<"\n";
    }
    string chooseTamagotchi() {
        cout << "1. Fish\n";
        cout << "2. Cat\n";
        cout << "3. Pickmin\n";
        cout << "4. Kermit\n";
        cout << "5. Amoeba\n";
        cout << "Which Tamagotchi would you like?: ";
        int choice;
        string tamagotchi;
        cin >> choice;
        switch(choice){
            case 1:
                tamagotchi = "Fish";
                break;

            case 2:
                tamagotchi = "Cat";
                break;

            case 3:
                tamagotchi = "Pickmin";
                break;

            case 4:
                tamagotchi = "Kermit";
                break;

            case 5:
                tamagotchi = "Amoeba";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }
        return tamagotchi;

    }
};

int main() {
    Tamagotchi pet;

    cout << "Welcome to Tamagotchi Console Game!\n";
    string tamagotchi = pet.chooseTamagotchi();


    while (pet.isAlive()) 
        pet.displayStats();
        cout << "1. Feed\n";
        cout << "2. Play\n";
        cout << "3. Rest\n";
        cout << "4. Give drink\n";
        cout << "5. Go walk\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                pet.feed();
                if (tamagotchi == "Fish")
                    cout << "BLUB Lecker BLUB!";

                break;

            case 2:
                pet.play();
                if (tamagotchi == "Fish")
                    cout << "BLUB BLUB BLUB!\n";

                break;

            case 3:
                pet.rest();
                if (tamagotchi == "Fish")
                    cout << "ZZZZZ BLUB ZZZZZ!\n";

                break;

            case 4:
                pet.drink();
                if (tamagotchi == "Fish")
                    cout << "BLUB GLUG GLUG BLUB";

                break;

            case 5:
                pet.go_walk();
                if (tamagotchi == "Fish")
                    cout << "BLUB UIUIUI BLUB!\n";


                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }

        pet.update();
    

    cout << "Your " << tamagotchi <<" has passed away. Game over.\n";

    return 0;
}