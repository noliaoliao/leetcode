class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> vRes;
        if(s.size() < 10) return vRes;

        unordered_map<int,int> hset;
        unordered_map<char,int> hmap;
        hmap['A'] = 0;
        hmap['C'] = 1;
        hmap['G'] = 2;
        hmap['T'] = 3;
        int nDNA = 0;
        for(int i = 0; i < 10; i++){
            nDNA = (nDNA << 2) | hmap[s[i]];
        }
        hset[nDNA] = 0;

        for(int i = 10; i < s.length(); i++){
            nDNA = ((nDNA & 0x3FFFF) << 2 | hmap[s[i]]);
            unordered_map<int,int>::iterator iter = hset.find(nDNA);
            if(iter != hset.end()){
                if(iter->second == 0){
                    vRes.push_back(s.substr(i-9,10));
                    iter->second++;
                }
            }else{
                hset[nDNA] = 0;
            }
        }

        return vRes;
    }
};