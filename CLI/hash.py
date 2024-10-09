import hashlib 

print("Enter String to be hashed")
str = input("")
result = hashlib.sha512(str.encode())
print("As a hash:")
print(result.hexdigest()) 