#include "Year2021.hpp"

/// @brief This was one of my interview question, for an application at Odoo in 2024 for an end-of-study internship. 
unsigned int Year2021::getResult_11(const bool& isPartOne)
{
    // Instantiation of a fstream object which is a file.
    std::fstream readingFile;

    // Choose an input folder name and concatenate it to the name of the file.
    const std::string inputFileToRead = AdventOfCode::getNameOfFile(2021, 11);

    // Opening the file in reading mode.
    readingFile.open(inputFileToRead, std::ios::in);

    if (!readingFile.is_open())
    {
        AdventOfCode::displayErrorOpeningFile(readingFile, inputFileToRead);
        return -1;
    }

    // Instantiation of a string that will represent the line in the document.
    std::string lineFromInputText;

    // Declaration of the variables for this exercise
    matrixII matrixOfOctopus(1);

    // Retrieve lines into lineFromInputText to construct the matrix.
    while(getline(readingFile, lineFromInputText))
    {
        for (const char& value: lineFromInputText)
        {
            matrixOfOctopus.back().push_back(static_cast<int> (value - '0'));
        }
        matrixOfOctopus.push_back({});
    }
    matrixOfOctopus.pop_back();

    if (isPartOne)
    {
        unsigned int numberOfFlash = 0U;

        for (unsigned int index = 0; 100 > index; ++index)
        {
            numberOfFlash += incrementByOne_11(matrixOfOctopus);
        }

        return numberOfFlash;
    }
    else
    {
        unsigned int firstTimeAllFlash = 1;

        const unsigned int nbOfOctopus = matrixOfOctopus.size() * matrixOfOctopus[0].size();

        while (nbOfOctopus != incrementByOne_11(matrixOfOctopus))
        {
            ++ firstTimeAllFlash;
        }

        return firstTimeAllFlash;
    }

    return 0;
}

unsigned int Year2021::incrementByOne_11(matrixII& octopus)
{
    static int nbOfRow = octopus.size();
    static int nbOfCol = octopus[0].size();

    for (int index = 0; nbOfRow > index; ++index)
    {
        for (int subIndex = 0; nbOfCol > subIndex; ++subIndex)
        {
            // Increment and check if it flash
            if (10 == ++ octopus[index][subIndex])
            {
                makeFlash_11_1(octopus, index, subIndex);
            }
        }
    }

    unsigned int nbFlash = 0;

    // Reset after flash
    for (int index = 0; nbOfRow > index; ++index)
    {
        for (int subIndex = 0; nbOfCol > subIndex; ++subIndex)
        {
            if (10 <= octopus[index][subIndex])
            {
                nbFlash++;
                octopus[index][subIndex] = 0;
            }
        }
    }

    return nbFlash;
}

void Year2021::makeFlash_11_1(matrixII& octopus, const int& row, const int& col)
{
    static int nbOfRow = octopus.size();
    static int nbOfCol = octopus[0].size();

    int indexStart = std::max(0, row - 1);
    int indexEnd = std::min(nbOfRow - 1, row + 1);
    int subIndexStart = std::max(0, col - 1);
    int subIndexEnd = std::min(nbOfCol - 1, col + 1);

    for (int index = indexStart; indexEnd >= index; ++index)
    {
        for (int subIndex = subIndexStart; subIndexEnd >= subIndex; ++subIndex)
        {
            if (10 == ++octopus[index][subIndex])
            {
                makeFlash_11_1(octopus, index, subIndex);
            }
        }
    }
}