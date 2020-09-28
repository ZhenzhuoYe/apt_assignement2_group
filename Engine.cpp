#include "Engine.h"


Engine::Engine(){


}

void Engine::start(){
	while (option != QUIT) {
        printMainMenu();
        getInput();
		if (option == NEW_GAME) {

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

	return num;
}

void Engine::printCredit(){
	std::cout<<"Name: Zhenzhuo Ye, Fengquan Jiang, Yinan Huang"<<std::endl;
	std::cout<<"Student ID: s3710760, s3692201, s3832854"<< std::endl;
	std::cout<<"Email: s3692201@student.rmit.edu.au, s3832854@student.rmit.edu.au, s3710760@student.rmit.edu.au" << std::endl;
}

void Engine::saveGame()
{
    std::ofstream outFile;
    std::string name = "saveData" + std::to_string(saveDataIndex) + ".txt";
    char charName[14];
    strcpy(charName, name.c_str());
    //check whether file with the name has exsisted.If not,create a new one
    if (_access(charName, 0) == -1)
    {
        std::ofstream outFile(charName);
    }
    //If exsited, create another new one
    else
    {
        saveDataIndex++;
        name = "saveData" + std::to_string(saveDataIndex) + ".txt";
        char charName[14];
        strcpy(charName, name.c_str());
        std::ofstream outFile(charName);
    }

    outFile.open(charName); //open file
    if (outFile.is_open())
    {
        //Write round counter to file
        outFile<<roundIndex<<std::endl;

        //put Bag linked list to file
        saveLinkedListToFile(outFile, bag.getBag());

        //put all Factory to File
        saveFactoryArrayToFile(outFile,factories);

        //put player to file
        savePlayerToFile(outFile,p1,p2);

    }
}
void Engine::saveLinkedListToFile(std::ofstream &file, LinkedList &list)
{
    file<<"Saved Bag"<<std::endl;
    Node *tmp =list.getHeadNode();
    int len =list.getSize();
    for (int i = 0; i < len; i++)
    {
        file << char(tmp->getTileColor());
        tmp = tmp->getNext();
    }
}

void Engine::saveFactoryArrayToFile(std::ofstream &file,Factory *arr){
    file<<"Saved Factories"<<std::endl;
    for(int i=0;i<sizeof(arr);i++){
       for(int j=0;j<sizeof(arr[i].getTiles());j++){
           file<<("%s\t",arr[i].getTiles()->getTileColor());
       }
    }
}

void Engine::savePlayerToFile(std::ofstream &file, Player &p1, Player &p2)
{
    file << "Player name:";
    file << p1.getPlayerName() << std::endl;
    file << "Score:";
    file << p1.getScore() << std::endl;

    //put pattern  line to file
    file << "Saved Pattern Line" << std::endl;
    for (int i = 0; i < sizeof(p1.getGameBoard().getPatternLine()); i++){
        file<<("%s\t",p1.getGameBoard().getPatternLine()[i].getTileColor());
    }

    //put wall to file
    file << "Saved Wall" << std::endl;
    int col = MAX_WALL_COL;
    int row = MAX_WALL_ROW;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            file << ("%s\t", (p1.getGameBoard().getWall() + i * col + j)->getTileColor());
        }
    }
    //put broken tile to file
    int len = sizeof(p1.getGameBoard().getBrokenTile());
    for(int i=0;i<len;i++){
        file<<("%s\t",p1.getGameBoard().getBrokenTile().getTileColor());
    }
}