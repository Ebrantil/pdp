/** Counter.java
* implementiert eine visitor-version, die knotenanzahl im netzwerk ausgibt
*'''''NAMEN'''''
**/


public class  Counter<T> implements Visitor<Node<T>>{

    private int count;

    public Counter(){ count=0;}

    public void reset(){ count=0;}
    
    public int getCount(){ return count; }

    public  void process(Node<T> knoten){
        
            count++;
        
        } 



}