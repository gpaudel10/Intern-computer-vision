<h2>Table of Contents:</h2>

- [Pandas](#pandas)
    - [Data Structures](#data-structures)
  - [Selection and Indexing](#selection-and-indexing)
  - [Filtering](#filtering)
  - [Useful Methods](#useful-methods)
  - [Handling Missing Data](#handling-missing-data)

## Pandas

Pandas is Python Data Analysis Library. It is a powerful open-source Python library widely used for data manipulation, analysis, and exploration. It provides fast, flexible, and expressive data structures designed to make working with relational or labeled data both easy and intuitive. It aims to be the fundamental high-level building block for doing practical, real-world data analysis in Python.

#### Data Structures

* **Pandas Series**

    A Series is a one-dimensional labeled array that can hold data of any type (integer, float, string, etc). A Series consists of two main components: the *data* itself and an associated *index* that labels each element in the Series. We can create a Series in pandas using various methods, such as passing a list, NumPy array, or dictionary to the `pd.Series()` constructor.
    for example:
    ```python
    import pandas as pd

    data = [1,2,3,4]
    s = pd.Series(data)
    s
    ```
Output:
```markdown
    0    1
    1    2
    2    3
    3    4
    dtype: int64
```
* **Pandas DataFrames**
  
   DataFrame is a two-dimensional labeled data structure that can hold data of different types (integer, float, string, etc). It is similar to a table in a relational database or a spreadsheet with rows and columns. It consists of three principal components, the *data*, *rows*, and *columns*. for example:
```python
import pandas as pd
team = {
    "name" : ["gyanendra","utsav","nripesh"],
    "depart" :["cv","cpp","cv2"],
    "company": ["ab","bc","cd"],
    "id" : [55,65,75]
}
df = pd.DataFrame(team)
df
```
Output:
```markdown

    name	depart	company	id
0	gyanendra	cv	 ab	    55
1	utsav	    cpp	 bc	    65
2	nripesh	    cv2	 cd	    75

```

1. Obtaining basic information about the dataframes

   * To get a concise summary of the dataframe, `df.info()` method is used, which provides information about the column names, data types, and non-null values.
   * To obtain descriptive statistics `df.describe()` method is used, which gives count, mean, standard deviation, minimum, maximum, and quartile values for numerical columns.
   * `df.head(n)`: returns the first n rows of the dataframe.
   * `df.tail(n)`: returns the last n rows of the dataframe.
   * `df.shape`: Returns a tuple representing the dimensions of the dataframe *(number of rows, number of columns)*.
   * `df.columns`: returns the column labels of the dataframe.
  
2. Index basics

    The index in a dataframe is the label assigned to each row. It can be used for selection, alignment, and data alignment operations. Some important features of the index include:

    * `df.set_index(keys)`: sets the dataframe's index using one or more columns.Here keys is column or labels.
    * `df.reset_index()`: resets the index to the default integer index.
    * `df.reindex(index)`: changes the order also adds missing labels in the index.
    * `df.sort_index()`: Sorts the dataframe by the index.


### Selection and Indexing

Pandas offers various methods for selecting and indexing data in a dataframe, some of them are:

* `df[column]`: selects a single column by label.
* `df[[column1, column2]]`: selects multiple columns by labels.
* `df.loc[row_label]`: selects a single row by label.
* `df.loc[start_row:end_row]`: selects multiple rows by label range.
* `df.iloc[row_index]`: selects a single row by integer index.
* `df.iloc[start_index:end_index]`: selects multiple rows by integer index range.
* `df.loc[row_label, column_label]`: selects a single value by row and column label.
* `df.iloc[row_index, column_index]`: selects a single value by row and column index.

In pandas, *loc* and *iloc* are two important methods used for indexing and selecting data in a DataFrame.

- `loc` stands for location and is used for label-based indexing. It allows to select rows or columns from a DataFrame using their labels (row or column names). The syntax for loc is `df.loc[row_label, column_label]`.  
eg:
```python
df.loc[[0,2], ['sepal_width', 'petal_width']]
```
output:
```markdown
        sepal_width	petal_width
    0	3.5	        0.2
    2	3.2	        0.2

```
- `iloc` stands for integer location and is used for integer-based indexing. It allows to select rows or columns from a DataFrame using their integer positions. The syntax for iloc is `df.iloc[row_index, column_index]`.
eg:
```python
df.iloc[1,3]
```
output:
```markdown
    0.2
```

### Filtering

Filtering allows to select specific rows or columns based on certain conditions. Pandas provides several methods for filtering data in a DataFrame:

Filtering with selection brackets: We can use boolean indexing to filter rows based on a condition.
* `df[df['column'] condition]`: filters rows based on a condition for a specific column.eg
```python
df[(df['sepal_width'] > 4) & (df['sepal_width'] < 4.1)]
```
* `df.isin(values)`: filters rows based on whether values are present in a column.eg
```python
df[df['petal_width'].isin([0.02, 0.1, 4])]
```
* `df.between(start, end)`: filters rows based on whether values are between a specified range.
```python
df[df['sepal_length'].between(5.1, 5.2)]
```
* `df.contains(substring)`: filters rows based on whether a substring is present in a column.

* `df.query(expression)`: filters rows based on a boolean expression.


### Useful Methods

* `apply()` is used to transform data, compute new values, or perform any custom operation on the data. Its syntax is `df.apply(func, axis=0, raw=False, result_type=None, args=(), **kwargs)` for dataframe and without axis for series.
* `corr()` function is used to compute the correlation between columns of a DataFrame or Series. Correlation is a statistical measure that indicates the strength and direction of the linear relationship between two variables.
* `idxmin()` and `idxmax()` functions in pandas are used to find the index labels of the minimum and maximum values in a DataFrame or Series. These functions return the index labels corresponding to the minimum or maximum values based on specified criteria. eg
```python
min = df['petal_length'].idxmin()
f"index label of the minimum petal_width is {min}"
```
output:
```markdown
'index label of the minimum petal_width is 22'
```

```python
max = df['petal_length'].idxmin()
f"index label of the minimum petal_width is {max}"
```
output:
```markdown
'index label of the minimum petal_width is 118'
```
* `map()` function from Series is used to substitute each value in a Series with another value, that may be derived from a function, a dict or a Series . Since DataFrame columns are series, we can use map() to update the column and assign it back to the DataFrame.eg
```python
species_mapping = {'Iris-setosa': 'setosa', 'Iris-versicolor': 'versicolor', 'Iris-virginica': 'virginica'}
df_map = df['species'].map(species_mapping)
print(df_map)
```
output:
```markdown
    0         setosa
    1         setosa
    2         setosa
    3         setosa
    4         setosa
            ...    
    145    virginica
    146    virginica
    147    virginica
    148    virginica
    149    virginica
    Name: species, Length: 150, dtype: object
```
* `df.value_counts()`: Counts the occurrences of unique values in a column. It returns a new Series object with the unique values as the index and their corresponding counts as the values.eg

```python
no_species = df['species'].value_counts()
no_species
```
output:
```markdown
    species
    Iris-setosa        50
    Iris-versicolor    50
    Iris-virginica     50
    Name: count, dtype: int64
```
* `replace()`function in pandas is used to replace values in a DataFrame or Series with specified new values.eg

```python
    to_replace = df.replace('Iris-setosa', 'Iris-Setosa')
    to_replace
```
output:
```markdown    
    sepal_length	sepal_width	petal_length	petal_width	species
    0	5.1	3.5	1.4	0.2	Iris-Setosa
    1	4.9	3.0	1.4	0.2	Iris-Setosa
    2	4.7	3.2	1.3	0.2	Iris-Setosa

```
* `unique()` function returns an array or a list of unique values present in a Series or column. It provides a distinct list of values without any duplicates. The unique values are returned in the order of their appearance in the original data.
* `nunique()` function returns the count of unique values in a Series or column. It provides the number of unique values present in the data. eg


```python
    unique_species = df['species'].unique()
    no_of_unique_species = df['species'].nunique()
    print(unique_species)
    print(no_of_unique_species)
```
output:
```markdown    
    ['Iris-setosa' 'Iris-versicolor' 'Iris-virginica']
    3

```
* `duplicated()` function returns a boolean Series that indicates whether each element in the DataFrame or Series is duplicated or not. syntax is `df.duplicated(subset, keep)` and parameters are:

| Parameter | Value | Description |
| --- | --- | --- |
| subset | column labels |  a string or a list containing any columns to ignore. |
| keep | 'first' | specifies to keep the first occurrence of the duplicate |
|      | 'last'  | specifies to keep the last occurrence of the duplicate. |
|      | False   | default 'first'. If set to false, drop all duplicates. |

example:
```python
    df.duplicated(subset=None, keep='first')
```
output:
```markdown
    0      False
1      False
2      False
3      False
4      False
       ...  
145    False
146    False
147    False
148    False
149    False
Length: 150, dtype: bool
```

* `drop_duplicates()` function removes duplicate rows from the DataFrame or Series and returns a new DataFrame or Series without the duplicate rows. same syntax as `duplicated()`.




### Handling Missing Data

Pandas provides functionality to handle missing data, represented as NaN (Not a Number) values, in a DataFrame:

* `df.isnull()`: returns a boolean DataFrame indicating missing values.
* `df.notnull()`: returns a boolean DataFrame indicating non-missing values.
* `df.dropna()`: removes rows or columns with missing values. Its syntax is `df.dropna(axis=0, how='any or all', subset=None, inplace=False)`

* `df.fillna(value)`: Fills missing values with a specified value. It returns a new DataFrame object unless the inplace parameter is set to **True**, in that case the **fillna()** method does the replacing in the original DataFrame instead.

* `df.interpolate()`: Interpolates missing values based on the existing data based on a specified method. its syntax is 

        `df.interpolate(method='linear', axis=0, limit=None, inplace=False, limit_direction='forward', limit_area=None, downcast=None)`


* `df.isna().sum()`: is used to count the number of missing values (NaN values) in each column of a DataFrame.eg
```python
df.isna().sum()
```
output:
```markdown
    sepal_length    0
    sepal_width     0
    petal_length    0
    petal_width     0
    species         0
    dtype: int64
```