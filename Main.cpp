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
     if (Button1->Caption == "Закрыть порт" )
    // ShowMessage("Закрыли порт");
    // ShowMessage("Закрыли порт");
     Button1->Caption = "Открыть порт";
     else
     ShowMessage("Порт уже окрыт");
   }
  else
   {
     ComPort1->ShowSetupDialog();  ComPort1->Open();
     dir = GetCurrentDir();
     ComPort1->StoreSettings(stIniFile, dir + "\\PortSettings.ini");
     Button1->Caption="Закрыть порт" ;

   }


}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
Edit1->Text = FormatDateTime("hh:nn:ss", Time());
Edit2->Text = FormatDateTime("dd.mm.yyyy", Date());
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Button2Click(TObject *Sender)
{
//ComPort1->WriteStr(Edit3->Text) ;
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
     ShowMessage("Переполнение буффера");
     new_paket = true; return;
     }

     ComPort1->Read(&work_buffer[read_byte], Count);

     read_byte+=Count;

     if (read_byte==9)   // answer on request
     {
     memcpy(&in_buffer[0],&work_buffer[0],read_byte);
     packet_parsing(&in_buffer[0],read_byte);
     new_paket =true;

     //ShowMessage("Пакет  принят");
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
;

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

Form1->packet_parsing(test,9); //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!вернуть
  char *Data, *Result;                                       // Declare two strings

  // Data = "0A";
  Result = MakeCRC(test,9);

 ShowMessage(My_BinToHex(Result));        // Calculate CRC


}
//---------------------------------------------------------------------------


char* TForm1::MakeCRC(char *HexString, int SizeHexString)
{

   static char Res[9];                                 // CRC Result
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

   return(Res);

}

AnsiString TForm1::My_BinToHex(AnsiString Data)
{
 // Подготовим места, чтоб на всех хватило...
   char *Bin=new char[65];
   char *Hex=new char[17];
   int tmp;
   //    Зададим двоичное число:
   // (11111010101 bin == 7D5 hex == 2005 dec)
   strcpy(Bin, Data.c_str());
   //     Функция       long strtol(const char *s, char **endptr, int radix)
   // принимает строку   s   в основании системы счисления, задаваемой
   // целым значением   radix   и преобразует ее в длинное целое значение,
   // котрое и возвращает
   tmp=strtol(Bin, NULL, 2);
   //     Функция       char * ltoa(long value, char * string, int radix)
   // принимает длинное целое значение   value   и преобразует к основанию
   // системы счисления, задаваемому целочисленным значеним   radix,
   // помещая результат в ASCIIZ-строку   string
   ltoa(tmp, Hex, 16);
  // ShowMessage(AnsiString(Hex)); // Ну, вот и результат... %)
   // Почистить на фиг все!!!
   delete []Bin;

   return Hex;
 //  delete []Hex;

}
