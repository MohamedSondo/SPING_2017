from __future__ import division
import numpy as np
import matplotlib.pyplot as plt

def FindDD(x,y, delta):
    Fx = []
    for i in range(len(y)):
        # print "x[delta]: {}".format(x[delta])
        # print "x[i]: {}".format(x[i])
        tempy = ((y[i+1] - y[i]) / (x[delta] - x[i]))
        Fx.append(tempy)
        delta += 1
        if delta >= len(x):
            break;

    return Fx


def result(x, xpoint, i):
    xvalue = 1.0
    j = 0
    while (j <= i):
        xvalue = xvalue * (xpoint - x[j])
        j+=1
    return xvalue


def computeNewtonsDDF(DDifference, x, y):
    def N(xpoint):
        NewtonsDDF = 0
        for i in range(len(DDifference)):
            NewtonsDDF+= (DDifference[i] * result(x, xpoint, i))
        return NewtonsDDF + y[0]
    return N


def plotNewton(y, start, end, grapingPoints):
    x = np.linspace(start, end, grapingPoints )
    plt.grid(True)
    plt.plot(x,y, linewidth=2)
    plt.show()


def setDataPoints(Xpoints, Ypoints, Xrange, SIZE):
    DDifference = []
    allOrderDifferences = []
    yy = Ypoints
    for j in range(SIZE - 1):
        yy = FindDD(Xpoints, yy, j + 1)
        allOrderDifferences = allOrderDifferences + yy  # send j + 1 so that (xi+1 - xi) is accurate
        DDifference.append(yy[0])

    N = computeNewtonsDDF(DDifference, Xpoints, Ypoints)  # N is Newtons divided difference formula
    y = map(N, Xrange) #change to Xrange or xPoints

    #for i in range(len(Xrange)):
      #  print "Year: {}".format(Xrange[i]) + "\t" + "cost: {}".format(y[i])

     #graphPoints = len(Xpoints) #change to Xrange
    graphPoints=len(xrange)
    start = Xpoints[0]
    end = Xpoints[-1]
    plotNewton(y, start, end, graphPoints)


def main():
    xRange = np.arange(1885,2016,1)
    Xpoints = [1885, 1917, 1919, 1932, 1958, 1963, 1968, 1971, 1974, 1978, 1981, 1985, 1988, 1991, 1995, 1999,
               2001, 2002, 2006, 2007, 2008, 2009, 2012, 2013, 2014, 2015, 2016]
    Ypoints = [2, 3, 2, 3, 4, 5, 6, 8, 10, 15, 19, 22, 25, 29, 32, 33, 34, 37, 39, 41, 42, 44, 45, 46, 49, 49, 47]


    SIZE = len(Xpoints)

    #print xRange

    setDataPoints(Xpoints, Ypoints, xRange, SIZE)

if __name__ == '__main__':
    main()


