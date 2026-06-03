#include<bits/stdc++.h>
using namespace std;





// /*
// one method=Using bubble sort-both the strings eventually will be same after using bubble sort on them so if they are equal then its a valid anagram

// It is used to give quicker solutions however the time complexity is nlogn which is not ideal. If u are using bubble sort then its n^2
// */

// // bool isAnagram(string s,string t){


// //    if(s.size()!=t.size())
// //         return false;

// //     sort(s.begin(),s.end());
// //     sort(t.begin(),t.end());

    
// //     if(s==t)
// //         return true;
// //     else
// //         return false;

// // }


// /*Better approach to use is hash counting-Used to track frequencies
// Why-Cuz it runs in O(n) time and constant space-O(26)-constant i.e O(1)
// */
// bool isAnagram(string s,string t){

//     //base case-check if the lengths are equal or not
//     if(s.size()!=t.size()){
//         return false;
//     }


//     vector<int>count(26,0);

//     for(int i=0;i<s.size();i++){ //there is no need to use another loop for t since the complexity increases
//         count[s[i]-'a']++;
//         count[t[i]-'a']--;
//     }

//     for(int i=0;i<26;i++){ //check if everything is zero
//         if(count[i]!=0)
//             return false;
//     }


//     return true;


// }


// int main(){


//     string s="anagram";
//     string t="nagaram";

//     cout<<isAnagram(s,t)<<endl;
//     return 0;

// }

//Brute Force Solution-Sorting both the strings and checking if equal after sorting


// #include<bits/stdc++.h>
// using namespace std;

// bool isAnagram(string s, string t){

//     if(s.size()!=t.size())
//         return false;


//     sort(s.begin(),s.end());
//     sort(t.begin(), t.end());

//     //After sorting

//     if(s==t)
//         return true;
    

// return false;

// }

// int main(){


//     string s="RAT";
//     string t="CAR";

//     cout<<isAnagram(s,t)<<endl;

//     return 0;

// }

//Optimal solution-Counting frequencies

bool isAnagram(string s, string t){

    if(s.size()!=t.size())
        return false;

    vector<int>freq(26,0); //creating a frequency array of all the lpahbets initialized to zero

    for(char c: s)
        freq[c-'a']++;
    
    for(char c:t)
        freq[c-'a']--; //doing this to check if the count becomes zero then valid

    for(int count:freq)
        if(count!=0)
            return false;

    return true;



}