/*****************************************
 Author: Sam Pickell
 Date: 11/5/15
 Resubmit Date 1: 11/8/15
 Resubmit Date 2: 11/15/15
 Resubmit Date 3: 11/16/15
 
 Purpose: Merge 2 separate files into
    one.
 
 Reason for Resubmit 1: Previously the
    program would print infinitely if
    a file was empty or would not write
    to "output.txt".
 
 Reason for Resubmit 2:
    1. Declared variables that were at
        line 95 at the start of main.
    2. Initialized the file pointers in
        main before passing them, and
        made sure to check to see if the
        input files would open.
    3. Every time a number prints, it is
        followed by a space and a new line.
 
 Reason for Resubmit 3: Grader said that the 
    program did not write to the output file.
    On my computer, it has been outputting.
    One of the graders (after attempt 2) was
    able to recieve output, but not in the 
    format that I specified. On my computer,
    when the program writes to the output
    file, it prints the number, a space
    (as requested by grader in attempt 2)
    and then a new line. If there's anything
    I can do to fix this, please point me
    in the right direction. I am using
    XCode on my Mac if that has anything
    to do with it.
 
 Sources of Help: Suggestions and 
    pointers from grader.
 Time Spent: 6 hours 20 minutes
 *****************************************/

#include <stdio.h>

void return_output_number(FILE* numbers1, FILE* numbers2, FILE* output);

void display_remaining_numbers2(int j, int trips_2, FILE* numbers2, FILE* output);

void display_remaining_numbers1(int i, int trips_1, FILE* numbers1, FILE* output);

int main (int argc, char* argv[])
{
    FILE* fp1;
    FILE* fp2;
    FILE* fpOut;
    
    fp1 = fopen("numbers1.txt", "r");
    fp2 = fopen("numbers2.txt", "r");
    fpOut = fopen("output.txt", "w");
    
    if (fp1 == NULL)
    {
        printf("Unable to read file 1, terminating program.");
        return 1;
    }
    
    if (fp2 == NULL)
    {
        printf("Unable to read file 2, terminating program.");
        return 1;
    }
    
    return_output_number(fp1, fp2, fpOut);
    
    fclose(fp1);
    fclose(fp2);
    fclose(fpOut);

    return 0;
}

void return_output_number(FILE* numbers1, FILE* numbers2, FILE* output)
{
    int i, j, k, l, find_file_size_1, find_file_size_2,
        file_size_1 = 0, file_size_2 = 0, extra_nums = 0, loop = 1,
        trips_1, trips_2;
    
    //Find the size of file 1
    
    //try
    find_file_size_1 = fscanf(numbers1, "%d", &k);
    
    //check
    if (find_file_size_1 == 0)
    {
        file_size_1 = 0;
    }
    else
    {
        while (find_file_size_1 == 1)
        {
            //do
            file_size_1 ++;
            //try
            find_file_size_1 = fscanf(numbers1, "%d", &k);
        }
    }
    
    fclose(numbers1);
    
    //Find the size of file 2
    
    //try
    find_file_size_2 = fscanf(numbers2, "%d", &l);
    
    //check
    if (find_file_size_2 == 0)
    {
        file_size_2 = 0;
    }
    else
    {
        while (find_file_size_2 == 1)
        {
            //do
            file_size_2 ++;
            //try
            find_file_size_2 = fscanf(numbers2, "%d", &l);
        }
    }
    
    fclose(numbers2);
    fclose(output);
    
    if (file_size_1 >= file_size_2 + 3 || file_size_2 >= file_size_1 + 3)
    {
        extra_nums = 1;
    }
    
    trips_1 = file_size_1;
    trips_2 = file_size_2;
    
    numbers1 = fopen("numbers1.txt", "r");
    numbers2 = fopen("numbers2.txt", "r");
    output = fopen("output.txt", "w");
    
    //try
    fscanf(numbers1, "%d", &i);
    fscanf(numbers2, "%d", &j);
    
    if (file_size_1 == 0)
    {
        i = 0;
        trips_2 ++;
        display_remaining_numbers2(j, trips_2, numbers2, output);
        fclose(numbers1);
        fclose(numbers2);
        fclose(output);
        return;
    }
    else if (file_size_2 == 0)
    {
        j = 0;
        trips_1 ++;
        display_remaining_numbers1(i, trips_1, numbers1, output);
        fclose(numbers1);
        fclose(numbers2);
        fclose(output);
        return;
    }
    
    if (file_size_1 != 0 && file_size_2 != 0)
    {
        //check
        while (loop == 1)
        {
            while (i < j)
            {
                //do
                fprintf(output, "%d \n", i);
        
                //try
                fscanf(numbers1, "%d", &i);
            
                if (i > j)
                {
                    break;
                }
            
                trips_1 --;
            
                if (trips_1 == 1)
                {
                    if (extra_nums == 0)
                    {
                        display_remaining_numbers2(j, trips_2, numbers2, output);
                        loop = 0;
                        break;
                    }
                    else if (extra_nums == 1)
                    {
                        display_remaining_numbers2(j, trips_2 - 1, numbers2, output);
                        loop = 0;
                        break;
                    }
                }
            }
            while (j < i)
            {
                //do
                fprintf(output, "%d \n", j);
            
                //try
                fscanf(numbers2, "%d", &j);
            
                if (j > i)
                {
                    break;
                }
        
                trips_2 --;
        
                if (trips_2 == 1)
                {
                    if (extra_nums == 0)
                    {
                        display_remaining_numbers1(i, trips_1, numbers1, output);
                        loop = 0;
                        break;
                    }
                    else if (extra_nums == 1)
                    {
                        display_remaining_numbers1(i, trips_1 - 1, numbers1, output);
                        loop = 0;
                        break;
                    }
                }
            }
        }
    }
    
    fclose(numbers1);
    fclose(numbers2);
    fclose(output);
}

void display_remaining_numbers2(int j, int trips_2, FILE* numbers2, FILE* output)
{
    while (trips_2 != 1)
    {
        //do
        fprintf(output, "%d \n", j);
        
        //try
        fscanf(numbers2, "%d", &j);
        
        trips_2 --;
    }
}

void display_remaining_numbers1(int i, int trips_1, FILE* numbers1, FILE* output)
{
    while (trips_1 != 1)
    {
        //do
        fprintf(output, "%d \n", i);
        
        //try
        fscanf(numbers1, "%d", &i);
        
        trips_1 --;
    }
}



