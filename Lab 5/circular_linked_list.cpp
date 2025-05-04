#include <stdio.h>
#include <stdlib.h>

class list{
    struct node{
        int data;
        struct node *next; // Cursor to move to the next node
    }*head;

    public:
        list(){
            head=NULL;
        }
        int insert_beg(int data);
        int insert_end(int data);
        int insert_pos(int data,int pos);
        void delete_beg();
        void delete_end();
        void delete_pos(int pos);
        int search(int data);
        void display();
};

int main(){
    list L;
    int choice,data,pos;

    // Main menu
    while(choice != 9){
        printf("Menu is as follows:\n1.Insert at the beginning\n2.Insert at the end\n3.Insert at a given position\n4.Delete from beginning\n5.Delete from end\n6.Delete from a given position\n7.Search\n8.Display\n9.Exit\n");
        printf("Please enter your choice:\n");
        scanf("%d",&choice);

        switch(choice) {
            case 1:
                printf("Enter data to be inserted: ");
                scanf("%d",&data);
                L.insert_beg(data);
                break;

            case 2:
                printf("Enter data to be inserted: ");
                scanf("%d",&data);
                L.insert_end(data);
                break;

            case 3:
                printf("Enter position of the new node: ");
                scanf("%d",&pos);
                printf("Enter data to be inserted: ");
                scanf("%d",&data);
                L.insert_pos(data,pos);
                break;

            case 4:
                L.delete_beg();
                break;

            case 5:
                L.delete_end();
                break;

            case 6:
                printf("Enter position to be deleted: ");
                scanf("%d",&pos);
                L.delete_pos(pos);
                break;

            case 7:
                printf("Enter data to be searched: ");
                scanf("%d",&data);
                L.search(data);
                break;

            case 8:
                printf("Contents of the circular linked list are\n");
                L.display();
                break;
            
            case 9:
                return 1;
                break;
        }
    }
    
    return 0;
}

// Insert in the beginning of the circular linked list
int list::insert_beg(int data){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    

    // If list is empty, point to itself
    if (head == NULL) {
        head = newnode;
        newnode->next = head;
    } else {
        newnode->next = head;
        head = newnode;
    }

    return 0;
}

// Display the circular linked list
void list::display() {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    
    struct node *temp = head;
    do {
        printf("%d\n", temp->data);
        temp = temp->next;
    } while (temp != head);
    
}

// Insert at the end of the circular linked list
int list::insert_end(int data){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    
    if (head == NULL) {
        head = newnode;
        newnode->next = head;
    } else {
        struct node *temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = head;
    }

    return 0;
}

// Insert at a given position in the circular linked list
int list::insert_pos(int data, int pos) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;

    if (pos == 1) {
        insert_beg(data);
        return 0;
    }

    struct node *temp = head;
    for (int i = 1; i < pos - 1 && temp->next != head; i++) {
        temp = temp->next;
    }

    if (temp->next == head && pos > 1) {
        printf("Position out of range.\n");
        free(newnode);
        return -1;
    }

    newnode->next = temp->next;
    temp->next = newnode;
    return 0;
}

// Delete from the beginning of the circular linked list
void list::delete_beg() {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    if (head->next == head) {  // Only one node in the list
        free(head);
        head = NULL;
    } else {
        struct node *temp = head;
        // Traverse to the last node to update its 'next' pointer
        while (temp->next != head) {
            temp = temp->next;
        }
        struct node *toDelete = head;
        head = head->next;
        temp->next = head;
        free(toDelete);
    }
}

// Delete from the end of the circular linked list
void list::delete_end() {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    if (head->next == head) {  // Only one node in the list
        free(head);
        head = NULL;
    } else {
        struct node *temp = head;
        while (temp->next->next != head) {
            temp = temp->next;
        }
        struct node *toDelete = temp->next;
        temp->next = head;
        free(toDelete);
    }
}

// Delete from a given position in the circular linked list
void list::delete_pos(int pos) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    if (pos == 1) {
        delete_beg();
        return;
    }

    struct node *temp = head;
    for (int i = 1; i < pos - 1 && temp->next != head; i++) {
        temp = temp->next;
    }

    if (temp->next == head) {
        printf("Position out of range.\n");
        return;
    }

    struct node *toDelete = temp->next;
    temp->next = temp->next->next;
    free(toDelete);
}

// Search for a data in the circular linked list
int list::search(int data) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return -1;
    }

    struct node *temp = head;
    int position = 1;
    do {
        if (temp->data == data) {
            printf("Data %d found at position %d.\n", data, position);
            return position;
        }
        temp = temp->next;
        position++;
    } while (temp != head);

    printf("Data %d not found in the list.\n", data);
    return -1;
}