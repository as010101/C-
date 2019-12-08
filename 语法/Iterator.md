Iterator有五个类型  categlory_type  difference_type   value_type   pointer_type  reference_type

为兼容原生指针，设计了iterator_traits,形式如下

template <class T>

struct Iterator_traits{...}

template <class T>

struct Iterator_traits<const T*>{...}

template <class T>

struct Iterator_traits<T*>{...}

还有其他traits(type_traits pointer_traits character_traits)



#include <iterator>     ///使用各类迭代器的时候要包含此文件
  
  三类迭代器适配器，就像容器适配器一样  back_inserter  front_inserter插入首元素之前    inserter 插入指定元素之前
