#include "main.hpp"

int main()
{
    try
    {
        AdventOfCode::displayAnswer(2022, 1, true);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what();
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}