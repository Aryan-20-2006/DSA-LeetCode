//Problem-Assign Cookies
//Difficulty-Easy

#include<bits/stdc++.h>
using namespace std;

int findMaximumCookieStudents(vector<int>&student, vector<int>&cookie){

    int l=0;
    int r=0;
    int m=cookie.size();
    int n=student.size();

    sort(student.begin(),student.end());
    sort(cookie.begin(),cookie.end());

    while(l<m && r<n){

        if(student[r]<=cookie[l]){
            r=r+1;
        }

        l=l+1;


    }

    return r;
}

int main(){

    vector<int>student={1,2,3};
    vector<int>cookie={1,1};
    cout<<findMaximumCookieStudents(student,cookie)<<" ";
    return 0;

}