# Eclipse RCP based on the 3.x API

## 1. Extending the Eclipse IDE

- *plug-ins* : An Eclipse application consists of individual software components

## 3. What are Extension Points?

Extension-points define interfaces for other plug-ins to contribute functionality (code and non-code)

They are defined in the *plugin.xml* file, which must be in the root directory of your plug-in project. Existing extensions(contributions) are collected during the start of an Eclipse application

## 4. Main components of an Eclipse RCP application

The Minimal required plug-ins to create and run an minimal Eclipse RCP application(with UI)
	- "org.eclipse.core.runtime"
	- "org.eclipse.ui"

Main program - A RCP main application class implements the interface "IApplication". Eclipse expects that the application class is defined via the extension point "org.eclipse.core.runtime.application"

A Perspective - defines the layout of your application. Must be declared via the extension point "org.eclipse.ui.perspective"

Workbench Advisor - invisible technical component which controls the appearance of the application (menus, toolbars, perspectives, etc)

## 5. Approach

First, just jump in and learn. Read the chapter about launch configurations and check the "Products and Branding" chapter

## 6. Application and Advisor Classes

Class defined via the `org.eclipse.core.runtime.application` extension point is reponsible for creating the SWT `Display` and for starting the event loop for the application.

```
Display display = PlatformUI.createDisplay();
PlatformUI.createAndRunWorkbench(display, new ApplicationWorkbenchAdvisor());
```

`PlatformUI.createAndRunWorkbench()` creates and runs a `Workbench`. The `Workbench` represents the GUI of Eclipse. The visual part of the Workbench is represented via the `WorkbenchWindow` class. A `Workbench` can have several `WorkbenchWindows` opened. The inner part of the `WorkbenchWindow` is represented via the class `WorkbenchPage`.

The `Workbench` is configured via a class of type `WorkbenchAdvisor`. This class defines the initial Perspective and defines the `WorkbenchWindowAdvisor` class.

`WorkbenchWindowAdvisor` calls the class `ActionBarAdvisor` which configures `Actions` for the `Workbench` and defines initial attribute for the `WorkbenchWindow` as initial size, title and visibility of the statusline.


```
public ActionBarAdvisor createActionBarAdvisor(IActionBarConfigurer configurer) {
    return new ApplicationActionBarAdvisor(configurer);
}

public void preWindowOpen() {
    IWorkbenchWindowConfigurer configurer = getWindowConfigurer();
    configurer.setInitialSize(new Point(400, 300));
    configurer.setShowCoolBar(false);
    configurer.setShowStatusLine(false);
    configurer.setTitle("Todo"); //$NON-NLS-1$
}
```

You could set the inittial position of the application via `postwindowCreate()` method.

```
// for further info see https://bugs.eclipse.org/bugs/show_bug.cgi?id=84938
@Override
public void postWindowCreate() {
    Shell shell = getWindowConfigurer().getWindow().getShell();
    shell.setLocation(100, 400);
    super.postWindowCreate();
}
```

## 7. WorkbenchParts and Perspectives

#### 7.1 WorkbenchParts - Views and Editors

WorkbenchWindow
	- WorkbenPage (GUI)
		- Parts (Views / Editors)

Views and Editors extend `WorkbenchPart`.

Views : Display information in an RCP application. Used to change data. Extends the abstract class `Viewpart`
Editors : Extends the abstract `Editorpart`.

*Views* and *Editors* are defined via extension points in the file *plugin.xml* via the tab "Extensions".

*Views* are defined via the extension point "org.eclipse.ui.views" and *Editors* via the extension point "org.eclipse.ui.editors".

*Views* must implement the `createPartControl()` and `setFocus()` methods.

`createPartControl()` is used to create the UI components of the `View`.

`createPartControl()` will get as parameter a `Composite` which can be used to construct the user interface. This composite has by default a `FillLayout` layout manager assigned to it. This layout manager assigns the same space to all components equally.

`setFocus()` must set the focus to a specific UI component.

#### 7.2 Perspective

A `Perspective` describes a certain configuration of `Views` and `Editors`.

A `Perspective` is defined via "org.eclipse.ui.perspectives". The `WorkbenchParts` which are part of a `Perspective` are either defined via a Java class defined in the extension point "org.eclipse.ui.perspectives" or via the "org.celipse.ui.perspectiveExtensions"

```
public class Perspective implements IPerspectiveFactory {
    public void createInitialLayout(IPageLayout layout) {
        layout.addView("de.vogella.rcp.intro.first.MyView", IPageLayout.TOP,
                IPageLayout.RATIO_MAX, IPageLayout.ID_EDITOR_AREA);
    }
}
```

`layout.addView()` adds a view to the perspective.

You can also add placeholders for views via the `layout.addPlaceholder()` method call. This methods accepts wildcards and a `View` with a matching ID would open in this area. For exmaple if you want to open all views in a specific place you could use the `layout.addPlaceholder("*", ...)` method call, or

`layout.addPlaceholder("view_id",...)` to open a View with the "view_id" ID in this placeholder.

You can also group view via a `IFolderLayout` which can be created via `layout.createFolder()` call and by adding `Views` to this folder via the `addView(id)` method on `IFolderLayout`.


