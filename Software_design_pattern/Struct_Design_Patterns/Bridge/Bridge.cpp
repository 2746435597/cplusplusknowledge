//我们有一个最基础的需求，实现了它，然后新的需求来了，我们建造新的需求类，把旧的需求类塞给新的需求类，于是完成了桥接
// Created by 27464 on 2024/3/18.
//用于将抽象部分与其实现部分分离，使它们可以独立变化。
// 桥接模式通过将抽象部分和实现部分分离，使得它们可以独立地进行扩展、变化和重用，
// 从而提高了系统的灵活性和可扩展性。
//抽象类（Abstraction）：定义了抽象部分的接口，并维护一个对实现部分对象的引用。抽象类通常包含一个抽象方法，用于调用实现部分的方法。
//扩展抽象类（Refined Abstraction）：是抽象类的子类，用于扩展或修改抽象部分的接口。扩展抽象类可以调用实现部分的方法来完成具体的操作。
//实现接口（Implementor）：定义了实现部分的接口，通常包含一个或多个方法。
//具体实现类（Concrete Implementor）：实现了实现接口，并提供了具体的实现。具体实现类是实现部分的具体实现。
#include <iostream>
#include <string>

// 实现接口：颜色
class Color {
public:
    virtual std::string getColor() const = 0;
};

// 具体实现类：红色
class RedColor : public Color {
public:
    std::string getColor() const override {
        return "Red";
    }
};

// 具体实现类：蓝色
class BlueColor : public Color {
public:
    std::string getColor() const override {
        return "Blue";
    }
};

// 抽象类：图形
class Shape {
protected:
    Color* color_;

public:
    Shape(Color* color) : color_(color) {}

    virtual void draw() const = 0;
};

// 扩展抽象类：圆形
class Circle : public Shape {
public:
    Circle(Color* color) : Shape(color) {}

    void draw() const override {
        std::cout << "Draw a " << color_->getColor() << " Circle" << std::endl;
    }
};

// 扩展抽象类：矩形
class Rectangle : public Shape {
public:
    Rectangle(Color* color) : Shape(color) {}

    void draw() const override {
        std::cout << "Draw a " << color_->getColor() << " Rectangle" << std::endl;
    }
};

int main() {
    // 创建具体实现对象
    Color* red = new RedColor();
    Color* blue = new BlueColor();

    // 创建具体抽象对象，并关联具体实现对象
    Shape* redCircle = new Circle(red);
    Shape* blueRectangle = new Rectangle(blue);

    // 绘制图形
    redCircle->draw();        // Draw a Red Circle
    blueRectangle->draw();    // Draw a Blue Rectangle

    // 释放内存
    delete red;
    delete blue;
    delete redCircle;
    delete blueRectangle;

    return 0;
}
