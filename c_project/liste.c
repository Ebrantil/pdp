// Praxis der Programmierung
// Hausaufgabe 1 - liste
// Abgabedatum: 28.5.2017
//
// Gruppennummer: 51
// Gruppenmitglieder:
// - Georg Duchrau
// - Nico Maronde
// - Maximilian Budwill

#include <stdio.h>
#include <stdlib.h>
#define zv printf("\n");  // kurzer zeilenvorschub

struct le {
    int value;
    struct le *next;
};

typedef struct le listenelement;
typedef listenelement *list;

void insert(int v,list *l){
    listenelement *new;
    new = malloc(sizeof(listenelement));
    new->value =v;
    new->next=*l;
    *l=new;
}

int insert_pos(int v, int pos, list * l){
    if (pos==0 /* or  *l==NULL  */){     //falls vorne angehängt wird, kann insert() benutzt werden
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

void sort(int m, list *l){

	
	if(m==0) m+=1;  // m==0 wird als positiv gewertet (m=0 macht sonst den vergleich kaputt)

	int aktuell;
	list sorted_list=NULL;
	list* runner=&sorted_list;	
	list* start=&sorted_list;
	int count=0;
	
	


	while(*l!=NULL){
		aktuell=(*l)->value;	//hohle neuen wert
		runner=start;		//setzte runner auf anfang der sortierten teil-liste
				
		count=0;		//reset counter
		while(*runner!=NULL){   //bis zum ende der aufzubauenden sortierten liste
			

			if(m*aktuell <= m*(*runner)->value ) break;     //Vergleiche Werte (Multipl. mit m ergibt gewünschtes Relationszeichen			
			count += 1;				// Inkrementiere zukünftige Position des einzusortierenden Elementes  
			runner=&(*runner)->next;			//setzte den Pointer zur speicherung der aktuellen Position ein Element weiter
						
		}
			
		insert_pos(aktuell,count,start);   //insert entsprechend der ermittelten Position
					
		
		delete_head(l);   //lösche einsortiertes Element aus *l
		
	}
	*l=sorted_list;   //etzte sortierte Liste an Stelle der übergebenen unsortierten

}

int main(){
    list Liste=NULL;// erstellt leere Liste
    printf("\nLeere Liste erstellt.\n");

    //test length function
    printf("\nAufruf length()\n");
    printf("---------------------------");
    printf("\nElement(e) in der Liste: %d\n",length(Liste));

    printf("\nAufruf insert()\n");
    printf("---------------------------");
    printf("\nEs werden die Elemente {1,4,3,4,7,6} je an POS 0 der Liste angefuegt.");
    // test insert function
    insert(1,&Liste);
    insert(4,&Liste);
    insert(3,&Liste);
    insert(4,&Liste);
    insert(7,&Liste);
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

    printf("\n Aufruf sort(m=-1):\n");
    printf("---------------------------");
    sort(1,&Liste);   
    printf(":\n");
    print_list(Liste);
    
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

	//test delete_all    , Bei delete_all muss noch manuell Liste =NULL gesetzt werden!
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
