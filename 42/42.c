int trap(int* height, int heightSize) {
    int nTotalRains = 0;
    int i = 0;
    while(i < heightSize-2){
        //找到一个波峰点
        if(height[i] > height[i+1]){
            int nEachRains = 0;
            int j = i+1;
            while(j < heightSize){
                if(height[j] >= height[i]){
                    nTotalRains += nEachRains;
                    i = j;
                    break;
                }else{
                    nEachRains += (height[i]-height[j]);
                }
                j++;
            }
            //判断有没有后续波峰比当前大的
            if(j == heightSize){
                int nMaxCur = i;
                i = heightSize-1;
                while(i > nMaxCur){
                    if(height[i] > height[i-1]){
                        int nEachRains = 0;
                        int j = i-1;
                        while(j >= nMaxCur){
                            if(height[j] >= height[i]){
                                nTotalRains += nEachRains;
                                i = j;
                                break;
                            }else{
                                nEachRains +=(height[i]-height[j]);
                            }
                            j--;
                        }
                    }else{
                        i--;
                    }
                }
                break;
            }
        }else{
            i++;
        }
    }
    return nTotalRains;
}