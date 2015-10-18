#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <ctime>
#include <sstream>

using namespace std;


class Player
{
private:
	string name;
	int wins;
	int losses;
	int draws;

public:
	Player(string newName);
	~Player();
	int getRPSThrow();
	void AddWin();
	void AddDraw();
	void AddLoss();
	string getName();
	string toString();
	void getWinRecord();
};
