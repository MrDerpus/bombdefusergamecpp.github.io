using namespace std;

// Random number gen . . .
default_random_engine randomGen(time(NULL));
uniform_int_distribution<int> diceRoll(1,35);
uniform_int_distribution<int> secAplhabet(1,66);


// Bools . . .
bool b_loadingAnimation = TRUE;
bool b_GameRunning = FALSE;
bool b_Running = TRUE;
bool b_Pressed = FALSE;
bool b_newGame = FALSE;
/////////////////////////////////////
// chars . . .
char RandomChar;
char c_UserName[450];
char c_ComputerName[450];
char c_Teams[4][10] = { "ALPHA", "BRAVO", "CHARL", ";" };
char c_Aplhabet[36] =
{
	'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'V', 'U', 'W', 'X', 'Y', 'Z',
	'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'
};
char c_fullaplabet[69] =
{
	'*', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
	'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
	'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '_', '#', '$', '!', '@', '%'
};

char c_Sec_Alph[10] = { 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm' };
char c_Sec_Numb[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };

char c_UserInput;
////////////////////////////////////
// DWORD's  . . .
DWORD CNsize = 450;
DWORD UNsize = 450;
////////////////////////////////////
// Strings . . .
string s_WindowTitle  = "Bomb defuser Terminal v1.0.0";
string s_secretKey    = "xxx";
string s_customerName = "<Customer name>";
string s_flowState    = "xxx";

string s_UserInput;

string s_NULL_Str = "";
string s_Sec_Alph = "";
string s_Sec_Numb = "";

string s_contactNumber = "xxx";
string s_contactEmail = "bdefusergame@email.com";
string s_msg_error = "There seems to be an error. \nPlease contact "+ s_contactEmail +" if you believe this is not correct. \n";
string s_msg_mistake = "If you think this is a mistake please restart program while connected to the internet. \n";
string printMsg;

string s_COMUS;
string s_COMURL;
//string s_curl = BROKEN 000WEBHOST LINK DO NOT USE "curl -o serialKey.ini -s --url https://bombdefuserv2licenseaustralia.000webhostapp.com/licences/";
string s_curl = "curl -o serialKey.ini -s --url https://raw.githubusercontent.com/MrDerpus/bombdefusergamecpp.github.io/main/licences/";
string s_curlOne = "curl -o ";
string s_curlTwo = " -s --url https://raw.githubusercontent.com/MrDerpus/bombdefusergamecpp.github.io/main/licences/";
string s_ext = ".txt";
string s_ranFileName;
string s_randomGenString = s_NULL_Str;
///////////////////////////////////
// Ints . . .
int RandInt;
int SecInt;
int throwAway   = 0;
int i_count     = 0;
int i_secretKey = 7;
int i_WinVal;
int i_SleepTime;
int i_volumeValue = 0;
//int chumis = 0;
int i_stdSleep = 2000;

// Table . . .
int i_t_col = 1;
int i_t_row = 1;
int i_UserDisplay = 1;

//cursor positioning . . .
int i_col = 4;
int i_row = 5;
///////////////////////////////////
// Read file data . . .
fstream SETTINGS; // Settings . . .
fstream TIME;     // Time . . .
fstream KEY;      // Key . . .
// Text files . . .
//ifstream splash_screen("splash_screen.txt");
//ifstream press_to_start("presstostart.txt");
///////////////////////////////////
// DATE & TIME . . .
time_t time_NULL;
struct tm Localtime;
int DATE_day = 0;
int DATE_mon  = 1;
int DATE_year = 1900;
int DATE_COM = 0;
int CDTM = 0;
///////////////////////////////////
// Strings . . .
string s_DATE_COM  = "xxx";
string s_DATE_day  = "xxx";
string s_DATE_mon  = "xxx";
string s_DATE_year = "xxx";
////////////////////////////////////
COORD screen;
HANDLE ColourCode = GetStdHandle(STD_OUTPUT_HANDLE);
HANDLE handle     = GetStdHandle(STD_OUTPUT_HANDLE);
///////////////////////////////////
