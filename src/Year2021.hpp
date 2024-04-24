#ifndef _Year2021_
#define _Year2021_

#include <vector>
#include <string>

#include "UnavailableDateException.hpp"
#include "AdventOfCode.hpp"

typedef std::vector<std::vector<int>> matrixII;

class Year2021
{
private:
    static unsigned int incrementByOne_11(matrixII& octopus);
    static void makeFlash_11_1(matrixII& octopus, const int& row, const int& col);


public:
    static unsigned int getResult_1(const bool& isPartOne);
    static unsigned int getResult_11(const bool& isPartOne);
};

#endif // _Year2021_