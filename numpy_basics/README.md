- [Numpy Basics](#numpy-basics)
  - [Numpy Vs Python's built-in list data structure](#numpy-vs-pythons-built-in-list-data-structure)
  - [Numpy's array creating functions](#numpys-array-creating-functions)
  - [Two- and Multidimensional Arrays](#two--and-multidimensional-arrays)
  - [Different standard numpy data types](#different-standard-numpy-data-types)
  - [Conclusion](#conclusion)


## Numpy Basics

NumPy (Numerical Python) is a powerful Python library that provides support for large, multi-dimensional arrays and matrices, along with a wide range of mathematical functions to operate on these arrays efficiently. NumPy's main feature is the ndarray (n-dimensional array) object, which is a homogeneous container for storing and manipulating numerical data efficiently. It provides a way to perform mathematical and logical operations on entire arrays, eliminating the need for loops and improving performance.


### Numpy Vs Python's built-in list data structure

There is some similarities between the numpy array and python list as both use square brackets, both datatypes are mutable means we can change the data in list or array. Both can be indexed and can be used for slicing operations. These things are looked in the notebook. Now the differences and the reason to use the numpy instead of python built-in list are:

1. Memory consumption
  * Numpy arrays
  
     NumPy arrays are more memory-efficient compared to lists. This is beacause they are homogeneous, meaning all elements have the same data type. This allows for a more compact representation in memory. NumPy arrays store data in a contiguous block of memory, allowing for efficient indexing and operations on large chunks of data.

  * Python List
  
     Python lists can contain elements of different data types, leading to additional memory overhead to store type information for each element. These are arrays of pointers to objects, which introduces additional memory overhead.

We can see example as:
```python
import numpy as np
import sys

eg_list = [1, 2, 3, 4, 5]
eg_array = np.array([1, 2, 3, 4, 5])

# memory usage of Python list
print(sys.getsizeof(eg_list))

# memory usage of numpy array
print(eg_array.nbytes)
```
output:
```markdown
     104
     40
```
We can see python list consumes 104 bytes whereas numpy array consumes 40 bytes of memory.

2. Time comparisions

* Numpy arrays
  
     NumPy arrays provide faster performance for numerical computations and operations compared to Python lists. numpy is implemented in C, which allows for efficient element-wise operations, vectorized operations, and broadcasting.

* Python List
  
     Python lists are more versatile but generally slower when it comes to numerical computations. This is because they are implemented as dynamic arrays, and each element access and operation involves additional python interpreter overhead. This does not mean that array is better than a list. A list is easier to modify than an array does. Since a list store each element individually, it is easier to add and delete an element than an array does and also can store different datasize.
So we can see with example of time comparision between the python list and numpy array as:

```python
import time


my_list = list(range(10000))
my_array = np.arange(10000)

# element wise multiplication using python list
start_time = time.time()
result_list = [x * 2 for x in my_list]
end_time = time.time()
execution_time_list = end_time - start_time
print("execution time for python list is:", execution_time_list)

#element wise multiplication using numpy array
start_time = time.time()
result_array = my_array * 2
end_time = time.time()
execution_time_array = end_time - start_time
print("execution time for numpy array is:", execution_time_array)

if execution_time_list < execution_time_array:
    print("python list operation is faster")
else:
    print("numpy array operation is faster")

```
Output:
```markdown
     execution time for python list is: 0.0008635520935058594
     execution time for numpy array is: 0.0003993511199951172
     numpy array operation is faster
```
So in general the performance benefits of numpy become more significant as the size of the data increases. NumPy arrays are more memory efficient and offer faster performance for numerical computations, making them a preferred choice when working with large-scale numerical data. Python lists, on the other hand, provide more flexibility and support different data types, but may be slower for numerical operations.

### Numpy's array creating functions 

There are 6 general mechanisms for creating arrays:

1. Conversion from other Python structures (i.e.    lists and tuples)

2. Intrinsic NumPy array creation functions (e.g. arange, ones, zeros, etc.)

3. Replicating, joining, or mutating existing arrays

4. Reading arrays from disk, either from standard or custom formats

5. Creating arrays from raw bytes through the use of strings or buffers

6. Use of special library functions (e.g., random)


So some terminologies from array creation are:

* `np.arange(start, stop, step)` creates a 1D array with values from start to stop-1, incrementing by step.

eg:
```python
arr = np.arange(1,5) #creating 1d array using arange()
print(arr)
x = np.arange(start = 1, stop = 10, step= 2)
print(x)
```
output:
```markdown
     [1 2 3 4]
     [1 3 5 7 9]
```
* `np.linspace(start, stop, num=5, endpoint=True, retstep=False) -> ndarray` creates a 1D array with num equally spac    ed values from start to stop, inclusive. It is similar to **arrange()** but instead of step, it uses a sample number. Step size changes when the endpoint is false. 
  * **start**  : [optional] start of interval range. ***default*** = 0
  * **stop**   : end of interval range
  * **retstep** : If True, return (samples, step).
  * **num**    :  No. of samples to generate
  * **dtype**   is the type of element of output array.

eg:
```python
arr = np.linspace(0,1,5)#creating 1d array using linspace()
arr
```
output:
```markdown
     array([0.  , 0.25, 0.5 , 0.75, 1.  ])
```
* `np.logspace(start, stop, num)` creates a 1D array with num logarithmically spaced values from 10*start to 10*stop.

eg:
```python
arr = np.logspace(0,1,3)#create 1d with logspace()
arr
```
output:
```markdown
     array([ 1.        ,  3.16227766, 10.        ])
```
* `np.random.random(size)` creates a 1D array with size random values between 0 and 1.

eg:
```python
     arr = np.random.random(5)#creates the 1d array of random values with random()
     print(arr)
```
output:
```markdown
     [0.41581093 0.14338813 0.19695268 0.62165961 0.19983609]
```
* `np.eye(N)` creates an N x N 2D array with ones on the diagonal and zeros elsewhere.

eg:
```python
arr = np.eye(3, dtype =int) #creates 2d array
print(arr)
```
output:
```markdown
     [[1 0 0]
     [0 1 0]
     [0 0 1]]
```
* `np.zeros(shape, dtype=float, order='C')` creates a 2D array filled with zeros, with the specified shape.<br>
Arguments: 
  * **shape**: Shape of numpy array, Single int or sequenc of int. 
  * **dtype**(optional) is the type of element of output array.***Default*** = **float64**
  * order (optional)Order in data is stored in multi-dimension array. if row major 'F' or column major 'C'. ***Default = C***.

eg:
```python
a = np.zeros(4, dtype = int)
b = np.zeros([4, 3], dtype = float)
c = np.zeros((4, 3, 2), float, 'C')
print("the values of array a : \n", a)
print("the values of array b : \n", b)
print("the values of array c : \n", c)
```
output:
```markdown

     the values of array a : 
     [0 0 0 0]
     the values of array b : 
     [[0. 0. 0.]
     [0. 0. 0.]
     [0. 0. 0.]
     [0. 0. 0.]]
     the values of array c : 
     [[[0. 0.]
     [0. 0.]
     [0. 0.]]

     [[0. 0.]
     [0. 0.]
     [0. 0.]]

     [[0. 0.]
     [0. 0.]
     [0. 0.]]

     [[0. 0.]
     [0. 0.]
     [0. 0.]]]
```
* `np.ones(shape, dtype=float, order='C')` creates a 2D array filled with ones, with the specified shape.

eg:
```python
arr = np.ones((4,3)) #creates 2d array
print(arr)
```
output:
```markdown
     [[1. 1. 1.]
     [1. 1. 1.]
     [1. 1. 1.]
     [1. 1. 1.]]
```
* `np.indices` will creates a set of arrays (stacked as a one-higher dimensioned array), one per dimension with each representing variation in that dimension.

eg:
```python
indices = np.indices((3, 4))

print(indices)
```
output:
```markdown
     [[[0 0 0 0]
     [1 1 1 1]
     [2 2 2 2]]

     [[0 1 2 3]
     [0 1 2 3]
     [0 1 2 3]]]
```

For replicating, joining or mutating existing arrays:

1. Replicating Arrays:

* `np.repeat(arr, repetitions)` repeats each element in the array a specified number of times.

eg:
```python
arr = np.array([1,2,3,4,5])

repeat = np.repeat(arr,2)#repeats we also can use tile()
print(repeat)
```
output:
```markdown
[1 1 2 2 3 3 4 4 5 5]
```
* `np.tile(arr, repetitions)` tiles the entire array a specified number of times.

eg:
```python
arr = np.array([1,2,3,4,5])

tiles = np.tile(arr,2)#repeats we also can use tile()
print(tiles)
```
output:
```markdown
     [1 2 3 4 5 1 2 3 4 5]
```

2. Joining Arrays:

* `np.concatenate((arr1, arr2))` concatenates arrays along a specified axis.

eg:
```python
arr1 = np.array([0, 2, 3])
arr2 = np.array([1, 5, 6])

new_arr = np.concatenate((arr1 ,arr2))
print(new_arr)
```
output:
```markdown
     [0 2 3 1  5 6] 
``` 
* `np.vstack((arr1, arr2))` stacks arrays vertically, creating a new array with the arrays as rows.

eg:
```python
new_arr = np.vstack((arr1,arr2))
print(new_arr)
```
output:
```markdown
     [[0 2 3]
     [1 5 6]]
```
* `np.hstack((arr1, arr2))` stacks arrays horizontally, creating a new array with the arrays as columns.

eg:
```python
new_arr = np.hstack((arr1,arr2))
print(new_arr)
```
output:
```markdown
     [0 2 3 1 5 6]
```
1. Mutating Arrays:

`np.flip(arr)` reverses the order of elements in the array.

`np.sort(arr)` sorts the array in ascending order.

eg:
```python
#mutate 
new_arr = np.array([1,2,3,4,5])
print(new_arr)
#reverse
new_arr1 = np.flip(new_arr)
print(new_arr1)
#sort
new_arr2 = np.sort(new_arr1)
print(new_arr2)
```
output:
```markdown
     [1 2 3 4 5]
     [5 4 3 2 1]
     [1 2 3 4 5]
```

To read the array from file we use `data = np.genfromtxt('somefile', delimiter=',')` to read from binary file `data = np.fromfile('somefile.bin', dtype=np.float32)` there are other like `np.loadtxt()`,`np.frombuffer()`,`np.load()`,etc

```python
#creating arrays from raw bytes using string

strbyte = b'\x01\x02\x03\x04\x05\x06\x07\x08'
arr_from_str = np.frombuffer(strbyte, dtype=np.uint8)
print(arr_from_str)
#creating arrays from raw bytes using buffers
buffbyte = bytearray(b'\x01\x02\x03\x04\x05\x06\x07\x08')

arr_from_buffer = np.frombuffer(buffbyte, dtype=np.uint8)
print(arr_from_buffer)
```
output:
```markdown
     [1 2 3 4 5 6 7 8]
     [1 2 3 4 5 6 7 8]
```


### Two- and Multidimensional Arrays
A two-dimensional numpy array, also known as a matrix, is a structured grid of elements arranged in rows and columns. Also multidimensional numpy array is an array with more than two dimensions. It can have three or more dimensions, and each dimension represents a different axis. For example, a three-dimensional array can be visualized as a cube with length, width, and height.

```python
# creating a two dimensional array
twoD_array = np.array([[1, 2, 3], [4, 5, 6]])

# accessing elements in a two dimensional array
print(twoD_array[0, 1]) 

# creating a three dimensional array
threeD_array = np.array([[[1, 2], [3, 4]], [[5, 6], [7, 8]]])

# accessing elements in a three dimensional array
print(threeD_array[0, 1, 1])  

```
output:
```markdown
     2
     4
```

### Different standard numpy data types


<img src = "https://www.simplifiedpython.net/wp-content/uploads/2018/11/Python-NumPy.jpg" width=600, height=400>

Numpy provides a wide range of data types to represent different kinds of numerical data.

**List of characters that are used to represent data type in NumPy**  
* i - integer
* b - boolean
* u - unsigned integer
* f - float
* c - complex float
* m - timedelta
* M - DateTime
* O - object
* S - string
* U - Unicode string
* V - fixed chunk of memory for another type


### Conclusion

So in this task i have learned some basics of numpy and some creating and manipulation fucntion also some datatypes and size they occupies.
