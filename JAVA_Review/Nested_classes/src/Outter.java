
public class Outter {
	String field = "Outter-field";
	
	void method()
	{
		System.out.println("Outter-method");
	}
	
	class Nested
	{
		String field = "Nested-field";
		void method()
		{
			System.out.println("Nested-method");
		}
		
		void print()
		{
			System.out.println(this.field);
			this.method(); // ÁßÃ¸ °´Ã¼ ÂüÁ¶
			System.out.println(Outter.this.field);
			Outter.this.method(); // ¹Ù±ù °´Ã¼ ÂüÁ¶
		}
	}
}
