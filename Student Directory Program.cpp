#include <iostream>
#include <string>

using namespace std;
//student class
struct Student {
    string firstName;
    string lastName;
    string courseCode;
    double grade;
    Student* next;
};
//linked list structure
class StudentDatabase {
private:
    Student* head;

public:
    StudentDatabase() : head(nullptr) {}

    void insertRecord(int position, string firstName, string lastName, string courseCode, double grade) {
        Student* newStudent = new Student{ firstName, lastName, courseCode, grade, nullptr };

        if (position == 0 || head == nullptr) {
            newStudent->next = head;
            head = newStudent;
        } else {
            Student* temp = head;
            int i = 0;
            while (temp->next != nullptr && i < position - 1) {
                temp = temp->next;
                i++;
            }
            newStudent->next = temp->next;
            temp->next = newStudent;
        }
    }
//delete student file
    void deleteRecord(int position) {
        if (head == nullptr) return;

        Student* temp = head;

        if (position == 0) {
            head = temp->next;
            delete temp;
            return;
        }

        for (int i = 0; temp != nullptr && i < position - 1; i++)
            temp = temp->next;
        if (temp == nullptr || temp->next == nullptr)
            return;

        Student* next = temp->next->next;
        delete temp->next;
        temp->next = next;
    }
//search function
    void searchDatabase(string lastName) {
        Student* temp = head;
        while (temp != nullptr) {
            if (temp->lastName == lastName) {
                cout << "Found: " << temp->firstName << " " << temp->lastName << ", " << temp->courseCode << ", " << temp->grade << endl;
            }
            temp = temp->next;
        }
    }
//range function
    void printRange(int start, int end) {
        Student* temp = head;
        int i = 0;
        while (temp != nullptr) {
            if (i >= start && i <= end) {
                cout << temp->firstName << " " << temp->lastName << ", " << temp->courseCode << ", " << temp->grade << endl;
            }
            temp = temp->next;
            i++;
        }
    }
//class average function
    void classAverage(string courseCode) {
        Student* temp = head;
        int count = 0;
        double total = 0.0;
        while (temp != nullptr) {
            if (temp->courseCode == courseCode) {
                total += temp->grade;
                count++;
            }
            temp = temp->next;
        }
        if (count == 0) {
            cout << "No students found for course: " << courseCode << endl;
        } else {
            cout << "Class average for " << courseCode << " is " << total / count << endl;
        }
    }
//menu
    void menu() {
        int choice;
        do {
            cout << "Student Database Menu:(enter a value to select)" << endl;
            cout << "1: insert a new record" << endl;
            cout << "2: delete a record (by student number)" << endl;
            cout << "3: search the database (by last name)" << endl;
            cout << "4: print a range in the database" << endl;
            cout << "5: find the class average for a course" << endl;
            cout << "9: exit" << endl;
            cin >> choice;
//menu choice inputs
            switch (choice) {
//student input 
                case 1: {
                    int position;
                    string firstName, lastName, courseCode;
                    double grade;
                    cout << "Enter Student Number: ";
                    cin >> position;
                    cout << "Enter first name: ";
                    cin >> firstName;
                    cout << "Enter last name: ";
                    cin >> lastName;
                    cout << "Enter course code: ";
                    cin >> courseCode;
                    cout << "Enter grade: ";
                    cin >> grade;
                    insertRecord(position, firstName, lastName, courseCode, grade);
                    break;
                }
//delete by student number
                case 2: {
                    int position;
                    cout << "Enter position to delete: ";
                    cin >> position;
                    deleteRecord(position);
                    break;
                }
//search all student data by last name
                case 3: {
                    string lastName;
                    cout << "Enter last name to search: ";
                    cin >> lastName;
                    searchDatabase(lastName);
                    break;
                }
//print range of students by student number
                case 4: {
                    int start, end;
                    cout << "Enter start range: ";
                    cin >> start;
                    cout << "Enter end range: ";
                    cin >> end;
                    printRange(start, end);
                    break;
                }
//class average by course code
                case 5: {
                    string courseCode;
                    cout << "Enter course code to find average: ";
                    cin >> courseCode;
                    classAverage(courseCode);
                    break;
                }
//exit
                case 9: {
                    cout << "Exiting..." << endl;
                    break;
                }
//invalid error
                default:
                    cout << "Invalid choice, try again." << endl;
            }
        } while (choice != 9);
    }
};
//driver code for database
int main() {
    StudentDatabase db;
    db.menu();
    return 0;
}