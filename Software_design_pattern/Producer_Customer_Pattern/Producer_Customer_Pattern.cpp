//
// Created by 27464 on 2024/3/14.
//生产者-消费者模式是一种常见的并发设计模式，用于解决生产者和消费者之间的协作问题。
// 在该模式中，生产者负责生成数据（产品），而消费者负责消费这些数据。生产者和消费者之间通过共享的缓冲区进行通信。
//这种模式的典型应用场景包括：
//生产者和消费者之间的速度不一致。例如，生产者生产数据的速度比消费者处理数据的速度快，或者反之。
//生产者和消费者在时间上是异步的。生产者和消费者不需要同时存在，可以是不同的线程或进程。
//生产者和消费者需要解耦。生产者和消费者之间通过缓冲区进行解耦，从而可以独立进行优化和修改。
//生产者-消费者模式通常包括以下几个角色：
//
//生产者（Producer）：负责生成数据并将数据放入缓冲区中。
//消费者（Consumer）：负责从缓冲区中取出数据并进行处理。
//缓冲区（Buffer）：生产者和消费者之间共享的数据存储区域。它可以是一个队列、栈、或者其他形式的数据结构。

#include "Producer_Customer_Pattern.h"
#include <iostream>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>

std::queue<int> buffer;
std::mutex mtx;
std::condition_variable cv;
bool finished = false;

void producer() {
    for (int i = 1; i <= 10; ++i) {
        {
            std::unique_lock<std::mutex> lock(mtx);
            buffer.push(i);
            std::cout << "Produced: " << i << std::endl;
        }
        cv.notify_one(); // 通知消费者取出数据
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
    finished = true;
    cv.notify_one(); // 最后一次通知消费者
}

void consumer() {
    while (true) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, []{ return !buffer.empty() || finished; }); // 等待生产者产生数据或者任务结束
        if (!buffer.empty()) {
            int data = buffer.front();
            buffer.pop();
            std::cout << "Consumed: " << data << std::endl;
        }
        if (buffer.empty() && finished) // 缓冲区为空且生产者任务结束时退出循环
            break;
    }
}

int main() {
    std::thread producerThread(producer);
    std::thread consumerThread(consumer);

    producerThread.join();
    consumerThread.join();

    return 0;
}
