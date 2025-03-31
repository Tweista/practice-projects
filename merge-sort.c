#include <stdio.h>

void merge_sort(int a[], int length);
void recursive_split(int a[], int left, int right);
void merge_elements(int a[], int left, int middle, int right);

int main(void)
{
    int array[] = {8, 5, 2, 10, 9, 6, 3, 7, 4, 1, 11};
    int length = 11;

    merge_sort(array, length);

    for (int i = 0; i < length; i++)
    {
        printf("%i ", array[i]);
    }
    printf("\n");
}

void merge_sort(int a[], int length)
{
    recursive_split(a, 0, length - 1);
}

void recursive_split(int a[], int left, int right)
{
    if (left < right)
    {
        int middle = left +(right - left) / 2;

        recursive_split(a, left, middle);
        recursive_split(a, middle + 1, right);
        merge_elements(a, left, middle, right);
    }
}

void merge_elements(int a[], int left, int middle, int right)
{
    int left_length = middle - left + 1;
    int right_length = right - middle;

    int temp_left[left_length];
    int temp_right[right_length];

    int i, j, k;

    for (i = 0; i < left_length; i++)
    {
        temp_left[i] = a[left + i];
    }
    for (i = 0; i < right_length; i++)
    {
        temp_right[i] = a[middle + 1 + i];
    }

    for (i = 0, j = 0, k = left; k <= right; k++)
    {
        if ((i < left_length) && (j >= right_length || temp_left[i] <= temp_right[j]))
        {
            a[k] = temp_left[i];
            i++;
        }
        else
        {
            a[k] = temp_right[j];
            j++;
        }
    }
}
