#include "sqlist.h"






sqlist* sqlist_create()
{
    sqlist *me;
    me = malloc(sizeof(*me));
    if(me == NULL)
        return NULL;
    me->last = -1;
    return me;
}
void sqlist_create1(sqlist **ptr)
{
    *ptr = malloc (sizeof(**ptr));
    if(*ptr == NULL)
        return;
    (*ptr)->last = -1;
    return;
}

int sqlist_insert(sqlist *me, int index, datatype *x)
{
    if(me->last == DATASIZE-1)
        return -1;
    if(index < 0 || index > (me->last +1))
        {   
            //printf("ababa %d\n", index);
            return -2;
        }
    //every element's index+1
    for(int j = me->last; index<=j; j--)
    {
        me->data[j+1] = me->data[j];
    }
    me->data[index]=*x;
    me->last++;
    //success

    return 0;
}
int sqlist_delete(sqlist *me, int index)
{
    if(index < 0 || index > (me->last+1))
        return -1;
    for(int i=index;i<me->last;i++)
    {
        (me->data[i])=(me->data[i+1]);
    }
    me->last--;
    return 0;
}
int sqlist_find(sqlist *me, datatype *d)
{
    if(sqlist_isempty(me)==1)
    {
        return -2;
    }
    for(int i=0; i<me->last+1; i++)
    {
            if(me->data[i]==*d)
            return i;
    }
    //unable to find   
    return -1;
}
int sqlist_isempty(sqlist *me)
{
    return (me->last==-1);
}
int sqlist_setempty(sqlist *me)
{
    for(int i=0; i<=me->last;i++)
        memset(me->data, 0, sizeof(me->data[i]));
    me->last=-1;
    
    return 0;
}
int sqlist_getnum(sqlist *me)
{
    return me->last;
}
void sqlist_display(sqlist *me)
{
    if(me->last ==-1)
        return;
    for(int i = 0;i<=me->last ;i++)
    {
        printf("%d ",me->data[i]);
    }
    printf("\n");
    return;
}
int sqlist_union(sqlist *list1, sqlist *list2)
{
    //list 1->12 23 34 45 56
    //list 2->78 89 56 23 10
    //set list1 as the list to be added
    
    for(int i=0; i<list2->last+1;i++)
    {
        //unable to find
        if(sqlist_find(list1,&list2->data[i])>=0)
            continue;
        sqlist_insert(list1,list1->last+1,&list2->data[i]);
    }
    return 0;
}

int sqlist_destroy(sqlist *me)
{
    free(me);
    return 0;
}//return if destroyed or not
