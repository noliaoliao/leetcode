class Solution {
public:
   void getAllCombine(int start, int end, int k, vector<int> vEach, vector<vector<int>> &vAll){
        if(vEach.size() == k){
            vAll.push_back(vEach);
            return;
        }
        for(int i = start; i < end; i++){
            //vEach.clear();
            vEach.push_back(i);
            getAllCombine(i+1,end,k,vEach,vAll);
            vEach.pop_back();
        }
    } 

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> vRet;
        vector<int> vEach;
        getAllCombine(1,n+1,k,vEach,vRet);
        return vRet;
    }
};