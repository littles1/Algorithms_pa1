/*
 * *File: pa1.h
 *
 */
#ifndef _PA1_H
#define _PA1_H
#include <limits.h>
#include <math.h>

#include <iostream>
#include <vector>
using namespace std;
class Prog1 {
  public:
   static int countInOrderPairs(vector<int>& A);
   static int smallestElementPos(vector<int>& A);
   static int groupSort(vector<int>& A);

  private:
   static int countInOrderPairs(vector<int>& A,
                                vector<int>& temp,
                                int          left,
                                int          right);
   static int countInOrderPairs(vector<int>& A,
                                vector<int>& temp,
                                int          left,
                                int          mid,
                                int          right);
   static int smallestElementPos(vector<int>& A,
                                 int          left,
                                 int          right,
                                 int          smallest,
                                 int          index);
   static int smallestElementPos(vector<int>& A,
                                 int          left,
                                 int          mid,
                                 int          right,
                                 int          smallest,
                                 int          index);
};
#endif