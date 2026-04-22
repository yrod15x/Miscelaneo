#ifndef STUDENTRECORD_H
#define STUDENTRECORD_H
#include <string>

class studentRecord
{
 public:
    studentRecord();
    studentRecord(int newGrade, int newID, std::string newName);
    int getGrade();
    void setGrade(int newGrade);
    int getStudentID();
    void setStudentID(int newID);
    std::string getName();
    void setName(std::string newName);
    std::string letterGrade();
 private:
    int _grade;
    int _studentID;
    std::string _name;
    bool isValidGrade(int grade);
};

#endif // STUDENTRECORD_H
