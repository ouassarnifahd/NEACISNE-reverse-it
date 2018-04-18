/** @file queue.c
*   @brief Ficher source contenant les fonctions de manupilation des files.
*/

#include "../inc/queue.h"

// #define DEBUG

PTQueue TQueue_New(int maxSize){
    PTQueue this = malloc(sizeof(TQueue));
    if(!this) return NULL;
    this->TabSize    = maxSize;
    this->FrontIndex = 0; // out
    this->BackIndex  = 0; // in
    this->NumElems   = 0;
    this->Table      = malloc(this->TabSize * sizeof(TElement));
    this->IsEmpty    = (void*) TQueue_IsEmpty;
    this->Length     = (void*) TQueue_Length;
    this->Enqueue    = (void*) TQueue_Enqueue;
    this->Dequeue    = (void*) TQueue_Dequeue;
    this->Clear      = (void*) TQueue_Clear;
    this->Display    = (void*) TQueue_Display;
    this->Delete     = (void*) TQueue_Delete;
    return this;
}

static bool TQueue_IsEmpty(const PTQueue this){
    return (!this->NumElems || (this->BackIndex == this->FrontIndex));
}

static int TQueue_Length(const PTQueue this){
    return this->NumElems;
}

static bool TQueue_Enqueue(const PTQueue this, TElement pushElt){
    if (this->FrontIndex == ((this->BackIndex + 1) % this->TabSize)) {
        this->Table = realloc(this->Table, 2 * this->TabSize * sizeof(TElement));
        if (this->BackIndex < this->FrontIndex) {
            for (int MoveIndex = 0; MoveIndex < this->BackIndex; MoveIndex++) {
                this->Table[this->TabSize + MoveIndex] = this->Table[MoveIndex];
            }
            this->BackIndex += this->TabSize;
        }
        this->TabSize *= 2;
    }
    this->Table[this->BackIndex] = pushElt;
    this->BackIndex = (this->BackIndex + 1) % this->TabSize;
    this->NumElems++;
    return 1;
}

static bool TQueue_Dequeue(const PTQueue this, PTElement popElt){
    bool Dequeued = 0;
    if(!TQueue_IsEmpty(this)){
        Dequeued = 1;
        popElt = this->Table + this->FrontIndex;
        this->FrontIndex = (this->FrontIndex + 1) % this->TabSize;
        this->NumElems--;
    }
    return Dequeued;
}

static void TQueue_Clear(const PTQueue this){
    this->FrontIndex = (this->BackIndex >= this->FrontIndex) ? this->FrontIndex : this->BackIndex;
    this->BackIndex = (this->BackIndex >= this->FrontIndex) ? this->FrontIndex : this->BackIndex;
    this->NumElems = 0;
}

static void TQueue_Delete(const PTQueue this){
    free(this->Table);
    free(this);
}

static void TQueue_Display(const PTQueue this){
	int Index = this->FrontIndex;
	printf("Taille: %d\n", this->TabSize);
    printf("Nombre d'éléments : %d\n", this->NumElems);
    #ifdef DEBUG
    printf("FrontIndex: %d, BackIndex: %d\n", this->FrontIndex, this->BackIndex);
    printf("Memoire:     [ ");
    int i = 0;
    for(i = 0; i < this->TabSize; i++) {
        display_element(this->Table + i);
        printf(" ");
    }
	printf("]\n");
    #endif
    printf("Contenu: out <- ");
    if (!this->IsEmpty(this)){
        do {
            display_element(this->Table + Index);
            printf(" <- ");
            Index = (Index + 1) % this->TabSize;
        } while((Index + 1) % this->TabSize != (this->BackIndex + 1) % this->TabSize);
    }
    printf("in\n");
}
