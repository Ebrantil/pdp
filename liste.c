#include <stdio.h>
#include <stdlib.h>

struct le {
								int value;
								struct le * next;
};

typedef struct le listenelement;
typedef listenelement * list;


int insert(); //adds element with value v to FIRST position of list 1
int insert_pos(); //adds element with value v to position 'pos' of list 1
int print_list(); //prints ALL elements of list
int length();//counts ALL elements of list 1

int delete_head(); //deletes FIRST element of list 1
int delete_elem(); //deletes ALL elements WITH value e from list 1
int delete_all(); //deletes ALL elements from list 1
int alles_weg();

int sort(); //sort list 1 with insertionSort



void insert(int v,list *l){
								listenelement *new;
								new = malloc(sizeof(listenelement));
								new->value =v;
								new->next=*l;
								*l=new;
}

void insert_pos(int v, int pos, list *l){
								listenelement *new;
								new = malloc(sizeof(listenelement));
								new->value =v;
								new->next =NULL;
								if(pos==1) {
																new->next=*l;
																*l=new;
								}
								else{
																listenelement *temp=*l;
																int i;
																for(i=1; i<pos-1; i++) {
																								temp =temp->next;
																}
																new->next = temp->next;
																temp->next = new;
								}


}

void print_list(list l) {
								if (l == NULL) printf("leer");
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

}

void delete_all(list l) {
								list next;
								while (l != NULL) {
																next = l->next;
																free(l);
																l = next;
								}
}

/*
   void alles_weg(list *l){

    while(*l != NULL){

        delete_head(l);
    }
   }

   void alles_weg(list *l){ //für fehlerbehaftete vorlesungsversion
        while(*l != NULL) {
                delete_head(l);
        }
   }*/

int sort(int m, list * l)
{

}

int main(){
								//listenkopf erstellen
								listenelement *liste;
								liste=malloc(sizeof(listenelement));
								liste->next=NULL;
								//liste->value=NULL;

								printf("\nlistenkopf.next%p",liste->next);
								printf("\tlistenkopf.value %d",liste->value);


								//test length function
								printf("\nlaenge: %d \n",length(liste));
								// test insert function
								insert(1,&liste);
								insert(5,&liste);
								printf("\n2 elemente links angefügt:");
								print_list(liste);
								//test delete head
								delete_head(&liste);
								printf("\nkopf geloescht:");
								print_list(liste);
								//test delete_all
								//delete_all(liste);
								alles_weg(&liste);
								printf("\nliste geloescht:");
								print_list(liste);

}
