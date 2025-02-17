#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <cctype>
#include "chord.hpp"
#include "chordProgression.hpp"

// Helper function: split a string by whitespace into tokens.
std::vector<std::string> split(const std::string &s) {
    std::istringstream iss(s);
    std::vector<std::string> tokens;
    std::string token;
    while (iss >> token)
        tokens.push_back(token);
    return tokens;
}

// Helper function: transpose a key by a given number of semitones.
// Our Note enum is 1-indexed.
Note transposeKey(Note key, int semitones) {
    int newVal = (static_cast<int>(key) - 1 + semitones) % 12;
    if (newVal < 0)
        newVal += 12;
    newVal += 1;
    return static_cast<Note>(newVal);
}

// Read an integer from user input.
int readInteger() {
    int num;
    while (!(std::cin >> num)) {
        std::cin.clear();
        std::string dummy;
        std::getline(std::cin, dummy);
        std::cout << "Invalid number. Please enter an integer: ";
    }
    std::cin.ignore(); // clear newline
    return num;
}

int main() {
    std::cout << "=== Chord/Progression Converter & Transposer ===\n";

    ChordProgression originalProg, currentProg;
    Note originalKey, currentKey;
    bool usingRomanInput = false; // true if user initially entered roman numeral tokens

    // Outer loop: input new progression or exit.
    while (true) {
        std::cout << "\nEnter input type ('roman' for roman numeral progression or 'chords' for chord progression), or 'exit' to quit: ";
        std::string inputType;
        std::getline(std::cin, inputType);
        if (inputType == "exit")
            break;

        if (inputType != "roman" && inputType != "chords") {
            std::cout << "Invalid input type. Please type 'roman' or 'chords'.\n";
            continue;
        }
        usingRomanInput = (inputType == "roman");

        // Ask for key.
        std::cout << "Enter key (e.g., C, C#, Db, etc.): ";
        std::string keyStr;
        std::getline(std::cin, keyStr);
        Note key;
        try {
            key = stringToNote(keyStr);
        } catch (const std::exception &e) {
            std::cout << "Error: " << e.what() << "\n";
            continue;
        }
        originalKey = key;
        currentKey = key;

        // Ask for progression.
        if (usingRomanInput)
            std::cout << "Enter roman numeral progression (space-separated, e.g., I vi IV V): ";
        else
            std::cout << "Enter chord progression (space-separated, e.g., C Am F G or C#m7 Gdim ...): ";

        std::string progLine;
        std::getline(std::cin, progLine);
        std::vector<std::string> tokens = split(progLine);
        if (tokens.empty()) {
            std::cout << "No progression tokens provided.\n";
            continue;
        }

        try {
            if (usingRomanInput) {
                // Create progression using roman numeral constructor.
                originalProg = ChordProgression(tokens, key);
            } else {
                // For chords, convert each token into a Chord using Chord::fromString.
                std::vector<Chord> chordList;
                for (const auto &tok : tokens) {
                    chordList.push_back(Chord::fromString(tok));
                }
                originalProg = ChordProgression(chordList);
            }
        } catch (const std::exception &e) {
            std::cout << "Error creating progression: " << e.what() << "\n";
            continue;
        }
        // Set current progression to original.
        currentProg = originalProg;

        std::cout << "\n--- Progression Loaded ---\n";
        if (usingRomanInput) {
            std::cout << "Input (roman numerals): ";
            // Display the roman numeral analysis (the tokens joined by space)
            for (const auto &tok : tokens)
                std::cout << tok << " ";
            std::cout << "\nConverted to chords: " << originalProg << "\n";
        } else {
            std::cout << "Input chords: " << originalProg << "\n";
            std::cout << "Roman numeral analysis (relative to key " << noteToString(key) << "): " 
                      << originalProg.toRomanNumerals(key) << "\n";
        }

        // Inner loop: operations on the current progression.
        bool innerLoop = true;
        while (innerLoop) {
            std::cout << "\nChoose an operation:\n"
                      << "  (t) Transpose\n"
                      << "  (c) Convert\n"
                      << "  (e) Exit to main menu\n"
                      << "Enter choice: ";
            std::string choice;
            std::getline(std::cin, choice);
            if (choice == "t" || choice == "T") {
                std::cout << "Enter number of semitones to transpose (can be negative): ";
                int semitones = readInteger();
                currentProg = currentProg.transpose(semitones);
                currentKey = transposeKey(currentKey, semitones);
                std::cout << "Progression transposed by " << semitones << " semitones.\n";
                if (usingRomanInput) {
                    // If originally roman, show chords.
                    std::cout << "Resulting chords: " << currentProg << "\n";
                } else {
                    // If originally chords, show roman numeral analysis.
                    std::cout << "Roman numeral analysis (key " << noteToString(currentKey) << "): " 
                              << currentProg.toRomanNumerals(currentKey) << "\n";
                }
            } else if (choice == "c" || choice == "C") {
                if (usingRomanInput) {
                    // Conversion: roman numeral input converted to chords.
                    std::cout << "Chord progression: " << currentProg << "\n";
                } else {
                    // Conversion: chord input converted to roman numeral analysis.
                    std::cout << "Roman numeral analysis (key " << noteToString(currentKey) << "): " 
                              << currentProg.toRomanNumerals(currentKey) << "\n";
                }
            } else if (choice == "e" || choice == "E") {
                // Exit inner loop to allow new progression input.
                innerLoop = false;
                break;
            } else {
                std::cout << "Invalid choice.\n";
                continue;
            }

            // Ask how to continue.
            std::cout << "\nWhat next?\n"
                      << "  (o) Use original progression\n"
                      << "  (c) Continue with current progression\n"
                      << "  (n) Input a new progression\n"
                      << "  (q) Quit the program\n"
                      << "Enter choice: ";
            std::string nextChoice;
            std::getline(std::cin, nextChoice);
            if (nextChoice == "o" || nextChoice == "O") {
                currentProg = originalProg;
                currentKey = originalKey;
                std::cout << "Reset to original progression.\n";
            } else if (nextChoice == "c" || nextChoice == "C") {
                // Continue with the current (possibly transposed) progression.
                continue;
            } else if (nextChoice == "n" || nextChoice == "N") {
                // Break out to outer loop to input a new progression.
                innerLoop = false;
            } else if (nextChoice == "q" || nextChoice == "Q") {
                std::cout << "Exiting program.\n";
                return 0;
            } else {
                std::cout << "Invalid choice, continuing with current progression.\n";
            }
        } // end inner loop
    } // end outer loop

    std::cout << "Goodbye!\n";
    return 0;
}

