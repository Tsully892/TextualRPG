
#include "CharacterTypes.h"


/*
	The default constructor creates a CharacterTypes of type Unknown.
   */
CharacterTypes::CharacterTypes() {
	this->theType = CharacterType::Generic;
}

/*
	Creates a CharacterTypes of the specified type.
   */
CharacterTypes::CharacterTypes(CharacterType type) {
	this->theType = type;
}

/*
	Returns the specific type of this CharacterTypes
   */
CharacterTypes::CharacterType CharacterTypes::getType() {
	return this->theType;
}

/*
	 Returns a string representation of this CharacterTypes
	*/
std::string CharacterTypes::toString() {
	return this->typeNames[static_cast<int>(theType)];
}




