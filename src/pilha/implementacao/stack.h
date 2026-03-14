#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <stdexcept>

template <typename T>
class Stack
{
private:
    int size;
    int capacity;
    T *stack;

    bool full() const
    {
        return size == capacity;
    }

    void resize()
    {
        capacity = capacity * 2;

        T *expandedStack = new T[capacity];

        for (int i = 0; i < size; i++)
        {
            expandedStack[i] = stack[i];
        }

        delete[] stack;

        stack = expandedStack;
    }

public:
    Stack()
    {
        size = 0;
        capacity = 3;
        stack = new T[capacity];
    }

    ~Stack()
    {
        delete[] stack;
    }

    Stack(const Stack<T> &other)
    {
        size = other.size;
        capacity = other.capacity;

        stack = new T[capacity];

        for (int i = 0; i < size; i++)
        {
            stack[i] = other.stack[i];
        }
    }

    Stack<T> &operator=(const Stack<T> &other)
    {
        if (this == &other)
        {
            return *this;
        }

        delete[] stack;

        size = other.size;
        capacity = other.capacity;
        stack = new T[capacity];

        for (int i = 0; i < size; i++)
        {
            stack[i] = other.stack[i];
        }

        return *this;
    }

    bool empty() const
    {
        return size == 0;
    }

    void push(const T &element)
    {
        if (full())
        {
            resize();
        }

        stack[size++] = element;
    }

    T pop()
    {
        if (empty())
        {
            throw std::out_of_range("A pilha está vazia!");
        }

        T element = stack[--size];

        return element;
    }

    T top() const
    {
        if (empty())
        {
            throw std::out_of_range("A pilha está vazia!");
        }

        return stack[size - 1];
    }

    T *begin() const
    {
        return &stack[0];
    }

    T *end() const
    {
        return &stack[size];
    }
};

#endif