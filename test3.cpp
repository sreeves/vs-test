// this_pointer.cpp  
// compile with: /EHsc  
  
#include <iostream>  
#include <string.h>
#include <vector>
  
using namespace std;  
  
class Buf   
{  
public:  
    Buf( const char* szBuffer, size_t sizeOfBuffer );  
    Buf& operator=( const Buf & );  
    void Display() { cout << buffer << endl; }  
  
private:  
    char*   buffer;  
    size_t  sizeOfBuffer;  
};  
  
Buf::Buf( const char* szBuffer, size_t sizeOfBuffer )  
{  
    sizeOfBuffer++; // account for a NULL terminator  
  
    buffer = new char[ sizeOfBuffer ];  
    if (buffer)  
    {  
        strncpy( buffer, szBuffer, sizeOfBuffer );  
        sizeOfBuffer = sizeOfBuffer;  
    }  
}  
  
Buf& Buf::operator=( const Buf &otherbuf )   
{  
    if( &otherbuf != this )   
    {  
        if (buffer)  
            delete [] buffer;  

        sizeOfBuffer =  strlen( otherbuf.buffer ) + 1;   
        buffer = new char[sizeOfBuffer];  
        strncpy( buffer, otherbuf.buffer, sizeOfBuffer );  
    }  
    return *this;  
}  
  
int main()  
{  
    vector<int> v(3, 4);
    v.erase(4 + v.begin());

    Buf myBuf( "my buffer", 10 );  
    Buf yourBuf( "your buffer", 12 );  

    // Display 'my buffer'  
    myBuf.Display();  

    // assignment opperator  
    myBuf = yourBuf;  

    // Display 'your buffer'  
    myBuf.Display();  
}  
