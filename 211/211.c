struct WordDictionary {
   char val;
   bool isWord;
   struct WordDictionary* child[26];    
};

/** Initialize your data structure here. */
struct WordDictionary* wordDictionaryCreate() {
    struct WordDictionary* head = (struct WordDictionary*)malloc(sizeof(struct WordDictionary));
    head->isWord =  false;
    memset(head->child,0,sizeof(struct WordDictionary*)*26);

    return head;
}

/** Inserts a word into the data structure. */
void addWord(struct WordDictionary* wordDictionary, char* word) {
    if(wordDictionary == NULL) return;
    struct WordDictionary* pCur = wordDictionary;
    int len = strlen(word);
    for(int i = 0; i < len; i++){
        if(pCur->child[word[i]-'a'] == NULL){
            pCur->child[word[i]-'a'] = (struct WordDictionary*)malloc(sizeof(struct WordDictionary));
            pCur->child[word[i]-'a']->isWord = false;
            memset(pCur->child[word[i]-'a']->child,0,sizeof(struct TrieNode*)*26);
        }
        pCur->child[word[i]-'a']->val = word[i];
        pCur = pCur->child[word[i]-'a'];
    }
    pCur->isWord = true;
}

/** Returns if the word is in the data structure. A word could
    contain the dot character '.' to represent any one letter. */
bool search(struct WordDictionary* wordDictionary, char* word) {
    if(wordDictionary == NULL) return false;
    struct WordDictionary* pCur = wordDictionary;
    int len = strlen(word);

    for(int i = 0; i < len; i++){
        if(word[i] == '.'){
            bool ret = false;
            //逐个匹配
            for(int j = 0; j < 26; j++){
                if(pCur->child[j] != NULL){
                    if(i == len-1){
                        ret |= pCur->child[j]->isWord;
                    }else{
                        ret |= search(pCur->child[j],&word[i+1]);
                    }
                }
            }
            return ret;
        }else{
            if(pCur->child[word[i]-'a'] == NULL) return false;
            pCur = pCur->child[word[i]-'a'];
        }
    }

    return pCur == NULL ? false : pCur->isWord;   
}

/** Deallocates memory previously allocated for the data structure. */
void wordDictionaryFree(struct WordDictionary* wordDictionary) {
    if(wordDictionary == NULL) return;
    for(int i = 0; i < 26; i++){
        if(wordDictionary->child[i] != NULL){
            wordDictionaryFree(wordDictionary->child[i]);
            //printf("%c ",root->child[i]->val);
            free(wordDictionary->child[i]);
            wordDictionary->child[i] = NULL;
        }
    }    
}