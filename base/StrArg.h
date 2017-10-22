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
    StrArg(const char *str)
        :mp_data(new char[strlen(str)+1])
    {
        strcpy(mp_data,str);
    }
    ~StrArg()
    {
        delete[] mp_data;
    }
private:
    char *mp_data;

public:
    char *c_str() const
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
        // //需要相等才能交换
        // assert(size() != rhs.size());
        // StrArg tmp_str(mp_data);
        // strcpy(mp_data,rhs.mp_data);
        // strcpy(rhs.mp_data,tmp_str.c_str());
        std::swap(mp_data,rhs.mp_data);
    }
};

}

#endif  //_MYTH52125_STRARG_H_