# Testing-Sorting-Algorithms
In this program, we will develop classes to use for testing two sorting algorithms (Selection and Quick sort)


* (1) GenerateRandomList(min, max, size) Generate a given number of random integer
data from a certain range. For example, one can generate a vector/array of 10000
integer numbers that fall in the range from 1 to 100000, e.g., [5554, 32300, 98000,
342, …]
* (2) GenerateReverseOrderedList(min, max, size) Generate a given number of reverse
ordered integer data from a certain range. You can first generate random data and
then sort them reversed
* (3) RunOnce(sorter, data, size) Run a given sorting algorithm on a given set of data
and calculate the time taken to sort the data
* (4) RunAndAverage(sorter, type, min, max, size, sets_num) Run a given sorting
algorithm on several sets of data of the same length and same attributes (from the
same range and equally sorted; e.g., random or reversed) and calculate the average
time
* (5) RunExperient (sorter, type, min, max, min_val, max_val, sets_num, step) Develop
an experiment to run a given sorting algorithm and calculate its performance on sets
of different sizes (e.g., data of size 10000, 20000, etc.) as follows:
I. All sets are generated with values between min and max
II. First, generate sets_num sets with size min_val. Use RunAndAverage () and
record the average time to process the sets
III. Next, repeat step ii but with sets whose size increases by step till reaching
max_val. Each time record the average time to process the sets
IV. For example I should be able to design an experiment to run Quick sort
algorithm on randomly sorted integers data taken from the range (1 to
1,100,000) and with input value (data size) from 0 to 100000, with step 5000.
This means we will run the algorithms on data sets of 5000, 10000, 15000, …,
100000 randomly sorted integers. Note that with each step you will generate
sets_num different sets and take the average of their runs
V. The output of the experiment goes to the screen as a table with two columns; first
column indicates set size, and second column indicates the average time
