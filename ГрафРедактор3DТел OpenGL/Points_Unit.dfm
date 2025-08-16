object Frm_Points: TFrm_Points
  Left = 452
  Top = 325
  BorderStyle = bsDialog
  Caption = #1047#1072#1076#1072#1090#1100' '#1090#1086#1095#1082#1091
  ClientHeight = 145
  ClientWidth = 141
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object GrBx_Rasmer: TGroupBox
    Left = 0
    Top = 0
    Width = 141
    Height = 113
    Align = alTop
    TabOrder = 0
    object Label1: TLabel
      Left = 6
      Top = 16
      Width = 7
      Height = 13
      Caption = 'X'
    end
    object Label2: TLabel
      Left = 6
      Top = 48
      Width = 7
      Height = 13
      Caption = 'Y'
    end
    object Label3: TLabel
      Left = 6
      Top = 80
      Width = 7
      Height = 13
      Caption = 'Z'
    end
    object Ed_PointsZ: TEdit
      Left = 30
      Top = 76
      Width = 70
      Height = 21
      MaxLength = 10
      TabOrder = 2
      Text = '0'
      OnKeyPress = Ed_PointsXKeyPress
    end
    object Ed_PointsY: TEdit
      Left = 30
      Top = 44
      Width = 70
      Height = 21
      MaxLength = 10
      TabOrder = 1
      Text = '0'
      OnKeyPress = Ed_PointsXKeyPress
    end
    object Ed_PointsX: TEdit
      Left = 30
      Top = 12
      Width = 70
      Height = 21
      MaxLength = 10
      TabOrder = 0
      Text = '0'
      OnKeyPress = Ed_PointsXKeyPress
    end
    object UpDown1: TUpDown
      Left = 100
      Top = 12
      Width = 15
      Height = 21
      Associate = Ed_PointsX
      Min = -600
      Max = 600
      Position = 0
      TabOrder = 3
      Wrap = False
      OnClick = UpDown1Click
    end
    object UpDown2: TUpDown
      Left = 100
      Top = 44
      Width = 15
      Height = 21
      Associate = Ed_PointsY
      Min = -600
      Max = 600
      Position = 0
      TabOrder = 4
      Wrap = False
      OnClick = UpDown1Click
    end
    object UpDown3: TUpDown
      Left = 100
      Top = 76
      Width = 15
      Height = 21
      Associate = Ed_PointsZ
      Min = -600
      Max = 600
      Position = 0
      TabOrder = 5
      Wrap = False
      OnClick = UpDown1Click
    end
  end
  object Btn_Points_Ok: TButton
    Left = 7
    Top = 120
    Width = 60
    Height = 20
    Caption = #1044#1072
    ModalResult = 1
    TabOrder = 1
  end
  object Btn_Points_No: TButton
    Left = 74
    Top = 120
    Width = 60
    Height = 20
    Caption = #1053#1077#1090
    ModalResult = 7
    TabOrder = 2
  end
end
