def SQRT(x):
    z = 1.0
    for i in range(0, 11):
        z = z-(((z*z)-x)/(2*z))
    return z


n = float(input())
print(round(SQRT(n), 4))
