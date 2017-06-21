#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "funciones.h"

// funciones privadas
int resizeUp(ArrayList* this);
int expand(ArrayList* this,int index);
int contract(ArrayList* this,int index);

#define AL_INCREMENT      10
#define AL_INITIAL_VALUE  10
//___________________

/** \brief Allocate a new arrayList with AL_INITIAL_VALUE elements.
 * \param void
 * \return ArrayList* Return (NULL) if Error [if can't allocate memory]
 *                  - (pointer to new arrayList) if ok
 */
ArrayList* al_newArrayList(void)
{
    ArrayList* this;
    ArrayList* returnAux = NULL;
    void* pElements;
    this = (ArrayList *)malloc(sizeof(ArrayList));

    if(this != NULL)
    {
        pElements = malloc(sizeof(void *)*AL_INITIAL_VALUE );
        if(pElements != NULL)
        {
            this->size=0;
            this->pElements=pElements;
            this->reservedSize=AL_INITIAL_VALUE;
            this->add=al_add;
            this->len=al_len;
            this->set=al_set;
            this->remove=al_remove;
            this->clear=al_clear;
            this->clone=al_clone;
            this->get=al_get;
            this->contains=al_contains;
            this->push=al_push;
            this->indexOf=al_indexOf;
            this->isEmpty=al_isEmpty;
            this->pop=al_pop;
            this->subList=al_subList;
            this->containsAll=al_containsAll;
            this->deleteArrayList = al_deleteArrayList;
            this->sort = al_sort;
            returnAux = this;
        }
        else
        {
            free(this);
        }
    }

    return returnAux;
}


/** \brief  Add an element to arrayList and if is
 *          nessesary resize the array
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer] - (0) if Ok
 *
 */
int al_add(ArrayList* pList, void* pElement)
{

    int returnAux = -1;
    void* aux;
    int tam;
    int flag;

    if(pList!=NULL && pElement!=NULL)
    {
        flag = resizeUp(pList);

        if(flag==0)
        {
            tam = pList->size;
            pList->pElements[tam]=pElement;
            pList->size++;
            returnAux = 0;
        }
    }
    return returnAux;

}

/** \brief  Delete arrayList
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer] - (0) if Ok
 *
 */
int al_deleteArrayList(ArrayList* pList)
{
    int returnAux = -1;


    if(pList != NULL)
    {

        free(pList->pElements);

        free(pList);

        returnAux = 0;
    }


    return returnAux;
}

/** \brief  Delete arrayList
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return length of array or (-1) if Error [pList is NULL pointer]
 *
 */
int al_len(ArrayList* pList)
{
    int returnAux = -1;

    if(pList!=NULL)
    {
        returnAux = pList->size;
    }

    return returnAux;
}


/** \brief  Get an element by index
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return void* Return (NULL) if Error [pList is NULL pointer or invalid index] - (Pointer to element) if Ok
 *
 */
void* al_get(ArrayList* pList, int index)
{
    void* returnAux = NULL;
    int tam;

    if(pList != NULL)
    {
        tam = pList->size;
        if(index <= tam && index > -1)
        {
            returnAux = *(pList->pElements+index);
        }
    }


    return returnAux;
}


/** \brief  Find if pList contains at least one element pElement
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer]
 *                  - ( 0) if Ok but not found a element
 *                  - ( 1) if this list contains at least one element pElement
 *
 */
int al_contains(ArrayList* pList, void* pElement)
{
    int returnAux = -1;
    int i, tam, flag = 0;
    void* aux;

    if(pList != NULL && pElement != NULL )
    {
        tam = pList->size;

        for(i=0; i<tam; i++)
        {
            if( pElement == *(pList->pElements+i) )
            {
                flag = 1;
                break;
            }
        }

        if(flag == 1)
        {
            returnAux = 1;
        }
        else
        {
            returnAux = 0;
        }
    }

    return returnAux;
}


/** \brief  Set a element in pList at index position
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer or invalid index]
 *                  - ( 0) if Ok
 *
 */
int al_set(ArrayList* pList, int index,void* pElement)
{
    int returnAux = -1;
    int tam;

    if(pList != NULL && pElement != NULL)
    {
        tam = pList->size;
        if(index <= tam && index > -1)
        {
            *(pList->pElements+index) = pElement;
            returnAux = 0;
        }
    }

    return returnAux;
}


