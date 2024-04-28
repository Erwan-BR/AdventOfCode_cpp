#include "Year2021.hpp"

unsigned int Year2021::getResult_1(const bool& isPartOne)
{
    // Instantiation of a fstream object which is a file.
    std::fstream readingFile;

    // Choose an input folder name and concatenate it to the name of the file.
    const std::string inputFileToRead = AdventOfCode::getNameOfFile(2021, 1);

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
    std::vector<int> depths;
    unsigned int numberOfIncreasingValues = 0U;

    // Retrieve lines into lineFromInputText to construct the matrix.
    while(getline(readingFile, lineFromInputText))
    {
        depths.push_back(stoi(lineFromInputText));
    }

    if (isPartOne)
    {
        for (size_t index = 1; depths.size() > index; ++index)
        {
            if (depths[index] > depths[index - 1])
            {
                ++ numberOfIncreasingValues;
            }
        }
    }
    else
    {
        for (size_t index = 3; depths.size() > index; ++index)
        {
            if (depths[index] > depths[index - 3])
            {
                ++ numberOfIncreasingValues;
            }
        }
    }
    return numberOfIncreasingValues;
}

unsigned int Year2021::getResult_2(const bool& isPartOne)
{
    // Instantiation of a fstream object which is a file.
    std::fstream readingFile;

    // Choose an input folder name and concatenate it to the name of the file.
    const std::string inputFileToRead = AdventOfCode::getNameOfFile(2021, 2);

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
    unsigned int depth = 0U;
    unsigned int front = 0U;

    if (isPartOne)
    {
        // Retrieve lines into lineFromInputText to compute depth and horizontal move
        while(getline(readingFile, lineFromInputText))
        {
            if ('f' == lineFromInputText.front())
            {
                front += static_cast<unsigned int> (lineFromInputText.back() - '0');
            }
            else if ('u' == lineFromInputText.front())
            {
                depth -= static_cast<unsigned int> (lineFromInputText.back() - '0');
            }
            else
            {
                depth += static_cast<unsigned int> (lineFromInputText.back() - '0');
            }
        }
    }
    else
    {
        unsigned int aim = 0U;

        // Retrieve lines into lineFromInputText to compute depth and horizontal move
        while(getline(readingFile, lineFromInputText))
        {
            if ('f' == lineFromInputText.front())
            {
                front += static_cast<unsigned int> (lineFromInputText.back() - '0');
                depth += aim * static_cast<unsigned int> (lineFromInputText.back() - '0');
            }
            else if ('u' == lineFromInputText.front())
            {
                aim -= static_cast<unsigned int> (lineFromInputText.back() - '0');
            }
            else
            {
                aim += static_cast<unsigned int> (lineFromInputText.back() - '0');
            }
        }
    }
    return front * depth;
}

unsigned int Year2021::getResult_3(const bool& isPartOne)
{
    // Instantiation of a fstream object which is a file.
    std::fstream readingFile;

    // Choose an input folder name and concatenate it to the name of the file.
    const std::string inputFileToRead = AdventOfCode::getNameOfFile(2021, 3);

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
    #define NB_BITS 12

    std::vector<unsigned int> frequenciesOfOne(NB_BITS);
    unsigned int numberOfLines = 0U;
    unsigned int gammaRate = 0U;
    unsigned int epsilonRate = 0U;

    if (isPartOne)
    {
        while (getline(readingFile, lineFromInputText))
        {
            for (size_t index = 0; NB_BITS > index; ++index)
            {
                frequenciesOfOne[index] += static_cast<unsigned int> (lineFromInputText[index] - '0');
            }
            ++numberOfLines;
        }

        for (size_t index = 0; NB_BITS > index; ++index)
        {
            if (frequenciesOfOne[index] > (numberOfLines / 2))
            {
                gammaRate += pow(2, (NB_BITS - index - 1));
            }
            else
            {
                epsilonRate += pow(2, (NB_BITS - index - 1));
            }
        }
    }
    else
    {
    }
    #undef NB_BITS

    return gammaRate * epsilonRate;
}

unsigned int Year2021::getResult_7(const bool& isPartOne)
{
    // Instantiation of a fstream object which is a file.
    std::fstream readingFile;

    // Choose an input folder name and concatenate it to the name of the file.
    const std::string inputFileToRead = AdventOfCode::getNameOfFile(2021, 7);

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
    std::vector<int> positionsOfCrabs;
    std::regex integer_regex("\\d+");

    while (getline(readingFile, lineFromInputText))
    {
        const auto words_begin = std::sregex_iterator(lineFromInputText.begin(), lineFromInputText.end(), integer_regex);
        const auto words_end = std::sregex_iterator();

        for (auto it = words_begin; words_end != it; ++it)
        {
            positionsOfCrabs.push_back(stoi(it->str()));
        }
    }
    unsigned int fuelNecessary = 0U;

    sort(positionsOfCrabs.begin(), positionsOfCrabs.end());

    if (isPartOne)
    {
        int median;
        if (positionsOfCrabs.size() % 2)
        {
            median = positionsOfCrabs[positionsOfCrabs.size() / 2];
        }
        else
        {
            median = (positionsOfCrabs[(positionsOfCrabs.size() / 2) - 1] + positionsOfCrabs[positionsOfCrabs.size() / 2]) / 2;
        }
        
        for (const int& crabpos: positionsOfCrabs)
        {
            fuelNecessary += abs(crabpos - median);
        }
    }
    else
    {
        int mean = (std::accumulate(positionsOfCrabs.begin(), positionsOfCrabs.end(), 0)) / positionsOfCrabs.size();
        
        for (const int& crabpos: positionsOfCrabs)
        {
            fuelNecessary += (abs(crabpos - mean) * (abs(crabpos - mean) + 1)) / 2;
        }
    }
    return fuelNecessary;
}

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