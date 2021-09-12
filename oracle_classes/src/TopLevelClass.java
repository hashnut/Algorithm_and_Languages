
public class TopLevelClass {
	void accessMembers(OuterClass2 outer)
	{
		//System.out.println(OuterClass2.outerField);
		System.out.println(outer.outerField);
		System.out.println(OuterClass2.staticOuterField);
	}
}
