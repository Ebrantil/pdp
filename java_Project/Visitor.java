/** Visitor.java 
* Interface zum traverxieren eines Netzwerkes
*
* #####NAMEN#####
**/

public interface Visitor<T>{
    
    public void process(T knoten);


}