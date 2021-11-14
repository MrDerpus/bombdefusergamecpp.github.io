using std::this_thread::sleep_for;
using std::chrono::milliseconds;
using namespace std;

// Functions . . .
// Colours . . .
void ConsoleColour()
{ SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); }
void GreenText()
{ SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); }
void AquaText()
{ SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11); }
void YellowText()
{ SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14); }
void RedText()
{ SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); }


void HOLT(){ getch(); } // Wait for button press . . .
void CLR(){ system("cls"); } // Clear screen . . .

void SaveWindow_HW() // Save windows width and height . . .
{
	HWND consoleWindow = GetConsoleWindow();
	SetWindowLong(consoleWindow, GWL_STYLE,
	GetWindowLong(consoleWindow, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);
}
void GetComputerName() // Get Computer name . . .
{ GetComputerName((TCHAR*) c_ComputerName, &CNsize); }


void NumRoll() // Roll random numbers . . .
{
	for(int i = 0; i < 5; i++)
	{ Sleep(15); RandInt = diceRoll(randomGen); }
}

void Num2Char() // Assign numbers to chars . . .
{
	NumRoll();
	if(RandInt ==  1){ RandomChar = 'A'; }
	if(RandInt ==  2){ RandomChar = 'B'; }
	if(RandInt ==  3){ RandomChar = 'C'; }
	if(RandInt ==  4){ RandomChar = 'D'; }
	if(RandInt ==  5){ RandomChar = 'E'; }
	if(RandInt ==  6){ RandomChar = 'F'; }
	if(RandInt ==  7){ RandomChar = 'G'; }
	if(RandInt ==  8){ RandomChar = 'H'; }
	if(RandInt ==  9){ RandomChar = 'I'; }
	if(RandInt == 10){ RandomChar = 'J'; }
	if(RandInt == 11){ RandomChar = 'K'; }
	if(RandInt == 12){ RandomChar = 'L'; }
	if(RandInt == 13){ RandomChar = 'M'; }
	if(RandInt == 14){ RandomChar = 'N'; }
	if(RandInt == 15){ RandomChar = 'O'; }
	if(RandInt == 16){ RandomChar = 'P'; }
	if(RandInt == 17){ RandomChar = 'Q'; }
	if(RandInt == 18){ RandomChar = 'R'; }
	if(RandInt == 19){ RandomChar = 'S'; }
	if(RandInt == 20){ RandomChar = 'T'; }
	if(RandInt == 21){ RandomChar = 'U'; }
	if(RandInt == 22){ RandomChar = 'W'; }
	if(RandInt == 23){ RandomChar = 'X'; }
	if(RandInt == 24){ RandomChar = 'Y'; }
	if(RandInt == 25){ RandomChar = 'Z'; }
	if(RandInt == 26){ RandomChar = '0'; }
	if(RandInt == 27){ RandomChar = '1'; }
	if(RandInt == 28){ RandomChar = '2'; }
	if(RandInt == 29){ RandomChar = '3'; }
	if(RandInt == 30){ RandomChar = '4'; }
	if(RandInt == 31){ RandomChar = '5'; }
	if(RandInt == 32){ RandomChar = '6'; }
	if(RandInt == 33){ RandomChar = '7'; }
	if(RandInt == 34){ RandomChar = '8'; }
	if(RandInt == 35){ RandomChar = '9'; }
}

//  Change a chactrer in a string to another char . . .
void Replace_Char(string& source, string const& find, string const& replace)
{
	for(string::size_type i = 0; (i = source.find(find, i)) != std::string::npos;)
	{
		source.replace(i, find.length(), replace);
		i += replace.length();
	}
}
void Replace_It()
{
	Replace_Char(s_UserInput, "a", "A");
	Replace_Char(s_UserInput, "b", "B");
	Replace_Char(s_UserInput, "c", "C");
	Replace_Char(s_UserInput, "d", "D");
	Replace_Char(s_UserInput, "e", "E");
	Replace_Char(s_UserInput, "f", "F");
	Replace_Char(s_UserInput, "g", "G");
	Replace_Char(s_UserInput, "h", "H");
	Replace_Char(s_UserInput, "i", "I");
	Replace_Char(s_UserInput, "j", "J");
	Replace_Char(s_UserInput, "k", "K");
	Replace_Char(s_UserInput, "l", "L");
	Replace_Char(s_UserInput, "m", "M");
	Replace_Char(s_UserInput, "n", "N");
	Replace_Char(s_UserInput, "o", "O");
	Replace_Char(s_UserInput, "p", "P");
	Replace_Char(s_UserInput, "q", "Q");
	Replace_Char(s_UserInput, "r", "R");
	Replace_Char(s_UserInput, "s", "S");
	Replace_Char(s_UserInput, "t", "T");
	Replace_Char(s_UserInput, "u", "U");
	Replace_Char(s_UserInput, "v", "V");
	Replace_Char(s_UserInput, "w", "W");
	Replace_Char(s_UserInput, "x", "X");
	Replace_Char(s_UserInput, "y", "Y");
	Replace_Char(s_UserInput, "z", "Z");
}
void GetUserInput() // Get user input . . .
{
	printf("  $:/TEAM LOGIN/"); 
	RedText(); printf("%s", c_ComputerName);
	AquaText(); printf("/");
	GreenText(); getline(cin, s_UserInput); ConsoleColour();
	Replace_It();
}

void ReadSETTINGS()
{
	SETTINGS.open("../../_bin/SETTINGS.ini");
	SETTINGS >> i_WinVal;
	SETTINGS >> i_SleepTime;
	SETTINGS.close();
	SETTINGS.clear();
}



void Slow_Print(const string& printMsg, unsigned int millis_per_char)
{
	for(const char c: printMsg)
	{
		cout << c << flush;
		sleep_for(milliseconds(millis_per_char));
	}
}
