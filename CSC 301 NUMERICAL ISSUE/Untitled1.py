
# coding: utf-8

# In[1]:

import numpy as np
import matplotlib.pyplot as plt


def plotSplines(y, init, end):
    x = np.linspace(start, end, 400)
    plt.axis([0, 7, 0, 9])
    plt.plot(x, y, linewidth=2)
    plt.grid(True)
    plt.show()

def setDataPoints(xVal, yVal):
    tempY = []
    for i in range(2):
        x = np.linspace(xVal[i], xVal[i+1], 100)
        S = spline(xVal, yVal,i)
        y = map(S, x)
        tempY = tempY + y
    return tempY

def spline(xVal, yVal, ii):
    def S(x):
        deltaX = []
        deltaY = []

        for i in range(len(xVal) - 1):
            deltaX.append(xVal[i+1] - xVal[i])
            deltaY.append(yVal[i+1] - yVal[i])

        Ci = calCi(deltaX, deltaY)
        Ai = calAi(yVal)
        Bi = calBi(deltaX, deltaY, Ci)
        Di = calDi(Ci, deltaX)
        Sx = (Ai[ii] + Bi[ii] * (x - xVal[ii]) + (Ci[ii] * (x - xVal[ii]) ** 2) + (Di[ii] * (x - xVal[ii]) ** 3))

        return Sx
    return S

def calAi(yVal):
    tempAi = []
    for i in range(len(yValues)-1):
        tempAi.append(yValues[i])
    return tempAi

def calBi(deltaX, deltaY, Ci):
    tempBi = []
    for i in range(len(Ci)-1):
        tempBi.append( ((deltaY[i] / deltaX[i]) - (deltaX[i] * (2 * Ci[i] + Ci[i+1])) / 3) )
    return tempBi

def calCi(deltaX, deltaY):
    tempCi = []
    tempCi.append(0) # The first value for C0 is 0
    i = 0 #because C0 = 0

    while(i<len(deltaX)-1):
        temp = ((3 * ((deltaY[i+1] / deltaX[i+1]) - (deltaY[i] / deltaX[i]))) / (2 * (deltaX[i] + deltaX[i+1])))
        tempCi.append(temp)
        i+=1

    tempCi.append(0) # Cn = 0
    return tempCi

def calDi(Ci, deltaX):
    tempDi=[]
    for i in range(len(Ci)-1):
        tempDi.append(((Ci[i+1] - Ci[i])/(3*deltaX[i])))
    return tempDi

def main():
    finalYdata = []

    xValues = [ [1, 2, 3,4], [4,5, 6, 7]]
    yValues = [ [6, 7, 1,1], [1, 8, 7,5]]

    for i in range(2):
        finalYdata += setDataPoints(xVal[i], yVal[i])

    plotSplines(finalYdata, xVal[0][0], xVal[1][2])

if __name__ == '__main__':
    main()







