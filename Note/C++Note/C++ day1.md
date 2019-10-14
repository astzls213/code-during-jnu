# C++ day1

#### 1.typedef后的注意事项

​	来自C++ Primer第61页：

​		`typedef char * ptrString`后，声明`const ptrString str`是指str是指向char的常量指针！！而并非指向常量char的指针！！即：不可以将上述声明理解为：`const char *str`

#### 2.引用与指针的区别

​	1.引用不是对象而指针是。

​	2.声明引用后必须初始化！且初始化的对象必须与引用类型相匹配。

​	3.引用是为一个对象创建别名。指针是个对象，该对象可以储存某个变量的地址。

#### 3.auto注意事项

​	1.使用auto声明时，必须初始化。因为必须根据 赋值表达式右边的类型 来定义 对象的类型。

​	2.auto无视赋值的对象是可变的还是不可变的。即`const int i=1; auto m=i; m=5;`是合法的。就是说，m现在的类型是int而不是const int.同理，`const int *const j=&i; auto n=j; n=&p;`也是合法的。虽然j是个常量指针，但n此时的类型是指向const int的指针。**其实，就是auto忽略顶层const。**

#### 4.decltype与auto区别

​	1.decl全称declare type。且decltype的用法是：`decltype(expression)` auto用法：`auto variable`

​	2.decltype的返回类型是包括顶层const的，这点和auto不同！即：

```c++
const int ci=1,&ir=ci;
decltype(ci) j=1; //j now is type of const int. -> const int j =1;
decltype(ir) jr=j;  //jr now is a reference of const int. -> const int &jr=j;
```

​	3.若 表达式为解引用 或 用括号括住变量：

```c++
const int ci=1,*ir=&ci;
decltype(*ir) j=ci;  //same to const int &j=ci;
decltype((ci)) k=ci;  //same to const int k=ci;
```

那么decltype返回的类型就会返回 **这个指针指向的类型的引用** 或 **变量类型的引用**。