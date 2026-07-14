//Problem-Count good numbers
//Difficulty-Medium

#include<bits/stdc++.h>
using namespace std;



const int MOD=1e9 + 7;

int countGoodNumbers(int index,long long n) {
        // Your code goes here
        
        if(index==n)
            return 1; //the number is valid

       int count=0;

        if(index%2==0){
            for(int digit:{0,2,4,6,8}){
                count+=countGoodNumbers(index+1,n)%MOD;
            }
        }

        else{
            for(int digit:{2,3,5,7}){
                count+=countGoodNumbers(index+1,n)%MOD;
            }
        }

        return count;
    }


int main(){

    long long n=2;
    cout<<countGoodNumbers(0,n)<<"";
    return 0;
}