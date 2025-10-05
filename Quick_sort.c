#include <stdio.h>
#include <stdlib.h>

void save_step(int arr[], int size, FILE *file) {
    for (int i = 0; i < size; i++) {
        fprintf(file, "%d", arr[i]);
        if (i < size - 1) fprintf(file, " ");
    }
    fprintf(file, "\n");
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high, FILE *file) {
    int pivot = arr[high];  // Выбираем последний элемент как опорный

    int i = (low - 1);  // Индекс меньшего элемента

    for (int j = low; j <= high - 1; j++) {
        // Если текущий элемент меньше или равен опорному
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
            save_step(arr, high + 1, file);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    save_step(arr, high + 1, file);
    return (i + 1);
}

void quickSort(int arr[], int low, int high, FILE *file) {
    if (low < high) {

        int pi = partition(arr, low, high, file);

        quickSort(arr, low, pi - 1,file);
        quickSort(arr, pi + 1, high, file);
    }
}

int main() {
    printf("Quick sort\n");

    int n[50];    //наш массив, который будем сортировать
    for (int i = 0; i < 50; i++) {
        n[i] = rand() % 150;  //случайное число от 0, 99
    }
    int l = sizeof(n) / sizeof(n[0]);       //размер массива

    FILE *file = fopen("/Users/aleksandrrubcov/Desktop/HomeWork/laba3/QuickSort/Quick.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    save_step(n, l, file);

    quickSort(n, 0, l - 1, file);
    fclose(file);
    for (int i = 0; i < l; i++) {
        printf("%d ", n[i]);
    }
    return 0;
}