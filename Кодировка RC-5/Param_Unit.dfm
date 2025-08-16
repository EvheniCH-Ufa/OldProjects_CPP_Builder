object Param_Frm: TParam_Frm
  Left = 377
  Top = 172
  AutoSize = True
  BorderStyle = bsDialog
  Caption = #1055#1072#1088#1072#1084#1077#1090#1088#1099
  ClientHeight = 181
  ClientWidth = 216
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
  object GroupBox2: TGroupBox
    Left = 0
    Top = 0
    Width = 216
    Height = 137
    Align = alTop
    Caption = #1055#1072#1088#1072#1084#1077#1090#1088#1099' '#1082#1086#1076#1080#1088#1086#1074#1072#1085#1080#1103
    Ctl3D = True
    ParentCtl3D = False
    TabOrder = 0
    object LblKolRaunds: TLabel
      Left = 12
      Top = 88
      Width = 103
      Height = 13
      Caption = #1050#1086#1083#1080#1095#1077#1089#1090#1074#1086' '#1088#1072#1091#1085#1076#1086#1074
    end
    object LblSizeBloks: TLabel
      Left = 29
      Top = 64
      Width = 122
      Height = 13
      Caption = #1056#1072#1079#1084#1077#1088' '#1073#1083#1086#1082#1072' = 64 '#1073#1080#1090#1072
    end
    object Label1: TLabel
      Left = 16
      Top = 16
      Width = 116
      Height = 13
      Caption = #1050#1083#1102#1095' '#1076#1083#1103' '#1082#1086#1076#1080#1088#1086#1074#1072#1085#1080#1103
    end
    object EdKey: TEdit
      Left = 13
      Top = 36
      Width = 188
      Height = 21
      Ctl3D = True
      ParentCtl3D = False
      TabOrder = 2
      Text = #1057#1091#1087#1077#1088#1050#1083#1102#1095
    end
    object EdKolRaunds: TEdit
      Left = 13
      Top = 104
      Width = 172
      Height = 21
      Ctl3D = True
      ParentCtl3D = False
      TabOrder = 0
      Text = '10'
    end
    object UpDown1: TUpDown
      Left = 185
      Top = 104
      Width = 16
      Height = 21
      Associate = EdKolRaunds
      Min = 6
      Max = 64
      Position = 10
      TabOrder = 1
      Wrap = True
    end
  end
  object Panel1: TPanel
    Left = 0
    Top = 136
    Width = 216
    Height = 45
    TabOrder = 1
    object Button1: TButton
      Left = 20
      Top = 16
      Width = 75
      Height = 25
      Caption = #1044#1072
      ModalResult = 1
      TabOrder = 0
      OnClick = Button1Click
    end
    object Button2: TButton
      Left = 118
      Top = 16
      Width = 75
      Height = 25
      Caption = #1054#1090#1084#1077#1085#1072
      ModalResult = 2
      TabOrder = 1
      OnClick = Button2Click
    end
  end
end
