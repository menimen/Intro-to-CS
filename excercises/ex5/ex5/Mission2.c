/******************************************
*Student name: name and family name
*Student ID:XXXX
*Submit Info:XXXX
*Exercise name: exXXXX
******************************************/

#include "Mission2.h"

/************************************************************************
 Fill comment
*************************************************************************/
int sweetCookies(int cookies[], int n, int K)
{
    int j = 0, count = 0;
	quickSort(cookies, 0, n-1);
    int limit = findTheLimit(cookies, n, K);
    if (limit == 0 && cookies[limit] >= K) {
        return count;
    }
    if (limit == 0 && cookies[limit] < K) {
        return -1;
    }
    if (limit == n-1 && cookies[j] >= K) {
        return count;
    }
    while (j < limit && cookies[j] < K) {
        cookies[j+1] = SpecialCombineCookie(cookies[j], cookies[j+1]);
        quickSort(cookies, 0, n-1);
        j++;
        count++;
    }
    for (int k = j; k < n; k++) {
        if (cookies[k] < K) {
            return -1;
        }
    }
	return count;
}
int SpecialCombineCookie(int num1, int num2) {
   return ((1 * num1) + (2 * num2));
}

/************************************************************************
 Fill comment
*************************************************************************/
void mission2()
{
	int n, sweet;
	int cookies[NUMOFCOOKIES];
	int i;
	int result;

	printf("Please enter the amount of cookies:\n");
	scanf("%d", &n);
	printf("Please enter the minimum required sweetness:\n");
	scanf("%d", &sweet);

	for (i = 0; i < n; i++)
	{
		printf("Please enter cookie number %d:\n", i + 1);
		scanf("%d", &cookies[i]);
	}
	result = sweetCookies(cookies, n, sweet);
	printf("The number of operations that are needed is %d\n", result);
}
void swap(int* a, int* b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
int findTheLimit(int arr[], int n, int K) {
    int *p = arr, i = 0;
    while((*p <= K) && i <= n-1) {
        i++;
    }
    if (i == n) {
        return n-1;
    }
    return i;
}
int partition (int arr[], int low, int high)
{
    int pivot = arr[high]; // pivot
    int i = (low - 1); // Index of smaller element

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (arr[j] < pivot)
        {
            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
        at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
