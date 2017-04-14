# Number 7

The server acts as a padding oracle and the message is encrypted with AES in CBC mode.
The participant can thus use the padding oracle to decrypt most of the message with the exception of the first and last block (note that OpenSSL adds padding even if the plaintext is a multiple of the blocksize).

See demo.py for an implementation.
