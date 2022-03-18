def add(x):
    def f(*y):
        nonlocal x
        if y is not tuple():
            x += y[0]
            return f
        else:
            return x
    return f


print(add(98)(101)(23)())
