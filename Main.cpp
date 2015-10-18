/*
					Test Case 1
"Please Choose one of the following options.
1. Show Players
2. Add Player
3. Add to line-up
4. Show Line-up
5. Fight!
6. Quit
	chose option 1
"You do not have any players."
	chose option 6
"Have a nice day!"

					Test Case 2
chose option 2
"Please enter the name of the person you wish to add: Joe"
"You added: Joe to all players."
	chose option 3
"Please enter the name of the player you would like to add to your line-up: Schmo"
"Sorry we dont have that player"
	chose option 3
"Please enter the name of the player you would like to add to your line-up: Joe"
"You added: Joe to your lineup"

					Test Case 3
	chose option 2
"Please enter the name of the person you wish to add: Joe"
"You added: Joe to all players."
	chose option 2
"Please enter the name of the person you wish to add: Joe"
"You added: Jack to all players."
	chose option 3
"Please enter the name of the player you would like to add to your line-up: Joe"
"You added: Joe to your lineup"
	chose option 3
"Please enter the name of the player you would like to add to your line-up: Joe"
"You added: Jack to your lineup"
	chose option 4
name: Joe
wins: 0
draws: 0
losses: 0

name: Jack
wins: 0
Draws: 0
Losses: 0
	chose option 5
Joe threw scissors.
Jack threw paper.

winner: Joe
*/

#include "Player.h"
#include <ctime>
#include <vector>

using namespace std; 

void Battle(vector<Player*>& lineup)
{
	int rock = 1;
	int paper = 2;
	int scissors = 3;
	int player1_throw = lineup[0]->getRPSThrow();
	int player2_throw = lineup[1]->getRPSThrow();
	if (lineup[0]->getName() == lineup[1]->getName())
	{
		lineup[0]->AddDraw();
		lineup[1]->AddDraw();
		cout << "They just played themself! :0 ... It was a draw. " << endl;
		cout << endl;
		lineup.erase(lineup.begin() + 0);
		lineup.erase(lineup.begin() + 0);
	}
	else if (player1_throw == rock && player2_throw == paper)//player1 = rock, player2 = paper  ---- player2 wins
	{
		lineup[0]->AddLoss();
		lineup[1]->AddWin();
		cout << lineup[0]->getName() << " threw rock." << endl;
		cout << lineup[1]->getName() << " threw paper." << endl;
		cout << endl;
		cout << "Winner: " << lineup[1]->getName() << endl;
		cout << endl;
		lineup.erase(lineup.begin());
		lineup.erase(lineup.begin());
	}
	else if (player1_throw == rock && player2_throw == scissors)//player1 = rock, player2 = scissors ---- player1 wins
	{

		lineup[0]->AddWin();
		lineup[1]->AddLoss();
		cout << lineup[0]->getName() << " threw rock." << endl;
		cout << lineup[1]->getName() << " threw scissors." << endl;
		cout << endl;
		cout << "Winner: " << lineup[0]->getName() << endl; 
		cout << endl;
		lineup.erase(lineup.begin());
		lineup.erase(lineup.begin());
	}
	else if (player1_throw == paper && player2_throw == rock)//player1 = paper, player2 = rock ---- player1 wins
	{
		lineup[0]->AddWin();
		lineup[1]->AddLoss();
		cout << lineup[0]->getName() << " threw paper." << endl;
		cout << lineup[1]->getName() << " threw rock." << endl;
		cout << endl;
		cout << "Winner: " << lineup[0]->getName() << endl;
		cout << endl;
		lineup.erase(lineup.begin());
		lineup.erase(lineup.begin());
	}
	else if (player1_throw == paper && player2_throw == scissors)//player1 = paper, player2 = scissors ---- player2 wins
	{
		lineup[0]->AddLoss();
		lineup[1]->AddWin();
		cout << lineup[0]->getName() << " threw paper." << endl;
		cout << lineup[1]->getName() << " threw scissors." << endl;
		cout << endl;
		cout << "Winner: " << lineup[1]->getName() << endl;
		cout << endl;
		lineup.erase(lineup.begin());
		lineup.erase(lineup.begin());
	}
	else if (player1_throw == scissors && player2_throw == rock)//player1 = scissors, player2 = rock ---- player2 wins
	{
		lineup[0]->AddLoss();
		lineup[1]->AddWin();
		cout << lineup[0]->getName() << " threw scissors." << endl;
		cout << lineup[1]->getName() << " threw rock." << endl;
		cout << endl;
		cout << "Winner: " << lineup[1]->getName() << endl;
		cout << endl;
		lineup.erase(lineup.begin());
		lineup.erase(lineup.begin());
	}
	else if (player1_throw == scissors && player2_throw == paper)//player1 = scissors, player2 = paper ----player1 wins
	{
		lineup[0]->AddWin();
		lineup[1]->AddLoss();
		cout << lineup[0]->getName() << " threw scissors." << endl;
		cout << lineup[1]->getName() << " threw paper." << endl;
		cout << endl;
		cout << "Winner: " << lineup[0]->getName() << endl;
		cout << endl;
		lineup.erase(lineup.begin());
		lineup.erase(lineup.begin());
	}
	else if (player1_throw == rock && player2_throw == rock)
	{
		lineup[0]->AddDraw();
		lineup[1]->AddDraw();
		cout << lineup[0]->getName() << " threw rock." << endl;
		cout << lineup[1]->getName() << " threw rock." << endl;
		cout << endl;
		cout << "It was a Draw!" << endl;
		cout << endl;
		lineup.erase(lineup.begin());
		lineup.erase(lineup.begin());
	}
	else if (player1_throw == scissors && player2_throw == scissors)
	{
		lineup[0]->AddDraw();
		lineup[1]->AddDraw();
		cout << lineup[0]->getName() << " threw scissors." << endl;
		cout << lineup[1]->getName() << " threw scissors." << endl;
		cout << endl;
		cout << "It was a Draw!" << endl;
		cout << endl;
		lineup.erase(lineup.begin());
		lineup.erase(lineup.begin());
	}
	else
	{
		lineup[0]->AddDraw();
		lineup[1]->AddDraw();
		cout << lineup[0]->getName() << " threw paper." << endl;
		cout << lineup[1]->getName() << " threw paper." << endl;
		cout << endl;
		cout << "It was a Draw!" << endl;
		cout << endl;
		lineup.erase(lineup.begin());
		lineup.erase(lineup.begin());
	}
}

