#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

class SLL {
private:
    Node* head;
public:
    SLL();
    ~SLL();
    void insertbeg(int value);
    void insertend(int value);
    void insertpos(int value, int pos);
    void delbeg();
    void delend();
    void delpos(int pos);
    void search(int value);
    void disp();
    void disprev();
    void revlink();
    void disprevhelp(Node* node);
};

int main() {
    SLL list;
    int choice, value, pos;
    do {
        cout << "1. Insert beginning\n";
        cout << "2. Insert end\n";
        cout << "3. Insert at position\n";
        cout << "4. Delete beginning\n";
        cout << "5. Delete end\n";
        cout << "6. Delete position\n";
        cout << "7. Search\n";
        cout << "8. Display\n";
        cout << "9. Display reverse\n";
        cout << "10. Reverse link\n";
        cout << "11. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            list.insertbeg(value);
            break;
        case 2:
            cout << "Enter value: ";
            cin >> value;
            list.insertend(value);
            break;
        case 3:
            cout << "Enter value and position: ";
            cin >> value >> pos;
            list.insertpos(value, pos);
            break;
        case 4:
            list.delbeg();
            break;
        case 5:
            list.delend();
            break;
        case 6:
            cout << "Enter position to delete: ";
            cin >> pos;
            list.delpos(pos);
            break;
        case 7:
            cout << "Enter value to search: ";
            cin >> value;
            list.search(value);
            break;
        case 8:
            list.disp();
            break;
        case 9:
            list.disprev();
            break;
        case 10:
            list.revlink();
            break;
        case 11:
            cout << "Exiting program\n";
            break;
        default:
            cout << "Invalid choice\n";
            break;
        }
    } while (choice != 11);
    return 0;
}

SLL::SLL() {
    head = nullptr;
}

SLL::~SLL() {
    Node* temp;
    while (head) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

void SLL::insertbeg(int value) {
    Node* newnode = new Node(value);
    newnode->next = head;
    head = newnode;
}

void SLL::insertend(int value) {
    Node* newnode = new Node(value);
    if (!head) {
        head = newnode;
        return;
    }
    Node* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newnode;
}

void SLL::insertpos(int value, int pos) {
    if (pos <= 0) {
        cout << "Invalid position\n";
        return;
    }
    if (pos == 1) {
        insertbeg(value);
        return;
    }
    Node* temp = head;
    Node* newnode = new Node(value);
    for (int i = 1; i < pos - 1 && temp; i++) {
        temp = temp->next;
    }
    if (!temp) {
        cout << "Invalid position\n";
        delete newnode;
        return;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}

void SLL::delbeg() {
    if (!head) {
        cout << "Empty list\n";
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
}

void SLL::delend() {
    if (!head) {
        cout << "Empty list\n";
        return;
    }
    if (!head->next) {
        delete head;
        head = nullptr;
        return;
    }
    Node* temp = head;
    while (temp->next->next) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
}

void SLL::delpos(int pos) {
    if (pos <= 0 || !head) {
        cout << "Invalid position or empty list\n";
        return;
    }
    if (pos == 1) {
        delbeg();
        return;
    }
    Node* temp = head;
    for (int i = 1; i < pos - 1 && temp; i++) {
        temp = temp->next;
    }
    if (!temp || !temp->next) {
        cout << "Invalid position\n";
        return;
    }
    Node* delnode = temp->next;
    temp->next = temp->next->next;
    delete delnode;
}

void SLL::search(int value) {
    Node* temp = head;
    int pos = 1;
    while (temp) {
        if (temp->data == value) {
            cout << "Value found at position " << pos << "\n";
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << "Value not found\n";
}

void SLL::disp() {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

void SLL::disprevhelp(Node* node) {
    if (!node) return;
    disprevhelp(node->next);
    cout << node->data << " ";
}

void SLL::disprev() {
    disprevhelp(head);
    cout << "\n";
}

void SLL::revlink() {
    Node* prev = nullptr, * curr = head, * next = nullptr;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}
