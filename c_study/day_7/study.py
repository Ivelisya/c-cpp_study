def swap(a,b):
    z = a
    a = b
    b = z
    return a,b
a = input()
b = input()
print(f"交换前{a},{b}")
a,b = swap(a,b)
print(f"交换后{a},{b}")