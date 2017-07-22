/** Visitor.java 
* Interface zum traverxieren eines Netzwerkes
*
* #####NAMEN#####
**/

public interface Visitor<T>{
    
    public <T> void process(Node<T> knoten);


}