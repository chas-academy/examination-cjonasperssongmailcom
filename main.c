#include <stdio.h>


// adding names
void add_names(){
    printf("Add name & score: ");
    char name[10];
    int score[12];

    scanf("%s", name);

    for(int i = 0; i <=13; i++){
        score[i] = scanf("%d");
    }
    printf("%s added\nScore: %d %d %d %d %d %d %d %d %d %d %d %d %d", name, score[0], score[1], score[2], score[3], score[4], score[5], score[6], score[7], score[8], score[9], score[10], score[11], score[12]);

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

int main(){
    add_names();


    return 0;
}
