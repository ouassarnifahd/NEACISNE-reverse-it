#include"../inc/queue.h"

PTQueue TQueue_New(int maxSize){
    PTQueue this = malloc(sizeof(TQueue));
    if(!this) return NULL;
    this->TabSize    = maxSize;
    this->NumElems   = 0;
    this->FrontIndex = 0;
    this->BackIndex  = 0;
    this->Table      = malloc(this->TabSize*sizeof(TElement));
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
    return this->NumElems?0:1;
}

static int TQueue_Length(const PTQueue this){
    return this->NumElems;
}

/*
if(TQueue_IsEmpty(this)){
    this->Table[this->NumElems]=pushElt;
    this->NumElems++;
    return 1;
}
else {
    if(this->NumElems == this->TabSize){
        this->TabSize=2*this->TabSize;
        this->Table=realloc(this->Table,this->TabSize*sizeof(TElement));
        if(!this->Table) return 0;
        int Index;
        for (Index = 0; Index < this->FrontIndex; Index++)
            this->Table[Index + this->TabSize] = this->Table[Index];
        this->BackIndex = Index + this->TabSize - 1;
    }
    else {
        this->BackIndex= (this->BackIndex + 1) % this->TabSize;
        this->Table[this->BackIndex]=pushElt;
        this->NumElems++;
    }
    return 1;
}
return 0;
*/

static bool TQueue_Enqueue(const PTQueue this, TElement pushElt){
    PTElement pfile;
    int i;
    if (this->IsEmpty(this)){
        *(this->Table) = pushElt;
    }
    else {
        this->BackIndex ++;
        if (this->BackIndex > this->TabSize){
            if (this->FrontIndex == 0){
                pfile = (PTElement) realloc(this->Table, 2*(this->TabSize)*sizeof(TElement));
                if (pfile == NULL){
                    printf("Erreur d'allocation!\n");
                    return false;
                }
                else {
                    this->Table = pfile;
                    this->TabSize *= 2;
                    this->Table[this->BackIndex] = pushElt;
                }
            }
            else{
                this->BackIndex = 0;
                this->Table[this->BackIndex] = pushElt;
            }
        }
        else if (((this->FrontIndex) == (this->BackIndex)) != 0){
            pfile = (PTElement) realloc(this->Table, 2*(this->TabSize)*sizeof(TElement));
            if (pfile == NULL){
                printf("Erreur d'allocation!\n");
                return false;
            }
            else {
                this->Table = pfile;
                this->TabSize *= 2;
                for (i=0; i<(this->BackIndex);i++){
                    this->Table[this->TabSize + i] = this->Table[i];
                }
                this->BackIndex += this->NumElems;
                this->Table[this->BackIndex] = pushElt;
            }
        }
        else{
            this->Table[this->BackIndex] = pushElt;
        }
    }
    this->NumElems ++;
    return true;
}

static bool TQueue_Dequeue(const PTQueue this, PTElement popElt){
    if(TQueue_IsEmpty(this)) return 0;
    *popElt = this->Table[this->FrontIndex];
    this->FrontIndex = (this->FrontIndex + 1) % this->TabSize;
    this->NumElems--;
    if(!this->NumElems)
        this->FrontIndex = 0;
        this->BackIndex = 0;
    return 1;
}

static void TQueue_Clear(const PTQueue this){
    int i;
    if(TQueue_IsEmpty(this)) return ;
    for (i=0; i<this->TabSize; i++){
        this->Table[i]=0;
    }
    this->NumElems=0;
    this->FrontIndex=0;
    this->BackIndex=0;
}

static void TQueue_Delete(const PTQueue this){
    TQueue_Clear(this);
    free(this->Table);
    free(this);
}

static void TQueue_Display(const PTQueue this){
	int i=this->FrontIndex;
	printf("Taille: %d\n",this->TabSize);
    printf("Nombre d'éléments : %d\n",this->NumElems);
	printf("Contenu: out <- ");
    while(i!=(this->BackIndex+1)%this->TabSize){
        display_element(this->Table + i);
        printf(" <- ");
        i=(i+1)%this->TabSize;
	}
    printf("in\n");
}
