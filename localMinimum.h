#ifndef LOCALMINIMUM_H
#define LOCALMINIMUM_H

#include "datatypes.h"
#include <QList>

void findLocalMinimum(int *array, int array_size, QList<range> &list){

    list.empty();

    int startIndex = 0;
    int refPoint, prevPoint;

    for (int i = 0; i < array_size; i++){

        if (i == 0){
            refPoint =  array[i];
            prevPoint = 0;
        } else {
            refPoint =  array[i];
            prevPoint =  array[i-1];
        }

        if ( refPoint > prevPoint ){
            startIndex = i;

            if (i == (array_size - 1)){
                range x;
                x.start = startIndex;
                x.end = startIndex;
                list.append(x);
            }

            for (int j = startIndex + 1; j < array_size; j++){
                if ( array[i] < array[j] ){  // < next, not maximum point
                    break;
                }
                else
                if ( array[i] > array[j] ){  // > next, maximum point

                    i = j;

                    range x;
                    x.start = startIndex;
                    x.end = j - 1;
                    list.append(x);
                    break;
                } else if (j == (array_size - 1)) {
                    range x;
                    x.start = startIndex;
                    x.end = j;
                    list.append(x);
                    break;
                }
            }
        }
    } // main for

};

void findMinimums(int *array, int array_size, QList<range> &list){

    list.empty();

    int startIndex = 0;
    int refPoint, prevPoint;

    for (int i = 0; i < array_size; i++){

        if (i == 0){
            refPoint =  array[i];
            prevPoint = 0;
        } else {
            refPoint =  array[i];
            prevPoint =  array[i-1];
        }

        if ( refPoint < prevPoint ){
            startIndex = i;

            if (i == (array_size - 1)){
                range x;
                x.start = startIndex;
                x.end = startIndex;
                list.append(x);
            }

            for (int j = startIndex + 1; j < array_size; j++){
                if ( array[i] > array[j] ){  // < next, not maximum point
                    break;
                }
                else
                if ( array[i] < array[j] ){  // > next, maximum point

                    i = j;

                    range x;
                    x.start = startIndex;
                    x.end = j - 1;
                    list.append(x);
                    break;
                } else if (j == (array_size - 1)) {
                    range x;
                    x.start = startIndex;
                    x.end = j;
                    list.append(x);
                    break;
                }
            }
        }
    } // main for

};

#endif // LOCALMINIMUM_H
