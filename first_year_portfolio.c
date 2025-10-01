#include <stdio.h>
#include <string.h>

#define MAX_COURSES 20
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    float credits;
    float grade;
} Course;

void trim_newline(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

void print_banner(void) {
    printf("==============================\n");
    printf("  First-Year Study Organizer   \n");
    printf("==============================\n\n");
    printf("This simple project helps you track courses, credits,\n");
    printf("and grades so you can stay on top of your studies.\n\n");
}

void print_menu(void) {
    printf("Menu:\n");
    printf("1. Add course\n");
    printf("2. List courses\n");
    printf("3. Calculate GPA\n");
    printf("4. Show study tips\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

void add_course(Course courses[], int *course_count) {
    if (*course_count >= MAX_COURSES) {
        printf("You have reached the maximum number of courses (%d).\n\n", MAX_COURSES);
        return;
    }

    Course *course = &courses[*course_count];

    printf("Enter course name: ");
    if (fgets(course->name, sizeof(course->name), stdin) == NULL) {
        printf("Error reading course name.\n\n");
        return;
    }
    trim_newline(course->name);

    printf("Enter course credits (e.g., 3): ");
    if (scanf("%f", &course->credits) != 1 || course->credits <= 0.0f) {
        printf("Invalid credit value.\n\n");
        while (getchar() != '\n') {
            // clear input buffer
        }
        return;
    }

    printf("Enter grade (0-100): ");
    if (scanf("%f", &course->grade) != 1 || course->grade < 0.0f || course->grade > 100.0f) {
        printf("Invalid grade.\n\n");
        while (getchar() != '\n') {
            // clear input buffer
        }
        return;
    }

    while (getchar() != '\n') {
        // consume trailing newline
    }

    (*course_count)++;
    printf("Course added! Keep going!\n\n");
}

void list_courses(const Course courses[], int course_count) {
    if (course_count == 0) {
        printf("No courses yet. Start by adding one!\n\n");
        return;
    }

    printf("%-3s %-25s %-10s %-10s\n", "#", "Course", "Credits", "Grade");
    printf("--------------------------------------------------\n");

    for (int i = 0; i < course_count; ++i) {
        printf("%-3d %-25s %-10.1f %-10.1f\n", i + 1, courses[i].name, courses[i].credits, courses[i].grade);
    }

    printf("\n");
}

void calculate_gpa(const Course courses[], int course_count) {
    if (course_count == 0) {
        printf("Add some courses first to calculate your GPA.\n\n");
        return;
    }

    float total_credits = 0.0f;
    float weighted_sum = 0.0f;

    for (int i = 0; i < course_count; ++i) {
        total_credits += courses[i].credits;
        weighted_sum += courses[i].credits * courses[i].grade;
    }

    if (total_credits == 0.0f) {
        printf("Total credits are zero. Check your course entries.\n\n");
        return;
    }

    float gpa = weighted_sum / total_credits / 25.0f; // approximate conversion to 4.0 scale
    printf("Your estimated GPA on a 4.0 scale is: %.2f\n", gpa);
    printf("Keep up the great work!\n\n");
}

void show_tips(void) {
    const char *tips[] = {
        "Break assignments into smaller tasks and schedule them.",
        "Review lecture notes within 24 hours to keep concepts fresh.",
        "Join a study group or find a study buddy to stay motivated.",
        "Take short breaks during long study sessions to recharge.",
        "Ask questions early when you are stuck—communication is key!"
    };

    printf("Study Tips:\n");
    for (size_t i = 0; i < sizeof(tips) / sizeof(tips[0]); ++i) {
        printf("- %s\n", tips[i]);
    }
    printf("\n");
}

int main(void) {
    Course courses[MAX_COURSES];
    int course_count = 0;
    int choice = 0;

    print_banner();

    while (1) {
        print_menu();
        if (scanf("%d", &choice) != 1) {
            printf("Please enter a number between 1 and 5.\n\n");
            while (getchar() != '\n') {
                // clear input buffer
            }
            continue;
        }

        while (getchar() != '\n') {
            // clear buffer after reading choice
        }

        switch (choice) {
            case 1:
                add_course(courses, &course_count);
                break;
            case 2:
                list_courses(courses, course_count);
                break;
            case 3:
                calculate_gpa(courses, course_count);
                break;
            case 4:
                show_tips();
                break;
            case 5:
                printf("Good luck with your studies! Bye!\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n\n");
                break;
        }
    }
}
