#include <sstream>
#include <string>
#include "PlayerActions.h"



PlayerActions::PlayerActions() {
	this->theAction = PlayerActions::PlayerAction::DoNothing;
}

/*
 Creates a new PlayerAction with the given value.
 */
PlayerActions::PlayerActions(PlayerAction action) {
	this->theAction = action;
}


/*
 Creates a new PlayerAction whose value is determined by
 the input string. Note: the input string must exactly
 match the name of the PlayerAction value.
 */
PlayerActions::PlayerActions(std::string actionString) {
	for ( int k = 0;  k < 48;  k++) {
		if (actionNames[k] == actionString) {
			int matchingK = k;
			this->theAction = static_cast<PlayerAction>(matchingK);
			break;
		}
	}
}

/*
 Returns the specific type of action of this action type.
 */
PlayerActions::PlayerAction PlayerActions::getAction() {
	return this->theAction;
}

/*
 Returns a string representation of this character type.
 */
std::string PlayerActions::toString() {
	return this->actionNames[static_cast<int>(theAction)];
}