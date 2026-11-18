class MedianFinder {
public:
    priority_queue<int> leftMaxHeap;
    priority_queue<int, vector<int>, greater<int>> rightMinHeap;
    vector<int> arr;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(leftMaxHeap.empty() || num <= leftMaxHeap.top()) {
            leftMaxHeap.push(num);
        } else {
            rightMinHeap.push(num);
        }
        balancing();
    }

    void balancing() {
        if(leftMaxHeap.size() > rightMinHeap.size()+1) {
            rightMinHeap.push(leftMaxHeap.top());
            leftMaxHeap.pop();
        } 
        else if(leftMaxHeap.size() < rightMinHeap.size()) {
            leftMaxHeap.push(rightMinHeap.top());
            rightMinHeap.pop();
        }
    }
    
    double findMedian() {
        if(leftMaxHeap.size() == rightMinHeap.size()) {
            double m = (double)leftMaxHeap.top() + rightMinHeap.top();
            m/=2.0;
            return m;
        } else {
            return leftMaxHeap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */