//Problem-Longest Susbtring with K Uniques
//Difficulty-Medium

#include<bits/stdc++.h>
using namespace std;

int longestKSubstr(string &s, int k){

    int maxlen=0;
    int l=0;
    int r=0;

    unordered_map<char,int>mp; //note-this takes complexity of O(1) considering all upper and lower case characters

    while(r<s.size()){

        mp[s[r]]++;

        while(mp.size()>k){  //if its exceeding the window size, its not valid
            mp[s[l]]--;
        

            if(mp[s[l]]==0){
                mp.erase(s[l]); //remove only one element
            
            }

            l=l+1;    
        }


        if(mp.size()<=k){
            int length=r-l+1;
            maxlen=max(maxlen,length);
        }

        r++;

    }

return maxlen;

}


int main(){

    string s="aaabbccd";
    int k=2;
    cout<<longestKSubstr(s,k)<<"";
    return 0;

}