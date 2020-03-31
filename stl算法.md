

`for_each` <br>
对容器元素进行操作，传入的算法对象的参数应该以引用方式传递

`transform` <br>
不直接对容器元素进行操作，传入的算法对象的参数可以以值方式传递，可以将结果值赋值给原元素

`unique` <br>
移除毗邻的重复元素(元素值相等者)注意在使用unique之前需要对元素排序

`sort` <br>
底层采用quicksort

`partial_sort` <br>
底层采用heapsort,任何情况下保证nlogn的时间复杂度

`stable_sort` <br>
底层采用mergesort,内存充足nlogn的时间复杂度，否则n*logn*logn,保证相等元素相对秩序不变

`find` <br>
查询某元素是否在容器中，返回一个迭代器







