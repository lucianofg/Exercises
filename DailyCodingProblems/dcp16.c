#include <stdio.h>
#include <stdlib.h>

/*
You run an e-commerce website and want to record the last N order ids in a
log. Implement a data structure to accomplish this, with the following API:

  record(order_id): adds the order_id to the log get_last(i): gets the ith
  last element from the log. i is guaranteed to be smaller than or equal to N.

You should be as efficient with time and space as possible. 
*/

struct {
    int size;
    int last;
    int* orders;
} lastest_orders_list;

void record(int order_id) {
    lastest_orders_list.last =
        (lastest_orders_list.last + 1) % lastest_orders_list.size;
    lastest_orders_list.orders[lastest_orders_list.last] = order_id;
}

int get_last() { return lastest_orders_list.orders[lastest_orders_list.last]; }

int main(void) {
    // Initializing the data structure
    lastest_orders_list.size = 10;
    lastest_orders_list.last = 0;
    lastest_orders_list.orders = malloc(sizeof(int) * lastest_orders_list.size);

    /* Do something with the list */

    free(lastest_orders_list.orders);

    return 0;
}



