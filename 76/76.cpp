class Solution {
public:
    string minWindow(string s, string t) {
        int htabTCharNums[256] = {0};
        int nTCharNums = t.length();
        for(int i = 0; i < nTCharNums; i++){
            htabTCharNums[t[i]]++;
        }

        int nFoundCharNums = 0;
        int htabWinCharNums[256] = {0};
        int nWinLeft = -1;
        int nWinRight = s.length();
        for(int nLeft = 0, nRight = 0; nRight < s.length(); nRight++){
            if(htabTCharNums[s[nRight]] != 0){
                htabWinCharNums[s[nRight]]++;
                if(htabWinCharNums[s[nRight]] <= htabTCharNums[s[nRight]]) nFoundCharNums++;
                //找到一个窗口
                if(nFoundCharNums == nTCharNums){
                    while(htabTCharNums[s[nLeft]] == 0 || htabTCharNums[s[nLeft]] < htabWinCharNums[s[nLeft]]){
                        //缩减这个窗口,当：
                        //当前要去掉的字符不在t中,或者
                        //当前要去掉的字符在窗口中的数量大于t中对应字符的数量
                        if(htabWinCharNums[s[nLeft]] != 0){
                            htabWinCharNums[s[nLeft]]--;
                        }
                        nLeft++;
                    }
                    //窗口的大小
                    if(nWinRight-nWinLeft > nRight-nLeft){
                        nWinLeft = nLeft;
                        nWinRight = nRight;
                    }
                    //去掉窗口最左边的字符,此时的窗口已经不满足条件了
                    htabWinCharNums[s[nLeft]]--;
                    nFoundCharNums--;
                    nLeft++;
                }
            }
        }

        return nWinLeft == -1 ? "" : s.substr(nWinLeft,nWinRight-nWinLeft+1);
    }
};