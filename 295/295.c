class MedianFinder {
public:
    MedianFinder(){
		//初始化建立一个最大堆
        make_heap(max.begin(),max.end());
		//一个最小堆
        make_heap(min.begin(),min.end(),greater<int>());
    }
    // Adds a number into the data structure.
    void addNum(int num) {
		//都为空,压入最大堆,也可压入最小堆
		//如果最大堆的堆顶元素大于要插入的元素
		//则将这个元素压入最大堆中
        if(max.size() == 0 || max[0] >= num){
            max.push_back(num);
            push_heap(max.begin(),max.end());
			//最大最小堆不平衡,取出最大堆的堆顶元素压入到最小堆中
            if(max.size()-min.size() > 1){
                //int top = max.begin();
                pop_heap(max.begin(),max.end());
                int top = max.back();
                max.pop_back();
                min.push_back(top);
                push_heap(min.begin(),min.end(),greater<int>());
            }
        }else{
			//最小堆操作类似
			//主要是维护两个堆的平衡
            min.push_back(num);
            push_heap(min.begin(),min.end(),greater<int>());
            if(min.size()-max.size() > 1){
                pop_heap(min.begin(),min.end(),greater<int>());
                int top = min.back();
                min.pop_back();
                max.push_back(top);
                push_heap(max.begin(),max.end());
            }
        }
    }

    // Returns the median of current data stream
    double findMedian() {
		//堆元素相同,偶数个,两个堆堆顶元素相加/2
		//否则就是堆大的堆顶元素
        if(max.size() == 0 && max.size() == 0){
            return 0;
        }else if(max.size() > min.size()){
            return max.front();
        }else if(max.size() == min.size()){
            return ((double)(max.front()+min.front()))/2.0;
        }else{
            return min.front();
        }
    }
private:
    vector<int> max;
    vector<int> min;
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();