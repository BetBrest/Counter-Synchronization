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
unsigned int number;
unsigned char Mas[256];
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
   { ComPort1->Open();
     ComPort1->ShowSetupDialog();
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
ComPort1->WriteStr(Edit3->Text) ;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::ComPort1RxChar(TObject *Sender, int Count)
{
      ComPort1->Read(&Mas[number], Count);

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
    // AnsiString s= ReadTime[0]+ReadTime[1];
   // ShowMessage(s);
     ComPort1->Write(ReadTime,6) ;
}
//---------------------------------------------------------------------------

