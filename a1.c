#include <keypad.h>
#bit C1=0x08.0     //Assigning Columns of Keypad to PORT D
#bit C2=0x08.1
#bit C3=0x08.2
#bit R1=0x08.3    //Assigning the rows of Keypad to PORT D
#bit R2=0x08.4
#bit R3=0x08.5
#bit R4=0x08.6
#bit TRIS_C1=0x88.0                //Setting the TRIS  pins of PORT D
#bit TRIS_C2=0x88.1
#bit TRIS_C3=0x88.2
#bit TRIS_R1=0x88.3
#bit TRIS_R2=0x88.4
#bit TRIS_R3=0x88.5
#bit TRIS_R4=0x88.6
#byte lcd=0x06                        //Assigning LCD to the PORT B
#byte TRIS_lcd=0x86
#bit rs=0x07.0
#bit en=0x07.1
#bit TRIS_rs=0x87.0             //Assigning RS pin to PORT C.0
#bit TRIS_en=0x87.1            //Assigning EN pin to PORT C.1
void lcd_msg(char b,int c);
char keypad();
char a;
void main()
{
TRIS_R1=TRIS_R2=TRIS_R3=TRIS_R4=0;  //Directions to row and col
TRIS_C1=TRIS_C2=TRIS_C3=1;
TRIS_lcd=TRIS_rs=TRIS_en=0;
lcd_msg(0x38,0);                                     //lcd_msg function calling for data/command to lcd
lcd_msg(0x80,0);
lcd_msg(0x0f,0);
   while(TRUE)
   {
     a=keypad();                                      //Taking keypad input to a char variable
     lcd_msg(a,1);
   }

}
char keypad()
{
while(TRUE)
{
     R1=1;                                           //Scanning Process
     R2=R3=R4=0;
     if(C1==1)
     {
     while(C1==1);
     return '1';
     }
     if(C2==1)
     {
     while(C2==1);
     return '2';
     }
     if(C3==1)
     {
     while(C3==1);
     return '3';
     }
     R2=1;
     R1=R3=R4=0;
     if(C1==1)
     {
     while(C1==1);
     return '4';
     }
     if(C2==1)
     {
     while(C2==1);
     return '5';
     }
     if(C3==1)
     {
     while(C3==1);
     return '6';
     }
     R3=1;
     R1=R2=R4=0;
     if(C1==1)
     {
     while(C1==1);
     return '7';
     }
     if(C2==1)
     {
     while(C2==1);
     return '8';
     }
     if(C3==1)
     {
     while(C3==1);
     return '9';
     }
     R4=1;
     R1=R2=R3=0;
     if(C1==1)
     {
     while(C1==1);
     return '*';
     }
     if(C2==1)
     {
     while(C2==1);
     return '0';
     }
     if(C3==1)
     {
     while(C3==1);
     return '#';
     }
}
}
void lcd_msg(char b,int c)                  //LCD command/data sending function
{
lcd=b;
rs=c;
en=1;
delay_ms(20);                                 //calling out delay of 20msec
en=0;
delay_ms(20);
}
