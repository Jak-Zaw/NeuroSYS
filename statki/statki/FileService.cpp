#include "FileService.h"

void FileService::writeTopPlayersToFile(std::string fileName, std::vector <PlayerInfo*> players)
{
	std::fstream file;

	file.open(fileName, std::ios::out);
	int size = players.size();
	for (int i = 0; i < size; i++) {
		file << players[i]->getName() << " " << players[i]->getNumberOfGames();
		if (i != size - 1) {
			file << std::endl;
		}
	}

	file.close();
}


std::vector <PlayerInfo*> FileService::readTopPlayersFromFile(std::string fileName)
{
	std::vector<PlayerInfo*> players;
	std::fstream file;
	std::string line;

	file.open(fileName, std::ios::in);

	while (std::getline(file, line)) {
		std::istringstream ss(line);
		std::string name;
		int numberOfGames;
		ss >> name >> numberOfGames;
		PlayerInfo *pi = new PlayerInfo(name, numberOfGames);
		players.push_back(pi);
	}
	std::sort(players.begin(), players.end(), PlayerInfo::comparePlayers);
	file.close();
	return players;
}

std::vector<std::vector<std::vector<int>>> FileService::readShipsCoordinates(std::string fileName)
{
	std::vector<std::vector<std::vector<int>>> ships;
	std::fstream file;
	std::string line;

	file.open(fileName, std::ios::in);

	while (std::getline(file, line)) {
		std::vector<std::vector<int>> ship;
		std::istringstream ss(line);
		while (!ss.eof()) {
			char x;
			int y;
			ss >> x >> y;
			std::vector<int> coordinates;
			coordinates.push_back(y - 1);
			coordinates.push_back(x - 65);
			ship.push_back(coordinates);
		}
		ships.push_back(ship);
	}
	file.close();
	return ships;
}
