//
// Created by marek on 12.02.16.
//

#ifndef INTERMEDIATE_238_FALLOUTHACKING_HACKENGINE_H
#define INTERMEDIATE_238_FALLOUTHACKING_HACKENGINE_H


#include <vector>
#include <string>
#include "Dictionary.h"

class HackEngine {

public:
    HackEngine(int difficulty = 4);
    HackEngine(int wordlen, int wordcount, int guesscount = 4);
    HackEngine(const Dictionary& dictionary, int difficulty = 4);
    HackEngine(const Dictionary& dictionary, int wordlen, int wordcount, int guesscount = 4);

    // changing difficulty also sets guesses_left to guesscount
    void changeDifficulty(int difficulty);
    // more specific difficulty setting
    void changeDifficulty(int wordlen, int wordcount, int guesscount = 4);

    void loadPasswords();
    void clearPasswords();

    void restartGame();

    // returns number of places that fits password
    int checkWord(int index);
    int checkWord(std::string word);

    int getGuessesLeft();
    std::vector<std::string> getWords();
    int getWordsLength();

    void decrementGuesses();

private:
    std::vector<std::string> words;
    std::string password;

    int guesses_left;

    int wordlen, wordcount, guesscount;
    Dictionary dict;
};


#endif //INTERMEDIATE_238_FALLOUTHACKING_HACKENGINE_H
