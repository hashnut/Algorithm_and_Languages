class A_1
{
	int field1;
	
	void method1() { ... }
	
	static int field2;
	static void method2() { ... }
	
	static class C
	{
		void method()
		{
			field1 = 10; // error
			method1(); // error
			
			field2 = 10;
			method2();
		}
	}
}


public class A {

	
	
	
	
}
