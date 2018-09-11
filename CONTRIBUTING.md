# Contributing

## C++ Coding Standard

This outlines the most important coding standards that are applicable to GDTEngine. The coding standards are enforced to maintain readability, consistency and easier maintenance.

#### Layout of C++ Classes
All C++ class declarations should follow this basic layout:
```cpp
class CSomeClass
{
// Typedefs, enums and nested classes.
public:
protected:
private:

// Methods, including constructors/destructor and operators.
public:
protected:
private:

// Member variables.
public:
protected:
private:
};
```

#### Documentation
Documentation will be generated through comments in the header files which means it is a part of the coding standard.
```cpp
class CSomeClass
{
public:
    /**
     * Add a quick description. 
     */
    int doSomething(int param1, float param2);       
}
```

#### Newlines
Both .cpp and .hpp files must always end with a newline.

#### Spaces and Tabs
* Tabs are not allowed, always use spaces.
* 4 spaces i equal to 1 level of indentation.

### Naming Conventions

#### General Naming Rules
* Use meaningful names even if they are relatively long.
* Use common one-letter counters for incrementation in loops (i, j, k, x, y, z).
* All names should be in American English.

#### Class Names
The name of a class should be in PascalCase, prefixed with the prefix **'C'**.

```cpp
class CSomeClass
```

#### Interface Names
The name of a interface should be in PascalCase, prefixed with the prefix **'I'**.

```cpp
class ISomeInterface
```

#### Struct Names
The name of a struct should be in PascalCase, prefixed with the prefix **'S'**.

```cpp
struct CSomeStruct
```
