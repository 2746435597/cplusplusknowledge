//Composite 模式（组合实体模式）
//将对象组合成树形结构以表示“部分-整体”的层次结构。Composite 使得用户对单个对象和组合对象的使用具有一致性。
//组合实体（Composite Entity）：高级别的实体，由多个更低级别的实体组成。组合实体提供一个统一的接口，用于访问其内部的低级别实体。
//粗粒度对象（Coarse-Grained Object）：组合实体中的较高级别的对象。粗粒度对象负责协调和管理组合实体中的子对象。
//细粒度对象（Fine-Grained Object）：组合实体中的较低级别的对象。细粒度对象是组合实体的组成部分，它们负责完成具体的操作或提供具体的功能。
//策略（Strategies）：组合实体中的子对象可能有多种不同的策略，用于实现不同的功能或行为。
//组合实体模式的目标是简化客户端的操作，并隐藏系统中的复杂性。
// 它通过将多个细粒度对象组合成一个高级别的实体，提供了一个更简单、更统一的接口来操作整个组合实体。
#include <iostream>
#include <string>

// 细粒度对象1
class SubObject1 {
public:
    void operation1(const std::string& data) {
        std::cout << "SubObject1: " << data << std::endl;
    }
};

// 细粒度对象2
class SubObject2 {
public:
    void operation2(const std::string& data) {
        std::cout << "SubObject2: " << data << std::endl;
    }
};

// 组合实体
class CompositeEntity {
private:
    SubObject1 subObject1_;
    SubObject2 subObject2_;

public:
    void setData(const std::string& data1, const std::string& data2) {
        subObject1_.operation1(data1);
        subObject2_.operation2(data2);
    }

    std::string getData() const {
        return "CompositeEntity Data";
    }
};

// 客户端
class Client {
private:
    CompositeEntity compositeEntity_;

public:
    void printData(const std::string& data1, const std::string& data2) {
        compositeEntity_.setData(data1, data2);
        std::cout << "Client: " << compositeEntity_.getData() << std::endl;
    }
};

int main() {
    Client client;
    client.printData("Data1", "Data2");

    return 0;
}
