#ifndef NODE_H
#define NODE_H


class Node
{
    public:
        virtual double Calc() const = 0;//const 方法不会改变类的数据成员
        virtual ~Node() {};//虚析构函数 基类指针指向派生类时，调用delete时，会调用派生类的析构函数，然后再调用基类的


    protected:

    private:
};

class NumberNode : public Node
{
public:
    NumberNode(double number) : number_(number){}
    double Calc() const;
private:
    const double number_;
};

class BinaryNode : public Node
{
public:
    BinaryNode(Node* left,Node *right)
    :left_(left),right_(right){}
    ~BinaryNode();
protected:
    Node* const left_;//const 指针不能改变，不能指向其他的节点了 但指向的节点的值可以改变
    Node* const right_;
};

class UnaryNode : public Node
{
public:
    UnaryNode(Node*child)
    :child_(child){}
protected:
    Node* const child_;
};

class AddNode : public BinaryNode
{
public:
    AddNode(Node* left,Node* right)
    : BinaryNode(left,right){}
    double Calc() const;

};
class SubNode : public BinaryNode
{
public:
    SubNode(Node* left,Node* right)
    : BinaryNode(left,right){}
    double Calc() const;

};
class MultiplyNode : public BinaryNode
{
public:
    MultiplyNode(Node* left,Node* right)
    : BinaryNode(left,right){}
    double Calc() const;

};

class DivisorNode : public BinaryNode
{
public:
    DivisorNode(Node* left,Node* right)
    : BinaryNode(left,right){}
    double Calc() const;

};

class UMinusNode : public UnaryNode
{
public:
    UMinusNode(Node* child)
    :UnaryNode(child) {}
    double Calc() const;
};

#endif // NODE_H
