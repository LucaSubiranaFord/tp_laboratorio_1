#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/ArrayList.h"

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
        }else
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
    aux = al_newArrayList();
    int i;


    if(pList != NULL)
    {
        aux->size = pList->size;
        aux->reservedSize = pList->reservedSize;

        for(i=0;i<aux->size;i++)
        {
            *(aux->pElements+i) = *(pList->pElements+i);
        }
        returnAux = aux;
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
    int flag, tam;

    if(pList != NULL)
    {
        tam = pList->size;

        if(index<=tam && index > -1)
        {
            if(index == tam)
            {
                flag = al_add(pList, pElement);

            }
            else
            {
                flag = expand(pList,index);
            }

            if(flag == 0)
            {
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

        for(i=0;i<tam;i++)
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
    int flagRemove;

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
    //void* returnAux = NULL; El ejercicio arranco asi, pero creo que se deberia hacer asi ->
    ArrayList* pList2 = NULL;
    int i,j,tam;

    if(pList != NULL)
    {
        pList2 = al_newArrayList();
        tam = to-from; // COMO EL TO ES EXCLUSIVO, EL TO-FROM COINCIDE CON EL TAMA�O QUE TENDRA EL NUEVO ARRAY.
        pList2->size = tam;
        pList->reservedSize = tam + AL_INCREMENT;

        for(i=from;i<to;i++)
        {
           for(j=0;i<tam;j++)
           {
                *(pList2->pElements+j) = *(pList->pElements+i);
                break;
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
    int i, j, flag, cont = 0, tam, tam2, tamT;


    if(pList != NULL && pList2 != NULL)
    {
        tam = pList->size;
        tam2 = pList2->size;

        /*if(tam > tam2)
        {
            tamT = tam;
        }else
        {
            tamT = tam2;     //TENDRIA QUE APLICAR ESTO SI ES MAS GRANDE?
        }*/

        for(i=0;i<tam;i++)
        {
            for(j=0;i<tam2;i++)
            {
                if( *(pList->pElements+i) == *(pList2->pElements+j) )
                {
                    cont++;
                    break;
                }
            }
        }

        if(cont == tam2)
        {
            returnAux = 1;
        }else
        {
            returnAux = 0;
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
int al_sort(ArrayList* this, int (*pFunc)(void*,void*), int order)
{
    int returnAux = -1;

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

    if(pList != NULL)
    {
        int tam = pList->size;
        if(index<=tam && index > -1)
        {
            flagResizeUp = resizeUp(pList);
            if(flagResizeUp = 0)
            {
                pList->size += 1;
                for(i=tam; i=index; i--)
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
    int returnAux = -1;
    int i,j;
    void* aux;
    int tam;

    if(pList != NULL)
    {
        tam = pList->size;
        if(index <= tam && index > -1)
        {
            for(i=index; i=(tam-1); i++)
            {
                for(j=(i+1); j=tam; j++)
                {
                    aux = *(pList->pElements+i);
                    *(pList->pElements+i) = *(pList->pElements+j);
                    *(pList->pElements+j) = aux;
                    break;
                }
            }

            free(pList->pElements+tam);
            pList->size -= 1;
            returnAux = 0;
            resizeDown(pList);
        }

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
