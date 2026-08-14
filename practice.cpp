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

// vector<vector<string>> groupAnagrams(vector<string>& strs){

//     unordered_map<string,vector<string>> map;

//     int n=strs.size();

//     for(int i=0;i<n;i++){

//         vector<int>freq(26,0);

//         //for each individual string, counting frequency of characters
//         for(int j=0;j<strs[i].size();j++){
//             freq[strs[i][j]-'a']++; //strs[i]-current word,j-every character in the current word

//         }

//         string key="";// because we need keys and we cant use arrays as keys

//         //converting the numbers into string
//         for(int k=0;k<26;i++){
//             key+=to_string(freq[k])+"#"; //can use any separator
//         }

//         map[key].push_back(strs[i]);


//     }


//     vector<vector<string>>result;

//     for(pair<string,vector<string>>p:map){
//         result.push_back(p.second);
//     }

//     return result;


// }

//Problem-SubArray sum equals k
// int subarraysum(vector<int>&nums, int k){
//     int n=nums.size();

//     int count=0;

//     int sum=0;

//     unordered_map<int,int>map; // prefix sum and freq

//     map[0]=1;

//     for(int i=0;i<n;i++){
//         sum+=nums[i];

//         count+=map[sum-k]++;
        
//         map[sum]++;

//     }

//     return count;


// }

//Longest Substring without repeating characters
// int lengthOfLongestSubstring(string s){

//     int l=0;
//     int n=s.size();
//     int r=0;
//     int maxlen=0;

//     vector<int>hash(256,-1);

//     while(r<n){
//         if(hash[s[r]]!=-1){
//             if(hash[s[r]]>=l){
//                 l=hash[s[r]]+1;
//                 l=l+1;

//             }

//             hash[s[r]]=r;
//             int length=r-l+1;
//             maxlen=max(maxlen,length);
//             r++;
            
//         }
//     }

//     return maxlen;


// }

// int main(){
//     string s="abcabcbb";
//     cout<<lengthOfLongestSubstring(s)<<" ";
//     return 0;
// }


// //First negative in every window of size k
// vector<int>firstNegative(vector<int>&arr, int k){

//     vector<int>result;
//     int n=arr.size();

//     for(int i=0;i<=n-k;i++){
//         bool found=false; //initially no negative found
//         for(int j=i;j<i+k;i++){
//             if(arr[j]<0){
//                 result.push_back(arr[j]);
//                 found=true;
//             }

//             if(!found){
//                 result.push_back(0);
//             }
//         }
//     }


// return result;


// }

// vector<int>firstNegative(vector<int>&arr,int k){

//     vector<int>result;
//     queue<int>q;
//     int n=arr.size();

//     for(int i=0;i<n;i++){
//         if(arr[i]<0){
//             q.push(arr[i]); //push every negative element u find into the queue
//         }

//         //check if the window exists
//         if(i>=k-1){
//             //queue is empty
//             if(q.empty()){
//                 result.push_back(0);
//             }

//             else{
//                 result.push_back(q.front());
//             }


//             //if the queue is not empty
//             if(!q.empty() && q.front()==arr[i-k+1]){
//                 q.pop();
//             }
//         }

        
//     }

//     return result;


// }

// //Longest Subarray with Sum K
// int longestSubarray(vector<int>&arr, int k){

//     //{presum,index}
//     unordered_map<int,int>preSum;
//     int sum=0;
//     int maxlen=0;

//     for(int i=0;i<arr.size();i++){
//         sum+=arr[i];

//         if(sum==k){
//             maxlen=max(maxlen,i+1);
//         }

//         int rem=sum-k;
//         if(preSum.find(rem)!=preSum.end()){
//             int len=i-preSum[rem];
//             maxlen=max(maxlen,len);
//         }

//         if(preSum.find(sum)==preSum.end()){
//             preSum[sum]=i;
//         }
//     }

// return maxlen;


// }
