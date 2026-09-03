class Solution {
public:
    
vector<int> twoSum(vector<int>& nums, int target) {   // O(n^2) solution
        for(int i = 0; i < nums.size(); i++) {    // O(n) solution
            for(int j = i + 1; j < nums.size(); j++) {   // O(n) solution
                if(nums[i] + nums[j] == target) {      // O(1) solution
                   
                    return {i, j};        // O(1) solution
                }
            }
        }
        return {};
    }
};
