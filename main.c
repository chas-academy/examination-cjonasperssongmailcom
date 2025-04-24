#include <stdio.h>
//function declaration
void add_students(char names[5][11], int scores[5][13]);
void print_students(char names[5][11], int scores[5][13]);

int main(){
    char names[5][11];
    int scores[5][13];

    add_students(names, scores);
    print_students(names, scores);

    return 0;
}

//Read 5 lines of names and test scores
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
    int sum;

    for(int i = 0; i <= 13; i++){
       sum += results[i];
    }

    avg = sum / 13.0;

    return avg;
}
//calculate highest average

//compare average
float compare_average(float a, float b){

}

//change to capital first letter

// print data
void print_students(char names[5][11], int scores[5][13]){
    printf("\nCollected data\n");
    for (int i = 0; i < 5; i++){
        printf("Name: %s\nScores: ", names[i]);
        for (int j = 0; j < 13; j++){
            printf("%d ", scores[i][j]);
        }
        printf("\n");
    }
}


