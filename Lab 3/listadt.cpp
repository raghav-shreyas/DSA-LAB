#include <iostream>
using namespace std;
class listadt
{
    private:
    int arr[5];
    int size;
    void reverse(int start,int end);

    public:
    void insertbeginning(int value);
    void insertend(int value);
    void insertpos(int value,int pos);
    int deletebeginning();
    int deleteend();
    int deletepos(int pos);
    void search(int value);
    void display();
    void rotate(int k);

listadt(){
    size=0;
}
};


int main(){
    listadt list;
    int value,pos,k;
    cout<<"List Operations:"<<endl;
    cout<<"1.Insert at beginning"<<endl;
    cout<<"2.Insert at end"<<endl;
    cout<<"3.Insert at position"<<endl;
    cout<<"4.Delete from beginning"<<endl;
    cout<<"5.Delete from end"<<endl;
    cout<<"6.Delete at position"<<endl;
    cout<<"7.Search"<<endl;
    cout<<"8.Display"<<endl;
    cout<<"9.Rotate"<<endl;
    cout<<"10.Exit"<<endl;
    int flag=1;
    while(flag==1){
        cout<<"Enter choice:";
        int choice;
        cin>>choice;
        switch(choice){
            case 1:
            cout<<"Enter value to insert in beginning:";
            cin>>value;
            list.insertbeginning(value);
            list.display();
            break;
            case 2:

            cout<<"Enter value to insert at end:";
            cin>>value;
            list.insertend(value);
            list.display();
            break;  

            case 3:
            cout<<"Enter value and position to insert:"<<endl;
            cin>>value;
            cin>>pos;
            list.insertpos(value,pos);
            list.display();
            break;
            
            case 4:
            cout<<"Deleting from beginning"<<endl;
            list.deletebeginning();
            list.display();
            break;

            case 5:
            cout<<"Deleting from end"<<endl;
            list.deleteend();
            list.display();
            break;

            case 6:
            cout<<"Enter position to delete:";
            cin>>pos;
            list.deletepos(pos);
            list.display();
            break;

            case 7:
            cout<<"Enter value to search:";
            cin>>value;
            list.search(value);
            list.display();
            break;

            case 8:
            cout<<"Displaying the list:"<<endl;
            list.display();
            break;

            case 9:
            cout<<"Enter number of times to rotate:";
            cin>>k;
            list.rotate(k);
            list.display();
            break;

            case 10:
            cout<<"Exiting.."<<endl;
            flag=0;
            break;
        }
    }
}
/*Function to insert at beginning*/
void listadt::insertbeginning(int value){
    if (size>5){
        cout<<"List full"<<endl;
    }
    for (int i=size;i>=0;i--){
        arr[i]=arr[i-1];
    }
    arr[0]=value;
    size++;

}
/*Function to insert at end*/
void listadt::insertend(int value){
    if (size>5){
        cout<<"List full"<<endl;
        
    }
    arr[size]=value;
    size++;
}
/*Function to insert at position*/
void listadt::insertpos(int value,int pos){
    if (size>5){
        cout<<"List full"<<endl;
        
    }
    for (int i=size;i>=pos;i--){
        arr[i]=arr[i-1];
    }
    arr[pos-1]=value;
    size++;

}
/*Function to delete at beginning*/
int listadt::deletebeginning(){
    if (size==0){
        cout<<"List empty"<<endl;
        return 0;
    }
    int temp=arr[0];
    for(int i=0;i<size;i++){
        arr[i]=arr[i+1];
    }
    cout<<"Deleted:"<<temp<<endl;
    size--;
    return temp;
}
/*Function to delete at end*/
int listadt::deleteend(){
    if (size==0){
        cout<<"List empty"<<endl;
        
    }
    int temp=arr[size-1];
    size--;
    cout<<"Deleted:"<<temp<<endl;
    return temp;
}
/*Function to delete using position*/
int listadt::deletepos(int pos){
    if (pos<1 || pos>size){
        cout<<"Invalid position"<<endl;
        return -1;
    }
    int temp=arr[pos-1];
    for (int i=pos-1;i<size-1;i++){
        arr[i]=arr[i+1];
    }
    cout<<"Deleted:"<<temp<<endl;
    size--;
    return temp;
    
}
/*Function to search*/
void listadt::search(int value){
    for(int i=0;i<size;i++){
        if (arr[i]==value){
            cout<<"Found at position "<<i+1<<endl;
            
        }
    }
}
/*Function to display*/
void listadt::display(){
    if (size==0) {
        cout <<"List is empty!"<< endl;
        return;
    }
    int i;
    cout<<"Array:";
    for(i=0;i<size;i++){
    cout<<arr[i]<<" ";}
    cout<<endl;    
}


/*Function to reverse*/
void listadt::reverse(int start,int end){
    while(start<end){
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
}
/*Function to rotate k times*/
void listadt::rotate(int k){
    if (size == 0 || k == 0) 
    return;
    reverse(size-k,size-1);
    reverse(0,size-k-1);
    reverse(0,size-1);
}