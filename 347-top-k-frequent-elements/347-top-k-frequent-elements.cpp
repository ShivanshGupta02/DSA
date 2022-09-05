// TC : O(n log(n-k))

// ----------- USING MAX HEAP -------------

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        // max heap
        priority_queue<pair<int,int>>pq;
        vector<int>res;
        for(auto it=mp.begin();it!=mp.end();it++){
            pq.push(pair(it->second,it->first));
            if(pq.size() > mp.size()-k){
                res.push_back(pq.top().second);
                pq.pop();
                if(res.size()==k)return res;
            }
        }
        return res;
    }
};

// ----------- USING MIN HEAP --------------

// class point{
//     public:
//     int freq;
//     int val;
//     public:
//     point(int x, int y){
//         this->freq = x;
//         this->val = y;
//     }
// };

// class comp{
//   public:
//     bool operator()(const point & p1, const point & p2){
//         return (p1.freq > p2.freq);
//     }
// };

// // TC : O(n logk)
// class Solution {
// public:
//     vector<int> topKFrequent(vector<int>& nums, int k) {
       
//         // min heap
//         priority_queue<point,vector<point>,comp>pq;
//         unordered_map<int,int>mp;
//         vector<int>res;
        
//         for(int i=0;i<nums.size();i++){
//             mp[nums[i]]++;
//         }
        
//         for(auto it=mp.begin();it!=mp.end();it++){
//             if(pq.size()<k){
//                 pq.push(point(it->second,it->first));
//             }
//             else{
//                 point top = pq.top();
//                 if(top.freq < it->second){
//                     pq.pop();
//                     pq.push(point(it->second,it->first));
//                 }
//             }
//         }
        
//         while(!pq.empty()){
//             // cout<<pq.top().val << " --  "<<pq.top().freq<<endl;
//             res.push_back(pq.top().val);
//             pq.pop();
//         }
        
//         return res;
        
//     }
// };


// class point{
//     public:
//     int freq;
//     int val;
//     public:
//     point(int x, int y){
//         this->freq = x;
//         this->val = y;
//     }
// };

// class comp{
//   public:
//     bool operator()(const point & p1, const point & p2){
//         return (p1.freq > p2.freq);
//     }
// };

// // TC : O(n logk)
// class Solution {
// public:
//     vector<int> topKFrequent(vector<int>& nums, int k) {
       
//         // min heap
//         priority_queue<point,vector<point>,comp>pq;
//         unordered_map<int,int>mp;
//         vector<int>res;
        
//         for(int i=0;i<nums.size();i++){
//             mp[nums[i]]++;
//         }
        
//         for(auto it=mp.begin();it!=mp.end();it++){
//             if(pq.size()<k){
//                 pq.push(point(it->second,it->first));
//             }
//             else{
//                 point top = pq.top();
//                 if(top.freq < it->second){
//                     pq.pop();
//                     pq.push(point(it->second,it->first));
//                 }
//             }
//         }
        
//         while(!pq.empty()){
//             // cout<<pq.top().val << " --  "<<pq.top().freq<<endl;
//             res.push_back(pq.top().val);
//             pq.pop();
//         }
        
//         return res;
        
//     }
// };