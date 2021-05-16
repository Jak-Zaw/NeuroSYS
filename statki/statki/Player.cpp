#include "Player.h"

void Player::showPlayersBoard()
{
	for (int i = -1; i < boardWidth; i++) {
		for (int j = -2; j < boardHight; j++) {
			if (i == -1) {
				if (j < -1) {
					std::cout << "\t";
				}
				else if (j != boardHight - 1) {
					std::cout << (char)(66 + j) << "\t";
				}

			}
			else if (j > -1) {
				std::cout << (char)playersBoard[i][j] << "\t";
			}
			else if (j == -2) {
				std::cout << i + 1 << "\t";
			}

		}
		std::cout << std::endl;
	}
}

Player::Player()
{
	boardHight = 10;
	boardWidth = 10;
	this->winner = false;
	this->hasExtraShot = false;
	this->fieldsToHit = std::accumulate(shipsToAllocate.begin(), shipsToAllocate.end(), 0);
	fillBoards();
}

void Player::setShipsPositions()
{
}

void Player::makeMove(Player* opponent)
{
}

bool Player::isWinner()
{
	return this->winner;

}

void Player::fillBoards()
{
	std::vector<Field> blanks(boardWidth, blank);
	for (int i = 0; i < boardHight; i++) {
		playersBoard.push_back(blanks);
		opponentsBoard.push_back(blanks);
	}
}

void Player::showOpponentsBoard()
{
	for (int i = -1; i < boardWidth; i++) {
		for (int j = -2; j < boardHight; j++) {
			if (i == -1) {
				if (j < -1) {
					std::cout << "\t";
				}
				else if (j != boardHight - 1) {
					std::cout << (char)(66 + j) << "\t";
				}

			}
			else if (j > -1) {
				std::cout << (char)opponentsBoard[i][j] << "\t";
			}
			else if (j == -2) {
				std::cout << i + 1 << "\t";
			}

		}
		std::cout << std::endl;
	}
}

void Player::showBoards()
{
	std::cout << " OPPONENT'S BOARDS\n";
	showOpponentsBoard();
	std::cout << "\n\nPLAYER'S BOARD\n";
	showPlayersBoard();
}

void Player::shot(std::vector<int> coordinates, Player* opponent)
{
	if (opponent->playersBoard[coordinates[0]][coordinates[1]] == ship) {
		opponentsBoard[coordinates[0]][coordinates[1]] = hit;
		hasExtraShot = true;
		fieldsToHit--;
	}
	else {
		opponentsBoard[coordinates[0]][coordinates[1]] = miss;
		hasExtraShot = false;
	}
}
