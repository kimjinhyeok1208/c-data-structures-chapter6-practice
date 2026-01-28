#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define MAX 100

typedef struct {
    char data[MAX];
    int front, rear;
} Deque;

void initDeque(Deque* d) {
    d->front = d->rear = 0;
}

int isEmpty(Deque* d) 
{
    if (d->front == d->rear)
        return 1;
    else
        return 0;
}

void addRear(Deque* d, char c)
{
    d->rear = (d->rear + 1) % MAX;
    d->data[d->rear] = c;
}

char deleteFront(Deque* d)
{
    d->front = (d->front + 1) % MAX;
    return d->data[d->front];
}

char deleteRear(Deque* d)
{
    char c = d->data[d->rear];
    d->rear = (d->rear - 1 + MAX) % MAX;
    return c;
}

int isPalindrome(char* str)
{
    Deque d;
    initDeque(&d);

    int len = strlen(str);
    for (int i = 0; i < len; i++)
        addRear(&d, str[i]);

    while (d.front != d.rear && (d.front + 1) % MAX != d.rear)
    {
        if (deleteFront(&d) != deleteRear(&d))
            return 0;
    }
    return 1;
}

int main() {
    char word[100];

    printf("문자열 입력: ");
    scanf("%s", word);

    if (isPalindrome(word))
        printf("회문입니다\n");
    else
        printf("회문이 아닙니다\n");

    return 0;
}