int FindName(vector<Player*> players, string findMe)
{
	for (int i = 0; i < players.size(); i++)
	{
		if (players[i]->getName() == findMe)
		{
			return i;
		}
	}
	return -1;
}

void ShowPlayers(vector <Player*> players)
{
	cout << endl;
	for (int i = 0; i < players.size(); i++)
	{
		cout << players[i]->toString();
		players[i]->getWinRecord();
		cout << endl;
	}
	if (players.size() == 0)
	{
		cout << "You do not have any players." << endl;
		cout << endl;
	}
}

void AddPlayer(vector <Player*>& players)
{
	string new_player_name;
	cout << "Please enter the name of the person you wish to add: ";
	cin.sync();
	getline(cin, new_player_name);
	cout << endl;
	int how_far = FindName(players, new_player_name);
	if (how_far == -1)
	{
		Player* player = new Player(new_player_name);
		players.push_back(player);
		cout << "You added: " << new_player_name << " to all players." << endl;
		cout << endl;
	}
	else
	{
		cout << "Sorry that person has already been added." << endl;
		cout << endl;
	}
}

void ShowLineUp(vector <Player*> lineup)
{
	cout << endl;
	for (int i = 0; i < lineup.size(); i++)
	{
		cout << lineup[i]->toString();
		cout << endl;
	}
	if (lineup.size() == 0)
	{
		cout << "You do not have any players in your lineup." << endl;
		cout << endl;
	}
}

void AddLineUp(vector <Player*>& players, string findMe, vector <Player*>& lineup)
{
	string new_lineup_name;
	if (players.size() > 0)
	{
		cout << "Please enter the name of the player you would like to add to your line-up: " << endl;
		cin.sync();
		getline(cin, new_lineup_name);
		cout << endl;
		int how_far = FindName(players, new_lineup_name);
		if (how_far == -1)
		{
			cout << "Sorry we don't have that player." << endl;
			cout << endl;
		}
		else
		{
			Player* lineUpMember = players[how_far];
			lineup.push_back(lineUpMember);
			cout << "You added: " << new_lineup_name << " to your lineup." << endl;
			cout << endl;
		}
	}
	else
	{
		cout << "You do not have any players to add to your line-up." << endl;
		cout << endl;
	}
}

int main()
{
	vector<Player*> players;
	vector<Player*> lineup;

	//Player* cont1 = new Player("Jack");
	//Player* c = new Player("Joe");
	//players.push_back(cont1);
	//players.push_back(c);

	srand(time(NULL));
	string findMe;
	string option;
	cout << "\t\t\tHello and welcome to my program!" << endl;
	cout << endl;
	do
	{
		cout << "Please choose one of the following options." << endl;
		cout << "1. Show Players." << endl;
		cout << "2. Add Player." << endl;
		cout << "3. Add to Line-Up." << endl;
		cout << "4. Show Line-Up." << endl;
		cout << "5. Fight!" << endl;
		cout << "6. Quit." << endl;
		cout << endl;
		cin.sync();
		cin >> option;
		cout << endl;
		if (option == "1")//show players
		{
			ShowPlayers(players);
		}
		if (option == "2")//add players
		{
			AddPlayer(players);
		}
		if (option == "3")//add to lineup
		{
			AddLineUp(players, findMe, lineup);
		}
		if (option == "4")//show lineup
		{
			ShowLineUp(lineup);
		}
		if (option == "5")//Battle
		{
			if (lineup.size() > 1)
			{
				Battle(lineup);
			}
			else
			{
				cout << "You need at least two players in order to battle!" << endl;
				cout << endl;
			}
		}
		if (option == "6")//quit
		{
			cout << "Have a nice day!" << endl;
			cout << endl;
		}
	} while (option != "6");



	system("pause");
	return 0;
}

