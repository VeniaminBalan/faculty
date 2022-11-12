#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10

char keys[N], A[N];

void initializare()
{
    int i;

    for (i = 1; i <= N; i++)
    {
        keys[i] = -1;
        A[i] = -1;
    }
}

void insert(char key, char parent)
{
    int i;
    for (i = 1; i <= N; i++)
    {
        if (keys[i] == -1)
        {
            A[i] = parent;
            keys[i] = key;
            break;
        }
    }
}

void stergereKey(char key) 
{
    int i;
    for (i = 1; i <= N; i++) 
    {
        if (keys[i] == key) 
        {
            A[i] = -1;
            stergereChild(i);
            
        }
    }
}
void stergereChild(char parent) 
{
    int i;
    for (i = 1; i <= N; i++)
    {
        if (A[i] == parent)
        {
            A[i] = -1;
            stergereKey(keys[i]);

        }
    }
}

void print_tables()
{
    int i;
    for (i = 1; i <= N; i++)
        printf("%d ", i);

    printf("\n");

    for (i = 1; i <= N; i++) 
    {
        if (A[i] == -1) printf("%s", "-1");
        else
            printf("%c ", A[i]);
    }


    printf("\n");
    printf("\n");

    for (i = 1; i <= N; i++)
        printf("%d ", i);

    printf("\n");

    for (i = 1; i <= N; i++) 
    {
        if (keys[i] == -1) printf("%s", "-1");
        else
            printf("%c ", keys[i]);
    }
        

}

int main()
{
    initializare();
    insert('a', '0');
    insert('b', '1');
    insert('c', '2');
    insert('d', '1');

    print_tables();
    stergereKey('b');
    print_tables();

    return 0;
}