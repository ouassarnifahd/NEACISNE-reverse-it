/** @file liste.c
*   @brief Ficher source contenant les fonctions de manupilation des listes.
*/

#include "../inc/liste.h"

PTList TList_New(int sizeofElem){
    PTList this = malloc(sizeof(TList));
    if(!this) return NULL;
    this->NumElems      = 0;
    this->SizeofElem    = sizeofElem;
    this->First         = NULL;
    this->Last          = NULL;
    this->Current       = NULL;
    this->Index         = -1;
    this->IsEmpty       = (void*) TList_IsEmpty;
    this->Length        = (void*) TList_Length;
    this->GetIndex      = (void*) TList_GetIndex;
    this->GoTo          = (void*) TList_GoTo;
    this->InsertFirst   = (void*) TList_InsertFirst;
    this->RemoveFirst   = (void*) TList_RemoveFirst;
    this->Add           = (void*) TList_Add;
    this->RemoveLast    = (void*) TList_RemoveLast;
    this->Insert        = (void*) TList_Insert;
    this->RemoveCurrent = (void*) TList_RemoveCurrent;
    this->Clear         = (void*) TList_Clear;
    this->Display       = (void*) TList_Display;
    this->Delete        = (void*) TList_Delete;
    return this;
}

static bool TList_IsEmpty(const PTList this){
    return (this->NumElems)?0:1;
}

static int TList_Length(const PTList this){
    return this->NumElems;
}

static int TList_GetSizeofElem(const PTList this){
    return this->SizeofElem;
}

static PTNode TList_GoTo(const PTList this, int Pos){
    if(TList_Length(this) <= Pos) return NULL;
    this->Current = this->First;
    this->Index = 0;
    while(this->Index < Pos){
        this->Current = this->Current->Next;
        this->Index++;
    }
    return this->Current;
}

static int TList_GetIndex(const PTList this){
    return this->Index;
}

static PTNode TList_InsertFirst(const PTList this, void* pNewElt){
    PTNode newNode = malloc(sizeof(TNode));
    if(!newNode)    return NULL;
    PTElement NewElt = new_element(TList_GetSizeofElem(this));
    if(!NewElt)  return NULL;
    *NewElt->pElement = *(BElement*)pNewElt;
    newNode->Element = NewElt;
    newNode->Next = this->First;
    if(TList_IsEmpty(this))
        this->Last = newNode;
    this->NumElems++;
    this->Index = 0;
    return newNode;
}

static bool TList_RemoveFirst(const PTList this){
    if(TList_IsEmpty(this)) return 0;
    PTNode pNode = this->First;
    PTNode nextNode = pNode->Next;
    free(pNode);
    this->First = nextNode;
    this->NumElems--;
    this->Index = 0;
    if(TList_IsEmpty(this))
        this->Last = NULL;
    return 1;
}

static PTNode TList_Add(const PTList this, void* pNewElt){
    PTNode newNode = (PTNode)malloc(sizeof(TNode));
    if(!newNode) return NULL;
    PTElement NewElt = new_element(TList_GetSizeofElem(this));
    if(!NewElt) return NULL;
    *NewElt->pElement = *(BElement*)pNewElt;
    newNode->Element = NewElt;
    newNode->Next = NULL;
    if(TList_IsEmpty(this))
        this->First=newNode;
    else
        this->Last->Next=newNode;
    this->Last=newNode;
    this->NumElems++;
    this->Index = this->NumElems - 1 ;
    return newNode;
}

static bool TList_RemoveLast(const PTList this){
    if(TList_IsEmpty(this)) return 0;
    PTNode prevNode=this->First, pNode=prevNode->Next;
    if(!pNode){
        free(prevNode);
        this->First=NULL;
        this->Last=NULL;
    }
    else {
        while(pNode->Next){
            prevNode=pNode;
            pNode=pNode->Next;
        }
        free(pNode);
        prevNode->Next=NULL;
        this->Last=prevNode;
    }
    this->NumElems--;
    this->Index = this->NumElems - 1 ;
    return true;
}

static PTNode TList_Insert(const PTList this, void* pNewElt){
    if(!this->Current) return NULL;
    if(this->First==this->Current){
        this->First=TList_InsertFirst(this, pNewElt);
        this->Current=this->First;
    } else {
        PTNode newNode=(PTNode)malloc(sizeof(TNode));
        if(!newNode) return NULL;
        PTElement NewElt = new_element(TList_GetSizeofElem(this));
        if(!NewElt)  return NULL;
        *NewElt->pElement = *(BElement*)pNewElt;
        newNode->Element = NewElt;
        newNode->Next=this->Current;
        TList_GoTo(this, this->Index-1);
        this->Current->Next=newNode;
        this->Current=newNode;
        this->Index++;
        this->NumElems++;
    }
    return this->Current;
}

static bool TList_RemoveCurrent(const PTList this){
    bool status=(TList_IsEmpty(this) || !this->Current);
    if(status) return 0;
    if(this->Current == this->First){
        status=TList_RemoveFirst(this);
        if(status){
            this->Current=this->First;
            if(!this->Current)
                this->Index=-1;
        }
        return status;
    }
    if(this->Current == this->Last){
        status=TList_RemoveLast(this);
        if(status){
            this->Current=this->Last;
            if(!this->Current)
                this->Index=-1;
        }
        return status;
    }
    PTNode pNodeToRemove=this->Current;
    this->GoTo(this, this->Index-1);
    this->Current->Next=pNodeToRemove->Next;
    free(pNodeToRemove);
    this->Current=this->Current->Next;
    this->Index++;
    this->NumElems--;
    return 1;
}

static void TList_Clear(const PTList this){
    while(TList_RemoveLast(this));
}

static void TList_Delete(const PTList this){
    TList_Clear(this);
    free(this);
}

static void TList_Display(const PTList this ,void (*display)(const void *)){
    PTNode CurrentNode=this->First;
    int currentIndex=TList_GetIndex(this);
    printf("Taille de la liste : %d\n", TList_Length(this));
    printf("Contenu : ");
    while(CurrentNode){
        display(CurrentNode->Element->pElement);
        printf(" -> ");
        CurrentNode=CurrentNode->Next;
    }
    printf("(null)\n");
    printf("Position courante : %d\n", currentIndex);
    if(TList_GetIndex(this)!=-1){
        printf("Element courant = ");
        display(TList_GoTo(this,currentIndex)->Element->pElement);
    }

}
