#include <stdio.h>

struct Customer {
    int accNo;
    char name[50];
    char accType[20];
    float balance;
};

int main() {
    struct Customer c[5];

    printf("Enter details of 5 customers:\n");
    for(int i = 0; i < 5; i++) {
        printf("\nCustomer %d\n", i + 1);

        printf("Account Number: ");
        scanf("%d", &c[i].accNo);

        printf("Name: ");
        scanf("%s", c[i].name);

        printf("Account Type (Savings/Current): ");
        scanf("%s", c[i].accType);

        printf("Balance: ");
        scanf("%f", &c[i].balance);
    }

    // Display in tabular form
    printf("\n\nCustomer Details:\n");
    printf("-------------------------------------------------------------\n");
    printf("AccNo\tName\t\tType\t\tBalance\n");
    printf("-------------------------------------------------------------\n");

    for(int i = 0; i < 5; i++) {
        printf("%d\t%-15s\t%-10s\t%.2f\n",
               c[i].accNo,
               c[i].name,
               c[i].accType,
               c[i].balance);
    }

    return 0;
}