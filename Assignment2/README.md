# Assignment 1

By Guillaume St-Pierre

## Encrypt

### Description

Encrypt - Program that receives a string message en encrypts it using an encryption key, printing the resulting encrypted string.

### How to use

Compile with `gcc bit_manipulation.c encrypt.c -o encrypt.exe`

Execute with `./encrypt.exe`

### Example

```
Please enter a message to encrypt: This is an example
Please enter the encryption key: 42


 Transmitted message:
-75 5 122 35 4 -102 21 -73 31 25 98 10 100 90 -100 53 -18 -81
```

## Decrypt

### Description

Decrypt - Program that receives an encrypted message and the decryption and key and decrypts it, priting the decrypted message.

### How to use

Compile with `gcc bit_manipulation.c decrypt.c -o decrypt.exe`

Execute with `./decrypt.exe`

### Example

```
Please enter the encrypted message: -75 5 122 35 4 -102 21 -73 31 25 98 10 100 90 -100 53 -18 -81
Please enter the encryption key: 42


Transmitted message:
This is an example
```