object Basic_Form: TBasic_Form
  Left = 639
  Top = 151
  BorderStyle = bsDialog
  Caption = 'Basic_Form'
  ClientHeight = 500
  ClientWidth = 274
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCanResize = FormCanResize
  OnCreate = FormCreate
  OnShow = FormShow
  DesignSize = (
    274
    500)
  PixelsPerInch = 96
  TextHeight = 13
  object GrBx_Param: TGroupBox
    Left = 2
    Top = 56
    Width = 273
    Height = 441
    Anchors = []
    Caption = #1055#1072#1088#1072#1084#1077#1090#1088#1099
    TabOrder = 0
    DesignSize = (
      273
      441)
    object Label10: TLabel
      Left = 8
      Top = 328
      Width = 72
      Height = 13
      Caption = #1055#1088#1086#1079#1088#1072#1095#1085#1086#1089#1090#1100
    end
    object Label11: TLabel
      Left = 104
      Top = 328
      Width = 12
      Height = 13
      Caption = 'Ks'
    end
    object Label12: TLabel
      Left = 160
      Top = 328
      Width = 13
      Height = 13
      Caption = 'Kd'
    end
    object Label13: TLabel
      Left = 232
      Top = 328
      Width = 9
      Height = 13
      Caption = 'Kl'
    end
    object Label14: TLabel
      Left = 8
      Top = 392
      Width = 8
      Height = 13
      Caption = 'N'
    end
    object Pnl_ElipsParam: TPanel
      Left = 2
      Top = 55
      Width = 269
      Height = 40
      Align = alTop
      Anchors = []
      TabOrder = 2
      Visible = False
      DesignSize = (
        269
        40)
      object Lbl_Elips_c: TLabel
        Left = 174
        Top = 12
        Width = 18
        Height = 13
        Anchors = []
        Caption = 'c = '
      end
      object Lbl_Elips_b: TLabel
        Left = 94
        Top = 12
        Width = 18
        Height = 13
        Anchors = []
        Caption = 'b = '
      end
      object Lbl_Elips_a: TLabel
        Left = 8
        Top = 12
        Width = 18
        Height = 13
        Anchors = []
        Caption = 'a = '
      end
      object Ed_Elips_a: TEdit
        Left = 24
        Top = 8
        Width = 30
        Height = 21
        Anchors = []
        TabOrder = 0
        Text = '150'
      end
      object Ed_Elips_b: TEdit
        Left = 112
        Top = 8
        Width = 30
        Height = 21
        Anchors = []
        TabOrder = 1
        Text = '150'
      end
      object Ed_Elips_c: TEdit
        Left = 192
        Top = 8
        Width = 30
        Height = 21
        Anchors = []
        TabOrder = 2
        Text = '150'
      end
      object UpDn_Elips_a: TUpDown
        Left = 54
        Top = 8
        Width = 16
        Height = 21
        Anchors = []
        Associate = Ed_Elips_a
        Min = 1
        Max = 250
        Position = 150
        TabOrder = 3
        Wrap = False
        OnClick = UpDn_Tor_RClick
      end
      object UpDn_Elips_b: TUpDown
        Left = 142
        Top = 8
        Width = 16
        Height = 21
        Anchors = []
        Associate = Ed_Elips_b
        Min = 1
        Max = 250
        Position = 150
        TabOrder = 4
        Wrap = False
        OnClick = UpDn_Tor_RClick
      end
      object UpDn_Elips_c: TUpDown
        Left = 222
        Top = 8
        Width = 16
        Height = 21
        Anchors = []
        Associate = Ed_Elips_c
        Min = 1
        Max = 250
        Position = 150
        TabOrder = 5
        Wrap = False
        OnClick = UpDn_Tor_RClick
      end
    end
    object Pnl_ToroidParam: TPanel
      Left = 2
      Top = 15
      Width = 269
      Height = 40
      Align = alTop
      Anchors = []
      TabOrder = 3
      DesignSize = (
        269
        40)
      object Label5: TLabel
        Left = 48
        Top = 12
        Width = 20
        Height = 13
        Anchors = []
        Caption = 'R = '
      end
      object Label6: TLabel
        Left = 160
        Top = 12
        Width = 18
        Height = 13
        Anchors = []
        Caption = 'a = '
      end
      object Ed_Tor_R: TEdit
        Left = 72
        Top = 8
        Width = 30
        Height = 21
        Anchors = []
        TabOrder = 0
        Text = '150'
      end
      object UpDn_Tor_R: TUpDown
        Left = 102
        Top = 8
        Width = 17
        Height = 21
        Anchors = []
        Associate = Ed_Tor_R
        Min = 0
        Max = 150
        Position = 150
        TabOrder = 1
        Wrap = True
        OnClick = UpDn_Tor_RClick
      end
      object Ed_Tor_a: TEdit
        Left = 184
        Top = 8
        Width = 30
        Height = 21
        Anchors = []
        TabOrder = 2
        Text = '75'
      end
      object UpDn_Tor_a: TUpDown
        Left = 214
        Top = 8
        Width = 17
        Height = 21
        Anchors = []
        Associate = Ed_Tor_a
        Min = 0
        Position = 75
        TabOrder = 3
        Wrap = True
        OnClick = UpDn_Tor_RClick
      end
    end
    object Button1: TButton
      Left = 152
      Top = 416
      Width = 121
      Height = 25
      Anchors = []
      Caption = #1047#1072#1075#1088#1091#1079#1080#1090#1100' '#1090#1077#1082#1089#1090#1091#1088#1091
      TabOrder = 1
      OnClick = Button1Click
    end
    object U_V_Pnl: TPanel
      Left = 2
      Top = 54
      Width = 270
      Height = 40
      Anchors = []
      TabOrder = 4
      DesignSize = (
        270
        40)
      object Lbl_U: TLabel
        Left = 48
        Top = 12
        Width = 20
        Height = 13
        Anchors = []
        Caption = 'U = '
      end
      object Lbl_V: TLabel
        Left = 160
        Top = 12
        Width = 19
        Height = 13
        Anchors = []
        Caption = 'V = '
      end
      object UpDn_Segment_U: TUpDown
        Left = 102
        Top = 8
        Width = 17
        Height = 21
        Anchors = []
        Associate = Ed_Segment_U
        Min = 3
        Position = 100
        TabOrder = 0
        Wrap = True
        OnClick = UpDn_Tor_RClick
      end
      object Ed_Segment_U: TEdit
        Left = 72
        Top = 8
        Width = 30
        Height = 21
        Anchors = []
        TabOrder = 1
        Text = '100'
      end
      object Ed_Segment_V: TEdit
        Left = 184
        Top = 8
        Width = 30
        Height = 21
        Anchors = []
        TabOrder = 2
        Text = '100'
      end
      object UpDn_Segment_V: TUpDown
        Left = 214
        Top = 8
        Width = 17
        Height = 21
        Anchors = []
        Associate = Ed_Segment_V
        Min = 3
        Position = 100
        TabOrder = 3
        Wrap = True
        OnClick = UpDn_Tor_RClick
      end
    end
    object Rotate_Pnl: TPanel
      Left = 2
      Top = 93
      Width = 270
      Height = 50
      Anchors = []
      TabOrder = 0
      DesignSize = (
        270
        50)
      object Label7: TLabel
        Left = 1
        Top = 2
        Width = 268
        Height = 13
        Alignment = taCenter
        Anchors = []
        AutoSize = False
        Caption = #1055#1086#1074#1086#1088#1086#1090' '#1087#1086' X,  Y,  Z'
      end
      object Lbl_Z: TLabel
        Left = 174
        Top = 24
        Width = 7
        Height = 13
        Anchors = []
        Caption = 'Z'
      end
      object Lbl_X: TLabel
        Left = 8
        Top = 24
        Width = 7
        Height = 13
        Anchors = []
        Caption = 'X'
      end
      object Lbl_Y: TLabel
        Left = 94
        Top = 24
        Width = 7
        Height = 13
        Anchors = []
        Caption = 'Y'
      end
      object Ed_Rot_X: TEdit
        Left = 24
        Top = 20
        Width = 30
        Height = 21
        Anchors = []
        TabOrder = 0
        Text = '0'
      end
      object Ed_Rot_Y: TEdit
        Left = 112
        Top = 20
        Width = 30
        Height = 21
        Anchors = []
        TabOrder = 1
        Text = '0'
      end
      object Ed_Rot_Z: TEdit
        Left = 192
        Top = 20
        Width = 30
        Height = 21
        Anchors = []
        TabOrder = 2
        Text = '0'
      end
      object UpDn_Rot_Z: TUpDown
        Left = 222
        Top = 20
        Width = 17
        Height = 21
        Anchors = []
        Associate = Ed_Rot_Z
        Min = 0
        Max = 359
        Position = 0
        TabOrder = 3
        Wrap = True
        OnClick = UpDn_Rot_XClick
      end
      object UpDn_Rot_X: TUpDown
        Left = 54
        Top = 20
        Width = 17
        Height = 21
        Anchors = []
        Associate = Ed_Rot_X
        Min = 0
        Max = 359
        Position = 0
        TabOrder = 4
        Wrap = True
        OnClick = UpDn_Rot_XClick
      end
      object UpDn_Rot_Y: TUpDown
        Left = 142
        Top = 20
        Width = 17
        Height = 21
        Anchors = []
        Associate = Ed_Rot_Y
        Min = 0
        Max = 359
        Position = 0
        TabOrder = 5
        Wrap = True
        OnClick = UpDn_Rot_XClick
      end
    end
    object Pnl_PositionLight: TPanel
      Left = 2
      Top = 142
      Width = 270
      Height = 50
      Anchors = []
      TabOrder = 5
      DesignSize = (
        270
        50)
      object Label8: TLabel
        Left = 1
        Top = 2
        Width = 268
        Height = 13
        Alignment = taCenter
        Anchors = []
        AutoSize = False
        Caption = #1048#1089#1090#1086#1095#1085#1080#1082' '#1089#1074#1077#1090#1072' '#1087#1086' X,  Y,  Z'
      end
      object Lbl_Light_Z: TLabel
        Left = 174
        Top = 24
        Width = 7
        Height = 13
        Anchors = []
        Caption = 'Z'
      end
      object Lbl_Light_X: TLabel
        Left = 8
        Top = 24
        Width = 7
        Height = 13
        Anchors = []
        Caption = 'X'
      end
      object Lbl_Light_Y: TLabel
        Left = 94
        Top = 24
        Width = 7
        Height = 13
        Anchors = []
        Caption = 'Y'
      end
      object Ed_Light_X: TEdit
        Left = 24
        Top = 20
        Width = 30
        Height = 21
        Anchors = []
        TabOrder = 0
        Text = '100'
      end
      object Ed_Light_Y: TEdit
        Left = 112
        Top = 20
        Width = 30
        Height = 21
        Anchors = []
        TabOrder = 1
        Text = '0'
      end
      object Ed_Light_Z: TEdit
        Left = 192
        Top = 20
        Width = 30
        Height = 21
        Anchors = []
        TabOrder = 2
        Text = '300'
      end
      object UpDn_Light_Z: TUpDown
        Left = 222
        Top = 20
        Width = 17
        Height = 21
        Anchors = []
        Associate = Ed_Light_Z
        Min = -300
        Max = 300
        Position = 300
        TabOrder = 3
        Wrap = True
        OnClick = UpDn_Light_XClick
      end
      object UpDn_Light_X: TUpDown
        Left = 54
        Top = 20
        Width = 17
        Height = 21
        Anchors = []
        Associate = Ed_Light_X
        Min = -300
        Max = 300
        Position = 100
        TabOrder = 4
        Wrap = True
        OnClick = UpDn_Light_XClick
      end
      object UpDn_Light_Y: TUpDown
        Left = 142
        Top = 20
        Width = 17
        Height = 21
        Anchors = []
        Associate = Ed_Light_Y
        Min = -300
        Max = 300
        Position = 0
        TabOrder = 5
        Wrap = True
        OnClick = UpDn_Light_XClick
      end
    end
    object Pnl_ColorLight: TPanel
      Left = 2
      Top = 191
      Width = 270
      Height = 70
      Anchors = []
      TabOrder = 6
      DesignSize = (
        270
        70)
      object Label2: TLabel
        Left = 1
        Top = 2
        Width = 268
        Height = 13
        Alignment = taCenter
        Anchors = []
        AutoSize = False
        Caption = #1062#1074#1077#1090' '#1080#1089#1090#1086#1095#1085#1080#1082#1072' '#1089#1074#1077#1090#1072' R, G, B'
      end
      object Lbl_ClrLight_B: TLabel
        Left = 174
        Top = 24
        Width = 7
        Height = 13
        Anchors = []
        Caption = 'B'
      end
      object Lbl_ClrLight_R: TLabel
        Left = 8
        Top = 24
        Width = 8
        Height = 13
        Anchors = []
        Caption = 'R'
      end
      object Lbl_ClrLight_G: TLabel
        Left = 94
        Top = 24
        Width = 8
        Height = 13
        Anchors = []
        Caption = 'G'
      end
      object Ed_ClrLight_R: TEdit
        Left = 24
        Top = 20
        Width = 30
        Height = 21
        Anchors = []
        TabOrder = 0
        Text = '255'
      end
      object Ed_ClrLight_G: TEdit
        Left = 112
        Top = 20
        Width = 30
        Height = 21
        Anchors = []
        TabOrder = 1
        Text = '255'
      end
      object Ed_ClrLight_B: TEdit
        Left = 192
        Top = 20
        Width = 30
        Height = 21
        Anchors = []
        TabOrder = 2
        Text = '255'
      end
      object UpDn_ClrLight_B: TUpDown
        Left = 222
        Top = 20
        Width = 17
        Height = 21
        Anchors = []
        Associate = Ed_ClrLight_B
        Min = 0
        Max = 255
        Position = 255
        TabOrder = 3
        Wrap = True
        OnClick = UpDn_ClrLight_RClick
      end
      object UpDn_ClrLight_R: TUpDown
        Left = 54
        Top = 20
        Width = 17
        Height = 21
        Anchors = []
        Associate = Ed_ClrLight_R
        Min = 0
        Max = 255
        Position = 255
        TabOrder = 4
        Wrap = True
        OnClick = UpDn_ClrLight_RClick
      end
      object UpDn_ClrLight_G: TUpDown
        Left = 142
        Top = 20
        Width = 17
        Height = 21
        Anchors = []
        Associate = Ed_ClrLight_G
        Min = 0
        Max = 255
        Position = 255
        TabOrder = 5
        Wrap = True
        OnClick = UpDn_ClrLight_RClick
      end
      object Pnl_ColorLigth_View: TPanel
        Left = 0
        Top = 50
        Width = 270
        Height = 20
        Anchors = []
        TabOrder = 6
      end
    end
    object Pnl_ColorBody: TPanel
      Left = 2
      Top = 260
      Width = 270
      Height = 70
      Anchors = []
      TabOrder = 7
      DesignSize = (
        270
        70)
      object Label3: TLabel
        Left = 1
        Top = 2
        Width = 268
        Height = 13
        Alignment = taCenter
        Anchors = []
        AutoSize = False
        Caption = #1062#1074#1077#1090' '#1090#1077#1083#1072' R, G, B'
      end
      object Lbl_ClrBody_B: TLabel
        Left = 174
        Top = 24
        Width = 7
        Height = 13
        Anchors = []
        Caption = 'B'
      end
      object Lbl_ClrBody_R: TLabel
        Left = 8
        Top = 24
        Width = 8
        Height = 13
        Anchors = []
        Caption = 'R'
      end
      object Lbl_ClrBody_G: TLabel
        Left = 94
        Top = 24
        Width = 8
        Height = 13
        Anchors = []
        Caption = 'G'
      end
      object Ed_ClrBody_R: TEdit
        Left = 24
        Top = 20
        Width = 30
        Height = 21
        Anchors = []
        TabOrder = 0
        Text = '255'
      end
      object Ed_ClrBody_G: TEdit
        Left = 112
        Top = 20
        Width = 30
        Height = 21
        Anchors = []
        TabOrder = 1
        Text = '255'
      end
      object Ed_ClrBody_B: TEdit
        Left = 192
        Top = 20
        Width = 30
        Height = 21
        Anchors = []
        TabOrder = 2
        Text = '0'
      end
      object UpDn_ClrBody_B: TUpDown
        Left = 222
        Top = 20
        Width = 17
        Height = 21
        Anchors = []
        Associate = Ed_ClrBody_B
        Min = 0
        Max = 255
        Position = 0
        TabOrder = 3
        Wrap = True
        OnClick = UpDn_ClrBody_RClick
      end
      object UpDn_ClrBody_R: TUpDown
        Left = 54
        Top = 20
        Width = 17
        Height = 21
        Anchors = []
        Associate = Ed_ClrBody_R
        Min = 0
        Max = 255
        Position = 255
        TabOrder = 4
        Wrap = True
        OnClick = UpDn_ClrBody_RClick
      end
      object UpDn_ClrBody_G: TUpDown
        Left = 142
        Top = 20
        Width = 17
        Height = 21
        Anchors = []
        Associate = Ed_ClrBody_G
        Min = 0
        Max = 255
        Position = 255
        TabOrder = 5
        Wrap = True
        OnClick = UpDn_ClrBody_RClick
      end
      object Pnl_ColorBody_View: TPanel
        Left = 0
        Top = 50
        Width = 270
        Height = 20
        Anchors = []
        TabOrder = 6
      end
    end
    object Ed_Prozr: TEdit
      Left = 8
      Top = 346
      Width = 41
      Height = 21
      TabOrder = 8
      Text = '100'
    end
    object Ed_Kd: TEdit
      Left = 144
      Top = 346
      Width = 30
      Height = 21
      TabOrder = 9
      Text = '0'
    end
    object Ed_Kl: TEdit
      Left = 216
      Top = 346
      Width = 30
      Height = 21
      TabOrder = 10
      Text = '0'
    end
    object Ed_Ks: TEdit
      Left = 88
      Top = 346
      Width = 30
      Height = 21
      TabOrder = 11
      Text = '0'
    end
    object UpDn_Kd: TUpDown
      Left = 174
      Top = 346
      Width = 17
      Height = 21
      Associate = Ed_Kd
      Min = 0
      Position = 0
      TabOrder = 12
      Wrap = True
    end
    object UpDn_Proz: TUpDown
      Left = 49
      Top = 346
      Width = 17
      Height = 21
      Associate = Ed_Prozr
      Min = 0
      Position = 100
      TabOrder = 13
      Wrap = True
      OnClick = UpDn_ProzClick
    end
    object UpDn_Ks: TUpDown
      Left = 118
      Top = 346
      Width = 17
      Height = 21
      Associate = Ed_Ks
      Min = 0
      Position = 0
      TabOrder = 14
      Wrap = True
    end
    object UpDn_Kl: TUpDown
      Left = 246
      Top = 346
      Width = 17
      Height = 21
      Associate = Ed_Kl
      Min = 0
      Position = 0
      TabOrder = 15
      Wrap = True
    end
    object Ed_N: TEdit
      Left = 24
      Top = 384
      Width = 30
      Height = 21
      TabOrder = 16
      Text = '60'
    end
    object UpDn_N: TUpDown
      Left = 54
      Top = 384
      Width = 17
      Height = 21
      Associate = Ed_N
      Min = 1
      Max = 128
      Position = 60
      TabOrder = 17
      Wrap = True
      OnClick = UpDn_Rot_XClick
    end
    object ChBx_Texture: TCheckBox
      Left = 8
      Top = 416
      Width = 73
      Height = 17
      Caption = #1058#1077#1082#1089#1090#1091#1088#1072
      TabOrder = 18
      OnClick = ChBx_TextureClick
    end
    object RadioGroup1: TRadioGroup
      Left = 80
      Top = 370
      Width = 185
      Height = 41
      Caption = #1058#1077#1082#1089#1090#1091#1088#1072
      Columns = 2
      ItemIndex = 0
      Items.Strings = (
        #1054#1076#1085#1072
        #1052#1085#1086#1075#1086)
      TabOrder = 19
      OnClick = RadioGroup1Click
    end
  end
  object GroupBox1: TGroupBox
    Left = 0
    Top = 2
    Width = 273
    Height = 55
    Anchors = []
    Caption = #1058#1077#1083#1086' '#1087#1086#1089#1090#1088#1086#1077#1085#1080#1103
    TabOrder = 1
    DesignSize = (
      273
      55)
    object CmbBx_Figura: TComboBox
      Left = 20
      Top = 20
      Width = 245
      Height = 21
      Style = csDropDownList
      Anchors = []
      ItemHeight = 13
      ItemIndex = 0
      TabOrder = 0
      Text = #1058#1086#1088#1086#1080#1076
      OnChange = CmbBx_FiguraChange
      Items.Strings = (
        #1058#1086#1088#1086#1080#1076
        #1069#1083#1080#1087#1089#1086#1080#1076)
    end
  end
  object OpenPictureDialog1: TOpenPictureDialog
    Left = 8
    Top = 464
  end
end
