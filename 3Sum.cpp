class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> v;
        if(nums.empty() || nums.size()<3)
            return v;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(i==0 || nums[i]!=nums[i-1]){
                int target=-nums[i];
                int start = i+1, end=nums.size()-1;
                while(start<end){
                    int sum=nums[start]+nums[end];
                    if(sum<target)
                        start++;
                    else if(sum> target)
                        end--;
                    else{
                        v.push_back({nums[i],nums[start],nums[end]});
                        int s=nums[start],e=nums[end];
                        while(start<end && nums[start]==s) start++;
                        while(start<end && nums[end]==e) end--;
                    }
                }    
            }
            
        }
        return v;
    }
};
