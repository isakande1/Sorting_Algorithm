#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
void selectionsort(int *arr, size_t size){
size_t i,j,temp,min;
min = arr[0];
for(i = 0; i < size - 1; i++){
for(j = i; j < size ; j++){
        if(arr[j] < arr[min]){
            min  = j;
       }
}
temp = arr[i];
arr[i] = arr[min];
arr[min] = temp;

}

}


void insertionsort(int arr[],size_t size) {
    size_t  i;
    int j = 0, temp ;
    for(i = 1; i < size  ; i++ ) {
        temp = arr[i];
        j = i -1;
        while ( j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
     }
}

void merge(int *arr, int *leftarr, int *rightarr,size_t leftl, size_t rightl) {

    size_t i = 0, j = 0, k = 0;
    while (j < leftl && k < rightl) {
        if (leftarr[j] < rightarr[k]) {
            arr[i] = leftarr[j];
            j++;
        } else {
            arr[i] = rightarr[k];
            k++;
        }
     i++;
    }
    while (j < leftl){
        arr[i] = leftarr[j];
    j++;i++;
    }
    while(k<rightl) {
        arr[i] = rightarr[k];
        k++;i++;
    }

}
void mergesort( int *arr, size_t arrlenght){
    int *leftarr = NULL, *rightarr = NULL;
    size_t leftl,  rightl, i ;
    if(arrlenght == 1)
        return;
    leftl = arrlenght / 2;
    rightl = arrlenght - leftl;
    leftarr  = malloc(sizeof(int) * leftl);
    rightarr = malloc(sizeof(int) * rightl);
    for( i =0; i < rightl ; i++) {
        if(i < leftl)
            leftarr[i] = arr[i];
        rightarr[i] = arr[(leftl + i)];
    }
    mergesort(leftarr, leftl);
    mergesort(rightarr, rightl);
    merge(arr, leftarr, rightarr,leftl,rightl);
   free(leftarr); free(rightarr);
}
void quicksort(int *arr,int start, int end) {
    int pivot, i = start, j, e, k = end,sump, temp;
    j = (end-start)/2;
    if(j<=0) {
        return;
    }
    sump = (arr[i] + arr[j]+arr[k] + (3-1)) /3;
    if(sump == arr[i]) {
        pivot = i;
    }else if(sump == arr[j]) {
        pivot = j;
    }else {
        pivot = k;
    }
    temp = arr[end];
    arr[end] = arr[pivot];
    arr[pivot] = temp;
    pivot = end;
    j = start - 1;
    for(e =start; e <= end - 1; e++) {
        if(arr[e] < arr[pivot]) {
            j++;
            temp = arr[j];
            arr[j] = arr[e];
            arr[e] = temp;
        }
    }
    j++;
    temp = arr[j];
    arr[j] = arr[e];
    arr[e] = temp;
    pivot = j;
    quicksort(arr,start ,pivot- 1);
    quicksort(arr,pivot + 1,end);
}



void display(int *p, size_t size){
 size_t i;
 for(  i = 0  ; i < size ; i++){
    printf("%d ", p[i]);
}
}
int findMax(int arr[], int n) {
    int max = arr[0], i;
    for (i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

/* Function to perform counting sort based on a specific digit*/
void countSort(int arr[], int n, int exp) {
    int *output = malloc(sizeof(int) * n);
    int count[10] = {0};
    int i;
    /* Count the occurrences of each digit at the specified position*/
    for (i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    /*Update the count array to store the actual position of each digit*/
    for ( i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    /*Build the output array using the count array*/
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    /*Copy the output array back into the original array*/
    for (i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

/* Radix Sort function*/
void radixSort(int arr[], int n) {
    int max;
    int exp;
    max =  findMax(arr, n);
    for (exp = 1; max / exp > 0; exp *= 10) {
        countSort(arr, n, exp);
    }

}



/*end*/

int main(void){
   /* size_t s = 0;*/
    FILE *f = fopen("rand100000000.txt","r");
    int digit;
    clock_t start, end;
    int run;
    int x;
    int size = 100000000;
    int *array= malloc(sizeof(int) * size);
    int *array2= malloc(sizeof(int) * size);
    int *array3= malloc(sizeof(int) * size);
    int *array4= malloc(sizeof(int) * size);
    for(x = 0; fscanf(f,"%d", &digit) != EOF; x++) {
        array[x] = digit;
        array2[x] = digit;
        array3[x] = digit;
        array4[x] = digit;
    }
    /* int size = sizeof(array)/sizeof(array[0]);*/
     printf("%s %d\n","Runtime for size:", size);
    /* selectionsort(array,size);*/
    /* start = clock();
     insertionsort(array,size);
     end = clock();
     run  = (((end - start) / CLOCKS_PER_SEC) * 1000);
    printf("%s, %d\n", "InsertionSort runtime", run);*/

     start = clock();
     mergesort(array2,size);
     end = clock();
    run  = (((end - start) / CLOCKS_PER_SEC) * 1000)  ;
    printf("%s, %d\n", "MergeSort runtime", run);

     start = clock();
     quicksort(array3,0,(size-1));
     end = clock();
    run  = (((end - start) / CLOCKS_PER_SEC) * 1000)  ;
    printf("%s, %d\n", "QuickSort runtime", run);

    start = clock();
    radixSort(array4,size);
    end = clock();
    run  = (((end - start) / CLOCKS_PER_SEC) * 1000) ;
    printf("%s, %d\n", "RadixSort runtime", run);
  /* display(&array4[0], size)*/;
free(array); free(array2); free(array3); free(array4);
    return 0;
}
