#include "Student.h"
#include <iostream>

namespace StudentNamespace {

    // Default constructor
    Student::Student() {
        rollNumber = 0;
        name = "";
        age = 0;
        gender = ' ';
        enrolled = false;
        for (int i = 0; i < 5; ++i)
            grades[i] = 0.0;
    }

    // Parameterized constructor
    Student::Student(int roll, std::string n, int a, char g, bool e, double *gradesArray) {
        rollNumber = roll;
        name = n;
        age = a;
        gender = g;
        enrolled = e;
        for (int i = 0; i < 5; ++i)
            grades[i] = gradesArray[i];
    }

    // Setters
    void Student::setRollNumber(int roll) {
        rollNumber = roll;
    }

    void Student::setName(std::string n) {
        name = n;
    }

    void Student::setAge(int a) {
        age = a;
    }

    void Student::setGender(char g) {
        gender = g;
    }

    void Student::setEnrollmentStatus(bool e) {
        enrolled = e;
    }

    void Student::setGrades(double *gradesArray) {
        for (int i = 0; i < 5; ++i)
            grades[i] = gradesArray[i];
    }

    // Getters
    int Student::getRollNumber() const {
        return rollNumber;
    }

    std::string Student::getName() const {
        return name;
    }

    int Student::getAge() const {
        return age;
    }

    char Student::getGender() const {
        return gender;
    }

    bool Student::isEnrolled() const {
        return enrolled;
    }

    double *Student::getGrades() {
        return grades;
    }

    // Calculate average grade
    double Student::calculateAverageGrade() const {
        double total = 0;
        for (int i = 0; i < 5; ++i)
            total += grades[i];
        return total / 5.0;
    }

    // Print student information
    void Student::printStudentInfo() const {
        std::cout << "Roll Number: " << rollNumber << std::endl;
        std::cout << "Name: " << name << std::endl;
        std::cout << "Age: " << age << std::endl;
        std::cout << "Gender: " << gender << std::endl;
        std::cout << "Enrolled: " << (enrolled ? "Yes" : "No") << std::endl;
        std::cout << "Grades: ";
        for (int i = 0; i < 5; ++i)
            std::cout << grades[i] << " ";
        std::cout << std::endl;
    }

} // End of namespace
