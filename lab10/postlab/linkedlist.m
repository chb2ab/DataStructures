/* Crispin Bernier, chb2ab */
#import <stdio.h>
#import <stdlib.h>
#import <objc/Object.h>
 
@interface node : Object
{
@private
   int x;
   node *y;
}
- (id) x: (int) x_value;
- (int) x;
- (id) y: (node*) y_value;
- (node*) y;
@end

@implementation node
 
- (id) x: (int) x_value
{
   x = x_value;
   return self;
}
 
- (int) x
{
   return x;
}
 
- (id) y: (node*) y_value
{
   y = y_value;
   return self;
}
 
- (node*) y
{
   return y;
}

 
@end


int main(void) {
    int n;
    int r;
    node *head, *lister;
    printf("Number of Nodes: ");
    scanf("%d", &n);
    int x;
    for (x = 0; x < n; x++){
        printf("Node Value %d", x);
        printf(": ");
        scanf("%d", &r);
        lister = [node new];
        [lister x:r];
        [lister y:head];
        head = lister;
    }

    for (int x = 0; x < n; x++){
        printf("%d\n", [lister x]);
        lister = [lister y];
    }

    node *temp;
    lister = head;

    for (x = 0; x < n; x++){
        temp = lister;
        lister = [lister y];
        free(temp);
    }
    return 0;
}
