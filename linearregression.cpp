#include "linearregression.h"
#include "math.h"

void linearregression( point *sampleArray, double &alfa, double &beta ){
    /*
        linar regression of sample data,

        y = alfa + beta.x
     */

    int sampleSize = sizeof(sampleArray);

    double xTotal = 0, yTotal = 0, yxTotal = 0, x2Total = 0;

    for (int i = 0; i < sampleSize; i++){

        xTotal += sampleArray[i].x;
        yTotal += sampleArray[i].y;
        yxTotal += sampleArray[i].x * sampleArray[i].y;
        x2Total += pow(sampleArray[i].x, 2);
    }

    beta = (sampleSize * yxTotal - xTotal * yTotal) /
           (sampleSize * x2Total - pow(xTotal, 2));

    alfa = (yTotal - beta * xTotal) / sampleSize;

}
