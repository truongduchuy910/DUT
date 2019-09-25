#include <iostream>
struct Vector
{
    int dimensional = 0;
    int *direction;
};
class vectors
{
private:
	Vector* next;
	Vector* previous;
    Vector data
;

public:
    vectors(){

    };
    ~vectors()
    {
        delete[] vector.direction;
    };
    void in()
    {
        std::cout << "Input dimensional (int): ";
        std::cin >> vector.dimensional;
        vector.direction = new int[vector.dimensional];
        std::cout << "Input directions (d1 d2 d3 ...): ";
        for (int i = 0; i < vector.dimensional; i++)
        {
            std::cin >> vector.direction[i];
        }
    };
    void out()
    {
        std::cout << "(";
        for (int i = 0; i < vector.dimensional; i++)
        {
            std::cout << vector.direction[i];
            if (i != vector.dimensional - 1)
                std::cout << ",";
        }
        std::cout << ")" << std::endl;
    }
};
class Stack
{
private:
    /* data */
public:
    Stack(/* args */);
    ~Stack();
};

Stack::Stack(/* args */)
{
}

Stack::~Stack()
{
}

int main()
{
    Vectors vector;
    vector.push(new Vector.in());
    out.vector(vector[0] + vector[1]);
    
    return 0;
}
