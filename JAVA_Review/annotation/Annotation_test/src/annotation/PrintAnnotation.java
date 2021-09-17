package annotation;

import java.lang.annotation.*;
import java.lang.annotation.Target;
import java.lang.annotation.ElementType;

@Target({ElementType.METHOD}) 
@Retention(RetentionPolicy.RUNTIME) 
public @interface PrintAnnotation 
{
	String value() default "-";
	int number() default 15;
}

