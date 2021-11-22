class gamesystem
{
	public:
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


		void loadingAnimation()
		{
			int i_MessageCount = 0;
			ShowConsoleCursor(FALSE);
			while(s_flowState == "xxx")
			{
				// | ( | )
				/*printf(BMAG "|\b");  Sleep(130);
				printf(BMAG "(\b");  Sleep(130);
				printf(BMAG "|\b");  Sleep(130);
				printf(BMAG ")\b");  Sleep(130);*/

				/*printf(BMAG "d\b");  Sleep(130);
				printf(BMAG "q\b");  Sleep(130);
				printf(BMAG "b\b");  Sleep(130);
				printf(BMAG "p\b");  Sleep(130);*/

				/*printf(BMAG "O o O\b\b\b\b\b"); Sleep(130);
				printf(BMAG "o O o\b\b\b\b\b"); Sleep(130);*/

				for(unsigned i = 0; i < 3; i++)
				{ printf(BMAG " o"); Sleep(150); }

				printf("\b\b\b\b\b\b");

				for(unsigned i = 0; i < 3; i++)
				{ printf(BMAG " O"); Sleep(150); }

				printf("\b\b\b\b\b\b");


				if(i_MessageCount == 20)
				{
					printf(BRED "\n\n\n  I think there might be an error. \n  Either you do not have a license or you have poor internet connection . . . \n");
					i_MessageCount++;
					set_cursor(28, 25);
				}
				else { i_MessageCount++; }
			}
			ShowConsoleCursor(TRUE);
		}
};
