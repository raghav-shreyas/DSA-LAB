#include "SLL.H"

int main() {
    SLL l1, l2, l3;
    int choice, value;

    do {
        cout << "\nMenu:\n";
        cout << "1. insert into list 1\n";
        cout << "2. insert into list 2\n";
        cout << "3. merge list 1 and list 2\n";
        cout << "4. disp\n";
        cout << "5. Exit\n";
        cout << "enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "enter value to insert into L1: ";
                cin >> value;
                l1.insertasc(value);
                break;
            case 2:
                cout << "Enter value to insert into L2: ";
                cin >> value;
                l2.insertasc(value);
                break;
            case 3:
                l3 = l3.merge(l1, l2);
                cout << "Merged\n";
                break;
            case 4:
                cout << "L1: ";
                l1.disp();
                cout << "L2: ";
                l2.disp();
                cout << "L3: ";
                l3.disp();
                break;
            case 5:
                cout << "exiting\n";
                break;
            default:
                cout << "invalid\n";
        }
    } while (choice != 5);

    return 0;
}
