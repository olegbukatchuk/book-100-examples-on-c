//
// Created by Oleg Bukatchuk on 25/10/2017.
//

// Вычисление разницы между двумя периодами времени (не работает)
#include <stdio.h>

struct TIME {

    int seconds;
    int minutes;
    int hours;

};

void differenceBetweenTimePeriod(struct TIME t1, struct TIME t2, struct TIME *diff);

int main(void) {

    struct TIME startTime, stopTime, diff;

    printf("Начальное время: \n");
    printf("Введите часы, минуты, секунды: ");
    scanf("%d %d %d", &startTime.hours, &startTime.minutes, &startTime.seconds);

    printf("Конечное время: \n");
    printf("Введите часы, минуты, секунды: ");
    scanf("%d %d %d", &startTime.hours, &startTime.minutes, &startTime.seconds);

    // Вычисляем разницу
    differenceBetweenTimePeriod(startTime, stopTime, &diff);

    printf("\nРазница: %d:%d:%d - ", startTime.hours, startTime.minutes, startTime.seconds);
    printf("%d:%d:%d ", stopTime.hours, stopTime.minutes, stopTime.seconds);
    printf("= %d:%d:%d\n", diff.hours, diff.minutes, diff.seconds);

    return 0;

}

void differenceBetweenTimePeriod(struct TIME start, struct TIME stop, struct TIME *diff) {

    if (stop.seconds > start.seconds) {

        --start.minutes;
        start.seconds += 60;

    }

    diff->seconds = start.seconds - stop.seconds;

    if (stop.minutes > start.minutes) {

        --start.hours;
        start.hours += 60;

    }

    diff->minutes = start.minutes - stop.minutes;
    diff->hours = start.hours - stop.hours;

}