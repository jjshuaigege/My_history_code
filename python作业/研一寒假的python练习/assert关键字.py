a,b=tuple(map(int,input().split()))
try:
    assert b!=0,"除数为0"
    print(a/b)
except Exception as e:
    print("{:}:{:}".format(type(e),e))