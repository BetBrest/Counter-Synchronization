//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

//TDateTime Time_comp = DateTimePicker1->DateTime.FormatString("dd.mm.yyyy");;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button1Click(TObject *Sender)
{

extern PACKAGE System::TDateTime __fastcall Now(void);
Edit1->Text = FormatDateTime("hh:nn:ss", Time());
Edit2->Text = FormatDateTime("dd.mm.yyyy", Date());
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
Button1->Click();
}
//---------------------------------------------------------------------------

