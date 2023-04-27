#include "Player.h"
#include <iostream>
#include <string>
#include <sstream>



// Constructor
Player::Player() {
    playerName = "Unnamed Player";
    characterName = "Unnamed Character";
    characterDesc = "No description available.";
    characterAge = 18;
}

// Parameterized constructor
Player::Player(std::string playerName, std::string characterName, int characterAge) {
    this->playerName = playerName;
    this->characterName = characterName;
    this->characterAge = characterAge;
    characterDesc = "No description available.";
}

int Player::getCharacterAge() {
    return this->characterAge;
}
void Player::setCharacterAge(int age) {
    this->characterAge = age;
}

std::string Player::getPlayerName() {
    return this->playerName;
}
void Player::setPlayerName(std::string pn) {
    this->playerName = pn;
}

std::string Player::getCharacterName() {
    return this->characterName;
}
void Player::setCharacterName(std::string cn) {
    this->characterName = cn;
}

/*
   Returns the character type of this player. For the base class
   Player, the character type should be CharacterType::Generic
   */
CharacterTypes Player::getCharacterType() {
    CharacterTypes result = CharacterTypes::CharacterType::Generic;
    return result;
}

/*
   Returns a list of the actions this player is capable of. For
   the base class Player, this method returns a list containing
   two actions: PlayerAction::DoAnything and PlayerAction::DoNothing.
   */
List<PlayerActions>* Player::getPlayerActions() {
    List<PlayerActions>* playerActions = new List<PlayerActions>();
    PlayerActions* doAnything = new PlayerActions(PlayerActions::PlayerAction::DoAnything);
    PlayerActions* doNothing = new PlayerActions(PlayerActions::PlayerAction::DoNothing);

    playerActions->insertAtEnd(doAnything);
    playerActions->insertAtEnd(doNothing);

    return playerActions;
}

/*
     Returns true if and only if this player is capable of the specified action.
     For the base class Player this method returns true if and only if the
     specified action is either PlayerAction::DoAnything or PlayerAction::DoNothing.
     */
bool Player::canPerformAction(PlayerActions anAction) {
    return (anAction.getAction() == PlayerActions::PlayerAction::DoAnything || anAction.getAction() == PlayerActions::PlayerAction::DoNothing);
}

std::string Player::getCharacterDesc() {
    return this->characterDesc;
}
void Player::setCharacterDesc(std::string characterDesc) {

    this->characterDesc = characterDesc;
}

std::string Player::toString() {
    std::ostringstream sout;
    sout << "Player name: " << this->playerName << std::endl;
    sout << "Character name: " << this->characterName << std::endl;
    sout << "Character type: Genearic." << std::endl;
    sout << "Character description: " << this->characterDesc << std::endl;
    sout << "Character Actions: DoAnything and DoNothing." << std::endl;
    return sout.str();

}

