//
// Created by 27464 on 2024/3/18.
//定义：Prototype 模式也正是提供了自我复制的功能，就是说新对象的创建可以通过已有对象进行创建。（拷贝）
//Prototype 模式提供了一个通过已存在对象进行新对象创建的接口（Clone），Clone接口在 C++中我们将通过拷贝构造函数实现。
//原型模式通常涉及以下几个角色：
//原型接口（Prototype Interface）：定义了克隆方法的接口或抽象类。该接口通常包含一个抽象方法用于克隆对象。
//具体原型类（Concrete Prototype）：实现了原型接口，并提供了克隆方法的具体实现。具体原型类是被复制的对象。、
//客户端（Client）：使用原型模式的客户端，通过调用原型对象的克隆方法来创建新对象。



#include <iostream>
#include <string>

// 原型接口
class Prototype {
public:
    virtual Prototype* clone() const = 0;
    virtual void setData(const std::string& data) = 0;
    virtual std::string getData() const = 0;
};

// 具体原型类
class ConcretePrototype : public Prototype {
public:
    ConcretePrototype() : data_("") {}
    ConcretePrototype(const std::string& data) : data_(data) {}

    Prototype* clone() const override {
        return new ConcretePrototype(*this);
    }

    void setData(const std::string& data) override {
        data_ = data;
    }

    std::string getData() const override {
        return data_;
    }

private:
    std::string data_;
};

int main() {
    // 创建原型对象
    ConcretePrototype prototype("Original Data");

    // 克隆原型对象
    Prototype* clone = prototype.clone();

    // 修改克隆对象的数据
    clone->setData("Cloned Data");

    // 输出原型对象和克隆对象的数据
    std::cout << "Original Prototype Data: " << prototype.getData() << std::endl;
    std::cout << "Cloned Prototype Data: " << clone->getData() << std::endl;

    // 释放克隆对象的内存
    delete clone;

    return 0;
}
