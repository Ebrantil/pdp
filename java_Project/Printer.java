/** Printer.java
* implementiert eine visitor-version, die knotennamen ausgibt
*'''''NAMEN'''''
**/


public class Printer implements Visitor{

    public  void process(Node knoten){
        
            System.out.println(knoten.getName());
        
        } 


}