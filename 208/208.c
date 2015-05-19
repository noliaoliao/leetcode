struct TrieNode {
   char val;                        //节点值
   bool isWord;                     //是否为单词
   struct TrieNode* child[26];      //26个孩子(a-z)  
};

/** Initialize your data structure here. */
struct TrieNode* trieCreate() {
    struct TrieNode* head = (struct TrieNode*)malloc(sizeof(struct TrieNode));
    head->isWord =  false;
    memset(head->child,0,sizeof(struct TrieNode*)*26);
    return head;
}

/** Inserts a word into the trie. */
void insert(struct TrieNode* root, char* word) {
    if(root == NULL) return;
    struct TrieNode* pCur = root;
    int len = strlen(word);
    for(int i = 0; i < len; i++){
        if(pCur->child[word[i]-'a'] == NULL){
            pCur->child[word[i]-'a'] = (struct TrieNode*)malloc(sizeof(struct TrieNode));
            pCur->child[word[i]-'a']->isWord = false;
            memset(pCur->child[word[i]-'a']->child,0,sizeof(struct TrieNode*)*26);
        }
        pCur->child[word[i]-'a']->val = word[i];
        pCur = pCur->child[word[i]-'a'];
    }
    pCur->isWord = true;
}

/** Returns if the word is in the trie. */
bool search(struct TrieNode* root, char* word) {
    if(root == NULL) return false;
    struct TrieNode* pCur = root;
    int len = strlen(word);

    for(int i = 0; i < len; i++){
        if(pCur->child[word[i]-'a'] == NULL) return false;
        pCur = pCur->child[word[i]-'a'];
    }

    return pCur->isWord;
}

/** Returns if there is any word in the trie 
    that starts with the given prefix. */
bool startsWith(struct TrieNode* root, char* prefix) {
    if(root == NULL) return false;
    struct TrieNode* pCur = root;
    int len = strlen(prefix);

    for(int i = 0; i < len; i++){
        if(pCur->child[prefix[i]-'a'] == NULL) return false;
        pCur = pCur->child[prefix[i]-'a'];
    }

    return true;
}

/** Deallocates memory previously allocated for the TrieNode. */
void trieFree(struct TrieNode* root) {
    if(root == NULL) return;
    for(int i = 0; i < 26; i++){
        if(root->child[i] != NULL){
            trieFree(root->child[i]);
            //printf("%c ",root->child[i]->val);
            free(root->child[i]);
            root->child[i] = NULL;
        }
    }
}