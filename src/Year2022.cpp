#include "Year2022.hpp"

unsigned int Year2022::getResult_1(const bool& isPartOne)
{
    // Instantiation of a fstream object which is a file.
    std::fstream readingFile;

    // Choose an input folder name and concatenate it to the name of the file.
    const std::string inputFileToRead = getNameOfFile(1);

    // Opening the file in reading mode.
    readingFile.open(inputFileToRead, std::ios::in);

    if (!readingFile.is_open())
    {
        displayErrorOpeningFile(readingFile, inputFileToRead);
        return -1;
    }

    // Instantiation of a string that will represent the line in the document.
    std::string lineFromInputText;

    // Declaration of the variables for this exercise
    // Pair for the part one.
    std::pair<int, int> maxAndCurrentValues = std::make_pair(0, 0);

    // Priority queue and current value for the part two.
    std::priority_queue<unsigned int, std::vector<unsigned int>, std::greater<unsigned int>> queueOfTopCalories;
    unsigned int currentValue = 0;

    // Retrieve lines into lineFromInputText
    if (isPartOne)
    {
        while(getline(readingFile, lineFromInputText))
        {
            getMaxCalories_1_1(lineFromInputText, maxAndCurrentValues);
        }

        return std::max(maxAndCurrentValues.first, maxAndCurrentValues.second);
    }
    else
    {
        while(getline(readingFile, lineFromInputText))
        {
            getMaxCalories_1_2(lineFromInputText, queueOfTopCalories, currentValue);
        }
        
        unsigned int returnValue = 0;

        if ((queueOfTopCalories.size() < 3))
        {
            returnValue += currentValue;
        }
        else if (queueOfTopCalories.top() < currentValue)
        {
            returnValue += currentValue;
            queueOfTopCalories.pop();
        }

        while (! queueOfTopCalories.empty())
        {
            returnValue += queueOfTopCalories.top();
            queueOfTopCalories.pop();
        }
        return returnValue;
    }
}

void Year2022::getMaxCalories_1_1(const std::string& line, std::pair<int, int>& maxAndCurrentValues)
{
    if ("" == line)
    {
        maxAndCurrentValues.first = std::max(maxAndCurrentValues.first, maxAndCurrentValues.second);
        maxAndCurrentValues.second = 0;
    }
    else
    {
        maxAndCurrentValues.second += stoi(line);
    }
}

void Year2022::getMaxCalories_1_2(const std::string& line, priorityQueue_1_2& values, unsigned int& currentValue)
{
    if ("" == line)
    {
        if (3 == values.size())
        {
            if (values.top() < currentValue)
            {
                values.pop();
                values.push(currentValue);
            }
        }
        else
        {
            values.push(currentValue);
        }
        currentValue = 0;
    }
    else
    {
        currentValue += std::stoi(line);
    }
}

unsigned int Year2022::getResult_2(const bool& isPartOne)
{
    // Instantiation of a fstream object which is a file.
    std::fstream readingFile;

    // Get the name of the file to read
    const std::string inputFileToRead = getNameOfFile(2);

    // Opening the file in reading mode.
    readingFile.open(inputFileToRead, std::ios::in);

    if (!readingFile.is_open())
    {
        displayErrorOpeningFile(readingFile, inputFileToRead);
        return -1;
    }

    // Instantiation of a string that will represent the line in the document.
    std::string lineFromInputText;

    // Declaration of the variables for this exercise
    unsigned int myScore = 0;

    if (isPartOne)
    {
        while(getline(readingFile, lineFromInputText))
        {
            myScore += getScoreOfLine_2_1(lineFromInputText);
        }
    }
    else
    {
        while(getline(readingFile, lineFromInputText))
        {
            myScore += getScoreOfLine_2_2(lineFromInputText);
        }
    }

    // Logic of the end of the exercise
    return myScore;
}

