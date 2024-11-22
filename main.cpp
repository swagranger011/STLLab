// Input/Output
#include <iostream>
using namespace std;

// Menu stuff
#include "Utilities/Menu.hpp"

// Each program type
#include "Programs/VectorProgram.hpp"
#include "Programs/ListProgram.hpp"
#include "Programs/MapProgram.hpp"
#include "Programs/QueueProgram.hpp"
#include "Programs/StackProgram.hpp"

int main()
{
    while ( true )
    {
        Menu::Header( "MAIN MENU" );

        cout << "Select which STL structure you want to work with." << endl << endl;

        string whichProgram = Menu::ShowStringMenuWithPrompt( {
            "QUIT PROGRAM",
            "Vector",
            "List",
            "Map",
            "Stack",
            "Queue"
        } );

        ProgramBase* program = nullptr;
        if      ( whichProgram == "Vector" ) { program = new VectorProgram(); }
        else if ( whichProgram == "List" )   { program = new ListProgram(); }
        else if ( whichProgram == "Map" )    { program = new MapProgram(); }
        else if ( whichProgram == "Stack" )  { program = new StackProgram(); }
        else if ( whichProgram == "Queue" )  { program = new QueueProgram(); }
        else
        {
            break; /* End program */
        }

        // Running the program
        bool runningSubProgram = true;
        Menu::Header( program->GetProgramName() );
        program->Intro();

        while ( runningSubProgram )
        {
            cout << program->GetSize() << " item(s) in structure." << endl;
            program->View();

            string whichOperation = Menu::ShowStringMenuWithPrompt( {
                "QUIT " + program->GetProgramName() + " STRUCTURE",
                "Add",
                "Access",
                "Remove",
            } );

            if      ( whichOperation == "Add" )     { program->Add(); }
            else if ( whichOperation == "Access" )  { program->Access(); }
            else if ( whichOperation == "Remove" )   { program->Empty(); }
            else
            {
                 runningSubProgram = false;

                if ( program != nullptr )
                {
                    delete program;
                    program = nullptr;
                }
            }
        }
    }

    return 0;
}


