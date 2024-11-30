#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()
#include <limits>   // For numeric_limits

using namespace std;

// Function to set the difficulty level
int setDifficulty() {
    int level;
    cout << "\nChoose a difficulty level: \n";
    cout << "1. Easy (1 to 50, Unlimited attempts)\n";
    cout << "2. Medium (1 to 100, 10 attempts)\n";
    cout << "3. Hard (1 to 1000, 5 attempts)\n";
    cout << "Enter your choice: ";
    cin >> level;

    while (level < 1 || level > 3) {
        cout << "Invalid choice. Please choose 1, 2, or 3: ";
        cin >> level;
    }
    return level;
}

// Function to get the player's guess
int getGuess() {
    int guess;
    cout << "Enter your guess: ";
    while (!(cin >> guess)) {  // Ensure valid input
        cout << "Invalid input! Please enter a number: ";
        cin.clear(); // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore any remaining characters
    }
    return guess;
}

// Function to play the game
void playGame(int minRange, int maxRange, int maxAttempts) {
    srand(static_cast<unsigned int>(time(0)));  // Initialize random seed
    int randomNumber = rand() % (maxRange - minRange + 1) + minRange;  // Generate random number within range
    int attempts = 0;
    int guess;

    cout << "I have selected a number between " << minRange << " and " << maxRange << ".\n";

    while (attempts < maxAttempts || maxAttempts == -1) {
        guess = getGuess();
        attempts++;

        if (guess == randomNumber) {
            cout << "Congratulations! You guessed the correct number in " << attempts << " attempts.\n";
            return;
        } else if (guess > randomNumber) {
            cout << "Too high! Try again.\n";
        } else {
            cout << "Too low! Try again.\n";
        }

        if (maxAttempts != -1 && attempts == maxAttempts) {
            cout << "Sorry! You've run out of attempts. The correct number was " << randomNumber << ".\n";
            return;
        }
    }
}

int main() {
    cout << "=== Welcome to the Advanced Number Guessing Game ===\n";

    int difficulty = setDifficulty();
    int minRange, maxRange, maxAttempts;

    // Set range and attempts based on difficulty
    switch (difficulty) {
        case 1:  // Easy
            minRange = 1;
            maxRange = 50;
            maxAttempts = -1;  // Unlimited attempts
            break;
        case 2:  // Medium
            minRange = 1;
            maxRange = 100;
            maxAttempts = 10;  // 10 attempts
            break;
        case 3:  // Hard
            minRange = 1;
            maxRange = 1000;
            maxAttempts = 5;  // 5 attempts
            break;
    }

    playGame(minRange, maxRange, maxAttempts);

    // Signature
    cout << "\nGame developed by: Software Engineer Muhammad Adnan\n";

    return 0;
}

