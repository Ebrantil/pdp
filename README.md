# pdp
Praxis der Programmierung SoSe2017 Abgaben

Hausaufgabe Nr. 1 (Abgabe bis 28. Mai 2017)
Bearbeiten Sie bitte diese Hausaufgabe in einem Team aus mindestens zwei und höchstens drei Stu-
denten oder Studentinnen, die im SS 2017 an der Lehrveranstaltung Praxis der Programmierung teil-
nehmen. In diesem Team muss später auch die zweite Hausaufgabe erledigt werden.
Geben Sie die Lösung zu dieser Hausaufgabe Nr. 1 bis zum Sonntag, dem 28. Mai 2017,
23.59 Uhr ab.
Und hier kommen die Aufgaben:
1. Schreiben Sie ein C-Programm liste.c, das eine einfach verkettete Liste ganzer Zahlen
implementiert. Definieren Sie dazu die Datentypen listenelement und list sowie die
Funktionen
(a) void insert(int v, list * l)
(b) int delete head(list * l)
(c) void delete all(list l)
(d) int length(list l)
(e) void print list(list l)
wie in der Vorlesung vom 19. Mai 2017 (v05.pdf).
2. Fügen Sie eine Funktion int insert pos(int v, int pos, list * l) hinzu, die ein
neues Listenelement mit dem Wert v an der Position pos in die Liste l einfügt (also so,
dass es in der neuen Liste die Position pos hat). Die Position des Head-Elements einer
Liste ist immer 0.
Falls pos keine Position in der neuen Liste sein kann, dann gibt die Funktion -1 zurück,
sonst 0.
3. Fügen Sie eine Funktion int delete elem(int e, list * l) hinzu, die alle Vorkom-
men eines Elements e aus Liste l löscht und den Fehlerstatus wie bei delete head
zurückgibt.
4. Fügen Sie eine Funktion void sort(int m, list * l) hinzu, die die Liste l nach
dem Verfahren insertionSort (Sortieren durch Einfügen) sortiert. Dabei gilt: Ist der
Parameter m negativ, soll absteigend sortiert werden, sonst aufsteigend. Das Verfahren
insertionSort wurde in Algorithmen und Datenstrukturen besprochen. Falls es Ihnen
unbekannt ist, nehmen Sie Literatur oder Tutorials im WWW zu Hilfe.
5. Definieren Sie in der main-Funktion eine Liste vom oben genannten Typ list z.B. mit
drei Elementen und testen Sie Ihre Implementierung (alle Funktionen). Nennen Sie das
ausführbare Programm liste.
Kommentieren Sie Ihr Programm in geeigneter Weise.
Ihr C-Programm muss im Computerpool im Haus 4 (0.02/03) ausführbar sein. Der Kommentarblock
am Anfang jedes Quellcodes muss (bei allen Hausafgaben) noch einmal die Namen und Matrikelnum-
mern der Teammitglieder enthalten.
