#include <stdio.h>

void clear_keyboard_buffer(void);

#define SIZE 100

int main(int argc, char* argv[])
{
    int array[SIZE];
    FILE* fp;
    char c;
    int i, j;
    
    fp = fopen("numbers.txt", "r");
    
    for (i = 0; i < 29; i++)
    {
        fscanf(fp, "%d", &j);
        array[i] = j;
        fprintf(stdout, "%d\n", array[i]);
    }
    //fprintf(fp, "Hello class!\n");
    
    fclose(fp);
    
    return 0;
}

void clear_keyboard_buffer(void)
{
    char c;
    
    do
    {
        scanf("%c", &c);
    } while (c != '\n');
    
}