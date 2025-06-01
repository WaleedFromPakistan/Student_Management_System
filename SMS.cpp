#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class Student {
public:
    int id;
    string name;
    int age;
    string department;
    float gpa;

    void inputStudent() {
        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Age: ";
        cin >> age;
        cout << "Enter Department: ";
        cin >> department;
        cout << "Enter GPA: ";
        cin >> gpa;
    }

    void displayStudent() {
        cout << "ID: " << id << ", Name: " << name << ", Age: " << age
             << ", Dept: " << department << ", GPA: " << gpa << endl;
    }
};

class StudentManager {
    vector<Student> students;

public:
    void addStudent() {
        Student s;
        cout << "Adding new student...\n";
        cout << "Enter Student ID: ";
        cin >> s.id;

        for (Student st : students) {
            if (st.id == s.id) {
                cout << "Student already exists.\n";
                return;
            }
        }

        cout << "Enter Student Name: ";
        cin.ignore();
        getline(cin, s.name);
        if (s.name.length() < 2) {
            cout << "Invalid name!\n";
            return;
        }

        cout << "Enter Age: ";
        cin >> s.age;
        if (s.age < 15 || s.age > 100) {
            cout << "Invalid age!\n";
            return;
        }

        cout << "Enter Department: ";
        cin >> s.department;

        cout << "Enter GPA: ";
        cin >> s.gpa;

        students.push_back(s);
        cout << "Student added successfully.\n";
    }

    void showAllStudents() {
        for (Student s : students) {
            s.displayStudent();
        }
    }

    void updateStudent() {
        int id;
        cout << "Enter ID to update: ";
        cin >> id;
        for (int i = 0; i < students.size(); i++) {
            if (students[i].id == id) {
                cout << "Enter new name: ";
                cin.ignore();
                getline(cin, students[i].name);

                cout << "Enter new age: ";
                cin >> students[i].age;

                cout << "Enter new department: ";
                cin >> students[i].department;

                cout << "Enter new GPA: ";
                cin >> students[i].gpa;

                cout << "Student updated.\n";
                return;
            }
        }
        cout << "Student not found.\n";
    }

    void deleteStudent() {
        int id;
        cout << "Enter ID to delete: ";
        cin >> id;
        for (int i = 0; i < students.size(); i++) {
            if (students[i].id == id) {
                students.erase(students.begin() + i);
                cout << "Student deleted.\n";
                return;
            }
        }
        cout << "Student not found.\n";
    }

    void showStatistics() {
        if (students.empty()) {
            cout << "No students to analyze.\n";
            return;
        }

        int total = students.size();
        float sum = 0;
        float maxGPA = students[0].gpa, minGPA = students[0].gpa;

        for (Student s : students) {
            sum += s.gpa;
            if (s.gpa > maxGPA) maxGPA = s.gpa;
            if (s.gpa < minGPA) minGPA = s.gpa;
        }

        cout << "Total: " << total << ", Avg GPA: " << (sum / total)
             << ", Highest GPA: " << maxGPA << ", Lowest GPA: " << minGPA << endl;
    }

    // Dead code
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
        cout << "\n1. Add Student\n2. Show All\n3. Update\n4. Delete\n5. Stats\n6. Exit\nChoice: ";
        cin >> choice;
        switch (choice) {
        case 1: manager.addStudent(); break;
        case 2: manager.showAllStudents(); break;
        case 3: manager.updateStudent(); break;
        case 4: manager.deleteStudent(); break;
        case 5: manager.showStatistics(); break;
        case 6: cout << "Exiting...\n"; break;
        default: cout << "Invalid choice.\n";
        }
    } while (choice != 6);

    return 0;
}
