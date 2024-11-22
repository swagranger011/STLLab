#ifndef _VECTOR_PROGRAM_HPP
#define _VECTOR_PROGRAM_HPP

#include "ProgramBase.hpp"

#include <vector>
#include <iostream>
using namespace std;

// https://www.cplusplus.com/reference/vector/vector/
class VectorProgram : public ProgramBase
{
    public:
    VectorProgram() { m_name = "vector"; }
    virtual ~VectorProgram() {}

    virtual void Intro();
    virtual void Add();
    virtual void Access();
    virtual void View();
    virtual void Empty();

    virtual int GetSize() { return m_data.size(); }

    private:
    vector<string> m_data;
    m_data[0] = "a";
    m_data[1] = "b";
    m_data[2] = "c";
    m_data[3] = "d";
};

void VectorProgram::Intro()
{
    cout    << "The VECTOR data type is basically a dynamic array. You can use its" << endl
            << "functionality to add items to the VECTOR, and still randomly access" << endl
            << "elements using the subscript operator []." << endl << endl;
}

void VectorProgram::Add()
{
    string data = Menu::GetStringLine( "New data item" );
    m_data.push_back( data );
    cout << "Item added." << endl;
}

void VectorProgram::Access()
{
    if ( m_data.size() == 0 )
    {
        cout << "Vector is empty! Can't access anything..." << endl;
        return;
    }

    int index = Menu::GetValidChoice( 0, m_data.size() - 1, "Enter an index to access" );
    cout << "The element at index " << index << " is: " << m_data[index] << endl;
    cout << endl;
}

void VectorProgram::View()
{
    for ( unsigned int i = 0; i < m_data.size(); i++ )
    {
        cout << "m_data[" << i << "] = " << m_data[i] << endl;
    }
    cout << endl;
}

void VectorProgram::Empty()
{
    m_data.clear();
    cout << "Data has been cleared." << endl;
}

#endif
