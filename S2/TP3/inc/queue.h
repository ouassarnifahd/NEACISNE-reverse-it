#ifndef _QUEUE_
#define _QUEUE_

#include"./Elements/element.h"

typedef struct Queue {
    int TabSize;
    int NumElems;
    int FrontIndex;
    int BackIndex;
    PTElement Table;
    bool    (*IsEmpty)  (const struct Queue *);
    int     (*Length)   (const struct Queue *);
    bool    (*Enqueue)  (const struct Queue *, TElement);
    bool    (*Dequeue)  (const struct Queue *, PTElement);
    void    (*Clear)    (const struct Queue *);
    void    (*Display)  (const struct Queue *);
    void    (*Delete)   (const struct Queue *);
} TQueue;

typedef TQueue *PTQueue;

PTQueue TQueue_New(int maxSize);

static inline bool TQueue_IsEmpty(const PTQueue this);

static inline int TQueue_Length(const PTQueue this);

static inline bool TQueue_Enqueue(const PTQueue this, TElement pushElt);

static inline bool TQueue_Dequeue(const PTQueue this, PTElement popElt);

static inline void TQueue_Clear(const PTQueue this);

static inline void TQueue_Display(const PTQueue this);

static inline void TQueue_Delete(const PTQueue this);

#endif /* end of include guard : _QUEUE_ */
