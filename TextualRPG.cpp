#include <iostream>
#include "GameZero.h"
#include "CharacterTypes.h"
#include "CharacterTypesTester.h"
#include "TestResults.h"

int main()
{
    std::cout << "Hello TextualRPG!\n";

    GameZero* theGame = new GameZero();
    theGame->startGame();
    

    //TestResults* r1 = CharacterTypesTester::runAllTests();
    //std::cout << r1->toString() << std::endl;

}
