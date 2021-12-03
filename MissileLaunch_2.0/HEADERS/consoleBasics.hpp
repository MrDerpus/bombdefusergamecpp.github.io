using std::this_thread::sleep_for;
using std::chrono::milliseconds;
using namespace std;

class consoleBasics
{
	public:
		void HOLT(){ cin.get(); } // Wait for button press . . .
		void CLR(){ system("CLS"); } // Clear screen . . .



		void GrabDateTime()
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
		}



		void GAME_STARTUP() // Save windows width & height + get username and computer name . . .
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

		}


		void SoundPlay(const string& sndFileName) // Play sound files . . .
		{
			string fullstring = "play " + sndFileName;
			mciSendString(fullstring.c_str(), NULL, 0, NULL);
		}


		void Num2Char() // Assign numbers to chars . . .
		{
			NumRoll();
			RandomChar = c_Aplhabet[RandInt];

			// DEBUG DISPLAY . . .
			/*if(RandInt < 10)
			{ printf("RandInt: 0%i  |  RandomChar: %c \n", RandInt, RandomChar); }
			else
			{ printf("RandInt: %i  |  RandomChar: %c \n", RandInt, RandomChar); }*/
		}


		void NumRoll() // Roll random numbers . . .
		{
			for(unsigned i = 0; i < 6; i++)
			{
				RandInt = diceRoll(randomGen);
				SecInt = secAplhabet(randomGen);
			}
		}


		void Slow_Print(const string& printMsg, unsigned int millis_per_char)
		{
			for(const char c: printMsg)
			{
				cout << c << flush;
				sleep_for(milliseconds(millis_per_char));
			}
		}
};
