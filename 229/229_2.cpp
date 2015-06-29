class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        //统计个数
        //O(n)
        unordered_map<int,int> hmap;
        for(int i = 0; i < nums.size(); i++){
            if(hmap.find(nums[i]) != hmap.end()){
                hmap[nums[i]]++;
            }else{
                hmap[nums[i]] = 1;
            }
        }

        vector<int> ret;
        unordered_set<int> hset;
        //找出不重复的大于n/3的元素
        //O(n)
        for(int i = 0; i < nums.size(); i++){
            if(hmap[nums[i]] > nums.size()/3 && hset.find(nums[i]) == hset.end()){
                ret.push_back(nums[i]);
                hset.insert(nums[i]);
            }
        }

        return ret;
    }
};