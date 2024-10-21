// without templates
int max(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

float max(float a, float b) {
    if (a > b) {
        return a;
    }
    return b;
}

// with templates
template<typename T>
T max(T a, T b) {
    if (a > b) {
        return a;
    }
    return b;
}

int main()
{
    max<int>(10, 15);
    
    return 0;
}