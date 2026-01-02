#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

enum enGameChoice { Stone = 1, Paper = 2, Scissors = 3 };
enum enWinner { Player1 = 1, Computer = 2, Draw = 3 };

struct stRoundResults
{
	short RoundNumber;
	enGameChoice Player1Choice;
	enGameChoice ComputerChoice;
	enWinner Winner;
	string WinnerName;
};

struct stGameResults
{
	short GameRounds = 0;
	short Player1WonTimes = 0;
	short ComputerWonTimes = 0;
	short DrawTimes = 0;
	enWinner FinalWinner;
};

int RandomNumber(int From, int To)
{
	int randNum = rand() % (To - From + 1) + From;
	return randNum;
}

enGameChoice GetComputerChoice()
{
	return enGameChoice(RandomNumber(1, 3));
}

enGameChoice ReadPlayerChoice()
{
	short Choice;

	cout << "\nYour Choice: [1]:Stone, [2]:Paper, [3]:Scissors ? ";
	cin >> Choice;

	return enGameChoice(Choice);
}

short ReadHowManyRounds()
{
	short HowManyRounds;

	do
	{
		cout << "How Many Rounds 1 to 10 ?\n";
		cin >> HowManyRounds;
	} while (HowManyRounds < 1 || HowManyRounds > 10);

	return HowManyRounds;
}

enWinner RoundWinner(enGameChoice PlayerChoice, enGameChoice ComputerChoice)
{
	if (PlayerChoice == ComputerChoice)
	{
		system("color 6F");
		return enWinner::Draw;
	}

	if (PlayerChoice == enGameChoice::Stone)
	{
		if (ComputerChoice == enGameChoice::Scissors)
		{
			system("color 2F");
			return enWinner::Player1;
		}
		else
		{
			cout << '\a';
			system("color 4F");
			return enWinner::Computer;
		}
	}
	else if (PlayerChoice == enGameChoice::Paper)
	{
		if (ComputerChoice == enGameChoice::Stone)
		{
			system("color 2F");
			return enWinner::Player1;
		}
		else
		{
			cout << '\a';
			system("color 4F");
			return enWinner::Computer;
		}
	}
	else if (PlayerChoice == enGameChoice::Scissors)
	{
		if (ComputerChoice == enGameChoice::Paper)
		{
			system("color 2F");
			return enWinner::Player1;
		}
		else
		{
			cout << '\a';
			system("color 4F");
			return enWinner::Computer;
		}
	}
}

string ChoiceName(enGameChoice Choice)
{
	string arr[3] = { "Stone","Paper","Scissors"};

	return arr[Choice - 1];
}

string WinnerName(enWinner Winner)
{
	string arr[3] = { "Player1","Computer","No Winner" };

	return arr[Winner - 1];
}

void UpdateScoreBoard(short& Player1WinTimes, short& ComputerWinTimes, short& DrawTimes, enWinner Winner)
{
	switch (Winner)
	{
	case enWinner::Player1:
		Player1WinTimes++;
		break;
	
	case enWinner::Computer:
		ComputerWinTimes++;
		break;

	case enWinner::Draw:
		DrawTimes++;
		break;
	}
}

stGameResults UpdateGameResults(short HowManyRounds, short Player1WinTimes, short ComputerWinTimes, short DrawTimes, enWinner Winner)
{
	stGameResults GameResults;

	GameResults.GameRounds = HowManyRounds;
	GameResults.Player1WonTimes = Player1WinTimes;
	GameResults.ComputerWonTimes = ComputerWinTimes;
	GameResults.DrawTimes = DrawTimes;
	GameResults.FinalWinner = Winner;

	return GameResults;
}

enWinner WhoWonTheGame(short Player1WinTimes, short ComputerWinTimes)
{
	if (Player1WinTimes > ComputerWinTimes)
		return enWinner::Player1;
	else if (Player1WinTimes < ComputerWinTimes)
		return enWinner::Computer;
	else
		return enWinner::Draw;
}

void PlayGame(stGameResults& GameResults)
{
	stRoundResults RoundResults;
	short HowManyRounds = ReadHowManyRounds();

	short Player1WinTimes = 0, ComputerWinTimes = 0, DrawTimes = 0;

	for (short i = 1;i <= HowManyRounds;i++)
	{
		cout << "\nRound [" << i << "] begins:\n";

		RoundResults.RoundNumber = i;
		RoundResults.Player1Choice = ReadPlayerChoice();
		RoundResults.ComputerChoice = GetComputerChoice();
		RoundResults.Winner = RoundWinner(RoundResults.Player1Choice, RoundResults.ComputerChoice);
		RoundResults.WinnerName = WinnerName(RoundResults.Winner);

		cout << "\n____________Round [" << RoundResults.RoundNumber << "]_____________\n\n";
		cout << "Player1  Choice: " << ChoiceName(RoundResults.Player1Choice) << endl;
		cout << "Computer Choice: " << ChoiceName(RoundResults.ComputerChoice) << endl;
		cout << "Round Winner   : " << "[" << RoundResults.WinnerName << "]" << endl;
		cout << "__________________________________\n\n";

		UpdateScoreBoard(Player1WinTimes, ComputerWinTimes, DrawTimes, RoundResults.Winner);
	}

	enWinner GameWinner = WhoWonTheGame(Player1WinTimes, ComputerWinTimes);

	GameResults = UpdateGameResults(HowManyRounds, Player1WinTimes, ComputerWinTimes, DrawTimes, GameWinner);
}

string Tabs(short NumberOfTabs)
{
	string T = "";

	for (short i = 1;i <= NumberOfTabs;i++)
	{
		T += "    ";
	}

	return T;
}

void ShowGameOverScreen()
{
	cout << Tabs(4) << "____________________________________________________________\n\n";
	cout << Tabs(4) << "                    +++ G a m e  O v e r +++\n";
	cout << Tabs(4) << "____________________________________________________________\n\n";
}

void ShowFinalGameResults(stGameResults GameResults)
{
	cout << Tabs(4) << "_____________________ [Game Results]________________________\n\n";
	cout << Tabs(4) << "Game Rounds        : " << GameResults.GameRounds << endl;
	cout << Tabs(4) << "Player1 won times  : " << GameResults.Player1WonTimes << endl;
	cout << Tabs(4) << "Computer won times : " << GameResults.ComputerWonTimes << endl;
	cout << Tabs(4) << "Draw times         : " << GameResults.DrawTimes << endl;
	cout << Tabs(4) << "Final Winner       : " << WinnerName(GameResults.FinalWinner) << endl;
	cout << Tabs(4) << "____________________________________________________________\n\n";

}

void ResetScreen()
{
	system("cls");
	system("color 0F");
}

void StartGame()
{
	stGameResults GameResults;
	char PlayAgain;

	do
	{
		ResetScreen();
		PlayGame(GameResults);
		ShowGameOverScreen();
		ShowFinalGameResults(GameResults);

		cout << Tabs(4) << "Do you want to play again? Y/N? ";
		cin >> PlayAgain; 

	} while (PlayAgain == 'Y' || PlayAgain == 'y');
}

int main()
{
	srand((unsigned)time(NULL));

	StartGame();

	return 0;
}

