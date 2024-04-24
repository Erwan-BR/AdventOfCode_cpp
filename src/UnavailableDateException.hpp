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

        return "The answer has not been coded for this date. Try the following dates:\n\
Year 2022: day 1 to 4.\nYear 2021: day 1, 11.\n";
    }
};

#endif // _UnavailableDateExeption_