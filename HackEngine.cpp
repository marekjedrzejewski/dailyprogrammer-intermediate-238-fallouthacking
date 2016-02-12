//
// Created by marek on 12.02.16.
//

#include "HackEngine.h"
#include <algorithm>

HackEngine::HackEngine(int difficulty) {
    dict = Dictionary();
    changeDifficulty(difficulty);
    loadPasswords();
}

HackEngine::HackEngine(int wordlen, int wordcount, int guesscount) {
    dict = Dictionary();
    changeDifficulty(wordlen, wordcount, guesscount);
    loadPasswords();
}

HackEngine::HackEngine(const Dictionary& dictionary, int difficulty) {
    dict = dictionary;
    changeDifficulty(difficulty);
    loadPasswords();
}

HackEngine::HackEngine(const Dictionary& dictionary, int wordlen, int wordcount, int guesscount) {
    dict = dictionary;
    changeDifficulty(wordlen, wordcount, guesscount);
    loadPasswords();
}

void HackEngine::changeDifficulty(int difficulty) {
    // if someone's playing outside range... Too bad for him!
    if (difficulty > 10 || difficulty < 0)
        changeDifficulty(10);
    else {
        changeDifficulty(difficulty + 3, difficulty + 5);
    }
}

void HackEngine::changeDifficulty(int wordlen, int wordcount, int guesscount) {
    // can't allow guesscount 0 or less
    guesscount = std::max(1, guesscount);
    // can't allow 1-letter words or negatives
    wordlen = std::max(2, wordlen);
    // can't allow wordcount smaller than guesscount. too easy.
    wordcount = std::max(guesscount+1, wordcount);

    // watching over limits
    this->wordlen = std::min(wordlen, dict.getMaxWordLength());
    this->wordcount = std::min(wordcount, dict.getNumberOfWordsOfLength(this->wordlen));
    this->guesscount = guesscount;
    guesses_left = guesscount;
}

void HackEngine::loadPasswords() {
    clearPasswords();
    while (words.size() < wordcount) {
        std::string word = dict.getRandomWordOfLength(wordlen);
        if (std::find(words.begin(), words.end(), word) == words.end())
            words.push_back(word);
    }

    password = words[0];
    // sorting mainly for hiding the password position. Aesthetics comes second here.
    std::sort(words.begin(), words.end());
}

void HackEngine::clearPasswords() {
    words.clear();
    password.clear();
}

int HackEngine::getGuessesLeft() {
    return guesses_left;
}

std::vector<std::string> HackEngine::getWords() {
    return words;
}

void HackEngine::decrementGuesses() {
    guesses_left--;
}
