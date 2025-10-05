#include <stdio.h>
#include <stdlib.h>

void save_step(int arr[], int size, FILE *file) {
    for (int i = 0; i < size; i++) {
        fprintf(file, "%d", arr[i]);
        if (i < size - 1) fprintf(file, " ");
    }
    fprintf(file, "\n");
}

int main(){
    printf("Insertion sort\n");

    int n[50];    //наш массив, который будем сортировать
    for (int i = 0; i < 50; i++) {
        n[i] = rand() % 150;  //случайное число от 0, 99
    }
    int l = sizeof(n) / sizeof(n[0]);       //размер массива

    FILE *file = fopen("/Users/aleksandrrubcov/Desktop/HomeWork/laba3/InsertionSort/Insertion.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    save_step(n, l, file);

    for (int j = 1; j < l; j++) {
        int tmp = n[j];
        int loc = j - 1;
        while (loc >= 0 && n[loc] > tmp) {
            n[loc + 1] = n[loc];
            loc = loc - 1;
        }
        n[loc + 1] = tmp;
        save_step(n, l, file);
    }
    fclose(file);
    for (int i = 0; i < l; i++) {
        printf("%d ", n[i]);
    }

    return 0;
}