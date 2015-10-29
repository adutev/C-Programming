#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

int get_numbers(double*, int);
int count_round_numbers(double*, int);
double min_double(double*, int);
double max_double(double*, int);
double sum_double(double*, int);
double avg_double(double*, int);
void print_result(double*, int);
int main(int argc, char** argv) {
    int i, size, rounds_count, non_rounds_count;
    
    printf("Enter an integer number:");
    if(scanf("%d", &size) != 1) {
        printf("Invalid input");
        return 1;
    }
    double numbers[size];
    int got_numbers = get_numbers(numbers, size);
    if(got_numbers != 0){
        printf("Invalid number of doubles entered.");
        return 1;
    }
    
    rounds_count = count_round_numbers(numbers, size);
    non_rounds_count = size - rounds_count;
    double round_numbers[rounds_count];
    double non_round_numbers[non_rounds_count];
    
    int k = 0, n = 0;
    for(i = 0; i < size; i++){
        if(fmod(numbers[i], 1) == 0){
            round_numbers[k++] = numbers[i];
        } else {
            non_round_numbers[n++] = numbers[i];
        }
    }
    
    print_result(non_round_numbers, n);
    print_result(round_numbers, k);
    
    return 0;
}

int get_numbers(double* numbers, int size) {
    int i, matches = 0;

    printf("Enter %d double numbers:", size);
    for (i = 0; i < size; i++) {
        matches += scanf("%lf", &numbers[i]);
    }
    if (matches != size) {
        printf("Invalid number of doubles entered.");
        return 1;
    }
    
    return 0;
}

int count_round_numbers(double* numbers, int size){
    int i, count = 0;
    for(i = 0; i < size;i++){
        if(fmod(numbers[i], 1) == 0){
            count++;
        }
    }
    
    return count;
}

double min_double(double* arr, int size){
    int i;
    double min = INT_MAX;
    for(i = 0;i < size;i++){
        if(arr[i] < min){
            min = arr[i];
        }
    }
    return min;
}
double max_double(double* arr, int size){
    int i;
    double max = INT_MIN;
    for(i = 0;i < size;i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    return max;
}
double sum_double(double* arr, int size){
    int i;
    double sum = 0;
    for(i = 0;i < size;i++){
        sum+= arr[i];
    }
    return sum;
}
double avg_double(double* arr, int size){
    int i;
    double avg = 0;
    for(i = 0; i < size;i++){
            avg += arr[i];
    }
    return avg/size;
}
void print_result(double* arr, int size){
    int i;
    printf("[");
    for(i = 0; i < size; i++){
        if(i == (size - 1)){
            printf("%.0d%.4g] -> ", (int)arr[i]/10, (arr[i]-((int)arr[i]-(int)arr[i]%10)));
        } else{
            printf("%.0d%.4g, ", (int)arr[i]/10, (arr[i]-((int)arr[i]-(int)arr[i]%10)));
        }
    }
    double min = min_double(arr, size);
    double max = max_double(arr, size);
    double sum = sum_double(arr, size);
    double avg = avg_double(arr, size);
    printf("min: %.2f, ", min);
    printf("max: %.2f, ", max);
    printf("sum: %.2f, ", sum);
    printf("avg: %.2f\n", avg);

}