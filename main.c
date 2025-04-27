#include <stdio.h>

/*
    This program reads input from the user in the form of student name and 13 test scores
    Calculates the highest average and the total average of all students
    Prints the name of the student with the highest average
    Prints the name of the students with an average below the median

    Written by Jonas Persson, 27.05.2025
*/

//function declaration
void add_students(char names[5][11], int scores[5][13]);
void print_student(char name[11]);
float calculate_average(int results[]);
float total_averages(float averages[]);
int highest_average(float avg[]);
void capital_letter(char names[11]);

/*
    Main function
*/
int main(){
    //declare variables
    char names[5][11];
    int scores[5][13];
    float averages[5];
    int highest_avg_index = 0;
    float total_avg = 0;

    //add students and test score to program
    add_students(names, scores);

    //calculates the average of each student
    for (int i =0 ; i < 5; i++){
        averages[i] = calculate_average(scores[i]);
    }

    //gets the index of the student with the highest average
    highest_avg_index = highest_average(averages);
    //Calculates the total average of all students
    total_avg = total_averages(averages);
    //Prints the student with the highest average
    print_student(names[highest_avg_index]);
    //Goes through each student and checks if their avg is lower than the median
    //if it is, print the name of the student
    for (int i = 0; i < 5; i++){
        if (averages[i] < total_avg){
            print_student(names[i]);
        }
    }

    return 0;
}

/*
    Reads input, five lines of names and test scores and saves into 2d arrays
    The input is expected as this: Name s1 s2 s3 s4 s5 s6 s7 s8 s9 s10 s11 s12 s13
    Expected number of lines: 5
    Goes through and saves name in one array and test scores in another array using scanf
*/
void add_students(char names[5][11], int scores[5][13]){

    for (int i = 0; i < 5; i++){

        scanf("%s", names[i]);

        for( int j = 0; j < 13; j++)
        {
            scanf("%d", &scores[i][j]);
        }
    }
}

/*
    Calculates the average score from an array
    Goes through an array with 13 test scores
    Sumss them together
    Gets the average by dividing the sum with 13.0
    Returns the average as a float
*/
float calculate_average(int results[]){
    float avg;
    int sum = 0;

    for(int i = 0; i < 13; i++){
       sum += results[i];
    }

    avg = sum / 13.0;

    return avg;
}

/*
    Calculates the highest average
    Goes through 5 different averages
    if the current avg index is highes than the variable highest
    saves the averages into highest
    gets the index of the highest average
    Returns the index as an int
*/
int highest_average(float avg[]){
    float counter = 5;
    float highest = 0;
    int top_index = 0;

    for (int i = 1; i < counter; i++){
        if (avg[i] > highest){
            highest = avg[i];
            top_index = i;
        }
    }

    return top_index;
}

/*
    Returns the total average for all students
    Sums together individual averages
    divides the sum of averages with 5.0
    returns the total average as a float
*/
float total_averages(float averages[]){
    float sum = 0;
    for (int i = 0; i < 5; i++){
        sum += averages[i];
    }
    return sum / 5.0;
}

/*
    Capitalises the first letter of a student name
    Checks if the first letter is greater or equal to lower case a
    and if the first letter is less or equal to 'z'
    If so, removes 32 (ASCII table) to capitalise the letter
*/
void capital_letter(char names[11]){

    if (names[0] >= 'a' && names[0] <= 'z'){
        names[0] -= 32;
    }

}

/*
    Prints the name of a student
    Capitalises the first letter if not already capitalised at input
*/
void print_student(char name[11]){
        capital_letter(name);
        printf("%s\n", name);
}