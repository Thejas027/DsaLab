/*
1. a) Define a structure called Student with the members: Name, Reg_no, marks in 3 tests and average_ marks.
Develop a menu driven program to perform the following by writing separate function for each operation: a) read
information of N students b) display student’s information c) to calculate the average of best two test marks of each
student.
*/

#include <stdio.h>
#include <stdlib.h>

struct student
{
    char name[25];
    int roll;
    int marks[3];
    float avg;
};

void read(struct student *s, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Enter the information of student  %d : \n", i + 1);
        printf("Enter the name : ");
        scanf("%s", s[i].name);
        printf("\nEnter the roll number : ");
        scanf("%d", &s[i].roll);
        printf("\nEnter the marks of 3 tests : ");
        for (int j = 0; j < 3; j++)
            scanf("%d", &s[i].marks[j]);
    }
}

void display(struct student *s, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("The inforamation fo student %d : \n", (i + 1));
        printf("\nName : %s", s[i].name);
        printf("\nRoll no :%d ", s[i].roll);
        printf("\nThe marks of 3 tests are : ");
        for (int j = 0; j < 3; j++)
            printf("%d ", s[i].marks[j]);
    }
    printf("\n");
}
void AvgMarks(struct student *s, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = j + 1; k < 3; k++)
            {
                if (s[i].marks[j] < s[i].marks[k])
                {
                    int temp = s[i].marks[j];
                    s[i].marks[j] = s[i].marks[k];
                    s[i].marks[k] = temp;
                }
            }
        }
        s[i].avg = (s[i].marks[0] + s[i].marks[1]) / 2.0;
        printf("avg from the best of 2 of student %d : %.2f", (i + 1), s[i].avg);
    }
}

int main()
{
    int n, ch;
    printf("Enter the number of students value : ");
    scanf("%d", &n);
    struct student *s = (struct student *)malloc(n * sizeof(struct student));

    do
    {
        printf("\nMenu\n");
        printf("1.To read\n");
        printf("2.to display\n");
        printf("3.to calculate and display the avg marks\n");
        printf("4. to exit\n");
        printf("Enter your choice : ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            read(s, n);
            break;

        case 2:
            display(s, n);
            break;

        case 3:
            AvgMarks(s, n);
            break;

        case 4:
            free(s);
            printf("Exiting program..\n");
            break;

        default:
            printf("Invalid choice..\n");
            break;
        }
    } while (ch != 4);
    return 0;
}