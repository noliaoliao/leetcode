class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> vRet;
        if(nums.size() == 0) return vRet;
        for(int i = 0; i < nums.size();i++){
            int j = i;
            string range = intToString(nums[j]);;
            while(j < nums.size() && nums[j] == nums[i]+j-i) j++;
            if(j != i+1){
                range += "->";
                range += intToString(nums[j-1]);
                i = j-1;
            }
            vRet.push_back(range);
        }

        return vRet;
    }

    string intToString(int val){
        char szBuf[32] = {0};
        sprintf(szBuf,"%d",val);
        return string(szBuf);
    }
};