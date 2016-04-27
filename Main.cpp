//---------------------------------------------------------------------------

#include <vcl.h>
#include <DateUtils.hpp>
#pragma hdrstop

#include "Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CPort"
#pragma link "CPortCtl"
#pragma resource "*.dfm"
TForm1 *Form1;
AnsiString dir;
bool new_paket=true;
unsigned int read_byte;
unsigned int number;
unsigned char in_buffer[256], out_buffer[256],work_buffer[256];
unsigned char ReadTime[] ={0xb9, 0x20, 0x00, 0x00, 0x00, 0x47 } ;
unsigned char WriteTime[] ={0xb9, 0x20, 0x00, 0x00, 0x00, 0x47 } ;

//TDateTime Time_comp = DateTimePicker1->DateTime.FormatString("dd.mm.yyyy");;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button1Click(TObject *Sender)
{


//extern PACKAGE System::TDateTime __fastcall Now(void);

if (ComPort1->Connected)
   {
     ComPort1->Close();
     if (Button1->Caption == "������� ����" )
    // ShowMessage("������� ����");
    // ShowMessage("������� ����");
     Button1->Caption = "������� ����";
     else
     ShowMessage("���� ��� �����");
   }
  else
   {
     ComPort1->ShowSetupDialog();  ComPort1->Open();
     dir = GetCurrentDir();
     ComPort1->StoreSettings(stIniFile, dir + "\\PortSettings.ini");
     Button1->Caption="������� ����" ;

   }


}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
Edit1->Text = FormatDateTime("hh:nn:ss", Time());
Edit2->Text = FormatDateTime("dd.mm.yyyy", Date());
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Button2Click(TObject *Sender)   //Write time in counter
{
   // Make write packet
 Word Year, Month, Day, Hour, Min, Sec, MSec;
  TDateTime dtPresent = Now();
  DecodeDate(dtPresent, Year, Month, Day);


WriteTime[1]=My_IntToHex(Day) ;
WriteTime[2]=Month;
WriteTime[3]=Year ;


//ComPort1->Write(Edit3->Text) ;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::ComPort1RxChar(TObject *Sender, int Count)
{
     if (new_paket==true)
     {
     new_paket =false;
     read_byte=0;
     }

     if ((read_byte+Count)>20)
     {
     ComPort1->ClearBuffer(true, true);
     ShowMessage("������������ �������");
     new_paket = true; return;
     }

     ComPort1->Read(&work_buffer[read_byte], Count);

     read_byte+=Count;

     if (read_byte==9)   // answer on request
     {
     if(work_buffer[7]==0x89)
     {
     //ShowMessage("�����  ������ 89");
      if(MakeCRC(work_buffer,8)==work_buffer[8])
        {
         //ShowMessage(MakeCRC(work_buffer,8));
         memcpy(&in_buffer[0],&work_buffer[0],read_byte);
         packet_parsing(&in_buffer[0],read_byte);
         new_paket =true;
        }
        else  ShowMessage("������������ ����������� ����� ������");
      }
      else ShowMessage("������������ ������ ������");
     //ShowMessage("�����  ������");
     }
      


}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
    // AnsiString s= ReadTime[0]+ReadTime[1];
   // ShowMessage(s);
     ComPort1->Write(ReadTime,6) ;
}
//---------------------------------------------------------------------------






