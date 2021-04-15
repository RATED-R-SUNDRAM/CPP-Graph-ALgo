
def fun():
    a=1
    b=10
    c=1

    if ((a&b or 0) or (a and c and 0)):
        a=a+c
        b=b%3

    a=a<<1
    print(a+b-c)
        

fun()