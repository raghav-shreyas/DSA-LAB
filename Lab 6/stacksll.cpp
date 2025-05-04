//Program to perform operations on a stack using SinglyLinkedList
#include<iostream>
using namespace std;

//Defining structure of the node
struct node{
    char data;
    node *next;
    node(char ch):data(ch),next(nullptr){};
};

//Defining top as a pointer and the function prototypes
class stack_sll{
    private:
    node *top;
    public:
    void push(char ch);
    void pop();
    void peek();
    void display();

stack_sll(){
    top=nullptr;   //constructor initializing top as a null pointer
}
};

//Main function to choose an operations and execute them accordingly
int main(){
    stack_sll stack;
    int choice;
    char ch;
    int flag=1;
    while (flag==1){
        cout<<"\nStack Operations using SinglyLinkedList:"<<endl;
        cout<<"1.Push"<<endl;
        cout<<"2.Pop"<<endl;
        cout<<"3.Peek"<<endl;
        cout<<"4.Exit"<<endl;
        cout<<"Enter choice: ";
        cin>>choice;
        switch(choice){
            case 1:
            cout<<"Enter character to push: ";
            cin>>ch;
            stack.push(ch);
            break;

            case 2:
            stack.pop();
            break;

            case 3:
            stack.peek();
            break;

            case 4:
            flag=0;
            cout<<"Exiting"<<endl;
            break;

            default:
            cout<<"Invalid choice"<<endl;
            break;
        }
    }
return 0;
}

//Function to push a character into the stack
void stack_sll::push(char ch){
    node *newnode=(node*)malloc(sizeof(node));
    newnode->data=ch;
    newnode->next=top;
    top=newnode;
    cout<<ch<<" pushed into stack"<<endl;
}

//Function to pop out the top most character of the stack
void stack_sll::pop(){
    if (top==nullptr){
        cout<<"Stack Underflow!"<<endl;
        return;
    }
    node *temp=top;
    cout<<top->data<<" popped from the stack"<<endl;
    top=top->next;
    free(temp);
}

//Function to peek and print the top most character of the stack
void stack_sll::peek(){
    if (top==nullptr){
        cout<<"Stack Underflow!"<<endl;
        return;
    }
    cout<<top->data<<" is the top element"<<endl;
}

