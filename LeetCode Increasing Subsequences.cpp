class Solution {
public:
    map<vector<int>,bool>mark;
    vector<vector<int>>ans;

    //Find all possible subsequence of an array 

    void solve(int idx, vector<int>& nums, vector<int>& currSub, int n){
        if(idx==n){
            if(currSub.size()>1 and mark[currSub]==false){
                ans.push_back(currSub);
                mark[currSub]=true;
            }
            return;
        }
        solve(idx+1, nums, currSub, n);
        if(currSub.size()==0){
            currSub.push_back(nums[idx]);
            solve(idx+1, nums, currSub, n);
            currSub.pop_back();
        }
        else{
            if(nums[idx]>=currSub[currSub.size()-1]){
                currSub.push_back(nums[idx]);
                solve(idx+1, nums, currSub, n);
                currSub.pop_back();
            }
        }
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        int n=nums.size();
        vector<int>v;
        solve(0,nums,v,n);
        return ans;
    }
};




