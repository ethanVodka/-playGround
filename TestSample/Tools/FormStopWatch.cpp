#include "../pch.h"
#include "FormStopWatch.h"

System::Void TestSample::FormStopWatch::BtnStart_Click(System::Object^ sender, System::EventArgs^ e)
{
    isStart = true;
    BackgroundTicer->RunWorkerAsync();
}

System::Void TestSample::FormStopWatch::BtnStop_Click(System::Object^ sender, System::EventArgs^ e)
{
    isStart = false;
}

System::Void TestSample::FormStopWatch::BtnReset_Click(System::Object^ sender, System::EventArgs^ e)
{
    return System::Void();
}

System::Void TestSample::FormStopWatch::BtnRapTime_Click(System::Object^ sender, System::EventArgs^ e)
{
    return System::Void();
}

System::Void TestSample::FormStopWatch::BtnSave_Click(System::Object^ sender, System::EventArgs^ e)
{
    return System::Void();
}

System::Void TestSample::FormStopWatch::BackgroundTicer_DoWork(System::Object^ sender, System::ComponentModel::DoWorkEventArgs^ e)
{
    while(isStart)
    {
        TimerCount();
    }
}

System::Void TestSample::FormStopWatch::TimerCount()
{
    return System::Void();
}