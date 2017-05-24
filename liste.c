#include <stdio.h>
#include <stdlib.h>
#define zv printf("\n");



struct le {
int value;
struct le * next;
};
typedef struct le listenelement;

typedef listenelement * list;



void insert(int v, list * l){
    listenelement *new;
    new= malloc(sizeof(listenelement));
    new->value= v;
    new->next= *l;
    *l =new;
}


int insert_pos(int v, int pos, list * l){
    if (pos==0){     //falls vorne angehängt wird, kann insert() benutzt werden
        insert(v,l);
        return 0;
    }
    int count=0; // aktuelle position
    list  * next=&(*l);
    while(count < pos && *next!=NULL){
        next=&(*next)->next;
        count+=1;
    } 
    if (count<pos) return -1;
    listenelement * new=malloc(sizeof(listenelement));
    new->value=v;
    new->next=*next;
    *next=new;
            
    return 0;   
}





int delete_head(list * l){

    if(*l == NULL) return -1;
    list old =*l;
    *l=old->next;
    free(old);
    return 0;
}



void alles_weg(list *l){ //für fehlerbehaftete vorlesungsversion
    
    while(*l != NULL){
    
        delete_head(l);
    }    
}


void delete_all(list l){
    list next;
    while(l!=NULL){
        next=l->next;
        free(l);
        l= next;
        
    }
    
}

int length(list l){                
    int count =0;
    while(l!=NULL){
        count++;
        l=l->next;
    }
    return count;
}


void print_list(list l){
    if(l== NULL) printf("leer");
    else
        while (l!= NULL){
            printf("%d ", l->value);
            l= l->next;
        }
        
}




int main(){
    
    
   
    return 0;  
}    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
