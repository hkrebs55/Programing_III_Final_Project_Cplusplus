#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex mtx;

void count_increase(int largest_num) {

    try {
        //lock for loop until finished, ensures other threads cannot use same memory
        //unlocks once complete
        lock_guard<mutex> lock(mtx);
        for (int i = 1; i <= largest_num; ++i) {
            cout << i << "\n";
        }
    } catch (exception e) {
        //log exception
    }
}

void count_decrease(int largest_num) {

    try {
        //lock for loop until finished, ensures other threads cannot use same memory
        //unlocks once complete
        lock_guard<mutex> lock(mtx);
        for (int i = largest_num; i > 0; --i) {
            cout << i << "\n";
        }
    } catch (exception e) {
        //log exception
    }
}

int main() {

    int largest_num = 20;
    thread t1(count_increase, largest_num);
    thread t2(count_decrease, largest_num);

    t1.join();
    t2.join();

    return 0;
}
