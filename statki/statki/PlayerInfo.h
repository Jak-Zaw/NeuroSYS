/** @file  */

#pragma once
#include<string>

/**
Klasa PlayerInfo przechowuje informacje o graczu.
*/
class PlayerInfo
{
private:

	/**
	@param name nazwa gracza
	*/
	std::string name;

	/**
	@param numberOfGames ilosc gier
	*/
	int numberOfGames;

public:

	/**
	Konstruktor PlayerInfo wskazuje na obiekty 
	@param name nazwa gracza
	@parma nuberOfGames ilosc rozegranych gier
	*/
	PlayerInfo(std::string name, int numberOfGames);

	/**
	Funkcja setName wskauje na obiekt name
	@param name nazwa uzytkownika 
	*/
	void setName(std::string name);

	/**
	getName zwrace podana przez uzytkownaika nazwe gracza
	*/
	std::string getName();

	/**
	Funkcja setNumberOfGames 
	@param numerOfGames ilosc rozegranych gier
	*/
	void setNumberOfGames(int numberOfGames);

	/**
	getNumberOfGames zwraca ilosc rozegranych gier
	*/
	int getNumberOfGames();

	/**
	@param p1 ilosc gier gracza 1
	@param p2 ilosc gier gracza 2
	*/
	static bool comparePlayers(PlayerInfo *p1, PlayerInfo *p2);
};

