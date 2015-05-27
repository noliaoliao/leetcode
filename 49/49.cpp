struct StringPair{
    string ori;
    string sorted;
    StringPair() : ori(NULL),sorted(NULL) {};
    StringPair(string s1,string s2) : ori(s1),sorted(s2) {}
};

bool cmp(StringPair s1, StringPair s2){
    return s1.sorted.compare(s2.sorted) < 0;
}

class Solution {
public:
    vector<string> anagrams(vector<string>& strs){
        vector<string> vRet;
        if(strs.size() <= 1) return vRet;
        vector<StringPair> stringPairs;
        //对strs中每一个str排序
        for(int i = 0; i < strs.size(); i++){
            StringPair currPair(strs[i],strs[i]);
            sort(currPair.sorted.begin(),currPair.sorted.end());
            stringPairs.push_back(currPair);
        }
        //按照排序好的str对整个vector排序
        sort(stringPairs.begin(),stringPairs.end(),cmp);
        //遍历排序好的vector,查找变为词

        bool flag = true;
        for(int i = 1; i < stringPairs.size(); i++){
            if(stringPairs[i].sorted.compare(stringPairs[i-1].sorted) == 0){
                if(flag == true){
                    vRet.push_back(stringPairs[i-1].ori);
                    flag = false;
                }
                vRet.push_back(stringPairs[i].ori);
            }else{
                flag = true;
            }
        }

        return vRet;
    }
};