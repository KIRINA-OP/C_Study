#include "sqlist.h"
int main()
{
    sqlist *list ;
    datatype arr[]={12, 23, 34, 45, 56};
    sqlist_create1(&list);
    int i, err;
    if(list ==NULL)
    {
        fprintf(stderr, "sqlist_create() failed!\n");
        exit(1);
    }
    for(i =0; i<sizeof(arr)/sizeof(*arr);i++)
    {   err = sqlist_insert(list, i, &arr[i]);
        if(err!=0)
        {   
            if(err == -1)
                fprintf(stderr, "The arr is full.");
            else if(err == -2)
                fprintf(stderr, "the pos you want to insert is wrong");
            else 
                fprintf(stderr, "Error!\n");
            exit(1);
        }      
    }
    sqlist_display(list);
    err=sqlist_delete(list,1);
    if(err==-1)
        fprintf(stderr,"The pos you want to delete is wrong");
    sqlist_display(list);
    int *p=&arr[0];
    int index=sqlist_find(list,p);
    printf("%d \n", index);
    *p=list->data[3];
    printf("%d \n", *p);
    //test sqlist_find
    index=sqlist_find(list,p);
    printf("found index = %d \n", index);

    //test sqlist union
    sqlist * list2;
    datatype arr2[]={12, 78, 51, 99};
    sqlist_create1(&list2);

    for(i =0; i<sizeof(arr2)/sizeof(*arr2);i++)
    {   err = sqlist_insert(list2, i, &arr2[i]);
        if(err!=0)
        {   
            if(err == -1)
                fprintf(stderr, "The arr is full.");
            else if(err == -2)
                fprintf(stderr, "the pos you want to insert is wrong");
            else 
                fprintf(stderr, "Error!\n");
            exit(1);
        }      
    }

    sqlist_display(list2);

    sqlist_union(list,list2);

    sqlist_display(list);
    sqlist_destroy(list);
    
    sqlist_destroy(list2);

    exit(0);
}


