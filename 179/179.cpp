bool cmp(string str1, string str2){
    string s1 = str1+str2;
    string s2 = str2+str1;

    return s1.compare(s2) > 0;
}

class Solution{
public:
    string largestNumber(vector<int>& nums) {
        vector<string> v;
        for(int i = 0; i < nums.size(); i++){
            //将int转换为string
            char szBuf[32] = {0};
            sprintf(szBuf,"%d",nums[i]);
            string s(szBuf);
            v.push_back(s);
        }
        //排序,如果str1+str2 > str2+str1,则str1>str2
        sort(v.begin(),v.end(),cmp);
        
        string res;
        for(int i = 0; i < v.size(); i++){
            res += v[i];
        }
        //去掉前导0
        int cur = 0;
        while(res[cur] == '0' && cur < res.length()-1) cur++;
        return res.substr(cur,res.length());
    }
};