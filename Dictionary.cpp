//
// Created by marek on 12.02.16.
//

#include <fstream>
#include <chrono>
#include "Dictionary.h"

const std::string Dictionary::defaultdict = "/home/marek/MEGA/programming_tasks/"
        "dailyprogrammer/intermediate-238-fallouthacking/dict.txt";

Dictionary::Dictionary(std::string filename, int maxlen) {
    // len will be index, so we can live with words[0] being empty.
    words = std::vector<std::vector<std::string>>(maxlen+1);

    std::ifstream dictfile;
    dictfile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try {
        dictfile.open(filename);
        while(!dictfile.eof()) {
            std::string word;
            dictfile >> word;
            if (word.size() > maxlen) continue;
            // put word to vector containing the proper size
            words[word.size()].push_back(word);
        }
        dictfile.close();
    }
    catch (std::ifstream::failure e){
        throw e;
    }

    initRandom();
}

std::string Dictionary::getRandomWordOfLength(int length) {
    std::uniform_int_distribution<int> distribution(0, words[length].size());
    int wordpos = distribution(random_generator);
    return words[length][wordpos];
}

void Dictionary::initRandom() {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

    random_generator.seed(seed);
}

int Dictionary::getNumberOfWordsOfLength(int length) {
    return words[length].size();
}

int Dictionary::getMaxWordLength() {
    int maxlen = words.size()-1;
    while (getNumberOfWordsOfLength(maxlen) == 0)
        maxlen--;
    return maxlen;
}
