#include <iostream>
using namespace std;

const int MAX = 100;

struct Student {
    int roll;
    string name;
    float marks;
};

Student students[MAX];
int count = 0;

// Function to add student
void addStudent() {
    if (count >= MAX) {
        cout << "Database full!\n";
        return;
    }
    cout << "Enter Roll Number: ";
    cin >> students[count].roll;
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, students[count].name);
    cout << "Enter Marks: ";
    cin >> students[count].marks;
    count++;
    cout << "Student added successfully.\n";
}

// Function to display all students
void displayAll() {
    if (count == 0) {
        cout << "No records found.\n";
        return;
    }
    for (int i = 0; i < count; i++) {
        cout << "\nStudent " << i + 1 << ":\n";
        cout << "Roll: " << students[i].roll << "\n";
        cout << "Name: " << students[i].name << "\n";
        cout << "Marks: " << students[i].marks << "\n";
    }
}

// Function to search student by roll number
void searchStudent() {
    int roll;
    cout << "Enter roll number to search: ";
    cin >> roll;
    for (int i = 0; i < count; i++) {
        if (students[i].roll == roll) {
            cout << "Record found:\n";
            cout << "Name: " << students[i].name << "\n";
            cout << "Marks: " << students[i].marks << "\n";
            return;
        }
    }
    cout << "Student not found.\n";
}

// Function to delete student by roll number
void deleteStudent() {
    int roll;
    cout << "Enter roll number to delete: ";
    cin >> roll;
    for (int i = 0; i < count; i++) {
        if (students[i].roll == roll) {
            for (int j = i; j < count - 1; j++) {
                students[j] = students[j + 1];
            }
            count--;
            cout << "Student record deleted.\n";
            return;
        }
    }
    cout << "Student not found.\n";
}

// Main menu
int main() {
    int choice;
    do {
        cout << "\n--- Student Record Management ---\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search by Roll Number\n";
        cout << "4. Delete Student\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayAll(); break;
            case 3: searchStudent(); break;
            case 4: deleteStudent(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
