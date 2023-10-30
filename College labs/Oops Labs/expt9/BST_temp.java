import java.util.Scanner;

class Node {
	int data;
	Node left, right;
	Node(int data)
	{
		this.data = data;
		this.left = null;
		this.right = null;
	}
}

public class BST_temp{
	static Node node;

	public static Node createNode(Node node, int data)
	{
		if (node == null)
		node = new Node(data);

		if (node.data>data)
		node.left = createNode(node.left, data);

        if (node.data<data)
		node.right = createNode(node.right, data);

		return node;
	}

	public static void create(int data)
	{
		node = createNode(node, data);
	}


    public static void deleteNode(int n)
    {
        Node p = findNode(node,n);
		if(p==null) return;

		Node parent = getParentNode(node,p.data);
        
        if(p.left == null && p.right == null)
		{
			if (parent.right.data == p.data)
			{
				parent.right = null;
			}
			else
			{
				parent.left = null;
			}
			return;
		}

		else if(p.left == null)
		{
			if (parent.right.data == p.data)
			{
				parent.right = p.right;
			}
			else
			{
				parent.left = p.right;
			}
			
		}

        else if(p.right == null)
		{
			if (parent.right.data == p.data)
			{
				parent.right = p.left;	
			}
			else
			{
				parent.left = p.left;
			}
		} 

		else {
			
			Node suc;
			suc = successor(p);
			// int a = suc.data;
			// deleteNode(suc.data);
			// p.data = a;
			deleteNode(suc.data);
			p.data = suc.data;
		}


    }
    
    public static Node successor(Node n)
    {
        n=n.right;
        
        while(n.left != null)
        {
            n=n.left;
        }
        return n;
        
    }
    
    public static Node getParentNode(Node n, int a)
    {

		// if(n.right == null && n.left == null) return null;
        // if(n.left.data == a || n.right.data == a) return n;
        
        // else if(n.data < a) return getParentNode(n.right,a);
        
        // else if(n.data > a) return getParentNode(n.left,a);

		if(n == node) return null;

		if(n.right!= null ) if(n.right.data == a) return n;
		if(n.left!= null ) if(n.left.data == a) return n;

		if(n.right !=null && n.data < a) return getParentNode(n.right,a);

		if(n.left !=null && n.data > a) return getParentNode(n.left,a);
        

        return null;
        
    }
    
    
    public static Node findNode(Node n, int a)
    {
        
        if(n.data == a) return n;
        
        else if(n.data < a) return findNode(n.right, a);
        
        else if(n.data > a) return findNode(n.left, a);
        
        if(n.right == null && n.left == null) return null;
        
        return null;
        
    }
    
    static void traverseTree(Node n) 
    {
        if (n != null) 
        {
            traverseTree(n.left);
            System.out.println(n.data);
            traverseTree(n.right);
        }
    }

	public static void main(String[] args)
	{
		int choice;
		Scanner in = new Scanner(System.in);

		while(true)
		{
			System.out.println("Enter your choice:\n1. Insert\n2. Traverse\n3. Delete\n4. Exit");
			choice = in.nextInt();

			if(choice==4) break;

			switch(choice)
			{
				case 1:

					System.out.println("Enter the no of req nodes:");
					int n = in.nextInt();
					int arr[] = new int[n];
			
					System.out.println("Enter the elements");
					for(int i=0;i<n;i++)
					{
						arr[i] = in.nextInt();
						System.out.println(arr[i]+" is inserted in the tree");
						create(arr[i]);
					}
					System.out.println("** BST is "+node);

					break;

				case 2:

					if(node == null)
					{
						System.out.println("Binary Search Tree is Empty");
					}
					else 
					{
						System.out.println("The elements of the Tree in order are:");
						traverseTree(node);
						System.out.println("** BST is "+node);
					}

					break;

				case 3:

					if(node == null)
					{
						System.out.println("Binary Search Tree is Empty");
					}
					else 
					{
						System.out.println("Enter the node to delete:");
						int del = in.nextInt();
						deleteNode(del);
						System.out.println("Node "+del+" deleted from Binary Search Tree");
						System.out.println("** BST is "+node);
					}
				    
					break;

				default:
					System.out.println("Please Enter a valid choice");

			}
		}

		in.close();
	}
}