unsigned int Year2022::getScoreOfLine_2_1(const std::string& line)
{
    unsigned int myScore = 0;

    // You play rock
    if ('X' == line[2])
    {
        myScore += 1;

        // Opponent plays rock
        if ('A' == line[0])
        {
            myScore += 3;
        }
        // Opponent plays scissors
        else if ('C' == line[0])
        {
            myScore += 6;
        }
    }
    // You play paper
    else if ('Y' == line[2])
    {
        myScore += 2;
        
        // Opponent plays paper
        if ('B' == line[0])
        {
            myScore += 3;
        }
        // Opponent plays rock
        else if ('A' == line[0])
        {
            myScore += 6;
        }
    }
    // You play Scissors
    else if ('Z' == line[2])
    {
        myScore += 3;

        // Opponent plays Scissors
        if ('C' == line[0])
        {
            myScore += 3;
        }
        // Opponent plays paper
        else if ('B' == line[0])
        {
            myScore += 6;
        }
    }

    return myScore;
}

unsigned int Year2022::getScoreOfLine_2_2(const std::string& line)
{
    unsigned int myScore = 0;

    // Opponents play rock
    if ('A' == line[0])
    {
        // You loose = play scissors
        if ('X' == line[2])
        {
            myScore += 3;
        }
        // You draw = play rock
        else if ('Y' == line[2])
        {
            myScore += 1;
            myScore += 3;
        }
        // You win = play paper
        else if ('Z' == line[2])
        {
            myScore += 2;
            myScore += 6;
        }
    }
    // Opponents play paper
    else if ('B' == line[0])
    {
        // You loose = play rock
        if ('X' == line[2])
        {
            myScore += 1;
        }
        // You draw = play paper
        else if ('Y' == line[2])
        {
            myScore += 2;
            myScore += 3;
        }
        // You win = play scissors
        else if ('Z' == line[2])
        {
            myScore += 3;
            myScore += 6;
        }
    }
    // Opponents play Scissors
    else if ('C' == line[0])
    {
        // You loose = play paper
        if ('X' == line[2])
        {
            myScore += 2;
        }
        // You draw = play scissors
        else if ('Y' == line[2])
        {
            myScore += 3;
            myScore += 3;
        }
        // You win = play rock
        else if ('Z' == line[2])
        {
            myScore += 1;
            myScore += 6;
        }
    }

    return myScore;
}

unsigned int Year2022::getResult_3(const bool& isPartOne)
{
    // Instantiation of a fstream object which is a file.
    std::fstream readingFile;

    // Get the name of the file to read
    const std::string inputFileToRead = getNameOfFile(3);

    // Opening the file in reading mode.
    readingFile.open(inputFileToRead, std::ios::in);

    if (!readingFile.is_open())
    {
        displayErrorOpeningFile(readingFile, inputFileToRead);
        return -1;
    }

    // Instantiation of a string that will represent the line in the document.
    std::string lineFromInputText;

    // Declaration of the variables for this exercise
    unsigned int total = 0;

    std::unordered_map<char, unsigned int> priority;

    // lowercase values
    for (char c = 'a'; 'z' >= c; ++c)
    {
        priority[c] = c - 'a' + 1;
    }

    // uppercase values
    for (char c = 'A'; 'Z' >= c; ++c)
    {
        priority[c] = c - 'A' + 27;
    }


    if (isPartOne)
    {
        while(getline(readingFile, lineFromInputText))
        {
            total += getValueOfBackPack_3_1(lineFromInputText, priority);
        }
    }
    else
    {
        while(getline(readingFile, lineFromInputText))
        {
            total += getValueOfBackPack_3_2(lineFromInputText, priority);
        }
    }

    // Logic of the end of the exercise
    return total;
}

unsigned int Year2022::getValueOfBackPack_3_1(const std::string& line, const std::unordered_map<char, unsigned int>& priority)
{
    std::unordered_set<char> lettersFirstRucksack;

    for (size_t index = 0; (line.size() / 2) > index; ++index)
    {
        lettersFirstRucksack.insert(line[index]);
    }

    for (size_t index = (line.size() / 2); line.size()  > index; ++index)
    {
        if (lettersFirstRucksack.contains(line[index]))
        {
            return priority.at(line[index]);
        }
    }

    return 0;
}

