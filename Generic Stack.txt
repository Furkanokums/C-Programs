#include <iostream>
#define N 10
using namespace std;

template<class T>
class Stack {
private:
    T arr[N];
    int tos = -1;
public:
    bool isEmpty() {
        if (tos == -1) {
            return true;
        }
        else {
            return false;
        }
    }

    T pop() {
        if (isEmpty()) {
            return NULL;
        }
        else {
            T temp = arr[tos];
            tos--;
            return temp;
        }
    }

    void push(T x) {
        if (tos == N - 1) {
             return;
        }
        else {
            tos++;
            arr[tos] = x;
        }
    }

    void displayStack() {
        for (int i = 0 ; i < N ; i++) {
            cout<< arr[i] << " ";
        }
    }
};



int main() {
    Stack<int>* stc1 = new Stack<int>();
    stc1->push(1);
    stc1->push(2);
    cout << stc1->pop();

}

