//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
  HWND hwndMain,hwnd1,hwnd2,hwnd3,hwnd4,hwnd5,hwnd6,hwnd7;

  if(!(hwndMain = FindWindow( "Afx:400000:b:10013:6:1ec0227","Программа настройки электросчетчиков")))
         {  ShowMessage("Программа настройки электросчетчиков не открыта. Откройте программу параметризации и попробуйте еще раз!");
         // fprintf(f, "%s Ошибка занесения частоты. Программа параметризации приборов учета СЭО6005 не открыта. \n", TimeToStr(Now()));
         }
          else
         {
           if(!(hwnd1 =FindWindowEx(hwndMain,NULL,"#32770",NULL) ))
         {  ShowMessage("Откройте 1 и повторите попытку");
          // fprintf(f, "%s Ошибка занесения частоты. <Окно параметров > не открыто. \n", TimeToStr(Now()));
         }

         if(!(hwnd2 =FindWindowEx(hwnd1,NULL,"Button","Чтение") ))
        {  ShowMessage("Откройте  2 и повторите попытку");
          // fprintf(f, "%s Ошибка занесения частоты. <Окно параметров > не открыто. \n", TimeToStr(Now()));
         }
         else
         ShowMessage("Кнопка нажата");
          int i=0;
         GetMessage((HWND)hwnd2,BM_CLICK,0,0)   ;


     //  ShowMessage( IsButtonChecked(HWND hdlg, int idButton))  ;
  /*
             BOOL bRet;
       MSG msg;
       int iii;
       while( 1)
{ bRet = GetMessage( &msg, hwnd2, 0, 0 );

   Memo1->Text=msg.message;
   Sleep(1000);

 }
{
    if (bRet == -1)
    {
        // handle the error and possibly exit
    }
    else
    {
      TranslateMessage(&msg);
       DispatchMessage(&msg);

        //ShowMessage(msg.message );
    }
}                                   */
     //   SendMessage((HWND)hwnd7,WM_SETTEXT,(WPARAM)NULL,(LPARAM)(LPCTSTR)onedit.c_str())  ;
        SendMessage((HWND)hwnd2,BM_CLICK,0,0);   // посылаем  нажатие enter


     }
}
//---------------------------------------------------------------------------
