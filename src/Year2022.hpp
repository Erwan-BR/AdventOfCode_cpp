#ifndef _Year2022_
#define _Year2022_

#include <limits.h>
#include <algorithm>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>

#include "UnavailableDateException.hpp"

typedef std::priority_queue<unsigned int, std::vector<unsigned int>, std::greater<unsigned int>> priorityQueue_1_2;

class Year2022
{
private:
    static std::string getNameOfFile(const int& numberOfExercise);
    static void displayErrorOpeningFile(const std::fstream& streamError, const std::string& nameOfFile);

    static void getMaxCalories_1_1(const std::string& line, std::pair<int, int>& maxAndCurrentValues);
    static void getMaxCalories_1_2(const std::string& line, priorityQueue_1_2& values, unsigned int& currentValue);

    static unsigned int getScoreOfLine_2_1(const std::string& line);
    static unsigned int getScoreOfLine_2_2(const std::string& line);

    static unsigned int getValueOfBackPack_3_1(const std::string& line, const std::unordered_map<char, unsigned int>& priority);
    static unsigned int getValueOfBackPack_3_2(const std::string& line, const std::unordered_map<char, unsigned int>& priority);

    static unsigned int getOverlappingTime_4_1(const int& start1, const int& start2, const int& end1, const int& end2);
    static unsigned int getOverlappingTime_4_2(const int& start1, const int& start2, const int& end1, const int& end2);
public:
    static unsigned int getResult_1(const bool& isPartOne);
    static unsigned int getResult_2(const bool& isPartOne);
    static unsigned int getResult_3(const bool& isPartOne);
    static unsigned int getResult_4(const bool& isPartOne);
};

#endif // _Year2022_