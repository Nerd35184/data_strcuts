#include "link_list.h"
#include<stdlib.h>
#include<string.h>

LinkListElem* alloc_link_list_elem(void* data,size_t data_size){
    LinkListElem* link_list_elem_p=malloc(sizeof(LinkListElem));
    if(link_list_elem_p==NULL){
        exit(-1);
        return NULL;
    }

    link_list_elem_p->elem=malloc(data_size);
    if(link_list_elem_p->elem==NULL){
        free(link_list_elem_p);
        exit(-1);
        return NULL;
    }
    memcpy(link_list_elem_p->elem,data,data_size);
    return link_list_elem_p;
}

int free_link_list_elem(LinkListElem** link_list_elem_pp){
    if(link_list_elem_pp==NULL){
        return -1;
    }

    LinkListElem* link_list_elem_p=*link_list_elem_pp;
    if(link_list_elem_p==NULL){
        return -1;
    }
    free(link_list_elem_p->elem);
    //todo 可能不需要
    link_list_elem_p->elem=NULL;
    free(link_list_elem_p);
    *link_list_elem_pp=NULL;
    return 0;
}


LinkList* alloc_link_list(size_t elem_size){
    //todo 可能为0也可以
    if(elem_size<=0){
        return NULL;
    }
    LinkList* link_list = malloc(sizeof(LinkList));
    if(link_list==NULL){
        return NULL;
    }
    memset(link_list,0,sizeof(LinkList));
    link_list->elem_size=elem_size;
    link_list->length=0;
    link_list->root.elem=NULL;
    link_list->root.link_list=link_list;
    link_list->root.prew=&link_list->root;
    link_list->root.next=&link_list->root;
    return link_list;
}


int free_link_list(LinkList** link_list_pp){
    if(link_list_pp==NULL){
        return -1;
    }
    LinkList* link_list_p=*link_list_pp;
    if(link_list_p==NULL){
        return -1;
    }

    LinkListElem* root=&link_list_p->root;
    LinkListElem* cur=link_list_p->root.next;
    LinkListElem* next=NULL;
    while(root!=cur){
        next = cur->next;
        //todo 链表如果释放内存到一半，失败了，要如何处理，这个得具体的考量一下
        int ret=free_link_list_elem(&cur);
        if(ret!=0){
            return ret;
        }
        cur = next;
    }

    free(link_list_p);
    *link_list_pp=NULL;
}


LinkListElem* get_link_list_front(LinkList* link_list_p){
    if(link_list_p==NULL){
        return NULL;
    }
    if(link_list_p->length==0){
        return NULL;
    }
    return link_list_p->root.next;
}

LinkListElem* get_link_list_back(LinkList* link_list_p){
    if(link_list_p==NULL){
        return NULL;
    }
    
    if(link_list_p->length==0){
        return NULL;
    }
    return link_list_p->root.prew;
}

int insert_link_list_after_elem(LinkListElem* elem,LinkListElem* mark){
    if(elem==NULL || mark==NULL || mark->link_list==NULL){
        return -1;
    }
    LinkList* link_list_p=mark->link_list;
    LinkListElem* first=mark;
    LinkListElem* second=elem;
    LinkListElem* third=mark->next;
    first->next=second;
    second->prew=first;
    second->next=third;
    third->prew=second;
    second->link_list=link_list_p;
    ++link_list_p->length;
    return 0;
}

int insert_link_list_before_elem(LinkListElem* elem,LinkListElem* mark){
    return insert_link_list_after_elem(elem,mark->prew);
}

int push_back_link_list(LinkList* link_list_p, void* data){
    if(link_list_p==NULL || data==NULL){
        return -1;
    }
    LinkListElem* elem= alloc_link_list_elem(data,link_list_p->elem_size);
    return insert_link_list_before_elem(&link_list_p->root,elem);
}


int push_front_link_list(LinkList* link_list_p, void* data){
    if(link_list_p==NULL || data==NULL){
        return -1;
    }
    LinkListElem* elem= alloc_link_list_elem(data,link_list_p->elem_size);
    return insert_link_list_after_elem(&link_list_p->root,elem);
}



// int remove_link_list_elem(LinkList* link_list_p,LinkListElem* link_list_elem_p){
//     if(link_list_p==NULL || link_list_elem_p==NULL){
//         return -1;
//     }

//     if(link_list_elem_p->link_list!=link_list_p){
//         return -1;
//     }


//     if(link_list_elem_p==&link_list_p->root){
//         return -1;
//     }

//     --link_list_p->length;
// }
