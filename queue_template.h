#ifndef H_QUEUE
#define H_QUEUE

template <class T>
class Entry;

template <class T>
class Queue {
    public:
        Queue();
        Entry<T> * head;
        Entry<T> * tail;
        unsigned long size;
};

template <class T>
class Entry {
    public:
        Entry();
        Entry(T, Entry*);
        T content;
        Entry * prev;
};

template <class T>
void enqueue (Queue<T> *queue_ptr, T content);

template <class T>
T dequeue (Queue<T> * queue_ptr);

template <class T>
void dump_queue (Queue<T> * queue_ptr);

#endif