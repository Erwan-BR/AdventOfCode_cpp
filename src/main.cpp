#include "main.hpp"

int main()
{
    try
    {
        AdventOfCode::displayAnswer(2022, 1, true);
        AdventOfCode::displayAnswer(2022, 1, false);
        AdventOfCode::displayAnswer(2022, 2, true);
        AdventOfCode::displayAnswer(2022, 2, false);
        AdventOfCode::displayAnswer(2022, 3, true);
        AdventOfCode::displayAnswer(2022, 3, false);
        AdventOfCode::displayAnswer(2022, 4, true);
        AdventOfCode::displayAnswer(2022, 4, false);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}