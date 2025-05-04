//Program to implement Priority Queue ADT using a Max Heap
#include<iostream>
#include<vector>
using namespace std;

//Function prototypes
void insert(int val);
void deletemax();
void display();
void search(int val);
void heapsort();
void heapifyup(int index);
void heapifydown(int index);

//Global max heap vector
vector<int>heap;

//Main function to perform menu-driven operations on Priority Queue
int main(){
    int choice,val;
    int flag=1;
    while(flag==1){
        cout<<"\nPriority Queue Operations:"<<endl;
        cout<<"1.Insert"<<endl;
        cout<<"2.Delete Max"<<endl;
        cout<<"3.Display"<<endl;
        cout<<"4.Search"<<endl;
        cout<<"5.Sort (Heap Sort)"<<endl;
        cout<<"6.Exit"<<endl;
        cout<<"Enter choice: ";
        cin>>choice;

        switch(choice){
            case 1:
            cout<<"Enter value to insert: ";
            cin>>val;
            insert(val);
            break;

            case 2:
            deletemax();
            break;

            case 3:
            display();
            break;

            case 4:
            cout<<"Enter value to search: ";
            cin>>val;
            search(val);
            break;

            case 5:
            heapsort();
            break;

            case 6:
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

//Function to insert element into the heap
void insert(int val){
    heap.push_back(val);
    heapifyup(heap.size()-1);
    cout<<val<<" inserted into the Priority Queue"<<endl;
}

//Function to delete the maximum element (root)
void deletemax(){
    if(heap.empty()){
        cout<<"Priority Queue is empty"<<endl;
        return;
    }
    cout<<heap[0]<<" deleted from the Priority Queue"<<endl;
    heap[0]=heap.back();
    heap.pop_back();
    heapifydown(0);
}

//Function to display the heap elements
void display(){
    if(heap.empty()){
        cout<<"Priority Queue is empty"<<endl;
        return;
    }
    cout<<"Current Heap: ";
    for(int val:heap)
        cout<<val<<" ";
    cout<<endl;
}

//Function to search for an element in the heap
void search(int val){
    for(int i=0;i<heap.size();i++){
        if(heap[i]==val){
            cout<<val<<" found at index "<<i<<endl;
            return;
        }
    }
    cout<<val<<" not found in the Priority Queue"<<endl;
}

//Function to perform heap sort and display in descending order
void heapsort(){
    if(heap.empty()){
        cout<<"Priority Queue is empty"<<endl;
        return;
    }
    vector<int>temp=heap;
    vector<int>sorted;
    while(!temp.empty()){
        sorted.push_back(temp[0]);
        temp[0]=temp.back();
        temp.pop_back();
        int i=0,size=temp.size();
        while(true){
            int largest=i;
            int l=2*i+1,r=2*i+2;
            if(l<size&&temp[l]>temp[largest]) largest=l;
            if(r<size&&temp[r]>temp[largest]) largest=r;
            if(largest!=i){
                swap(temp[i],temp[largest]);
                i=largest;
            }
            else break;
        }
    }
    cout<<"Heap Sorted (Descending): ";
    for(int val:sorted)
        cout<<val<<" ";
    cout<<endl;
}

//Function to maintain heap property from bottom to top
void heapifyup(int index){
    while(index>0&&heap[index]>heap[(index-1)/2]){
        swap(heap[index],heap[(index-1)/2]);
        index=(index-1)/2;
    }
}

//Function to maintain heap property from top to bottom
void heapifydown(int index){
    int size=heap.size();
    int largest=index;
    int left=2*index+1;
    int right=2*index+2;

    if(left<size&&heap[left]>heap[largest])
        largest=left;
    if(right<size&&heap[right]>heap[largest])
        largest=right;
    if(largest!=index){
        swap(heap[index],heap[largest]);
        heapifydown(largest);
    }
}
