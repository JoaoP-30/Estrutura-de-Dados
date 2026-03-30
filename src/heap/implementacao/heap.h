#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <stdexcept>
#include <cstring>

template <typename T>
class Heap
{
private:
    int capacity;
    int size;
    T *heap;

    void heapify(int i)
    {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < size && heap[left] > heap[largest])
        {
            largest = left;
        }

        if (right < size && heap[right] > heap[largest])
        {
            largest = right;
        }

        if (largest != i)
        {
            std::swap(heap[i], heap[largest]);
            heapify(largest);
        }
    }

    void resize()
    {
        capacity *= 2;
        T *newHeap = new T[capacity];

        for (int i = 0; i < size; i++)
        {
            newHeap[i] = heap[i];
        }

        delete heap;

        heap = newHeap;
    }

public:
    Heap()
    {
        capacity = 10;
        size = 0;
        heap = new T[capacity];
    }

    Heap(int cap)
    {
        capacity = cap;
        size = 0;
        heap = new T[capacity];
    }

    Heap(T vet[], int s)
    {
        capacity = s;

        heap = new T[capacity];

        memcpy(heap, vet, s * sizeof(T));

        size = s;

        for (int i = (size - 1 / 2); i >= 0; i--)
        {
            heapify(i);
        }
    }

    ~Heap()
    {
        delete[] heap;
    }

    void add(const T &val)
    {
        if (size == capacity)
        {
            resize();
        }

        heap[size++] = val;

        int i = size - 1;

        while (i != 0 && heap[(i - 1) / 2] < heap[i])
        {
            std::swap(heap[(i - 1) / 2], heap[i]);
            i = (i - 1) / 2;
        }
    }

    T remove()
    {
        if (size == 0)
        {
            throw std::underflow_error("Heap is empty!");
        }

        T val = heap[0];

        std::swap(heap[0], heap[size - 1]);
        size--;

        heapify(0);

        return val;
    }

    T getMax() const
    {
        if (size == 0)
        {
            throw std::underflow_error("Heap is empty!");
        }

        return heap[0];
    }

    void printHeap()
    {
        for (int i = 0; i < size; i++)
        {
            std::cout << heap[i] << ' ';
        }
        std::cout << '\n';
    }
};

#endif