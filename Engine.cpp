#include "Engine.h"

Engine::Engine(){
	bag = new Bag();

	//fill in factory with tile
	for(int i = 0; i < 5; i++){
		allFactory[i].addingTile(bag->popFourTile());
	}

	//add the first player token into the factory
	allFactory[5].addFirstPlayerToken();
}

Engine::~Engine(){
	delete bag;
	delete player1;
	delete player2;
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
	//TODO: only number input
	char ch;
	int num = -1;
	std::cout << ">";
	std::cin >> num;
	ch = getchar(); // new line in the buffer
	option = num;
	return num;
}

void Engine::printCredit(){

	std::cout<<std::endl;
	std::cout<<"------------------------------------------"<<std::endl;
	std::cout<<"Name: Zhenzhuo Ye, Fengquan Jiang, Yinan Huang"<<std::endl;
	std::cout<<"Student ID: s3710760, s3692201, s3832854"<< std::endl;
	std::cout<<"Email: s3692201@student.rmit.edu.au, s3832854@student.rmit.edu.au, s3710760@student.rmit.edu.au" << std::endl;
	std::cout<<"------------------------------------------"<<std::endl;

	std::cout<<std::endl;

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

		for(int i = 0; i < MAX_PLAYER; i++){

			std::cout<<"TURN FOR PLAYER: "<<players[i]->getPlayerName()<<std::endl;

			printAllFactory();//print the share factory to the console

			std::cout<<"Mosaic for "<< players[i]->getPlayerName()<<std::endl;

			
			std::cout<<*(players[i]->getGameBoard())<<std::endl;//print the gameboard

			getPlayerInput();
			//plyaer pick the factory and patternline


			//important TODO: user input loop until the reasonble input
			//after haveing the resonble input, adding to the record

			// while(checkIfFactoryContainColor()&&checkInput(*player1)){
			// 	getPlayerInput();
			// }

			//take tiles from the facotry.
			vector<Tile> chosenTiles = allFactory[chosenFactory].takeTile(chosenColor);

			//add tilles to the pattern line
			players[i]->getGameBoard()->addtoPatternLine(chosenTiles, chosenRow);

			//if the factory is empty, adding tiles to the factory and start scoring
			//TODO:

		}
	}	
}

void Engine::setupNewGame(){
	string playername;

	std::cout<<"Starting a New Game"<<std::endl;
	std::cout<<"Enter a name for player 1"<<std::endl;
	std::cin >> playername;
	player1 = new Player(playername, new GameBoard());
	std::cout<<"Enter a name for player 2"<<std::endl;
	std::cin >> playername;
	player2 = new Player(playername, new GameBoard());

	std::cout<<"Let's Play!"<<std::endl;
	std::cout<<"=== Start Round ==="<<std::endl;

	players[0] = player1;
	players[1] = player2;
}

void Engine::printAllFactory(){
	std::cout<<"Factories:"<< std::endl;
	std::cout<<allFactory[5]<<std::endl;

	for(int i = 0; i < 5; i++){
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
	}else if(inputCollection[0] == "save"){
		//save();
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
	//TODO: adding first player token
	
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

bool Engine::checkIfFactoryContainColor(){
	Factory currentFactory = allFactory[chosenFactory];
	int length = currentFactory.getLength();

	for(int i = 0; i < length; i++){
		if(currentFactory.getTiles()[i].getTileColor() == chosenColor){
			return true;
		}
	}
	
	
	std::cout<<"the choosen factory doesn't contain choosen color"<<std::endl;

	return false;
}


bool Engine::checkInput(Player player){
	Color headColor = player.getGameBoard()->getPatternLineRowColor(chosenRow);
	
	if(headColor == chosenColor){
		return true;
	}else{
		std::cout<<"the choosen tiles doesn't match the pattern line color"<<std::endl;
		return false;
	}
}