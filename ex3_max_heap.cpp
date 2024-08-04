#include <iostream>
#include <vector>

class MaxHeap {
private:	
    std::vector<int> heap;

    void heapifyUp(int index) {
        // Compare with parent and swap if needed
        while (index > 0 && heap[index] > heap[(index - 1) / 2]) {
            std::swap(heap[index], heap[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }

    void heapifyDown(int index) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int largest = index;

        if (leftChild < heap.size() && heap[leftChild] > heap[largest])
            largest = leftChild;
        if (rightChild < heap.size() && heap[rightChild] > heap[largest])
            largest = rightChild;

        if (largest != index) {
            std::swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    int pop() {
        if (heap.empty()) return -1;
        int root = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return root;
    }

    void display() {
        for (int val : heap)
            std::cout << val << " ";
        std::cout << std::endl;
    }
};

int main() {
    MaxHeap maxHeap;
    maxHeap.insert(10);
    maxHeap.insert(20);
    maxHeap.insert(5);
    maxHeap.insert(15);

    std::cout << "Max Heap: ";
    maxHeap.display();

    int deleted = maxHeap.pop();
    std::cout << "Deleted element: " << deleted << std::endl;
    std::cout << "Max Heap after deletion: ";
    maxHeap.display();

     return 0;
}