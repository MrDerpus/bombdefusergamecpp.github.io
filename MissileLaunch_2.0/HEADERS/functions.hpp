using namespace std;


// Functions . . .
/*void HOLT(){ getch(); } // Wait for button press . . .
void CLR(){ system("CLS"); } // Clear screen . . .*/


/*void ConsoleBasics() // Save windows width & height + get username and computer name . . .
{
	CLR(); printf(BWHT);
	SetConsoleTitle(s_WindowTitle.c_str());

	HWND consoleWindow = GetConsoleWindow();
	SetWindowLong(consoleWindow, GWL_STYLE,
	GetWindowLong(consoleWindow, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);

	GetUserName((TCHAR*) c_UserName, &CNsize);
	GetComputerName((TCHAR*) c_ComputerName, &UNsize);

	s_COMUS = string(c_ComputerName) + "_" + string(c_UserName);
	//s_COMURL = s_curl + s_COMUS + s_ext;

}*/


/*void set_cursor(int row_Position, int col_Position)
{
	int x_position = col_Position;
	int y_position = row_Position;
    screen.X = x_position;
    screen.Y = y_position;
    SetConsoleCursorPosition(handle, screen);
}*/


/*void ShowConsoleCursor(bool showFlag)
{
    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(handle, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor status . . .
    SetConsoleCursorInfo(handle, &cursorInfo);
}*/

/*void DisplaySplashscreen()
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
}*/

void loadingAnimation()
{

	// Pretty messy, but it does the job.
	int i_MessageCount = 0;
	gameSystem.ShowConsoleCursor(FALSE);
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
			gameSystem.set_cursor(28, 25);
		}
		else { i_MessageCount++; }
	}

	gameSystem.ShowConsoleCursor(TRUE);
}


/*void GrabDateTime()
{
	time_NULL = time(NULL);
	tm Localtime = *localtime(&time_NULL);
	// Grab the date (DD/MM/YYYY - INTS), convert the ints to strings . . .
	DATE_day   = Localtime.tm_mday; s_DATE_day  = to_string(DATE_day);
	DATE_mon  += Localtime.tm_mon;  s_DATE_mon  = to_string(DATE_mon);
	DATE_year += Localtime.tm_year; s_DATE_year = to_string(DATE_year);
	// Add all strings together into one big string, convert the string back into an int . . .

	//s_DATE_COM  = s_DATE_day + s_DATE_mon + s_DATE_year;
	// Above was a mistake and I made god cry.
	// It caused an error I didn't think about, where the function that checked
	// the expiry date and still consider it to be expired.
	// This was a formatting issue with collecting the data as DAY - MONTH - YEAR.
	// Where it should have been YEAR - MONTH - DAY, all along.

	//s_DATE_COM = s_DATE_year + s_DATE_mon + s_DATE_day;
	//DATE_COM   = stoi(s_DATE_COM);
}*/


/*void NumRoll() // Roll random numbers . . .
{
	for(unsigned i = 0; i < 6; i++)
	{
		RandInt = diceRoll(randomGen);
		SecInt = secAplhabet(randomGen);
	}
}*/

/*void secFileNameGen()
{
	// serial key . . .
	while(s_randomGenString.length() < 8)
	{
		NumRoll();
		s_randomGenString += c_fullaplabet[SecInt];
		//Sleep(50);
	}

	// Debug printf() function . . .
	//printf("%s\n", s_randomGenString.c_str());
	s_ranFileName = s_randomGenString + "." + s_randomGenString;
	s_COMURL = s_curlOne + s_ranFileName + s_curlTwo + s_COMUS + s_ext; // THIS IS THE CURL COMMAND TO GRAB FILE FROM SERVER . . .

	s_randomGenString = s_NULL_Str;
}*/

/*void Num2Char() // Assign numbers to chars . . .
{
	NumRoll();
	RandomChar = c_Aplhabet[RandInt];

	// DEBUG DISPLAY . . .
	//if(RandInt < 10)
	//{ printf("RandInt: 0%i  |  RandomChar: %c \n", RandInt, RandomChar); }
	//else
	//{ printf("RandInt: %i  |  RandomChar: %c \n", RandInt, RandomChar); }
}*/


