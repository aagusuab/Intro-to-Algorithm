public class Queue {
    private Node head = null;
    private Node tail = null;
    private int length = 1;
    
    public Queue(){
    }
    public Queue(Node nNode){
        this.head = nNode;
        this.tail = nNode;
        this.head.setNode(this.tail);
    }
    public void enqueue(Node nNode){
        this.tail.setNode(nNode);
        this.tail = nNode;
        this.length++;
    }
    public Node peek(){
        return this.head;
    }
    public void dequeue(){
        this.head = this.head.getnNode();
        this.length --;
    }
    public boolean isEmpty(){
        return this.head == null;
    }
    public int length(){
        return this.length;
    }
    
    public Node getHead(){
        return this.head;
    }
    public Node getTail(){
        return this.tail;
    }
}


}
























}