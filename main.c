#include <stdio.h>

//function declaration
void add_students(char names[5][11], int scores[5][13]);
void print_student(char name[11]);
float calculate_average(int results[]);
float total_averages(float averages[]);
int compare_average(float total_avg, float avg[]);
int highest_average(float avg[]);
void capital_letter(char names[11]);

/*
    Main function
*/
int main(){
    char names[5][11];
    int scores[5][13];
    float averages[5];
    int highest_avg_index = 0;
    float total_avg = 0;

    add_students(names, scores);

    for (int i =0 ; i < 5; i++){
        averages[i] = calculate_average(scores[i]);
    }

    highest_avg_index = highest_average(averages);
    total_avg = total_averages(averages);

    print_student(names[highest_avg_index]);

    for (int i = 0; i < 5; i++){
        if (averages[i] < total_avg){
            print_student(names[i]);
        }
    }

    return 0;
}

/*
    Reads input, five lines of names and test scores and saves into 2d arrays
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

//calculate average
float calculate_average(int results[]){
    float avg;
    int sum = 0;

    for(int i = 0; i < 13; i++){
       sum += results[i];
    }

    avg = sum / 13.0;

    return avg;
}

//calculate highest average
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

// returns the total averages for all students
float total_averages(float averages[]){
    float sum = 0;
    for (int i = 0; i < 5; i++){
        sum += averages[i];
    }
    return sum / 5.0;
}

//compare averages with the total averages
//this isn't working as I want, need to think some more on implementation etc 25.04.2025
/*int compare_average(float total_avg, float avg[]){
    int index = 0;
    int counter = 0;
    for (int i = 0; i < 5; i++){
        if (avg[i] > total_avg){
            index = i;
            counter++;
        }
    }

    return index;
}*/

//change to capital first letter
void capital_letter(char names[11]){

    if (names[0] >= 'a' && names[0] <= 'z'){
        names[0] -= 32;
    }

}

// print data
void print_student(char name[11]){
        capital_letter(name);
        printf("%s\n", name);
}


