object Form1: TForm1
  Left = 281
  Top = 212
  Width = 858
  Height = 359
  Caption = #1055#1088#1086#1075#1088#1072#1084#1084#1072' '#1089#1080#1085#1093#1088#1086#1085#1080#1079#1072#1094#1080#1080' '#1076#1072#1090#1099'/'#1074#1088#1077#1084#1077#1085#1080' '#1089#1095#1077#1090#1095#1080#1082#1072' '#1057#1054#1052'-'#1069'1.1'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -14
  Font.Name = 'MS Sans Serif'
  Font.Style = [fsBold]
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 120
  TextHeight = 16
  object Label1: TLabel
    Left = 30
    Top = 105
    Width = 95
    Height = 32
    Caption = #1042#1088#1077#1084#1103' '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -28
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label2: TLabel
    Left = 50
    Top = 153
    Width = 69
    Height = 32
    Caption = #1044#1072#1090#1072
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -28
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label3: TLabel
    Left = 196
    Top = 79
    Width = 92
    Height = 16
    Caption = #1050#1086#1084#1087#1100#1102#1090#1077#1088#1072
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label4: TLabel
    Left = 383
    Top = 79
    Width = 72
    Height = 16
    Caption = #1057#1095#1077#1090#1095#1080#1082#1072
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label5: TLabel
    Left = 551
    Top = 89
    Width = 88
    Height = 16
    Caption = #1056#1072#1089#1089#1090#1088#1086#1081#1082#1072
  end
  object Edit1: TEdit
    Left = 177
    Top = 112
    Width = 152
    Height = 21
    TabOrder = 0
  end
  object Edit2: TEdit
    Left = 177
    Top = 160
    Width = 152
    Height = 21
    TabOrder = 1
  end
  object Button1: TButton
    Left = 327
    Top = 16
    Width = 178
    Height = 49
    Caption = #1053#1072#1089#1090#1088#1086#1081#1082#1080' COM '#1087#1086#1088#1090#1072
    TabOrder = 2
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 528
    Top = 196
    Width = 159
    Height = 31
    Caption = #1047#1072#1087#1080#1089#1072#1090#1100' '#1074#1088#1077#1084#1103
    TabOrder = 3
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 176
    Top = 197
    Width = 159
    Height = 31
    Caption = #1057#1095#1080#1090#1072#1090#1100'  '#1074#1088#1077#1084#1103
    TabOrder = 4
    OnClick = Button3Click
  end
  object Edit4: TEdit
    Left = 344
    Top = 108
    Width = 149
    Height = 21
    TabOrder = 5
  end
  object Edit5: TEdit
    Left = 344
    Top = 158
    Width = 149
    Height = 21
    TabOrder = 6
  end
  object Edit6: TEdit
    Left = 531
    Top = 108
    Width = 149
    Height = 21
    TabOrder = 7
  end
  object Edit7: TEdit
    Left = 531
    Top = 158
    Width = 149
    Height = 21
    TabOrder = 8
  end
  object Timer1: TTimer
    Enabled = False
    Interval = 100
    OnTimer = Timer1Timer
    Left = 56
    Top = 16
  end
  object ComPort1: TComPort
    BaudRate = br9600
    Port = 'COM1'
    Parity.Bits = prNone
    StopBits = sbOneStopBit
    DataBits = dbEight
    Events = [evRxChar, evTxEmpty, evRxFlag, evRing, evBreak, evCTS, evDSR, evError, evRLSD, evRx80Full]
    FlowControl.OutCTSFlow = False
    FlowControl.OutDSRFlow = False
    FlowControl.ControlDTR = dtrDisable
    FlowControl.ControlRTS = rtsDisable
    FlowControl.XonXoffOut = False
    FlowControl.XonXoffIn = False
    StoredProps = [spBasic]
    TriggersOnRxChar = True
    OnRxChar = ComPort1RxChar
    Left = 104
    Top = 16
  end
end
