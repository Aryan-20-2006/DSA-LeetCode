//Problem-Sort Characters by Frequency
//Difficulty-Easy

#include<bits/stdc++.h>
using namespace std;

static bool comperator(pair<int,char>p1,pair<int,char>p2){

    if(p1.first>p2.first)
        return true;
    if(p1.first<p2.first)
        return false;
    
    return p1.second< p2.second;



}

vector<char> frequencySort(string &s){

    pair<int,char>freq[26];

    //initializing the array with character labels i.e freq,char
    for(int i=0;i<26;i++){
        freq[i]={0,i+'a'};
    }

    for(char ch:s){
        freq[ch-'a'].first++;
    }

    sort(freq, freq+26, comperator); //based on the comparator function, sort it

    vector<char>ans;

    //store answers with non zero frequency
    for(int i=0;i<26;i++){
        if(freq[i].first>0){
            ans.push_back(freq[i].second);
        }
    }

return ans;

}

int main(){

    string s="tree";
    vector<char>ans=frequencySort(s);

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }


    return 0;


}