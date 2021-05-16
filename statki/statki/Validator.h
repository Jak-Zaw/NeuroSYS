/** @file  */

#pragma once
#include"InvalidShipPlacement.h"
#include"InvalidCoordinates.h"
#include"InvalidShotCoordinates.h"
#include <string>
#include <vector>
#include<stdexcept>

enum Field { blank = ' ', miss = '*', hit = 'X', ship = 'O', aroundShip = '.' };

/**
Klasa walidator odpowiadajaca zanalizowanie wspolrzednych wykorzystwanych podczas gry.
*/
class Validator
{

public:

	/**
	Funkcja validateCoordinates sprawdza czy wprowadzone wspó³rzêdne s¹ poporawne.
	@param x wspolrzedna x
	@param y wspolrzedna y
	@param boardWidth szereokosc planszy
	@param obartHight wysokosc planszy
	*/
	static void validateCoordinates(std::string x, std::string y, int boardWidth, int boardHight );

	/**
	Funkcja validateShipCoordiantes sprawdza poprawne ulozenie statkow na planszy
	@param x wspolrzedna x
	@param y wspolrzedna y
	@param 
	@param
	*/
	static void validateShipCoordinates(std::string x, std::string y, std::vector<int> lastCoordinates, std::vector<std::vector<Field>>playersBoard);

	/**
	Funkjca valideateShotCoordinates sprawdza poprawanosc podawanych wspolrzednych podczas oddawania strzalu 
	@param x wspolrzedna x
	@param y wspolrzedna y
	@param
	*/
	static void validateShotCoordinates(std::string x, std::string y, std::vector<std::vector<Field>> opponentsBoard);
};

