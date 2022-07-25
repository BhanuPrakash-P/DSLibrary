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
#include <stdlib.h>
#include "ll.h"
#include "dll.h"
#include "logging.h"

typedef struct app_data {
    int data;
}app_data_t;

int main() {

/* linked list */
    ll_t* list = init_ll();
    for(int i=0; i<5; i++) {
        app_data_t* node = (app_data_t*) calloc(1, sizeof(app_data_t));
        node->data = i+1;
        append_ll(list, node);
    }
    ll_node_t* node = list->head;
    while(node) {
        debug("%d \t", *(int*)node->data);
        // free the node here, to avoid memory leaks
        free(node->data); 
        node = node->link;
    }
    debug("\n");
    deinit_ll(list);
    node = list->head;
    if(!node)
    {
        debug("List is Empty!!!\n");
        free(list);
    }

/* Double linked list */
    dll_t* d_list = init_dll();
    for(int i=0; i<5; i++) {
        app_data_t* d_node = (app_data_t*) calloc(1, sizeof(app_data_t));
        d_node->data = i+1;
        append_dll(d_list, d_node);
    }
    dll_node_t* d_node = d_list->head;
    while(d_node) {
        debug("%d \t", *(int*)d_node->data);
        // free the node here, to avoid memory leaks
        free(d_node->data); 
        d_node = d_node->next;
    }
    debug("\n");
    deinit_dll(d_list);
    d_node = d_list->head;
    if(!d_node)
    {
        debug("DL List is Empty!!!\n");
        free(d_list);
    }

}
