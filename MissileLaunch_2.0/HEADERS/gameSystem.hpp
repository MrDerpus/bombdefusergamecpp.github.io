using namespace std;

class gameSystem
{
	public:

		void DisplaySplashscreen()
		{
			if(s_DATE_day == "1" && s_DATE_mon == "1"){ system("TYPE \" newyears_day.txt\" "); } // New years day splashscreen . . .
			else if(s_DATE_day == "26" && s_DATE_mon == "1"){ system("TYPE \"aus_day.txt\" "); } // Australia day splashscreen . . .
			else if(s_DATE_day == "13" && s_DATE_mon == "2"){ system("TYPE \"valentines_day.txt\" "); } // Valentines day splashscreen . . .
			else if(s_DATE_day == "25" && s_DATE_mon == "5"){ system("TYPE \"poppyflower.txt\" "); } // Anzac day splashscreen . . .
			else if(s_DATE_day == "31" && s_DATE_mon == "10"){ system("TYPE \"halloween.txt\" "); } // Halloween splashscreen . . .
			else if(s_DATE_day == "11" && s_DATE_mon == "11"){ system("TYPE \"poppyflower.txt\" "); } // Rememberance day splashscreen . . .
			else if(s_DATE_day == "25" && s_DATE_mon == "12"){ system("TYPE \"xmas1.txt\" "); } // Christmas splashscreen . . .
			//else if(s_DATE_day == "" && s_DATE_mon == ""){ system("TYPE \" .txt\" "); }
			//else if(s_DATE_day == "" && s_DATE_mon == ""){ system("TYPE \" .txt\" "); }
			//else if(s_DATE_day == "" && s_DATE_mon == ""){ system("TYPE \" .txt\" "); }
			else { system("TYPE \"splash_screen.txt\" "); }
		}


		void set_cursor(int row_Position, int col_Position)
		{
			int x_position = col_Position;
			int y_position = row_Position;
		    screen.X = x_position;
		    screen.Y = y_position;
		    SetConsoleCursorPosition(handle, screen);
		}

		void ShowConsoleCursor(bool showFlag)
		{
		    CONSOLE_CURSOR_INFO cursorInfo;

		    GetConsoleCursorInfo(handle, &cursorInfo);
		    cursorInfo.bVisible = showFlag; // set the cursor status . . .
		    SetConsoleCursorInfo(handle, &cursorInfo);
		}

		/*void loadingAnimation()
		{

			// Pretty messy, but it does the job.
			int i_MessageCount = 0;
			ShowConsoleCursor(FALSE);
			while(s_flowState == "xxx" && b_loadingAnimation == TRUE)
			{
				for(unsigned i = 0; i < 3; i++)
				{ printf(BMAG " o"); Sleep(150); }

				printf("\b\b\b\b\b\b");

				for(unsigned i = 0; i < 3; i++)
				{ printf(BMAG " O"); Sleep(150); }

				printf("\b\b\b\b\b\b");


				if(i_MessageCount == 10)
				{
					printf(BRED "\n\n\n  I think there might be an error. \n  Either you do not have a license or you have poor internet connection . . . \n");
					i_MessageCount++;
					set_cursor(28, 25);
				}
				else { i_MessageCount++; }
			}

			ShowConsoleCursor(TRUE);
		}*/


		void GetUserInput() // Get user input . . .
		{
			printf(BGRN " $" BWHT "TEAM" BCYN "> " BMAG);
		    // $/TEAM> ;

			getline(cin, s_UserInput); printf(reset);

			// transform text to upper case . . .
			for(unsigned i = 0; i < s_UserInput.length(); i++)
			{ s_UserInput[i] = toupper(s_UserInput[i]); }


			// Loop through text array, this is for 'GetUserInput();' . . .
			for(unsigned i = 0; i < 4; i++)
			{
				if(s_UserInput == string(c_Teams[i]))
				{
					// Set new game var to true and start new game . . .
					b_newGame = TRUE;
				}
			}




			// Commands . . .
			if(s_UserInput == ";CLR"){ consoleBasics.CLR(); } // Clear console . . .
			else if(s_UserInput == ";SPLASH"){ DisplaySplashscreen(); } // Display splashscreen . . .
			else if(s_UserInput == ";SETTINGS"){ system("start \"\" \"SETTINGS.ini\" >nul"); } // Open up the settings file in notepad . . .
			else if(s_UserInput == ";DIE") // Close game . . .
			{
				b_Running = FALSE;
				b_Pressed = FALSE;
				b_newGame = FALSE;
				b_GameRunning = FALSE;
				printf(BYEL "\n\n Exiting game . . . \n");
			}
			else if(s_UserInput == ";DEBUG") // Display options and options values . . .
			{
				file.ReadSETTINGS();
				printf(BWHT "\n");
				printf(BWHT "   s_customerName   :   " BMAG "%s \n", s_customerName.c_str());
				printf(BWHT "   Expire code      :   " BMAG "%s \n", s_secretKey.c_str());
				printf(BWHT "   c_ComputerName   :   " BMAG "%s \n", c_ComputerName);
				printf(BWHT "   c_UserName       :   " BMAG "%s \n", c_UserName);
				printf(BWHT "   Total # of cells :   " BMAG "%i \n", i_WinVal);
				printf(BWHT "   i_SleepTime      :   " BMAG "%i \n", i_SleepTime);
				printf(BWHT "   i_WinVal         :   " BMAG "%i \n", i_WinVal);
				printf(BWHT "   i_volumeValue    :   " BMAG "%i \n", i_volumeValue);
				printf(BWHT "\n");
			}
		}
};
