
#include <stdio.h>

int main()
{
    int choice, shape;
    int size, rows;
    int i, j, space;
    int pascal[20][20];

    float prelim, midterm, semifinal, finalGrade;
    float average;

    char word[100];
    char again = 'Y';

    int length, palindrome;

    while (again == 'Y' || again == 'y')
    {
        printf("\n====================================\n");
        printf("          IT101 FINAL PROJECT\n");
        printf("====================================\n");
        printf("1. Pattern Generator\n");
        printf("2. Pascal's Triangle\n");
        printf("3. Grade Calculator and Evaluator\n");
        printf("4. Palindrome Checker\n");
        printf("====================================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        // 1. PATTERN GENERATOR
        if (choice == 1)
        {
            printf("\n--- PATTERN GENERATOR ---\n");

            printf("Enter size/height: ");
            scanf("%d", &size);

            if (size < 1 || size > 20)
            {
                printf("Invalid size. Enter 1 to 20.\n");
            }
            else
            {
                printf("\nChoose a shape:\n");
                printf("1. Right Triangle\n");
                printf("2. Square\n");
                printf("3. Isosceles Triangle\n");
                printf("4. Inverted Right Triangle\n");
                printf("5. Christmas Tree\n");

                printf("Enter your choice: ");
                scanf("%d", &shape);

                if (shape == 1)
                {
                    for (i = 1; i <= size; i++)
                    {
                        for (j = 1; j <= i; j++)
                        {
                            printf("* ");
                        }
                        printf("\n");
                    }
                }
                else if (shape == 2)
                {
                    for (i = 1; i <= size; i++)
                    {
                        for (j = 1; j <= size; j++)
                        {
                            printf("* ");
                        }
                        printf("\n");
                    }
                }
                else if (shape == 3)
                {
                    for (i = 1; i <= size; i++)
                    {
                        for (space = 1; space <= size - i; space++)
                        {
                            printf(" ");
                        }

                        for (j = 1; j <= (2 * i - 1); j++)
                        {
                            printf("*");
                        }
                        printf("\n");
                    }
                }
                else if (shape == 4)
                {
                    for (i = size; i >= 1; i--)
                    {
                        for (j = 1; j <= i; j++)
                        {
                            printf("* ");
                        }
                        printf("\n");
                    }
                }
                else if (shape == 5)
                {
                    // First triangle
                    for (i = 1; i <= size; i++)
                    {
                        for (space = 1; space <= size - i; space++)
                        {
                            printf(" ");
                        }

                        for (j = 1; j <= (2 * i - 1); j++)
                        {
                            printf("*");
                        }
                        printf("\n");
                    }

                    // Second triangle
                    for (i = 1; i <= size; i++)
                    {
                        for (space = 1; space <= size - i; space++)
                        {
                            printf(" ");
                        }

                        for (j = 1; j <= (2 * i - 1); j++)
                        {
                            printf("*");
                        }
                        printf("\n");
                    }

                    // Third triangle
                    for (i = 1; i <= size; i++)
                    {
                        for (space = 1; space <= size - i; space++)
                        {
                            printf(" ");
                        }

                        for (j = 1; j <= (2 * i - 1); j++)
                        {
                            printf("*");
                        }
                        printf("\n");
                    }

                    // Tree trunk
                    for (i = 1; i <= 2; i++)
                    {
                        for (space = 1; space < size; space++)
                        {
                            printf(" ");
                        }
                        printf("*\n");
                    }
                }
                else
                {
                    printf("Invalid shape choice.\n");
                }
            }
        }

        // 2. PASCAL'S TRIANGLE
        else if (choice == 2)
        {
            printf("\n--- PASCAL'S TRIANGLE ---\n");

            printf("Enter number of rows (1-20): ");
            scanf("%d", &rows);

            if (rows < 1 || rows > 20)
            {
                printf("Invalid number of rows.\n");
            }
            else
            {
                for (i = 0; i < rows; i++)
                {
                    for (j = 0; j <= i; j++)
                    {
                        if (j == 0 || j == i)
                        {
                            pascal[i][j] = 1;
                        }
                        else
                        {
                            pascal[i][j] =
                                pascal[i - 1][j - 1] +
                                pascal[i - 1][j];
                        }
                    }
                }

                for (i = 0; i < rows; i++)
                {
                    for (space = 1; space <= rows - i; space++)
                    {
                        printf("  ");
                    }

                    for (j = 0; j <= i; j++)
                    {
                        printf("%4d", pascal[i][j]);
                    }
                    printf("\n");
                }
            }
        }

        // 3. GRADE CALCULATOR AND EVALUATOR
        else if (choice == 3)
        {
            printf("\n--- GRADE CALCULATOR ---\n");

            printf("Enter Prelim grade: ");
            scanf("%f", &prelim);

            printf("Enter Midterm grade: ");
            scanf("%f", &midterm);

            printf("Enter Semifinal grade: ");
            scanf("%f", &semifinal);

            printf("Enter Final grade: ");
            scanf("%f", &finalGrade);

            if (prelim < 1 || prelim > 5 ||
                midterm < 1 || midterm > 5 ||
                semifinal < 1 || semifinal > 5 ||
                finalGrade < 1 || finalGrade > 5)
            {
                printf("Invalid grade. Enter grades from 1.00 to 5.00.\n");
            }
            else
            {
                average = (prelim + midterm +
                           semifinal + finalGrade) / 4.0;

                printf("\nFinal Average: %.2f\n", average);

                if (average < 4.00)
                {
                    printf("Status: PASS\n");
                }
                else
                {
                    printf("Status: FAIL\n");
                }
            }
        }

        // 4. PALINDROME CHECKER
        else if (choice == 4)
        {
            printf("\n--- PALINDROME CHECKER ---\n");

            printf("Enter a word or sentence: ");
            scanf(" %99[^\n]", word);

            length = 0;
            j = 0;

            // Count characters and remove spaces
            for (i = 0; word[i] != '\0'; i++)
            {
                if (word[i] != ' ')
                {
                    if (word[i] >= 'A' && word[i] <= 'Z')
                    {
                        word[i] = word[i] + 32;
                    }

                    word[j] = word[i];
                    j++;
                }
            }

            word[j] = '\0';
            length = j;

            palindrome = 1;

            for (i = 0; i < length / 2; i++)
            {
                if (word[i] != word[length - 1 - i])
                {
                    palindrome = 0;
                    break;
                }
            }

            if (palindrome == 1)
            {
                printf("It is a palindrome.\n");
            }
            else
            {
                printf("It is not a palindrome.\n");
            }
        }

        else
        {
            printf("Invalid choice. Choose 1 to 4.\n");
        }

        printf("\nDo you want to try another operation? (Y/N): ");
        scanf(" %c", &again);
    }

    printf("\nThank you for using the program!\n");

    return 0;
}
