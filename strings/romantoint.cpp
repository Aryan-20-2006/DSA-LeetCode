//Problem-Roman to Integer
//Difficulty-Medium

/*I = 1
V = 5
X = 10
L = 50
C = 100
D = 500
M = 1000
*/

#include<bits/stdc++.h>
using namespace std;

int romantoint(string s){

    unordered_map<char,int>map={{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
    
    int n=s.size();
    int result=0;

    
    for(int i=0;i<n-1;i++){ //adding everything except the last character
        if(map[s[i]]<map[s[i+1]]){
            result-=map[s[i]];
        }

        else{
            result+=map[s[i]];
        }

    }

return result+map[s.back()];

}

int main(){

    string s="III";
    cout<<romantoint(s)<<" ";
    return 0;

}