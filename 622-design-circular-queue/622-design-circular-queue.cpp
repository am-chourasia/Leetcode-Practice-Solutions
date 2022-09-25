class MyCircularQueue {
    vector<int> queue;
    int rearPointer, frontPointer;
    int size;
public:
    MyCircularQueue(int k) {
        queue.resize(k);
        frontPointer = -1;
        rearPointer = -1;
        size = k;
    }
    
    bool enQueue(int value) {
        int nextLoc = (rearPointer + 1) % size;
        if (nextLoc == frontPointer)
            return false;
        queue[nextLoc] = value;
        if (nextLoc == 0 and frontPointer == -1)
            frontPointer = 0;
        rearPointer = nextLoc;
        return true;
    }
    
    bool deQueue() {
        if (frontPointer == -1)
            return false;
        if (frontPointer == rearPointer)
            frontPointer = rearPointer = -1;
        else
            frontPointer = (frontPointer + 1) % size;
        return true;
    }
    
    int Front() {
        if (frontPointer == -1)
            return -1;
        return queue[frontPointer];
    }
    
    int Rear() {
        if (rearPointer == -1)
            return -1;
        return queue[rearPointer];
    }
    
    bool isEmpty() {
        return frontPointer == -1;
    }
    
    bool isFull() {
        int nextLoc = (rearPointer + 1) % size;
        return nextLoc == frontPointer;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */