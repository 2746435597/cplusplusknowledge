//
// Created by 27464 on 2024/3/14.
//懒汉/饱汉模式（线程安全需要加锁）：
//尽可能的晚的创建这个对象的实例，即在单例类第⼀次被引⽤的时候就将⾃⼰初始化，C++
//很多地⽅都有类型的思想，⽐如写时拷⻉，晚绑定等

#include "Lazy.h"
#include <pthread.h>
#include <iostream>
#include <algorithm>
using namespace std;
class SingleInstance {
public:
    static SingleInstance* GetInstance() {
        if (ins == nullptr) {
            pthread_mutex_lock(&mutex);
            if (ins == nullptr) {
                ins = new SingleInstance();
            }
            pthread_mutex_unlock(&mutex);
        }
        return ins;
    }
    ~SingleInstance(){};
    //互斥锁
    static pthread_mutex_t mutex;
private:
    //涉及到创建对象的函数都设置为private
    SingleInstance() { std::cout<<"SingleInstance() 饱汉"<<std::endl;
    }
    SingleInstance(const SingleInstance& other) {};
    SingleInstance& operator=(const SingleInstance& other) { return
                *this; }
    //静态成员
    static SingleInstance* ins;
};
//懒汉式 静态变量需要定义
SingleInstance* SingleInstance::ins = nullptr;
pthread_mutex_t SingleInstance::mutex;
int main(){
    //因为不能创建对象所以通过静态成员函数的⽅法返回静态成员变ᰁ
    SingleInstance* ins = SingleInstance::GetInstance();
    delete ins;
    return 0;
}
//输出 SingleInstance() 懒汉