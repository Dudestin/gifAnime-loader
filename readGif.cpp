#include <iostream>
#include <fstream>
using std::cout; using std::endl;

struct GCTable{
   char R[1];
   char G[1];
   char B[1];
};

struct Header{
   char signature[6];
   char version[6];
   char l_scr_with[2];
   char l_scr_height[2];
   char bg_index[1];
   char pix_aspect_ratio[1];
   GCTable hoge[256];
};

int main(void){
   std::fstream file;
   char buf[16];

   file.open("03.gif",std::ios::in|std::ios::binary);
   if ( !file.is_open() ) {
      cout <<  "file open error" << endl;
      return 1;
   }
    
   while( !file.eof() ) {
      file.read(buf,sizeof(buf));
        
      for(int i=0,size=file.gcount();i<size;++i) {
         cout << buf[i] << std::flush;
      }
   }
    
   file.close();
    
   return 0;
}
