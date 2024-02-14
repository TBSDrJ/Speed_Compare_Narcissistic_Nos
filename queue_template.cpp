#include<iostream>
#include"queue_template.h"

template <class T>
Queue<T>::Queue () {
    head = NULL;
    tail = NULL;
    size = 0;
}

template <class T>
Entry<T>::Entry () {
    prev = NULL;
}

template <class T>
Entry<T>::Entry (T content_in, Entry * prev_in) {
    content = content_in;
    prev = prev_in;
}

template <class T>
void enqueue (Queue<T> *queue_ptr, T content) {
    if (queue_ptr -> head == NULL) {
        Entry <T> * new_entry = new Entry <T> (content, NULL);
        queue_ptr -> head = new_entry;
        queue_ptr -> tail = new_entry;
    } else {
        Entry <T> * new_entry = new Entry <T> (content, NULL);
        (queue_ptr -> tail) -> prev = new_entry;
        queue_ptr -> tail = new_entry;
    }
    queue_ptr -> size++;
}

template <class T>
T dequeue (Queue<T> * queue_ptr) {
    if (queue_ptr -> head != NULL) {
        T content = (queue_ptr -> head) -> content;
        (queue_ptr -> head) = (queue_ptr -> head) -> prev;
        (queue_ptr -> size)--;
        return content;
    } else {
        return NULL;
    }
}

template <class T>
void dump_queue (Queue<T> * queue_ptr) {
    Entry <T> * current = queue_ptr -> head;
    std::cout << "Size of queue: " << queue_ptr -> size << " entries." << std::endl;
    while(current != NULL) {
        std::cout << current -> content << " ";
        current = current -> prev;
    }
    std::cout << "End of queue." << std::endl << std::endl;
}
