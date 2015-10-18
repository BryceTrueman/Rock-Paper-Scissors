#include "Player.h"

Player::Player(string newName)
{
	name = newName;
	wins = 0;
	draws = 0;
	losses = 0;
}

Player::~Player(){}

int Player::getRPSThrow()
{
	int throw_choice = rand() % 3 + 1;
	return throw_choice;
}

string Player::toString()
{
	stringstream ss;
	ss << "Name: " << name << endl;
	ss << "Wins: " << wins << endl;
	ss << "Draws: " << draws << endl;
	ss << "Losses: " << losses << endl;
	return ss.str();
}

void Player::getWinRecord()
{
	double games_played = wins + draws + losses;
	if (games_played < 1)
	{
		cout << "No games played." << endl;
	}
	else
	{
		double winning_percentage = wins / games_played;
		cout << wins << " / " << games_played << " Winning percentage: " << winning_percentage << endl;
	}
}

void Player::AddWin()
{
	wins++;
}

void Player::AddDraw()
{
	draws++;
}

void Player::AddLoss()
{
	losses++;
}

string Player::getName()
{
	return name;
}

