#include<stdio.h>
#include<stdlib.h>

void swapNumbers(double * number1, double * number2) {
    int temp = *number1;
    *number1 = *number2;    
    *number2 = temp;
}

double * selectionSort(double * array, int n) {

    int min;
    for (int i=0; i<n-1; i++) {
        min = i;

        for (int j=i+1; j<n; j++) {
            if (array[j] < array[min]) 
                min = j;
        }
    
        swapNumbers(&array[i], &array[min]);
    }
    return array;
}

double * insertionSort(double * array, int n) {
    for (int i=1; i<n; i++) {
        int j=i-1;
        double temp = array[i];

        while (j>=0 && array[j] > temp) {
            array[j+1] = array[j];
            j--;
        }
        j++;
        if (array[j] > temp)
            array[j] = temp;
        for (int i=0; i<n; i++) {
                printf("%Lf ", array[i]);
            }
            printf("\n");
    }
    return array;
}

double * bubbleSort(double * array, int n) {
    for (int i=0; i<n; i++) {
        for (int j=i; j<n; j++) {
            if (array[i] > array[j])
                swapNumbers(&array[i], &array[j]);
        }
    }
    return array;
}

double * mergeArray(double * array1, int length1, double * array2, int length2) {
    int i=0, j=0, k=0;
    double * mergedArray = (double *)malloc(sizeof(double) * (length1 + length2));

    while (i < length1 || j < length2) {
        if (array1[i] < array2[j]) {
            mergedArray[k] = array1[i];
            i++; k++;
        }

        else if (array1[i] > array2[j]) {
            mergedArray[k] = array2[j];
            k++; j++;
        }

        else {
            mergedArray[k] = array1[i];
            k++; i++; j++;
        }
    }
    return mergedArray;
}

double * splitArray(double * array, int start, int end) {
    int j=0;
    int i=start;
    double * splittedArray = (double *)malloc(sizeof(double) * (start + end));

    while (i <= end) {
        splittedArray[j] = array[i];
        j++; i++;
    }

    return splittedArray;
}

double * mergeSort(double * array, int start, int end) {
    int mid = (start + end)/2;
    double * array1 = splitArray(array, start, mid);
    double * array2 = splitArray(array, mid+1, end);
 
    double * returnArray = mergeArray(mergeSort(array1, start, mid), (start + mid + 1), mergeSort(array2, mid+1, end), (end - mid));

    return returnArray;
}

void printArray(int length, double * array) {
    for (int i=0; i<length; i++)
            printf("%lf \n", array[i]);

        printf("\n");
}

int main() {
    int length;
    double * sortedArray;
    int choice;
    double * unsortedArray = (double *)malloc(sizeof(double) * length);

    while (1) {
        printf(" Enter 1 to sort using selection sort\n Enter 2 to sort using insertion sort \n Enter 3 to sort using bubble sort \n Enter 4 to sort using merge sort\n Enter -1 as choice to exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == -1) {
            printf("B'Bye!!\n");
            exit(0);
        }
        
        printf("Enter the number of elements: ");
        scanf("%d", &length);

        printf("Enter the numbers: ");

        for (int i=0; i<length; i++) {
            scanf("%lf", &unsortedArray[i]);
        }

        switch (choice)
        {
        case 1:
            printf("The unsorted array is sorted using selection sort\n");
            sortedArray = selectionSort(unsortedArray, length);
            printArray(length, sortedArray);
            break;
        
        case 2:
            printf("THe unsorted array is sorted using insertion sort\n");
            sortedArray = insertionSort(unsortedArray, length);
            printArray(length, sortedArray);
            break;
        
        case 3:
            printf("The unsorted array is sorted using bubble sort\n");
            sortedArray = bubbleSort(unsortedArray, length);
            printArray(length, sortedArray);
            break;

        case 4:
            printf("The unsorted array is sorted using merge sort");
            sortedArray = mergeSort(unsortedArray, 0, length);
            printArray(length, sortedArray);
            break;
        
        default:
            printf("Unrecognised choice, please enter again.\n");
        }
    }
    return 0;
}