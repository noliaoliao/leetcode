int jump(int* nums, int numsSize){
    int ret = 0;
    int last = 0;
    int curr = 0;
    for (int i = 0; i < numsSize; i++) {
        if (i > last) {
            last = curr;
            ++ret;
        }
        curr = max(curr, i+A[i]);
    }

    return ret;
}