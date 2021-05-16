/** @file  */

#pragma once
#include "Player.h"
#include "FileService.h"
#include<time.h>

/**
Klasa ComputerPlayer opisujaca funkcje gracza komputerowego 
*/
class ComputerPlayer : public Player
{
public:

	/**
	Kostruktor bezargumentowy
	*/
	ComputerPlayer();

	/**
	Destruktor
	*/
	~ComputerPlayer();

	/**
	Funkcja setShipsPosition odpowiedzialna jest za wylosowanie jednej z trzech wbudowanych plansz komputera
	*/
	void setShipsPositions();

	/**
	Funkcja makeMove odpwiedzialna jest za wykonanie ruchu komputera
	*/
	void makeMove(Player* opponent);

private:

	/**
	Wylosowanie wartosci typu int, ktore beda wspolrzednymi strzalu komputera oraz wyboru planszy komputera
	@param from poczatek zakresu liczb do losowania
	@param to koniec zakresu liczb do losowania
	*/
	int generateRandomNumber(int from, int to);

	/**
	Funkcja setShotCoordinates odpowiedzialna jest za ustawienie wspolrzednych ruchu gracza komputerowego
	@param boardwidth szerokosc planszy
	@param boardHight wysokosc planszy
	*/
	std::vector<int> setShotCoordinates(int boardWidth, int boardHight);
};

