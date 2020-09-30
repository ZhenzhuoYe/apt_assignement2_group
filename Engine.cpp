#include "Engine.h"

Engine::Engine(){
	bag = new Bag();

	for(int i = 0; i < 5; i++){
		allFactory[i].addingTile(bag->popFourTile());
	}
}

void Engine::start(){
	while (option != QUIT) {
        printMainMenu();
        getInput();
		if (option == NEW_GAME) {
			newGame();
		}
		else if (option == LOAD_GAME) {
            
		}
		else if (option == CREDITS) {
			printCredit();
		}
	}
}

void Engine::printMainMenu(){
    std::cout << "Menu" << std::endl;
	std::cout << "----" << std::endl;
	std::cout << "1. New Game" << std::endl;
	std::cout << "2. Load Game" << std::endl;
	std::cout << "3. Credits (Show student information)" << std::endl;
	std::cout << "4. Quit" << std::endl;
}
       
int Engine::getInput(){

	char ch;
	int num = -1;
	std::cout << ">";
	std::cin >> num;
	ch = getchar(); // new line in the buffer
	option = num;
	return num;
}

void Engine::printCredit(){
	std::cout<<"Name: Zhenzhuo Ye, Fengquan Jiang, Yinan Huang"<<std::endl;
	std::cout<<"Student ID: s3710760, s3692201, s3832854"<< std::endl;
	std::cout<<"Email: s3692201@student.rmit.edu.au, s3832854@student.rmit.edu.au, s3710760@student.rmit.edu.au" << std::endl;
}
/*
	1. setup play
	2. start turn
	
**/
void Engine::newGame(){
	setupNewGame();// initlalise both of the player name

	int turn = 1;// set the turn of the game
	while(turn < MAX_TURN){
		if(checkFactoryElement()){
			//the factory is empty time to refill
		}

		std::cout<<"TURN FOR PLAYER: "<<player1->getPlayerName()<<std::endl;

		printAllFactory();//print the share factory to the console

		std::cout<<"Mosaic for "<< player1->getPlayerName()<<std::endl;

		//std::cout<<player1->getGameBoard()<<std::endl;//print the gameboard

		getPlayerInput();
		//plyaer pick the factory and patternline


		vector<Tile> chosenTiles;
		//TODO:check if the facory have that color inside
		if(checkIfFactoryContainColor(chosenColor,chosenFactory)){
			chosenTiles = allFactory[chosenFactory].takeTile(chosenColor);
			// give factory what color player have picked

		}
		
		player1->getGameBoard().addtoPatternLine(chosenTiles, chosenRow);



		
		


	}	
}

void Engine::setupNewGame(){
	string playername;

	std::cout<<"Starting a New Game"<<std::endl;
	std::cout<<"Enter a name for player 1"<<std::endl;
	std::cin >> playername;
	player1 = new Player(playername);
	std::cout<<"Enter a name for player 2"<<std::endl;
	std::cin >> playername;
	player2 = new Player(playername);

	std::cout<<"Let's Play!"<<std::endl;
	std::cout<<"=== Start Round ==="<<std::endl;
}

void Engine::printAllFactory(){
	std::cout<<"Factories:"<< std::endl;
	for(int i = 0; i < MAX_ALL_FACTORY; i++){
		std::cout << allFactory[i] << std::endl;
	}
}

void Engine::getPlayerInput(){

	string playerInput;
	std::cout << ">";

	std::cin.ignore();
    std::getline(std::cin, playerInput);

	//std::cout<<playerInput<<std::endl;

	inputRecord.push_back(playerInput);


	std::vector<string> inputCollection;
	string word;

	playerInput = playerInput + " ";

	for (auto x : playerInput) { 
       if (x == ' ') { 
		   inputCollection.push_back(word);
		   word = "";
       } 
       else{ 
           word = word + x; 
    	} 
   }

	if(inputCollection.at(0) == "turn"){
		/*
			take a string convert it to color
		*/
		chosenColor = stringToColor(inputCollection.at(2));
		// convert the string to color

		chosenFactory = std::stoi(inputCollection.at(1));

		chosenRow = std::stoi(inputCollection.at(3));
	}
}

bool Engine::checkFactoryElement(){
	for(int i = 0; i < MAX_ALL_FACTORY; i++){
		if(allFactory[i].ifEmpty()){
			return true;
		}
	}
	return false;
}

Color Engine::stringToColor(string s){
	if(s == "B"){
		return DARK_BLUE;
	}else if(s == "Y"){
		return YELLOW;
	}else if(s == "R"){
		return RED;
	}else if(s == "L"){
		return LIGHT_BLUE;
	}else if(s == "U"){
		return BLACK;
	}else{
		return NO_TILE;
	}
}

bool Engine::checkIfFactoryContainColor(Color color, int factoryNum){
	Tile* currentFactory = allFactory[factoryNum].getTiles();
	int length = allFactory[factoryNum].getLength();

	for(int i = 0; i < length; i++){
		if(currentFactory[i].getTileColor() == color){
			return true;
		}
	}

	return false;
}


