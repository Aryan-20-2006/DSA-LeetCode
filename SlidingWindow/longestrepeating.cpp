//Problem-Longest Repeating Character Replacement
//Difficulty-Medium

#include<bits/stdc++.h>
using namespace std;

//Brute Force-TC(O(N2), SC-O(26)
// int characterReplacement(string s, int k){

// //To find the no of changes I have to make , it would be the len-maxFreq
// //Eg:-AABABC, I have to make sure the changes are lesser than the no of operations, so here I can change B and C to A 
// //Since A has a maxFreq=3 and the length is 6 , that means I have to change 3 characters i.e B B C

// int maxlen=0;
// int n=s.size();

// for(int i=0;i<n;i++){
//     //creating a hash array and also initializing the freq
//     vector<int>hash(26,0);

//     int maxFreq=0;

//     for(int j=i;j<n;j++){

//         //increase the freq as you move across the string
//         hash[s[j]-'A']++;

//         //find the max frequency
//         maxFreq=max(maxFreq,hash[s[j]-'A']); 

//         int changes=(j-i+1)-maxFreq;

//         //if it is valid i.e changes are lesser than or equal to k
//         if(changes<=k){
//             maxlen=max(maxlen,j-i+1);
//         }

//         //othwerwise it is not possible
//         else{
//             break; 
//         }
//     }
// }

// return maxlen;


// }


//Optimal Solution
int characterReplacement(string s,int k){

    int n=s.size();
    int l=0;
    int r=0;
    int maxlen=0;
    int maxFreq=0;

    vector<int>hash(26,0);

    while(r<n){
        hash[s[r]-'A']++;
        maxFreq=max(maxFreq,hash[s[r]-'A']);

        while((r-l+1)-maxFreq>k){
                hash[s[l]-'A']--; //removing the outgoing element
                int maxfreq=0; //again I have to update the new freq after removing the outgoing element
            
                for(int i=0;i<26;i++){  //checking which has the maxFreq 
                    maxFreq=max(maxFreq,hash[i]);
                }    
                
            l=l+1;
        }
        
        if((r-l+1)-maxFreq<=k){
            maxlen=max(maxlen,r-l+1);
        }

        r++;
}

return maxlen;

}

int main(){
    string s="AAABBCCD";
    int k=2;
    cout<<characterReplacement(s,k)<<" ";
    return 0;
}