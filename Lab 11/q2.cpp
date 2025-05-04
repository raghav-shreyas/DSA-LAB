//Program to implement Hash ADT with Quadratic Probing with operations like insertion, deletion, and searching
#include <iostream>
using namespace std;

const int TABLE_SIZE = 10;
const int EMPTY = -1;
const int DELETED = -2;

class HashTable {
private:
    int table[TABLE_SIZE];

    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

public:
    HashTable() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            table[i] = EMPTY;
        }
    }
    void insert(int);
    void remove(int);
    void search(int);
    void display();
};

int main() {
    HashTable ht;
    int choice, key;

    do {
        cout << "\n--- Hash Table Menu (Quadratic Probing) ---\n";
        cout << "1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter key to insert: ";
                cin >> key;
                ht.insert(key);
                break;
            case 2:
                cout << "Enter key to delete: ";
                cin >> key;
                ht.remove(key);
                break;
            case 3:
                cout << "Enter key to search: ";
                cin >> key;
                ht.search(key);
                break;
            case 4:
                ht.display();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 5);

    return 0;
}

//Function to insert an element to the hash table
void HashTable::insert(int key) {
    int index = hashFunction(key);
    int i = 0;

    while (i < TABLE_SIZE) {
        int newIndex = (index + i + i*i) % TABLE_SIZE;
        if (table[newIndex] == EMPTY || table[newIndex] == DELETED) {
            table[newIndex] = key;
            cout << "Inserted " << key << " at index " << newIndex << ".\n";
            return;
        } else if (table[newIndex] == key) {
            cout << "Duplicate key! Insertion aborted.\n";
            return;
        }
        i++;
    }

    cout << "Hash Table is full! Cannot insert.\n";
}

//Function to remove an element from the hash table
void HashTable::remove(int key) {
    int index = hashFunction(key);
    int i = 0;

    while (i < TABLE_SIZE) {
        int newIndex = (index + i * i) % TABLE_SIZE;
        if (table[newIndex] == EMPTY) break;
        if (table[newIndex] == key) {
            table[newIndex] = DELETED;
            cout << "Deleted " << key << " from index " << newIndex << ".\n";
            return;
        }
        i++;
    }

    cout << "Key not found!\n";
}

//Function to search an element in the hash table
void HashTable::search(int key) {
    int index = hashFunction(key);
    int i = 0;

    while (i < TABLE_SIZE) {
        int newIndex = (index + i * i) % TABLE_SIZE;
        if (table[newIndex] == EMPTY) break;
        if (table[newIndex] == key) {
            cout << "Key " << key << " found at index " << newIndex << ".\n";
            return;
        }
        i++;
    }

    cout << "Key not found!\n";
}

//Function to display all the elements in the hash table
void HashTable::display() {
    cout << "\nHash Table:\n";
    for (int i = 0; i < TABLE_SIZE; ++i) {
        cout << i << ": ";
        if (table[i] == EMPTY)
            cout << "EMPTY";
        else if (table[i] == DELETED)
            cout << "DELETED";
        else
            cout << table[i];
        cout << endl;
    }
}