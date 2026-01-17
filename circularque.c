#include <stdio.h>
#include <conio.h>

#define max 5

int q[max];
int r = 0, f = 0, cnt = 0;

void add_students();
void distribute_pass();
void display_stud();

void main()
{
    int ch;
    clrscr();

    do
    {
        printf("\n1:add student");
        printf("\n2:Distribute bus pass");
        printf("\n3:show waiting student");
        printf("\n4:exit");
        printf("\nenter choice:");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1:
                add_students();
                break;

            case 2:
                distribute_pass();
                break;

            case 3:
                display_stud();
                break;

            case 4:
                break;

            default:
                printf("\n wrong choice..");
        }
    } while (ch != 4);

    getch();
}

/* add student */
void add_students()
{
    int roll;

    if (cnt == max)
    {
        printf("\n queue is full");
    }
    else
    {
        printf("\n enter student roll number");
        scanf("%d", &roll);

        q[r] = roll;
        r = (r + 1) % max;
        cnt++;

        printf("student added successfully");
    }
}

/* distribute bus pass */
void distribute_pass()
{
    if (cnt == 0)
    {
        printf("\nqueue is empty");
    }
    else
    {
        printf("\nbus pass distributed to roll no:%d", q[f]);
        f = (f + 1) % max;
        cnt--;
    }
}

/* display waiting students */
void display_stud()
{
    int i, temp;

    if (cnt == 0)
    {
        printf("\n no students waiting");
    }
    else
    {
        printf("\n waiting students are:\n");
        temp = f;

        for (i = 1; i <= cnt; i++)
        {
            printf("%d\t", q[temp]);
            temp = (temp + 1) % max;
        }
    }
}