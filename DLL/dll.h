/**
 * @file dll.h
 * @author Bhanu Prakash
 * @brief 
 * @version 0.1
 * @date 2022-07-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef __DLL_H__
#define __DLL_H__

typedef struct dll_node{
    void *data;
    struct dll_node *prev;
    struct dll_node *next;
}dll_node_t;

typedef struct dll{
    dll_node_t *head;
}dll_t;

dll_t* init_dll();
dll_node_t* getDllNode(void *data);
void append_dll(dll_t* list, void *data);
void deinit_dll(dll_t*list);

#endif // __DLL_H__
