/** ValueGetter.java
* implementiert eine visitor-version, die Knotenwerte ausgibt
*'''''NAMEN'''''
**/


public class ValueGetter implements Visitor{

    public  void process(Node knoten){
        
            System.out.println(knoten.getVal());
        
        } 


}