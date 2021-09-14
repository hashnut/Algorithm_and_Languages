# JAVA_Review
Review Java with 'Effective Java' and 'Optimizing Java'

Reference : [1. A Tour of Java](https://github.com/hashnut/JAVA_Review/blob/main/java_article_merged.pdf), [2. Oracle Docs](https://docs.oracle.com/javase/tutorial/java/TOC.html), [3. This is JAVA](http://www.yes24.com/Product/Goods/15651484)

## [JAVA Reference type](https://koreanfoodie.me/635)

# Classes

Class contains members and methods.

### Access Levels

- public : Class, Package, SubClass, World
- protected : Class, Package, Subclass
- no modifier : Class, Package
- private : Class

### [static](https://github.com/hashnut/JAVA_Review/blob/main/oracle_classes/src/TopLevelClass.java)

*static* members and methods should be accessed through *class* itself, not instances. (It is unique!) **Class methods cannot directly access to instance variables and methods**

- [Singleton and static block](https://koreanfoodie.me/636)
- [JAVA Package](https://koreanfoodie.me/638)

### [Nested Classes](https://github.com/hashnut/JAVA_Review/blob/main/oracle_classes/src/OuterClass2.java)

Nested class is a member of its enclosing class. Non-static nested classes(inner classes) have access to other members of the enclosing class, even if they are declared private. Static nested classes do not have access to other members of the enclosing class. (Outer classes can only be declared public or package private)

### [Inner Classes](https://github.com/hashnut/JAVA_Review/blob/main/oracle_classes/src/DataStructure.java)

Inner class is associated with an instance, it cannot define any static members itself.

Objects that are instances of an inner class exist within an instance of the outer class.
'''
OuterClass outerObject = new OuterClass();
OuterClass.InnerClass innerObject = outerObject.new InnerClass();
'''

Ref : [Shadowing](https://github.com/hashnut/JAVA_Review/blob/main/oracle_classes/src/ShadowTest.java)

### [Local classes](https://github.com/hashnut/JAVA_Review/blob/main/oracle_classes/src/LocalClassExample.java)

Local classes are classes that are defined in a block. A local class has access to the members of its enclosing class. 

In addition, a local class has access to local variables. Starting in Java SE 8, a local class can access local variables and parameters of the enclosing block that are final or *effectively* final. *Effectively* final means its value is unchanged after initialization.

Local classes are similiar to inner classes([cannot define/declare any static members, except *final*](https://github.com/hashnut/JAVA_Review/blob/main/oracle_classes/src/only_final_in_local_static.java)). [You cannot declare interface inside a block, since interface is inherently static.](https://github.com/hashnut/JAVA_Review/blob/main/oracle_classes/src/interface_static.java)

[**Further readings are uploaded on the blog**](https://iamfoodie.tistory.com/category/Tutorials/Java)



