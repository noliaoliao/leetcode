class Solution {
public:
    int compareVersion(string version1, string version2) {
        int v1End = version1.length()-1;
        int v1Begin = beginZero(version1) > v1End ? v1End : beginZero(version1);
        int v2End = version2.length()-1;
        int v2Begin = beginZero(version2) > v2End ? v2End : beginZero(version2);
        int i = v1Begin;
        int j = v2Begin;

        while(i <= v1End && j <= v2End){
            string v1;
            bool flag = true;
            while(i <= v1End){
                if(version1[i] == '.'){
                    i++;
                    break;
                }
                if(version1[i] == '0' && flag){
                    i++;
                    continue;
                }
                v1 += version1[i];
                flag = false;
                i++;
            }
            string v2;
            flag = true;
            while(j <= v2End){
                if(version2[j] == '.'){
                    j++;
                    break;
                }
                if(version2[j] == '0' && flag){
                    j++;
                    continue;
                }
                v2 += version2[j];
                flag = false;
                j++;
            }

            if(v1.length() > v2.length()) return 1;
            if(v1.length() < v2.length()) return -1;
            for(int start = 0; start < v1.length(); start++){
                if(v1[start] == v2[start]) continue;
                return v1[start] > v2[start] ? 1 : -1;
            } 
        }

        if(i == version1.length() && j == version2.length()) return 0;
        //判断末尾是不是.00.0.00格式
        bool flag = true;
        if(version1.length() > version2.length()){
            for(int start = i; start < version1.length(); start++){
                if(version1[start] == '.') continue;
                if(version1[start] != '0'){
                    flag = false;
                    break;
                }
            }
        }else{
            for(int start = j; start < version2.length(); start++){
                if(version2[start] == '.') continue;
                if(version2[start] != '0'){
                    flag = false;
                    break;
                }
            }
        }
        if(flag) return 0;
        else return i < version1.length() ? 1 : -1;
    }

    int beginZero(string s){
        for(int i = 0, j = 0; i < s.length(); i++){
            if(s[i] != '0') return i;
        }
        return s.length();
    }
};