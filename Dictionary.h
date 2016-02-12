//
// Created by marek on 12.02.16.
//

#ifndef INTERMEDIATE_238_FALLOUTHACKING_DICTIONARY_H
#define INTERMEDIATE_238_FALLOUTHACKING_DICTIONARY_H

#include <string>
#include <vector>
#include <random>

class Dictionary {

public:
    Dictionary(std::string filename=defaultdict, int maxlen = 15);
    std::string getRandomWordOfLength(int length);
    int getNumberOfWordsOfLength(int length);
    int getMaxWordLength();

private:
    static const std::string defaultdict;
    // separate vectors for lengths
    std::vector<std::vector<std::string>> words;

    std::default_random_engine random_generator;
    void initRandom();
};


#endif //INTERMEDIATE_238_FALLOUTHACKING_DICTIONARY_H
