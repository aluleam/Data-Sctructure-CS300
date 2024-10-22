//
//  StackQueue.h
//  StackQueues
//
//  Created by Making Aberto on 1/31/24.
//

#ifndef StackQueue_h
#define StackQueue_h

class StackQueue

{
private:
    
    int *queueArray;
    int queueSize;
    int front, rear;
    int num_items; //number of the items in the queue
    
public:
    StackQueue(int size);
    ~StackQueue();
    
    bool addQueue(int num);
    bool queue(int &num);
    
    bool isFull()const;
    bool isEmpty()const;
    
    
};


#endif
