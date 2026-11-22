
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define JUMLAH_UJI 3

// Fungsi Bubble Sort
void bubbleSort(int arr[], int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Fungsi Insertion Sort
void insertionSort(int arr[], int n) {
    int key, j;
    for (int i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Fungsi Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;
        int temp;

        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;

        int pi = i + 1;

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Menyalin data
void salinData(int sumber[], int tujuan[], int n) {
    for (int i = 0; i < n; i++) {
        tujuan[i] = sumber[i];
    }
}

int main() {
    int ukuran[JUMLAH_UJI] = {1000, 16000, 64000};

    printf("=============================================\n");
    printf("   PERBANDINGAN ALGORITMA SORTING\n");
    printf("=============================================\n");

    srand((unsigned int)time(NULL));

    for (int u = 0; u < JUMLAH_UJI; u++) {
        int n = ukuran[u];

        int *data = malloc(n * sizeof(int));
        int *arr = malloc(n * sizeof(int));

        if (data == NULL || arr == NULL) {
            printf("Gagal mengalokasikan memori!\n");
            free(data);
            free(arr);
            return 1;
        }

        // Membuat data acak
        for (int i = 0; i < n; i++) {
            data[i] = rand() % 100000;
        }

        clock_t mulai, selesai;
        double waktuBubble, waktuInsertion, waktuQuick;

        // Bubble Sort
        salinData(data, arr, n);
        mulai = clock();
        bubbleSort(arr, n);
        selesai = clock();
        waktuBubble = (double)(selesai - mulai) / CLOCKS_PER_SEC;

        // Insertion Sort
        salinData(data, arr, n);
        mulai = clock();
        insertionSort(arr, n);
        selesai = clock();
        waktuInsertion = (double)(selesai - mulai) / CLOCKS_PER_SEC;

        // Quick Sort
        salinData(data, arr, n);
        mulai = clock();
        quickSort(arr, 0, n - 1);
        selesai = clock();
        waktuQuick = (double)(selesai - mulai) / CLOCKS_PER_SEC;

        printf("\nJumlah Data: %d\n", n);
        printf("---------------------------------------------\n");
        printf("Bubble Sort    : %.6f detik\n", waktuBubble);
        printf("Insertion Sort : %.6f detik\n", waktuInsertion);
        printf("Quick Sort     : %.6f detik\n", waktuQuick);

        free(data);
        free(arr);
    }

    printf("\n=============================================\n");
    printf("          PENGUJIAN SELESAI\n");
    printf("=============================================\n");

    return 0;
}
