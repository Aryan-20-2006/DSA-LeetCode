//Problem-Task Scheduler
//Difficulty-Medium

#include<bits/stdc++.h>
using namespace std;

int leastInterval(vector<char>& tasks, int n){


unordered_map<char,int>freq; //this stores the char and freq

for(char task:tasks){
    freq[task]++;
}

//create a maxheap-since we eed the tasks with the highest frequencies
priority_queue<int>pq;

//push all the frequencies into the priority queue
for(auto it:freq){
    pq.push(it.second);
}

int time=0; //count the time for every task executed

while(!pq.empty()){

    vector<int>temp; //this stores the tasks being executed

    int cycles=n+1;

    int i=0;

    while(i<cycles && !pq.empty()){

        //pop the char with the highest frequency
        int cnt=pq.top();
        pq.pop();

        //every time you pop the char with that frequency , decrement the frequency
        cnt--;

        //if there is any remaining count left in the heap, push it into temp
        if(cnt>0)
            temp.push_back(cnt);

        time++;//increase the time for the task being exeuted

    }

    //after all this if there is anything left in the , push it into the heap
    for(int val:temp){
        pq.push(val); //this is where we push it from the temp into the heap
    }


    //finally when the heap becomes empty, come out of the loop

    if(pq.empty())
        break;

    //add the idle time before the cycle ends
    time+=(cycles-i);

    i++;
}

return time;

}