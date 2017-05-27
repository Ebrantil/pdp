#include <stdio.h>
#include <stdlib.h>
#define zv printf("\n");  // kurzer zeilenvorschub

struct le {
    int value;
    struct le *next;
};

typedef struct le listenelement;
typedef listenelement *list;

void insert(); //adds element with value v to FIRST position of list
int insert_pos(); //adds element with value v to position 'pos' of list
void print_list(); //prints ALL elements of list
int length();//counts ALL elements of list
int delete_head(); //deletes FIRST element of list
int delete_elem(); //deletes ALL elements WITH value e from list
void delete_all(); //deletes ALL elements from list
void sort(); //create new least and prepare sorting
void sortedInsert(); //sort new list by inserting from old list


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

int delete_head(list *l) {
    if (*l == NULL) return -1;
    list old = *l;
    *l = old->next;
    free(old);
    return 0;
}

int delete_elem(int e, list *l) {
    list  old;
    int z=-1;   //speichert ausgabewert 0 falls gelöscht -1 falls e nicht in Liste

    while(*l!=NULL){

        if ((*l)->value==e){   //vorkommen aufgespürt
            z=0;
            old=*l;     //merke zeiger auf zu löschendes element
            *l=old->next;                //verknüpfe vorgänger mt nachfolger

            free(old);     //lösche altes element

        }
        else l=&(*l)->next;   // gehe weiter

    }

    return z;
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

/*
void sort(struct list *l)
{
    // Initialize new sorted list
    list sorted= NULL;

    // Traverse the given list and insert every
    // value to sorted
    struct le *liste = *sorted;
    while (*l != NULL)
    {
        // Store next for next iteration
        struct le *next = listenelement->next;

        // insert current in sorted linked list
        sortedInsert(&sorted, listenelement);

        // Update current
        listenelement = next;
    }

    // Update listhead to point to sorted list
    *le = sorted;

}
void sortedInsert(int m, struct value** sorted, struct value* new_value)
{
    struct le* listenelement;
    //case for the head end
    if (*list == NULL || (*list)->value >= new_value->value)
    {
        new_value->next = *sorted;
        *sorted = new_value;
    }
    else {
        //Locate the value before the point of insertion
        list = *sorted;
        while (listenelement->next != NULL &&
               listenelement->next->value < new_value->value) {
           //sort ascending
            if (m = -1) {
                listenelement = listenelement->next;
                new_value->next = listenelement->next;
            listenelement->next = new_value;
        }
        new_value->next = value->next;
        Liste->next = sorted;
    }
}
*/

int main(){
    list Liste=NULL;// erstellt leere Liste
    printf("\nLeere Liste erstellt.\n");

    //printf("\nlistenkopf.next%p",liste->next);
    //printf("\tlistenkopf.value %d",liste->value);

    //test length function
    printf("\nAufruf length()\n");
    printf("---------------------------");
    printf("\nElement(e) in der Liste: %d\n",length(Liste));

    printf("\nAufruf insert()\n");
    printf("---------------------------");
    printf("\nEs werden die Elemente {1,4,3,4,5,6} je an POS 1 der Liste angefuegt.");
    // test insert function
    insert(1,&Liste);
    insert(4,&Liste);
    insert(3,&Liste);
    insert(4,&Liste);
    insert(5,&Liste);
    insert(6,&Liste);
    printf("\nElement(e) in der Liste: %d\n",length(Liste));

    printf("\nAufruf print_list()\n");
    printf("---------------------------");
    print_list(Liste);

    //test insert_pos
    printf("\n\nAufruf insert_pos)\n");
    printf("---------------------------");
    insert_pos(4,5,&Liste);
    print_list(Liste);
    printf("\nElement mit Wert = 4 an Position 5 angefügt.\n");
    printf("\nElement(e) in der Liste: %d\n",length(Liste));


    /*//test insertion_sort
    printf("\n\nAufruf sort()\n");
    printf("---------------------------");
    sort(&Liste);
    print_list(Liste);*/

    //test delete_elem
    printf("\n\nAufruf delete_elem()\n");
    printf("---------------------------");
    delete_elem(4,&Liste);
    print_list(Liste);
    printf("\nAlle Elemente mit Wert: 4 gelöscht:\n");

    //test delete head
    printf("\n\nAufruf delete_head()\n");
    printf("---------------------------");
    delete_head(&Liste);
    print_list(Liste);
    printf("\nElement(e) in der Liste: %d\n",length(Liste));

	//test delete_all    , Bei delete_all muss noch manuell Liste =NULL gesetzt werden! will man das nicht, kann man alles_weg nehmen
    printf("\n\nAufruf delete_all:\n");
    printf("---------------------------");
    delete_all(Liste);
    Liste =NULL;
    print_list(Liste); zv
    printf("\nElement(e) in der Liste: %d\n",length(Liste));

    /*printf("\nHeadpointer wieder auf NULL gesetzt\n");
    print_list(Liste); zv*/

    return 0;
}
