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
