#pragma once
#include <iostream>
#include <string>
#include <sstream>

#include "CharacterTypes.h"
#include "PlayerActions.h"
#include "List.h"





class Player {
protected:

    int characterAge;

    std::string playerName;

    std::string characterName;

    std::string characterDesc;

    /*
   List to hold the actions this player is capable of.
   */
    List<PlayerActions>* playerActions;

public:


    // Constructor
    Player();

    // Parameterized constructor
    Player(std::string pn, std::string cn, int ca);

    int getCharacterAge();
    void setCharacterAge(int age);

    std::string getPlayerName();
    void setPlayerName(std::string pn);

    std::string getCharacterName();
    void setCharacterName(std::string cn);

    /*
    Returns the character type of this player. For the base class
    Player, the character type should be CharacterType::Generic
    */
    virtual CharacterTypes getCharacterType();

    /*
    Returns a list of the actions this player is capable of. For
    the base class Player, this method returns a list containing
    two actions: PlayerAction::DoAnything and PlayerAction::doNothing.
    */
    virtual List<PlayerActions>* getPlayerActions();

    /*
     Returns true if and only if this player is capable of the specified action.
     For the base class Player this method returns true if and only if the
     specified action is either PlayerAction::DoAnything or PlayerAction::DoNothing.
     */
    bool canPerformAction(PlayerActions anAction);

    std::string getCharacterDesc();
    void setCharacterDesc(std::string characterDesc);

    virtual std::string toString();


};

