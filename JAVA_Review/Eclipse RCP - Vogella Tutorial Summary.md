# Eclipse RCP - Vogella Tutorial Summary



# 10. The Eclipse Context

#### 10.1 What is the Eclipse Context?

During startup, the Eclipse runtime creates an object based on the `IEclipseContext` interface. This object is called the *context* or the *Eclipse context*. 

The context is similiar to a `Map`, since it has keys and corresponding values. But it is different from map, because it has hierarchy.

![Sample Context Hierarchy](https://www.vogella.com/tutorials/EclipseRCP/img/contexthierarchy03.png)

Objects can be placed at different levels in the context hierarchy. This allows that the same key points to differenct objects in the hierarchy.

#### 10.2 Which model elements have a local context?

Following model elements implement the `MContext` interface and therefore have their own context : 
- MApplication
- MWindow
- MPerspective
- MPart
- MPopupMenu

#### 10.3 Life cycle of the Eclipse context

The model objects and the created objects based on the *class URI* attributes are created by the Eclipse platform. For each model element with a custom context the Eclipse framework determines which objects should be available in the local context of the model object. If required, it also creates the required Java objects referred by the *Class URI* property of the model elements.

Once the application is stopped, the context gets destroyed.

#### 10.4 How are objects selected for dependency injection

Objects created by Eclipse can use annotations to describe its class dependencies.

During dependency injection, the Eclipse framework searches for a fitting object with the key, starting from the local context associated with the application model object. Ir the key is not available, Eclipse continues to search in the parent context. This process continues until the main context has been reached.

![Eclipse context hierarchy](https://www.vogella.com/tutorials/EclipseRCP/img/contexthierarchy10.png)

#### 10.5 How to access the model objects?

For the class references in the application model, the Eclipse framework creates the corresponding objects when needed.

For example, in the implementation of a part you can access the model information of a part via : `@Inject MPart part;`

#### 10.6 Default entries in the Eclipse context

The Eclipse framework creates several objects in the context.

- model objects : contain the data of the application model
- services : software components which are defined by the Eclipse platform or via the OSGi service registry
- several other objects which have explicitly been added to the context

#### 10.7 Qualifiers for accessing the active part of shell

The Eclipse platform places the part which is currently selected and the active shell into the `IEclipseContext` of the application object. The related keys are defined in the `IServiceConstants` interface.

Eclipse uses handlers to define actions which can be triggered via menu or toolbar entries. For a handler implementation class it is not necessary to use these qualifiers, as a handler is executed in the active context of the application.

#### 10.8 Tracking a child context with @Active

The `@Active` annotation allows you to track values in a child context.

For example : 

```
public class MyOwnClass {
    @Inject
    void setChildValue(
            @Optional @Named("key_of_child_value") @Active String value) {
        this.childValue = value;
    }
}
```


# Using annotations to define behavior

#### 11.1 API definition in a framework

Framework = library + rules

#### 11.2 PI definition via inheritance

The "traditional" way of defining an API is via inheritance.

The framework defines, for example, an abstract class which defines methods to be implemented.

In the example of the toolbar button the method might be called `execute()` and the framework knows that this method must be called once the button is clicked. 

API definition via inheritance is a simple way to define an API, but it also couples the classes tightly to the framework. Therefore, the Eclipse 4.x does not use this approah anymore

#### 11.3 API definition via annotations

The Eclipse 4.x platform API is based on annotations, e.g., annotations are used to identify which methods should be called at a certain point in time. These annotations are called behavior annotations.

[Eclipse life cycle annotations for parts]()

Behavior annotations imply that the framework needs to provide the specified parameters to the method, i.e., the framework also performs method dependency injection. If you also add the`@Inject` annotation, the method is called twice, first during the dependency injection phase and later for the behavior annotation. This is typically undesired and therefore an error.

#### 11.4 Use the @PostConstruct method to build the user interface

It is recommeneded to construct the user interface of a part in a method annotated with the `@PostConstruct` annotation. It would also be possible to create the user interface in the constructor, but this is not recommended as field and method injection have not been done at this point.

-> 그러니까 생성자에서 User Interface 만들지 말고, field와 method injection이 완료된 후에 `@PostConstruct` 마킹이 된 메소드를 사용해서 User Interface를 만들라는 뜻.

Creating the user interface in an `@PostConstruct` method requires that `@Inject` methods are aware that the user Interface might not have been created yet.



# 13. Menu and toolbar application objects

#### 13.1 Adding menu and toolbar entries

You can add menus and toolbars. `Handler class` is a class which is responsible for the execution(e.g. select menu or toolbar)

#### 13.2 The usage of commands and handlers

The Eclipse application model allows you to specify `commands` and `handlers`.

A command is a declarative description of an abstract action which can be performed, for example, `save`, `edit`, or `copy`.

A command is independent from its implementation details. The Eclipse framework does not provide standard commands, e.g., you have to create all required commands in your application model.

The behavior of a command is defined via a handler. A handler model element points to a class (handler class) via the `contributionURI` property of the handler. This attribute is displayed as *Class URI* in the model editor.

Commands are used by the *Handled Menuitem* and *Handled ToolItem* model elements.

Prefer the usage of commands over the usage of direct (menu or tool) items. Using commands together with handlers allows you to define different handlers for different scopes(application or part) and you can define key bindings for the handler's associated commands.

#### 13.3 Behavior annotations and dependency injection for handler classes

In a handler class exactly one method must be annotated with the `@Execute` annotation. In additional, you can also annotate one method with the `@CanExecute` annotation. If you annotate more than one method with the same annotation, the framework calls only one of them. The Eclipse runtime uses dependency injection to provide the parameters of the method. The purpose of these annotations are described in the following table.

- @Execute : Marks the method which is responsible for the action of the handler class
- @CanExecute : Marks a method to be visited by the Eclipse framework to check if the handler class can be executed

```
package com.vogella.tasks.ui.handlers;

// import statements cut out
// ..

public class ExitHandler {
    @Execute
    public void execute(IWorkbench workbench) {
        workbench.close();
    }

    // NOT REQUIRED IN THIS EXAMPLE
    // just to demonstrates the usage of
    // the annotation
    @CanExecute
    public boolean canExecute() {
        return true;
    }

}
```

A handler instance does not have its own Eclipse context(`IEclipseContext`). It is executed with the Eclipse context of the active model element which has a Eclipse context. In most common cases this it the context of the active part.

All required parameters should be injected into the method annotated with `@Execute`, as you want the handler class to retrieve its runtime information during execution.

#### 13.4 Determining the relevant handler for a command

If a command is selected, the runtime determines the relevant handler for the command. The application model allows you to create a handler for the application, a window and a part.

Each command can have only one valid handler for a given scope. The Eclipse framework selects the handler most specific to the model element.

#### 13.5 Evaluation of @CanExecute

A method annotated with `@CanExecute` is called by the framework, if a change in the Eclipse context happens. For example, if you select a new part. If the method returns `false`, the framework disables any menu and tool items that point to that command.

You can request the re-evaluation of the `@CanExecute` methods by sending out an event via the event broker.

```
// evaluate all @CanExecute methods
eventBroker.post(UIEvents.REQUEST_ENABLEMENT_UPDATE_TOPIC, UIEvents.ALL_ELEMENT_ID);

// evaluate a context via a selector
Selector s = (a selector that an MApplicationElement or an ID);
eventBroker.post(UIEvents.REQUEST_ENABLEMENT_UPDATE_TOPIC, s);


//See  https://bugs.eclipse.org/bugs/show_bug.cgi?id=427465 for details
```

#### 13.6 Mnemonics

The application model allows you to define *mnemonics*. A mnemonic appears as an underlined letter in the menu when the user presses and holds the `ALT` key and allows the user to quickly access menu entries by keyboard.

You specify mnemonics by prefixing the letter intended to be the mnemonic with an ampersand(`&`) in the label definition. For example, if you use the label *&Save*, the S will be underlined if the `ALT` key is pressed.

#### 13.7 Naming schema for command and handler IDs

A good convention is to start IDs with the *top level package name* of your project and to use only lower case letters.

The IDs of commands and handlers should reflect their relationship. For example, if you implement a command with the `com.example.contacts.commands.show` ID, you should use `com.example.contacts.handler.show` as the ID for the handler. If you have more than one handler for one command, add another suffix to it, describing its purpose, e.g., `com.example.contacts.handler.show.details`.

In case you implement commonly used functions in your RCP application, e.g., save, copy, you should use the existing platform IDs, as some Eclipse contributions expect these IDs to better integrate with the OS. A more complete list of command IDs is available in `org.eclipse.ui.IWorkbenchCommandConstants`.

