#include <time.h>
int delay(int number_of_seconds){
    int milli_seconds =  number_of_seconds;

    clock_t start_time = clock();

    while (clock() < start_time + milli_seconds);
}