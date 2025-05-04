#ifndef SLL_H
#define SLL_H

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class SLL {
private:
    Node* head;
    Node* gethead() const { return head; }
public:
    SLL() : head(nullptr) {}
    
    void insertasc(int val) {
        Node* newNode = new Node(val);
        if (!head || head->data >= val) {
            newNode->next = head;
            head = newNode;
            return;
        }
        Node* current = head;
        while (current->next && current->next->data < val) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    
    SLL merge(const SLL& l1, const SLL& l2) {
        SLL mergedL;
        Node* ptr1 = l1.gethead();
        Node* ptr2 = l2.gethead();
        while (ptr1 || ptr2) {
            if (!ptr2 || (ptr1 && ptr1->data <= ptr2->data)) {
                mergedL.insertasc(ptr1->data);
                ptr1 = ptr1->next;
            } else {
                mergedL.insertasc(ptr2->data);
                ptr2 = ptr2->next;
            }
        }
        return mergedL;
    }
    
    void disp() const {
        Node* temp = head;
        while (temp) {
            cout << temp->data << "  ";
            temp = temp->next;
        }
        cout<<"\n";
    }
    
    ~SLL() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

#endif
