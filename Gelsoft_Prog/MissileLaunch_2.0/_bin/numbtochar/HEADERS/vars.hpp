using namespace std;


// Bools . . .
bool b_Running = TRUE;
////////////////////////////////////
// Chars . . .
char c_UserName[250];
char c_ComputerName[250];
char c_MenuInput;

char c_Sec_Alph[10] = { 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm' };
char c_Sec_Numb[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
////////////////////////////////////
// DWORDs . . . (Now that wasn't very nice ;-[ )
DWORD UNsize = 250;
DWORD CNsize = 250;
////////////////////////////////////
// Strings . . .
string s_WindowTitle = "convert";
string s_UserInput;

string s_Sec_Alph = "";
string s_Sec_Numb = "";
string s_NULL_Str = "";
///////////////////////////////////
// Ints . . .
///////////////////////////////////
// Doubles . . .
///////////////////////////////////
// Handles . . .
//HANDLE ColourCode = GetStdHandle(STD_OUTPUT_HANDLE);
HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
///////////////////////////////////