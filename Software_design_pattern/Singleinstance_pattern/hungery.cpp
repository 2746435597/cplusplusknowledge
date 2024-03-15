//
// Created by 27464 on 2024/3/14.
//饿汉模式（线程安全）：
//在最开始的时候静态对象就已经创建完成，设计⽅法是类中包含⼀个静态成员指针，该指针指向该类的⼀个对象,
//提供⼀个公有的静态成员⽅法，返回该对象指针，为了使得对象唯⼀，构造函数设为私有。
//

#include "hungery.h"
#include <iostream>
#include <algorithm>
using namespace std;
class SingleInstance {
public:
    static SingleInstance* GetInstance() {
        static SingleInstance ins;
        return &ins;
    }
    //第一个 static 关键字用于函数 GetInstance() 自身，它表明该函数是一个静态成员函数。
    // 静态成员函数不属于任何类对象，它可以直接通过类名来调用，而不需要通过对象。这样，客户端可以在不创建类的实例的情况下获取单例对象。
    //第二个 static 关键字用于局部变量 ins，它保证了在函数 GetInstance() 被调用时，ins 只会被初始化一次，之后的调用都会返回同一个实例的指针。
    // 这种方式确保了单例对象的唯一性。

    ~SingleInstance(){};
private:
    //涉及到创建对象的函数都设置为private
    SingleInstance() { std::cout<<"SingleInstance() 饿汉"<<std::endl;
    }//构造函数
    SingleInstance(const SingleInstance& other) {};//拷贝构造
    SingleInstance& operator=(const SingleInstance& other) {return
                *this;}//赋值运输
};

int main(){
    //因为不能创建对象所以通过静态成员函数的⽅法返回静态成员变ᰁ
    SingleInstance* ins = SingleInstance::GetInstance();
    return 0;
}
//输出 SingleInstance() 饿汉