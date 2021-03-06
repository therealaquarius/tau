#include "tau.h"

using namespace tau;
using namespace si;

#include "../../src/trace.h"
#include <map>

template < class T > struct Test
{    
    template< class _T > struct _Pair
    {
        _T key;
        _T value;
        
        _Pair( const _T& _key, const T& _value )
        : key( _key ), value( _value )
        {
            
        }
        
        _Pair( const _Pair& pair )
        : key( pair.key ), value( pair.value )
        {
            
        }
    };

    typedef li::Map< T, T > Map;
    typedef _Pair< T > Pair;
    typedef li::List< Pair > List;
    
    Map map;
    List list;
    ui size;
    ui count;
    
    Test( ui _size )
    : size( _size ), count( 0 )
    {
        
    }
    
    template < class Gen > Pair pair( Gen gen )
    {        
        Pair pair( gen(), gen() );
        list.add( pair );
        return pair;
    }
    
    template< class Gen, class Run > void operator()( Gen gen, Run run )
    {
        ENTER();
        
        for (  ; count < size; count ++ )
        {
            Pair pair = this->pair( gen );
            map[ pair.key ] = pair.value;
            run( pair );
        }
    }
};

// class First
// {
//     public:
//         First()
//         {
//
//         }
//
//         virtual void result(  )
//         {
//             TRACE( "0x%x", what );
//         }
// };

class Task: public th::Pool::Task
{
public:
    Task()
        : th::Pool::Task()
    {
        
    }
    
    virtual ~Task()
    {
        ENTER();
    }
    
    virtual void operator()( )
    {
        ENTER();
        
        request().data().add( Data::get() );
    }
    
};

class Second: public Reel
{
public:
    Second()
    {
        ENTER();
    }
        
    void test()
    {
        ENTER();
        
    }
    
    virtual void destroy()
    {
        mem::mem().detype< Second >( this );            
    }
};
    


int main( )
{

    // {
  //       Test< int > test( 30 );
  //       test( [ ] ( ) { return random( INT_MAX ); }, [ & ] ( const Test< int >::Pair & pair )
  //       {
  //           test.map.remove( pair.key );
  //
  //           try
  //           {
  //               test.map.get( pair.key );
  //               assert( false );
  //           }
  //           catch( ... )
  //           {
  //
  //           }
  //       } );
  //   }
  //  
//    {
//        Test< int > test( 30 );
  //      test( [ ] ( ) { return random( INT_MAX ); }, [ & ] ( const Test< int >::Pair & pair ) { } );
        

        // Some test;
        // li::Map< int, int > map;
        //
        // for ( int i = 0; i < 10; ++i )
        // {
        //     map[ i ] = i;
        // }
        //
        // printf( "pthread_self: %f\n", ::pthread_self( ) );
        //
        // test.start();
        // test.join();
        
    //    First first;    
    
    
  //       li::Map< int, int > map;
//
//     auto count = 3;
//
// //    void* voids[ 100 ];
//
//     {
//         li::List< int >  ints;
//
//         for( auto i = 0; i < 2; ++i )
//         {
//             ints.append( i );
//         }
//     }
        
        
       

       
       // map.remove( 2 );
//        STRACE( "%d", map.length() );
//
//
//        li::List< Data > list;
//        list.append( "test" );
//        list.append( "test1" );
//        list.clear();
//        STRACE( "%d", list.length() );
//
//        newmem::Mem mem;
//        auto test = mem.type< First >();
//        mem.detype< First >( test );
//
//
//        // li::List< First* > firsts;
// //
    
// //
// //        firsts.all( [ & ]( First* f ){ mem.detype< First >( f ); } );
//
//        test = mem.type< First >();
//        mem.detype< First >( test );
    
//        mem::disable();
        // auto event = ev::Loop::Event::get( Time( 1000 ) );
        // ev::Loop loop;
        // loop.add( *event );
        // loop.run( [ & ]( ev::Loop::Event& event )
        //     {
        //         STRACE( "event 0x%x", &event );
        //         //event.deref();
        //         loop.stop();
        //     } );
        
        
        struct Result: io::Result
        {
            virtual void event( ui event, ev::Request& request )
            {
                ENTER();
                
//                Data data = request.data();
                
                TRACE( "result with event %d", event );
                
                if ( event == io::Net::Read )
                {
                    printf( "%s", request.data().c() );
                }
                
                if ( event == io::Net::Accept )
                {
                    auto address = static_cast< fs::Link::Address* >( request.custom() );
                    TRACE( "accepted connection from %s", address->tostring().c() );
                    tau::stop( [ & ] ( ) { TRACE( "stopped", "" ); } );
                }
                
                if ( event == io::Net::Error )
                {
                    TRACE( "error: %s", request.error()->message.c() );
                    
                }
                
                if ( event == io::Process::Read )
                {
                    printf( "%s", request.data().c() );
                }
                
                if ( event == io::Process::Exit )
                {
                    auto code = ( long ) request.custom();
                    TRACE( "process exited with code %d", code );
                }
                
               // 
                
                    
                
//                  request.parent().deref();
            }
            
            virtual void destroy()
            {
                mem::mem().detype< Result >( this );
            }
            
            virtual ~Result()
            {
                ENTER();
            }
        };
    
        void* test = NULL;
        ul a = ( ul ) test;
       
        tau::start( [ & ] ( )
        {
            auto result = mem::mem().type< Result >();
            io::process( *result, "echo 'test'" );
            //io::timer( *result );
            //io::file( *result, "Makefile" ).read();

                          //STRACE( "%d", a );
            // io::file( "Makefile" ).read( [ & ]( ev::Request& request )
//                 {
//                      request.data().add( '\0' );s
//                      printf( "%s", request.data().c() );
//
//                      tau::stop( [](){ printf("stopped\n"); } );
//
//                 } ).deref();

//            io::net( *result, {{ options::Port, 8000 }, { options::Server, true }} );
            result->deref();

                          int a = 100;




            // io::timer( [ & ] ( const ev::Request& request, const io::Event& event )
            //     {
            //                           STRACE( "%d", a );
            //          STRACE( "callback with event 0x%x", &event );
            //      }, { { options::Msec, 100 }, { options::Repeat, true } } );
        } );

        
       

  //      test.map.keys( [ & ] ( int key ) {  printf("key %d\n", key ); } );
        
    //     test( [ ] ( ) { return random( INT_MAX ); }, [ & ] ( const Test< int >::Pair & pair ) { assert( test.map.size() == test.count + 1 ); } );
//         test.list.all( [ & ] ( const Test< int >::Pair& pair )
//             {
//
//
// //                assert( test.map.remove( pair.key ) );
//             } );
//     }
//
        
        
    // {
  //       Test< int > test( 30 );
  //       test( [ ] ( ) { return random( INT_MAX ); }, [ & ] ( const Test< int >::Pair & pair ) { } );
  //       test.map.clear();
  //       assert( !test.map.size() );
  //       test.list.all( [ & ] ( const Test< int >::Pair& pair ) {  assert( !test.map.remove( pair.key ) ); } );
  //   }
    
    

}