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
	
	static void outMethod(final int arg1, int arg2)
	{
		final int var1 = 1;
		int var2 = 2;
		class LocalClass
		{
			void method()
			{
				int result = arg1 + arg2 + var1 + var2;
			}
		}
	}
	
	// 실제 :
	class LocalClass
	{
		int arg2 = 매개값; // 필드로 복사
		int var2 = 2; // 필드로 복사
		
		void method()
		{
			int arg1 = 매개값; // 로컬 변수로 복사 (final)
			int var1 = 1; // 로컬 변수로 복사 (final)
			int result = arg1 + arg2 + var1 + var2;
		}
	}
	
	
}


public class A {

	interface I
	{
		void method();
	}
	
}
