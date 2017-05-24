#include <stdio.h>
#include <stdlib.h>
#define zv printf("\n");  // kurzer zeilenvorschub

struct le {
    int value;
    struct le * next;
};

typedef struct le listenelement;
typedef listenelement * list;


void insert(); //adds element with value v to FIRST position of list 1
int insert_pos(); //adds element with value v to position 'pos' of list 1
void print_list(); //prints ALL elements of list
int length();//counts ALL elements of list 1

int delete_head(); //deletes FIRST element of list 1
int delete_elem(); //deletes ALL elements WITH value e from list 1
void delete_all(); //deletes ALL elements from list 1

int sort(); //sort list 1 with insertionSort



void insert(int v,list *l){
    listenelement *new;
    new = malloc(sizeof(listenelement));
    new->value =v;
    new->next=*l;
    *l=new;
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



void print_list(list l) {       //gibt Werte und pointer aus
    if (l == NULL) printf("\nleer");
    else
        while (l != NULL) {
            printf("\n%d ", l->value);
            printf("\t%p ", l->next);
            l = l->next;
	}
}

int length(list l) {
    int count = 0;
    while (l != NULL) {
        count++;
        l = l->next;
    }
    return count;
}

int delete_head(list * l) {
    if (*l == NULL) return -1;
    list old = *l;
    *l = old->next;
    free(old);
    return 0;
}

int delete_elem(int e, list * l) {
    return 0;
}

void delete_all(list l) {
    list next;
    while (l != NULL) {
        next = l->next;
        free(l);
        l = next;
    }
}


void alles_weg(list *l){

    while(*l != NULL){

        delete_head(l);
    }
   }


int sort(int m, list * l)
{
    return 0;
}

int main(){
    list Liste=NULL;// erstellt leere Liste
    printf("\nleere Liste erstellt\n");

                                                                //printf("\nlistenkopf.next%p",liste->next);
								//printf("\tlistenkopf.value %d",liste->value);


								//test length function
    printf("\nElement(e) in der Liste: %d\n",length(Liste));

								// test insert function
    insert(1,&Liste);
    insert(5,&Liste);
    printf("\n2 Elemente links angefuegt:\n");
    printf("---------------------------");
    print_list(Liste);

								//test delete head
    delete_head(&Liste);
    printf("\n\nListenkopf geloescht:\n");
    printf("---------------------------");
    print_list(Liste);

								//test delete_all    , Bei delete_all muss noch manuell Liste =NULL gesetzt werden! will man das nicht, kkann man alles_weg nehmen
    delete_all(Liste);
    printf("\n\nAlle Listenelemete geloescht:\n");
    printf("---------------------------");
    print_list(Liste); zv
    Liste =NULL;
    printf("\nHeadpointer wieder auf NULL gesetzt\n");
    printf("---------------------------");
    print_list(Liste); zv
    
    return 0;
}