void __fastcall TForm1::packet_parsing(unsigned char* s, int d)
 {
 TDateTime CounterTime,Time_now ;


 //Get Time/Date Counter
 AnsiString sec=IntToHex(s[0],2);
 AnsiString min=IntToHex(s[1],2);
 AnsiString hour=IntToHex(s[2],2);
 AnsiString day=IntToHex(s[4],2);
 AnsiString month=IntToHex(s[5],2);
 AnsiString year=IntToHex(s[6],2);

 AnsiString ss;

 ss = day+ "."  + month + "." + year + " " + hour + ":" + min + ":" + sec;
 CounterTime=StrToDateTime(ss);

 Edit4->Text=CounterTime.TimeString();
 Edit5->Text=CounterTime.DateString();


 //double difference=Time_now.CurrentDateTime() - CounterTime ;
  //Edit6->Text=difference;
Edit7->Text =  FloatToStr(DaysBetween(Time_now.CurrentDateTime(), CounterTime))  ;
Edit6->Text =  FloatToStr(SecondsBetween(Time_now.CurrentDateTime(), CounterTime))  ;

Edit1->Text = FormatDateTime("hh:nn:ss", Time());
Edit2->Text = FormatDateTime("dd.mm.yyyy", Date());
//ShowMessage(CounterTime);

}
void __fastcall TForm1::Button4Click(TObject *Sender)
{
unsigned char test[9] = {0x12,0x00,0x22,0x15,0x22,0x02,0x16,0x89,0x23};
     //  delete []test;
//unsigned char test[1] = {0x0a};

Form1->packet_parsing(test,9); //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!�������
  char *Data; int Result;                                       // Declare two strings

  // Data = "0A";
  Result = MakeCRC(test,9);

 ShowMessage(Result);        // Calculate CRC


}
//---------------------------------------------------------------------------


unsigned int TForm1::MakeCRC(char *HexString, int SizeHexString)
{

   static char Res[9];                                 // CRC Result
   unsigned int Result;
   char CRC[8];
   int  i,j;
   char DoInvert;
   int SizeBitString=SizeHexString*8;
   char BitString[256];
   Byte Byte_1;


    for(i=0; i<SizeHexString; i++)
    {
      Byte_1=HexString[i];
      for(j=0; j<8; j++)

      {
        if((Byte_1 & 1 << j) == 0)
        BitString[7-j+i*8]=0;
        else
        BitString[7-j+i*8]=1;
      }

      // ShowMessage(BitString);


     }


   for (i=0; i<8; ++i)  CRC[i] = 0;                    // Init before calculation

   for (i=0; i<SizeBitString; ++i)
      {
      DoInvert = (1==BitString[i]) ^ CRC[7];         // XOR required?

      CRC[7] = CRC[6];
      CRC[6] = CRC[5];
      CRC[5] = CRC[4] ^ DoInvert;
      CRC[4] = CRC[3] ^ DoInvert;
      CRC[3] = CRC[2];
      CRC[2] = CRC[1];
      CRC[1] = CRC[0];
      CRC[0] = DoInvert;
      }
      
   for (i=0; i<8; ++i)  Res[7-i] = CRC[i] ? '1' : '0'; // Convert binary to ASCII
   Res[8] = 0;                                         // Set string terminator


  // return(Res);

   Result= My_BinToHex(Res) ;
   return(Result);

}

unsigned int TForm1::My_BinToHex(AnsiString Data)
{
 // ���������� �����, ���� �� ���� �������...
   char *Bin=new char[65];
   char *Hex=new char[17];
unsigned   char answer;
   int tmp;
   //    ������� �������� �����:
   // (11111010101 bin == 7D5 hex == 2005 dec)
   strcpy(Bin, Data.c_str());
   //     �������       long strtol(const char *s, char **endptr, int radix)
   // ��������� ������   s   � ��������� ������� ���������, ����������
   // ����� ���������   radix   � ����������� �� � ������� ����� ��������,
   // ������ � ����������
   tmp=strtol(Bin, NULL, 2);
   //     �������       char * ltoa(long value, char * string, int radix)
   // ��������� ������� ����� ��������   value   � ����������� � ���������
   // ������� ���������, ����������� ������������� ��������   radix,
   // ������� ��������� � ASCIIZ-������   string
   ltoa(tmp, Hex, 16);
  // ShowMessage(AnsiString(Hex)); // ��, ��� � ���������... %)
   // ��������� �� ��� ���!!!
   char tmp1[4] = "0x";
   strcat(tmp1, Hex);
 
    answer=StrToInt(tmp1);
   delete []Bin;
   delete []Hex;
   return answer;
 //

}

unsigned char TForm1::My_IntToHex(int Word2)
{
unsigned   char answer;
 char tmp1[4] = "0x";
 // char tmp2[1];
 // tmp2[0] =Word2;
 //strcat(tmp1, tmp2);
   tmp1[2]=Word2;
   tmp1[3]=0;
 answer=StrToInt(tmp1);
  return answer;

 }


