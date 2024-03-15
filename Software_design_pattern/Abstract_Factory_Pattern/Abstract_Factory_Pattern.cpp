//
// Created by 27464 on 2024/3/14.
//抽象工厂（Abstract Factory）：定义了创建一系列产品对象的接口，通常包含多个抽象方法，每个抽象方法用于创建一类产品对象。
//具体工厂（Concrete Factory）：实现了抽象工厂接口，负责创建具体的产品对象。每个具体工厂类实现了抽象工厂中定义的方法，
//用于创建相应类型的产品对象。
//抽象产品（Abstract Product）：定义了一类产品对象的接口，可以是抽象类或接口。抽象产品中通常包含了产品对象的公共方法。
//具体产品（Concrete Product）：实现了抽象产品接口，是具体的产品对象
#include "Abstract_Factory_Pattern.h"
#include <iostream>
//
// 抽象产品 A
class AbstractProductA {
public:
    virtual void operationA() = 0;
};

// 具体产品 A1
class ConcreteProductA1 : public AbstractProductA {
public:
    void operationA() override {
        std::cout << "Concrete Product A1" << std::endl;
    }
};

// 具体产品 A2
class ConcreteProductA2 : public AbstractProductA {
public:
    void operationA() override {
        std::cout << "Concrete Product A2" << std::endl;
    }
};

// 抽象产品 B
class AbstractProductB {
public:
    virtual void operationB() = 0;
};

// 具体产品 B1
class ConcreteProductB1 : public AbstractProductB {
public:
    void operationB() override {
        std::cout << "Concrete Product B1" << std::endl;
    }
};

// 具体产品 B2
class ConcreteProductB2 : public AbstractProductB {
public:
    void operationB() override {
        std::cout << "Concrete Product B2" << std::endl;
    }
};

// 抽象工厂
class AbstractFactory {
public:
    virtual AbstractProductA* createProductA() = 0;
    virtual AbstractProductB* createProductB() = 0;
};

// 具体工厂 1
class ConcreteFactory1 : public AbstractFactory {
public:
    AbstractProductA* createProductA() override {
        return new ConcreteProductA1();
    }

    AbstractProductB* createProductB() override {
        return new ConcreteProductB1();
    }
};

// 具体工厂 2
class ConcreteFactory2 : public AbstractFactory {
public:
    AbstractProductA* createProductA() override {
        return new ConcreteProductA2();
    }

    AbstractProductB* createProductB() override {
        return new ConcreteProductB2();
    }
};

int main() {
    // 创建具体工厂 1
    AbstractFactory* factory1 = new ConcreteFactory1();
    // 使用具体工厂 1 创建产品 A1 和产品 B1
    AbstractProductA* productA1 = factory1->createProductA();
    AbstractProductB* productB1 = factory1->createProductB();
    // 调用产品的操作方法
    productA1->operationA();
    productB1->operationB();
    // 释放内存
    delete productA1;
    delete productB1;
    delete factory1;

    // 创建具体工厂 2
    AbstractFactory* factory2 = new ConcreteFactory2();
    // 使用具体工厂 2 创建产品 A2 和产品 B2
    AbstractProductA* productA2 = factory2->createProductA();
    AbstractProductB* productB2 = factory2->createProductB();
    // 调用产品的操作方法
    productA2->operationA();
    productB2->operationB();
    // 释放内存
    delete productA2;
    delete productB2;
    delete factory2;

    return 0;
}
