# C++ day2

1. #### string and "string literal" are not the same type.

2. #### When multi-dimension array using "scope for"(范围for循环),如：

   ```c++
   int array[2][2][2];
   for(auto &x:array) //If x isn't a reference, and x of line 3 will cast to "int **".
       for(auto &y:x)	//same as above, cast to "int *"
           for(auto &z:y) /*For assign element in y, z must be a reference. And the 														reason is z will be a temporary variable,if there is z 															instead of &z.*/
               z=1;
   
   for(auto &x:array)
       for(auto &y:x)
           for(auto z:y)
               cout<<z<<endl;
   ```

3. #### Must tell what type that vector holding when you try to initialize a vector. And you don't need tell what capacity about that vector. Just ``vector<type> v;``, after that you can use a method called ``v.push_back(data);`` to add data to your vector. Don't worry, vector is a dynamic container. That is to say, its capacity increased by the numbers of data.

4. #### In my opinion, Iteration is something like "pointer". And container like vector, string can use ``begin(), end(), cbegin(), cend();`` to get a iteration or const it. Using ``*`` to solve reference iteration. Like :

   ```c++
   vector<int> v(10,1); // init v, v has ten of 1.
   auto vb=v.begin(); //vb type is vector<int>::iterator.
   auto ve=v.end();
   for(;vb!=ve;vb++)
       *vb=2; // solve reference, and the data vb pointing changed to 2.
   for(vb=v.begin();vb!=ve;vb++)
       cout<<*vb<<endl; // print data vb pointing.
   ```

5. #### 

