object Form1: TForm1
  Left = 232
  Top = 282
  Width = 764
  Height = 484
  Caption = #1040#1083#1075#1086#1088#1080#1090#1084' RC-5'
  Color = clBtnFace
  Font.Charset = RUSSIAN_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'Times New Roman'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  OnClose = FormClose
  OnCreate = FormCreate
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 15
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 756
    Height = 400
    Align = alTop
    TabOrder = 0
    object Panel2: TPanel
      Left = 1
      Top = 63
      Width = 754
      Height = 336
      Align = alBottom
      TabOrder = 0
      object Splitter1: TSplitter
        Left = 376
        Top = 1
        Width = 4
        Height = 334
        Cursor = crHSplit
        Color = clRed
        ParentColor = False
      end
      object Memo1: TMemo
        Left = 1
        Top = 1
        Width = 375
        Height = 334
        Align = alLeft
        Color = cl3DLight
        ReadOnly = True
        ScrollBars = ssBoth
        TabOrder = 0
      end
      object Memo2: TMemo
        Left = 380
        Top = 1
        Width = 375
        Height = 334
        Align = alLeft
        Color = cl3DLight
        ReadOnly = True
        ScrollBars = ssBoth
        TabOrder = 1
      end
    end
    object Panel4: TPanel
      Left = 1
      Top = 1
      Width = 754
      Height = 64
      Align = alTop
      TabOrder = 1
      object Label1: TLabel
        Left = 1
        Top = 41
        Width = 375
        Height = 22
        Alignment = taCenter
        AutoSize = False
        Caption = #1058#1077#1082#1089#1090' '#1076#1086' '#1096#1080#1092#1088#1086#1074#1082#1080
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clTeal
        Font.Height = -21
        Font.Name = 'Times New Roman'
        Font.Style = [fsItalic]
        ParentFont = False
      end
      object Label3: TLabel
        Left = 379
        Top = 41
        Width = 375
        Height = 22
        Alignment = taCenter
        AutoSize = False
        Caption = #1058#1077#1082#1089#1090' '#1087#1086#1089#1083#1077' '#1096#1080#1092#1088#1086#1074#1082#1080
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clTeal
        Font.Height = -21
        Font.Name = 'Times New Roman'
        Font.Style = [fsItalic]
        ParentFont = False
      end
      object Label2: TLabel
        Left = 360
        Top = 0
        Width = 38
        Height = 15
        Caption = #1050#1051#1070#1063
      end
      object Memo4: TMemo
        Left = 1
        Top = 17
        Width = 752
        Height = 25
        Color = clInactiveCaptionText
        ReadOnly = True
        TabOrder = 0
      end
    end
  end
  object Panel3: TPanel
    Left = 0
    Top = 400
    Width = 756
    Height = 30
    Align = alBottom
    TabOrder = 1
    object ProgressBar1: TProgressBar
      Left = 1
      Top = 0
      Width = 754
      Height = 29
      Align = alBottom
      Min = 0
      Max = 100
      Smooth = True
      TabOrder = 0
    end
  end
  object MainMenu1: TMainMenu
    Left = 32
    Top = 352
    object FileMM: TMenuItem
      Caption = #1060#1072#1081#1083
      object OpenMM: TMenuItem
        Caption = #1054#1090#1082#1088#1099#1090#1100
        OnClick = OpenMMClick
      end
      object ExitMM: TMenuItem
        Caption = #1042#1099#1093#1086#1076
        OnClick = ExitMMClick
      end
    end
    object CodMM: TMenuItem
      Caption = #1064#1080#1092#1088#1086#1074#1072#1085#1080#1077
      object CodingMM: TMenuItem
        Caption = #1047#1072#1096#1080#1092#1088#1086#1074#1072#1090#1100
        OnClick = CodingMMClick
      end
      object RecodingMM: TMenuItem
        Caption = #1056#1072#1089#1096#1080#1092#1088#1086#1074#1072#1090#1100
        OnClick = RecodingMMClick
      end
      object ParamsMM: TMenuItem
        Caption = #1055#1072#1088#1072#1084#1077#1090#1088#1099
        OnClick = ParamsMMClick
      end
    end
    object AboutMM: TMenuItem
      Caption = 'About'
      OnClick = AboutMMClick
    end
  end
  object OpenDialog1: TOpenDialog
    Filter = '|*.txt||*.h'
    Left = 8
    Top = 352
  end
end
