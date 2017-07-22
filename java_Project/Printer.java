/** Printer.java
* implementiert eine visitor-version, die knotennamen ausgibt
*'''''NAMEN'''''
**/


public class Printer<T> implements Visitor<Node<T>>{

    public void process(Node<T> knoten){
        
            System.out.println(knoten.getName());
        
        } 


}