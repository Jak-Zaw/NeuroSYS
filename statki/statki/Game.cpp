#include "Game.h"

Game::Game()
{
	playerInfos = FileService::readTopPlayersFromFile(TOP_PLAYERS_FILE);
}

void Game::runGame()
{
	menuService();
}

void Game::showMenu()
{
	std::cout << " [1] Play Battleship game." << std::endl;
	std::cout << " [2] Show top players list." << std::endl;
	std::cout << " [3] Show informations about program. " << std::endl;
	std::cout << " [Q] Close program. " << std::endl;
}

void Game::showTopPlayers()
{
	system("cls");
	std::cout << "TOP PLAYERS:\n";
	int position = 0;
	for (PlayerInfo* pi : playerInfos) {
		std::cout << "[" << ++position << "]\t" << pi->getName() << "\t\t" << pi->getNumberOfGames() << std::endl;
	}
	std::cout << std::endl << std::endl << "Choose Q to back to Main Menu...";
	char q = 'x';
	while (q != 'Q') {
		q = getCharFromUser();
	}
}

void Game::showProgramInfo()
{
	system("cls");
	std::cout << "This is a Battleship game, written as midterm project from Computer Programming 4." << std::endl;
	std::cout << "You can choose if you want to play with computer or the other opponent." << std::endl;
	std::cout << "We will ask you to enter your name and the coordinates of the ships." << std::endl;
	std::cout << "Then you can start the game." << std::endl;
	std::cout << "* means, that you missed yout shot\nX means, that you hit opponents ship\nO is your ship\n. is a space around ship" << std::endl;
	std::cout << std::endl << std::endl << "Choose Q to back to Main Menu...";

	char q = 'x';
	while (q != 'Q') {
		q = getCharFromUser();
	}
}

void Game::menuService()
{
	char option = 'x';
	while (option != 'Q') {
		system("cls");
		showMenu();
		option = getCharFromUser();

		switch (option) {
		case '1':
			gameService();
			break;
		case '2':
			showTopPlayers();
			break;
		case '3':
			showProgramInfo();
			break;
		}
	}
	FileService::writeTopPlayersToFile(TOP_PLAYERS_FILE, playerInfos);
}

void Game::gameService()
{
	char option = 'X';
	while (option != 'Q') {
		system("cls");
		std::cout << " [1] Play with other player." << std::endl;
		std::cout << " [2] Play with computer." << std::endl;
		std::cout << std::endl << std::endl << "Choose Q to back to Main Menu...";

		option = getCharFromUser();
		if (option == 'Q') {
			continue;
		}
		GameType type = convertToGameType(option);
		switch (type) {
		case Human_Human: {
			runHumanHumanGame();
			break;
		}
		case Human_Computer: {
			runHumanComputerGame();
			break;
		}
		default: {
			std::cout << "\nPlease choose correct option! ";
		}
		}
	}
}

Game::GameType Game::convertToGameType(char option)
{
	int type = option - 48;
	switch (type)
	{
	case 1:
		return Human_Human;
	case 2:
		return Human_Computer;
	default: {
		return Undefined;
	}
	}
}

void Game::runHumanHumanGame()
{
	std::vector<Player*> players;
	std::string player1Name = getNameFromUser();
	players.push_back(new HumanPlayer());
	std::string player2Name = getNameFromUser();
	players.push_back(new HumanPlayer());
	for (Player* p : players) {
		p->setShipsPositions();
	}
	int turn = 0;
	while (1) {
		for (Player* p : players) {
			system("cls");
			std::cout << "BATTLESHIP " << player1Name << " vs " << player2Name << std::endl;
			int playerNumber = (turn++ % 2);
			std::cout << "\nYour " << (playerNumber == 1 ? player1Name : player2Name) << " turn\n";
			p->makeMove(players[!playerNumber]);
			if (p->isWinner()) {
				updatePlayersInfo(player1Name, player2Name);
				std::system("cls");
				std::cout << "The winner is " << (playerNumber == 1 ? player1Name : player2Name) << std::endl;
				delete players[0];
				delete players[1];
				std::system("pause");
				return;
			}
		}
	}
}

void Game::runHumanComputerGame()
{
	std::vector<Player*> players;
	std::string player1Name = getNameFromUser();
	players.push_back(new HumanPlayer());
	std::string player2Name = "COMPUTER";
	players.push_back(new ComputerPlayer());
	for (Player* p : players) {
		p->setShipsPositions();
	}
	int turn = 0;
	while (1) {
		for (Player* p : players) {
			system("cls");
			std::cout << "BATTLESHIP " << player1Name << " vs " << player2Name << std::endl;
			int playerNumber = (turn++ % 2);
			std::cout << "\nYour " << (playerNumber == 1 ?  player2Name: player1Name) << " turn\n";
			p->makeMove(players[!playerNumber]);
			if (p->isWinner()) {
				updatePlayersInfo(player1Name, player2Name);
				std::system("cls");
				std::cout << "The winner is " << (playerNumber == 1 ? player1Name : player2Name) << std::endl;
				delete players[0];
				delete players[1];
				std::system("pause");
				return;
			}
		}
	}
}

char Game::getCharFromUser()
{
	std::string s;
	do {
		std::cin >> s;
	} while (s.size() != 1 && s.size() > 0);
	return s[0];
}

std::string Game::getNameFromUser()
{
	std::string s;
	std::cout << "\nPlease enter name: ";
	std::cin >> s;
	return s;
}

void Game::updatePlayersInfo(std::string player1Name, std::string player2Name)
{
	std::vector<std::string> playerNames = { player1Name,player2Name };

	for (std::string playerName : playerNames) {
		bool found = false;
		for (PlayerInfo* player : playerInfos) {
			if (player->getName() == playerName) {
				player->setNumberOfGames(player->getNumberOfGames() + 1);
				found = true;
				break;
			}
		}
		if (!found) {
			PlayerInfo* p = new PlayerInfo(playerName, 1);
			playerInfos.push_back(p);
		}
	}
	std::sort(playerInfos.begin(), playerInfos.end(), PlayerInfo::comparePlayers);

}

Game::~Game()
{
	for (int i = 0; i < playerInfos.size(); i++) {
		delete playerInfos[i];
	}
	playerInfos.clear();
}
