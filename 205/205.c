bool isIsomorphic(char* s, char* t) {
    int hTab1[256] = {0};
    int hTab2[256] = {0};
    int len = strlen(s);
    for(int i = 0; i < len; i++){
        //建立映射的同时判断是否有非法的映射
        //1.一个字符映射到两个字符
        //2.两个字符映射到同一字符
        if(hTab1[s[i]] != hTab2[t[i]]) return false;
        hTab1[s[i]] = i+1;
        hTab2[t[i]] = i+1;
    }

    return true;
}