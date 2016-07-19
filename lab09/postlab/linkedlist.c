/* Crispin Bernier, chb2ab */
#include <stdio.h>
#include <stdlib.h>

struct node {
  int val;
  struct node *next;
};


int main() {
    int n;
    int r;
    struct node *head, *list;
    printf("Number of Nodes: ");
    scanf("%d", &n);

    for (int x = 0; x < n; x++){
        printf("Node Value %d", x);
        printf(": ");
        scanf("%d", &r);
        list = (struct node *)malloc(sizeof(struct node));
        (*list).val = r;
        (*list).next = head;
        head = list;
    }

    for (int x = 0; x < n; x++){
        printf("%d\n", (*list).val);
        list = (*list).next;
    }

    struct node *temp;
    list = head;

    for (int x = 0; x < n; x++){
        temp = list;
        list = (*list).next;
        free(temp);
    }
    return 0;
}
