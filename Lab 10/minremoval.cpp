//Program to find the least number of moves to remove the duplicates in an array
#include <iostream>
#include <vector>
using namespace std;

//Function to count the frequency of elements occuring more than once
int minremoval(vector <int>&a,int n){
    vector <int>freq(n+1,0);
    int removal=0;
    for (int i=n-1;i>=0;i--){
        if (freq[a[i]]>0){
            break;
        }
        freq[a[i]]++;
        removal++;
    }
    return n-removal;
}

//Main function to call the subfunction and get the output
int main(){
    int testcase,n;
    cout<<"Enter the number of testcases:";
    cin>>t;
    while (testcase--){
        cout<<"Enter the number of elements:";
        cin>>n;
        vector <int> a(n);
        cout<<"Enter the elements:";
        for (int &x:a){
            cin>>x;
    }
    int result=minremoval(a,n);
    cout<<"Minimum elements to remove:"<<result<<endl;
}
return 0;
}