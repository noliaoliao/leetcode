//Unique Binary Search Trees
//任意一个点做根节点,二叉搜索树的数目为左搜索树*右搜素树
int numTrees(int n) {
    if(n < 1) return 0;
    if(n < 2) return 1;
    int *nums = (int *)malloc(sizeof(int)*(n+1));
    nums[0] = 1;
    nums[1] = 1;
    for(int i = 2; i <= n; i++){
        for(int j = 0; j < i; j++){
            nums[i] = nums[j]*nums[i-j-1]+nums[i];
        }
    }
    return nums[n];
}