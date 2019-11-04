In this challenge we consider a modified version of double DES.

Short description:

Consider DES as a function 
	 
	DES(key, block_in) = block_out

Where:
	key:		is a 56 bit key
	block_in:	is a 64 bit input plain block
	block_out:	is a 64 bit output cipher block

Then consider double DES as

        DDES(key1, key2, block_in) = DES(key2, DES(key1, block_in)) = block_out

Where:
	key1:		is a 56 bit key
	key2:		is a 56 bit key
	block_in:	is a 64 bit input plain block
	block_out:	is a 64 bit output cipher block

Hence, we get a 56 + 56 bit = 112 bit key to DDES.

The modified double DES function we consider in this challenge is
defined as follows.

	MDDES_l(key1_l, key2_l, block_in) = DDES(key1_l, key2_l, block_in)

	key1_l:		is a l-bit key
	key2_l:		is a l-bit key
	block_in:		is a 64 bit input plain block

* The l-bit keys are formatted with (56 - l) leading 0 bits
  concatenated with the actual l-bit key. 

  E.g. for l=10 : the 10-bit key 1100110011 (binary) would be
  formatted as the key
  key_10 : 00000000000000000000000000000000000000000000001100110011

Hence, the modified double DES (MDDES_l) has an l + l bit key.


Description of data:

The file 'blocks.txt' contain lines in the following format:

l-plain-cipher: 01 5871643160744f22 d5d7727715b5d38e

where
	01:			is l in decimal
	5871643160744f22:	is the plain block encoded in hex
	d5d7727715b5d38e:	is the cipher block encoded in hex

Each value of l has four lines, i.e., four plain-cipher pairs, which
are encrypted with the same key (key1_l, key2_l of size l-bit each).

Hence the above line has been encrypted by MDDES_1 (l = 1).



Challenge:

For how large l can you recover the key?

Please note, that it is *not* expected that you provide a solution
which can solve it for all l values.

Requirements:
	1) The code should only run on one core.
	2) The run time should not exceed 1 hour.

Provide the source code to recover keys. E.g. if you develop a
C-program: 'my_solution.c" which can recover keys, then provide
instruction and command lines with the expected behaviour.

E.g.

The following is done on Ubuntu.
Used the DES implementation from openssl.
To compile the code run:

gcc -O3 my_solution.c -o my_solution -lssl -lcrypto

Note: it is important that -lssl and -lcrypto are the last arguments.

Run:

./my_solution -l 10

'prints out the the key for l=10 in hex'



