class Logger { };
class TestLogger : public Logger { };
class ReleaseLogger : public Logger { };
bool tests_are_running(bool running) {
    return running;
}

Logger* createLogger() {
    if (tests_are_running(true)) {
        TestLogger* logger = new TestLogger();
        return logger;
    } else {
        ReleaseLogger* logger = new ReleaseLogger();
        return logger;
    }
    /* in this case there is no call to delete here! so the code calling
    "createLogger" needs to make sure to call the delete function (now go back to
    the "main.cpp" source file) */
}