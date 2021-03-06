# 第五章 C++与STL入门

3-17
- [x] UVa10474(sort、lower_bound)
- [x] UVa101(vector)

3-18
- [x] UVa10815(set)
- [x] UVa156(vector、set)

3-19
- [x] UVa12096(set、map)

3-21
- [x] UVa540(queue)

3-23
- [x] UVa136

## STL初步

- `vector`
  使用`v.size()`来读取大小，`v.resize()`来改变大小，`v.push_back()`向尾部添加元素，`v.pop_back()`删除最后一个元素。

- `sort()`函数
  可以对任意对象进行排序，不一定是内置类型。类型需要重载`<`运算符。

- `lower_bound()`函数
  查找**大于或者等于**x的第一个位置。

- 集合的交集`set_union()`函数
```cpp
set_union(set1.begin(), set1.end(), set2.begin(), set2.end(),inserter(set3, set3.begin()));
```

- 集合的并集`set_intersection()`函数
```cpp
set<int> set3;
set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(),inserter(set3, set3.begin()));
```