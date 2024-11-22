#ifndef _MENU
#define _MENU

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <limits>
#include <map>
#include <functional>
using namespace std;

class Menu
{
    public:
    // OUTPUT
    static void Header( const string& header );
    static void DrawHorizontalBar( int width, char symbol = '-' );

    // MENUS and INPUT/OUTPUT
    static void ShowMenu( const vector<string> options, bool vertical = true );
    static int ShowIntMenuWithPrompt( const vector<string> options, bool vertical = true );
    static string ShowStringMenuWithPrompt( const vector<string> options, bool vertical = true );
    static function<void(void)> ShowCallbackMenuWithPrompt( map<string, function<void(void)> > options, bool vertical = true );
    static int GetValidChoice( int min, int max, const string& message = "" );
    static string GetStringChoice( const string& message = "" );
    static string GetStringLine( const string& message = "" );
    static int GetIntChoice( const string& message = "" );

    // HANDY TRICKS
    static void ClearScreen();
    static void Pause();
    static void PrintPwd();

    private:
    static bool s_lastCinWasStream;

    static string CinStreamString();
    static int CinStreamInt();
    static string CinGetlineString();
};



#endif

