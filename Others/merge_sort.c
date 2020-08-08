#include <limits.h>
#include <stdio.h>
#include <string.h>

void merge_sort(int *array, int begining, int end);
void merge(int *array, int begining, int middle, int end);

int main(void) {
    int n;
    scanf("%d", &n);
    int array[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &array[i]);

    merge_sort(array, 0, n - 1);

    for (int i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("\n");

    return 0;
}

void merge_sort(int *array, int begining, int end) {
    if (begining < end) {
        int middle = (begining + end) / 2;

        merge_sort(array, begining, middle);
        merge_sort(array, middle + 1, end);
        merge(array, begining, middle, end);
    }
}

void merge(int *array, int begining, int middle, int end) {
    int left_size = middle - begining + 1;
    int right_size = end - middle;

    int left[left_size];
    int right[right_size];

    for (int i = 0, j = begining; j <= middle; i++, j++)
        left[i] = array[j];

    for (int i = 0, j = middle + 1; j <= end; i++, j++)
        right[i] = array[j];

    int i = 0, j = 0, k = begining;
    while (i < left_size && j < right_size) {
        if (left[i] < right[j])
            array[k++] = left[i++];
        else
            array[k++] = right[j++];
    }

    /* The leftovers */
    while (i < left_size)
        array[k++] = left[i++];
    while (j < right_size)
        array[k++] = right[j++];
}
