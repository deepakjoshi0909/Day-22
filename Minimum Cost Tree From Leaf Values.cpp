class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int ans = 0;
        stack<int>s;

        s.push(INT_MAX);
        
        for(int i=0;i<arr.size();i++){
            while(s.top() <= arr[i]){
                int mid = s.top();
                s.pop();
                ans += mid * min(s.top(),arr[i]);
            }
            s.push(arr[i]);
        }

        while(s.size() > 2){
            int mid = s.top();
            s.pop();
            ans += mid * s.top();
        }

        return ans;
    }
};
