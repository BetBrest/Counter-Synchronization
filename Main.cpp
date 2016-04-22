//---------------------------------------------------------------------------

#include <vcl.h>
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
     if (Button1->Caption == "������� ����" )
    // ShowMessage("������� ����");
    // ShowMessage("������� ����");
     Button1->Caption = "������� ����";
     else
     ShowMessage("���� ��� �����");
   }
  else
   { ComPort1->Open();
     ComPort1->ShowSetupDialog();
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
     ShowMessage("������������ �������");
     new_paket = true; return;
     }

     ComPort1->Read(&work_buffer[read_byte], Count);

     read_byte+=Count;

     if (read_byte==9)   // answer on request
     {
     memcpy(&in_buffer[0],&work_buffer[0],read_byte);
     packet_parsing(&in_buffer[0],read_byte);
     new_paket =true;

     ShowMessage("�����  ������");
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
TDateTime CounterTime;

//Get Time/Date Counter
AnsiString sec=IntToHex(s[0],2);
AnsiString min=IntToHex(s[1],2);
AnsiString hour=IntToHex(s[2],2);
AnsiString day=IntToHex(s[4],2);
AnsiString month=IntToHex(s[5],2);
AnsiString year=IntToHex(s[6],2);

//CounterTime.;
//settings.ShortDateFormat = "mmddyy";
//AnsiString ss=/*hour + ":" + min + ":" + sec + " " ;//+ */day+ "-"  + month + "-" + year;
//ShortDateFormat = "dd-mm-yy";
ShortDateFormat = "dd.mm.yyyy";// - ������� ������ ����
ShortTimeFormat = "hh:mm:ss";
AnsiString ss;
   
 ss = day+ "."  + month + "." + year;
  // CounterTime = StrToDateTime(ss);
CounterTime=StrToDate(ss);


 ss = hour + ":" + min + ":" + sec;
 CounterTime = StrToTime(ss);
 ShowMessage(CounterTime);

 /*ss = day+ "."  + month + "." + year;
  // CounterTime = StrToDateTime(ss);
CounterTime=StrToDate(ss);   */

    Edit4->Text=CounterTime.TimeString();
    Edit5->Text=CounterTime.DateString();
//ShowMessage(CounterTime);

}