unsigned int Year2022::getValueOfBackPack_3_2(const std::string& line, const std::unordered_map<char, unsigned int>& priority)
{
    static int index = 0;
    static std::unordered_set<char> lettersInGroup;

    std::unordered_set<char> currentLetters;

    for (const char& letter: line)
    {
        currentLetters.insert(letter);
    }

    if (0 == index++)
    {
        lettersInGroup = currentLetters;
    }
    else
    {
        std::unordered_set<char> lettersToDelete;

        for (const char& letter: lettersInGroup)
        {
            if (! currentLetters.contains(letter))
            {
                lettersToDelete.insert(letter);
            }
        }

        for (const char& letter: lettersToDelete)
        {
            lettersInGroup.erase(letter);
        }
    }
    
    if (3 == index)
    {
        index = 0;

        for (const char& letter: lettersInGroup)
        {
            return priority.at(letter);
        }
    }

    return 0;
}

unsigned int Year2022::getResult_4(const bool& isPartOne)
{
    // Instantiation of a fstream object which is a file.
    std::fstream readingFile;

    // Get the name of the file to read
    const std::string inputFileToRead = getNameOfFile(4);

    // Opening the file in reading mode.
    readingFile.open(inputFileToRead, std::ios::in);

    if (!readingFile.is_open())
    {
        displayErrorOpeningFile(readingFile, inputFileToRead);
        return -1;
    }

    // Instantiation of a string that will represent the line in the document.
    std::string lineFromInputText;

    // Declaration of the variables for this exercise
    unsigned int numberOfOverlapping = 0;

    // Retrieve lines into lineFromInputText
    while(getline(readingFile, lineFromInputText))
    {
        int start1 = 0, start2 = 0, end1 = 0, end2 = 0 ;

        size_t index = 0;
        while ('-' != lineFromInputText[index])
        {
            start1 *= 10;
            start1 += lineFromInputText[index] - '0';
            ++ index;
        }
        ++index;
        while (',' != lineFromInputText[index])
        {
            end1 *= 10;
            end1 += lineFromInputText[index] - '0';
            ++ index;
        }
        ++index;
        while ('-' != lineFromInputText[index])
        {
            start2 *= 10;
            start2 += lineFromInputText[index] - '0';
            ++ index;
        }
        ++index;
        while (lineFromInputText.size() != index)
        {
            end2 *= 10;
            end2 += lineFromInputText[index] - '0';
            ++ index;
        }

        if (isPartOne)
        {
            numberOfOverlapping += getOverlappingTime_4_1(start1, start2, end1, end2);
        }
        else
        {
            numberOfOverlapping += getOverlappingTime_4_2(start1, start2, end1, end2);
        }
    }

    // Logic of the end of the exercise
    return numberOfOverlapping;
}

unsigned int Year2022::getOverlappingTime_4_1(const int& start1, const int& start2, const int& end1, const int& end2)
{
    return ((start1 <= start2 && end1 >= end2) || (start1 >= start2 && end1 <= end2)) ? 1 : 0;
}

unsigned int Year2022::getOverlappingTime_4_2(const int& start1, const int& start2, const int& end1, const int& end2)
{
    return ((start1 <= end2 && end1 >= start2) || (start1 >= end2 && end1 <= start2)) ? 1 : 0;
}

/// @brief Display to the user an error if an error occured when the file was opened.
/// @param streamError Stream where the error occured.
/// @param nameOfFile Name of the file that has not been opened.
void Year2022::displayErrorOpeningFile(const std::fstream& streamError, const std::string& nameOfFile)
{
    std::cerr << "Error opening file: " << nameOfFile << std::endl;
    std::cerr << "Stream state: " << streamError.rdstate() << std::endl;
}

/// @brief Get the name of the file, according to the number of the exercise.
/// @param numberOfExercise Number of the exercise (day of the challenge in fact)
/// @return Name of the file to open to get the input of the challenge.
std::string Year2022::getNameOfFile(const int& numberOfExercise)
{
    // Choose an input folder name and concatenate it to the name of the file.
    const std::string inputFolderName = "src/textFiles/";
    const std::string inputFileName = std::to_string(2022) + "_" + std::to_string(numberOfExercise) + ".txt";
    const std::string inputFileToRead = inputFolderName + inputFileName;

    return inputFileToRead;
}