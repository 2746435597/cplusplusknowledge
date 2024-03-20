//用于将一个类的接口转换成客户端所期待的另一个接口，使得原本由于接口不兼容而无法一起工作的类能够协同工作。
// 适配器模式允许系统间的接口不兼容问题得到解决，使得原本无法直接交互的类能够进行协同工作。
// Created by 27464 on 2024/3/18.

//类适配器模式
#include <iostream>

// 目标接口:：通过多重继承或单一类继承和接口实现来实现适配器。在这种情况下，适配器类继承了目标接口，并且持有一个对被适配者的引用
class Target {
public:
    virtual void request() const = 0;
};

// 被适配者
class Adaptee {
public:
    void specificRequest() const {
        std::cout << "Adaptee's specific request" << std::endl;
    }
};

// 适配器类（类适配器）
class Adapter : public Target, private Adaptee {
public:
    void request() const override {
        specificRequest();
    }
};

int main() {
    Target* target = new Adapter();
    target->request();  // Output: Adaptee's specific request

    delete target;
    return 0;
}
