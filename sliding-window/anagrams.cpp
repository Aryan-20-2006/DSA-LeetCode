//Problem-Find All Anagrams in a String
//Difficult-Medium

#include<bits/stdc++.h>
using namespace std;

vector<int> findAnagrams(string s,string p){

    vector<int>pfreq(26,0);
    vector<int>sfreq(26,0);

    vector<int>result; //store the indices in a result array

    //count characters of p
    for(int i=0;i<p.size();i++){
        pfreq[p[i]-'a']++;
    }

    //using sliding window
    for(int i=0;i<s.size();i++){
        sfreq[s[i]-'a']++;

        //remove the character leaving the window

        if(i>=p.size()){
            sfreq[s[i-p.size()]-'a']--;
        }

        //compare frequency

        if(sfreq==pfreq){
            result.push_back(i-p.size()+1); //pushing the first index
        }

    }
return result;

}

int main(){

    string s="cbaebabacd";
    string p="abc";
    vector<int>result=findAnagrams(s,p);

    for(int i=0;i<result.size();i++){
        cout<< result[i] << " ";
    }

    return 0;

}