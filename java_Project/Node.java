/** Node.java
* Klasse eines Knoten im Netzwerk
*
* Teil der HA von ####NAMEN####
**/


import java.util.*;


public class Node<T>{
    
    private String name;
    private T value;
    public ArrayList<Node> adjList;  //public ???
    

   public Node(){
       
        this.adjList = new ArrayList<Node>(0); // Standard-Konstr. der ArraList initialisieert mit der größe 10, desshalb mit 0 angegeben
        this.name = "unnamed";
        
       
    }
   
   
   public Node(String iniName){

        this();
        this.name = iniName;
    
    }
    
    public Node(String iniName , T iniValue){
    
        this(iniName);
        this.value = iniValue;
        
    
    }

    public String getName(){return this.name;}
    
    public T getVal(){return this.value;}

    public void setVal( T givenVal ){ this.value = givenVal; }
    
    public <S> void connect(Node<S> target){   
        
        
        //is target alrdy in adjList??:
        if (adjList.contains(target)) { return; }
        
        //else:
        this.adjList.add(target);
        target.connect(this); //da der graph ungerichtet ist muss die target-adjList auch ein update erfahren
    
    }
    public <S> void disconnect(Node<S> target){
        
        if ( ! adjList.contains(target)) { return; } //returns if target not in list
        
        this.adjList.remove(target);
        target.disconnect(this);  // update targets adjList
         
    }
    
    public  void visitAll(Visitor v){   //THIS ebnfalls "besuchen???"
    
        ArrayList<Node> markinList = new ArrayList<Node>();
        markinList.add(this);
        
        LinkedList<Node> processQ = new LinkedList<Node>();
        processQ.addAll(this.adjList);  // da noch kein Knoten besucht wurde können alle adj. knoten in die Q gepackt werdfen
        
        Node dummy;
        
        while( ! processQ.isEmpty()){    
            
            dummy = processQ.remove();
            markinList.add(dummy);
            v.process(dummy);    // führe je nach art des vis. process durch, , in processQ sind nur unbesuchte Knoten
            
            @SuppressWarnings("unchecked")//LOL no more warnings xD
            Iterator<Node> i =  dummy.adjList.iterator();    //!!! Diese Zeile benötigt ein zugängliches adjList
            
            while (i.hasNext()){
            
                Node n = i.next();
                if ( ! markinList.contains(n)) {processQ.add(n);} //quadratischer Aufwand, evtl mit hashing performence verbessern...
            
            }
           
        }
        if ( v instanceof Counter ) {System.out.println(((Counter)v).getCount());}
    }
    
    
    
}