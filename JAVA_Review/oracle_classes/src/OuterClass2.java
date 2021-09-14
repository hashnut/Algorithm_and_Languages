
public class OuterClass2 
{

	String outerField = "Outer field";
	static String staticOuterField = "Static outer field";
	
	class InnerClass
	{
		void accessMembers()
		{
			System.out.println(outerField);
			System.out.println(staticOuterField);
		}
	}
	
	static class StaticNestedClass
	{
		void accessMembers(OuterClass2 outer)
		{
			// Compile error : cannot make a static reference
			// to the non-static field outerField
			//System.out.println(outerField);
			System.out.println(outer.outerField);
			System.out.println(staticOuterField);			
		}

	}
	
	public static void main(String[] args)
	{
		System.out.println("Inner class:");
		System.out.println("------------");
		OuterClass2 outerObject = new OuterClass2();
		OuterClass2.InnerClass innerObject = outerObject.new InnerClass();
		innerObject.accessMembers();
		
		System.out.println("\nStatic nested class:");
		System.out.println("----------------------");
		StaticNestedClass staticNestedObject = new StaticNestedClass();
		staticNestedObject.accessMembers(outerObject);
		
		System.out.println("\nTop-level class:");
		System.out.println("------------------");
		TopLevelClass topLevelObject = new TopLevelClass();
		topLevelObject.accessMembers(outerObject);
		
	}
}
