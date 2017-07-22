/** Counter.java
* implementiert eine visitor-version, die knotenanzahl im netzwerk ausgibt
*'''''NAMEN'''''
**/


public class Counter implements Visitor{

    private int count;

    public Counter(){ count=0;}

    public void reset(){ count=0;}
    
    public int getCount(){ return count; }

    public  void process(Node knoten){
        
            count++;
        
        } 



}