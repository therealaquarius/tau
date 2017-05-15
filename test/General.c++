#include "Test.h"


class General: public Test
{
public:
    General()
        : Test( 3 )
    {
        start();
    }
    
private:
    virtual void run()
    {
        ENTER();
    }
    
    virtual void check()
    {
        assert( true );
    }
};


int main()
{
    new General();
    return 0;
}


