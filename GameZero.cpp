#include <random>
#include "GameZero.h"
#include "Vertex.h"
#include "Player.h"


//Should create and initialize the player and the game graph
GameZero::GameZero() {
	this->thePlayer = new Player();
	this->theGraph = nullptr;
	// get Player info 
	this->getUserInfo();
	//build the new game graph 
	this->buildGameGraph();

	std::cout << thePlayer->toString() << std::endl;
}

/*
	   Creates a new game with the specified player.
	   */
GameZero::GameZero(Player* player) {
	this->thePlayer = player;
	this->theGraph = nullptr;
	this->buildGameGraph();

	std::cout << thePlayer->toString() << std::endl;
}


//Meathod to start the game
void GameZero::startGame() {
	this->printVertexData();
	this->simulateFight();
}

// Meathod to end the game 
void GameZero::endGame() {
	std::cout << "Bye bye, see you next time!\n";
	std::exit(0);
}

// toString 
std::string GameZero::toString() {
	std::ostringstream sout;
	sout << "GameZero at: " << this << std::endl;
	sout << this->thePlayer->toString() << std::endl;
	
	return sout.str();
}

//All protected feilds down here


//Build our graph for the game
void GameZero::buildGameGraph() {
	this->theGraph = new Graph <List <std::string>, List <std::string>>();
	//add single vertex
	Vertex<List<std::string>>* dragonsLair = new Vertex<List<std::string>>();
	this->theGraph->addVertex(dragonsLair);
	//Add some string data to decribe the story that occurs in the dragons lair 
	List<std::string>* storyList = new List<std::string>();
	//add some strings to the list
	storyList->insertAtEnd(new std::string("You awaken in a dark underground pit..."));
	storyList->insertAtEnd(new std::string("You can't see far ahead of you but you see a light at the end of the room..."));
	storyList->insertAtEnd(new std::string("You stumble forward, weary of what's ahead..."));
	storyList->insertAtEnd(new std::string("As you draw closer to the flame you realize it's a slumbering dragon..."));
	storyList->insertAtEnd(new std::string("Slowly you back away as a glimmer of gold catches your eye..."));
	storyList->insertAtEnd(new std::string("Greedily you double back to claim some of the booty..."));
	storyList->insertAtEnd(new std::string("As you grab the gold the dragon begains to awaken..."));
	storyList->insertAtEnd(new std::string("The dragon awakens to find you stealing his wealth..."));
	storyList->insertAtEnd(new std::string("The dragon spits out three fire ghosts as defence... goodluck!"));
	//After all stories store list in vertex
	this->theGraph->storeInVertex(storyList , 0);
}

//Function to prompt the user for character info  to create the player
// object representing the game player
void GameZero::getUserInfo() {
	// get players name 
	std::cout << "Enter your name: " << std::endl;
	std::string playerName = getUserResponse();
	this->thePlayer->setPlayerName(playerName);
	
	//get char name
	std::cout << "Enter your character's name: " << std::endl;
	std::string characterName = getUserResponse();
	this->thePlayer->setCharacterName(characterName);

	//get char age
	std::cout << "Enter your desired character age: " << std::endl;
	std::string characterAgeString = getUserResponse();
	try {
		int characterAge = stoi(characterAgeString); //could be fualty
		this->thePlayer->setCharacterAge(characterAge);
	}
	catch (const std::exception e) {
		std::cout << e.what() << std::endl;
		//Set character's age to defualt value (30)
		this->thePlayer->setCharacterAge(30);
		std::cout << "Invalid age string, set character's age to 30.\n";
	}
	

	//get char decription
	std::cout << "Enter your character's description (breif): " << std::endl;
	std::string characterDescription = getUserResponse();
	this->thePlayer->setCharacterDesc(characterDescription);

}

/*
		Prints the string data stored in the vertex of the game graph. The method
		should print one string at a time, then accept user input, then print the
		next string, and so on, until no more strings are left to print.
		*/
void GameZero::printVertexData() {
	std::cout << "The story thus far: " << std::endl;
	//get pointer to the list of strings (graph)
	List<std::string>* storyList = this->theGraph->getVertexData(0);
	for (int k = 0; k < storyList->getSize(); k++) {
		//get k from the list 
		std::string* itemk = storyList->peek(k);
		std::cout << *itemk << std::endl;
		this->getUserResponse();
	}

}

//Function to allow the user to 
	// Provide a respnse frequently during the game
	// Allow the user to exit the game if the response is "exit" 
std::string GameZero::getUserResponse() {
	std::string result = "";
	// allow user to respond, will cath the users response
	std::getline(std::cin, result);
	if (result == "exit") {
		this->endGame();
	} else {
		return result;
	}
}

//Meathod for the fight scene
void GameZero::simulateFight() {
	std::cout << "simulateFight() here.\n" << std::endl;

	//Random number generator
	std::random_device r;
	std::default_random_engine engn(r());
	std::uniform_real_distribution<double> prng(0.0, 1.0);

	//Set up player's vitality and hit point values and hit prob 
	int playerVitality = 100; 
	int playerDamagePerHit = 10;
	double playerHitProbability = 0.60;

	//Set up ghost's vitality and hit point values and hit prob
	int ghostVitality[3] = { 30, 30, 30 };
	int ghostDamagePerHit = 5;
	double ghostHitProbability = 0.35;

	//Round counter
	//The fight will proceed in round where the player attacks ghosts individually
	int roundNumber = 1;

	//Main Simulation loop 
	while (playerVitality > 0) {
		std::cout << std::endl;
		std::cout << "Round: " << roundNumber << " fight!" << std::endl;

		//For each ghost that remains alive, check two things 
		//Did player's blow land on ghost
		//Did ghost land blow on player
		for (int k = 0; k < 3; k++) {
			if (ghostVitality[k] > 0) {
				//check if player landed hit on ghost
				//If so update vitality point for the ghost
				//cout message to player
				double randVal = prng(engn);
				if (randVal <= playerHitProbability) { //players blow landed
					//decrement vitality of ghost k 
					ghostVitality[k] -= ghostDamagePerHit;
					std::cout << "Take that!" << std::endl;
					std::cout << "The player has landed a hit on ghost " << k << ", its vitality is now " << ghostVitality[k] << std::endl;
					this->getUserResponse();
				} 

				//Check if ghost k is still alive and if they hit the player 
				if (ghostVitality[k] > 0) {
					//Check if ghost k landed a hit on the player 
					// will update and print out player vitality
					double randVal = prng(engn);
					if (randVal <= ghostHitProbability) { //players blow landed
					//decrement vitality of the player  
						playerVitality -= playerDamagePerHit;
						std::cout << "Ouch!" << std::endl;
						std::cout << "Ghost " << k << " has hit the player! Player viltality is now " << playerVitality << std::endl;
						this->getUserResponse();

						if (playerVitality <= 0) {
							std::cout << "The player has been defeated! Vitality at: " << playerVitality << std::endl << std::endl;
							std::cout << "Maybe next time don't be so gredy!!" << std::endl;
							this->getUserResponse();
							this->endGame();
						}
					}
				}

			}
		}
		//Check if there are ghosts left 
		if (ghostVitality[0] <= 0 && ghostVitality[1] <= 0 && ghostVitality[2] <= 0) {
			std::cout << "All three ghosts are dead, the player has won the treasure!" << std::endl << std::endl;
			std::cout << "You share your wealth with the village to help everyone prosper! What a generous soul!" << std::endl;
			this->endGame();
		}


		roundNumber++;
	}

}
