#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    int studentID;
    float avg;
    Student* next;
};

void insert(Student*& head, string name, int id, float avg) {
    Student* newNode = new Student;
    newNode->name = name;
    newNode->studentID = id;
    newNode->avg = avg;
    newNode->next = head;
    head = newNode;
}

void display(Student* head) {
    Student* temp = head;
    while (temp != NULL) {
        cout << "Name: " << temp->name
             << " | ID: " << temp->studentID
             << " | Avg: " << temp->avg << endl;
        temp = temp->next;
    }
}

Student* search(Student* head, int id) {
    while (head != NULL) {
        if (head->studentID == id)
            return head;
        head = head->next;
    }
    return NULL;
}

void deleteStudent(Student*& head, int id) {
    Student* temp = head;
    Student* prev = NULL;

    if (temp != NULL && temp->studentID == id) {
        head = temp->next;
        delete temp;
        return;
    }

    while (temp != NULL && temp->studentID != id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    prev->next = temp->next;
    delete temp;
}

int main() {
    Student* head = NULL;

    insert(head, "Ali", 1001, 17.8);
    insert(head, "Sara", 1002, 18.5);
    insert(head, "Reza", 1003, 16.9);

    cout << "List of students:\n";
    display(head);

    cout << "\nAfter deleting student with ID 1002:\n";
    deleteStudent(head, 1002);
    display(head);

    return 0;
}