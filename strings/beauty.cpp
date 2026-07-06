//Problem-Sum of Beauty of All Substrings
//Difficulty-Medium

#include<bits/stdc++.h>
using namespace std;

int beautySum(string s){

    
    int sum=0;

    int n=s.size();

    for(int i=0;i<n;i++){
        vector<int>freq(26,0); //here using an array would be better instead of an unordered map even though both work
        
        for(int j=i;j<n;j++){
            freq[s[j]-'a']++;

           int maxFreq=0;
           int minFreq=INT_MAX; //these values need to be updated, so they are within this loop

            for(int k=0;k<26;k++){ //we scan to look for the max and min cuz we dont know
                if(freq[k]==0)
                    continue; //we dont want to update to 0 as our min freq so we skip the iteration
                
                maxFreq=max(maxFreq,freq[k]);
                minFreq=min(minFreq,freq[k]);
            }

            int beauty=maxFreq-minFreq;
            sum+=beauty;
        }

    }

return sum;

}

int main(){

    string s="xyx";
    cout<<beautySum(s)<<" ";
    return 0;

}