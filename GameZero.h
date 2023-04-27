#pragma once
#include "Graph.h"
#include "Player.h"
#include "List.h"
#include <string>
class GameZero
{

public:

	//Defualt Constructor
	GameZero();

	/*
	   Creates a new game with the specified player.
	   */
	GameZero(Player* player);

	//Meathod to start the game
	void startGame();

	// Meathod to end the game 
	void endGame();

	// toString 
	std::string toString();

protected:

	//The player in our game
	Player* thePlayer;

	//The graph for our game 
	Graph<List<std::string>, List<std::string>>* theGraph;

	//Build our graph for the game
	void buildGameGraph();

	//Function to prompt the user for character info  to create the player
	// object representing the game player
	void getUserInfo();

	/*
		Prints the string data stored in the vertex of the game graph. The method
		should print one string at a time, then accept user input, then print the
		next string, and so on, until no more strings are left to print.
		*/
	void printVertexData();

	//Function to allow the user to 
	// Provide a respnse frequently during the game
	// Allow the user to exit the game if the response is "exit" 
	std::string getUserResponse();

	//Meathod for the fight scene
	void simulateFight();

	

};

