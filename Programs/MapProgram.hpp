#ifndef _MAP_PROGRAM_HPP
#define _MAP_PROGRAM_HPP

#include "ProgramBase.hpp"

#include <map>
#include <iostream>
using namespace std;

// https://www.cplusplus.com/reference/map/map/
class MapProgram : public ProgramBase
{
    public:
    MapProgram() { m_name = "map"; }
    virtual ~MapProgram() {}

    virtual void Intro();
    virtual void Add();
    virtual void Access();
    virtual void View();
    virtual void Empty();

    virtual int GetSize() { return m_data.size(); }

    private:
    map<string,string> m_data;
};

void MapProgram::Intro()
{
    cout    << "A MAP is a type of data structure that lets you associate a KEY to a VALUE." << endl
            << "With arrays so far, an index is our key (0, 1, 2, 3, ...) and the value is" << endl
            << "whatever the data type of our array is." << endl
            << "With a map, the KEY and the VALUE can be any data types." << endl << endl;
}

void MapProgram::Add()
{
    string key      = Menu::GetStringLine( "Enter the KEY for the new item" );
    string value    = Menu::GetStringLine( "Enter the VALUE for the new item" );

    m_data[key] = value;

    cout << "Item added." << endl;
}

void MapProgram::Access()
{
    string key = Menu::GetStringLine( "Enter the KEY to access" );

    if ( m_data.find( key ) == m_data.end() )
    {
        cout << "Item with key " << key << " not found!" << endl;
    }
    else
    {
        cout << "Item with key " << key << ": " << m_data[key] << endl;
    }
    cout << endl;
}

void MapProgram::View()
{
    for ( auto& item : m_data )
    {
        cout << "Key: " << item.first << "\t Value: " << item.second << endl;
    }
    cout << endl;
}

void MapProgram::Empty()
{
    m_data.clear();
    cout << "Data has been cleared." << endl;
}

#endif
