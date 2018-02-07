public class Node{

private String item;
private Node front
private Node back;
private int cursor = 0;

public Node(String newitem){
this.item = newitem;
back = null;
front = null;
cursor = 0;
}

public Node(){
item = null;
back = null;
front = null;
}


public Node getNode(){
return this;
}

public int getItem(){
return this.item;
}

public void setbackNode(Node backNode){
this.back = backNode;
}

public void setfrontNode(Node frontNode){
	this.front = frontNode;
}

public void setItem(String newItems){
this.item = newItems;
}






}




























