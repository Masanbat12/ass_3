#include "main.h"


int main()
{
    int i = 0;
    char ch = 0;
    int *inputStream = calloc(i, sizeof(*inputStream));
    int size=0;
    for (i = 0; (ch = getchar()) != '\n'; i++)
    {
        size++;
        inputStream = realloc(inputStream, ((i + 1) * sizeof(*inputStream)));
        *(inputStream + i) = (int)(ch-48);
    }


    for (int i = 0; i < size; i++)
    {
        printf("%d ",*(inputStream+i));
    }
    
    int arr[3] = {2, 3, 1};
    int len = sizeof(arr) / sizeof(arr[0]);

    insertion_sort(arr, len);

    for (int i = 0; i < len; i++)
    {
        if (i == len - 1)
            printf("%d", arr[i]);
        else
            printf("%d ", arr[i]);
    }
    puts("");

    char a[LINE];
    int aa = getLine(a);
    char b[WORD];
    int bb = getWord(b);
    printf("%s, %d", a, aa);
    printf("%s, %d", b, bb);
    return 1;
}
/*
cat a

this is a text file
looking for the word cat
the program should print also cats
and crat and lcat but it shouldn't
print the word caats
*/