/** UseNode.java
* Testumgebung für Node.class
*
**/


public class UseNode{
    
    
    public static void main(String[] args){
    
    
    
        Node<Integer> A = new Node<Integer>("A",3);
        Node<Integer> B = new Node<Integer>("B",8);
        Node<Integer> C = new Node<Integer>("C",5);
        Node<Integer> D = new Node<Integer>("D",1);
        Node<Integer> E = new Node<Integer>("E",8);
        Node<Integer> F = new Node<Integer>("F",17);
        Node<Integer> G = new Node<Integer>("G",9);
    
        A.connect(F);
        A.connect(G);
        
        B.connect(F);
        B.connect(G);
        
        C.connect(D);
        C.connect(F);
        
        D.connect(E);
        
        F.connect(G);
      
    
        
        Printer p = new Printer();
        ValueGetter v = new ValueGetter();
        Counter c = new Counter();
        
      
        G.visitAll(p);
        F.visitAll(v);
        F.visitAll(c);
        System.out.println("G --- B : " + G.isConnected(B));
        System.out.println("G --- D : " + G.isConnected(D));
        
        
        
        
        
        
        
        
        
    }
}