/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
bool mycmp(Interval s1, Interval s2){
    return s1.start < s2.start;
}

class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {  
        vector<Interval> vRet;  
        sort(intervals.begin(),intervals.end(),mycmp);  
        int left = -1;
        int right = -1;
        int nlen = intervals.size();  
        for(int i = 0; i < nlen; i++)  
        {              
            if(intervals[i].start<=right)  
            {  
                right=max(right,intervals[i].end);  
            }  
            else  
            {  
                if(left != -1){
                    vRet.push_back(Interval(left,right));
                }
                left = intervals[i].start;  
                right = intervals[i].end;  
            }  
        }
        //最后一个元素也要压入
        if(left != -1){
            vRet.push_back(Interval(left,right));
        }
        return vRet;  
    }

    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        intervals.push_back(newInterval);
        return merge(intervals);
    }
};