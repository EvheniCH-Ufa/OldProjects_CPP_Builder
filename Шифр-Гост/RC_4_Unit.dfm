object Form1: TForm1
  Left = 242
  Top = 178
  Width = 708
  Height = 480
  Caption = 'Form1'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 129
    Width = 700
    Height = 317
    Align = alClient
    Caption = 'Panel1'
    TabOrder = 0
    object Splitter1: TSplitter
      Left = 349
      Top = 1
      Width = 3
      Height = 315
      Cursor = crHSplit
    end
    object DO_Memo: TMemo
      Left = 1
      Top = 1
      Width = 348
      Height = 315
      Align = alLeft
      ScrollBars = ssBoth
      TabOrder = 0
    end
    object Posle_Memo: TMemo
      Left = 352
      Top = 1
      Width = 348
      Height = 315
      Align = alLeft
      ScrollBars = ssBoth
      TabOrder = 1
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 0
    Width = 700
    Height = 129
    Align = alTop
    TabOrder = 1
    object Label1: TLabel
      Left = 328
      Top = 48
      Width = 26
      Height = 13
      Caption = #1050#1083#1102#1095
    end
    object Label2: TLabel
      Left = 128
      Top = 104
      Width = 100
      Height = 13
      Caption = #1058#1077#1082#1089#1090' '#1076#1086' '#1096#1080#1092#1088#1086#1074#1082#1080
    end
    object Label3: TLabel
      Left = 448
      Top = 104
      Width = 118
      Height = 13
      Caption = #1058#1077#1082#1089#1090' '#1087#1086#1089#1083#1077' '#1096#1080#1092#1088#1086#1074#1082#1080
    end
    object Key_Edit: TEdit
      Left = 0
      Top = 72
      Width = 697
      Height = 21
      MaxLength = 32
      TabOrder = 0
      Text = 'as28zw37q8397342ui238e2twqm2ewp1'
    end
    object Open_Btn: TButton
      Left = 80
      Top = 0
      Width = 75
      Height = 25
      Caption = #1054#1090#1082#1088#1099#1090#1100
      TabOrder = 1
      OnClick = Open_BtnClick
    end
    object Cod_Btn: TButton
      Left = 192
      Top = 0
      Width = 97
      Height = 25
      Caption = #1047#1072#1096#1080#1092#1088#1086#1074#1072#1090#1100
      TabOrder = 2
      OnClick = Cod_BtnClick
    end
    object Recod_Btn: TButton
      Left = 312
      Top = 0
      Width = 97
      Height = 25
      Caption = #1056#1072#1089#1096#1080#1092#1088#1086#1074#1072#1090#1100
      TabOrder = 3
      OnClick = Recod_BtnClick
    end
  end
  object OpenDialog1: TOpenDialog
    Left = 80
    Top = 360
  end
end
