#include "student.h"
#include <iostream>

// Constructor
Student::Student(std::string id, std::string first, std::string last, std::string email, int age, int days1, int days2, int days3, DegreeProgram degree) {
    this->studentID = id;
    this->firstName = first;
    this->lastName = last;
    this->emailAddress = email;
    this->age = age;
    this->daysInCourse = {days1, days2, days3};
    this->degreeProgram = degree;
}

// Accessors
std::string Student::getStudentID() const {
    return studentID;
}

std::string Student::getFirstName() const {
    return firstName;
}

std::string Student::getLastName() const {
    return lastName;
}

std::string Student::getEmailAddress() const {
    return emailAddress;
}

int Student::getAge() const {
    return age;
}

std::array<int, 3> Student::getDaysInCourse() const {
    return daysInCourse;
}

DegreeProgram Student::getDegreeProgram() const {
    return degreeProgram;
}

// Mutators
void Student::setStudentID(std::string id) {
    this->studentID = id;
}

void Student::setFirstName(std::string first) {
    this->firstName = first;
}

void Student::setLastName(std::string last) {
    this->lastName = last;
}

void Student::setEmailAddress(std::string email) {
    this->emailAddress = email;
}

void Student::setAge(int age) {
    this->age = age;
}

void Student::setDaysInCourse(int days1, int days2, int days3) {
    this->daysInCourse = {days1, days2, days3};
}

void Student::setDegreeProgram(DegreeProgram degree) {
    this->degreeProgram = degree;
}

// Print method
void Student::print() const {
    std::cout << studentID << "\t";
    std::cout << "First Name: " << firstName << "\t";
    std::cout << "Last Name: " << lastName << "\t";
    std::cout << "Age: " << age << "\t";
    std::cout << "daysInCourse: {" << daysInCourse[0] << ", " << daysInCourse[1] << ", " << daysInCourse[2] << "}\t";
    std::cout << "Degree Program: " << degreeProgram << std::endl;
}
