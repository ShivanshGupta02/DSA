// -------------- ONE PASS SOLUTION -------------
class Solution {
    // TC : O(N)
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int candy = n;
        int i = 1;
        while(i<n){
            if(ratings[i]==ratings[i-1]){
                i++; continue;
            }

            // processing increasing slope
            int peak = 0;
            while(ratings[i-1] < ratings[i]){
                peak++;
                candy += peak;
                i++; 
                if(i==n) return candy;
            }

            // processing decreasing slope
            int valley = 0;
            while(i<n && ratings[i-1] > ratings[i]){
                valley++;
                candy += valley;
                i++;
            }
            candy -= min(peak, valley);
        }
        return candy;

    }
};

//  ------------------ THREE PASS (ACTUALLY TWO PASS)  METHOD ----------
class Solution1 {
    // TC : O(N)
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int>res(n);
        vector<int>left(n), right(n);
        for(int i=0;i<n;i++){
            int left_rating = (i-1>=0)? ratings[i-1] : 0;
            int right_rating = (i+1<n)? ratings[i+1] : 0;
            
            if(ratings[i] < left_rating && ratings[i] < right_rating){
                left[i] = 1;
            }
            else if(left_rating < ratings[i]){
                left[i] = (i>0?left[i-1]:0) + 1;
            }
            else if(left_rating == ratings[i]){
                left[i] = 1;
            }
        }
        for(int i=n-1; i>=0;i--){
            int left_rating = (i-1>=0)? ratings[i-1] : 0;
            int right_rating = (i+1<n)? ratings[i+1] : 0;

            if(ratings[i] < left_rating && ratings[i] < right_rating){
                right[i] = 1;
            }
            else if(ratings[i] > right_rating){
                right[i] = (i+1<n? right[i+1] : 0) + 1;
            }
            else if(ratings[i] == right_rating){
                right[i] = 1;
            }
        }
        int cnt = 0;
        for(int i=0;i<n;i++){
            res[i] = max(left[i], right[i]);
            cnt += res[i];
            // cout<<res[i]<<" ";
        }
        return cnt;

    }
};