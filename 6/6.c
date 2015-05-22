char* convert(char* s, int numRows) {
    int len = strlen(s);
    if(len <= numRows || numRows == 1) return s;
    char *ret = (char *)malloc(sizeof(char)*(len+1));

    //依次生成每一层
    int nRetIndex = 0;
    for(int i = 0; i < numRows; i++){
        int index = i;
        int inc = i*2;
        while(index < len){
            ret[nRetIndex++] = s[index];
            int nAdd = (numRows-1)*2 - inc;
            inc = (nAdd == 0 ? (numRows-1)*2 : nAdd);
            index += inc;
        }
    }
    ret[len] = '\0';
    
    return ret;
}