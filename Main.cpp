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
//Form1->ComLed1->State=True;
}
//---------------------------------------------------------------------------


