#include "AdventOfCode.hpp"

void AdventOfCode::displayAnswer(const unsigned short& year, const unsigned short& day, const bool& isPartOne)
{
    // Check if result available
    if (2022 != year && 2021 != year)
    {
        throw UnavailableDateExeption();
    }

    // Check if date available
    if ((2022 == year && (0 == day || 4 < day)) || (2021 == year && (11 != day)))
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

    using Year2021_Ptr = unsigned int (*)(const bool&);
    static const std::vector<Year2021_Ptr> y21_Sol = {
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        &Year2021::getResult_11,
    };

    unsigned int solution = 0;
    switch (year)
    {
        case 2022:
            solution = y22_Sol[day](isPartOne);
            break;
        case 2021:
            solution = y21_Sol[day](isPartOne);
        default:
            break;
    }

    std::cout << "The solution for year " << year << ", day " << day << ((isPartOne) ? " (part one)" : " (part two)") << " is: " << solution << std::endl;
}

/// @brief Display to the user an error if an error occured when the file was opened.
/// @param streamError Stream where the error occured.
/// @param nameOfFile Name of the file that has not been opened.
void AdventOfCode::displayErrorOpeningFile(const std::fstream& streamError, const std::string& nameOfFile)
{
    std::cerr << "Error opening file: " << nameOfFile << std::endl;
    std::cerr << "Stream state: " << streamError.rdstate() << std::endl;
}

/// @brief Get the name of the file, according to the number of the exercise.
/// @param numberOfExercise Number of the exercise (day of the challenge in fact)
/// @return Name of the file to open to get the input of the challenge.
std::string AdventOfCode::getNameOfFile(const unsigned int& year, const int& numberOfExercise)
{
    // Choose an input folder name and concatenate it to the name of the file.
    const std::string inputFolderName = "src/textFiles/" + std::to_string(year) + "/" ;
    const std::string inputFileName = std::to_string(numberOfExercise) + ".txt";
    const std::string inputFileToRead = inputFolderName + inputFileName;

    return inputFileToRead;
}