// Change a chactrer in a string to another char . . .
/*void Replace_Char(string& source, string const& find, string const& replace)
{
	for(string::size_type i = 0; (i = source.find(find, i)) != std::string::npos;)
	{
		source.replace(i, find.length(), replace);
		i += replace.length();
	}
}*/


/*void Replace_Sec()
{
	// Array for loop, for sec key decryption . . .
	for(unsigned i = 0; i < 10; i++)
	{
		s_Sec_Alph += c_Sec_Alph[i];
		s_Sec_Numb += c_Sec_Numb[i];

		Replace_Char(s_secretKey, s_Sec_Alph, s_Sec_Numb);

		s_Sec_Alph = s_NULL_Str;
		s_Sec_Numb = s_NULL_Str;
	}

}*/


/*void ReadKEY()
{
	// Check if computer has connection to the internet,
	// if not then loop an error message . . .
	if(system("PING www.google.com.au >NUL") == 1)
	{
		CLR();
		while(TRUE) // ERROR MESSAGE . . .
		{
			//printf(BRED "\n PLEASE CONNECT TO THE INTERNET AND RESART PROGRAM . . .");
			printf(BRED "\n You are not connected to the internet, please connect your");
			printf(BRED "\n device to the internet and restart the program . . .\n");
			Sleep(i_stdSleep);
		}
	}
	// if there is an internet connection: download file from server and assign all infomation to
	//appropriate variables . . .
	else
	{
		system(s_COMURL.c_str());
		KEY.open(s_ranFileName);

		getline(KEY, s_secretKey);
		getline(KEY, s_customerName);
		getline(KEY, s_flowState);

		KEY.close();
		KEY.clear();
		//system("DEL /Q \"serialKey.ini\"");
		string delCommandONE = "DEL /Q \""+ s_ranFileName +"\" ";
		system(delCommandONE.c_str());

		// ----------------------------------------------

		system("node node_dep.js");
		TIME.open("timefile.timefile");

		getline(TIME, s_DATE_COM); // cur date

		TIME.close();
		TIME.clear();


		system("DEL /Q \"timefile.timefile\" ");
		Replace_Sec();

		b_loadingAnimation = FALSE;

		// if there is no license
		while(s_secretKey == "xxx") // if there is no license . . .
		{
			printf(BRED "\n It seems that you do not have a license . . . ");
			printf(BRED "\n If you think this is a mistake please restart program while connected to the internet.");
			printf(BRED "\n If this persists please contact: %s. \n\n", s_contactEmail.c_str());
			Sleep(i_stdSleep);
		}


		i_secretKey = stoi(s_secretKey); // convert the deciphered string into an int value . . .
		DATE_COM = stoi(s_DATE_COM);
		Sleep(i_stdSleep);
	}
}*/


/*void ReadSETTINGS()
{
	SETTINGS.open("SETTINGS.ini");

	SETTINGS.ignore(10000, '\n');
	SETTINGS >> i_t_col; // get ammount of rows . . .
	//SETTINGS >> i_WinVal;

	for(unsigned i = 0; i < 3; i++){ SETTINGS.ignore(10000, '\n'); }
	SETTINGS >> i_SleepTime; // get sleep time . . .

	for(unsigned i = 0; i < 3; i++){ SETTINGS.ignore(10000, '\n'); }
	SETTINGS >> i_volumeValue; // get game volume setting . . .


	SETTINGS.close();
	SETTINGS.clear();

	i_WinVal = i_t_col * 5;
}*/


/*void GetUserInput() // Get user input . . .
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
}*/


/*void Slow_Print(const string& printMsg, unsigned int millis_per_char)
{
	for(const char c: printMsg)
	{
		cout << c << flush;
		sleep_for(milliseconds(millis_per_char));
	}
}*/

// Play sound files . . .
/*void SoundPlay(const string& sndFileName)
{
	string fullstring = "play " + sndFileName;
	mciSendString(fullstring.c_str(), NULL, 0, NULL);
}*/


/*void Draw_Table()
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

}*/

// Upload . . .
// curl -u USER:PASS -T file.file ftp://files.000webhost.com:port/Path/To/File/file.file
// Download . . .
// curl -o file.file -s --url https://website.com/Path/To/File/file.file
