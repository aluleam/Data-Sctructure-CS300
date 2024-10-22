#include <iostream>
#include <algorithm>
#include <ctime>
using namespace std;

void insertionSort(int array[], int size);
void merge(int array[], int left, int middle, int right);
void mergeSort(int array[], int left, int right);
int partition(int arr[], int start_index, int end_index);
void printArray(int array[], int size);
void quickSort(int arr[], int low, int high);
void heapify(int array[], int size, int index);
void HeapSort(int array[], int size);

int main()
{
    int *array1, *array2, *array3, *array4;
    
    // Seed for random numbers
    srand(static_cast<unsigned int>(time(nullptr)));

    // Array sizes
    int array_sizes[] = {75000,750000,7500000};
    int size;

    // Loop over array sizes
    for (int i = 0; i < 3; i++) {
        size = array_sizes[i];
        array1 = new int[size];
        array2 = new int[size];
        array3 = new int[size];
        array4 = new int[size];

        // Fill arrays with random values
        for (int j = 0; j < size; ++j)
        {
            array1[j] = rand() % size;
            array2[j] = array1[j];
            array3[j] = array1[j];
            array4[j] = array1[j];
        }

        // Output array before sorting
        cout << "Array before sorting of size " << size << ": ";
        if (size < 100) {
            printArray(array1, size);
        }
        cout << endl;
        clock_t start, end;

        // Insertion Sort
        start = clock();
        insertionSort(array1, size);
        end = clock();
        cout << "Insertion Sort: " << double(end - start) / CLOCKS_PER_SEC * 1000 << " milliseconds" << endl;
        if (size < 100) {
            cout << "Sorted: ";
            printArray(array1, size);
        }
        cout << endl;

        // Merge Sort
        start = clock();
        mergeSort(array2, 0, size - 1);
        end = clock();
        cout << "Merge Sort: " << double(end - start) / CLOCKS_PER_SEC * 1000 << " milliseconds" << endl;
        if (size < 100) {
            cout << "Sorted: ";
            printArray(array2, size);
        }
        cout << endl;

        // Quick Sort
        start = clock();
        quickSort(array3, 0, size - 1);
        end = clock();
        cout << "Quick Sort: " << double(end - start) / CLOCKS_PER_SEC * 1000 << " milliseconds" << endl;
        if (size < 100) {
            cout << "Sorted: ";
            printArray(array3, size);
        }
        cout << endl;

        // Heap Sort
        start = clock();
        HeapSort(array4, size); // Use array4 here for Heap Sort
        end = clock();
        cout << "Heap Sort: " << double(end - start) / CLOCKS_PER_SEC * 1000 << " milliseconds" << endl;
        if (size < 100) 
        {
            cout << "Sorted: ";
            printArray(array4, size);
        }
        cout << endl;

        // Free memory allocated for the arrays
        delete[] array1;
        delete[] array2;
        delete[] array3;
        delete[] array4;
    }

    return 0;
}
void insertionSort(int array[], int size)
{
    int j, current_value;
    for (int i = 1; i < size; ++i) {
        current_value = array[i]; // Store current element to be compared
        j = i - 1;
        while (j >= 0 && array[j] > current_value)//Move elements greater than the current value
        {
            array[j + 1] = array[j]; // Shift element to the right
            --j; // Move to the previous element
        }
        array[j + 1] = current_value; //Place the value in correct position
    }
}

void merge(int array[], int first, int middle, int last)
{
    int* temp;
    int num_items;
   
    int first1 = first, last1 = middle;
    int first2 = middle + 1, last2 = last;
    int ftemp = 0;

    
    num_items = last - first + 1;
    temp = new int[num_items]; //Dynamically allocate the temporary array
    
    while ((first1 <= last1) && (first2 <= last2))
    {
        if (array[first1] <= array[first2])
        {
            temp[ftemp++] = array[first1++];
        } else {
            temp[ftemp++] = array[first2++];
        }
    }

    // Copy the remaining elements of the first half if there are any
    while (first1 <= last1)
    {
        temp[ftemp++] = array[first1++];
    }

    // Copy the remaining elements of the second half if there are any
    for (int i = first2; i <= last2; i++)
    {
        temp[ftemp] = array[i];
        ftemp++;
    }

    // Copy the temp array back into the original array
    for (int i = first; i <= last; i++)
    {
        array[i] = temp[i - first];
    }

    delete[] temp; //Free the allocated memory
    return;
}


void mergeSort(int array[], int left, int right)
{
    // Base case
    if (left < right)
    {
        // Calculate the middle index
        int middle = left + (right - left) / 2;

        // Recursively sort the left half of the array
        mergeSort(array, left, middle);

        // Recursively sort the right half of the array
        mergeSort(array, middle + 1, right);

        // Merge the sorted halves
        merge(array, left, middle, right);
    }
}

//Function to partition the array
int partition(int arr[], int start_index, int end_index)
{
    int pivot = arr[end_index]; // Select pivot element
    int i = (start_index - 1); // Index of smaller element
    for (int j = start_index; j <= end_index - 1; ++j)
    {
        if (arr[j] < pivot) { // If current element is smaller than pivot
            ++i; // Increment index of smaller element
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[end_index]);
    return (i + 1); // Return index of partition
}

// Function to perform quicksort
void quickSort(int arr[], int low, int high)
{
    if (low < high) {  // If there are elements to sort
        int partition_index = partition(arr, low, high); // Get partition index
        quickSort(arr, low, partition_index - 1); // Recursively sort left partition
        quickSort(arr, partition_index + 1, high); // Recursively sort right partition
    }
}

void heapify(int array[], int size, int index) 
{
    int largest = index;
    int left = 2 * index + 1; // left child index
    int right = 2 * index + 2; // right child index

    // If left child is larger than root
    if (left < size && array[left] > array[largest])
        largest = left;

    // If right child is larger than current largest
    if (right < size && array[right] > array[largest])
        largest = right;

    // If largest is not root
    if (largest != index)
    {
        swap(array[index], array[largest]); //Swap root with largest
        heapify(array, size, largest); // Recursively heapify
    }
}

// Function to perform heap sort
void HeapSort(int array[], int size) {
    // Build heap from the array
    for (int index = size / 2 - 1; index >= 0; index--)
    {
        heapify(array, size, index);  // Apply heapify to each node
    }
    for (int i = size - 1; i >= 0; i--) 
    {
        swap(array[0], array[i]);  // Move current root to the end
        heapify(array, i, 0);  // Call max heapify on the reduced heap
    }
}


// Function to print the elements of an array
void printArray(int array[], int size)
{
    for (int i = 0; i < size; ++i) // Loop through array elements
        cout << array[i] << " "; // Print current element
    cout << endl << endl;
}
