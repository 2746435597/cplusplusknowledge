//
// Created by 27464 on 2024/3/14.
//观察者模式（Observer Pattern）是一种行为设计模式，它定义了一种一对多的依赖关系，
// 让多个观察者对象可以同时监听一个主题对象，当主题对象状态发生变化时，所有依赖于它的观察者都会得到通知并自动更新\
//观察者模式中存在两种⻆⾊：
//观察者：内部包含被观察者对象，当被观察者对象的状态发⽣变化时，更新⾃⼰的状态。（接收通知更新状态）
//被观察者：内部包含了所有观察者对象，当状态发⽣变化时通知所有的观察者更新⾃⼰的状态。（发送通知）
//应⽤场景：
//当⼀个对象的改变需要同时改变其他对象，且不知道具体有多少对象有待改变时，应该考虑使⽤观察者模式；
//⼀个抽象模型有两个⽅⾯，其中⼀⽅⾯依赖于另⼀⽅⾯，这时可以⽤观察者模式将这两者封装在独⽴的对象中使它们各⾃独⽴地改变和复⽤
#include "Observer_Pattern.h"
#include <iostream>
#include <string>
#include <list>
using namespace std;
class Subject;
//观察者 基类 （内部实例化了被观察者的对象sub）
class Observer {
protected:
    string name;
    Subject *sub;
public:
    Observer(string name, Subject *sub) {
        this->name = name;
        this->sub = sub;
    }
    virtual void update() = 0;
};
class StockObserver : public Observer {
public:
    StockObserver(string name, Subject *sub) : Observer(name, sub){}
    void update();
};
class NBAObserver : public Observer {
public:
    NBAObserver(string name, Subject *sub) : Observer(name, sub){}
    void update();
};
//被观察者 基类 （内部存放了所有的观察者对象，以便状态发⽣变化时，给观察者发通知）
class Subject {
protected:
    std::list<Observer *> observers;
public:
    string action; //被观察者对象的状态
    virtual void attach(Observer *) = 0;
    virtual void detach(Observer *) = 0;
    virtual void notify() = 0;
};
class Secretary : public Subject {
    void attach(Observer *observer) {
        observers.push_back(observer);
    }
    void detach(Observer *observer) {
        list<Observer *>::iterator iter = observers.begin();
        while (iter != observers.end()) {
            if ((*iter) == observer) {
                observers.erase(iter);
                return;
            }
            ++iter;
        }
    }
    void notify() {
        list<Observer *>::iterator iter = observers.begin();
        while (iter != observers.end()) {
            (*iter)->update();
            ++iter;
        }
    }
};
void StockObserver::update() {
    cout << name << " 收到消息：" << sub->action << endl;
    if (sub->action == "⽼板来了!") {
        cout << "我⻢上关闭股票，装做很认真⼯作的样⼦！" << endl;
    }
}
void NBAObserver::update() {
    cout << name << " 收到消息：" << sub->action << endl;
    if (sub->action == "⽼板来了!") {
        cout << "我⻢上关闭 NBA，装做很认真⼯作的样⼦！" << endl;
    }
}
int main()
{
    Subject *BOSS = new Secretary();
    Observer *xa = new NBAObserver("xa", BOSS);
    Observer *xb = new NBAObserver("xb", BOSS);
    Observer *xc = new StockObserver("xc", BOSS);
    BOSS->attach(xz);
    BOSS->attach(xb);
    BOSS->attach(xc);
    BOSS->action = "去吃饭了！";
    BOSS->notify();
    cout << endl;
    BOSS->action = "⽼板来了!";
    BOSS->notify();
    return 0;
}
//输出
//product A create! product B create!