/** UseNode.java
* Testumgebung für Node.class
*
**/


public class UseNode{
    
    
    public static void main(String[] args){
    
    
        Node<Integer> Knoten = new Node<Integer>("string des knotens");  
        
        
        int testVal = 23;
        
        
        Node<Integer> Knoten2 = new Node<Integer>("polunder" , testVal );
        Node<String> Knoten3 = new Node<String>("KNoten3" , "knoten3s string");
        
        
        Node<Integer> Knoten4 = new Node<Integer>("polunder4" , 44 );
        Node<String> Knoten5 = new Node<String>("KNoten5" , "knoten5s string");
        
        
        Knoten.connect(Knoten2);
        Knoten.connect(Knoten3);
        Knoten.connect(Knoten4);
        Knoten.connect(Knoten5);
        
        //System.out.println(Knoten.adjList.get(0).getName());
        //System.out.println(Knoten2.adjList.get(0).getName());
        
        Printer p = new Printer();
        ValueGetter v = new ValueGetter();
        Counter c = new Counter();
        
        Knoten.visitAll(p);
        Knoten.visitAll(v);
        Knoten.visitAll(c);
        
        
        
        
    }
}