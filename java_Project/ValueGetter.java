/** ValueGetter.java
* implementiert eine visitor-version, die Knotenwerte ausgibt
*'''''NAMEN'''''
**/


public class ValueGetter<T> implements Visitor<Node<T>>{

    public  void process(Node<T> knoten){
        
            System.out.println(knoten.getVal());
        
        } 


}