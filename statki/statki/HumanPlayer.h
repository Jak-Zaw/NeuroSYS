/** @file  */

#pragma once
#include "Player.h"


/**
Klasa HumanPlayer opisujaca funkcje gracza
*/
class HumanPlayer : public Player
{
public:

	/**
	Konstruktor bezargumentowy
	*/
	HumanPlayer();

	/**
	Destruktor
	*/
	~HumanPlayer();

	/**
	Funkcja setShipsPosition odpowiedzialna jest za rozmieszczenie statkow o odpowiednim rozmiarze na planszy gracza.
	*/
	void setShipsPositions();

	/**
	Funkcja makeMove odpowiedzialna jest za wykonywanie ruchow na zmiane przez graczy
	*/
	void makeMove(Player* opponent);

private:

	/**
	Funkcja setShipsCoordinates odpowiedzialna za wprowadzenie wspolrzednych statkow
	@param boardwidth szerokosc planszy
	@param boardHight wysokosc planszy
	*/
	std::vector<int> setShipsCoordinates(int boardWidth, int boardHight, std::vector<int> lastCoordinates);

	/**
	Funkcja setShotCoordinates
	@param boardwidth szerokosc planszy
	@param boardHight wysokosc planszy
	*/
	std::vector<int> setShotCoordinates(int boardWidth, int boardHight);

	/**
	Funkcja updateAreasAroundShip odpowiedzialna jest za "zarezerwoanie" miejsc wokol statku, w celu unikniecia kolizji stakow bokami oraz rogami
	*/
	void updateAreasAroundShip(std::vector<std::vector<int>> shipCoordinates);
};



