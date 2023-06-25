#pragma once
#include "gdstk.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Collections::Generic;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Runtime::InteropServices;
using namespace gdstk;
using namespace Utils::Models;

ref class GdsPolygon
{
public:
	Tag layer_polygon;
	List<List<GPoint^>^>^ plygons_list = gcnew List<List<GPoint^>^>();
};