#include <iostream>
#include <iomanip>
#include <fstream>
#include "Student.h"

using namespace std;
using namespace StudentNamespace;

// Function prototypes
void printMenu();
void addStudent(Student students[], int &count);
void updateStudentInfo(Student students[], int count);
void calculateAverage(Student students[], int count);
void printEnrolledStudents(Student students[], int count);
void searchStudentByName(Student students[], int count);
void searchStudentByRollNumber(Student students[], int count);
void saveToFile(Student students[], int count);
void loadFromFile(Student students[], int &count);

// Main function
int main() {
    const int MAX_STUDENTS = 100;
    Student students[MAX_STUDENTS];
    int studentCount = 0;
    int choice;
    
    do { // do-while loop to keep the program running until the user chooses to exit
        printMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent(students, studentCount);
                break;
            case 2:
                updateStudentInfo(students, studentCount);
                break;
            case 3:
                calculateAverage(students, studentCount);
                break;
            case 4:
                printEnrolledStudents(students, studentCount);
                break;
            case 5:
                searchStudentByName(students, studentCount);
                break;
            case 6:
                searchStudentByRollNumber(students, studentCount);
                break;
            case 7:
                saveToFile(students, studentCount);
                break;
            case 8:
                loadFromFile(students, studentCount);
                break;
            case 9:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 9);

    return 0;
}
// Function to print the menu
void printMenu() {
    cout << "\n===== Student Management System =====" << endl;
    cout << "1. Add a student" << endl;
    cout << "2. Update student information" << endl;
    cout << "3. Calculate average grades" << endl;
    cout << "4. Print enrolled students" << endl;
    cout << "5. Search student by name" << endl;
    cout << "6. Search student by roll number" << endl;
    cout << "7. Save student records to file" << endl;
    cout << "8. Load student records from file" << endl;
    cout << "9. Exit" << endl;
}
// Function to add a student
void addStudent(Student students[], int &count) {
    if (count < 100) { // Check if there is space in the array
        cout << "Enter student details:" << endl;
        int roll;
        string name;
        int age;
        char gender;
        bool enrolled;
        double grades[5];

        cout << "Roll number: ";
        cin >> roll;
        cout << "Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Age: ";
        cin >> age;
        cout << "Gender (M/F): ";
        cin >> gender;
        cout << "Enrolled (1 for Yes, 0 for No): ";
        cin >> enrolled;
        cout << "Enter 5 grades: ";
        for (int i = 0; i < 5; ++i)
            cin >> grades[i];

        students[count++] = Student(roll, name, age, gender, enrolled, grades);
        cout << "Student added successfully." << endl;
    } else {
        cout << "Maximum student limit reached." << endl;
    }
}
// Function to update student information
void updateStudentInfo(Student students[], int count) {
    int roll;
    cout << "Enter roll number of the student to update: ";
    cin >> roll;

    for (int i = 0; i < count; ++i) {
        if (students[i].getRollNumber() == roll) {
            cout << "Enter new details for the student:" << endl;
            string name;
            int age;
            char gender;
            bool enrolled;
            double grades[5];

            cout << "Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Age: ";
            cin >> age;
            cout << "Gender (M/F): ";
            cin >> gender;
            cout << "Enrolled (1 for Yes, 0 for No): ";
            cin >> enrolled;
            cout << "Enter 5 grades: ";
            for (int j = 0; j < 5; ++j)
                cin >> grades[j];

            students[i].setName(name);
            students[i].setAge(age);
            students[i].setGender(gender);
            students[i].setEnrollmentStatus(enrolled);
            students[i].setGrades(grades);

            cout << "Student information updated successfully." << endl;
            return;
        }
    }

    cout << "Student not found." << endl;
}
// Function to calculate average grades
void calculateAverage(Student students[], int count) {
    int roll;
    cout << "Enter roll number of the student to calculate average grades: ";
    cin >> roll;

    for (int i = 0; i < count; ++i) {
        if (students[i].getRollNumber() == roll) {
            cout << "Average grade: " << fixed << setprecision(2) << students[i].calculateAverageGrade() << endl;
            return;
        }
    }

    cout << "Student not found." << endl;
}
// Function to print enrolled students
void printEnrolledStudents(Student students[], int count) {
    cout << "Enrolled students:" << endl;
    for (int i = 0; i < count; ++i) {
        if (students[i].isEnrolled()) {
            students[i].printStudentInfo();
            cout << endl;
        }
    }
}
// Function to search student by name
void searchStudentByName(Student students[], int count) {
    string name;
    cout << "Enter name of the student to search: ";
    cin.ignore();
    getline(cin, name);

    bool found = false;
    for (int i = 0; i < count; ++i) {
        if (students[i].getName() == name) {
            students[i].printStudentInfo();
            found = true;
        }
    }

    if (!found)
        cout << "Student not found." << endl;
}
// Function to search student by roll number
void searchStudentByRollNumber(Student students[], int count) {
    int roll;
    cout << "Enter roll number of the student to search: ";
    cin >> roll;

    for (int i = 0; i < count; ++i) {
        if (students[i].getRollNumber() == roll) {
            students[i].printStudentInfo();
            return;
        }
    }

    cout << "Student not found." << endl;
}
// Function to save student records to file
void saveToFile(Student students[], int count) {
    ofstream file("student_records.txt");
    if (file.is_open()) {
        for (int i = 0; i < count; ++i) {
            file << students[i].getRollNumber() << ","
                 << students[i].getName() << ","
                 << students[i].getAge() << ","
                 << students[i].getGender() << ","
                 << (students[i].isEnrolled() ? "1" : "0") << ",";
            double *grades = students[i].getGrades();
            for (int j = 0; j < 5; ++j)
                file << grades[j] << (j == 4 ? "\n" : ",");
        }
        file.close();
        cout << "Student records saved to file." << endl;
    } else {
        cout << "Unable to open file." << endl;
    }
}
// Function to load student records from file
void loadFromFile(Student students[], int &count) {
    ifstream file("student_records.txt");
    if (file.is_open()) {
        count = 0; // Reset count

        while (!file.eof()) {
            int roll;
            string name;
            int age;
            char gender;
            bool enrolled;
            double grades[5];

            file >> roll;
            if (file.eof()) // To handle extra empty line
                break;
            file.ignore(); // Ignore comma
            getline(file, name, ',');
            file >> age;
            file.ignore();
            file >> gender;
            file.ignore();
            int en;
            file >> en;
            enrolled = (en == 1);
            file.ignore();
            for (int i = 0; i < 5; ++i) {
                file >> grades[i];
                if (i < 4)
                    file.ignore();
            }

            students[count++] = Student(roll, name, age, gender, enrolled, grades);
        }
        file.close();
        cout << "Student records loaded from file." << endl;
    } else {
        cout << "Unable to open file." << endl;
    }
}
