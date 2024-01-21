#ifndef CircularQueue_h
#define CircularQueue_h

class CircularQueue {
private:
    static const int N = 100;
    int front, rear;
    int arr[N];

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    bool empty() {
        return (front == -1 && rear == -1);
    }

    bool full() {
        return ((rear + 1) % N == front);
    }

    void enqueue(int x) {
        if (full()) {
            cout << "circular queue overflow.\n";
            return;
        }

        if (empty()) {
            front = 0;
            rear = 0;
            arr[0] = x;
            return;
        }

        rear = (rear + 1) % N;
        arr[rear] = x;
    }

    int dequeue() {
        if (empty()) {
            cout << "stack underflow.\n";
            return -1;
        }

        if (front == rear) {
            int item = arr[front];
            front = -1;
            rear = -1;
            return item;
        }

        int item = arr[front];
        front = (front + 1) % N;
        return item;
    }

    void display() {
        if (empty()) {
            return;
        }

        for (int i = front;; i = (i + 1) % N) {
            cout << arr[i] << " ";
            if (i == rear) {
                return;
            }
        }
    }
};

#endif