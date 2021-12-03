#include "HEADERS\includes.hpp"
using namespace std;

int main()
{
	consoleBasics.GAME_STARTUP();
	file.secFileNameGen();

	// 'Jucie up' the random number gen . . .
	for(unsigned i = 0; i < 5; i++){ consoleBasics.Num2Char(); }

	// Grab current date and time from computer . . .
	consoleBasics.GrabDateTime();


	// Main game loop . . .
	while(b_Running)
	{


		// Display splash screen . . .
		gameSystem.DisplaySplashscreen();
		printf(BWHT "  Bomb Defuser v1.1.0  |  Created by Matthew. Klatt\n");




		///////////////////////////////////////////////////////
		// Download and check if the license is valid
		// While downloading, display a loading animation . . .
		printf(BWHT "  Checking license . . . ");
		thread animation(loadingAnimation);
		while(!animation.joinable()){ loadingAnimation(); }


		// Download license . . .
		file.ReadKEY();

		animation.join();

		// if serial has not expired, Play . . .
		if(DATE_COM <= i_secretKey && DATE_COM > 0)
		{
			while(s_flowState != "ALLOW") // Check for exposed account . . .
			{
				printf(BRED " It appers that your license has been blocked for violating the terms of service.\n");
				printf(BRED " If you think this is a mistake please restart program while connected to the internet.\n");
				printf(BRED " If this persists please contact: %s. \n\n", s_contactEmail.c_str());
				//printf(BRED "%s", s_msg_error.c_str());
				Sleep(i_stdSleep);
			}

			b_GameRunning = TRUE;
			consoleBasics.CLR();

			// Press to starty splash screen . . .
			system("TYPE \"presstostart.txt\" ");
			consoleBasics.HOLT(); consoleBasics.CLR();
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
				printf(BRED " If you would like to renew your license, please contact: %s.\n\n", s_contactEmail.c_str());
				Sleep(i_stdSleep);
			}
		}
		///////////////////////////////////////////////////////




		while(b_GameRunning) // Game, main menu screen, waiting for player input . . .
		{
			// Get user input & 'log into the correct user profile', b_newGame = TRUE, starting a new game . . .
			gameSystem.GetUserInput();
			file.ReadSETTINGS();




			// If new game var is set to true, start new game . . .
			if(b_newGame == TRUE)
			{
				//GAME MODE ONE
				gameModes.GamemodeONE();
			}
			//else if() // GAME MODE TWO IF STATMENT . . .
			{
				// GAME MODE TWO
			}
		///////////////////////////////////////////////////////////////////////////////////////

		}


	}
	printf(BWHT);
	return 0;
}
