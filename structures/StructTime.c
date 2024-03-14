#include <stdio.h>

// Define structure Time
struct Time
{
    int hours;
    int minutes;
    int seconds;
};

// Function to read time
void Read(struct Time *t)
{
    printf("Enter Time in format HH:MM:SS\n");
    scanf("%d %d %d", &(t->hours), &(t->minutes), &(t->seconds));
}

// Function to display time
void Display(struct Time *t)
{
    printf("Time: %02d:%02d:%02d\n", t->hours, t->minutes, t->seconds);
}

// Function to update time
void Update(struct Time *t)
{
    t->seconds++;
    if (t->seconds == 60)
    {
        t->seconds = 0;
        t->minutes++;
        if (t->minutes == 60)
        {
            t->minutes = 0;
            t->hours++;
            if (t->hours == 24)
            {
                t->hours = 0;
            }
        }
    }
}

// Function to add two times
struct Time Add(struct Time *t1, const struct Time *t2)
{
    struct Time result;
    result.seconds = t1->seconds + t2->seconds;
    result.minutes = t1->minutes + t2->minutes;
    result.hours = t1->hours + t2->hours;

    // Normalize the resultant time
    if (result.seconds >= 60)
    {
        result.seconds -= 60;
        result.minutes++;
    }
    if (result.minutes >= 60)
    {
        result.minutes -= 60;
        result.hours++;
    }
    if (result.hours >= 24)
    {
        result.hours -= 24;
    }

    return result;
}

int main()
{
    struct Time T1, T2, Result;

    int choice;
    do
    {
        printf("\nMENU\n");
        printf("\n1. Read Time\n");
        printf("2. Display Time\n");
        printf("3. Update Time\n");
        printf("4. Add Two Times\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            Read(&T1);
            break;
        case 2:
            Display(&T1);
            break;
        case 3:
            Update(&T1);
            Display(&T1);
            break;
        case 4:
            Read(&T1);
            Read(&T2);
            Result = Add(&T1, &T2);
            printf("Resultant Time after addition: ");
            Display(&Result);
            break;
        case 5:
            printf("Exiting the program.\n");
            break;
        default:
            printf("Invalid choice. Try again.\n");
        }
    } while (choice != 5);

    return 0;
}
