#include "Test.h"

TEST();

class TestFile: public Test
{
public:
    TestFile()    
    : m_name( data::Data::get() )
    {
        setInterval( Time( 10 ) );
        Test::handler( File::Read, ( Test::Handler ) &TestFile::onRead );
    }
    
    virtual ~TestFile()
    {
            
    }
    
private:
    
    
    virtual void onRead( Grain& grain )
    {
        ENTER();
        
        auto& file = dynamic_cast< File& >( grain );
        
        auto& read = file.in().data();
        auto& data = dynamic_cast< Data& >( Test::data( file ) );
        
        assert( read.find( data.first.data() ) > -1 );
        assert( read.find( data.second.data(), data.first.data().length() ) > -1 );
        
        Test::set( "read" );
        
        out( read );
        out( "\n" );        
    }
    
    virtual void onWrite( Grain& grain )
    {
        ENTER();
        auto& file = dynamic_cast< File& >( grain );

//        auto& nfile = Test::file( file.name() );
//        Test::assign( nfile, Test::data( file ) );
//        nfile.read();
        
        Test::set( "write" );
    }
        
    struct Data: Test::Data
    {
        Till& first;
        Till& second;
        
        Data()
        : first( Till::get() ), second( Till::get() )
        {
            
        }
        
        ~Data()
        {
            first.deref();
            second.deref();
        }
        
    };
    
    virtual void run()
    {
        ENTER();

        auto& file = Test::file( m_name );

        auto& data = *new Data( );

        data.first.add( data::Data::get( 100 ) );
        file.out( ).add( data.first );
        
        data.second.add( data::Data::get( 100 ) );
        file.out( ).add( data.second );

        Test::assign( file, data );
        
            
    }
    
    
    virtual void si::check( )
    {
        ENTER();
        Test::si::check( "write" );
    }
    
    virtual void cleanup()
    {
        ENTER();
        File::remove( m_name );
        Test::cleanup();
    }
    
private:
    data::Data m_name;
};

int main()
{
    TestFile()();
}
