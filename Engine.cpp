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

		for(int i = 0; i < MAX_PLAYER; i++){

			std::cout<<"TURN FOR PLAYER: "<<players[i]->getPlayerName()<<std::endl;

			printAllFactory();//print the share factory to the console

			std::cout<<"Mosaic for "<< players[i]->getPlayerName()<<std::endl;

			
			std::cout<<*(players[i]->getGameBoard())<<std::endl;//print the gameboard

			//plyaer pick the factory and patternline
			do{
				getPlayerInput();
			}while(!(checkInput(players[i])));

			//take tiles from the facotry.
			vector<Tile> chosenTiles = allFactory[chosenFactory].takeTile(chosenColor);

			if(chosenFactory != 5){
				centerFactory.addingTile(allFactory[chosenFactory].takeRest());
			}else{
				//centerFactory.take
			}

			//add tilles to the pattern line
			players[i]->getGameBoard()->addtoPatternLine(chosenTiles, chosenRow);

			//FIXME: for testing remove me after
			std::cout<<*(players[i]->getGameBoard())<<std::endl;//print the gameboard


			//if the factory is empty, adding tiles to the factory and start scoring
			//TODO:

		}

		if(checkFactoryElement()){
			for(int i = 0; i < MAX_PLAYER; i++){
				for(int row = 0; row<5;row++){
					if(players[i]->getGameBoard()->ifPatternLineComplete(row)){
						//get the patterline of row in a vector
						vector<Tile> PatternLineVector = players[i]->getGameBoard()->getPatternLineInVector(row);
						//give the vector to the wall and add into wall
						players[i]->increaseScore(players[i]->getGameBoard()->addtoWall(PatternLineVector, row));
						//clear the patterline
						players[i]->getGameBoard()->clearRowOfPatterline(row);
					}
				}
			}
			//the factory is empty time to refill
		}
	}	
}

void Engine::setupNewGame(){
	string playername;

	std::cout<<"Starting a New Game"<<std::endl;
	std::cout<<"Enter a name for player 1"<<std::endl;
	std::cout<<">";
	std::cin >> playername;
	player1 = new Player(playername, new GameBoard());
	std::cout<<"Enter a name for player 2"<<std::endl;
	std::cout<<">";
	std::cin >> playername;
	player2 = new Player(playername, new GameBoard());
	std::cin.ignore(1024,'\n');

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

		chosenFactory = std::stoi(inputCollection.at(1)) - 1;
		if(chosenFactory == -1){
			chosenFactory = 5;
		}

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




bool Engine::checkInput(Player* player){
	bool factoryColorCheck = false;
	bool patternlineHeadColorCheck = true;


	Color headColor = player->getGameBoard()->getPatternLineRowColor(chosenRow);
	//head color of that row, if the color is "." or same as chosen color return false
	//if the color is differnt with chosen color and the color is not "."return true

	Factory currentFactory = allFactory[chosenFactory];
	//check if the current factory have the chosen tile inside


	int length = currentFactory.getLength();// the size of the vector
	
	for(int i = 0; i < length; i++){
		if(currentFactory.getTiles()[i].getTileColor() == chosenColor){
			factoryColorCheck = true;
			//return false to break the do while loop
		}
	}
	
	if(!(factoryColorCheck)){
		std::cout<<"the choosen factory doesn't contain choosen color"<<std::endl;
	}

	
	if(headColor == chosenColor || headColor == NO_TILE){
		patternlineHeadColorCheck = true;
	}else{
		std::cout<<"the choosen tiles doesn't match the pattern line color"<<std::endl;
		patternlineHeadColorCheck = false;
	}


	return patternlineHeadColorCheck && factoryColorCheck;
	//return true when both check pass, otherwise any pass false return false
}