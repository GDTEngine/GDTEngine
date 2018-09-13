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
     * @breif Add a quick description.
     * @param param1 The first param. 
     * @param param2 The second param.
     * @return Returns some integer.
     *
     * A more detailed description here if needed.
     * Examples can be added.
     * @code{.cpp}
     * void CSomeClass::someMethod()
     * {
     *     // This is some random integer.
     *     int someInt = doSomething(3, 0.5f);
     * }
     * @endcode
     * More comments can be added here, and more examples.
     */
    int doSomething(int param1, float param2);       
}
```

#### Header Files
The header files should follow the below mentioned format:
* Always use *'#pragma once'*, it is supported by all modern compilers.
* Don't use #include guards (#ifndef ... #define ... #endif).
* Avoid having function implementations in header files, prefer headers with declarations only, it allows to have less '#include's in headers.
* Avoid using  #include in a header file that are not required (put all include needed in the .cpp instead).
* Order of includes: Current project headers, other project headers, third party headers. After that, alphabetically by filename/filepath.
* Use forward declarations if applicable to reduce compiletime, excluding third party.

#### Source Files
The source files should follow the below mentioned format:
* Classes should not be split across multiple source files.

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
    Beans,
    Cheese,
    Pasta
};
```

#### Function Name
The name of a function must be in camelCase.

```cpp
// Good!
float getHealth() const;

// Good!
bool isDead() const;

// Good!
void setHealth(float health);

// Bad! Missing verb, not descriptive.
float health() const;

// Bad! Missing auxiliary verb due to return type, not descriptive.
bool dead() const;
```

#### Variable Naming Prefixes
* **m_**: for members with access specifierer of private.
* **s**: for static variables.
* **p**: for pointer-like (raw and smart pointers).
* For booleans use auxiliary verbs such as was, can, is, must and so on.
```cpp
class CSomeClass
{
public:
    // Good! However, in general do not make member variables public.
    int someInteger;
    
    // Bad!
    int m_someInteger;
    
private:
    // Good!
    float m_someFloat;
    
    // Good!
    char* m_pName;
    
    // Bad!
    float someFloat;
    
    // Bad!
    char* m_name;
    
    // Good!
    static char* m_spName;
    
    // Good!
    bool isSwimming;
    
    // Bad!
    bool swimming;
}

void CSomeClass::someMethod()
{
    // Good!
    int someInteger = 3;
    
    // Good!
    void* pSomePointer = nullptr;
}
```

### C++ Class Example

#### Header File
The header file is named **Texture.hpp**.

```cpp
#pragma once

#include "Core/BaseTypes.hpp"

#include <glm.hpp>
#include <string>

namespace Graphics
{
    class CTexture final    // If no virtual desturctor please put final here.
    {
    public:
        class enum EFormat : uint32
        {
            RGB = 3,
            RGBA = 4
        };
        
    public:
        CTexture();
        
        CTexture(const CTexture& other);
        
        CTexture(const CTexture&& other);
                
        ~CTexture();
        
        void operator=(const CTexture& rhs);
        
        EFormat getFormat() const;
        
        void loadFromFile(const std::string& filename, EFormat format);
        
    private:
        EType m_format;
        int32 m_size;
        uchar* m_pTextureData;
    }
}
// Do not forget to put a newline at the end of the file.
```

### Source File
The source file is named **Texture.cpp**.

```cpp
#include "Texture.hpp"

using namespace Graphics;

CTexture::CTexture()
    : m_format(EFormat::RGB)
    , m_size(0)
    , m_pTextureData(nullptr)
{
}

CTexture::CTexture(const CTexture& other)
{
    // Make a deep copy here.
    m_format = other.m_format;
    m_size = other.m_size;
    m_pTextureData = new uchar[m_size * static_cast<int32>(m_format)];
    memcpy(m_pTextureData, other.m_pTextureData, m_size * static_cast<int32>(m_format));
}

CTexture::CTexutre(const CTexture&& other)
{
    m_format = other.m_format;
    m_size = other.m_size,
    m_pTextureData = other.m_pTextureData;
    other.m_size = 0;
    other.m_pTextureData = nullptr;
}

CTexture::~CTexture()
{
    if (m_pTextureData)
    {
        delete[] m_pTextureData;
    }
}

void operator=(const CTexture& rhs)
{
    ...
}

EFormat CTexture::getFormat() const
{
    ...
}

void CTexture::loadFromFile(const std::string& filename, EFormat format)
{
    ...
}
// Do not forget to put a newline at the end of the file.
```

### A Final Note on C++ Coding Standard
If you stumble upon something in the c++ coding standard not specified here, please put out an Epic issue on that so we can add it into this document.
