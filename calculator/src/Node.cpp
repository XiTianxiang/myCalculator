#include "Node.h"
#include <math.h>
#include <iostream>


double NumberNode::Calc() const
{
    return number_;
}

BinaryNode::~BinaryNode()
{
    delete left_;
    delete right_;
}
double AddNode::Calc() const
{
    return left_->Calc()+right_->Calc();
}

double SubNode::Calc() const
{
    return left_->Calc()-right_->Calc();
}

double MultiplyNode::Calc() const
{
    return left_->Calc()*right_->Calc();
}

double DivisorNode::Calc() const
{
    double divisor = right_->Calc();
    if(divisor != 0.0)
        return left_->Calc()/right_->Calc();
    else
    {
        std::cout<<"Error : Divisor by zero"<<std::endl;
        return HUGE_VAL;
    }
}

double UMinusNode::Calc() const
{
    return -child_->Calc();
}

