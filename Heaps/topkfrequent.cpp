//Problem-Top k frequent elements
//Difficulty-Medium

#include<bits/stdc++.h>
using namespace std;


//Brute Force-TC-O(nlogn), SC-O(n)
// vector<int> topKFrequent(vector<int>&nums, int k){

//     int n=nums.size();
//     unordered_map<int,int>map; //stores {num,freq};

//     for(int i=0;i<nums.size();i++){
//         map[nums[i]]++;
//     }

//     vector<int>result; //to store the top k frequent elements

//     //using a maxheap since we want top k frequent elements
//     priority_queue<pair<int,int>>pq; //{freq,num}

//     for(auto it:map){
//         pq.push({it.second,it.first}); //freq,num why> because priority queue sorts it by freq since that is the priority and based on freq, returns num
//     }

//     while(k>0 && !pq.empty()){
//         result.push_back(pq.top().second);
//         pq.pop();

//         k--;
//     }

// return result;

// }

//Optimal Solution-Using buckets
//TC-O(N),SC-O(N)
vector<int> topKFrequent(vector<int>&nums, int k){

    int n=nums.size();
    //create the buckets
    vector<vector<int>>buckets(n+1); //why 2d array?-because each index represents a frequency value

    //1.Find all the frequencies
    unordered_map<int,int>freq;

    //O(N)
    for(int i=0;i<nums.size();i++){
        freq[nums[i]]++; //{nums,freq}
    }

    //iterate through the freq map and group the elements based on frequencies-O(N)
    for(auto it:freq){
        buckets[it.second].push_back(it.first); //buckets[freq]={num}
    }

    //start filling the buckets from the end
    vector<int>result;

    for(int i=n;n>=0 && result.size()<k;i--){
        for(int num:buckets[i]){
            result.push_back(num);

            //we want only the k elements so if the reuslting array gets those elements , come out of the loop
            if(result.size()==k)
                break;
        }
    }
return result;


}

int main(){
    vector<int>nums={1,1,1,2,2,3,3,4};
    int k=2;
    vector<int>result=topKFrequent(nums,k);

    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }

    return 0;
}