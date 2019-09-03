//Remove elements in-place. Note that old implementations only calculated the size but did not modify the array
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        for(int i=0;i<nums.size();++i) {
            while(nums[i]==val&&i<nums.size()) {
                nums.erase(nums.begin()+i);
            }
        }
        return nums.size();
    }
};

/*Count the number only
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int count = 0;
        for(int i=0;i<nums.size();++i){
            if(nums[i]!=val)
                nums[i-count] = nums[i];
            else
                ++count;
        }
        return nums.size()-count;
    }
};

//Old Implementation
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int count = 0;
        for (int i=0;i<nums.size();++i) {
            if (nums[i]!=val) nums[count++] = nums[i];
        }
        return count;
    }
};
*/
