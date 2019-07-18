# Difference between references and pointers 
There are three critical attributes of pointers that differentiate them
from references.

1. You use pointer syntax to access the values "pointed to" by the pointer.
2. You can redirect the pointer to point it to a different "target" variable.
3. You can make a pointer point to nothing (ie, NULL pointer).


#  References have a couple of key characteristics that differentiate them from pointers:

1. References must be initialized at the point of instantiation.
2. References must ALWAYS "refer to" a named or unnamed variable
(that is, you cannot have a reference variable that refers to
nothing, the equivalent of a NULL pointer).
3. Once a reference is set to refer to a particular variable, you
cannot, during its lifetime, "rebind" it to refer to a different
variable.
4. You use normal "value" syntax to access the value being referred to.



# to summarize:

1. Pass by value when the function does not want to modify the parameter and the
value is easy to copy (ints, doubles, char, bool, etc... simple types. std::string,
std::vector, and all other STL containers are NOT simple types.)

2. Pass by const pointer when the value is expensive to copy AND the function does
not want to modify the value pointed to AND NULL is a valid, expected value that
the function handles.

3. Pass by non-const pointer when the value is expensive to copy AND the function
wants to modify the value pointed to AND NULL is a vlaid, expected value that the
function handles.

4. Pass by const reference when the value is expensive to copy AND the function does
not want to modify the value referred to AND NULL would not be a valid value if 
a pointer was used instead.

5. Pass by non-cont reference when the value is expensive to copy AND the function wants
to modify the value referred to AND NULL would not be a valid value if a pointer was used 
instead.

6. When writing template functions, there isn't a clear-cut answer because there are a few
tradeoffs to consider that are beyond the scope of this discussion, but suffice it to say that
most template functions take their parameters by value or (const) reference, however
because iterator syntax is similar to that of pointers (asterisk to "dereference"), any
template function that expects iterators as arguments will also by default accept pointers
as well (and not check for NULL since the NULL iterator concept has a different syntax).

# Void pointer
The void type of pointer is a special type of pointer. In C++, void represents the absence of type. Therefore, void pointers are pointers that point to a value that has no type (and thus also an undetermined length and undetermined dereferencing properties).

This gives void pointers a great flexibility, by being able to point to any data type, from an integer value or a float to a string of characters. In exchange, they have a great limitation: the data pointed to by them cannot be directly dereferenced (which is logical, since we have no type to dereference to), and for that reason, any address in a void pointer needs to be transformed into some other pointer type that points to a concrete data type before being dereferenced.

