#ifndef _MYTH52125_STRARG_H_
#define _MYTH52125_STRARG_H_

#include <string>
#include <string.h>
#include <cassert>
#include <algorithm>


namespace myth52125
{

using namespace std;

class StrArg
{
public:
    explicit StrArg()
        :mp_data(new char[1])
    {
        *mp_data='\0';
    }
    explicit StrArg(const string &str)
        :mp_data(new char[str.size()+1])
    {
        strcpy(mp_data,str.c_str());
    }
    explicit StrArg(const char *str)
        :mp_data(new char[strlen(str)+1])
    {
        strcpy(mp_data,str);
    }
    explicit StrArg(const StrArg& str)
        :mp_data(new char[str.size()+1])
    {
        strcpy(mp_data,str.c_str());
    }
    ~StrArg()
    {
        delete[] mp_data;
    }
private:
    char *mp_data;

public:
    const char *c_str() const
    {
        return mp_data;
    }

    size_t size() const
    {
        return strlen(mp_data);
    }

    StrArg& operator=(StrArg rhs)
    {   
        swap(rhs);
        return *this;
    }

    void swap(StrArg& rhs)
    {
        std::swap(mp_data,rhs.mp_data);
    }
    bool empty()
    {
        return size() == 1;
    }
};

}

#endif  //_MYTH52125_STRARG_H_