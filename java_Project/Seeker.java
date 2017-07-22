/** Seeker.java
* implementiert eine visitor-version, die nach bestimmten Knoten sucht
*'''''NAMEN'''''
**/


public class Seeker<T> implements Visitor<T>{
    
    private Node<T> target;
    private int found;  //== 0 if not found !=0 if found

    public Seeker(){ this.found=0;}
    
    public Seeker(Node<T> toSeek){
        
            this();
            this.target = toSeek;
    
    }

    public void reset(){ this.found=0;}
    
    public int getReport(){ return found; }

    public <T> void process(Node<T> knoten){
        
            if (knoten == target){
            
                this.found =1;
            
            }
            
        } 



}