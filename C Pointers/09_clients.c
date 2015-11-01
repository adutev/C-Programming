#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Client {
    char name[50];
    int age;
    double account_balance;
};

void sort_clients(struct Client *clients, int clientsCount, int(*comparator) (struct Client*, struct Client*));
int name_comparator(struct Client *a, struct Client *b);
int balance_comparator(struct Client *a, struct Client *b);
int age_comparator(struct Client *a, struct Client *b);
void print_result(struct Client*, int);

int main() {
    struct Client clients[] = {
        {"Volen", 72, 100.10},
        {"Mimi", 25, 15275.2345},
        {"Gogo", 96, 2234.4},
        {"Boiko", 31, 230}
    };
    int clientsCount = sizeof (clients) / sizeof (clients[0]);
    printf("Sorted by name\n");
    sort_clients(clients, clientsCount, &name_comparator);
    print_result(clients, clientsCount);
    
    printf("Sorted by account balance\n");
    sort_clients(clients, clientsCount, &balance_comparator);
    print_result(clients, clientsCount);
    
    printf("Sorted by age\n");
    sort_clients(clients, clientsCount, &age_comparator);
    print_result(clients, clientsCount);    

    return 0;
}

void sort_clients(struct Client *clients, int clientsCount, int(*comparator) (struct Client*, struct Client*)) {
    int i;
    int swapped = 1;
    while (swapped) {
        swapped = 0;
        for (i = 0; i < clientsCount - 1; i++) {
            if (comparator(&clients[i], &clients[i + 1])) {
                struct Client temp = clients[i];
                clients[i] = clients[i + 1];
                clients[i + 1] = temp;
                swapped = 1;
            }
        }
    }

}

int name_comparator(struct Client *a, struct Client *b) {
    return a->name[0] > b->name[0];
}

int balance_comparator(struct Client *a, struct Client *b) {
    return a->account_balance > b->account_balance;
}

int age_comparator(struct Client *a, struct Client *b) {
    return a->age > b->age;
}

void print_result(struct Client* clients, int clientsCount){
    int i;
    for (i = 0; i < clientsCount; i++) {
        struct Client c = clients[i];
        printf("name: %s, age: %d, balance: %.2f\n", c.name, c.age, c.account_balance);
    }
}