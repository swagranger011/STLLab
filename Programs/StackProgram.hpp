#ifndef _STACK_PROGRAM_HPP
#define _STACK_PROGRAM_HPP

#include "ProgramBase.hpp"

#include <stack>
#include <iostream>
using namespace std;

// https://www.cplusplus.com/reference/stack/stack/
class StackProgram : public ProgramBase
{
    public:
    StackProgram() { m_name = "stack"; }
    virtual ~StackProgram() {}

    virtual void Intro();
    virtual void Add();
    virtual void Access();
    virtual void View();
    virtual void Empty();

    virtual int GetSize() { return m_data.size(); }

    private:
    stack<string> m_data;
};

void StackProgram::Intro()
{
    cout    << "A STACK is a type of restricted data structure." << endl
            << "You can only add, access, and remove items from the TOP." << endl << endl
            << "The following items will be added in this order:" << endl;

}

void StackProgram::Add()
{
    string data = Menu::GetStringLine( "New data item" );
    m_data.push( data );
    cout << "Item added." << endl;
}

void StackProgram::Access()
{
    cout << "The item at the top of the stack is: " << m_data.top() << endl << endl;
}

void StackProgram::View()
{
    stack<string> temp;
    cout << "TOP ";
    while ( !m_data.empty() )
    {
        cout << m_data.top() << " ";
        temp.push( m_data.top() );
        m_data.pop();
    }
    cout << "BOTTOM" << endl << endl;

    while ( !temp.empty() )
    {
        m_data.push( temp.top() );
        temp.pop();
    }
}

void StackProgram::Empty()
{
    if ( !m_data.empty() )
    {
        m_data.pop();
        cout << "Removed the item at the top of the stack." << endl;
    }
}

#endif
