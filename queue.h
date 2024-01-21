#ifndef queue_h
#define queue_h

#include <iostream>
using namespace std;

const int N = 100;
class queue {
private:
    int front, rear;
    int arr[N];

public:
    queue() {
        front = -1;
        rear = -1;
    }

    bool empty() {
        return (rear == -1 && front == -1);
    }

    bool full() {
        return (rear == N - 1);
    }

    void insert(int x) {
        if (full()) {
            cout << "queue overflow.\n";
            return;
        }

        if (empty()) {
            front = 0;
            rear = 0;
            arr[0] = x;
            return;
        }

        arr[++rear] = x;
    }

    int remove() {
        if (empty()) {
            cout << "queue underflow.\n";
            return -1;
        }
        if (front == rear) {
            int item = arr[front];
            front = -1;
            rear = -1;
            return item;
        }
        int item = arr[front++];
        return item;
    }

    void display() {
        if (empty()) {
            return;
        }
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
    }
};

#endif