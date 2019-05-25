# SortNebula
# sorting techniques to sort a vector of pairs
1) Quick sort
It uses a divide and conquer strategy. Pick an element as pivot and then we partition the given array around the pivot point.I chose the last element as the pivot at all times. The function partition performs the following:- Given an array and an element X of arry as pivot, put X at its correct position in a sorted array and put all the samller elements before x and greater after x. Time complexity on best case in O(n) and worst case is O(n**2).
2) Radix sort
It just compares the elements place value wise and proceeds ahead at every place value and keeps on sorting. It uses the concept of counting sort in its process
3) Merge Sort
Simple recursive divide and conquer sorting technique that first divides the array into halves till only single elements remain and then apply merge function to merge the two arrays using iterators i and j to their correct positions in the merged array.
