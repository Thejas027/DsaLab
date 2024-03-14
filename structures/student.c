#include <stdio.h>
#include <string.h>
#include <malloc.h>
struct student
{
  char name[25];
  int reg_no;
  int marks[3];
  float avg_marks;
};

void readInfo(struct student *students, int n)
{
  for (int i = 0; i < n; i++)
  {
    printf("\nEnter information for Student %d:\n", i + 1);
    printf("name: ");
    scanf("%s", students[i].name);
    printf("reg no ");
    scanf("%d", &students[i].reg_no);
    printf("enter the test marks\n");
    for (int j = 0; j < 3; j++)
    {
      scanf("%d", &students[i].marks[j]);
    }
  }
}

void displayInfo(struct student *students, int n)
{
  for (int i = 0; i < n; i++)
  {
    printf("Information for Student %d:\n", i + 1);
    printf("Name :%s\n", students[i].name);
    printf("Reg-no:%d\n", students[i].reg_no);
    printf("marks in 3 tests");
    for (int j = 0; j < 3; j++)
    {
      printf("%d", students[i].marks[j]);
    }
    printf("\n");
  }
}

void avgMarks(struct student *students, int n)
{
  for (int i = 0; i < n; i++)
  {

    // sort the marks
    for (int j = 0; j < 2; j++)
    {
      for (int k = j + 1; k < 3; k++)
      {
        if (students[i].marks[j] < students[i].marks[k])
        {
          int temp = students[i].marks[j];
          students[i].marks[j] = students[i].marks[k];
          students[i].marks[k] = temp;
        }
      }
    }

    students[i].avg_marks = (students[i].marks[0] + students[i].marks[1]) / 2.0;

    printf("Average of best 2 tests for Student %d: %.2f\n", i + 1, students[i].avg_marks);
  }
}

int main()
{
  int n, choice;
  struct student *students;

  printf("Enter the number of students: ");
  scanf("%d", &n);

  students = (struct student *)malloc(n * sizeof(struct student));

  do
  {
    printf("MENU\n");
    printf("1.read information\n");
    printf("2.Display information\n");
    printf("3.Avg marks\n");
    printf("4.exit\n");
    printf("enter your choice\n");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      readInfo(students, n);
      break;

    case 2:

      displayInfo(students, n);
      break;

    case 3:
      avgMarks(students, n);
      break;

    case 4:
      free(students);
      printf("exiting program");
      break;

    default:
      printf("invalid choice\n");
      break;
    }
  } while (choice != 4);
  return 0;
}
