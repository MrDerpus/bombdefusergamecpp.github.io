// Dedicated to all fucntions that read/write or upload/download files.
using namespace std;

class file
{
	public:

		void ReadSETTINGS() // Read settings file . . .
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
		}


		void Replace_Char(string& source, string const& find, string const& replace)
		{
			for(string::size_type i = 0; (i = source.find(find, i)) != std::string::npos;)
			{
				source.replace(i, find.length(), replace);
				i += replace.length();
			}
		}


		void Replace_Sec()
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

		}


		void secFileNameGen()
		{
			// serial key . . .
			while(s_randomGenString.length() < 8)
			{
				consoleBasics.NumRoll();
				s_randomGenString += c_fullaplabet[SecInt];
				//Sleep(50);
			}

			// Debug printf() function . . .
			//printf("%s\n", s_randomGenString.c_str());
			s_ranFileName = s_randomGenString + "." + s_randomGenString;
			s_COMURL = s_curlOne + s_ranFileName + s_curlTwo + s_COMUS + s_ext; // THIS IS THE CURL COMMAND TO GRAB FILE FROM SERVER . . .

			s_randomGenString = s_NULL_Str;
		}

		void ReadKEY() // Read security key that is downloaded . . .
		{
			// Check if computer has connection to the internet,
			// if not then loop an error message . . .
			if(system("PING www.google.com.au >NUL") == 1)
			{
				consoleBasics.CLR();
				while(TRUE) // ERROR MESSAGE . . .
				{
					//printf(BRED "\n PLEASE CONNECT TO THE INTERNET AND RESART PROGRAM . . .");
					printf(BRED "\n You are not connected to the internet, please connect your");
					printf(BRED "\n device to the internet and restart the program . . .\n");
					Sleep(i_stdSleep);
				}
			}
			/* if there is an internet connection: download file from server and assign all infomation to
			appropriate variables . . . */
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


		}
};
