object Frm_Create_Object: TFrm_Create_Object
  Left = 487
  Top = 248
  BorderStyle = bsDialog
  Caption = #1057#1086#1079#1076#1072#1085#1080#1077' '#1086#1073#1098#1077#1082#1090#1072
  ClientHeight = 313
  ClientWidth = 222
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object CmBx_Tela: TComboBox
    Left = 35
    Top = 6
    Width = 140
    Height = 21
    Style = csDropDownList
    ItemHeight = 13
    PopupMenu = PopupMenu1
    TabOrder = 0
    Visible = False
    OnChange = CmBx_TelaChange
  end
  object Panel2: TPanel
    Left = 0
    Top = 0
    Width = 222
    Height = 313
    Caption = 'Panel2'
    ParentColor = True
    TabOrder = 1
    object PageControl1: TPageControl
      Left = 0
      Top = 0
      Width = 222
      Height = 276
      ActivePage = TbSht_param
      TabIndex = 0
      TabOrder = 0
      object TbSht_param: TTabSheet
        Caption = '    '#1056#1072#1079#1084#1077#1088#1099' '#1090#1077#1083#1072'    '
        object GrBx_Rasmer: TGroupBox
          Left = 3
          Top = 0
          Width = 210
          Height = 129
          Caption = '                         '#1056#1072#1079#1084#1077#1088#1099'                       '
          TabOrder = 0
          object Label1: TLabel
            Left = 2
            Top = 40
            Width = 39
            Height = 13
            Caption = #1044#1083#1080#1085#1085#1072
          end
          object Label2: TLabel
            Left = 2
            Top = 72
            Width = 39
            Height = 13
            Caption = #1064#1080#1088#1080#1085#1072
          end
          object Label3: TLabel
            Left = 2
            Top = 104
            Width = 38
            Height = 13
            Caption = #1042#1099#1089#1086#1090#1072
          end
          object ChkBx: TCheckBox
            Left = 8
            Top = 16
            Width = 137
            Height = 17
            Caption = #1050#1091#1073
            TabOrder = 0
            OnClick = ChkBxClick
          end
          object Ed_Rasmer3: TEdit
            Left = 130
            Top = 100
            Width = 50
            Height = 21
            MaxLength = 10
            TabOrder = 3
            Text = '0'
            OnKeyPress = Ed_Rasmer1KeyPress
          end
          object Ed_Rasmer2: TEdit
            Left = 130
            Top = 68
            Width = 50
            Height = 21
            MaxLength = 10
            TabOrder = 2
            Text = '0'
            OnKeyPress = Ed_Rasmer1KeyPress
          end
          object Ed_Rasmer1: TEdit
            Left = 130
            Top = 36
            Width = 50
            Height = 21
            MaxLength = 10
            TabOrder = 1
            Text = '0'
            OnKeyPress = Ed_Rasmer1KeyPress
          end
          object UpDown1: TUpDown
            Left = 180
            Top = 36
            Width = 15
            Height = 21
            Associate = Ed_Rasmer1
            Min = 0
            Max = 1000
            Position = 0
            TabOrder = 4
            Wrap = False
            OnClick = UpDn_Rot_XClick
          end
          object UpDown2: TUpDown
            Left = 180
            Top = 68
            Width = 15
            Height = 21
            Associate = Ed_Rasmer2
            Min = 0
            Max = 1000
            Position = 0
            TabOrder = 5
            Wrap = False
            OnClick = UpDn_Rot_XClick
          end
          object UpDown3: TUpDown
            Left = 180
            Top = 100
            Width = 15
            Height = 21
            Associate = Ed_Rasmer3
            Min = 0
            Max = 1000
            Position = 0
            TabOrder = 6
            Wrap = False
            OnClick = UpDn_Rot_XClick
          end
        end
        object GrBx_Rotate: TGroupBox
          Left = 3
          Top = 128
          Width = 210
          Height = 97
          Caption = '            '#1054#1089#1085#1086#1074#1085#1086#1081' '#1091#1075#1086#1083' '#1087#1086#1074#1086#1088#1086#1090#1072'          '
          TabOrder = 1
          object Label4: TLabel
            Left = 2
            Top = 24
            Width = 109
            Height = 13
            Caption = #1054#1090#1085#1086#1089#1080#1090#1077#1083#1100#1085#1086' '#1086#1089#1080' oX'
          end
          object Label5: TLabel
            Left = 2
            Top = 48
            Width = 109
            Height = 13
            Caption = #1054#1090#1085#1086#1089#1080#1090#1077#1083#1100#1085#1086' '#1086#1089#1080' oY'
          end
          object Label6: TLabel
            Left = 2
            Top = 72
            Width = 109
            Height = 13
            Caption = #1054#1090#1085#1086#1089#1080#1090#1077#1083#1100#1085#1086' '#1086#1089#1080' oZ'
          end
          object Ed_Rot_X: TEdit
            Left = 130
            Top = 20
            Width = 50
            Height = 21
            MaxLength = 10
            TabOrder = 0
            Text = '0'
            OnKeyPress = Ed_Rasmer1KeyPress
          end
          object Ed_Rot_Z: TEdit
            Left = 130
            Top = 68
            Width = 50
            Height = 21
            MaxLength = 10
            TabOrder = 1
            Text = '0'
            OnKeyPress = Ed_Rasmer1KeyPress
          end
          object UpDn_Rot_X: TUpDown
            Left = 180
            Top = 20
            Width = 15
            Height = 21
            Associate = Ed_Rot_X
            Min = 0
            Max = 1000
            Position = 0
            TabOrder = 2
            Wrap = False
            OnClick = UpDn_Rot_XClick
          end
          object UpDn_Rot_Z: TUpDown
            Left = 180
            Top = 68
            Width = 15
            Height = 21
            Associate = Ed_Rot_Z
            Min = 0
            Max = 1000
            Position = 0
            TabOrder = 3
            Wrap = False
            OnClick = UpDn_Rot_XClick
          end
          object Ed_Rot_Y: TEdit
            Left = 130
            Top = 44
            Width = 50
            Height = 21
            TabOrder = 4
            Text = '0'
            OnKeyPress = Ed_Rasmer1KeyPress
          end
          object UpDn_Rot_Y: TUpDown
            Left = 180
            Top = 44
            Width = 15
            Height = 21
            Associate = Ed_Rot_Y
            Min = 0
            Max = 1000
            Position = 0
            TabOrder = 5
            Wrap = False
            OnClick = UpDn_Rot_XClick
          end
        end
        object Btn_Start_Points: TButton
          Left = 3
          Top = 224
          Width = 210
          Height = 25
          Caption = #1057#1090#1072#1088#1090#1086#1074#1072#1103' '#1090#1086#1095#1082#1072
          TabOrder = 2
          OnClick = Btn_Start_PointsClick
        end
      end
      object TbSht_color: TTabSheet
        Caption = '       '#1062#1074#1077#1090'  '#1090#1077#1083#1072'       '
        ImageIndex = 1
        object Label7: TLabel
          Left = 0
          Top = 181
          Width = 214
          Height = 13
          Alignment = taCenter
          AutoSize = False
          Caption = #1055#1088#1086#1079#1088#1072#1095#1085#1086#1089#1090#1100' ('#1072#1083#1100#1092#1072')'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clGray
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object Label8: TLabel
          Left = 0
          Top = 10
          Width = 214
          Height = 13
          Alignment = taCenter
          AutoSize = False
          Caption = #1057#1086#1089#1090#1072#1074#1083#1103#1102#1097#1072#1103' '#1094#1074#1077#1090#1072' R'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clRed
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object Lbl_VG: TLabel
          Left = 88
          Top = 83
          Width = 35
          Height = 13
          Caption = 'Lbl_VG'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clGreen
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object Lbl_VB: TLabel
          Left = 88
          Top = 140
          Width = 34
          Height = 13
          Caption = 'Lbl_VB'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlue
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object Lbl_VPR: TLabel
          Left = 88
          Top = 197
          Width = 42
          Height = 13
          Caption = 'Lbl_VPR'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clGray
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object Lbl_VR: TLabel
          Left = 88
          Top = 26
          Width = 35
          Height = 13
          Caption = 'Lbl_VR'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clRed
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object Label13: TLabel
          Left = 0
          Top = 67
          Width = 214
          Height = 13
          Alignment = taCenter
          AutoSize = False
          Caption = #1057#1086#1089#1090#1072#1074#1083#1103#1102#1097#1072#1103' '#1094#1074#1077#1090#1072' G'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clGreen
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object Label14: TLabel
          Left = 0
          Top = 124
          Width = 214
          Height = 13
          Alignment = taCenter
          AutoSize = False
          Caption = #1057#1086#1089#1090#1072#1074#1083#1103#1102#1097#1072#1103' '#1094#1074#1077#1090#1072' B'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlue
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object TrBr_R: TTrackBar
          Left = 7
          Top = 37
          Width = 200
          Height = 20
          Ctl3D = True
          Max = 255
          Orientation = trHorizontal
          ParentCtl3D = False
          PageSize = 1
          Frequency = 1
          Position = 0
          SelEnd = 0
          SelStart = 0
          TabOrder = 0
          ThumbLength = 15
          TickMarks = tmBottomRight
          TickStyle = tsAuto
          OnChange = TrBr_RChange
        end
        object TrBr_G: TTrackBar
          Left = 7
          Top = 94
          Width = 200
          Height = 20
          Ctl3D = True
          Max = 255
          Orientation = trHorizontal
          ParentCtl3D = False
          PageSize = 1
          Frequency = 1
          Position = 0
          SelEnd = 0
          SelStart = 0
          TabOrder = 1
          ThumbLength = 15
          TickMarks = tmBottomRight
          TickStyle = tsAuto
          OnChange = TrBr_RChange
        end
        object TrBr_B: TTrackBar
          Left = 7
          Top = 151
          Width = 200
          Height = 20
          Ctl3D = True
          Max = 255
          Orientation = trHorizontal
          ParentCtl3D = False
          PageSize = 1
          Frequency = 1
          Position = 0
          SelEnd = 0
          SelStart = 0
          TabOrder = 2
          ThumbLength = 15
          TickMarks = tmBottomRight
          TickStyle = tsAuto
          OnChange = TrBr_RChange
        end
        object TrBr_Proz: TTrackBar
          Left = 7
          Top = 208
          Width = 200
          Height = 20
          Ctl3D = True
          Max = 100
          Orientation = trHorizontal
          ParentCtl3D = False
          PageSize = 1
          Frequency = 1
          Position = 0
          SelEnd = 0
          SelStart = 0
          TabOrder = 3
          ThumbLength = 15
          TickMarks = tmBottomRight
          TickStyle = tsAuto
          OnChange = TrBr_RChange
        end
        object Panel1: TPanel
          Left = 0
          Top = 231
          Width = 214
          Height = 17
          Align = alBottom
          TabOrder = 4
          OnClick = Panel1Click
        end
      end
    end
    object Btn_CrObj_Ok: TButton
      Left = 34
      Top = 288
      Width = 60
      Height = 20
      Caption = #1044#1072
      ModalResult = 1
      TabOrder = 1
    end
    object Btn_CrObj_No: TButton
      Left = 124
      Top = 288
      Width = 60
      Height = 20
      Caption = #1053#1077#1090
      TabOrder = 2
      OnClick = Btn_CrObj_NoClick
    end
  end
  object ColorDialog1: TColorDialog
    Ctl3D = True
    Left = 40
    Top = 40
  end
  object PopupMenu1: TPopupMenu
    Left = 80
    Top = 16
    object N1: TMenuItem
      Caption = #1059#1076#1072#1083#1080#1090#1100
      OnClick = N1Click
    end
  end
end
