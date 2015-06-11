class Stack {
public:

    // Push element x onto stack.
    void push(int x) {
        //总是push进非空的队列
        if(q1.empty() == false){
            q1.push(x);
        }else{
            q2.push(x);
        }
    }

    // Removes the element on top of the stack.
    void pop() {
        //从非空的队列中依次pop出元素,push进空的队列
        //剩下最后一个元素即是pop的
        if(q1.empty() == false){
            for(int i = 0; i < q1.size()-1; i++){
                q2.push(q1.front());
                q1.pop();
            }
            q1.pop();
        }else{
            for(int i = 0; i < q2.size()-1; i++){
                q1.push(q2.front());
                q2.pop();
            }
            q2.pop();
        }
    }

    // Get the top element.
    int top() {
        //总是非空队列的最后一个元素
        if(q1.empty() == false){
            return q1.back();
        }else{
            return q2.back();
        }
    }

    // Return whether the stack is empty.
    bool empty() {
        return q1.empty() && q2.empty();
    }

private:
    queue<int> q1;
    queue<int> q2;
//     queue<int> *pushqueue;
//     queue<int> *popqueue;
};