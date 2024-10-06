import hashlib 
str = input("str:")
result = hashlib.sha512(str.encode()) 
print(result.hexdigest()) 
