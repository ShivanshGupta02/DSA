// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int kPalindrome(string str, int n, int k)
    {
        // code here
        
        // TC : O(N^2)
        
        // string s1 = str , s2 = string (str.rbegin(),str.rend());
       
        // vector<vector<int>>dp(n+1,vector<int>(n+1));
        
        // for(int i=1;i<=n;i++){
        //     dp[i][0] = i; dp[0][i] = i; 
        // }
        
        // for(int i=1; i<=n; i++){
        //     for(int j=1; j<=n; j++){
        //         if(s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1];
        //         else dp[i][j] = min(dp[i-1][j], dp[i][j-1])+1;
        //     }
        // }
        
        // return (dp[n][n]/2 <= k);
        
        
        int start = 0 , end = str.size()-1;
        
        if(str.size()==1) return 1;
        
        while(start < end){
            if(str[start]!=str[end]){
                if(k>0){
                    k--;
                    if(str[start]==str[end-1]) start--;
                    else end++;
                }
                else return 0;
            }
            start++;
            end--;
        }
     
     return 1;
        
    }
    
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.kPalindrome(str, n, k)<<endl;
    }
    return 0;
}  // } Driver Code Ends