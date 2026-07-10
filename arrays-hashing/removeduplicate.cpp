//Problem:Remove Duplicates from Sorted Array
//Difficulty:Easy

/*you have integer array nums
you have to remove the duplicates in place such that each unique element appears only once
number of unique elements in nums is k
after removing duplicates, return the number of unique elements
the remaining elements beynd index k-1 can be ignored
eg:- nums=[1,1,2]
nums=[1,2,_]

nums=[0,0,1,1,1,2,2,3,3,4]
nums=[0,1,2,3,4,_,_,_,_,_]

My thought process
- using the concept of two pointers
- here there is only one array
- both the pointers start at the first index
- one thing I can see is that empty space is filled up after sorting the unique elements
- if I were to compare the first and last positions i.e 0 and 4 then obviously 0 comes before four 
- then I move the pointer to right but I encounter another 0, so we ignore it
- then compare 1 and 4, 1 is less than 4 so the order is correct
- Similarly I do it for the rest and ignore the rest
- but how do I ignore the rest?





*/



/*
Optimal solution
TC-O(n) since we're using only two indices
SC-O(1) extra space is not being used because of the two indices

nums=[0,0,1,1,1,2,2,3,3,4]

Suppose I have two pointers , lets say i and j
let them both start at the index 1
i pointer is used for scanning the array
j is used for overwriting values
it would make sense to start at i=1 since 0 at i=0 is supposed to be there
now move i to the right you find 1 which is not a duplicate element
so u replace the 0 by 1 i.e you overwrite the element at position j with that of i
after doing that you move j to right and then move i to the right
again 1 and 1 they both are duplicate, so you dont move j, you move i, keep doing this until u reach 2
then 1 and 2 , replace 1 by 2 and move j and this process continues
finally you return j which gives the number of unique elements(since we started j=1 so j reaches at index 5 onces all the unique elements are found so we get 5)
*/

// #include<bits/stdc++.h>
// using namespace std;



// int removeDuplicates(vector<int>&nums){

//     int n=nums.size();

//     int k=1; // this index is used for overwriting

//     for(int i=1;i<n;i++){ //here im starting with i=1 i.e the first index cuz anyways the first element i.e 0 should be there 
//         if(nums[i]!=nums[i-1]){  //if there are no duplicated elements
//             nums[k]=nums[i];
//             k++;
//         }

//     }

//     return k;


// }

// int main(){

//     vector<int>nums={0,1,0,3,12};
//     cout<<removeDuplicates(nums)<<endl;
//     return 0;


// }

