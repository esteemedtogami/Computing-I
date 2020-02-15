/********************************************
 Author: Sam Pickell
 Date: 11/4/15
 
 Purpose: Read from a file and calculate data
    based on its contents.
 
 Sources of Help: A few emails from Dr. Adams
 
 Time Spent: 1 hr 46 min
********************************************/

#include <stdio.h>

int main(int argc, char* argv[])
{
    FILE* fp;
    int i, j, number = 0, count = 0, sum = 0, smallest_num, largest_num, find_file_size, file_size = 0;
    
    fp = fopen("numbers.txt", "r");
    
    //try
    find_file_size = fscanf(fp, "%d", &number);
    
    
    //check
    while (find_file_size == 1)
    {
        //do
        file_size ++;
        
        //try
        find_file_size = fscanf(fp, "%d", &number);
    }
    
    fclose(fp);
    
    fopen("numbers.txt", "r");
    
    fscanf(fp, "%d", &j);
    count ++;
    sum += j;
    smallest_num = j;
    largest_num = j;
    
    for (i = 1; i < file_size; i++)
    {
        fscanf(fp, "%d", &j);
        count ++;
        sum += j;
        if (j < smallest_num)
        {
            smallest_num = j;
        }
        if (j > largest_num)
        {
            largest_num = j;
        }
    }
    
    fprintf(stdout, "There were %d numbers in the file.\n", count);
    fprintf(stdout, "The sum of all the integers in the file is: %d\n", sum);
    fprintf(stdout, "The smallest integer in the file is: %d\n", smallest_num);
    fprintf(stdout, "The largest integer in the file is: %d\n", largest_num);
    fprintf(stdout, "The average of all the numbers is: %f\n", (double)sum / count);
    
    fclose(fp);
    
    return 0;
}
