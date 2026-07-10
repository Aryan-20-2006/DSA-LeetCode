#include<bits/stdc++.h>
using namespace std;

// /*
//     struct NewType{
// };



// */


// //create a struct named Student, representing student's details and store the dataof the student

// /*String stream

//     vector<int> parseInts(string str){
    
//         stringStream ss(str);
//         vector<int> result;

//         int num;
//         char comma;

//         while(ss>>num){
//             result.push_back(num);
//             ss>>comma;

//         }

//         return result;
    
    
    
//     }


// */

// // class Sample{
// //     private:
// //         int val;
// //     public:
// //         void set(int a){
// //             val=a;
// //         }

// //         int get(){
// //             return val;
// //         }
// // };

// class Student{
//     private:
//         int age;
//         string first_name;
//         string last_name;
//         int standard;
//     public:
//         void set_age(int a){
//             age=a;
//         }

//         int get_age(){
//             return age;
//         }

//         void set_first_name(char b){
//             first_name=b;
//         }

//         string get_first_name(){
//             return first_name;
//         }

//         void set_last_name(string c){
//             last_name=c;
//         }

//         string get_last_name(){
//             return last_name;
//         }

//         void get_standard(int d){
//             standard=d;
//         }

//         int get_standard(){
//             return standard;
//         }

    
// string to_string_format(){

//     stringstream ss;
//     ss<<age<<","<<first_name<<","<<last_name<<","<<standard;

//     return ss.str();

// }

// };


// int removeDuplicates(vector<int>&nums){

//     int n=nums.size();

//     int i=0;

//     if(nums.size()==0){
//         return 0;
//     }

//     for(int j=1;j<n;i++){
//         if(nums[j]!=nums[i])
//             i++;
        
//         nums[i]=nums[j];
//     }

// return i+1;

// }

//Problem-Group Anagrams

vector<vector<string>> groupAnagrams(vector<string>& strs){

    unordered_map<string,vector<string>> map;

    int n=strs.size();

    for(int i=0;i<n;i++){

        vector<int>freq(26,0);

        //for each individual string, counting frequency of characters
        for(int j=0;j<strs[i].size();j++){
            freq[strs[i][j]-'a']++; //strs[i]-current word,j-every character in the current word

        }

        string key="";// because we need keys and we cant use arrays as keys

        //converting the numbers into string
        for(int k=0;k<26;i++){
            key+=to_string(freq[k])+"#"; //can use any separator
        }

        map[key].push_back(strs[i]);


    }


    vector<vector<string>>result;

    for(pair<string,vector<string>>p:map){
        result.push_back(p.second);
    }

    return result;


}

