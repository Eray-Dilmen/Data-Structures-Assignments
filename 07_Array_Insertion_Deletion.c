#include <stdio.h>




void printArray(int arr[], int size) {
    printf("Current Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}





void insertElement(int arr[], int *size, int position, int value) {

    if (*size >= 100) {
        printf("Error: Array is full, cannot insert.\n");
        return;
    }

    if (position < 0 || position > *size) {
        printf("Error: Invalid position!\n");
        return;
    }

    for (int i = *size; i > position; i--) {
        arr[i] = arr[i - 1];
    }

    arr[position] = value;
    (*size)++;
    printf("Inserted %d at position %d.\n", value, position);
}





void deleteElement(int arr[], int *size, int position) {

    if (*size <= 0) {
        printf("Error: Array is empty.\n");
        return;
    }

    if (position < 0 || position >= *size) {
        printf("Error: Invalid position!\n");
        return;
    }

    int deletedValue = arr[position];

    for (int i = position; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    (*size)--;
    printf("Deleted value %d from position %d.\n", deletedValue, position);
}




int main() {

	/// HW 7: Adding and deleting operations in arrays

/* Logic behind insertion and deletion operations in an Array is shifting.
// When inserting, we need to shift elements to the right;
 when deleting, we need to shift them to the left. */


    int arr[100] = {10, 20, 30, 40, 50};
    int size = 5;

    printArray(arr, size);


    printf("\n--- Operation: Insertion ---\n");
    insertElement(arr, &size, 2, 99);
    printArray(arr, size);

    printf("\n--- Operation: Deletion ---\n");
    deleteElement(arr, &size, 4);
    printArray(arr, size);

    return 0;
}