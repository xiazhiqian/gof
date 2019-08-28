#include "pch.h"
#include "bridge.h"

#include <iostream>


namespace gof
{
    Display::Display(DisplayImpl *imp)
    {
        this->m_imp = imp;
    }
    void Display::open()
    {
        this->m_imp->rawopen();
    }
    void Display::print()
    {
        this->m_imp->rawprint();
    }
    void Display::close()
    {
        this->m_imp->rawclose();
    }

    void Display::show()
    {
        this->open();
        this->print();
        this->close();
    }

    StringDisplayImpl::StringDisplayImpl(string str) :m_str(str)
    {
        
    }

    void StringDisplayImpl::rawopen()
    {
        std::cout << "---------Start----------" << std::endl;
    }
    
    void StringDisplayImpl::rawprint()
    {
        std::cout << this->m_str << std::endl;
    }

    void StringDisplayImpl::rawclose()
    {
        std::cout << "---------end----------" << std::endl;
    }
    
    MultiDisplay::MultiDisplay(DisplayImpl *imp):Display(imp)
    {
        
    }
    void MultiDisplay::MultiShow(int cnt)
    {
        for (int i=0;i<cnt;i++)
        {
            this->show();
        }
    }
}