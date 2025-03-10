#ifndef STUDENT_H
#define STUDENT_H

#include <string>

namespace StudentNamespace {

    // Define the Student class
    class Student {
    private:
        // Private member variables
        int rollNumber;
        std::string name;
        int age;
        char gender;
        bool enrolled;
        double grades[5]; // Assuming there are 5 subjects

    public:
        // Constructors
        Student(); // Default constructor
        Student(int roll, std::string n, int a, char g, bool e, double *gradesArray);

        // Setters
        void setRollNumber(int roll);
        void setName(std::string n);
        void setAge(int a);
        void setGender(char g);
        void setEnrollmentStatus(bool e);
        void setGrades(double *gradesArray);

        // Getters
        int getRollNumber() const;
        std::string getName() const;
        int getAge() const;
        char getGender() const;
        bool isEnrolled() const;
        double *getGrades();

        // Other member functions
        double calculateAverageGrade() const;
        void printStudentInfo() const;
    };

} // End of namespace

#endif // STUDENT_H
