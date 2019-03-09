#include "functions.cpp"



int main(){
  
cout<<" ######                                                          "<<endl;      
cout<<" #     #  ####  #####  ###### #####  ##### ##### # #    #  ####  "<<endl;
cout<<" #     # #    # #    # #      #    #   #     #   # ##   # #    #"<<endl;
cout<<" ######  #    # #####  #####  #    #   #     #   # # #  # #    # "<<endl;
cout<<" #   #   #    # #    # #      #####    #     #   # #  # # #    #"<<endl; 
cout<<" #    #  #    # #    # #      #   #    #     #   # #   ## #    #"<<endl;
cout<<" #     #  ####  #####  ###### #    #   #     #   # #    #  ####  "<<endl;
cout<<"     Steganography Tool Coded By ___Kamaladdin Ahmadzada___ "<<endl;
cout<<endl;
 Mat img=imread("/home/joe/Desktop/xxx.jpg");

 Mat image;
 //Secret data that will be hided in image
string text="Today we have to meet at 9_pm in Russia\nDo not forget to get nuclear weapons ! \nBoss wants to see new things Be carefull \nWe also have some documents you may interested  \nHere is special password  for communication :\n20829348mskdfsmvn23312ea\nejwkeqjwe3898394923429342\ndjkjfsdnfbn23333333333\n1111111111112222222222\n333333333333333\n3434235340894834928374583479\n31029120391039103190140859343\nDo not forget to bring required documents ! \n";
//Coder initialization 
coder b(text,img);
image=b.start();
imwrite("/home/joe/Desktop/dec.png",image);

//Decoder initialization
img=imread("/home/joe/Desktop/dec.png");
decoder a(img);
a.start();
a.show();


}