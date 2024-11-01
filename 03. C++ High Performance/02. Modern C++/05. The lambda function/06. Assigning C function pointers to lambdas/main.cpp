/* Let's say you are using a C library, or an older C++ library, which uses a
callback function as a parameter. For convenience, you would like to use a lambda
function like this */
external void download_webpage(const char* url, void (*callback)(int, const char*));

/* The callback here is a return code and the web page HTML. If you want to invoke
this with a lambda, you have to use a plus in front of the lambda in order to
convert it into a regular function pointer */
auto func()
{
    auto lambda = +[](int result, const char *str) { };
    download_webpage("http://www.example.com", lambda);
}

/* This way, the lambda is converted into a regular function pointer. Note that the
lambda cannot have any captures at all in order to use this functionality */