#include <iostream>
#include <deque>
#include <thread>
#include <mutex>
#include <condition_variable>

std::deque<int> q;
std::mutex mu;
std::condition_variable cond;

/*
生产者 在生产的时候加锁（推数据）  不保证推一个取一个，只保证在推的时候不能取 
*/
void function_1() {
    int count = 10;
    while (count > 0) {
        std::unique_lock<std::mutex> locker(mu);
        q.push_front(count);
        locker.unlock();
        cond.notify_one();  // Notify one waiting thread, if there is one.
        std::this_thread::sleep_for(std::chrono::seconds(1));
        count--;
    }
}

/*
消费者 在消费的时候加锁（取数据）  不保证推一个取一个，只保证在取的时候不能推 
*/

void function_2() {
    int data = 0;
    while ( data != 1) {
        std::unique_lock<std::mutex> locker(mu);
        while(q.empty())
            cond.wait(locker); // Unlock mu and wait to be notified
        data = q.back();
        q.pop_back();
        locker.unlock();
        std::cout << "t2 got a value from t1: " << data << std::endl;
    }
}
int main() {
    std::thread t1(function_1);
    std::thread t2(function_2);
    t1.join();
    t2.join();
    return 0;
}
