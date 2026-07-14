//Problem-Power(x,n)
//Difficulty-Easy

#include<bits/stdc++.h>
using namespace std;

double myPow(double x, int n){

    //base case
    if(n==0)
        return 1;

    return x * myPow(x,n-1);


}

int main(){
    double x=2.0000;
    int n=10;
    cout<<myPow(x,n)<<" ";
    return 0;
}