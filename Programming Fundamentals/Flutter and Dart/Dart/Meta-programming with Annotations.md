Meta-programming in Dart involves writing code that can manipulate or generate other code at runtime. One of the key features of meta-programming in Dart is the use of annotations. Annotations provide a way to attach metadata to classes, methods, or fields, which can be used by the Dart runtime or other tools to influence behavior or facilitate various operations.

### 1. What Are Annotations?

Annotations are a way to add metadata to Dart code. They can be applied to classes, methods, and fields, and they are defined using the `@` symbol followed by the annotation name.

### 2. Creating Annotations

To create an annotation, you simply define a class. Annotations typically have a constructor to pass parameters.

```dart
class MyAnnotation {
  final String description;

  const MyAnnotation(this.description);
}
```

### 3. Using Annotations

You can apply annotations to classes, methods, and fields using the `@` symbol. Here’s how you can use the `MyAnnotation` class we defined earlier:

#### a. Annotating Classes

```dart
@MyAnnotation('This is a sample class annotation.')
class MyClass {
  // Class implementation
}
```

#### b. Annotating Methods

```dart
class MyClass {
  @MyAnnotation('This is a sample method annotation.')
  void myMethod() {
    // Method implementation
  }
}
```

#### c. Annotating Fields

```dart
class MyClass {
  @MyAnnotation('This is a sample field annotation.')
  String myField;
}
```

### 4. Reflecting on Annotations

To work with annotations at runtime, Dart provides reflection capabilities through the `dart:mirrors` library. However, keep in mind that `dart:mirrors` is not supported in Flutter due to performance concerns. For Flutter, it’s better to use code generation tools like `json_serializable` or `built_value`.

#### a. Using `dart:mirrors`

Here’s an example of how you can use reflection to access annotations in Dart:

```dart
import 'dart:mirrors';

void printAnnotations(Object obj) {
  ClassMirror classMirror = reflectClass(obj.runtimeType);
  classMirror.declarations.forEach((key, value) {
    if (value is MethodMirror) {
      var annotation = value.metadata.firstWhere(
          (meta) => meta.reflectee is MyAnnotation,
          orElse: () => null);
      if (annotation != null) {
        print('Method: ${MirrorSystem.getName(key)} - ${annotation.reflectee.description}');
      }
    }
  });
}
```

### 5. Limitations of Reflection in Flutter

Since `dart:mirrors` is not available in Flutter, you can consider using other packages that provide code generation and annotation processing. For example, you can use:

- **Source_gen**: A library for generating Dart code. It works well with annotations and provides a way to create compile-time code generation based on the metadata.
  
- **Json_serializable**: This package automatically generates serialization code based on annotations you provide in your classes.

### 6. Example: Using Annotations with Code Generation

Let's take an example using the `json_serializable` package, which uses annotations to automate JSON serialization.

1. **Add Dependencies**: In your `pubspec.yaml`, add the following dependencies:

```yaml
dependencies:
  json_annotation: ^4.6.0

dev_dependencies:
  build_runner: ^2.3.0
  json_serializable: ^6.3.0
```

2. **Create a Model with Annotations**:

```dart
import 'package:json_annotation/json_annotation.dart';

part 'user.g.dart'; // Code generation file

@JsonSerializable() // Annotation to indicate that this class is serializable
class User {
  final String name;
  final int age;

  User(this.name, this.age);

  // Factory constructor for creating a new User instance
  factory User.fromJson(Map<String, dynamic> json) => _$UserFromJson(json);

  // Method to convert User instance to JSON
  Map<String, dynamic> toJson() => _$UserToJson(this);
}
```

3. **Generate Code**:

Run the following command to generate the JSON serialization code:

```bash
flutter pub run build_runner build
```

This will create a file called `user.g.dart` that contains the serialization logic based on the annotations.

### 7. Conclusion

Meta-programming with annotations in Dart allows you to add meaningful metadata to your code and utilize it to generate code or alter behavior at runtime. While reflection through `dart:mirrors` is limited in Flutter, using code generation libraries such as `json_serializable` can provide similar functionality without performance drawbacks. Understanding and leveraging annotations can significantly improve the efficiency and maintainability of your Dart and Flutter applications.
