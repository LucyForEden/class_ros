#include <string>
#include <array>
#include "degree.h"

class Student {
private:
    std::string studentID;
    std::string firstName;
    std::string lastName;
    std::string emailAddress;
    int age;
    std::array<int, 3> daysInCourse;
    DegreeProgram degreeProgram;

public:
    // Constructors
    Student(std::string id, std::string first, std::string last, std::string email, int age, int days1, int days2, int days3, DegreeProgram degree);
    
    // Accessors
    std::string getStudentID() const;
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getEmailAddress() const;
    int getAge() const;
    std::array<int, 3> getDaysInCourse() const;
    DegreeProgram getDegreeProgram() const;
    
    // Mutators
    void setStudentID(std::string id);
    void setFirstName(std::string first);
    void setLastName(std::string last);
    void setEmailAddress(std::string email);
    void setAge(int age);
    void setDaysInCourse(int days1, int days2, int days3);
    void setDegreeProgram(DegreeProgram degree);
    
    // Other methods
    void print() const;
};
