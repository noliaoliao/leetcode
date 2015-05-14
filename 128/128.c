//最长连续序列
//利用map实现,还不是最优的

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int nMaxLong = 0;
        map<int, int> htab;
        for(int i = 0; i < nums.size(); i++){
           htab[nums[i]] = 1;
        }
        for(int i = 0; i < nums.size(); i++){
            int tmp = 1;
            for(int j = 1; j < nums.size(); j++){
                //int x = htab[nums[i]+2];
                if(htab[nums[i]+j] != 1) break;
                tmp++;
                htab[nums[i]+j] = 0;
            }
            for(int j = 1; j < nums.size(); j++){
                if(htab[nums[i]-j] != 1) break;
                tmp++;
                htab[nums[i]-j] = 0;
            }
            if(tmp > nMaxLong) nMaxLong = tmp;
        }

        return nMaxLong;
    }
};