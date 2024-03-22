#ifndef QUEUE_H
#define QUEUE_H
#define QueueSize 100
typedef int DataType;
typedef struct {
    DataType data[QueueSize];
    int front, rear;
} Queue;
#endif // QUEUE_H