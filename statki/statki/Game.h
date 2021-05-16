/** @file */
#pragma once
#include"PlayerInfo.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"
#include<vector>
#include<iostream>
#define TOP_PLAYERS_FILE "BattleShip.txt"

/**
Klasa Game obsluguje funkcje oraz uruchamianie gry
*/
class Game
{
private:

	/**
	*/
	std::vector<PlayerInfo*> playerInfos;

	/**
	*/
	enum GameType { Human_Human = 1, Human_Computer = 2, Undefined = 3};
public:

	/**
	Konstruktor bezargumentowy
	*/
	Game();

	/**
	Funkcja runGame odpowiedzilana jest za uruchomienie menu glownego, ktore pozwala na dalsze korzystanie z funkcjonalnosci programu.
	*/
	void runGame();

	/**
	Destruktor
	*/
	~Game();

private:

	/**
	Funkcja showMennu odpowiedzialna jest wyswietalnie menu glownego programu
	*/
	void showMenu();

	/**
	Funkcja showTopPlayers odpowiedzialna jest za wyswietlanie graczy, ktorzy rozegrali gre w posortowanej kolejnosci ilosci rozgeranych gier.
	*/
	void showTopPlayers();

	/**
	Funkcja showProgramInfo odpowiedzialna jest za wyswietlanie informacji o programie
	*/
	void showProgramInfo();

	/**
	Funkcja  menuService odpowiedzialna jest mechaniz wybierania funkcjonalnosci menu programu
	*/
	void menuService();
	

	/**
	Funkcja gameService odpowiedzialna jest za mozliwosc wyboru trybu gry
	*/
	void gameService();

	/**
	convertToGameType wybiera typ gry
	*/
	GameType convertToGameType(char option);
	

	/**
	Funkcja runHumanHumanGame pozwala na przeporowadzenie rozgrywki miedzy dwoma graczami
	*/
	void runHumanHumanGame();

	/**
	Funkcja runHumanComputerGame pozwala przeprowadzenie rozgrywki miedzy graczem, a komputerem
	*/
	void runHumanComputerGame();


	/**
	Pobranie od uzytkownika pojedynczego znaku 
	*/
	char getCharFromUser();

	/**
	Pobranie od uzytkownika jego nazwy jako lancucha znakow string
	*/
	std::string getNameFromUser();

	/**
	Funkcja updatePlayersInfo odpowiedzialna jest za aktualizacje informacji o graczu, dodanie nowego gracza do bazy graczy oraz posortowanie graczy w rankingu
	@param player1Name nazwa gracza
	@param player2Name nazwa gracza 
	*/
	void updatePlayersInfo(std::string player1Name, std::string player2Name);

};

