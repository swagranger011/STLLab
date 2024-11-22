#ifndef _LIST_PROGRAM_HPP
#define _LIST_PROGRAM_HPP

#include "ProgramBase.hpp"

#include <list>
#include <iostream>
using namespace std;

// https://www.cplusplus.com/reference/list/list/
class ListProgram : public ProgramBase
{
    public:
    ListProgram() { m_name = "list"; }
    virtual ~ListProgram() {}

    virtual void Intro();
    virtual void Add();
    virtual void Access();
    virtual void View();
    virtual void Empty();

    virtual int GetSize() { return m_data.size(); }

    private:
    list<string> m_data;
};

void ListProgram::Intro()
{
    cout    << "The LIST data type is similar to a vector, but it's structured differently." << endl
            << "You can ADD, REMOVE, and ACCESS items at the front or back of the LIST." << endl
            << "However, you cannot randomly access items like with a vector or array." << endl << endl;
}

void ListProgram::Add()
{
    cout << "Push to what side of the list?" << endl;
    bool pushFront = ( Menu::ShowIntMenuWithPrompt( { "Push Front", "Push Back" } ) == 1 );

    string data = Menu::GetStringLine( "New data item" );

    if      ( data != "" && pushFront )    { m_data.push_front( data ); }
    else if ( data != "" && !pushFront )   { m_data.push_back( data ); }

    cout << "Item added." << endl;
}

void ListProgram::Access()
{
    if ( m_data.size() == 0 )
    {
        cout << "List is empty! Can't access anything..." << endl;
        return;
    }

    cout << "Access which side of the list?" << endl;
    int getLocation = Menu::ShowIntMenuWithPrompt( { "Get Front", "Get Back" } );

    if ( getLocation == 1 )
    {
        cout << "The front of the list is: " << m_data.front() << endl;
    }
    else
    {
        cout << "The back of the list is: " << m_data.back() << endl;
    }
    cout << endl;
}

void ListProgram::View()
{
    for ( auto& item : m_data )
    {
        cout << item << endl;
    }
    cout << endl;
}

void ListProgram::Empty()
{
    m_data.clear();
    cout << "Data has been cleared." << endl;
}

#endif
