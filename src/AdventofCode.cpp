#include "AdventOfCode.hpp"

void AdventOfCode::displayAnswer(const unsigned short& year, const unsigned short& day, const bool& isPartOne)
{
    // Check if year available
    if (2022 != year)
    {
        throw UnavailableDateExeption();
    }

    // Check if date available
    if (0 == day || 4 < day)
    {
        throw UnavailableDateExeption();
    }

    using Year2022_Ptr = unsigned int (*)(const bool&);
    static const std::vector<Year2022_Ptr> y22_Sol = {
        nullptr,
        &Year2022::getResult_1,
        &Year2022::getResult_2,
        &Year2022::getResult_3,
        &Year2022::getResult_4
    };

    unsigned int solution = 0;
    switch (year)
    {
        case 2022:
            solution = y22_Sol[day](isPartOne);
            break;
        default:
            break;
    }

    std::cout << "The solution for year " << year << ", day " << day << ((isPartOne) ? " (part one)" : " (part two)") << " is: " << solution << std::endl;
}