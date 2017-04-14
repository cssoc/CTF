# Extend
User is expected to perform a length extension attack on the webapi.
It uses SHA-256.
See wikipedia or a paper on the "flickr api exploit" for details.
Note that the request string is decoded using `urldecode` and can thus include encoded binary data.
