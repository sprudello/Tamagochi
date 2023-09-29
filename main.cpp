#include <iostream>
using namespace std;

class Tamagotchi {
private:
    int hunger;
    int happiness;
    int energy;

public:
    Tamagotchi() : hunger(50), happiness(50), energy(50) {}

    void feed() {
        hunger -= 10;
    }

    void play() {
        happiness += 10;
        energy -= 5;
    }

    void rest() {
        energy += 10;
        hunger += 5;
    }

    void update() {
        hunger += 5;
        happiness -= 5;
        energy -= 5;
    }

    bool isAlive() {
        return hunger > 0 && happiness > 0 && energy > 0;
    }

    void displayStats() {
        cout << "Hunger: " << hunger << " | Happiness: " << happiness << " | Energy: " << energy << "\n";
    }
    void chooseTamagotchi() {
        cout << "1. Fish\n";
        cout << "2. Cat\n";
        cout << "3. Pickmin\n";
        cout << "4. Kermit\n";
        cout << "5. Amoeba\n";
    }
};

int main() {
    Tamagotchi pet;

    cout << "Welcome to Tamagotchi Console Game!\n";
    /*pet.chooseTamagotchi();*/

    while (pet.isAlive()) {
        pet.displayStats();
        cout << "1. Feed\n";
        cout << "2. Play\n";
        cout << "3. Rest\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                pet.feed();
                break;

            case 2:
                pet.play();
                break;

            case 3:
                pet.rest();
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }

        pet.update();
    }

    cout << "Your Tamagotchi has passed away. Game over.\n";

    return 0;
}