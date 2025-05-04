//Program to implement Hash ADT with Separate Chaining with operations like insertion, deletion, and searching
#include <iostream>
#include <list>
#include <vector>

using namespace std;

class HashTable {
private:
    vector<list<int>> table;
    int size;

    int hashFunction(int key) const {
        return key % size;
    }

public:
    HashTable(int s) : size(s) {
        table.resize(size);
    }
    void insert(int);
    void remove(int);
    void search(int)const;
    void display()const;
    
};

int main() {
    int tableSize;
    cout << "Enter size of hash table: ";
    while (!(cin >> tableSize) || tableSize <= 0) {
        cout << "Please enter a valid positive size: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    HashTable ht(tableSize);
    int choice, key;

    do {
        cout << "\n--- Hash Table Menu ---\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Search\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter key to insert: ";
            cin >> key;
            ht.insert(key);
            ht.display();
            break;
        case 2:
            cout << "Enter key to delete: ";
            cin >> key;
            ht.remove(key);
            ht.display();
            break;
        case 3:
            cout << "Enter key to search: ";
            cin >> key;
            ht.search(key);
            break;
        case 4:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}

//Function to insert an element to the hash table
void HashTable::insert(int key) {
    int index = hashFunction(key);
    for (int val : table[index]) {
        if (val == key) {
            cout << "Key " << key << " already exists in the hash table.\n";
            return;
        }
    }
    table[index].push_back(key);
    cout << "Inserted " << key << " into the hash table.\n";
}

//Function to remove an element from the hash table
void HashTable::remove(int key) {
    int index = hashFunction(key);
    auto& chain = table[index];
    auto it = find(chain.begin(), chain.end(), key);
    if (it != chain.end()) {
        chain.erase(it);
        cout << "Key " << key << " deleted from the hash table.\n";
    } else {
        cout << "Key " << key << " not found in the hash table.\n";
    }
}

//Function to search an element in the hash table
void HashTable::search(int key) const {
    int index = hashFunction(key);
    const auto& chain = table[index];
    for (int val : chain) {
        if (val == key) {
            cout << "Key " << key << " found at index " << index << ".\n";
            return;
        }
    }
    cout << "Key " << key << " not found in the hash table.\n";
}

//Function to display all the elements in the hash table
void HashTable::display() const {
    cout << "\nCurrent Hash Table:\n";
    for (int i = 0; i < size; ++i) {
        cout << "[" << i << "]: ";
        for (int key : table[i]) {
            cout << key << " -> ";
        }
        cout << "NULL\n";
    }
}