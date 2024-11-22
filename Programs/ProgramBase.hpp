#ifndef _PROGRAM_BASE_HPP
#define _PROGRAM_BASE_HPP

class ProgramBase
{
    public:
    ProgramBase() { m_name = "base"; }
    virtual ~ProgramBase() {}

    virtual void Intro()    = 0;
    virtual void Add()      = 0;
    virtual void Access()   = 0;
    virtual void View()     = 0;
    virtual void Empty()    = 0;

    virtual int GetSize()   = 0;

    string GetProgramName() { return m_name; }

    protected:
    string m_name;
};

#endif
