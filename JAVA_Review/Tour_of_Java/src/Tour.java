import java.util.ArrayList;
import java.util.*;

interface Container
{
	double elementAt(int i);
	void set(int i, double e);
	int size();
}

class ArrayListContainer implements Container
{
	private ArrayList<Double> list;
	
	public ArrayListContainer(int s)
	{
		list = new ArrayList<>(s);
		for (int i = 0; i < s; i++)
		{
			list.add(0.0);
		}
	}
	
	public double elementAt(int i)
	{
		return list.get(i);
	}
	
	public void set(int i, double e)
	{
		list.add(i, e);
	}
	
	public int size()
	{
		return list.size();
	}
	
}

class NodeGeneric<T>
{
	private T t;
	public NodeGeneric(T t_)
	{
		t = t_;
	}
	public void set(T t)
	{
		this.t = t;
	}
	public T get()
	{
		return t;
	}
}

class Movie
{
	String name;
}
class Genre extends Node<String> implements Comparable<Genre>
{
	String name;
	LinkedList<Movie> movieList;
	
	@Override
	public int compareTo(Genre other)
	{
		throw new UnsupportedOperationException();
	}
}
class Node<T>
{
	T obj;
	Node<T> next;
}
class LinkedList<T>
{
	Node<T> head;
}

interface Pair<K, V>
{
	public K getKey();
	public V getValue();
}

class MyPair<K, V> implements Pair<K, V>
{
	private K key;
	private V value;
	public MyPair(K key, V value)
	{
		this.key = key;
		this.value = value;
	}
	public K getKey()
	{
		return key;
	}
	public V getValue()
	{
		return value;
	}
}

public class Tour {

	static void use(Container c)
	{
		final int sz = c.size();
		for (int i = 0; i < sz; i++)
		{
			System.out.println(c.elementAt(i));
		}
	}
	
	public static void main(String[] args) {

		ArrayListContainer a = new ArrayListContainer(10);
		
		
		System.out.println(a.elementAt(0));

		Pair<String, Integer> p1 = new MyPair<String, Integer>("Dice", 6);
		Pair<String, String> p2 = new MyPair<>("Hello", "World");
		Pair<String, NodeGeneric<Integer>> p = 
				new MyPair<>("Data", new NodeGeneric<Integer>(10));
		
		
		
		
	}

}
