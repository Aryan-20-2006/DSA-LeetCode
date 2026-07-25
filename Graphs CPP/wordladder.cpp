//Problem-Word Ladder I
//Difficulty-Hard

#include<bits/stdc++.h>
using namespace std;

int wordLadderLength(string startWord, string targetWord,vector<string> &wordlist){

    queue<pair<string,int>>q;
    q.push({startWord,1});
    //using the set data structure
    unordered_set<string>st(wordlist.begin(),wordlist.end());
    //every time we pushed something into the queue, we marked it as visited
    //since we're not using a visited array, we're deleting it from the set
    st.erase(startWord);

    while(!q.empty()){
        string word=q.front().first;
        int steps=q.front().second;
        q.pop();

    if(word==targetWord){
        return steps;
    }

    //every time you get a word, for every character im doing a change
    for(int i=0;i<word.size();i++){
        char original=word[i]; //character that im looking to change
        for(char ch='a';ch<='z';ch++){ //change to character to anyone from a-z
            word[i]=ch;
            //if it exists in the set
            if(st.find(word)!=st.end()){ //if it does exist, it will never be pointing to the end
                st.erase(word);//marking it as visited
                q.push({word,steps+1});

            }
        }

        word[i]=original; //because eralier every time im changing for every character from a to z, I need to get my original word back
    }

}

return 0;

}