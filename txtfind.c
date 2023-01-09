#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#define LINE 256
#define WORD 30
//Authors : Aaron Luchan and Masanbat Mulo
//This part is done according to the assignment instructions and stamp functions
int getLine(char s[])
{
    char *temp = s;
    int counter1 = 0;
    char c = getc(stdin);

    while (c != '\n' && !feof(stdin))
    {
        temp[counter1] = c;
        counter1++;
        c = getc(stdin);
    }
    return counter1;
}

int getword(char w[])
{

    int counter2 = 0;

    for (int i = 0; i < WORD; i++)
    {
        scanf("%c", &w[i]);

        if (w[i] != ' '  && w[i] != '\t'&& w[i] != '\n')
        {
            counter2++;
        }
    }
    return counter2;
}

int substring(char *str1, char *str2)
{
    char *isIn;
//strstr is a function that finds the first occurrence of the substring str2 in the string str1.
    isIn = strstr(str1, str2);
    if (isIn)
        return 1;
    else
        return 0;
}

int similar(char *s, char *t, int n)
{
    int S_length = strlen(s);
    int T_length = strlen(t);

    // the ways that cannot be possible to be
    if (S_length < T_length || T_length + n < S_length)
        return 0;

    int i = 0, j = 0;
    while (i < S_length && j < T_length)
    {
        if (s[i] == t[j])
            j++;
        i++;
    }
    // if all characters in t were found in s return 1
    if (j == T_length)
        return 1;
    else
        return 0;
}
//function to print thr lines when the string we find appears
void print_lines(char *str)
{
    char *x;
    x = (char *)calloc(LINE, sizeof(char));
    if (x == NULL)
    {
        return;
    }
    bzero(x, sizeof(char) * LINE);

    int counter = getLine(x);
    while (!feof(stdin) || counter > 0)
    {
        if (substring(x, str) == 1)
        {
            printf("%s\n", x);
        }
        bzero(x, sizeof(char) * LINE);
        counter = getLine(x);
    }
    free(x);
}

//function to print the words that are similar to the string
void print_similar_words(char *str) {
    char word[WORD]; 
    while (getword(word) > 0) { 
        if (similar(word, str, 1)) { 
            printf("%s\n", word); 
        }   
    }
}

// This main function will run the program
int main(void)
{
    char *line_1 = (char *)calloc(LINE, sizeof(char));
    if (line_1 == NULL)
    {
        return 1;
    }
    char *str = (char *)calloc(WORD, sizeof(char));
    if (str == NULL)
    {
        return 1;
    }
    // gets the line number 1 from the input
    fgets(line_1, LINE * sizeof(char), stdin);
    char func;
    bzero(&func, sizeof(char));
    int counter = 0;

    while (line_1[counter] != ' ')
    {
        str[counter] = line_1[counter];
        counter++;
    }

    while (line_1[counter] != '\n')
    {
        func = line_1[counter];
        counter++;
    }

    // is to skip the next line because is empty
    getLine(NULL);
    //According to the instructions of the assignment
    if (func == 'a')
    {
        print_lines(str);
    }
    if (func == 'b')
    {
        print_similar_words(str);
    }
    free(line_1);
    free(str);

    return 0;
}
