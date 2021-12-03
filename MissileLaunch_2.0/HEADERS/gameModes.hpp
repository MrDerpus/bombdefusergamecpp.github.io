using namespace std;

class gameModes
{
	public:
		// ---------------------- Game mode one | Button press gamemode functions . . .
		void Draw_Table()
		{
			// This will draw the border / screen for the game . . .
			//top
			printf("  \xDA\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC2\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC2\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC2\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC2\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xBF \n");

			for(int i = 0; i < i_t_col; i++)
			{
				//cell
				printf("  \xB3 ? : ? \xB3 ? : ? \xB3 ? : ? \xB3 ? : ? \xB3 ? : ? \xB3 \n");

				if(i < i_t_col - 1)
				{
					//linespace
					printf("  \xC3\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC5\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC5\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC5\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC5\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xB4 \n");
				}
			}

			//bottom
			printf("  \xC0\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC1\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC1\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC1\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC1\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xD9 \n");

		}



		void GamemodeONE()
		{
			printf(BYEL); consoleBasics.CLR();

			// Display rules & count down till game starts. . .
			consoleBasics.Slow_Print("  Press the correct keys on the keyboard to defuse the bomb . . . \n\n  ", 25);
			consoleBasics.Slow_Print("3 2 1", 250); Sleep(750);
			printf("  GO! \n\n"); Sleep(250);

			printf(BWHT); Draw_Table();
			gameSystem.set_cursor(i_row, i_col);


			// Play game . . .
			while(i_count < i_WinVal)
			{
				// Randomise roll & print the random number on
				// screen for the player to press . . .
				consoleBasics.Num2Char(); printf(BWHT "%c : ", RandomChar); Sleep(i_SleepTime * 1000);




				///////// User presses . . .
				// If correct key is pressed, Loop until the
				// user fails, or wins the mini game . . .
				if(GetAsyncKeyState(RandomChar))
				{
					printf(BGRN "%c", RandomChar);
					b_Pressed = TRUE;

					// Play sound . . .
					if(i_volumeValue == 50){ consoleBasics.SoundPlay("snds/Correct_button_press_50.wav"); }
					if(i_volumeValue == 100){ consoleBasics.SoundPlay("snds/Correct_button_press_100.wav"); }

				}
				// if wrong button is pressed . . .
				if(!GetAsyncKeyState(RandomChar) && b_Pressed == FALSE)
				{
					// Display wrong key char and then end game . . .
					if(i_volumeValue == 50){ consoleBasics.SoundPlay("snds/Wrong_button_press_50.wav"); }
					if(i_volumeValue == 100){ consoleBasics.SoundPlay("snds/Wrong_button_press_100.wav"); }

					printf(BRED "\xce");
					i_t_row = i_WinVal;
					gameSystem.set_cursor(i_t_row + 2, 0);
					i_count = i_WinVal;
				}




				// New line everytime the var is greater than 4 . . .
				// Cosmetic only.
				throwAway++;
				if(throwAway < 5 && b_Pressed == TRUE){ printf(BWHT " \xb3 "); }
				if(throwAway > 4 && b_Pressed == TRUE){
					i_row += 2;
					gameSystem.set_cursor(i_row, i_col);
					throwAway = 0;
				}

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



		// ---------------------- Game mode two | Wires gamemode functions . . .
};
