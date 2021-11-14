using namespace std;

// Rnadom number gen . . .
default_random_engine randomGen(time(NULL)); uniform_int_distribution<int> diceRoll(1,35);

// Bools . . .
bool b_Running = TRUE;
bool b_GameRunning;
bool b_Pressed = FALSE;
/////////////////////////////////////
// chars . . .
char c_ComputerName[250];
char RandomChar;
////////////////////////////////////
// DWORD's  . . .
DWORD CNsize = 250;
////////////////////////////////////
// Strings . . .
string s_WindowTitle = "Missile Launch Control Terminal v1.0";
string s_UserInput;
string printMsg = "3, 2, 1 ";
string teamOneLogin = "ALPHA TEAM LOGIN";
string teamTwoLogin = "BETA5 TEAM LOGIN";
///////////////////////////////////
// Ints . . .
int RandInt;
int throwAway = 0;
int i_count = 0;
int i_WinVal;
int i_SleepTime;
int TeamOne_failCount = 0;
int TeamTwo_failCount = 0;
///////////////////////////////////
// Read file data . . .
fstream SETTINGS;
///////////////////////////////////
