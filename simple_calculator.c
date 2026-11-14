#include <stdio.h>

int main(void) {
    double first_number;
    double second_number;
    double answer;
    char operation;

    printf("Enter first number: ");
    if (scanf("%lf", &first_number) != 1) {
        fprintf(stderr, "Invalid first number.\n");
        return 1;
    }

    printf("Enter operation (+, -, *, /): ");
    if (scanf(" %c", &operation) != 1) {
        fprintf(stderr, "Invalid operation.\n");
        return 1;
    }

    printf("Enter second number: ");
    if (scanf("%lf", &second_number) != 1) {
        fprintf(stderr, "Invalid second number.\n");
        return 1;
    }

    switch (operation) {
        case '+':
            answer = first_number + second_number;
            break;
        case '-':
            answer = first_number - second_number;
            break;
        case '*':
            answer = first_number * second_number;
            break;
        case '/':
            if (second_number == 0.0) {
                fprintf(stderr, "Cannot divide by zero.\n");
                return 1;
            }
            answer = first_number / second_number;
            break;
        default:
            fprintf(stderr, "Unsupported operation: %c\n", operation);
            return 1;
    }

    printf("Answer: %.2f\n", answer);
    return 0;
}
