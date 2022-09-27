/*
 * @lc app=leetcode id=622 lang=cpp
 *
 * [622] Design Circular Queue
 */

// @lc code=start
class MyCircularQueue
{
public:
    vector<int> circularQ;
    int back, front, capacity;
    MyCircularQueue(int k)
    {
        circularQ.resize(k, -1);
        capacity = 0;
        // both front and back need not be tracked
        // but for convenience I am using both variables
        back = 0;
        front = 0;
    }

    bool enQueue(int value)
    {
        if (capacity < circularQ.size())
        {
            if (back >= circularQ.size())
                back = back % circularQ.size();
            circularQ[back++] = value;
            capacity++;
            return true;
        }
        return false;
    }

    bool deQueue()
    {
        if (capacity > 0)
        {
            // Food for thought: should following line go below circularQ[back++]
            // line, if yes what are drawbacks, I figured out this while solving
            if (front >= circularQ.size())
                front = front % circularQ.size();
            circularQ[front++] = -1;
            capacity--;
            return true;
        }
        return false;
    }

    int Front()
    {
        // front is the side where oldest elements are there
        if (capacity == 0)
            return -1;
        return circularQ[front % circularQ.size()];
    }

    int Rear()
    {
        // rear side is the one where latest elements comes
        if (capacity == 0)
            return -1;
        // logic for below line is pretty obvious if you think about how back increases
        // a dry run might help on following testcase
        // ["MyCircularQueue","enQueue","enQueue","deQueue","enQueue","deQueue","enQueue","deQueue","enQueue","deQueue", "Rear"]
        // [[2],[1],[2],[],[3],[],[3],[],[3],[],[]]
        return circularQ[(back - 1) % circularQ.size()];
        ;
    }

    bool isEmpty()
    {
        if (capacity == 0)
            return true;
        return false;
    }

    bool isFull()
    {
        if (capacity == circularQ.size())
            return true;
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->back();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
// @lc code=end
