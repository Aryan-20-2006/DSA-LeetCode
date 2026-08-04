//Problem-Longest Common Prefix
//Difficultt-Easy

#include<bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string>&str){

    string result;
    int n=str.size();

    //sort the array first
    sort(str.begin(),str.end());

    //get the first and last strings
    string first=str[0];
    string last=str[n-1];

    //compare the characters
    for(int i=0;i<first.size();i++){
        if(first[i]!=last[i]){
            break;
        }

        result.push_back(first[i]);
    }

return result;

}

int main(){

    vector<string>str={"flowers","flow","fly","flight"};
    cout<<longestCommonPrefix(str)<<" ";
    return 0;

}


