//Builder 模式要解决的也正是这样的问题：当我们要创建的对象很复杂的时候（通常是由很多其他的对象组合而成），
// 我们要要复杂对象的创建过程和这个对象的表示（展示）分离开来，
// 这样做的好处就是通过一步步的进行复杂对象的构建，由于在每一步的构造过程中可以引入参数，使得经过相同的步骤创建最后得到的对象的展示不一样。
// Created by 27464 on 2024/3/18.
//产品（Product）：表示被构建的复杂对象。产品类通常包含多个属性，这些属性在建造过程中逐步设置。
//建造者（Builder）：抽象接口，定义了创建产品对象的各个步骤，并提供了方法来设置产品的属性。
//具体建造者（Concrete Builder）：实现了建造者接口，负责实际构建产品对象。
//  具体建造者类通常包含一个成员变量用于存储正在构建的产品对象，以及一系列方法用于设置产品的属性。
//指挥者（Director）：负责使用建造者接口来构建产品对象。指挥者类通常定义了一个构建方法，
//  该方法接受一个建造者对象作为参数，并根据具体的构建步骤来调用建造者对象的方法来构建产品对象。

#include "Builder.h"
#include <iostream>
#include <string>

// 产品类
class Product {
public:
    void setPartA(const std::string& partA) {
        partA_ = partA;
    }

    void setPartB(const std::string& partB) {
        partB_ = partB;
    }

    void setPartC(const std::string& partC) {
        partC_ = partC;
    }

    void show() {
        std::cout << "Part A: " << partA_ << std::endl;
        std::cout << "Part B: " << partB_ << std::endl;
        std::cout << "Part C: " << partC_ << std::endl;
    }

private:
    std::string partA_;
    std::string partB_;
    std::string partC_;
};

// 建造者抽象类
class Builder {
public:
    virtual void buildPartA() = 0;
    virtual void buildPartB() = 0;
    virtual void buildPartC() = 0;
    virtual Product* getResult() = 0;
};

// 具体建造者类
class ConcreteBuilder : public Builder {
public:
    ConcreteBuilder() : product_(new Product()) {}

    void buildPartA() override {
        product_->setPartA("Part A");
    }

    void buildPartB() override {
        product_->setPartB("Part B");
    }

    void buildPartC() override {
        product_->setPartC("Part C");
    }

    Product* getResult() override {
        return product_;
    }

private:
    Product* product_;
};

// 指挥者类
class Director {
public:
    void construct(Builder* builder) {
        builder->buildPartA();
        builder->buildPartB();
        builder->buildPartC();
    }
};

int main() {system("chcp 65001");
    Director director;
    ConcreteBuilder builder;
    director.construct(&builder);

    Product* product = builder.getResult();
    product->show();

    delete product;

    return 0;
}
