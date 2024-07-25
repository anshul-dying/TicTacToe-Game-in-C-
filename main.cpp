	#include <iostream>
	#include <string>
	#include <cstdbool>

	//Define Players
	const char playerX = 'X';
	const char playerO = 'O';

	void drawBoard(char board[3][3]);
	void checkWin(char board[3][3], bool& x, bool& o, bool& tie);

	int main()
	{
		//Layout for board and to store X and O
		char board[3][3] = {
			{' ', ' ', ' '},
			{' ', ' ', ' '},
			{' ', ' ', ' '}
		};

		char currPlayer = playerX;  //Keep track of current player
		int r = -1, c = -1;

		bool w_playerX	= false;
		bool w_playerO	= false;
		bool tie = false;

		while(!w_playerX && !w_playerO && !tie)
		{
			//Print board each time
		START:
			drawBoard(board);

			//check if won
			checkWin(board, w_playerX, w_playerO, tie);
			if (w_playerX == true)
			{
				std::cout << "Player X won\n";
				return 0;
			}
			else if (w_playerO == true)
			{
				std::cout << "Player O won\n";
				return 0;
			}
			else if(tie == true)
			{
				std::cout << "TIE\n";
				return 0;
			}

			//Display Current player
			std::cout << "Current player is: " << currPlayer << '\n';

			//Take player input in which block he wants to put his character
			std::cout << "Enter row and column number: ";
			std::cin >> r >> c;

			//set corresponding block to player character
			if (board[r][c] == playerX || board[r][c] == playerO)
			{
				printf("Invalid\n");
				goto START;
			}
			else {
				board[r][c] = currPlayer;
			}

			//change player after each iteration
			currPlayer = (currPlayer == playerX) ? playerO : playerX;
		}

		return 0;
	}

	void drawBoard(char board[3][3])
	{
		std::cout << "     |     |     " << std::endl;
		std::cout << "  " << board[0][0] << "  |" << "  " << board[0][1] << "  |" << "  " << board[0][2] << std::endl;
		std::cout << "_____|_____|_____" << std::endl;
		std::cout << "     |     |     " << std::endl;
		std::cout << "  " << board[1][0] << "  |" << "  " << board[1][1] << "  |" << "  " << board[1][2] << std::endl;
		std::cout << "_____|_____|_____" << std::endl;
		std::cout << "     |     |     " << std::endl;
		std::cout << "  " << board[2][0] << "  |" << "  " << board[2][1] << "  |" << "  " << board[2][2] << std::endl;
		std::cout << "     |     |     " << std::endl;
	}

	void checkWin(char board[3][3], bool& x, bool& o, bool& tie)
	{
		if(!tie)
		{
			// Main diagonal
			if (board[0][0] == playerX && board[1][1] == playerX && board[2][2] == playerX) x = true;
			if (board[0][0] == playerO && board[1][1] == playerO && board[2][2] == playerO) o = true;

			// Second diagonal
			if (board[0][2] == playerX && board[1][1] == playerX && board[2][0] == playerX) x = true;
			if (board[0][2] == playerO && board[1][1] == playerO && board[2][0] == playerO) o = true;

			// Columns
			for (int i = 0; i < 3; i++)
			{
				if (board[0][i] == playerX && board[1][i] == playerX && board[2][i] == playerX) x = true;
				if (board[0][i] == playerO && board[1][i] == playerO && board[2][i] == playerO) o = true;
			}

			// Rows
			for (int i = 0; i < 3; i++)
			{
				if (board[i][0] == playerX && board[i][1] == playerX && board[i][2] == playerX) x = true;
				if (board[i][0] == playerO && board[i][1] == playerO && board[i][2] == playerO) o = true;
			}
		}
		
		// Check for tie
		tie = true;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (board[i][j] == ' ')
				{
					tie = false;
					return;
				}
			}
		}
	}
