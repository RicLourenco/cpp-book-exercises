class Class_Name
{
    private:
        int privateDataMember;
        int privateDataFunction();

    protected:
        float protectedDataMember;
        float protectedDataFunction();

    public:
        double publicDataMember;
        double publicDataFunction();
        // associates the field with the class instead of the object
        static int staticMember;
};