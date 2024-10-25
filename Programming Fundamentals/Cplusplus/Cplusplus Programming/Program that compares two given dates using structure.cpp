#include <stdio.h>

struct date {
    int day;
    int month;
    int year;
};

int compareDates(struct date date1, struct date date2);

int main() {
    struct date date1, date2;
    printf("Enter first date (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &date1.day, &date1.month, &date1.year);
    printf("Enter second date (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &date2.day, &date2.month, &date2.year);

    int result = compareDates(date1, date2);

    if (result == 1) {
        printf("First date is later than the second date.\n");
    } else if (result == -1) {
        printf("Second date is later than the first date.\n");
    } else {
        printf("Both dates are the same.\n");
    }

    return 0;
}

int compareDates(struct date date1, struct date date2) {
    if (date1.year > date2.year) {
        return 1;
    } else if (date1.year < date2.year) {
        return -1;
    } else {
        if (date1.month > date2.month) {
            return 1;
        } else if (date1.month < date2.month) {
            return -1;
        } else {
            if (date1.day > date2.day) {
                return 1;
            } else if (date1.day < date2.day) {
                return -1;
            } else {
                return 0;
            }
        }
    }
}
