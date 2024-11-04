//
// Created by Steven Turner on 11/4/24.
//
#include <iostream>
#include "queueStructure.h"

int main() {
    CircularQueue<int> intQueue; // Create a queue of integers

    // Push 10 values into the queue
    intQueue.push(5);
    intQueue.push(2);
    intQueue.push(8);
    intQueue.push(1);
    intQueue.push(7);
    intQueue.push(3);
    intQueue.push(9);
    intQueue.push(4);
    intQueue.push(10);
    intQueue.push(6);

    // Displaying all elements in the queue
    std::cout << "Queue elements: ";


    CircularQueue<int> tempQueue; // Temporary queue for displaying

    // Pop elements one by one and print them
    while (!intQueue.empty()) {
        int value = intQueue.front(); // Get front element
        std::cout << value << " ";     // Display front element
        tempQueue.push(value);          // Push to temporary queue
        intQueue.pop();                 // Remove from original queue
    }

    std::cout << std::endl;

    // Restore elements back to the original queue from tempQueue
    while (!tempQueue.empty()) {
        int value = tempQueue.front(); // Get front element from tempQueue
        intQueue.push(value);          // Push it back to original queue
        tempQueue.pop();               // Remove it from tempQueue
    }

    //rear_to_back
    std::cout << "Moving front element to the rear..." << std::endl;
    std::cout << "Front before moving to rear: " << intQueue.front() << std::endl;

    intQueue.move_to_rear(); // Move front element to the rear

    std::cout << "Front after moving to rear: " << intQueue.front() << std::endl;

    // Displaying all elements in the queue after moving the front to rear
    std::cout << "Queue elements after moving front to rear: ";

    // Using a temporary queue to display the current state of the original queue
    while (!intQueue.empty()) {
        int value = intQueue.front(); // Get front element
        std::cout << value << " ";     // Display front element
        tempQueue.push(value);          // Push to temporary queue
        intQueue.pop();                 // Remove from original queue
    }

    std::cout << std::endl;

    // Restore elements back to the original queue from tempQueue
    while (!tempQueue.empty()) {
        int value = tempQueue.front(); // Get front element from tempQueue
        intQueue.push(value);          // Push it back to original queue
        tempQueue.pop();               // Remove it from tempQueue
    }

    // Displaying all elements in the queue
    std::cout << "Queue before sorting: ";
    for (int i = 0; i < intQueue.size(); i++) {
        std::cout << intQueue.front() << " ";
        intQueue.move_to_rear(); // Move front to rear to display all elements
    }
    std::cout << std::endl;

    // Sort the queue
    intQueue.insertion_sort();

    std::cout << "Queue after sorting: ";
    for (int i = 0; i < intQueue.size(); i++) {
        std::cout << intQueue.front() << " ";
        intQueue.move_to_rear(); // Move front to rear to display all elements
    }
    std::cout << std::endl;


    return 0;
}