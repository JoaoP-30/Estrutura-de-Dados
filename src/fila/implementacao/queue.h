#ifndef QUEUE_H
#define QUEUE_H

#include <stdexcept>

template <typename T>
class Queue
{
private:
    int capacity;
    int size;
    int begin;
    int end;
    T *queue;

    bool full() const
    {
        return size == capacity;
    }

    void resize()
    {
        capacity *= 2;
        T *expandedQueue = new T[capacity];

        for (int i = 0; i < size; i++)
        {
            expandedQueue[i] = queue[(begin + i) % capacity];
        }

        delete[] queue;
        queue = expandedQueue;

        begin = 0;
        end = size;
    }

public:
    Queue()
    {
        capacity = 10;
        size = 0;
        begin = 0;
        end = 0;
        queue = new T[capacity];
    }

    ~Queue()
    {
        delete[] queue;
    }

    bool empty() const
    {
        return begin == end;
    }

    void enqueue(T value)
    {
        if (full())
        {
            resize();
        }

        queue[end % capacity] = value;
        end++;
        size++;
    }

    void dequeue()
    {
        if (empty())
        {
            throw std::out_of_range("A fila está vazia!");
        }

        begin++;
        size--;
    }

    T front() const
    {
        if (empty())
        {
            throw std::out_of_range("A fila está vazia!");
        }

        T frontElement = queue[begin % capacity];

        return frontElement;
    }
};
#endif