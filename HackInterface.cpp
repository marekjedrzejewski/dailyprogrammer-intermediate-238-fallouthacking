//
// Created by marek on 12.02.16.
//

#include <vector>
#include <iostream>
#include "HackInterface.h"

HackInterface::HackInterface() {
    engine = HackEngine();
}

void HackInterface::menu() {
    char option;
    do {
        printMenuOptions();
        std::cout << "option: ";
        std::cin >> option;
        switch (tolower(option)) {
            case '1' :
                play();
                break;
            case '2' :
                difficultyLevelSettings();
                break;
            case '3' :
                customDifficultySettings();
                break;
            case 'q' :
            std::cout << "Bye!\n";
                break;
            default:
            std::cout << "Option not recognized.\n";
        }
    } while (tolower(option) != 'q');
}

void HackInterface::play() {
    engine.restartGame();

    std::cout << "\n";
    std::vector<std::string> words = engine.getWords();
    for (int i = 0; i < words.size(); ++i) {
        std::cout << i+1 << " - " << words[i] << "\n";
    }
    std::cout << "\n";

    int choice = 0;
    while (engine.getGuessesLeft() > 0) {
        std::cout << "Enter number [1-" << words.size() << "]: ";
        std::cin >> choice;
        while (choice > words.size() || choice < 1) {
            std::cout << "Invalid number. Enter again: ";
            std::cin >> choice;
        }
        if (engine.checkWord(choice) == engine.getWordsLength()) {
            std::cout << "CONGRATULATIONS! YOU WON! \n\n";
            return;
        }
        else {
            std::cout << engine.checkWord(choice) << "/" << engine.getWordsLength() << " characters matching.\n";
        }
        engine.decrementGuesses();
        std::cout << engine.getGuessesLeft() << " guesses left. ";
    }
    std::cout << "YOU LOST! Maybe another time.\n\n";
}

void HackInterface::printMenuOptions() {
    std::cout << "1 - Play\n";
    std::cout << "2 - Set difficulty level\n";
    std::cout << "3 - Custom difficulty settings\n";
    std::cout << "Q - Quit\n";
}

void HackInterface::difficultyLevelSettings() {
    int difflevel;
    std::cout << "Enter difficulty level (0-10): ";
    std::cin >> difflevel;
    engine.changeDifficulty(difflevel);
    engine.loadPasswords();
}

void HackInterface::customDifficultySettings() {
    int wordlen, wordcount, guesscount;

    std::cout << "Enter word length: ";
    std::cin >> wordlen;

    std::cout << "Enter words count: ";
    std::cin >> wordcount;

    std::cout << "Enter number of guesses: ";
    std::cin >> guesscount;

    engine.changeDifficulty(wordlen, wordcount, guesscount);
    engine.loadPasswords();
}
