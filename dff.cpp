//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "dff.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm4 *Form4;
//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm4::PopupBox1Change(TObject *Sender)
{
 ShowMessage("No.of members: " + PopupBox1->Text);
}
//---------------------------------------------------------------------------

void __fastcall TForm4::PopupBox2Change(TObject *Sender)
{
 if (PopupBox2->Text == "Burger")
	{
		// Handle Burger order
		ShowMessage("You ordered: Burger");
	}
	else if (PopupBox2->Text == "Pizza")
    {
		// Handle Pizza order
        ShowMessage("You ordered: Pizza");
	}
}
//---------------------------------------------------------------------------

