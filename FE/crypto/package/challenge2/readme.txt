The file 'cipher.py' contains a Python program to encrypt and decrypt files.

Example:
Create file 'test.txt'. E.g. on linux
Run
echo "THIS IS MY TEST MESSAGE" > test.txt

To encrypt a file 'test.txt' with password "nufsisiht" to the file 'test.enc'
Run:

python cipher.py enc nufsisiht test.txt test.enc

To decrypt the file 'test.enc' to 'test.clr'
Run:

python cipher.py dec nufsisiht test.enc test.clr



Challenge:
The following four files have been encrypted with 'cipher.py'.

file1.enc
file2.enc
file3.enc

How many files can you decipher?



Provide the source code to decipher the encrypted files. E.g. if you
develop a python script: 'my_solution.py" which can decipher the
encrypted files, then provide command lines with the expected
behaviour.

E.g.

python my_solution.py description.enc

'prints out the deciphered content of description.enc to stdout'

