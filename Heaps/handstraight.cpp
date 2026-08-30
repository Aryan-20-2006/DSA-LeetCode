//Problem-Hand of straights
//Difficulty-Medium

#include<bits/stdc++.h>
using namespace std;

//TC-O(NlogN), SC-(O(N))
bool isNStraightHand(vector<int>&hand, int groupSize){

    //if the size of the hand array is not divisble by the group size, then it is not possible to form groups

    if(hand.size()%groupSize!=0)
        return false;

    //since we need elements in the sorted order , instead of sorting the array we'll use a sorted map
    map<int,int>map;//this stores {int,freq}

    //iterate through the map and count the frequency
    for(int i=0;i<hand.size();i++){
        map[hand[i]]++; 
    }

    //correct syntax here (throws a warning otherwise) can also be written as auto [it,freq]:map
    for(auto it=map.begin();it!=map.end();it++){

        int key=it->first;
        int freq=it->second;

        //we will try to place the elements oursleves until the freq becomes zero   
        if(freq==0)
            continue; //if the freq becomes zero, we will skip the iteraton and go the next element and decrease its frequency

        while(freq>0){
            for(int curr=key;curr<key+groupSize;curr++){ //Eg: Im at 1 , curr=1, key+groupSize=4 so my first group will have element 1,2,3
                
                //if the key your looking for isnt in the map or if the key is in the map but we used up all the copies
                if(map.find(curr)==map.end() || map[curr]<=0){
                    return false;
                }

                map[curr]--; //decrease the frequency as you iterate

            }
            freq--;
        }

    }

    return true;

}


int main(){
    vector<int>hand={1,2,3,6,2,3,4,7,8};
    int groupSize=3;
    cout<<isNStraightHand(hand,groupSize);
    return 0;
}