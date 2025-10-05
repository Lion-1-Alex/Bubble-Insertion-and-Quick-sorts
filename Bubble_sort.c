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
    printf("Bubble sort\n");

    int n[50];    //наш массив, который будем сортировать
    for (int i = 0; i < 50; i++) {
        n[i] = rand() % 150;  //случайное число от 0, 99
    }
    int l = sizeof(n) / sizeof(n[0]);       //размер массива

    FILE *file = fopen("/Users/aleksandrrubcov/Desktop/HomeWork/laba3/BubbleSort/Bubble.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    save_step(n, l, file);

    for (int j = 0; j < l; j++) {
        for (int i = 0; i < l - j - 1; i++) {
            int tmp = n[i];
            if (tmp > n[i + 1]) {
                n[i] = n[i + 1];
                n[i + 1] = tmp;
                save_step(n, l, file);
            }
        }
    }
    fclose(file);
    for (int j = 0; j < l; j++) {
        printf("%d ", n[j]);
    }
    return 0;
}
