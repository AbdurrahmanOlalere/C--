from base64 import b64decode

def super_complex_decode(c):
    for _ in range(pow(33, 1337, 42)):
        c = b64decode(c)
    return c.decode()
inspect = super_complex_decode("V2pKc2JscFhNVGROVmpsNlpGaEplbGd5WjNkalJFNW1aVlJDTVZnelNUQmliRGt3WVVSR2VtWlJQVDA9")

print(inspect)
s = input("Enter your guess for the flag: ")


if s == inspect:
    print("That's right!")
else:
    print("That's wrong! D:")
