//
// Created by 27464 on 2024/3/14.
//
// 简单工厂模式： 简单工厂 》 具体产品  》 抽象产品
// 抽象产品是具体产品的基类，实现所有产品的通用接口，一般为为纯虚函数，具体产品实现具体接口
//使用时通过简单工厂对传入参数条件进行分析以选择创建具体产品类
#include "simple_factory.h"
#include <iostream>

// 产品接口
class Product {
public:
    virtual void operation() = 0;
};

// 具体产品A
class ConcreteProductA : public Product {
public:
    void operation() override {
        std::cout << "Concrete Product A" << std::endl;
    }
};

// 具体产品B
class ConcreteProductB : public Product {
public:
    void operation() override {
        std::cout << "Concrete Product B" << std::endl;
    }
};

// 简单工厂类
class SimpleFactory {
public:
    static Product* createProduct(char type) {
        if (type == 'A') {
            return new ConcreteProductA();
        } else if (type == 'B') {
            return new ConcreteProductB();
        } else {
            return nullptr;
        }
    }
};

int main() {
    // 使用简单工厂创建产品对象
    Product* productA = SimpleFactory::createProduct('A');
    Product* productB = SimpleFactory::createProduct('B');

    // 调用产品对象的操作方法
    productA->operation();
    productB->operation();

    // 释放内存
    delete productA;
    delete productB;

    return 0;
}
