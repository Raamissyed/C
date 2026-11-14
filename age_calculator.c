#include <stdio.h>
#include <time.h>

int main(void) {
    int birth_year;
    time_t now = time(NULL);
    struct tm *today = localtime(&now);

    if (today == NULL) {
        fprintf(stderr, "Unable to determine the current year.\n");
        return 1;
    }

    const int current_year = today->tm_year + 1900;

    printf("Enter birth year: ");
    if (scanf("%d", &birth_year) != 1 || birth_year < 1 || birth_year > current_year) {
        fprintf(stderr, "Please enter a valid birth year (1-%d).\n", current_year);
        return 1;
    }

    printf("Approximate age (based on birth year): %d\n", current_year - birth_year);
    printf("Your exact age depends on whether your birthday has passed this year.\n");
    return 0;
}
