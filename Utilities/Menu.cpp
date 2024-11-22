#include "Menu.hpp"

bool Menu::s_lastCinWasStream = false;

string Menu::CinStreamString()
{
    string buffer;
    cin >> buffer;

    Menu::s_lastCinWasStream = true;

    return buffer;
}

int Menu::CinStreamInt()
{
    int buffer;
    cin >> buffer;

    Menu::s_lastCinWasStream = true;

    return buffer;
}

string Menu::CinGetlineString()
{
    string buffer;
    if ( Menu::s_lastCinWasStream )
    {
        cin.ignore();
    }

    getline( cin, buffer );
    Menu::s_lastCinWasStream = false;

    return buffer;
}

void Menu::Header( const string& header )
{
    DrawHorizontalBar( 80 );
    string head = "| " + header + " |";
    cout << " " << head << endl << " ";
    DrawHorizontalBar( head.size() );
    cout << endl;
}

void Menu::DrawHorizontalBar( int width, char symbol )
{
    for ( int i = 0; i < width; i++ )
    {
        cout << symbol;
    }
    cout << endl;
}

// MENUS and INPUT/OUTPUT
void Menu::ShowMenu( const vector<string> options, bool vertical )
{
    if ( vertical )
    {
        for ( unsigned int i = 0; i < options.size(); i++ )
        {
            cout << " " << (i+1) << ".\t" << options[i] << endl;
        }
    }
    else
    {
        for ( unsigned int i = 0; i < options.size(); i++ )
        {
            cout << " " << (i+1) << ". " << options[i] << "\t";
        }
        cout << endl;
    }
}

int Menu::ShowIntMenuWithPrompt( const vector<string> options, bool vertical )
{
    ShowMenu( options, vertical );
    int choice = GetValidChoice( 1, options.size() );
    return choice;
}

string Menu::ShowStringMenuWithPrompt( const vector<string> options, bool vertical )
{
    ShowMenu( options, vertical );
    int choice = GetValidChoice( 1, options.size() );
    string value = options[ choice-1 ];
    return value;
}

/*
 * Call looks like this:

Menu::ShowCallbackMenuWithPrompt( {
    { "Set text", bind( &Program::Menu_SetText, this ) },
    { "Get text", bind( &Program::Menu_GetText, this ) }
} )();
*
 * */
function<void(void)> Menu::ShowCallbackMenuWithPrompt( map<string, function<void(void)> > options, bool vertical )
{
    vector<string> menuOptions;
    for ( auto& opt : options )
    {
        menuOptions.push_back( opt.first );
    }

    ShowMenu( menuOptions, vertical );
    int choice = GetValidChoice( 1, options.size() );
    string key = menuOptions[ choice-1 ];

    return options[ key ];
}

int Menu::GetValidChoice( int min, int max, const string& message )
{
    if ( message != "" )
    {
        cout << endl;
        DrawHorizontalBar( message.size() + 2 );
        cout << " " << message << endl;
    }

    int choice = GetIntChoice();

    while ( choice < min || choice > max )
    {
        cout << "Invalid selection. Try again." << endl;
        choice = GetIntChoice();
    }

    return choice;
}

string Menu::GetStringChoice( const string& message )
{
    if ( message != "" )
    {
        cout << " " << message << endl;
    }

    cout << endl << " >> ";
    string choice = Menu::CinStreamString();
    cout << endl;
    return choice;
}

string Menu::GetStringLine( const string& message )
{
    if ( message != "" )
    {
        cout << " " << message << endl;
    }
    cout << endl << " >> ";
    string choice = Menu::CinGetlineString();
    cout << endl;
    return choice;
}

int Menu::GetIntChoice( const string& message )
{
    if ( message != "" )
    {
        cout << " " << message << endl;
    }
    cout << endl << " >> ";
    int choice = Menu::CinStreamInt();
    cout << endl;
    return choice;
}

// HANDY TRICKS
void Menu::ClearScreen()
{
    #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
        system( "cls" );
    #else
        system( "clear" );
    #endif
}

void Menu::Pause()
{
    #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
        system( "pause" );
    #else
        cout << endl << " Press ENTER to continue..." << endl;
        if ( Menu::s_lastCinWasStream )
        {
            cin.ignore( std::numeric_limits <std::streamsize> ::max(), '\n' );
        }
        else
        {
            cin.get();
        }
    #endif
}

void Menu::PrintPwd()
{
    #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
        system( "echo %cd%" );
    #else
        system( "pwd" );
    #endif
}


