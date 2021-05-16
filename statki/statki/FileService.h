/** @file  */

#pragma once
#include<fstream>
#include"Game.h"
#include<string.h>
#include<sstream>
#include<string>
#include "PlayerInfo.h"
#include<algorithm>


/**
Klasa FileService zajmuje sie obsluga plikow tekstowych
*/
class FileService
{
public:

	/**
	Funkcja writeTopPlayersToFile odpowiedzialna jest za zapisanie do pliku tesktowego nazwy gracza
	@param fileName nazwa pliku tekstowego
	*/
	static void writeTopPlayersToFile(std::string fileName, std::vector <PlayerInfo*> players);

	/**
	Funkcja readTopPlayersFromFile odpowiedzialna jest za czytanie danych gracza z pliku tekstowego
	@param fileName nazwa pliku teksowego
	*/
	static std::vector <PlayerInfo*> readTopPlayersFromFile(std::string fileName);

	/**
	Funkcja readShipsCoordinates odpowiedzialna jest za odczytanie wspolrzednych dla gotowych plansz gracza komputerowego
	@param fileName nazwa pliku tekstowego
	*/
	static std::vector < std::vector<std::vector<int>>>  readShipsCoordinates(std::string fileName);

};

