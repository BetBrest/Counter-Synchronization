//---------------------------------------------------------------------------

#ifndef MainH
#define MainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include "CPort.hpp"
#include "CPortCtl.hpp"
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TLabel *Label2;
        TEdit *Edit1;
        TEdit *Edit2;
        TTimer *Timer1;
        TComPort *ComPort1;
        TButton *Button1;
        TButton *Button2;
        TButton *Button3;
        TEdit *Edit4;
        TEdit *Edit5;
        TLabel *Label3;
        TLabel *Label4;
        TEdit *Edit6;
        TEdit *Edit7;
        TLabel *Label5;
        TButton *Button4;
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Timer1Timer(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall ComPort1RxChar(TObject *Sender, int Count);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall Button4Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
         //void packet_parsing(unsigned char*, int );
        __fastcall TForm1(TComponent* Owner);

        void __fastcall packet_parsing(unsigned char*, int);
        char* MakeCRC(char*);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