/** \brief  Remove an element by index
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int al_remove(ArrayList* pList,int index)
{
    int returnAux = -1;
    int flagContract;

    flagContract = contract(pList,index);

    if(flagContract == 0)
    {
        returnAux = 0;
    }

    return returnAux;
}



/** \brief Removes all of the elements from this list
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer]
 *                  - ( 0) if Ok
 */
int al_clear(ArrayList* pList)
{
    int returnAux = -1;
    int i;

    if(pList != NULL)
    {
        for(i=0; i<pList->size; i++)
        {
            free(pList->pElements+i);
        }

        pList->size = 0;
        pList->reservedSize = AL_INITIAL_VALUE;

        returnAux = 0;
    }
    return returnAux;
}



/** \brief Returns an array containing all of the elements in this list in proper sequence
 * \param pList ArrayList* Pointer to arrayList
 * \return ArrayList* Return  (NULL) if Error [pList is NULL pointer]
 *                          - (New array) if Ok
 */
ArrayList* al_clone(ArrayList* pList)
{
    ArrayList* returnAux = NULL;
    ArrayList* aux;
    int tam,i, flagAdd;

    if(pList != NULL)
    {
        aux = al_newArrayList();
        tam = pList->size;

        for(i=0; i<tam; i++)
        {
            flagAdd = al_add(aux,al_get(pList,i));
        }

        if(flagAdd == 0)
        {
            returnAux = aux;
        }
    }

    return returnAux;
}




/** \brief Inserts the element at the specified position
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int al_push(ArrayList* pList, int index, void* pElement)
{
    int returnAux = -1;
    int flag = 1, tam, i;
    void* aux;

    if(pList != NULL && pElement != NULL)
    {
        tam = pList->size;
        if(index<=tam && index > -1)
        {
            if(index == tam)
            {
                al_add(pList, pElement);
                returnAux = 0;
            }
            else
            {
                al_add(pList,pElement);
                tam = pList->size;
                for(i=(tam-1); i>index; i--)
                {
                    aux = al_get(pList,i);
                    al_set(pList,i,al_get(pList,(i-1)));
                    al_set(pList,(i-1),aux);
                }
                returnAux = 0;
            }
        }
    }


    return returnAux;
}



/** \brief Returns the index of the first occurrence of the specified element
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer] - (index to element) if Ok
 */
int al_indexOf(ArrayList* pList, void* pElement)
{
    int returnAux = -1;
    int i, tam;

    if(pList != NULL)
    {
        tam = pList->size;

        for(i=0; i<tam; i++)
        {
            if( *(pList->pElements+i) == pElement )
            {
                returnAux = i;
                break;
            }
        }
    }


    return returnAux;
}



/** \brief Returns true if this list contains no elements.
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer] - (0) if Not Empty - (1) if is Empty
 */
int al_isEmpty(ArrayList* pList)
{
    int returnAux = -1;
    int tam;

    if(pList != NULL)
    {
        tam = pList->size;
        if(tam == 0)
        {
            returnAux = 1;
        }
        else
        {
            returnAux = 0;
        }
    }
    return returnAux;
}




/** \brief Remove the item at the given position in the list, and return it.
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (NULL) if Error [pList is NULL pointer or invalid index]
 *                  - ( element pointer) if Ok
 */
void* al_pop(ArrayList* pList,int index)
{
    void* returnAux = NULL;
    void* aux;
    int tam;
    int flagRemove = 1;

    if(pList != NULL)
    {
        tam = pList->size;
        if(index <= tam && index > -1)
        {
            aux = *(pList->pElements+index);
            flagRemove = al_remove(pList,index);
        }

        if(flagRemove == 0)
        {
            returnAux = aux;
        }
    }
    return returnAux;
}


/** \brief Returns a new arrayList with a portion of pList between the specified
 *         fromIndex, inclusive, and toIndex, exclusive.
 * \param pList ArrayList* Pointer to arrayList
 * \param from int Initial index of the element (inclusive)
 * \param to int Final index of the element (exclusive)
 * \return int Return (NULL) if Error [pList is NULL pointer or invalid 'from' or invalid 'to']
 *                  - ( pointer to new array) if Ok
 */
ArrayList* al_subList(ArrayList* pList,int from,int to)
{
    ArrayList* pList2 = NULL;
    int i,tam;

    if(pList != NULL && from<to)
    {
        tam = pList->size;

        if( to>0 && to<=tam)
        {
            if(from>-1 && from<tam)
            {
                pList2 = al_newArrayList();

                for(i=from; i<to; i++)
                {
                    al_add(pList2,al_get(pList,i));
                }
            }

        }
    }

    return pList2;
}


