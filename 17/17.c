char** letterCombinations(char* digits, int* returnSize) {
    char szBuf[10][5] = {
        {32},
        {32},
        {"abc"},
        {"def"},
        {"ghi"},
        {"jkl"},
        {"mno"},
        {"pqrs"},
        {"tuv"},
        {"wxyz"}};
    int tab[] = {1,1,3,3,3,3,3,4,3,4};
    int len = strlen(digits);
    if(len == 0) return NULL;
    *returnSize = tab[digits[0]-'0'];
    for(int i = 1; i < len; i++){
        (*returnSize) *= (tab[digits[i]-'0']);
    }
    
    char **ret = (char **)malloc(sizeof(char *)*(*returnSize));
    for(int i = 0; i < *returnSize; i++){
        *(ret+i) = (char *)malloc(sizeof(char)*(len+1));
        memset(*(ret+i),0,sizeof(char)*(len+1));
    }

    int nRepTime = *returnSize;
    for(int i = 0; i < len; i++){
        int nNumsLen = tab[digits[i]-'0'];
        char *nums = szBuf[digits[i]-'0'];
        nRepTime /= nNumsLen;
        for(int j = 0; j < *returnSize; j++){
            int index = (j/nRepTime)%nNumsLen;
            ret[j][i] = nums[index];
        }
    }

    return ret;
}