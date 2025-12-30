#include <stdio.h>


int heap[100];
int size = 0;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}





void heapify(int array[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && array[left] > array[largest])
        largest = left;

    if (right < n && array[right] > array[largest])
        largest = right;


    if (largest != i) {
        swap(&array[i], &array[largest]);
        heapify(array, n, largest);
    }
}





void insert(int array[], int newNum) {
    if (size == 0) {
        array[0] = newNum;
        size += 1;
    } else {
        array[size] = newNum;
        size += 1;

	for (int i = size - 1; i > 0; i = (i - 1) / 2) {
		int parent = (i - 1) / 2;
	if (array[parent] < array[i]) {
		swap(&array[parent], &array[i]);
		}
	 else
		{
			break;
		}
		}
    }
}





void deleteRoot(int array[]) {
    if (size == 0) {
        printf("Heap is empty, cannot delete.\n");
        return;
    }

   int deletedElement = array[0];

    array[0] = array[size - 1];
    size -= 1;

    heapify(array, size, 0);

    printf("Deleted root element: %d\n", deletedElement);
}





void printHeap(int array[], int size) {
    printf("Current Heap: ");
    for (int i = 0; i < size; ++i)
        printf("%d ", array[i]);
    printf("\n");
}





int main() {


		/// HW 4: Max, Min Heap Code




    insert(heap, 3); insert(heap, 9); insert(heap, 2); insert(heap, 1); insert(heap, 4); insert(heap, 5);

    printf("--- Max Heap Created ---\n");
    printHeap(heap, size);

    printf("\n--- Deleting Root ---\n");
    deleteRoot(heap);
    printHeap(heap, size);

    printf("\n--- Deleting Root Again ---\n");
    deleteRoot(heap);
    printHeap(heap, size);



/*
The Heap data structure is the foundation of Priority Queues and the Heap Sort algorithm. It is usually implemented using an array.
Max Heap: Every node is greater than or equal to its children. The root is the largest element.
Min Heap: Every node is less than or equal to its children. The root is the smallest element.
The code below is a standard Max Heap implementation (including Insertion and Deletion operations).
Tip to convert to Min Heap: It is sufficient to simply swap the comparison operators in the code ( '>' instead of '<' or reverse one).
*/

    return 0;
}