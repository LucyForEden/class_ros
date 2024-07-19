#include "roster.h"
#include <iostream>
#include <vector>


Student** Roster::getClassRosterArray() {
    return classRosterArray;
}
// Constructor
Roster::Roster() {
    for (int i = 0; i < 5; ++i) {
        this->classRosterArray[i] = nullptr;
    }
}

// Destructor
Roster::~Roster() {
    for (int i = 0; i < 5; ++i) {
        delete this->classRosterArray[i];
        this->classRosterArray[i] = nullptr;
    }
}

// Add method
void Roster::add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int days1, int days2, int days3, DegreeProgram degree) {
    int i = 0;
    for (; i < 5; ++i) {
        if (classRosterArray[i] == nullptr) {
            classRosterArray[i] = new Student(studentID, firstName, lastName, emailAddress, age, days1, days2, days3, degree);
            break;
        }
    }
    if (i == 5) {
        std::cout << "Roster full. Cannot add more students." << std::endl;
    }
}

// Remove method
void Roster::remove(std::string studentID) {
    bool found = false;
    for (int i = 0; i < 5; ++i) {
        if (classRosterArray[i] != nullptr && classRosterArray[i]->getStudentID() == studentID) {
            delete classRosterArray[i];
            classRosterArray[i] = nullptr;
            found = true;
            std::cout << "Student ID " << studentID << " removed from roster." << std::endl;
            break;
        }
    }
    if (!found) {
        std::cout << "Error: Student with ID " << studentID << " not found." << std::endl;
    }
}

// Print all method
void Roster::printAll() const {
    for (int i = 0; i < 5; ++i) {
        if (classRosterArray[i] != nullptr) {
            classRosterArray[i]->print();
        }
    }
}

// Print average days in course method
void Roster::printAverageDaysInCourse(std::string studentID) const {
    for (int i = 0; i < 5; ++i) {
        if (classRosterArray[i] != nullptr && classRosterArray[i]->getStudentID() == studentID) {
            auto days = classRosterArray[i]->getDaysInCourse();
            double average = (days[0] + days[1] + days[2]) / 3.0;
            std::cout << "Average days in course for student ID " << studentID << ": " << average << std::endl;
            return;
        }
    }
    std::cout << "Student ID " << studentID << " not found." << std::endl;
}

// Print invalid emails method
void Roster::printInvalidEmails() const {
    for (int i = 0; i < 5; ++i) {
        if (classRosterArray[i] != nullptr) {
            std::string email = classRosterArray[i]->getEmailAddress();
            if (email.find(' ') != std::string::npos || email.find('@') == std::string::npos || email.find('.') == std::string::npos) {
                std::cout << "Invalid email: " << email << std::endl;
            }
        }
    }
}

// Print by degree program method
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) const {
    for (int i = 0; i < 5; ++i) {
        if (classRosterArray[i] != nullptr && classRosterArray[i]->getDegreeProgram() == degreeProgram) {
            classRosterArray[i]->print();
        }
    }
}
