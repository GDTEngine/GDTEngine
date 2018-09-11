# Contributing

## C++ Coding Standard

This outlines the most important coding standards that are applicable to GDTEngine. The coding standards are enforced to maintain readability, consistency and easier maintenance.

#### Layout of a C++ Classes
* Typedef, enums, nested classes, methods are first orderd by access specifiers then alphabetically by the name.
* Member variables are first orderd by access specifiers, then alphabetically by the name of the type, and last alphabetically by the name.

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

#### Documenting
Documentation will be generated through comments in the header files which means it is a part of the coding standard.
* Every class, struct, enum, and member variable with a access specifier of public and protected must be documented.
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
struct SSomeStruct
```

#### Enum Names
The name of a enum should be in PascalCase, prefixed with the prefix **'E'**.
* Enum values should by ordered alphabetically by name if no explicit reason not to do so.
```cpp
enum class EFoodType : uint32_t
{
    Cheese,
    Meatballs,
    Pasta,
};
```

### A Final Note on C++ Coding Standard
There are a lot of rules here and they might fright you a bit. But the reason is to cover as many cases as possible, so think of this a bit of a dictionary.

Finally, if you stumble upon something in the c++ coding standard not specified here, please put out an Epic issue on that so we can addit into this document.
