int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize) {
    int nGasSum = 0;     //�Ӽ�����ʼgas���ܺ�
    int nGasTotal = 0;   //һ������gas��ʣ����
    int start = -1;      //���

    /**
    *���κ�һ�㿪ʼ����,��ʣ��gas��С��0ʱ,���¿�ʼ�� 
    *�������ʣ�µ����gas���ڵ�0,˵������������һ��
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