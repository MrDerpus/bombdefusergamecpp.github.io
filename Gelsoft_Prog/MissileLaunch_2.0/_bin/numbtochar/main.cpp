#include "HEADERS\includes.hpp"
using namespace std;

int main()
{
	// Program setup . . .
	ConsoleBasics();
	SetConsoleTitle(s_WindowTitle.c_str());
	




	while(TRUE)
	{
		printf(BWHT "Press 1 for: convert numb to char \n");
		printf(BWHT "Press 2 for: convert char to numb \n");

		printf(BWHT "Choice: "); c_MenuInput = getch(); printf("%c \n", c_MenuInput);
		printf(BWHT "Input:  " BCYN); getline(cin, s_UserInput);


		if(s_UserInput.length() <= 10) // if input is =< 10, then run function, else error . . .
		{
			if(c_MenuInput == '1')
			{
				Replace_n2c();
			}
			else if(c_MenuInput == '2')
			{
				Replace_c2n();
			}
			else
			{
				printf(BRED "\n\n <FAIL, must be 1 or 2> \n\n");
			}
		}
		else
		{
			printf(BRED "\n\n <too big, must be 10 or smaller> \n\n");
		}

		// Output . . .
		printf(BWHT "Output:" BMAG " %s \n\n\n\n" BWHT, s_UserInput.c_str());
	}
	




	//printf("Hello World! \n\n");
	//printf("Username: %s \nComputername: %s", c_UserName, c_ComputerName);

	return 0;
}