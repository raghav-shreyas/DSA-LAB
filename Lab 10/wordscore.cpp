//Program to find the common words and caclulate the score
#include <iostream>
#include <vector>
#include <map>
using namespace std;

//Function to find the common words
void solve(){
    int n,score;
    cout<<"Enter number of words per person:";
    cin>>n;
    vector <vector<string>>words(3,vector<string>(n));
    map<string,int>freq;

    for (auto &players:words){
        for (auto &word:players){
            cout<<"Enter 3 letter word:";
            cin>>word;
            freq[word]++;
        }
    }
    for (auto &players:words){
        score=0;
        for (auto &word:players){
            score+=freq[word]==1?3:freq[word]==2?1:0; //to calculate score after comparing common words
        }
        cout<<score;                          
    }
    cout<<endl;
}

//Main function to call the subfunction and get the output
int main(){
    int testcase;
    cout<<"Enter number of testcases:";
    cin>>testcase;
    while (testcase--){
        solve();
    }
}