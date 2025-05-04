#include<iostream>
#include<string>
using namespace std;

struct node{
    char data;
    node* next;
};

class stack{
private:
    node* top;
public:
    stack(){
        top=nullptr;
    }

    int isempty(){return top==nullptr;}

    void push(char value){
        node* newnode=(node*)malloc(sizeof(node));
        newnode->data=value;
        newnode->next=top;
        top=newnode;
    }

    int pop(){
        if(isempty())return '\0';
        char value=top->data;
        node* temp=top;
        top=top->next;
        free(temp);
        return value;
    }

    ~stack(){
        while(!isempty())pop();
    }
};

int isbalanced(string &expr){
    stack s;
    
    for(char ch:expr){
        if(ch=='(')s.push(ch);
        else if(ch==')'){
            if(s.isempty())return 0;
            s.pop();
        }
    }
    return s.isempty();
}

int main(){
    string expr;
    int choice,flag=0;

    while(flag==0){
        cout<<"1.Check balance"<,endl;
        cout<<"2.Exit"<<endl;
        cout<<"Enter choice: ";
        cin>>choice;

        switch(choice){
            case 1:
                cout<<"Enter parenthesis string: ";
                cin>>expr;
                if(isbalanced(expr))cout<<"Balanced\n";
                else cout<<"Not balanced\n";
                break;
            case 2:
                cout<<"Exiting"<<endl;
                flag=1;
                break;
            default:
                cout<<"Invalid choice.\n";
        }
    }
    return 0;
}
