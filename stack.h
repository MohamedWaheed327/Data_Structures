#ifndef stack_h
#define stack_h

template <class M>
class stack {
private:
    int N;
    int Top;
    M *arr;

public:
    stack(int N) {
        Top = -1;
        this->N = N;
        arr = new M[N];
    }

    ~stack() {
        delete[] arr;
    }

    int size() {
        return Top + 1;
    }

    bool full() {
        return Top == N - 1;
    }

    bool empty() {
        return Top == -1;
    }

    M top() {
        if (empty()) {
            cout << "stack underflow.\n";
            return -1;
        }
        return arr[Top];
    }

    void push(M x) {
        if (full()) {
            cout << "stack overflow.\n";
            return;
        }
        arr[++Top] = x;
    }

    M pop() {
        if (empty()) {
            cout << "stack underflow.\n";
            return -1;
        }
        return arr[Top--];
    }

    void display() {
        for (int i = 0; i <= Top; ++i) {
            cout << arr[i] << " ";
        }
    }
};

#endif