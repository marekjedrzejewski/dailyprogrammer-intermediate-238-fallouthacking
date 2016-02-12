//
// Created by marek on 12.02.16.
//

#ifndef INTERMEDIATE_238_FALLOUTHACKING_HACKINTERFACE_H
#define INTERMEDIATE_238_FALLOUTHACKING_HACKINTERFACE_H


#include "HackEngine.h"

class HackInterface {
public:
    HackInterface();
    void menu();
    void play();
    void printMenuOptions();
    void difficultyLevelSettings();
    void customDifficultySettings();

private:
    HackEngine engine;

};


#endif //INTERMEDIATE_238_FALLOUTHACKING_HACKINTERFACE_H
