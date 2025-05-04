//Program to implement List ADT using doubly linked list

#include <stdio.h>
#include <stdlib.h>

class list{
    struct node{
        int data;
        struct node *next; // Cursor to move to the next node
        struct node *prev; // Cursor to move to the previous node
    }*head,*tail;

    public:
        list(){
            head=NULL;
            tail=NULL; // Points to the last node
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
    while(choice!=9){
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
                L.display();
                break;
            
            case 9:
                return 1;
                break;
        }
    }
    
    return 0;
}

//Insert in the beginning of the doubly linked list
int list:: insert_beg(int data){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=newnode->prev=NULL;

    if(head==NULL){
        head=tail=newnode;
        return 1;
    }
    else{
        head->prev=newnode;
        newnode->next=head;
        head=newnode;
        return 0;
    }
}

// Display the contents of the doubly linked list
void list:: display(){
    struct node *temp;
    // Forward display
    printf("Contents of the dll in original order: \n");
    temp=head;
    while(temp!=NULL){
        printf("%d\n",temp->data);
        temp=temp->next;
    }

    // Backward display
    printf("Contents of the dll in reverse order: \n");
    temp=tail;
    while(temp!=NULL){
        printf("%d\n",temp->data);
        temp=temp->prev;
    }

}

// Insert in the end of the doubly linked list
int list:: insert_end(int data){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=newnode->prev=NULL;

    if(head==NULL){
        head=tail=newnode;
        return 1;
    }
    else{
        newnode->prev=tail;
        tail->next=newnode;
        tail=newnode;
        return 0;
    }
}

// Delete from the beginning of the doubly linked list
void list:: delete_beg(){
    if(head==NULL){
        printf("List is empty\n");
    }
    else{
        struct node *temp=head;
        head=head->next;
        head->prev=NULL;
        free(temp);
        printf("Deletion successful!\n");
    }
}

// Delete from the end of the doubly linked list
void list:: delete_end(){
    if(tail==NULL){
        printf("List is empty\n");
    }
    else{
        struct node *temp=tail;
        tail=tail->prev;
        tail->next=NULL;
        free(temp);
        printf("Deletion successful!\n");
    }
}

// Search for a particular data in a doubly linked list
int list:: search(int data){
    if(head==NULL){
        printf("Data cannot be searched since list is empty");
        return 1;
    }
    else{
        struct node *temp=head;
        int pos=1;
        while(temp->next!=NULL){
            if(temp->data==data){
                printf("Data found at position %d\n",pos);
            }
            temp=temp->next;
            pos=pos+1;
        }
        return 0;
    }
}

// Insert in a given position in a doubly linked list
int list:: insert_pos(int data,int pos){
    struct node *temp=head;
    int count=0; // To calculate and store the length of the DLL

    while(temp->next!=NULL){
        temp=temp->next;
        count+=1;
    }
    temp=head;

    if(pos<1 || pos>count+1) {
        printf("Invalid position");
        return 1;
    }

    else if(pos==1){
        insert_beg(data);
        return 1;
    }

    else{
        struct node *newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data;
        newnode->next=newnode->prev=NULL;
        struct node *temp2;
        
        
        int i=1; // To traverse till the given position

        while(i<pos){
            temp=temp->next;
            i=i+1;
        }
        temp2=temp->next;
        temp->next=newnode;
        temp2->prev=newnode;
        newnode->prev=temp;
        newnode->next=temp2;
        return 0;
    }

}

// Delete from a given position in a doubly linked list
void list:: delete_pos(int pos){
    struct node *temp=head;
    int count=0; // To calculate and store the length of the DLL

    while(temp->next!=NULL){
        temp=temp->next;
        count+=1;
    }
    temp=head;

    if(pos<1 || pos>count+1) {
        printf("Invalid position");
    }

    else if(pos==1){
        delete_beg();
    }
    else{
        int i=1;
        struct node *temp2;
        while(i<pos){
            temp=temp->next;
            i+=1;
        }
        temp2=temp->prev;
        temp2->next=temp->next;
        temp->next->prev=temp2;
        free(temp);
    }
}