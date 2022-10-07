#ifndef MY_COMMON_H
#define MY_COMMON_H

class MyTestClass
{
    public:
    int func1(int a)
    {
        return a+1;
    }
    private:
    int func2(int a)
    {
        return a-1;
    }
    vector<int> m_v;
    map<int, int> m_m;

};

#endif /* MY_COMMON_H */
