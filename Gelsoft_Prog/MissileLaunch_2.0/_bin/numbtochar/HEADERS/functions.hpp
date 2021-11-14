using namespace std;

// Functions . . .
void HOLT(){ getch(); } // Wait for button press . . .


void ConsoleBasics() // Save windows width & height + get username and computer name . . .
{
	// Set console text to white . . .
	system("CLS"); printf(BWHT);


	// Keep console windows to one size . . .
	HWND consoleWindow = GetConsoleWindow(); 
	SetWindowLong(consoleWindow, GWL_STYLE,
	GetWindowLong(consoleWindow, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);

	// Get username and computer name . . .
	GetUserName((TCHAR*) c_UserName, &UNsize);
	GetComputerName((TCHAR*) c_ComputerName, &CNsize);
}





// Change a chactrer in a string to another char . . .
void Replace_Char(string& source, string const& find, string const& replace)
{
	for(string::size_type i = 0; (i = source.find(find, i)) != std::string::npos;)
	{
		source.replace(i, find.length(), replace);
		i += replace.length();
	}
}












void Replace_c2n()
{
	// Array for loop, for sec key decryption . . .
	for(unsigned i = 0; i < 10; i++)
	{
		s_Sec_Alph += c_Sec_Alph[i];
		s_Sec_Numb += c_Sec_Numb[i];

		Replace_Char(s_UserInput, s_Sec_Alph, s_Sec_Numb);

		s_Sec_Alph = s_NULL_Str;
		s_Sec_Numb = s_NULL_Str;
	}

}

void Replace_n2c()
{
	// Array for loop, for sec key decryption . . .
	for(unsigned i = 0; i < 10; i++)
	{
		s_Sec_Alph += c_Sec_Alph[i];
		s_Sec_Numb += c_Sec_Numb[i];

		Replace_Char(s_UserInput, s_Sec_Numb, s_Sec_Alph);

		s_Sec_Alph = s_NULL_Str;
		s_Sec_Numb = s_NULL_Str;
	}

}