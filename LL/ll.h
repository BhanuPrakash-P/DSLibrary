/**
 * @file ll.h
 * @author Bhanu Prakash
 * @brief 
 * @version 0.1
 * @date 2022-07-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef __LL_H__
#define __LL_H__

typedef struct ll_node {
    void *data;
    struct ll_node *link;
}ll_node_t;

typedef struct ll {
    ll_node_t *head;
}ll_t;

ll_t* init_ll();
ll_node_t* getNode(void* data);
void append_ll(ll_t* list, void* data);
void deinit_ll(ll_t* list);

#endif //__LL_H__
