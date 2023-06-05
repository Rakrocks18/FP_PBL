//---------------------------------------------------------------------------

#ifndef dffH
#define dffH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Objects.hpp>
#include <FMX.Types.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.ExtCtrls.hpp>
#include <FMX.StdCtrls.hpp>
//---------------------------------------------------------------------------
class TForm4 : public TForm
{
__published:	// IDE-managed Components
	TImage *Image1;
	TRectangle *Rectangle1;
	TCircle *Circle1;
	TImage *Image2;
	TLabel *Label1;
	TPopupBox *PopupBox1;
	TLabel *Label2;
	TPopupBox *PopupBox2;
	void __fastcall PopupBox1Change(TObject *Sender);
	void __fastcall PopupBox2Change(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm4(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm4 *Form4;
//---------------------------------------------------------------------------
#endif
