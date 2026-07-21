#include <stdio.h>

union Deduction {
    float pf;
    float tax;
};

struct Employee {
    int id;
    float salary;
    union Deduction d;
};

int main() {
    struct Employee e;

    e.id = 101;
    e.salary = 30000;
    e.d.pf = 2000; 

    printf("Net Salary: %.2f\n", e.salary - e.d.pf); 
    printf("Pf member: %.2f\n", e.d.pf);
    printf("Tax member: %.2f\n", e.d.tax);
    return 0;
}