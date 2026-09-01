int longestKSubstr(string &s, int k){

//     int n=s.size();
//     int maxlen=0;
    
  

//     for(int i=0;i<n;i++){

//         unordered_map<char,int>map; //we are tracking the distinct character so this has to update

//         for(int j=i;j<n;j++){
//             map[s[j]]++;


//             //if the no of distinct characters exceed k
//             if(map.size()>k){
//                 break;
//             } 

//             int len=j-i+1;
//             maxlen=max(maxlen,len);
//         }

//     }

//     return maxlen;

// }