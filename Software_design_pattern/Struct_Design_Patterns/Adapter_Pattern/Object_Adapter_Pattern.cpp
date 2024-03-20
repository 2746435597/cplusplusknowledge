//
// Created by 27464 on 2024/3/18.
//通过组合关系来实现适配器。在对象适配器模式中，适配器持有一个对被适配者的引用，并实现了目标接口的方法。
// 适配器将客户端的请求转发给被适配者，并将被适配者的响应转换为客户端所期待的响应。
//对象适配器模式:通过获取被适配者的引用实现
#include <iostream>

// 目标接口
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

// 适配器类（对象适配器）
class Adapter : public Target {
private:
    Adaptee* adaptee_;

public:
    Adapter(Adaptee* adaptee) : adaptee_(adaptee) {}

    void request() const override {
        adaptee_->specificRequest();
    }
};

int main() {
    Adaptee* adaptee = new Adaptee();
    Target* target = new Adapter(adaptee);
    target->request();  // Output: Adaptee's specific request

    delete target;
    delete adaptee;
    return 0;
}
