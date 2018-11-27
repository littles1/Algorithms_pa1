/*
    Scott Little
    version 1.0
*/
#include "pa1.h"

using namespace std;

/*
Problem Statement

You are given a list of n numbers, stored in a vector A. You are
interested in finding out how many pairs of numbers that are
already in order.

Formally, A pair (A[i], A[j]) is called to be in
order if i < j and A[i] < A[j]. Being a CS student, you feel
embarrassed to solve the problem in O(n 2 ).

Design and implement an efficient divide-and-conquer
algorithm better than O(n 2 ) to return the number of in-order pairs
in A.

Besides the code, you also need to write the recurrence relation
and give T(n) in Big-oh.

T(n) = 2T(n/2) + n
a = 2; b = 2; d = 1
O(nlogn)
*/
int Prog1::countInOrderPairs(vector<int>& A,
                             vector<int>& temp,
                             int          left,
                             int          right) {
   int mid, counter = 0;
   if (right > left) {
      mid     = floor(left + (right - left) / 2);
      counter = countInOrderPairs(A, temp, left, mid);
      counter = counter + countInOrderPairs(A, temp, mid + 1, right);

      counter = counter + countInOrderPairs(A, temp, left, mid + 1, right);
   }
   return counter;
}
int Prog1::countInOrderPairs(vector<int>& A,
                             vector<int>& temp,
                             int          left,
                             int          mid,
                             int          right) {
   int i, j, k;
   int counter = 0;

   i = left;
   j = mid;
   k = left;

   while ((i <= mid - 1) && (j <= right)) {
      if (A[i] < A[j]) {
         temp[k++] = A[j++];
         counter   = counter + (mid - i);
      } else {
         temp[k++] = A[i++];
      }
   }

   while (i <= mid - 1) { temp[k++] = A[i++]; }

   while (j <= right) { temp[k++] = A[j++]; }

   for (i = left; i <= right; i++) { A[i] = temp[i]; }

   return counter;
};

int Prog1::countInOrderPairs(vector<int>& A) {
   int         size = A.size();
   vector<int> temp(size);
   return countInOrderPairs(A, temp, 0, size - 1);
};

/*
Problem Statement

A is a vector of n integers.

Design and implement a divide-and-
conquer algorithm to find the index position of the smallest
element.

If there are duplicate smallest elements, then return the
lowest index position.

Besides the code, you also need to write the recurrence relation
and give T(n) in Big-oh

Current
T(n) = 2T(n/2) + n
a = 2; b = 2; d = 1
O(nlogn)

Faster
T(n) = 2T(n/2) + 1
a = 2; b = 2; d = 0
O(n^log2) = O(n)
*/
int Prog1::smallestElementPos(vector<int>& A,
                              int          left,
                              int          right,
                              int          smallest,
                              int          index) {
   int mid;

   if (right > left) {
      mid = floor(left + (right - left) / 2);
      smallestElementPos(A, left, mid, smallest, index);
      smallestElementPos(A, mid + 1, right, smallest, index);

      index = smallestElementPos(A, left, mid, right, smallest, index);
   }
   return index;
};
int Prog1::smallestElementPos(vector<int>& A,
                              int          left,
                              int          mid,
                              int          right,
                              int          smallest,
                              int          index) {
   int i, j;

   i = left;
   j = mid;

   while ((i <= mid - 1) && (j <= right)) {
      if (A[j] < smallest) {
         smallest = A[j];
         index    = j;
      }
      if (A[i] <= smallest) {
         smallest = A[i];
         index    = i;
      }
      j++;
      i++;
   }
   return index;
};
int Prog1::smallestElementPos(vector<int>& A) {
   int smallest = INT_MAX;
   int index    = 0;
   int size     = A.size();
   return smallestElementPos(A, 0, size - 1, smallest, index);
};

/*
Problem Statement

Given a list of n numbers stored in a vector A, you want to
quickly divide the list in place (without using extra space) to two
groups such that all the even numbers precede all the odd
numbers.

 You do not care whether the even numbers themselves are sorted.

You also do not care whether the odd numbers themselves are sorted.

Your algorithm must be O(n).

The algorithm should return the index position of the last even
number after the group sort. Return -1 if there is no even number
in the list.
*/
int Prog1::groupSort(vector<int>& A) {
   int size = A.size();
   int j    = -1;

   for (int i = 0; i < size; i++) {
      if (A[i] % 2 == 0) {
         j++;
         swap(A[i], A[j]);
      }
   }
   return j;
}
