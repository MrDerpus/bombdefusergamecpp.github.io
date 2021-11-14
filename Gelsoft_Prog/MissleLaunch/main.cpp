#include "HEADERS\includes.hpp"
using namespace std;

int main()
{
	// Program setup . . .
	SaveWindow_HW();
	GetComputerName();
	SetConsoleTitle(s_WindowTitle.c_str());

	// 'Jucie up' the random number gen . . .
	for(int i = 0; i < 5; i++){ Num2Char(); }

	// Clear screen . . .
	ConsoleColour(); CLR();




	// until the correct string has been
	while(b_Running)
	{


		// Loop Logo . . .
		printf("  A game mode created for Donnybrook Gel Ballers . . . \n"); printf("  Created by Matthew. Klatt \n");
		for(int i = 0; i < 5; i++)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10 + i);
			printf("    ____                                            _                 _               _             _    \n");
			printf("   |  _ \\ _ __ ___  ___ ___     __ _ _ __  _   _   | | _____ _   _   | |_ ___     ___| |_ __ _ _ __| |_  \n");
			printf("   | |_) | '__/ _ \\/ __/ __|   / _` | '_ \\| | | |  | |/ / _ \\ | | |  | __/ _ \\   / __| __/ _` | '__| __| \n");
			printf("   |  __/| | |  __/\\__ \\__ \\  | (_| | | | | |_| |  |   <  __/ |_| |  | || (_) |  \\__ \\ || (_| | |  | |_   _   _   _  \n");
			printf("   |_|   |_|  \\___||___/___/   \\__,_|_| |_|\\__, |  |_|\\_\\___|\\__, |   \\__\\___/   |___/\\__\\__,_|_|   \\__| (_) (_) (_) \n");
			printf("		                            |___/             |___/ \n");
		}
		HOLT(); b_GameRunning = TRUE;

		// Clear screen . . .
		ConsoleColour(); CLR();

		while(b_GameRunning)
		{
			// Get user input & log into the correct 'user profile'. . .
			GetUserInput();
			ReadSETTINGS(); // Read settings file . . .

			// Team logins  . . . ////////////////////////////////
			// If login is correct, let user play the game . . .
			if(s_UserInput == teamOneLogin || s_UserInput == teamTwoLogin || s_UserInput == ";")
			{
				i_count = 0; b_Pressed = FALSE;
				// Display rules & timer. . .
				CLR(); YellowText(); Slow_Print("  Press the correct keys on the keyboard to launch missiles . . . \n\n  ", 100); ConsoleColour();
				Slow_Print("3, 2, 1 ", 315); Sleep(2 * 1000); printf("  GO! \n\n"); Sleep(350);






				// Play game . . .
				while(i_count < i_WinVal)
				{
					// Randomise roll & print the random number on
					// screen for the player to press . . .
					Num2Char(); printf("  %c : ", RandomChar); Sleep(i_SleepTime * 1000);

					// If correct key is pressed, Loop until the
					// user fails, or wins the mini game . . .
					if(GetAsyncKeyState(RandomChar))
					{
						GreenText(); printf("%c", RandomChar); ConsoleColour();
						b_Pressed = TRUE; Beep(1500, 100);
					}


					// if wrong button is pressed . . .
					if(!GetAsyncKeyState(RandomChar) && b_Pressed == FALSE)
					{
						RedText(); printf(" FAIL! \n\n"); ConsoleColour();
						i_count = i_WinVal + 1;
					}



					// New line everytime the var is greater than 4 . . .
					// Cosmetic only.
					throwAway++;
					if(throwAway < 5 && b_Pressed == TRUE){ printf("  |"); }
					if(throwAway > 4 && b_Pressed == TRUE){ printf("\n"); throwAway = 0; }

					// Reset vars while playing . . .
					b_Pressed = FALSE; // Reset value . . .
					i_count++; // Count up until it has reached it's limit . . .







					// If game is won . . .
					// Display the winning team.
					if(i_count == i_WinVal)
					{ printf("\n  %s IS THE WINNER ! \n", s_UserInput.c_str()); i_count = i_WinVal; }
				}

				// Reset values after winning or loosing . . .
				i_count = 0;
				b_Pressed = FALSE;
				throwAway = 0;
			}
		/////////////////////////////////////////////////////////

		}
	}
	return 0;
}
