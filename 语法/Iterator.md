Iterator有五个类型  categlory_type  difference_type   value_type   pointer_type  reference_type

为兼容原生指针，设计了iterator_traits,形式如下

template <class T>

struct Iterator_traits{...}

template <class T>

struct Iterator_traits<const T*>{...}

template <class T>

struct Iterator_traits<T*>{...}

还有其他traits(type_traits pointer_traits character_traits)