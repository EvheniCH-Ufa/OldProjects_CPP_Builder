object Form1: TForm1
  Left = 361
  Top = 264
  Width = 313
  Height = 201
  Caption = #1048#1075#1088#1072': '#1050#1088#1077#1089#1090#1080#1082#1080' - '#1085#1086#1083#1080#1082#1080
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Visible = True
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Image1: TImage
    Left = 8
    Top = 8
    Width = 149
    Height = 149
    OnMouseDown = Image1MouseDown
  end
  object Label1: TLabel
    Left = 176
    Top = 104
    Width = 32
    Height = 13
    Caption = 'Label1'
  end
  object NewGame_Btn: TButton
    Left = 168
    Top = 8
    Width = 125
    Height = 25
    Caption = #1053#1086#1074#1072#1103' '#1080#1075#1088#1072
    TabOrder = 0
    OnClick = NewGame_BtnClick
  end
  object Komp1_Btn: TButton
    Left = 168
    Top = 64
    Width = 125
    Height = 25
    Caption = '1-'#1081' '#1093#1086#1076#1080#1090' '#1082#1086#1084#1087#1100#1102#1090#1077#1088
    TabOrder = 1
    OnClick = Komp1_BtnClick
  end
  object Exit_Btn: TButton
    Left = 168
    Top = 128
    Width = 125
    Height = 25
    Caption = #1042#1099#1093#1086#1076
    TabOrder = 2
    OnClick = Exit_BtnClick
  end
  object TreeView1: TTreeView
    Left = 312
    Top = 8
    Width = 497
    Height = 149
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Courier New'
    Font.Style = []
    Indent = 19
    ParentFont = False
    TabOrder = 3
    Visible = False
  end
end
