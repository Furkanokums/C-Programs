#include <iostream>
#define N 10
using namespace std;

template<class T>
class Queue {
private:
    T arr[N];
    int front;
    int rear;
public:
    Queue() {
        front = 0;
        rear = 0;
    }

    bool isEmpty() {
        return front == rear;

    }
    void enqueue(T x) {
        if (rear == N) {
            cout << "Queue overflow!" << endl;
            return;
        }
        else {
            arr[rear] = x;
            rear++;
        }
    }

    T dequeue() {
        if (isEmpty()) {
            cout << "Queue underflow!" << endl;
            return NULL; // Varsayılan değer
        }
        else {
            T temp = arr[front];
            front++;
            return temp;
        }
    }

    void empty() {
        front = 0;
        rear = 0;
    }
    
    void displayQueue() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        for (int i = front ; i < rear ; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }

};

int main() {
    
    Queue<int> *que = new Queue<int>();
    que->enqueue(1);
    que->enqueue(2);
    que->enqueue(3);
    que->displayQueue();
    que->empty();
    que->displayQueue();

}
