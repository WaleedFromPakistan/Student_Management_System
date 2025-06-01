#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;

class Student {
public:
    int id;
    string name;
    int age;
    string department;
    float gpa;
};

class StudentManager {
private:
    vector<Student> students;

public:
    void addStudent() {
        Student s;
        cout << "Enter Student ID: ";
        cin >> s.id;
        for (Student student : students) {
            if (student.id == s.id) {
                cout << "Student with this ID already exists.\n";
                return;
            }
        }

        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, s.name);
        if (s.name.length() < 2) {
            cout << "Invalid name! Name must be at least 2 characters.\n";
            return;
        }

        cout << "Enter Age: ";
        cin >> s.age;
        if (s.age < 15 || s.age > 100) {
            cout << "Invalid age! Age must be between 15 and 100.\n";
            return;
        }

        cout << "Enter Department: ";
        cin >> s.department;

        cout << "Enter GPA: ";
        cin >> s.gpa;

        students.push_back(s);
        cout << "Student added successfully.\n";
    }

    void updateStudent() {
        int id;
        cout << "Enter Student ID to update: ";
        cin >> id;

        for (int i = 0; i < students.size(); i++) {
            if (students[i].id == id) {
                cout << "Enter new name: ";
                cin.ignore();
                getline(cin, students[i].name);
                if (students[i].name.length() < 2) {
                    cout << "Invalid name! Must be at least 2 characters.\n";
                    return;
                }

                cout << "Enter new age: ";
                cin >> students[i].age;
                if (students[i].age < 15 || students[i].age > 100) {
                    cout << "Invalid age! Must be between 15 and 100.\n";
                    return;
                }

                cout << "Enter new department: ";
                cin >> students[i].department;

                cout << "Enter new GPA: ";
                cin >> students[i].gpa;

                cout << "Student updated successfully.\n";
                return;
            }
        }

        cout << "Student not found.\n";
    }

    void deleteStudent() {
        int id;
        cout << "Enter Student ID to delete: ";
        cin >> id;

        for (int i = 0; i < students.size(); i++) {
            if (students[i].id == id) {
                students.erase(students.begin() + i);
                cout << "Student deleted successfully.\n";
                return;
            }
        }

        cout << "Student not found.\n";
    }

    void displayAllStudents() {
        for (Student s : students) {
            cout << "ID: " << s.id << ", Name: " << s.name << ", Age: " << s.age
                 << ", Department: " << s.department << ", GPA: " << s.gpa << "\n";
        }
    }

    void showStatistics() {
        int total = students.size();
        if (total == 0) {
            cout << "No student records available.\n";
            return;
        }

        float totalGPA = 0;
        float maxGPA = students[0].gpa;
        float minGPA = students[0].gpa;

        for (Student s : students) {
            totalGPA += s.gpa;
            if (s.gpa > maxGPA) maxGPA = s.gpa;
            if (s.gpa < minGPA) minGPA = s.gpa;
        }

        cout << "Total Students: " << total << "\n";
        cout << "Average GPA: " << (totalGPA / total) << "\n";
        cout << "Highest GPA: " << maxGPA << "\n";
        cout << "Lowest GPA: " << minGPA << "\n";
    }

    // ---------- Dead Code (Not Used) ----------
    string toUpperCase(string str) {
        for (int i = 0; i < str.length(); i++) {
            str[i] = toupper(str[i]);
        }
        return str;
    }

    int random(int min, int max) {
        return min + (rand() % (max - min + 1));
    }
};

int main() {
    StudentManager manager;
    int choice;

    do {
        cout << "\n1. Add Student\n2. Update Student\n3. Delete Student\n4. Display All\n5. Show Stats\n6. Exit\nChoice: ";
        cin >> choice;

        switch (choice) {
        case 1: manager.addStudent(); break;
        case 2: manager.updateStudent(); break;
        case 3: manager.deleteStudent(); break;
        case 4: manager.displayAllStudents(); break;
        case 5: manager.showStatistics(); break;
        case 6: cout << "Exiting...\n"; break;
        default: cout << "Invalid choice.\n";
        }
    } while (choice != 6);

    return 0;
}
