// 2022.05.15
class NumArray {
public:
    NumArray(vector<int>& nums): prefix(nums.size(), 0) {
        prefix[0] = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            prefix[i] = nums[i] + prefix[i - 1];
        }
    }
    
    int sumRange(int left, int right) {
        if(left == 0) {
            return prefix[right];
        }
        return prefix[right] - prefix[left - 1];
    }
private:
    vector<int> prefix;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */