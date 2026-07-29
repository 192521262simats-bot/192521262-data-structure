#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    int productID;
    char day[15];
    int unitsSold;
    struct Node *next;
};

struct Node *head = NULL;

void insertSale(int id, char day[], int units)
{
    struct Node *newNode;
    struct Node *temp;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->productID = id;
    strcpy(newNode->day, day);
    newNode->unitsSold = units;
    newNode->next = NULL;

    if(head == NULL)
    {
        head = newNode;
    }
    else
    {
        temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void totalSales()
{
    int total101 = 0;
    int total102 = 0;
    int total103 = 0;

    struct Node *temp = head;

    while(temp != NULL)
    {
        if(temp->productID == 101)
            total101 += temp->unitsSold;

        else if(temp->productID == 102)
            total102 += temp->unitsSold;

        else if(temp->productID == 103)
            total103 += temp->unitsSold;

        temp = temp->next;
    }

    printf("\nTotal Sales:\n");
    printf("Product 101 = %d\n", total101);
    printf("Product 102 = %d\n", total102);
    printf("Product 103 = %d\n", total103);
}

void highestSale()
{
    struct Node *temp = head;
    int max = 0;
    int pid;
    char d[15];

    while(temp != NULL)
    {
        if(temp->unitsSold > max)
        {
            max = temp->unitsSold;
            pid = temp->productID;
            strcpy(d, temp->day);
        }
        temp = temp->next;
    }

    printf("\nHighest Sale:\n");
    printf("Product ID = %d\n", pid);
    printf("Day = %s\n", d);
    printf("Units Sold = %d\n", max);
}

void displayProduct(int id)
{
    struct Node *temp = head;

    printf("\nSales of Product %d:\n", id);

    while(temp != NULL)
    {
        if(temp->productID == id)
        {
            printf("%s : %d units\n",
                   temp->day,
                   temp->unitsSold);
        }
        temp = temp->next;
    }
}

int main()
{
    insertSale(101,"Monday",20);
    insertSale(101,"Tuesday",15);
    insertSale(101,"Wednesday",18);

    insertSale(102,"Monday",10);
    insertSale(102,"Tuesday",12);

    insertSale(103,"Monday",8);

    totalSales();

    highestSale();

    displayProduct(101);

    return 0;
}


