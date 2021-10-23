#include <iostream>
#include <vector>
using namespace std;

class Expression{
public:
    Expression() {};

    virtual double evaluate() = 0;
};

class Constant: public Expression{
private:
    double value;
public:
    Constant(double value) : value(value) {};

    double evaluate() override{
        return value;
    }
};

class UnaryExpression: public Expression{
protected:
    Expression* right;
public:
    UnaryExpression(Expression *right) : right(right) {};

    double evaluate() override{
        return right->evaluate();
    }
};

class Negate: public UnaryExpression{
public:
    Negate(Expression *right) : UnaryExpression(right) {};

    double evaluate() override{
        return -UnaryExpression::evaluate();
    }
};

class BinaryExpression: public UnaryExpression{
public:
    BinaryExpression(Expression *right, Expression *left) : UnaryExpression(right), left(left) {}

protected:
    Expression* left;
};

class Adder: public BinaryExpression{
public:
    Adder(Expression *right, Expression *left) : BinaryExpression(right, left) {};

    double evaluate() override{
        return left->evaluate() + right->evaluate();
    }
};

class Subtracter: public BinaryExpression{
public:
    Subtracter(Expression *right, Expression *left) : BinaryExpression(right, left) {};

    double evaluate() override{
        return left->evaluate() - right->evaluate();
    }
};

class MathHomework{
private:
    vector<Expression*> expressions;
public:
    MathHomework(const vector<Expression *> &expressions) : expressions(expressions) {};

    void addExpression(Expression *ex){
        expressions.push_back(ex);
    }
    vector<double> getResults(){
        std::vector<double> results;
        for(auto &el:expressions){
            results.push_back(el->evaluate());
        }
        return results;
    }
};

int main() {
    auto c5 = new Constant(5);
    auto n5 = new Negate(c5);
    //cout << n5->evaluate();
    auto c9 = new Constant(9);
    auto c3 = new Constant(3);
    auto c10 = new Constant(10);
    auto u10 = new UnaryExpression(c10);
    auto n10 = new Negate(u10);
    auto c4 = new Constant(4);
    auto c2 = new Constant(2);
    auto s39 = new Subtracter(c3, c9);
    auto a593 = new Adder(n5, s39);
    cout << "-5 + (9 - 3) = " << a593->evaluate() << "\n";
    auto s42 = new Adder(c4, c2);
    auto n42 = new Negate(s42);
    auto s4210 = Subtracter(n10, n42);
    cout << "-(4+2)-(-10) = " << s4210.evaluate() << "\n";
    return 0;
}
