class MedianFinder {
   public:
    priority_queue<int> maxHeap;                             // left
    priority_queue<int, vector<int>, greater<int>> minHeap;  // right
    MedianFinder() {  }

    void addNum(int num) {
        if (maxHeap.empty()) {
            maxHeap.push(num);
            return;
        }

        if (num > maxHeap.top()) {
            printf("push min %d\n", num);
            minHeap.push(num);
            if (maxHeap.size() < minHeap.size()) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
        } else {
            printf("push max %d\n", num);
            maxHeap.push(num);
            if (maxHeap.size() > minHeap.size() + 1) {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
        }
        // printf("maxs=%d mins=%d\n", maxHeap.size(), minHeap.size());
    }

    double findMedian() {
        if (maxHeap.size() > minHeap.size()) {
            return maxHeap.top();
        }

        return ((double)maxHeap.top() + minHeap.top()) / 2.0;
    }
};
