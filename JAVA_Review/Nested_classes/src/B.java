public class B
{
	void method1(Parent parent) {}
	void method2()
	{
		method1(
			
			new Parent()
		    {
		    	int childField;
		        void childMethod() {}
		        @Override
		        void parentMethod() {}
		    }
		);
		
	}
 
	Parent field = new Parent()
    {
    	int childField;
        void childMethod() {}
        @Override
        void parentMethod() {}
    };
    
    void method()
    {
    	field.childField = 3; // 부모 타입에 선언되지 않아 사용 불가
    	field.childMethod(); // 부모 타입에 선언되지 않아 사용 불가
    	field.parentMethod(); // 부모 타입에 선언되어 사용 가능!
    }
}