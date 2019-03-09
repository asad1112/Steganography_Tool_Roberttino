#include "sources.h"
int temp,u=0;
int new_data[9]={0,0,0,0,0,0,0,0,0};
/*
7*7*7 -> 127 mod(4);
(1,1,1)+(1,1,1)+(1,1,1)
RGB       RGB      RGB
check string data first if not problem 

*/




void ascii_2_binary(uchar a){
     uchar *temp=new uchar;
     for(int x=0;x<9;x++){
      *temp=a%2;
      a=(a-*temp)/2;
      new_data[x]=*temp;
     }  
     delete temp;   
}
char binary_2_ascii(){
     int ret=0;
     for(int x=0;x<9;x++){
          ret+=new_data[x]*pow(2,x);
     }
     return char(ret);
}


//initializes all required variables 
coder::coder(string data,Mat image){
     try{
     if(image.empty()){
          throw 54;
     }
     if((image.rows*image.cols)<(3*data.size())){
          throw 33;
     }
     else{
     this->data=data;
     this->image=image;

     }
     }
     catch(int e){
          if(e==54){
          cout<<"Image is empty ! error code is : "<<e<<endl;
          }
          else if(e==33){
          cout<<"data size is too big : error code is 33 "<<endl;
          }
          exit(0);

     }

}
coder::~coder(){
    
}
void coder::initialize(){
    for(int x=0;x<image.rows;x++){
         for(int y=0;y<image.cols;y++){
              (image.at<Vec3b>(x,y)[0]%2 ? image.at<Vec3b>(x,y)[0]-=1 : image.at<Vec3b>(x,y)[0]+=0);
              (image.at<Vec3b>(x,y)[1]%2 ? image.at<Vec3b>(x,y)[1]-=1 : image.at<Vec3b>(x,y)[1]+=0);
              (image.at<Vec3b>(x,y)[2]%2 ? image.at<Vec3b>(x,y)[2]-=1 : image.at<Vec3b>(x,y)[2]+=0);
         }
    }


}



Mat& coder::start(){
     initialize();
     int k=0,z=0;
     clock_t start=clock();
     ascii_2_binary(data[z]);
        for(int x=0;x<image.rows;x++){
             for(int y=0;y<image.cols;y++){               
                if(k==9){
                     k=0;
                     z++;
                      if(z==data.size()){
                         goto A;
                         }
                      else{
                      ascii_2_binary(data[z]);
                      
                      }
                }
                else{
                     image.at<Vec3b>(x,y)[0]+=new_data[8-k];
                     image.at<Vec3b>(x,y)[1]+=new_data[7-k];
                     image.at<Vec3b>(x,y)[2]+=new_data[6-k];
                     k+=3;
                }            
                
             }
        
        }
        A:
        cout<<"*******************************************************************"<<endl;
        cout<<"Encoding ended duration :"<<(float(clock()-start)/CLOCKS_PER_SEC)<<endl;
        cout<<"*******************************************************************"<<endl;
        return image;

}

bool summation(){
     int sum=0;
     for(int x=0;x<9;x++){
         sum+=new_data[x];
     }
     if(sum==0){
          return false;
     }
     else{
          return true;
     }
}


void set_zero(){
     new_data[0]=0;new_data[1]=0;new_data[2]=0;new_data[3]=0;new_data[4]=0;
     new_data[5]=0;new_data[6]=0;new_data[7]=0;new_data[8]=0;
}

decoder::decoder(Mat &image){
     this->image=image; 
}
void decoder::start(){
     int u=0;
     data="";
     set_zero();
     clock_t start=clock();
     for(int x=0;x<image.rows;x++ ){
          for(int y=0;y<image.cols;y++){
             if(u==9){
                  u=0;
                  if(!summation()){
                    goto A;
                  }
                  else{
                      data+=binary_2_ascii();
                  }
                  set_zero();
             }
             else{
                 new_data[8-u]=image.at<Vec3b>(x,y)[0]%2;
                 new_data[7-u]=image.at<Vec3b>(x,y)[1]%2;
                 new_data[6-u]=image.at<Vec3b>(x,y)[2]%2;
                 u+=3;
             }
          }
     }
    A:
      cout<<"*******************************************************************"<<endl;
      cout<<"Decoding ended  duration :"<<(float(clock()-start)/CLOCKS_PER_SEC)<<endl;
      cout<<"*******************************************************************"<<endl;
      return;
     
}
void decoder::show(){
     cout<<data;
}

decoder::~decoder(){
 
} 