/** \brief Returns true if pList list contains all of the elements of pList2
 * \param pList ArrayList* Pointer to arrayList
 * \param pList2 ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList or pList2 are NULL pointer]
 *                  - (0) if Not contains All - (1) if is contains All
 */
int al_containsAll(ArrayList* pList,ArrayList* pList2)
{
    int returnAux = -1;
    int i,flag, tam2;


    if(pList != NULL && pList2 != NULL)
    {
        tam2 = pList2->size;

        returnAux = 1;
        for(i=0; i<tam2; i++)
        {
            flag = al_contains(pList, al_get(pList2, i));
            if(flag == 0)
            {
                returnAux = 0;
                break;
            }
        }

    }


    return returnAux;
}

/** \brief Sorts objects of list, use compare pFunc
 * \param pList ArrayList* Pointer to arrayList
 * \param pFunc (*pFunc) Pointer to fuction to compare elements of arrayList
 * \param order int  [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [pList or pFunc are NULL pointer]
 *                  - (0) if ok
 */
int al_sort(ArrayList* pList, int (*pFunc)(void*,void*), int order)
{
    int returnAux = -1;
    int i, j, aux;

    void* AuxpList;
    if(pList != NULL && pFunc != NULL && order > -1 && order < 2)
    {
        for(i=0; i<al_len(pList)-1; i++)
        {
            for(j=i+1; j<al_len(pList); j++)
            {
                aux = pFunc(pList->pElements[i],pList->pElements[j]);
                switch(aux)
                {
                case -1:
                    if(order == 0)
                    {
                        AuxpList = pList->pElements[j];
                        pList->pElements[j] = pList->pElements[i];
                        pList->pElements[i] = AuxpList;
                    }
                    else
                    {
                        continue;
                    }
                    break;
                case 0:
                    continue;
                    break;
                case 1:
                    if(order == 0)
                    {
                        continue;
                    }
                    else
                    {
                        AuxpList = pList->pElements[j];
                        pList->pElements[j] = pList->pElements[i];
                        pList->pElements[i] = AuxpList;
                    }
                    break;
                }
            }
        }
        returnAux = 0;
    }

    return returnAux;
}


/** \brief Increment the number of elements in pList in AL_INCREMENT elements.
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer or if can't allocate memory]
 *                  - (0) if ok
 */
int resizeUp(ArrayList* pList)
{
    int returnAux = -1;
    void* aux;
    int flag = 0;
    if(pList != NULL)
    {
        if(pList->size == pList->reservedSize)
        {
            aux = realloc(pList->pElements, sizeof(void*) * (pList->reservedSize + AL_INCREMENT));
            if(aux!=NULL)
            {
                pList->pElements = aux;
                pList->reservedSize+=AL_INCREMENT;
                flag = 1;
            }
        }
        else
        {
            flag = 1;
        }

        if(flag != 0)
        {
            returnAux = 0;
        }

    }

    return returnAux;

}

/** \brief  Expand an array list
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int expand(ArrayList* pList,int index)
{
    int returnAux = -1;
    int flagResizeUp;
    int i;
    void* aux;
    aux = (void*) malloc (sizeof(void));

    if(pList != NULL)
    {
        int tam = pList->size;
        if(index<tam && index > -1)
        {
            flagResizeUp = resizeUp(pList);
            if(flagResizeUp == 0)
            {
                al_add(pList,aux);
                for(i=(tam-1); i=index; i--)
                {
                    al_set(pList,i,al_get(pList,(i-1)));
                }
                returnAux = 0;
            }
        }

    }

    return returnAux;
}

/** \brief  Contract an array list
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int contract(ArrayList* pList,int index)
{
    int returnAux = -1,i;
    if( pList!= NULL && (index >= 0 && index <  pList->size))
    {
        for(i=index; i<al_len( pList); i++)
        {
            pList->pElements[i] =  pList->pElements[i+1];
        }
        pList->size--;
        returnAux = 0;
    }
    return returnAux;
}




int resizeDown(ArrayList* pList)
{
    int returnAux = -1;
    void* aux;
    int tamSize = pList->size;
    int tamReservado = pList->reservedSize;

    if(pList != NULL)
    {

        if( (tamReservado-tamSize)> 10 )
        {
            pList->reservedSize = (tamSize + AL_INCREMENT);
        }

        returnAux = 0;
    }

    return returnAux;
}


