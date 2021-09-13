import java.util.*;

public class Blog {
	
	private int id;
	private String name;
	
	public Blog() {}
	public Blog(int id, String name)
	{
		this.id = id;
		this.name = name;
	}
	
	public int getId()
	{
		return id;
	}
	public void setId(int id)
	{
		this.id = id;
	}
	public String getName()
	{
		return name;
	}
	public void setName(String name)
	{
		this.name = name;
	}
	public void displayInfo()
	{
		System.out.println("학번: " + id);
		System.out.println("이름: " + name);
	}
	public static void display(Blog c)
	{
		c.displayInfo();
	}
	
	@Override
	public String toString()
	{
		return "학번: " + id + "\n" + "이름 : " + name;
	}
	
	static int y = 0;
	public static void main(String[] args)
	{
		
		abstract class A
		{
			public abstract int calc(int x);
		}
		
		A a = new A()
				{
					public int calc(int x) {return x*y;}
					public void print(int x) {System.out.println(calc(x));}
				};
				
		System.out.println(a.calc(2));
		// Below is error. Cannot call method defined in anonymous class
		// a.print(2);
		/*
		System.out.println("HashSet 연습");
		
		HashSet<Blog> hset = new HashSet<Blog>();
		
		Blog bl1 = new Blog(1, "Abc");
		Blog bl2 = new Blog(2, "Def");
		Blog bl3 = new Blog(3, "Asdf");
		hset.add(bl1);
		hset.add(bl2);
		hset.add(bl3);
		
		
		System.out.println();
		System.out.println("Iterator");
		Iterator<Blog> itr = hset.iterator();
		while (itr.hasNext())
		{
			Blog bl = itr.next();
			System.out.println("id : " + bl.getId());
			System.out.println("name : " + bl.getName());
		}
		
		System.out.println();
		System.out.println("enhanced for");
		
		for (Blog b : hset)
		{
			b.displayInfo();
		}
		
		System.out.println();
		System.out.println("forEach() 사용");
		
		hset.forEach(System.out::println);
		hset.forEach(Blog::display);
		*/
	}
}

