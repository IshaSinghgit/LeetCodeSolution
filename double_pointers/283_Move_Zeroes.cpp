// 2022.03.31
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slow = 0;
        for(int fast = 0; fast < nums.size(); fast++){
            if(nums[fast] != 0){
                nums[slow++] = nums[fast];
            }
        }
        for(int i = slow; i < nums.size(); i++){
            nums[i] = 0;
        }
    }
};

// 2022.04.19
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slow = 0;
        int fast = 0;
        while(slow <= fast && fast < nums.size()) {
            if(nums[fast] == 0) {
                fast++;
            }
            else {
                nums[slow] = nums[fast];
                slow++;
                fast++;
            }
        }
        for(int i = slow; i < nums.size(); i++) {
            nums[i] = 0;
        }
    }
};