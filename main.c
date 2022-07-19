/**
 * @file main.c
 * @author Bhanu Prakash
 * @brief sample application to use the DS libraries
 * @version 0.1
 * @date 2022-07-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>
#include "ll.h"
#include "logging.h"

typedef struct app_data {
    int data;
}app_data_t;

#ifdef DEBUG
int debugLevel = 2;
#else
int debugLevel = 0;
#endif

int main() {
    ll_t* list = init_ll();
    for(int i=0; i<5; i++) {
        app_data_t* node = (app_data_t*) calloc(1, sizeof(app_data_t));
        node->data = i+1;
        append_ll(list, node);
    }
    ll_node_t* node = list->head;
    while(node) {
        debug("%d \t", *(int*)node->data);
        node = node->link;
    }
    debug("\n");
    deinit_ll(list);
    node = list->head;
    if(!node)
    {
        debug("List is Empty!!!\n");
    }
}
