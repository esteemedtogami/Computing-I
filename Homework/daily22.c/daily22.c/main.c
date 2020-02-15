#include <stdio.h>

void clear_keyboard_buffer(void);

int main(int argc, char* argv[])
{
    FILE* fp;
    char c;
    int i;
    
    fp = fopen("numbers.txt", "r");
    
    for (i = 0; i < 29; i++)
    {
        fscanf(fp, "%c", &c);
        fprintf(stdout, "%c", c);
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