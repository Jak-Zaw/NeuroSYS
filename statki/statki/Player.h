/** @file  */

#pragma once
#include <vector>
#include<iostream>
#include<numeric>
#include"Validator.h"

/**
Klasa Player opisuje funkcje gracza
*/
class Player
{
protected:

	/**
	Zmienna bool winner sprawdza czy winner jest true czy false
	*/
	bool winner;

	/**
	@param boardWidth szerokosc planszy
	@param boardHigth wysokosc planszy
	*/
	int boardWidth, boardHight;

	/**
	Fucnkcja bool sprawdza czy jest mozliwosc ponownego ruchu po trafieniu statku przeciwnika
	*/
	bool hasExtraShot;

	/**
	Vector opponentsBoard przechowuje plansze przeciwnika
	*/
	std::vector<std::vector<Field>> opponentsBoard;

	/**
	Vector shipsToAllocate przechowuje rozmiary statkow do ustawienia na planszy 
	*/
	std::vector<int> shipsToAllocate = { 2,3,4 };
	//std::vector<int> shipsToAllocate = { 2 };

	/**
	@param ilosc pol ktore mozna wykorzystac w rozgrywce 
	*/
	int fieldsToHit;

	/**
	Funkcja shot odpowiedzialna jest za wykonywanie strzaly
	*/
	void shot(std::vector<int> coordinates, Player* opponent);

public:

	/**
	Vector playersBoard przechowuje plansze gracza
	*/
	std::vector<std::vector<Field>> playersBoard;

	/**
	Konstruktor bezargumentowy
	*/
	Player();

	/**
	Funkcja showPlayersBoard pokazuje plansze gracza.
	*/
	void showPlayersBoard();

	/**
	Funkcja showOpponentsBoard pozauje plansze przeciwnika z naszymi strzalami
	*/
	void showOpponentsBoard();

	/**
	Funkjca showBoards pokazuje plansze gracza i jego przeciwnika
	*/
	void showBoards();


	/**
	Funkjca setShipsPositions odpowiedzialna jest za ustawienie statkow
	*/
	virtual void setShipsPositions();

	/**
	Funkjac makeMove odpowiedzialna jest za wykonywanie ruchow
	*/
	virtual void makeMove(Player* opponent);

	/**
	Funkcja bool isWinner zwaraca wygranego 
	*/
	bool isWinner();

private:

	/**
	Funkcja fillBoards odpowiedzialna jest za wypelenie planszy pustymi polami 
	*/
	void fillBoards();
};

