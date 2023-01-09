#include <stdio.h>

#define array_size 50
//Authors : Aaron Luchan and Masanbat Mulo
//This part is done according to the assignment instructions and stamp functions

// Function that make one shift to the right in array: 
void shift_element(int *arr, int i) {
  for (int j = 0; j < i; j++) {
    int temp = *(arr + j);
    *(arr + j) = *(arr + j + 1);
    *(arr + j + 1) = temp;
  }
}

// Function that implement insertion sort algorithm: (dont have to be by shift_element)
void insertion_sort(int *arr, int len)
{

  for (int i = 1; i < len; i++)
  {
    int value = *(arr + i);
    int j = i - 1;
    while (j >= 0 && *(arr + j) > value)
    {
      *(arr + j + 1) = *(arr + j);
      j--;
    }
    *(arr + j + 1) = value;
  }
}

// running the program:
int main(){
    
    int raw_arr[array_size] = {0};
    int tmp;
    int i;

    for(i=0; i<array_size; i++){
        scanf("%d", &tmp);
        *(raw_arr+ i) = tmp;  

    }
    insertion_sort(raw_arr, array_size);

    for(i=0; i<array_size-1; i++){
        printf("%d,",*(raw_arr+ i));
    }
    printf("%d\n",*(raw_arr+ array_size-1));

    return 0;
}