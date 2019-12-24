https://jingyan.baidu.com/album/425e69e6f2009cbe15fc161a.html?picindex=1


Summary from answers and links below:

A pointer can be re-assigned any number of times while a reference cannot be re-assigned after binding.
Pointers can point nowhere (NULL), whereas a reference always refers to an object.
You can't take the address of a reference like you can with pointers.
There's no "reference arithmetic" (but you can take the address of an object pointed by a reference and do pointer arithmetic on it as in &obj + 5).
To clarify a misconception:

The C++ standard is very careful to avoid dictating how a compiler may implement references, but every C++ compiler implements references as pointers. That is, a declaration such as:

int &ri = i;
if it's not optimized away entirely, allocates the same amount of storage as a pointer, and places the address of i into that storage.

So, a pointer and a reference both use the same amount of memory.

As a general rule,

Use references in function parameters and return types to provide useful and self-documenting interfaces.
Use pointers for implementing algorithms and data structures.
