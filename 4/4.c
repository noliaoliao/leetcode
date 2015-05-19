double findMinKSortedArrays(int* nums1, int nums1Size, int *nums2, int nums2Size, int k){
    //保证nums1Size>nums2Size
    if(nums2Size > nums1Size) return findMinKSortedArrays(nums2, nums2Size, nums1, nums1Size, k);
    if(nums2Size == 0){
        return nums1[k-1];
    }
    if(k == 1){
        return nums1[0] < nums2[0] ? nums1[0] : nums2[0];
    }
    //将nums1 nums2分为两半
    int pNums2 = nums2Size > k/2 ? k/2 : nums2Size;
    int pNums1 = k - pNums2;
    if(nums2[pNums2-1] < nums1[pNums1-1]){
        //nums2的一半可以去掉
        return findMinKSortedArrays(nums1,nums1Size,nums2+pNums2,nums2Size-pNums2,k-pNums2);
    }else if(nums2[pNums2-1] > nums1[pNums1-1]){
        //nums1的一半可以去掉
        return findMinKSortedArrays(nums1+pNums1,nums1Size-pNums1,nums2,nums2Size,k-pNums1);
    }else{
        return nums2[pNums2-1];
        //or return nums1[pNums1-1];
        
    }
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    if(nums1Size <= 0 && nums2Size <= 0) return 0;
    if((nums1Size+nums2Size)&0x1){
        return findMinKSortedArrays(nums1,nums1Size,nums2,nums2Size,(nums1Size+nums2Size)/2+1);
    }else{
        return (findMinKSortedArrays(nums1,nums1Size,nums2,nums2Size,(nums1Size+nums2Size)/2)+\
             findMinKSortedArrays(nums1,nums1Size,nums2,nums2Size,(nums1Size+nums2Size)/2+1))/2;
    }
}