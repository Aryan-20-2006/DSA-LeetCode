//Problem-Word Search
//Difficulty-Hard

#include<bits/stdc++.h>
using namespace std;



bool find(vector<vector<char>>&board,string word, int i, int j, int index){

    //Base case-this means we have found our word
    if(index==word.size()){
        return true;
    }   

    //checking if its not out of bounds or if it has been visited

    if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][j]=='$'){
        return false;
    }

    if(board[i][j]!=word[index])
        return false;


    char temp=board[i][j];
    board[i][j]='$'; //this means it has been visited

    //Directions-up, down , left and right


    bool found= find(board,word,i+1,j,index+1) || //Down
                find(board,word,i-1,j,index+1) || //Up
                find(board,word,i,j+1,index+1) || //Right
                find(board,word,i,j-1,index+1);   //Left
    
    board[i][j]=temp; //while backtracking change it back to how it was

    return found;

}

bool exist(vector<vector<char>>&board, string word){

    int rows=board.size();
    int columns=board[0].size();

    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            if(board[i][j]==word[0] && find(board,word,i,j,0)){
                return true;
            }
        }
    }

return false;

}

