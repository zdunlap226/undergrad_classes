## module euler
''' X,Y = integrate(F,x,y,xStop,h).
    Euler's method for solving the
    initial value problem {y}' = {F(x,{y})}, where
    {y} = {y[0],y[1],...y[n-1]}.
    x,y   = initial conditions
    xStop = terminal value of x
    h     = increment of x used in integration
    F     = user-supplied function that returns the
            array F(x,y) = {y'[0],y'[1],...,y'[n-1]}.
'''
from numpy import array
def integrate(F,x,y,xStop,h):    
    X = []
    Y = []
    X.append(x)
    Y.append(y)
    while x < xStop:
        h = min(h,xStop - x)
        y = y + h*F(x,y)
        x = x + h
        X.append(x)
        Y.append(y)
    return array(X),array(Y)

def modified_euler_method(F,x,y,xStop,h):
    X = []
    Y = []
    X.append(x)
    Y.append(y)
    while x < xStop:
        h = min(h,xStop - x)
        hd2=h/2.0
        K0 = F(x,y) # estimate y after a half-step (h/2)
        K1 = F(x+hd2,y+hd2*K0) # approximate area of panel with width h
        y = y + h*K1
        x = x + h
        X.append(x)
        Y.append(y)
    return array(X),array(Y)