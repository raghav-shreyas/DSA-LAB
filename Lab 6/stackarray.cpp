//Program to perform operations on a stack using array
#include<iostream>
using namespace std;

//Defining the array, top element and its functions
class stack_array{
    private:
        char arr[5];
        int top;
    public:
        void push(char ch);
        void pop();
        void peek();

stack_array(){
    top=-1;   //constructor initializiing top to -1 showing as list is empty
}
};

//Main function to choose an operation and execute it accordingly
int main(){
    stack_array stack;
    int choice;
    char ch;
    int flag=1;
    while (flag==1){
        cout<<"\nStack Operations using Array:"<<endl;
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
void stack_array::push(char ch){
    if (top>=4){
        cout<<"Stack Overflow!"<<endl;
        return;
    }
    arr[++top]=ch;
    cout<<"Added "<<ch<<" into the stack"<<endl;
}

//Function to pop out the top most character from the stack
void stack_array::pop(){
    if (top==-1){
        cout<<"Stack Underflow!"<<endl;
        return;
    }
    cout<<arr[top--]<<" popped from the stack"<<endl;
}

//Function to peek and print the top most character
void stack_array::peek(){
    if (top==-1){
        cout<<"Stack empty!"<<endl;
        return;
    }
    cout<<arr[top]<<" is the top element"<<endl;
}

