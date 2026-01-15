#include "studentRecord.h"
#include <string>

studentRecord::studentRecord()
{
    setGrade(0);
    setStudentID(-1);
    setName("");
}

studentRecord::studentRecord(int newGrade, int newID, std::string newName)
{
    setGrade(newGrade);
    setStudentID(newID);
    setName(newName);
}

int studentRecord::getGrade()
{
    return _grade;
}

void studentRecord::setGrade(int newGrade)
{
    if (isValidGrade(newGrade))
        _grade = newGrade;
}

std::string studentRecord::getName()
{
    return _name;
}

void studentRecord::setName(std::string name)
{
    _name = name;
}

void studentRecord::setStudentID(int newID)
{
    _studentID = newID;
}

int studentRecord::getStudentID()
{
    return _studentID;
}

bool studentRecord::isValidGrade(int grade)
{
    if((grade >= 0) && (grade <= 100)) return true;
    return false;
}

std::string studentRecord::letterGrade()
{
    if(!isValidGrade(_grade)) return "ERROR";
    const int NUMBER_CATEGORIES = 11;
    const std::string GRADE_LETTER[] = {"F","D", "D+", "C-", "C", "C+",
    "B-", "B", "B+", "A-", "A"};
    const int LOWEST_GRADE_SCORE[] = {0, 60, 67, 70, 73, 77, 80, 83,
    87, 90, 93};
    int category = 0;
    while(category < NUMBER_CATEGORIES && LOWEST_GRADE_SCORE[category] <= _grade)
    {
        category++;
    }
    return GRADE_LETTER[category - 1];
}
