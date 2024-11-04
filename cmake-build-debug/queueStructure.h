#ifndef QUEUE_STRUCTURE_H
#define QUEUE_STRUCTURE_H

#include <iostream>
#include <vector>

template <typename T>
class CircularQueue {
private:
    T* arr; // Array to store elements
    int front_index; // Index of front element
    int rear_index; // Index of rear element
    int capacity; // Max number of elements allowed
    int num_items; // Current size of queue

public:
    // Constructor
    CircularQueue(int cap = 10) {
        capacity = cap;
        arr = new T[capacity];
        front_index = 0;
        rear_index = -1;
        num_items = 0;
    }

    // Destructor to free memory
    ~CircularQueue() {
        delete[] arr;
    }

    void push(T value) {
        if (num_items == capacity) {
            std::cout << "Queue is full, cannot push " << value << std::endl;
            return;
        }
        rear_index = (rear_index + 1) % capacity; // Circular increment for rear
        arr[rear_index] = value; // Pushing value onto array
        num_items++;
    }

    void pop() {
        if (empty()) {
            std::cout << "Queue is empty, cannot pop" << std::endl;
            return;
        }
        front_index = (front_index + 1) % capacity;
        num_items--;
    }

    T front() {
        if (empty()) {
            std::cerr << "Queue is empty" << std::endl;
            throw std::out_of_range("Queue is empty");
        }
        return arr[front_index];
    }

    int size() {
        return num_items;
    }

    bool empty() {
        return num_items == 0;
    }

    void move_to_rear() {
        if (empty()) {
            std::cout << "Queue is empty, cannot move front to rear" << std::endl;
            return;
        }
        T front_value = front();
        pop(); // Remove the front element
        push(front_value); // Push it to the rear
    }

    // Insertion sort for the CircularQueue
    void insertion_sort() {
        CircularQueue<int> sortedQueue; // Create a new queue for sorted elements

        while (num_items > 0) {
            int current = front(); // Get the front element
            pop(); // Remove it from the original queue

            // If the sorted queue is empty, directly insert the first element
            if (sortedQueue.empty()) {
                sortedQueue.push(current);
            } else {
                // Temporarily move all sorted elements back to the original queue until we find the insertion point
                CircularQueue<int> tempQueue;
                bool inserted = false;

                // Move sorted elements back to the original queue if necessary
                while (!sortedQueue.empty()) {
                    if (!inserted && sortedQueue.front() > current) {
                        tempQueue.push(current); // Insert current element at the correct position
                        inserted = true;
                    }
                    // Move sorted element to temp queue
                    tempQueue.push(sortedQueue.front());
                    sortedQueue.pop();
                }

                // If the element was not inserted (i.e., it's the largest), push it to the end
                if (!inserted) {
                    tempQueue.push(current);
                }

                // Move everything back to the sortedQueue
                while (!tempQueue.empty()) {
                    sortedQueue.push(tempQueue.front());
                    tempQueue.pop();
                }
            }
        }

        // Now move sorted elements back to the original queue
        while (!sortedQueue.empty()) {
            push(sortedQueue.front());
            sortedQueue.pop();
        }
    }

};

// Recursive linear search function to find the last occurrence of a target
template <typename Item_Type>
int linear_search(const std::vector<Item_Type>& items, const Item_Type& target, size_t pos_first) {
    if (pos_first == items.size())
        return -1; // Base case: reached the end of the vector

    int index = linear_search(items, target, pos_first + 1); // Recursive step
    if (index != -1)
        return index; // Return found index if it's not -1

    return (items[pos_first] == target) ? pos_first : -1; // Return current index if target matches
}

#endif // QUEUE_STRUCTURE_H
