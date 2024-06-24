
#include <iostream>
#include <sstream>
#include <vector>
#include "roster.h"

// Function to convert string to DegreeProgram enum
DegreeProgram parseDegreeProgram(const std::string& degree) {
    if (degree == "SECURITY") return SECURITY;
    if (degree == "NETWORK") return NETWORK;
    if (degree == "SOFTWARE") return SOFTWARE;
    return SOFTWARE; // Default case if none match
}

int main() {
    std::cout << "Course Title: C++ Programming\n";
    std::cout << "Programming Language Used: C++\n";
    std::cout << "Student ID: 3824428488\n";
    std::cout << "Name: Lucy Thall\n\n";

    Roster classRoster;
    const std::string studentData[] = {
        "A1,John,Smith,John1989@gmail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Lucy,Thall,lucythall@gmail.com,36,30,35,40,SOFTWARE"
    };

    for (const auto& entry : studentData) {
        std::istringstream iss(entry);
        std::string part;
        std::vector<std::string> parts;
        while (getline(iss, part, ',')) {
            parts.push_back(part);
        }
        classRoster.add(parts[0], parts[1], parts[2], parts[3], std::stoi(parts[4]),
                        std::stoi(parts[5]), std::stoi(parts[6]), std::stoi(parts[7]),
                        parseDegreeProgram(parts[8]));
    }

    classRoster.printAll();
    std::cout << "\n";
    classRoster.printInvalidEmails();
    std::cout << "\n";

    for (int i = 0; i < 5; ++i) {
        if (classRoster.getClassRosterArray()[i] != nullptr) {
            classRoster.printAverageDaysInCourse(classRoster.getClassRosterArray()[i]->getStudentID());
        }
    }
    std::cout << "\n";

    classRoster.printByDegreeProgram(SOFTWARE);
    std::cout << "\n";
    classRoster.remove("A3");
    classRoster.printAll();
    classRoster.remove("A3");

    return 0;
}

