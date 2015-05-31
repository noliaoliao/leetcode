int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize) {
    int nGasSum = 0;     //从计数开始gas的总和
    int nGasTotal = 0;   //一趟下来gas的剩余量
    int start = -1;      //起点

    /**
    *从任何一点开始出发,当剩余gas量小于0时,重新开始走 
    *最终如果剩下的如果gas大于等0,说明可以完整走一趟
    */
    for(int i = 0; i < gasSize; i++){
        nGasSum += (gas[i]-cost[i]);
        nGasTotal += (gas[i]-cost[i]);
        if(nGasSum < 0){
            nGasSum = 0;
            start = i;
        }
    }

    return nGasTotal >= 0? start+1 : -1;
}