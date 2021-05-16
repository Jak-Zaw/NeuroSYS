#include "ComputerPlayer.h"

ComputerPlayer::ComputerPlayer()
{
	this->winner = false;
}

ComputerPlayer::~ComputerPlayer()
{
}

void ComputerPlayer::setShipsPositions()
{
	int setOfShips = generateRandomNumber(1, 3);
	std::vector < std::vector<std::vector<int>>> ships = FileService::readShipsCoordinates(std::to_string(setOfShips));

	for (std::vector<std::vector<int>> shipCoordinates : ships) {
		for (std::vector<int> coordinates : shipCoordinates) {
			playersBoard[coordinates[0]][coordinates[1]] = ship;
		}
	}
}

void ComputerPlayer::makeMove(Player* opponent)
{
	do {
		std::vector<int> coordinates = setShotCoordinates(10, 10);
		shot(coordinates, opponent);
		if (fieldsToHit == 0) {
			winner = true;
			return;
		}

	} while (hasExtraShot);
}

int ComputerPlayer::generateRandomNumber(int from, int to)
{
	srand(time(NULL));
	return rand() % to + from;
}

std::vector<int> ComputerPlayer::setShotCoordinates(int boardWidth, int boardHight)
{
	std::vector<int> coordinates;
	int x;
	int y;
	do {
		x = generateRandomNumber(0, 9);
		y = generateRandomNumber(0, 9);
	} while (opponentsBoard[x][y] != blank); 
	coordinates.push_back(x);
	coordinates.push_back(y);
	return coordinates;

}
