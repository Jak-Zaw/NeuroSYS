#include "Validator.h"

void Validator::validateCoordinates(std::string x, std::string y, int boardWidth, int boardHight)
{
	int coordinateX, coordinateY;
	try {
		if (x.size() > 1) {
			throw InvalidCoordinates();
		}
		coordinateX = x[0] - 65;
		coordinateY = stoi(y) - 1;

		if (coordinateX < 0 || coordinateX >= boardWidth) {
			throw InvalidCoordinates();
		}
		if (coordinateY < 0 || coordinateY >= boardHight) {
			throw InvalidCoordinates();
		}
	}
	catch (std::invalid_argument & e) {
		throw InvalidCoordinates();
	}
	catch (std::out_of_range & e) {
		throw InvalidCoordinates();
	}


}

void Validator::validateShipCoordinates(std::string x, std::string y, std::vector<int> lastCoordinates, std::vector<std::vector<Field>> playersBoard)
{
	int coordinateX, coordinateY;
	coordinateX = x[0] - 65;
	coordinateY = stoi(y) - 1;
	if (playersBoard[coordinateY][coordinateX] != blank) {
		throw InvalidShipPlacement();
	}
	if (lastCoordinates.empty()) {
		return;
	}
	if ((lastCoordinates[1] + 1 == coordinateX && lastCoordinates[0] == coordinateY)
		|| (lastCoordinates[1] - 1 == coordinateX && lastCoordinates[0] == coordinateY)
		|| (lastCoordinates[1] == coordinateX && lastCoordinates[0] + 1 == coordinateY)
		|| (lastCoordinates[1] == coordinateX && lastCoordinates[0] - 1 == coordinateY)) {
		return;
	}
	throw InvalidShipPlacement();
}

void Validator::validateShotCoordinates(std::string x, std::string y, std::vector<std::vector<Field>> opponentsBoard)
{
	int coordinateX, coordinateY;
	coordinateX = x[0] - 65;
	coordinateY = stoi(y) - 1;
	if (opponentsBoard[coordinateY][coordinateX] != blank) {
		throw InvalidShotCoordinates();
	}
}

