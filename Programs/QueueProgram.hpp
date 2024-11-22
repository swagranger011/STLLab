#ifndef _QUEUE_PROGRAM_HPP
#define _QUEUE_PROGRAM_HPP

#include "ProgramBase.hpp"

#include <queue>
#include <iostream>
using namespace std;

// https://www.cplusplus.com/reference/queue/queue/
class QueueProgram : public ProgramBase
{
    public:
    QueueProgram() { m_name = "queue"; }
    virtual ~QueueProgram() {}

    virtual void Intro();
    virtual void Add();
    virtual void Access();
    virtual void View();
    virtual void Empty();

    virtual int GetSize() { return m_data.size(); }

    private:
    queue<string> m_data;
};

void QueueProgram::Intro()
{
    cout    << "A QUEUE is a type of restricted data structure." << endl
            << "You can only add items from the BACK," << endl
            << "and you can only access, and remove items from the FRONT." << endl << endl
            << "The following items will be added in this order:" << endl;

}

void QueueProgram::Add()
{
    string data = Menu::GetStringLine( "New data item" );
    m_data.push( data );
    cout << "Item added." << endl;
}

void QueueProgram::Access()
{
    cout << "The item at the front of the queue is: " << m_data.front() << endl << endl;
}

void QueueProgram::View()
{
    queue<string> tempQueue;
    cout << "FRONT ";
    while ( !m_data.empty() )
    {
        cout << m_data.front() << " ";
        tempQueue.push( m_data.front() );
        m_data.pop();
    }
    cout << "BACK" << endl << endl;
    m_data = tempQueue;
}

void QueueProgram::Empty()
{
    if ( !m_data.empty() )
    {
        m_data.pop();
        cout << "Removed the item at the front of the queue." << endl;
    }
}

#endif
