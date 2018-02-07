package Project1
public class List{
    private Node back = null;
	private Node front = null;
    private int length = 1;
	
    
    public List(){
		this.item = 0;
		this.back = null;
		this.front = null;
		length = 0;
    }
	
    public void InsertBefore(int data){
		if(!this.isEmpty){
		Node nNode = new Node(data);
		else
			Node nNode = new Node(data);
		temp = this.front;
		this.front.setNode(nNode(data));
		this.front = nNode;
		this.front.front = this;
		this.front.back = temp;
		this.length++;
		}
    }
	
	public void InsertAfter(int data){
		if(!this.isEmpty){
		Node nNode;
		temp = this.back;
		this.back.setNode(nNode(data));
		this.back = nNode;
		this.back.front = this;
		this.back.back = temp;
		this.length++;
		
		
		}
		
	}
	
	public void prepend(int data){
		if(!front.isEmpty){
		prepend(int data);
		}
		else
			
	}
	
	
	
	public int front(){
		if (length > 0 && !this.front.isEmpty)
			return front.item;
		else
			return -1;
	}
	public int back(){
		if(length > 0 && !this.back.isEmpty)
			return back.item;
		else
			return -1;
	
	}
	
	public boolean equals(List L){
		if(this.body == L.body)
			return true;
		else 
			return false;
	
	}
	public void clear(){
	this.back = null;
	this.front = null;
	this.item = 0;
	}
	
    public Node peek(){
        return this.body;
    }
    public void dequeue(){
        this.body = this.body.getnNode();
        this.length --;
    }
    public boolean isEmpty(){
        return this.body == null;
    }
    public int length(){
        return this.length;
    }
    
    public Node getbody(){
        return this.body;
    }
    public Node getback(){
        return this.back;
    }
}


}

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}