#ifndef _AdventOfCode_
#define _AdventOfCode_

#include <vector>

#include "Year2022.hpp"
#include "Year2021.hpp"
#include "UnavailableDateException.hpp"

class AdventOfCode
{
public:
    static void displayAnswer(const unsigned short& year, const unsigned short& day, const bool& isPartOne);
    
    static void displayErrorOpeningFile(const std::fstream& streamError, const std::string& nameOfFile);
    static std::string getNameOfFile(const unsigned int& year, const int& numberOfExercise);
};

#endif // _AdventOfCode_