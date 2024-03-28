#ifndef _UnavailableDateExeption_
#define _UnavailableDateExeption_

#include <iostream>
#include <vector>
#include <string>

class UnavailableDateExeption : public std::exception
{
public:
    const char* what() const throw()
    {
        return "Currently, there is no answer available. Check the latest version of develop, or branchs corresponding to the issues.\n";
    }
};

#endif // _UnavailableDateExeption_