int romanToInt(char* s) {
    //I（1）、V（5）、X（10）、L（50）、C（100）、D（500）、M（1000）
    int htab[26] = {0};
    htab['I'-'A'] = 1;
    htab['V'-'A'] = 5;
    htab['X'-'A'] = 10;
    htab['L'-'A'] = 50;
    htab['C'-'A'] = 100;
    htab['D'-'A'] = 500;
    htab['M'-'A'] = 1000;

    int len = strlen(s);
    if(len <= 0) return 0;
    int ret = htab[s[len-1]-'A'];
    for(int i = len-2; i >= 0; i--){
        if(htab[s[i+1]-'A'] <= htab[s[i]-'A']){
            ret += htab[s[i]-'A'];
        }else{
            ret -= htab[s[i]-'A'];
        }
    }

    return ret;
}