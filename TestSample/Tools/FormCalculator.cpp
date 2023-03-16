#include "../pch.h"
#include "FormCalculator.h"

System::Void TestSample::FormCalculator::Number_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (Operator == "Plus" || Operator == "Minus" || Operator == "Divide" || Operator == "Mulitple")
	{
		if (Check)
		{
			Check = false;
		}
	}
	Button^ btn = (Button^)sender;

	if (ResultText == "0")
	{
		ResultText = btn->Text;
	}
	else
	{
		BoxRichText->Text += btn->Text;
	}
}

System::Void TestSample::FormCalculator::Operatrion_Click(System::Object^ sender, System::EventArgs^ e)
{

}

System::Void TestSample::FormCalculator::btnClear_Click(System::Object^ sender, System::EventArgs^ e)
{

}

System::Void TestSample::FormCalculator::BtnAllClear_Click(System::Object^ sender, System::EventArgs^ e)
{

}

System::Void TestSample::FormCalculator::BtnEqual_Click(System::Object^ sender, System::EventArgs^ e)
{

}

System::Void TestSample::FormCalculator::SetCalcLine(String^ value)
{


}
