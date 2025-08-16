object BasicForm: TBasicForm
  Left = 232
  Top = 125
  Cursor = crHandPoint
  BorderStyle = bsDialog
  Caption = 'BasicForm'
  ClientHeight = 746
  ClientWidth = 1024
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PopupMenu = PopMenu
  Position = poDesktopCenter
  WindowState = wsMaximized
  OnClose = FormClose
  OnConstrainedResize = FormConstrainedResize
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object ImageFon: TImage
    Left = 0
    Top = 0
    Width = 1024
    Height = 746
    Cursor = crHandPoint
    Align = alClient
    Stretch = True
    OnMouseDown = ImageFonMouseDown
  end
  object Timer1: TTimer
    Interval = 300
    OnTimer = Timer1Timer
  end
  object PopMenu: TPopupMenu
    Left = 32
    object KormPM: TMenuItem
      AutoCheck = True
      Caption = #1050#1086#1088#1084#1080#1090#1100
      OnClick = KormPMClick
    end
  end
  object Timer2: TTimer
    Interval = 50
    OnTimer = Timer2Timer
    Left = 24
    Top = 64
  end
end
