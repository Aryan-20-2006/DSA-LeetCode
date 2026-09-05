//Problem-Minimum Window Substring
//Difficulty-Hard

#include<bits/stdc++.h>
using namespace std;

string minWindow(string s, string t){


int l=0, r=0;

int minlen=INT_MAX;
int sindex=-1; //starting index
int cnt=0;
int n=t.size(); 
int m=s.size();

vector<int>hash(256,0); //storing all the alphabets

//storing all the characters of t in the hash i.e pre inserting the values
for(int i=0;i<n;i++){
    hash[t[i]]++;
}

while(r<s.size()){
    if(hash[s[r]]>0){ //if it is already positive in the map, that means that character is one among t
        cnt=cnt+1;
    
    }

    hash[s[r]]--;

    //shrinking the window
    while(cnt==n){
        if(r-l+1<minlen){
            minlen=r-l+1;
            sindex=l;
        }
        

    
    hash[s[l]]++; //when your shrinking s[l] from the current window , you need to give back the character so it would be ++
    

    //if after removal the value turns out to be greater than zero , it means I reinserted
    if(hash[s[l]]>0){
        cnt=cnt-1;
    }

    l++;

    }

    r++;
}

//if the starting index was never updated, then return an empty string
if(sindex==-1)
    return "";

return s.substr(sindex,minlen); //since we want the min length as possible


}

int main(){
    string s="cabwefgewcwaefgcf";
    string t="cae";
    cout<<minWindow(s,t)<<" ";
    return 0;
}