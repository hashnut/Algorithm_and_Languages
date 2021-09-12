import java.util.*;

class FullDeck
{
	private ArrayList<Card> myDeck;
	
	public FullDeck(Card c)
	{
		myDeck.add(c);
	}
	
	public void AddCard(Card c)
	{
		myDeck.add(c);
	}
	
	public void display()
	{
		for (Card c : myDeck)
			c.display();
	}
}



public class ex_classes {

	public static int x = 7;
	public int y = 3;
	
	public static void main(String[] args)
	{
		System.out.println("Hello World");
		
		/*
		 * 	Qusetion Answer : 
		 * 	1. 
		 * 		a. x
		 * 		b. y
		 * 		c . 5 6 2 2 2 
		 * 
		 * 
		 */
	}
}
