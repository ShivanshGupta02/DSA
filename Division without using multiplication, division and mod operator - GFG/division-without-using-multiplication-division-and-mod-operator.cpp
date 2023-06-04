//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    long long divide(long long dividend, long long divisor) 
    {
        //code here
       
        bool pos = true;
        if(dividend<0 || divisor<0) pos = false;
        if(dividend<0 && divisor<0) pos = true;
        dividend = abs(dividend);
        divisor = abs(divisor);
        
        long long rem = dividend;
        long long quotient = 0;
        
        for(int i=31;i>=0;i--){
            if(rem >= (divisor<<i)){
                quotient |= (1<<i);
                rem -= (divisor<<i);
            }
        }
        
        
        return pos?quotient:-quotient;
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin >> t;

	while (t--)
	{

		long long a, b;
		cin >> a >> b;
		
		Solution ob;
		cout << ob.divide(a, b) << "\n";
	}

	return 0;
}

// } Driver Code Ends