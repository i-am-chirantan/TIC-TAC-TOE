# TIC-TAC-TOE
TIC-TAC-TOE-game
# Tic-Tac-Toe Game

![Tic-Tac-Toe](tic_tac_toe_image.png)

## Introduction

This C++ program is an implementation of the classic game of Tic-Tac-Toe. It allows two players to play against each other or play against a computer opponent.

## Features

- **Human vs. Human:** Two human players can take turns to play the game.
- **Human vs. Computer:** Play against a computer opponent that makes strategic moves.
- **Winning Conditions:** The game ends when a player fills an entire row, column, or diagonal with their symbol ('X' or 'O').
- **Draw Detection:** If no player wins and all cells are filled, the game is considered a draw.

## How to Play

1. Run the program.
2. Choose the game mode:
   - Press `1` for Human vs. Human.
   - Press `2` for Human vs. Computer.
3. Follow the on-screen instructions to enter player names and make moves.
4. Enjoy the game and have fun!

## Rules

- Players take turns marking cells on the 3x3 grid.
- The grid is numbered from 1 to 9 for player convenience.
- The game announces the winner or declares a draw at the end.

## Compilation and Execution

To compile and run the program, you can use the following commands:

```bash
g++ tic_tac_toe.cpp -o tic_tac_toe
./tic_tac_toe
