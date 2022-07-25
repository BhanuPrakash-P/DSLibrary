/**
 * @file ll.c
 * @author Bhanu Prakash
 * @brief 
 * @version 0.1
 * @date 2022-07-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include "ll.h"

/**
 * @brief create and return an empty list
 * 
 * @return ll_t* 
 */
ll_t* init_ll() {
    ll_t* ll = (ll_t*) calloc(1, sizeof(ll_t));
    ll->head = NULL;
    return ll;
}

/**
 * @brief Get the Node object filled with data
 * 
 * @param data 
 * @return ll_node_t 
 */
ll_node_t* getNode(void* data) {
    ll_node_t* new_node = (ll_node_t*) calloc(1, sizeof(ll_node_t));
    new_node->data = data;
    new_node->link = NULL;
    return new_node;
}
/**
 * @brief append data to the end of the list
 * 
 * @param list 
 * @param data 
 */
void append_ll(ll_t* list, void* data) {
    if(!data || !list)
        return;

    ll_node_t* new_node = getNode(data);

    if(!list->head) {
        list->head = new_node;
    }
    else {
        ll_node_t* curNode = list->head;
        while(curNode->link) {
            curNode = curNode->link;
        }
        curNode->link = new_node;
    }
}

/**
 * @brief empties the list, but don't free the data
 * 
 * @param list 
 */
void deinit_ll(ll_t* list) {
    if(!list)
        return;
    
    ll_node_t* curNode = list->head;
    ll_node_t* nextNode;

    while(curNode) {
        nextNode = curNode->link;
        free(curNode);
        curNode = nextNode;
    }
    list->head = NULL;


}
