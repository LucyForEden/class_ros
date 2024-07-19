#include <string>
#include "student.h"

class Roster {
private:
    Student* classRosterArray[5]; // assuming there are 5 students

public:
    Roster(); // Constructor
    ~Roster(); // Destructor

    Student** getClassRosterArray(); 
    void add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int days1, int days2, int days3, DegreeProgram degree);
    void remove(std::string studentID);
    void printAll() const;
    void printAverageDaysInCourse(std::string studentID) const;
    void printInvalidEmails() const;
    void printByDegreeProgram(DegreeProgram degreeProgram) const;

};
