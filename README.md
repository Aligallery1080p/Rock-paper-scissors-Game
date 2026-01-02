# Rock-paper-scissors-Game
This is my first project ever. it is Rock-paper-scissors Game against computer using C++ i hope you like it

Rock-Paper-Scissors Game (C++)

A simple yet robust CLI-based Rock-Paper-Scissors game written in C++. This project demonstrates the use of Enums, Structs, Functions, and Control Structures to create a terminal-based gaming experience with visual feedback.
🚀 Features

    Customizable Rounds: Choose between 1 to 10 rounds per game session.

    Dynamic Visuals: The terminal background color changes based on the round outcome:

        🟢 Green: Player wins the round.

        🔴 Red: Computer wins the round (with a system beep).

        🟡 Yellow: Round is a draw.

    Comprehensive Stats: Detailed summary at the end of each game, including total wins for both sides and the number of draws.

    Replayability: Option to restart the game immediately after finishing.

🛠️ Technical Highlights

The code is organized using clean programming practices:

    Structs: Used stRoundResults and stGameResults to manage data efficiently.

    Enums: Used for enGameChoice and enWinner to improve code readability.

    Logic: Modularized functions for random number generation, winner determination, and UI rendering.

🎮 How to Play

    Clone the repository:
    Bash

git clone https://github.com/your-username/rock-paper-scissors-cpp.git

Compile the code: Use any C++ compiler (like g++):
Bash

g++ Rock-paper-scissors-Game.cpp -o RPSGame

Run the executable:
Bash

    ./RPSGame

    Rules:

        Enter the number of rounds you want to play.

        Choose [1] Stone, [2] Paper, or [3] Scissors.

        The computer will make its choice, and the winner will be displayed instantly!

📸 Preview
Plaintext

_____________________ [Game Results]________________________

Game Rounds        : 3
Player1 won times  : 2
Computer won times : 1
Draw times         : 0
Final Winner       : Player1
____________________________________________________________

Do you want to play again? Y/N?

