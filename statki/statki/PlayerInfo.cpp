#include "PlayerInfo.h"

PlayerInfo::PlayerInfo(std::string name, int numberOfGames)
{
	this->name = name;
	this->numberOfGames=numberOfGames;
}

void PlayerInfo::setName(std::string name)
{
	this->name = name;
}

std::string PlayerInfo::getName()
{
	return name;
}

void PlayerInfo::setNumberOfGames(int numberOfGames)
{
	this->numberOfGames = numberOfGames;
}

int PlayerInfo::getNumberOfGames()
{
	return numberOfGames;
}

bool PlayerInfo::comparePlayers(PlayerInfo* p1, PlayerInfo* p2)
{
	return p1->getNumberOfGames()>p2->getNumberOfGames();
}
