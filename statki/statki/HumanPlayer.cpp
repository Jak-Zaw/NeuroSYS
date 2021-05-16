#include "HumanPlayer.h"

HumanPlayer::HumanPlayer()
{
	this->winner = false;
}

HumanPlayer::~HumanPlayer()
{
}

void HumanPlayer::setShipsPositions()
{
	for (int sizeOfShip : shipsToAllocate) {
		showPlayersBoard();
		std::cout << "\nPut your " << sizeOfShip << "-ship on board\n";
		std::vector<int> lastCoordinates;
		std::vector<std::vector<int>> shipCoordinates;

		for (int i = 0; i < sizeOfShip; i++) {
			if (i == 0) {
				lastCoordinates.clear();
			}
			std::vector<int> coordinates = setShipsCoordinates(10, 10, lastCoordinates);
			playersBoard[coordinates[0]][coordinates[1]] = ship;
			lastCoordinates = coordinates;
			shipCoordinates.push_back(coordinates);
		}
		updateAreasAroundShip(shipCoordinates);
		shipCoordinates.clear();
	}
	showPlayersBoard();
	std::cout << "\nAll ships has been put on board\n";
}

void HumanPlayer::makeMove(Player* opponent)
{
	do {
		showBoards();
		std::vector<int> coordinates = setShotCoordinates(10, 10);
		shot(coordinates, opponent);
		if (fieldsToHit==0) {
			winner = true;
			return;
		}

	} while (hasExtraShot);
	std::cout << "\n\nNEXT PLAYER...\n";
	system("pause");
}

std::vector<int> HumanPlayer::setShipsCoordinates(int boardWidth, int boardHight, std::vector<int> lastCoordinates)
{
	std::string x, y;
	std::vector<int> coordinates;
	bool isCorrect = false;
	showPlayersBoard();
	while (!isCorrect) {
		try {
			std::cout << "\nEnter x value = ";
			std::cin >> x;
			std::cout << "\nEnter y value = ";
			std::cin >> y;
			Validator::validateCoordinates(x, y, boardWidth, boardHight);
			Validator::validateShipCoordinates(x, y, lastCoordinates, playersBoard);
			coordinates.push_back(stoi(y) - 1);
			coordinates.push_back(x[0] - 65); 
			isCorrect = true;
		}
		catch (InvalidCoordinates & e) {
			system("cls");
			std::cout << "Invalid coordinates, please enter them again..." << std::endl;
			showPlayersBoard();
		}
		catch (InvalidShipPlacement & e) {
			system("cls");
			std::cout << "Invalid coordinates, please enter them again..." << std::endl;
			showPlayersBoard();
		}
	}
	return coordinates;
}

std::vector<int> HumanPlayer::setShotCoordinates(int boardWidth, int boardHight)
{
	std::string x, y;
	std::vector<int> coordinates;
	bool isCorrect = false;
	while (!isCorrect) {
		try {
			std::cout << "\nEnter x value = ";
			std::cin >> x;
			std::cout << "\nEnter y value = ";
			std::cin >> y;
			Validator::validateCoordinates(x, y, boardWidth, boardHight);
			Validator::validateShotCoordinates(x, y, opponentsBoard);
			coordinates.push_back(stoi(y) - 1);
			coordinates.push_back(x[0] - 65);
			isCorrect = true;
		}
		catch (InvalidCoordinates & e) {
			std::cout << "Invalid coordinates, please enter them again..." << std::endl;
		}
		catch (InvalidShotCoordinates & e) {
			std::cout << "Invalid coordinates, please enter them again..." << std::endl;
		}
	}
	return coordinates;
}


void HumanPlayer::updateAreasAroundShip(std::vector<std::vector<int>> shipCoordinates)
{
	std::vector<std::vector<int>> coordinatesToAdd = { {-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1} };

	for (std::vector<int>shipCoordinate : shipCoordinates) {
		for (std::vector<int> coordinateToAdd : coordinatesToAdd) {
			int x = shipCoordinate[0] + coordinateToAdd[0];
			int y = shipCoordinate[1] + coordinateToAdd[1];
			if (x >= 0 && x < 10 && y >= 0 && y < 10) {
				if (playersBoard[x][y] == blank) {
					playersBoard[x][y] = aroundShip;
				}
			}
		}
	}
}


