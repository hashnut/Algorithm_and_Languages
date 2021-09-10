import java.util.ArrayList;

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

public class Tour_of_Java {

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
		
	}

}
