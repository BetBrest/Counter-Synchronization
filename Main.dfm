object Form1: TForm1
  Left = 274
  Top = 215
  Width = 1280
  Height = 477
  Caption = #1055#1088#1086#1075#1088#1072#1084#1084#1072' '#1089#1080#1085#1093#1088#1086#1085#1080#1079#1072#1094#1080#1080' '#1076#1072#1090#1099'/'#1074#1088#1077#1084#1077#1085#1080' '#1089#1095#1077#1090#1095#1080#1082#1072' '#1057#1054#1052
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -10
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 33
    Top = 85
    Width = 248
    Height = 32
    Caption = #1042#1088#1077#1084#1103' '#1082#1086#1084#1087#1100#1102#1090#1077#1088#1072
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -27
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 33
    Top = 124
    Width = 210
    Height = 32
    Caption = #1044#1072#1090#1072' '#1082#1086#1084#1087#1100#1090#1077#1088#1072
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -27
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object ComLed1: TComLed
    Left = 162
    Top = 42
    Width = 20
    Height = 20
    LedSignal = lsConn
    Kind = lkRedLight
  end
  object Edit1: TEdit
    Left = 280
    Top = 91
    Width = 124
    Height = 21
    TabOrder = 0
  end
  object Edit2: TEdit
    Left = 280
    Top = 130
    Width = 124
    Height = 21
    TabOrder = 1
  end
  object Button1: TButton
    Left = 437
    Top = 92
    Width = 92
    Height = 29
    Caption = #1054#1090#1082#1088#1099#1090#1100' '#1087#1086#1088#1090
    TabOrder = 2
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 416
    Top = 160
    Width = 121
    Height = 25
    Caption = #1055#1086#1089#1083#1072#1090#1100' '#1089#1090#1088#1086#1082#1091
    TabOrder = 3
    OnClick = Button2Click
  end
  object Edit3: TEdit
    Left = 176
    Top = 160
    Width = 217
    Height = 21
    TabOrder = 4
  end
  object Button3: TButton
    Left = 416
    Top = 200
    Width = 129
    Height = 25
    Caption = #1057#1095#1080#1090#1072#1090#1100'  '#1074#1088#1077#1084#1103
    TabOrder = 5
    OnClick = Button3Click
  end
  object Timer1: TTimer
    Enabled = False
    OnTimer = Timer1Timer
    Left = 784
    Top = 40
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
    Top = 40
  end
end
