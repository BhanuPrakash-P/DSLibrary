/**
 * @file dll.c
 * @author Bhanu Prakash
 * @brief 
 * @version 0.1
 * @date 2022-07-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include "dll.h"

/**
 * @brief create and return empty list
 * 
 * @return dll_t* 
 */
dll_t* init_dll(){
    dll_t* list = (dll_t*) calloc(1, sizeof(dll_t));
    list->head = NULL;
    return list;
}

/**
 * @brief Get the Dll Node object filled with data
 * 
 * @param data 
 * @return dll_node_t* 
 */
dll_node_t* getDllNode(void *data){
    dll_node_t* node = (dll_node_t*) calloc(1, sizeof(dll_node_t));
    node->data = data;
    node->prev = NULL;
    node->next = NULL;
    return node;
}

/**
 * @brief append data to the end of the list
 * 
 * @param list 
 * @param data 
 */
void append_dll(dll_t* list, void *data){
    if(!list || !data)
        return;

    dll_node_t* newNode = getDllNode(data);
    if(!list->head) {
        list->head = newNode;
    }
    else {
        dll_node_t* curNode = list->head;
        while(curNode->next) {
            curNode = curNode->next;
        }
        curNode->next = newNode;
        newNode->prev = curNode;
    }
}

/**
 * @brief empties the list, but don't free the data
 * 
 * @param list 
 */
void deinit_dll(dll_t*list){
    if(!list)
        return;
    dll_node_t* curNode = list->head;
    dll_node_t* nextNode;
    while(curNode)
    {
        nextNode = curNode->next;
        free(curNode);
        curNode = nextNode;
    }
    list->head = NULL;
}
