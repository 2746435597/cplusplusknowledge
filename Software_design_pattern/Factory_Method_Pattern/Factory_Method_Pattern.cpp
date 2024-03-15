//
// Created by 27464 on 2024/3/14.
//工厂方法模式（Factory Method Pattern）是一种创建型设计模式，它定义了一个用于创建对象的接口，
//但是允许子类决定要实例化的类是哪一个。工厂方法模式让一个类的实例化延迟到其子类。
//抽象产品（Abstract Product）：定义了产品的接口，是所有具体产品的父类。
//具体产品（Concrete Product）：实现了抽象产品接口，是工厂方法模式创建的对象。
//抽象工厂（Abstract Factory）：定义了创建产品的接口，包含一个抽象的工厂方法。
//具体工厂（Concrete Factory）：实现了抽象工厂接口，负责创建具体的产品对象。
#include "Factory_Method_Pattern.h"
#include <iostream>
#include <string>

// 抽象产品
class Product {
public:
    virtual void use() = 0;
};

// 具体产品 A
class ConcreteProductA : public Product {
public:
    void use() override {
        std::cout << "Using Concrete Product A" << std::endl;
    }
};

// 具体产品 B
class ConcreteProductB : public Product {
public:
    void use() override {
        std::cout << "Using Concrete Product B" << std::endl;
    }
};

// 抽象工厂
class AbstractFactory {
public:
    virtual Product* createProduct() = 0;
};

// 具体工厂 A
class ConcreteFactoryA : public Factory {
public:
    Product* createProduct() override {
        return new ConcreteProductA();
    }
};

// 具体工厂 B
class ConcreteFactoryB : public Factory {
public:
    Product* createProduct() override {
        return new ConcreteProductB();
    }
};

int main() {
    // 使用具体工厂 A 创建产品 A
    AbstractFactory* factoryA = new ConcreteFactoryA();
    Product* productA = factoryA->createProduct();
    productA->use();

    // 使用具体工厂 B 创建产品 B
    AbstractFactory* factoryB = new ConcreteFactoryB();
    Product* productB = factoryB->createProduct();
    productB->use();

    delete factoryA;
    delete factoryB;
    delete productA;
    delete productB;

    return 0;
}
