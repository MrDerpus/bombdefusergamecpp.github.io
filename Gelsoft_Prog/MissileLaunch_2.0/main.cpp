#include "HEADERS\includes.hpp"
using namespace std;

int main()
{
	ConsoleBasics();

	// 'Jucie up' the random number gen . . .
	for(unsigned i = 0; i < 5; i++){ Num2Char(); }

	// Grab current date and time from computer . . .
	GrabDateTime();

	// Main game loop . . .
	while(b_Running)
	{


		// Display splash screen . . .
		DisplaySplashscreen();
		printf(BWHT "  Bomb Defuser v1.0  |  Created by Matthew. Klatt\n");




		///////////////////////////////////////////////////////
		// Download and check if the license is valid
		// While downloading, display a loading animation . . .
		printf(BWHT "  Checking license . . . ");
		thread animation(loadingAnimation);
		while(!animation.joinable()){ loadingAnimation(); }


		// Download license . . .
		ReadKEY();

		animation.join();

		// if serial has not expired, Play . . .
		if(DATE_COM <= i_secretKey && DATE_COM > 0)
		{
			while(s_flowState != "ALLOW") // Check for exposed account . . .
			{
				printf(BRED " It appers that your license has been blocked for violating the terms of service.\n");
				printf(BRED " If you think this is a mistake please restart program while connected to the internet.\n");
				printf(BRED " If this persists please contact: %s. \n\n", s_contactNumber.c_str());
				//printf(BRED "%s", s_msg_error.c_str());
				Sleep(i_stdSleep);
			}

			b_GameRunning = TRUE;
			CLR();

			// Press to starty splash screen . . .
			system("TYPE \"presstostart.txt\" ");
			HOLT(); CLR();
		}
		// else, Throw error . . .
		else
		{

			b_newGame = FALSE;
			b_Running = FALSE;
			b_GameRunning = FALSE;



			while(DATE_COM > i_secretKey) // expired license . . .
			{
				printf(BRED " Hey there %s,\n it seems your license has expired. \n", s_customerName.c_str());
				printf(BRED " If you would like to renew your license, please contact: %s.\n\n", s_contactNumber.c_str());
				Sleep(i_stdSleep);
			}
		}
		///////////////////////////////////////////////////////




		while(b_GameRunning) // Game, main menu screen, waiting for player input . . .
		{
			// Get user input & 'log into the correct user profile', b_newGame = TRUE, starting a new game . . .
			GetUserInput();
			ReadSETTINGS();




			// If new game var is set to true, start new game . . .
			if(b_newGame == TRUE)
			{
				//i_count = 0; b_Pressed = FALSE;
				printf(BYEL); CLR();

				// Display rules & count down till game starts. . .
				Slow_Print("  Press the correct keys on the keyboard to defuse the bomb . . . \n\n  ", 25);
				Slow_Print("3 2 1", 250); Sleep(750);
				printf("  GO! \n\n"); Sleep(250);

				printf(BWHT); Draw_Table();
				set_cursor(i_row, i_col);


				// Play game . . .
				while(i_count < i_WinVal)
				{
					// Randomise roll & print the random number on
					// screen for the player to press . . .
					Num2Char(); printf(BWHT "%c : ", RandomChar); Sleep(i_SleepTime * 1000);




					///////// User presses . . .
					// If correct key is pressed, Loop until the
					// user fails, or wins the mini game . . .
					if(GetAsyncKeyState(RandomChar))
					{
						printf(BGRN "%c", RandomChar);
						b_Pressed = TRUE;

						// Play sound . . .
						if(i_volumeValue == 50){ SoundPlay("snds/Correct_button_press_50.wav"); }
						if(i_volumeValue == 100){ SoundPlay("snds/Correct_button_press_100.wav"); }

					}
					// if wrong button is pressed . . .
					if(!GetAsyncKeyState(RandomChar) && b_Pressed == FALSE)
					{
						// Display wrong key char and then end game . . .
						if(i_volumeValue == 50){ SoundPlay("snds/Wrong_button_press_50.wav"); }
						if(i_volumeValue == 100){ SoundPlay("snds/Wrong_button_press_100.wav"); }

						printf(BRED "\xce");
						i_t_row = i_WinVal;
						set_cursor(i_t_row + 2, 0);
						i_count = i_WinVal;
					}




					// New line everytime the var is greater than 4 . . .
					// Cosmetic only.
					throwAway++;
					if(throwAway < 5 && b_Pressed == TRUE){ printf(BWHT " \xb3 "); }
					if(throwAway > 4 && b_Pressed == TRUE){ i_row += 2; set_cursor(i_row, i_col); throwAway = 0; }

					// Reset vars while playing . . .
					b_Pressed = FALSE; // Reset value . . .
					i_count++; // Count up until it has reached it's limit . . .







					// If game is won . . .
					// Display the winning team.
					if(i_count == i_WinVal)
					{ printf("\n  TEAM '%s' IS THE WINNER ! \n",s_UserInput.c_str()); }


				}

				// Reset values after winning or loosing . . .
				i_row     = 5;
				i_count   = 0;
				throwAway = 0;
				b_Pressed = FALSE;
				b_newGame = FALSE;
			}
		///////////////////////////////////////////////////////////////////////////////////////

		}


	}
	printf(BWHT);
	return 0;
}
