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


1.condition_variable  依赖于unique_lock  
2.调用wait时会释放锁
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




/*
这个操作很奇怪 thread没有join  notify也可被存储？
*/


// condition_variable::wait (with predicate)
#include <iostream>           // std::cout
#include <thread>             // std::thread, std::this_thread::yield
#include <mutex>              // std::mutex, std::unique_lock
#include <condition_variable> // std::condition_variable

std::mutex mtx;
std::condition_variable cv;

int cargo = 0;
bool shipment_available() {return cargo!=0;}

void consume (int n) {
  for (int i=0; i<n; ++i) {
    std::unique_lock<std::mutex> lck(mtx);
    cv.wait(lck,shipment_available);
    // consume:
    std::cout << cargo << '\n';
    cargo=0;
  }
}

int main ()
{

//  std::thread consumer_thread (consume,10);
  // produce 10 items when needed:
  for (int i=0; i<10; ++i) {
    while (shipment_available()) std::this_thread::yield();
    std::unique_lock<std::mutex> lck(mtx);
    cargo = i+1;
    cv.notify_one();
  }
std::thread consumer_thread (consume,10);
 consumer_thread.join();

  return 0;
}
