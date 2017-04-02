# Hash
Medium challenge user input is appended directly to SQL statements.
Search form vulnerable to injections.
The flag can be found on a page shown when logged in.
Search outputs login and password_hashes if

%' UNION SELECT username, password_hash FROM Users;#

is entered.

Ensure to include phpbb.txt

Password hashes can then be decrypted on other website.
eg. https://hashkiller.co.uk/sha1-decrypter.aspx
