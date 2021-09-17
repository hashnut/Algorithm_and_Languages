package annotation;

import java.lang.reflect.Method;


public class PrintAnnotationExample
{
	public static void main(String... args)
	{
		// Get Methods from Service Class
		Method[] declaredMethods = Service.class.getDeclaredMethods();

		// Take care of Method Objects, one by one
		for(Method method :declaredMethods)
		{
			// Check if PrintAnnotation is applied
			if (method.isAnnotationPresent(PrintAnnotation.class))
			{

				// Get PrintAnnotation Object
				PrintAnnotation printAnnotation  = method.getAnnotation(PrintAnnotation.class);

				// Print method name
				System.out.println("[" + method.getName() + "] ");

				// Print lines
				for (int i = 0; i < printAnnotation.number(); i++)
				{
					System.out.print(printAnnotation.value());
				}
				System.out.println();

				try
				{
					method.invoke(new Service());
				}
				catch (Exception e) {}
				System.out.println();

			}
		}
	}

}