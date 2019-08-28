#pragma once
#include <string>

using std::string;



namespace gof
{
    class DisplayImpl {
    public:
        virtual void rawopen() = 0;
        virtual void rawprint() = 0;
        virtual void rawclose() = 0;
    };

    class StringDisplayImpl :public DisplayImpl
    {
    private:
        string m_str;
    public:
        StringDisplayImpl(string str);
        void rawopen() override;
        void rawprint() override;
        void rawclose() override;
    };


    class Display { 
    protected:
        DisplayImpl *m_imp;
    public:
        Display(DisplayImpl *imp);
        void open();
        void print();
        void close();
        void show();
    };

    class MultiDisplay :public Display
    {
    public:
        MultiDisplay(DisplayImpl *imp);
        void MultiShow(int cnt);
    };


}