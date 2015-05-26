int findKthMax(int left, int right, int *nums, int k){
    int i = left;
    int j = right;
    int tmp = nums[left];
    if(i > j) return 0;
    //进行一趟快排
    while(i != j){
        while(j > i && tmp <= nums[j]) j--;
        while(i < j && tmp >= nums[i]) i++;
        if(i < j){
            nums[i] = nums[i] ^ nums[j];
            nums[j] = nums[i] ^ nums[j];
            nums[i] = nums[i] ^ nums[j];
        }
    }
    nums[left] = nums[i];
    nums[i] = tmp;
    
    if(right-j+1 == k){
        //nums[j]刚好是第k大的数
        return nums[j];
    }else if(right-j+1 > k){
        //比nums[j]大的数数量大于k
        //那么在j的右边继续找第k大的数
        return findKthMax(j+1,right,nums,k);
    }else{
        //不然在j的左边找k-(right-j+1)大的数
        return findKthMax(left,j-1,nums,k+j-right-1);
    }

}

int findKthLargest(int* nums, int numsSize, int k) {
    if(nums == NULL || numsSize <= 0 || k <= 0) return 0;
    return findKthMax(0,numsSize-1,nums,k);
}