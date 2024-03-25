/*
b) Define a structure called Time containing 3 integer members (Hour, Minute, Second).Develop a menu driven
program to perform the following by writing separate function for each operation.
a) Read (T) :To read time b) Display (T):To display time c) update(T):To Update time d) Add(T1, T2) : Add two
time variables.
Update function increments the time by one second and returns the new time (if the incrementresults in 60
seconds, then the second member is set to zero and minute member is incrementedby one. If the result is 60
minutes, the minute member is set to zero and the hour member isincremented by one. Finally, when the hour
becomes 24, Time should be reset to zero. Whileadding two time variables, normalize the resultant time value as in
the case of update function. Note: Illustrate the use of pointer to pass time variable to different functions.
*/

#include <stdio.h>
#include <stdlib.h>

struct Time
{
    int H;
    int M;
    int S;
};

void read(struct Time *t)
{
    printf("Enter the time in format HH:MM:SS : ");
    scanf("%d %d %d", &t->H, &t->M, &t->S);
}

void display(struct Time *t)
{
    printf("Time is : %d %d %d  ", t->H, t->M, t->S);
}

void update(struct Time *t)
{
    t->S++;
    if (t->S == 60)
    {
        t->S = 0;
        t->M++;
        if (t->M == 60)
        {
            t->M = 0;
            t->H++;
            if (t->H == 24)
            {
                t->H = 0;
            }
        }
    }
}

struct Time add(struct Time *t1, struct Time *t2)
{
    struct Time res;

    res.S = t1->S + t2->S;
    res.M = t1->M + t2->M;
    res.H = t1->H + t2->H;

    if (res.S >= 60)
    {
        res.S -= 60;
        res.M++;
    }
    if (res.M >= 60)
    {
        res.M -= 60;
        res.H++;
    }
    if (res.H >= 24)
    {
        res.H -= 24;
    }
    return res;
}

int main()
{
    int choice;
    struct Time T1, T2, res;
    do
    {
        printf("\nMenu");
        printf("1.To read\n");
        printf("2.To display\n");
        printf("3.to update\n");
        printf("4.to add \n");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            read(&T1);
            break;
        case 2:
            display(&T1);
            break;

        case 3:
            update(&T1);
            display(&T1);
            break;

        case 4:
            read(&T1);
            read(&T2);
            res = add(&T1, &T2);
            display(&res);
            break;

        case 5:
            printf("Exiting the program\n");
            break;

        default:
            printf("Invalid choice\n");
            break;
        }
    } while (choice != 5);
    return 0;
}