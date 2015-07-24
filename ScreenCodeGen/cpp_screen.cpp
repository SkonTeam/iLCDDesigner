#include "stdafx.h"
#include "hpp_screen.hpp"

Screen::Screen(string filename){
	out_file.open(filename.c_str(), ofstream::out);
	if (!out_file.is_open()){
		cout << "Couldn't open file with filename : " << filename << endl;
	}
	else{
		this->filename = filename;
		cout << "File : " << this->filename << " opened succesfully " << endl;
	}
}

Screen::~Screen(){
	out_file.close();
}
void Screen::WriteComment(std::string comment) {
	if (out_file.is_open()) {

		std::ostringstream str_to_write;

		str_to_write << "{ ";
		str_to_write << comment;
		str_to_write << " }\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}
void Screen::StartMacro(std::string MacroName, int MacroIndex, int Charset){
	if (out_file.is_open()){

		std::ostringstream str_to_write;

		str_to_write << "#macro_start(";
		str_to_write << MacroIndex;
		str_to_write << ",\"" << MacroName << "\",";
		str_to_write << Charset;
		str_to_write << ")\n";


		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}
void Screen::EndMacro(){
	if (out_file.is_open()){
		std::string str_to_write;
		str_to_write = "#macro_end\n";
		out_file.write(str_to_write.c_str(), str_to_write.size());
	}
}
void Screen::NoOperation(){
	if (out_file.is_open()){
		std::string str_to_write;
		str_to_write = "\\i";
		str_to_write += "'";
		str_to_write += "\n";
		out_file.write(str_to_write.c_str(), str_to_write.size());
	}
}

void Screen::ResetAll(){
	if (out_file.is_open()){
		std::string str_to_write;
		str_to_write = "\\i";
		str_to_write += "!";
		str_to_write += "\n";
		out_file.write(str_to_write.c_str(), str_to_write.size());
	}
}

void Screen::ResetAllandShowStartupGraphic(){
	if (out_file.is_open()){
		std::string str_to_write;
		str_to_write = "\\i";
		str_to_write += "$";
		str_to_write += "\n";
		out_file.write(str_to_write.c_str(), str_to_write.size());
	}
}

void Screen::RebootPanelController(){
	if (out_file.is_open()){
		std::string str_to_write;
		str_to_write = "\\i";
		str_to_write += "#";
		str_to_write += "\n";
		out_file.write(str_to_write.c_str(), str_to_write.size());
	}
}

void Screen::GetLastErrorCode(){
	if (out_file.is_open()){
		std::string str_to_write;
		str_to_write = "\\i";
		str_to_write += "?";
		str_to_write += "E";
		str_to_write += "\n";
		out_file.write(str_to_write.c_str(), str_to_write.size());
	}
}

void Screen::GetFirmwareInfo(){
	if (out_file.is_open()){
		std::string str_to_write;
		str_to_write = "\\i";
		str_to_write += "?";
		str_to_write += "I";
		str_to_write += "\n";
		out_file.write(str_to_write.c_str(), str_to_write.size());
	}
}

void Screen::GetIdentificationInfo(){
	if (out_file.is_open()){
		std::string str_to_write;
		str_to_write = "\\i";
		str_to_write += "?";
		str_to_write += "M";
		str_to_write += "\n";
		out_file.write(str_to_write.c_str(), str_to_write.size());
	}
}

void Screen::GetFirmwareVersion(){
	if (out_file.is_open()){
		std::string str_to_write;
		str_to_write = "\\i";
		str_to_write += "?";
		str_to_write += "V";
		str_to_write += "\n";
		out_file.write(str_to_write.c_str(), str_to_write.size());
	}
}

void Screen::GetSerialNumber(){
	if (out_file.is_open()){
		std::string str_to_write;
		str_to_write = "\\i";
		str_to_write += "?";
		str_to_write += "S";
		str_to_write += "\n";
		out_file.write(str_to_write.c_str(), str_to_write.size());
	}
}

void Screen::GetiLCDControllerName(){
	if (out_file.is_open()){
		std::string str_to_write;
		str_to_write = "\\i";
		str_to_write += "?";
		str_to_write += "C";
		str_to_write += "\n";
		out_file.write(str_to_write.c_str(), str_to_write.size());
	}
}

void Screen::GetHardwareRevision(){
	if (out_file.is_open()){
		std::string str_to_write;
		str_to_write = "\\i";
		str_to_write += "?";
		str_to_write += "H";
		str_to_write += "\n";
		out_file.write(str_to_write.c_str(), str_to_write.size());
	}
}

void Screen::GetNetworkStatus(){
	if (out_file.is_open()){
		std::string str_to_write;
		str_to_write = "\\i";
		str_to_write += "?";
		str_to_write += "N";
		str_to_write += "\n";
		out_file.write(str_to_write.c_str(), str_to_write.size());
	}
}

void Screen::GetInputBufferSize(){
	if (out_file.is_open()){
		std::string str_to_write;
		str_to_write = "\\i";
		str_to_write += "?";
		str_to_write += "Q";
		str_to_write += "\n";
		out_file.write(str_to_write.c_str(), str_to_write.size());
	}
}

void Screen::GetProjectInfo(){
	if (out_file.is_open()){
		std::string str_to_write;
		str_to_write = "\\i";
		str_to_write += "?";
		str_to_write += "P";
		str_to_write += "\n";
		out_file.write(str_to_write.c_str(), str_to_write.size());
	}
}

void Screen::GetTouchScreenType(){
	if (out_file.is_open()){
		std::string str_to_write;
		str_to_write = "\\i";
		str_to_write += "?";
		str_to_write += "T";
		str_to_write += "M";
		str_to_write += "\n";
		out_file.write(str_to_write.c_str(), str_to_write.size());
	}
}

void Screen::DefineViewport(byte_int viewport, byte_int orientation, word width, word height){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "C";
		str_to_write << "V";
		str_to_write << "D";
		str_to_write << "\\d" << viewport;
		str_to_write << "\\d" << orientation;
		str_to_write << "\\D" << width;
		str_to_write << "\\D" << height;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::SelectViewport(byte_int viewport){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "C";
		str_to_write << "V";
		str_to_write << "S";
		str_to_write << "\\d" << viewport;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::CopyViewport(byte_int screen, byte_int viewport, bool copy_content, word pos_x, word pos_y){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "C";
		str_to_write << "V";
		str_to_write << "C";
		str_to_write << "\\d" << screen;
		str_to_write << "\\d" << viewport;
		str_to_write << "\\"  << copy_content;
		str_to_write << "\\D" << pos_x;
		str_to_write << "\\D" << pos_y;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::TurnDisplayOnOff(DisplayMode mode){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "C";
		str_to_write << "D";
		str_to_write << "\\d" << mode;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::SetScreenOrientation(ScreenOrientation orientation){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "C";
		str_to_write << "O";
		str_to_write << "\\d" << orientation;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::SetTextOrGraphicOrientation(GraphicOrientation orientation){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "C";
		str_to_write << "o";
		str_to_write << "\\d" << orientation;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::EnableDisableANSI(bool on_off){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "C";
		str_to_write << "A";
		str_to_write << "\\" << on_off;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::SetColumnAddress(word address){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "C";
		str_to_write << "C";
		str_to_write << "\\D" << address;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::IncrementDecrementColumnAddress(signed_word addr_inc){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "C";
		str_to_write << "c";
		str_to_write << "\\D" << addr_inc;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::SetRowAddress(word address){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "C";
		str_to_write << "R";
		str_to_write << "\\D" << address;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::IncrementDecrementRowAddress(signed_word addr_inc){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "C";
		str_to_write << "r";
		str_to_write << "\\D" << addr_inc;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::SetCursorPosition(word pos_x, word pos_y){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "C";
		str_to_write << "K";
		str_to_write << "\\D" << pos_x;
		str_to_write << "\\D" << pos_y;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::SetRelativeCursorPosition(signed_word x_inc, signed_word y_inc){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "C";
		str_to_write << "k";
		str_to_write << "\\D" << x_inc;
		str_to_write << "\\D" << y_inc;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::GetCursorPosition(){
	if (out_file.is_open()){
		std::string str_to_write;
		str_to_write = "\\i";
		str_to_write += "C";
		str_to_write += "?";
		str_to_write += "K";
		str_to_write += "\n";
		out_file.write(str_to_write.c_str(), str_to_write.size());
	}
}

void Screen::GetGraphicInfobyindex(word graphic_index){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "C";
		str_to_write << "?";
		str_to_write << "G";
		str_to_write << "\\D" << graphic_index;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::GetGraphicInfobyname(by_name graphic_name){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "C";
		str_to_write << "?";
		str_to_write << "G";
		str_to_write << "\\m" << graphic_name << "\\0";
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::GetGraphicInfobyfilename(by_file graphic_filename){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "C";
		str_to_write << "?";
		str_to_write << "G";
		str_to_write << "\\f" << graphic_filename << "\\0";
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::SetGraphicAlignment(bits mode, word width, word height){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "C";
		str_to_write << "G";
		str_to_write << "A";
		str_to_write << "\\d" << mode;
		str_to_write << "\\D" << width;
		str_to_write << "\\D" << height;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::GetTextExtent(string text){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "C";
		str_to_write << "?";
		str_to_write << "T";
		str_to_write << text << "\\0";
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::GetUnicodeTextExtent(string unicode_text){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "C";
		str_to_write << "?";
		str_to_write << "U";
		str_to_write << unicode_text << "\\0";
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::GetTextMessageExtentbyindex(byte_int message_index){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "C";
		str_to_write << "?";
		str_to_write << "t";
		str_to_write << "\\d" << message_index;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::GetTextMessageExtentbyname(by_name message_name){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "C";
		str_to_write << "?";
		str_to_write << "t";
		str_to_write << "\\m" << message_name << "\\0";
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::SetTextAlignment(TextAlign mode, word width, word height){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "C";
		str_to_write << "T";
		str_to_write << "\\d" << mode;
		str_to_write << "\\D" << width;
		str_to_write << "\\D" << height;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::SetLineStyle(byte_int style){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "C";
		str_to_write << "L";
		str_to_write << "\\d" << style;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::GetDisplaySize(){
	if (out_file.is_open()){
		std::string str_to_write;
		str_to_write = "\\i";
		str_to_write += "C";
		str_to_write += "?";
		str_to_write += "D";
		str_to_write += "\n";
		out_file.write(str_to_write.c_str(), str_to_write.size());
	}
}

void Screen::SetAutoLinefeed(bool on_off){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "C";
		str_to_write << "F";
		str_to_write << "\\" << on_off;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::SetWrapMode(bool horz_wrap, bool vert_wrap){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "C";
		str_to_write << "W";
		str_to_write << "\\" << horz_wrap;
		str_to_write << "\\" << vert_wrap;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::GoTerminalMode(){
	if (out_file.is_open()){
		std::string str_to_write;
		str_to_write = "\\i";
		str_to_write += "C";
		str_to_write += "G";
		str_to_write += "=";
		str_to_write += "\n";
		out_file.write(str_to_write.c_str(), str_to_write.size());
	}
}

void Screen::SetXONXOFFforTerminalMode(bool on_off){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "C";
		str_to_write << "X";
		str_to_write << "\\" << on_off;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::SetBacklightMode(BacklightMode mode){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "C";
		str_to_write << "B";
		str_to_write << "\\d" << mode;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::GetBacklightMode(){
	if (out_file.is_open()){
		std::string str_to_write;
		str_to_write = "\\i";
		str_to_write += "C";
		str_to_write += "?";
		str_to_write += "B";
		str_to_write += "\n";
		out_file.write(str_to_write.c_str(), str_to_write.size());
	}
}

void Screen::SetBacklightBlinkFrequency(byte_int period){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "C";
		str_to_write << "b";
		str_to_write << "\\d" << period;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::SetBacklightIntensity(byte_int intensity){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "C";
		str_to_write << "I";
		str_to_write << "\\d" << intensity;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::SetBacklightIntensityHighRes(byte_int intensity){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "C";
		str_to_write << "i";
		str_to_write << "\\d" << intensity;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::GetBacklightIntensity(){
	if (out_file.is_open()){
		std::string str_to_write;
		str_to_write = "\\i";
		str_to_write += "C";
		str_to_write += "?";
		str_to_write += "I";
		str_to_write += "\n";
		out_file.write(str_to_write.c_str(), str_to_write.size());
	}
}

void Screen::GetBacklightIntensityHighRes(){
	if (out_file.is_open()){
		std::string str_to_write;
		str_to_write = "\\i";
		str_to_write += "C";
		str_to_write += "?";
		str_to_write += "i";
		str_to_write += "\n";
		out_file.write(str_to_write.c_str(), str_to_write.size());
	}
}

void Screen::GetFixedLCDContrastGamma(){
	if (out_file.is_open()){
		std::string str_to_write;
		str_to_write = "\\i";
		str_to_write += "C";
		str_to_write += "?";
		str_to_write += "X";
		str_to_write += "\n";
		out_file.write(str_to_write.c_str(), str_to_write.size());
	}
}

void Screen::SetLCDContrast(byte_int value){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "C";
		str_to_write << "N";
		str_to_write << "\\d" << value;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::GetLCDContrast(){
	if (out_file.is_open()){
		std::string str_to_write;
		str_to_write = "\\i";
		str_to_write += "C";
		str_to_write += "?";
		str_to_write += "N";
		str_to_write += "\n";
		out_file.write(str_to_write.c_str(), str_to_write.size());
	}
}

void Screen::SetLCDGammaValue(byte_int value){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "C";
		str_to_write << "M";
		str_to_write << "\\d" << value;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::GetLCDGammaValue(){
	if (out_file.is_open()){
		std::string str_to_write;
		str_to_write = "\\i";
		str_to_write += "C";
		str_to_write += "?";
		str_to_write += "M";
		str_to_write += "\n";
		out_file.write(str_to_write.c_str(), str_to_write.size());
	}
}

void Screen::SetGraphicsScaling(byte_int factor){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "C";
		str_to_write << "E";
		str_to_write << "G";
		str_to_write << "\\d" << factor <<" ";
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::SetFontsScaling(byte_int factor){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "C";
		str_to_write << "E";
		str_to_write << "F";
		str_to_write << "\\d" << factor;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::SetColumnCoordinatesScaling(word mult, word div){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "C";
		str_to_write << "E";
		str_to_write << "C";
		str_to_write << "\\D" << mult;
		str_to_write << "\\D" << div;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::SetRowCoordinatesScaling(word mult, word div){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "C";
		str_to_write << "E";
		str_to_write << "R";
		str_to_write << "\\D" << mult;
		str_to_write << "\\D" << div;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::SetFontbyindex(word font_index){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "A";
		str_to_write << "F";
		str_to_write << "\\D" << font_index;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::SetFontbyname(by_name font_name){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "A";
		str_to_write << "F";
		str_to_write << "\\m" << font_name << "\\0";
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::SetFontSpacing(byte_int x_spacing, byte_int y_spacing){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "A";
		str_to_write << "S";
		str_to_write << "\\d" << x_spacing;
		str_to_write << "\\d" << y_spacing;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::SetSymbolFont(bool on_off){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "A";
		str_to_write << "Y";
		str_to_write << "\\" << on_off;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::SetBoldMode(bool on_off){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "A";
		str_to_write << "B";
		str_to_write << "\\" << on_off;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::SetUnderlineMode(bool on_off){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "A";
		str_to_write << "U";
		str_to_write << "\\" << on_off;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::SetUnderlinePosition(signed_byte position){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "A";
		str_to_write << "u";
		str_to_write << "\\d" << position;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::SetInverseMode(bool on_off){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "A";
		str_to_write << "I";
		str_to_write << "\\" << on_off;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::SetTransparentModeOnOff(bool on_off){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "A";
		str_to_write << "T";
		str_to_write << "\\" << on_off;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::SetForegroundColor(color color_value){ 
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "A";
		str_to_write << "C";
		str_to_write << "F";
		str_to_write << "\\#" << std::hex << color_value.to_ulong();
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

COLORREF inverse(COLORREF c) {
	return RGB(GetBValue(c), GetGValue(c),GetRValue(c));
}
void Screen::SetForegroundColor(COLORREF color_value){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "A";
		str_to_write << "C";
		str_to_write << "F";
		str_to_write << "\\#" << std::hex <<inverse(color_value);
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}
void Screen::SetForegroundColorRGB(unsigned RedVal, unsigned GreenVal, unsigned BlueVal){
	if (RedVal > 255 || GreenVal > 255 || BlueVal > 255){
		cout << "color values out of boundaries " << endl;
		return;
	}
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "A";
		str_to_write << "C";
		str_to_write << "F";
		str_to_write << "\\#" << std::hex << RedVal << std::hex << GreenVal << std::hex << BlueVal;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}
void Screen::SetBackgroundColor(color color_value){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "A";
		str_to_write << "C";
		str_to_write << "B";
		str_to_write << "\\#" << std::hex << color_value;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}
void Screen::SetBackgroundColorRGB(unsigned RedVal, unsigned GreenVal, unsigned BlueVal){
	if (RedVal > 255 || GreenVal > 255 || BlueVal > 255){
		cout << "color values out of boundaries " << endl;
		return;
	}
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "A";
		str_to_write << "C";
		str_to_write << "B";
		str_to_write << "\\#" << std::hex << RedVal << std::hex << GreenVal << std::hex << BlueVal;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}
void Screen::SetBorderColor(color color_value){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "A";
		str_to_write << "C";
		str_to_write << "R";
		str_to_write << "\\#" << std::hex << color_value;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}
void Screen::SetBorderColorRGB(unsigned RedVal, unsigned GreenVal, unsigned BlueVal){
	if (RedVal > 255 || GreenVal > 255 || BlueVal > 255){
		cout << "color values out of boundaries " << endl;
		return;
	}
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "A";
		str_to_write << "C";
		str_to_write << "R";
		str_to_write << "\\#" << std::hex << RedVal << std::hex << GreenVal << std::hex << BlueVal;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}
void Screen::SetBorderShadowColor(color color_value){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "A";
		str_to_write << "C";
		str_to_write << "S";
		str_to_write << "\\#" << std::hex << color_value;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}
void Screen::SetBorderShadowColorRGB(unsigned RedVal, unsigned GreenVal, unsigned BlueVal){
	if (RedVal > 255 || GreenVal > 255 || BlueVal > 255){
		cout << "color values out of boundaries " << endl;
		return;
	}
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "A";
		str_to_write << "C";
		str_to_write << "S";
		str_to_write << "\\#" << std::hex << RedVal << std::hex << GreenVal << std::hex << BlueVal;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}
void Screen::SetShadowOffset(signed_byte x_offset, signed_byte y_offset){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "A";
		str_to_write << "H";
		str_to_write << "S";
		str_to_write << "\\d" << x_offset;
		str_to_write << "\\d" << y_offset;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::SetRectangleCornerRadius(word radius){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "A";
		str_to_write << "H";
		str_to_write << "R";
		str_to_write << "\\D" << radius;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::SetLineThickness(byte_int thickness){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "A";
		str_to_write << "L";
		str_to_write << "T";
		str_to_write << "\\d" << thickness;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::SetLineCapsStyle(byte_int style){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "A";
		str_to_write << "L";
		str_to_write << "C";
		str_to_write << "\\d" << style;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::SetLineEndingMode(LineDrawMode mode){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "A";
		str_to_write << "L";
		str_to_write << "M";
		str_to_write << "\\d" << mode;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::SetAlpha(byte_int alpha){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "A";
		str_to_write << "A";
		str_to_write << "A";
		str_to_write << "\\d" << alpha;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::SetFillingColor(color color_value){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "A";
		str_to_write << "P";
		str_to_write << "C";
		str_to_write << "\\#" << std::hex << color_value;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}
void Screen::SetFillingColorRGB(unsigned RedVal, unsigned GreenVal, unsigned BlueVal){
	if (RedVal > 255 || GreenVal > 255 || BlueVal > 255){
		cout << "color values out of boundaries " << endl;
		return;
	}
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "A";
		str_to_write << "P";
		str_to_write << "C";
		str_to_write << "\\#" << std::hex << RedVal << std::hex << GreenVal << std::hex << BlueVal;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}
void Screen::SetFillingGradient(GradientMode mode, word ramp, color from_color, color to_color){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "A";
		str_to_write << "P";
		str_to_write << "G";
		str_to_write << "\\d" << mode;
		str_to_write << "\\D" << ramp;
		str_to_write << "\\#" << std::hex << from_color;
		str_to_write << "\\#" << std::hex << to_color;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}
void Screen::SetFillingGradientRGB(GradientMode mode, word ramp, unsigned RedValFrom, unsigned GreenValFrom, unsigned BlueValFrom, unsigned RedValTo, unsigned GreenValTo, unsigned BlueValTo){
	if (RedValFrom > 255 || GreenValFrom > 255 || BlueValFrom > 255 || RedValTo > 255 || GreenValTo > 255 || BlueValTo > 255){
		cout << "color values out of boundaries " << endl;
		return;
	}
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "A";
		str_to_write << "P";
		str_to_write << "G";
		str_to_write << "\\d" << mode;
		str_to_write << "\\D" << ramp;
		str_to_write << "\\#" << std::hex << RedValFrom << std::hex << GreenValFrom << std::hex << BlueValFrom;
		str_to_write << "\\#" << std::hex << RedValTo << std::hex << GreenValTo << std::hex << BlueValTo;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::SetFillingTilebyindex(word graphic_index){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "A";
		str_to_write << "P";
		str_to_write << "T";
		str_to_write << "\\D" << graphic_index;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::SetFillingTilebyname(by_name graphic_name){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "A";
		str_to_write << "P";
		str_to_write << "T";
		str_to_write << "\\m" << graphic_name << "\\0";
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::SetFillingTilebyfilename(by_file graphic_filename){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "A";
		str_to_write << "P";
		str_to_write << "T";
		str_to_write << "\\f" << graphic_filename << "\\0";
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::SetAdjustmentforGraphics(bits mode){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "A";
		str_to_write << "A";
		str_to_write << "G";
		str_to_write << "\\d" << mode;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::SetBrightnessAdjustment(signed_word value){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "A";
		str_to_write << "A";
		str_to_write << "B";
		str_to_write << "\\D" << value;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::SetContrastAdjustment(signed_word value){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "A";
		str_to_write << "A";
		str_to_write << "C";
		str_to_write << "\\D" << value;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::SetHueAdjustment(signed_word value){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "A";
		str_to_write << "A";
		str_to_write << "H";
		str_to_write << "\\D" << value;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::SetSaturationAdjustment(signed_word value){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "A";
		str_to_write << "A";
		str_to_write << "S";
		str_to_write << "\\D" << value;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::EraseDisplay(){
	if (out_file.is_open()){
		std::string str_to_write;
		str_to_write = "\\i";
		str_to_write += "D";
		str_to_write += "E";
		str_to_write += "\n";
		out_file.write(str_to_write.c_str(), str_to_write.size());
	}
}

void Screen::EraseDisplayArea(word width, word height){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "D";
		str_to_write << "e";
		str_to_write << "\\D" << width;
		str_to_write << "\\D" << height;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::InvertDisplay(){
	if (out_file.is_open()){
		std::string str_to_write;
		str_to_write = "\\i";
		str_to_write += "D";
		str_to_write += "I";
		str_to_write += "\n";
		out_file.write(str_to_write.c_str(), str_to_write.size());
	}
}

void Screen::InvertDisplayArea(word width, word height){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "D";
		str_to_write << "i";
		str_to_write << "\\D" << width;
		str_to_write << "\\D" << height;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::WriteText(string text_string){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "D";
		str_to_write << "T";
		str_to_write << text_string << "\\0";
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::WriteUnicodeText(string unicode_text){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "D";
		str_to_write << "U";
		str_to_write << unicode_text << "\\0";
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::WriteTextMessagebyindex(word message_index){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "D";
		str_to_write << "t";
		str_to_write << "\\D" << message_index;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::WriteTextMessagebyname(by_name message_name){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "D";
		str_to_write << "t";
		str_to_write << "\\m" << message_name << "\\0";
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::ScrollUp(word scroll_y){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "D";
		str_to_write << "S";
		str_to_write << "U";
		str_to_write << "\\D" << scroll_y;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::ScrollDown(word scroll_y){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "D";
		str_to_write << "S";
		str_to_write << "D";
		str_to_write << "\\D" << scroll_y;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::ScrollLeft(word scroll_x){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "D";
		str_to_write << "S";
		str_to_write << "L";
		str_to_write << "\\D" << scroll_x;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::ScrollRight(word scroll_x){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "D";
		str_to_write << "S";
		str_to_write << "R";
		str_to_write << "\\D" << scroll_x;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::WriteScanLine(word no_of_pixels, color_16bit p0){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "D";
		str_to_write << "N";
		str_to_write << "W";
		str_to_write << "\\D" << no_of_pixels;
		str_to_write << "\\X" << std::hex << p0;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::ReadScanLine(word no_of_pixels){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "D";
		str_to_write << "N";
		str_to_write << "R";
		str_to_write << "\\D" << no_of_pixels;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::Write1D2DRunLengthEncodedScanLine(signed_byte prev_line_offset, word no_of_pixels, word no_of_rle_bytes, byte_int b0){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "D";
		str_to_write << "N";
		str_to_write << "w";
		str_to_write << "\\d" << prev_line_offset;
		str_to_write << "\\D" << no_of_pixels;
		str_to_write << "\\D" << no_of_rle_bytes;
		str_to_write << "\\d" << b0;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::Read1D2DRunLengthEncodedScanLine(signed_byte prev_line_offset, word no_of_pixels){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "D";
		str_to_write << "N";
		str_to_write << "r";
		str_to_write << "\\d" << prev_line_offset;
		str_to_write << "\\D" << no_of_pixels;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::SetClearPixel(bool on_off){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "D";
		str_to_write << "P";
		str_to_write << "\\" << on_off;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::SetClearPixelatXY(word pos_x, word pos_y, bool on_off){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "D";
		str_to_write << "p";
		str_to_write << "\\D" << pos_x;
		str_to_write << "\\D" << pos_y;
		str_to_write << "\\" << on_off;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::DrawDot(color color_value){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "D";
		str_to_write << "D";
		str_to_write << "\\#" << std::hex << color_value;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}
void Screen::DrawDotRGB(unsigned RedVal, unsigned GreenVal, unsigned BlueVal){
	if (RedVal > 255 || GreenVal > 255 || BlueVal > 255){
		cout << "color values out of boundaries " << endl;
		return;
	}
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "D";
		str_to_write << "D";
		str_to_write << "\\#" << std::hex << RedVal << std::hex << GreenVal << std::hex << BlueVal;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::DrawDotatXY(word pos_x, word pos_y, color color_value){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "D";
		str_to_write << "d";
		str_to_write << "\\D" << pos_x;
		str_to_write << "\\D" << pos_y;
		str_to_write << "\\#" << std::hex << color_value;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}
void Screen::DrawDotatXYRGB(word pos_x, word pos_y, unsigned RedVal, unsigned GreenVal, unsigned BlueVal){
	if (RedVal > 255 || GreenVal > 255 || BlueVal > 255){
		cout << "color values out of boundaries " << endl;
		return;
	}
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "D";
		str_to_write << "d";
		str_to_write << "\\D" << pos_x;
		str_to_write << "\\D" << pos_y;
		str_to_write << "\\#" << std::hex << RedVal << std::hex << GreenVal << std::hex << BlueVal;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}
void Screen::DrawLine(word end_x, word end_y){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "D";
		str_to_write << "L";
		str_to_write << "\\D" << end_x;
		str_to_write << "\\D" << end_y;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::DrawRectangle(RectangleMode mode, word width, word height){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "D";
		str_to_write << "R";
		str_to_write << "\\d" << mode;
		str_to_write << "\\D" << width;
		str_to_write << "\\D" << height;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::DrawCircle(word radius){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "D";
		str_to_write << "C";
		str_to_write << "\\D" << radius;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::DrawStyledCircle(CircleMode mode, word radius){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "D";
		str_to_write << "c";
		str_to_write << "\\d" << mode;
		str_to_write << "\\D" << radius;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::DrawEllipse(EllipseMode mode, word vertex_a, word vertex_b){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "D";
		str_to_write << "Y";
		str_to_write << "\\d" << mode;
		str_to_write << "\\D" << vertex_a;
		str_to_write << "\\D" << vertex_b;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::AdjustDisplay(DisplayAdjust mode){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "D";
		str_to_write << "A";
		str_to_write << "\\d" << mode;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::AdjustDisplayArea(DisplayAreaAdjust mode, word width, word height){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "D";
		str_to_write << "a";
		str_to_write << "\\d" << mode;
		str_to_write << "\\D" << width;
		str_to_write << "\\D" << height;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::FillDisplay(){
	if (out_file.is_open()){
		std::string str_to_write;
		str_to_write = "\\i";
		str_to_write += "D";
		str_to_write += "F";
		str_to_write += "\n";
		out_file.write(str_to_write.c_str(), str_to_write.size());
	}
}

void Screen::FillDisplayArea(word width, word height){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "D";
		str_to_write << "f";
		str_to_write << "\\D" << width;
		str_to_write << "\\D" << height;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::DisplayLocalGraphicbyindex(word graphic_index){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "G";
		str_to_write << "\\D" << graphic_index;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::DisplayLocalGraphicbyname(by_name graphic_name){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "G";
		str_to_write << "\\m" << graphic_name << "\\0";
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::DisplayLocalGraphicbyfilename(by_file graphic_filename){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "G";
		str_to_write << "\\f" << graphic_filename << "\\0";
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::DisplayGraphicAreabyname(word offset_x, word offset_y, word width, word height, by_name graphic_name){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "g";
		str_to_write << "A";
		str_to_write << "\\D" << offset_x;
		str_to_write << "\\D" << offset_y;
		str_to_write << "\\D" << width;
		str_to_write << "\\D" << height;
		str_to_write << "\\m" << graphic_name << "\\0";
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::DisplayGraphicAreabyfilename(word offset_x, word offset_y, word width, word height, by_file graphic_filename){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "g";
		str_to_write << "A";
		str_to_write << "\\D" << offset_x;
		str_to_write << "\\D" << offset_y;
		str_to_write << "\\D" << width;
		str_to_write << "\\D" << height;
		str_to_write << "\\f" << graphic_filename << "\\0";
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::LoadAnimatedGraphicsbyindex(byte_int anim_loc, word anim_graph_index){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "g";
		str_to_write << "L";
		str_to_write << "\\d" << anim_loc;
		str_to_write << "\\D" << anim_graph_index;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::LoadAnimatedGraphicsbyname(byte_int anim_loc, by_name anim_graph_name){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "g";
		str_to_write << "L";
		str_to_write << "\\d" << anim_loc;
		str_to_write << "\\m" << anim_graph_name << "\\0";
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::LoadAnimatedGraphicsbyfilename(byte_int anim_loc, by_file anim_graph_filename){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "g";
		str_to_write << "L";
		str_to_write << "\\d" << anim_loc;
		str_to_write << "\\f" << anim_graph_filename << "\\0";
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::SetAnimationCoordinatestoXY(byte_int anim_loc, word pos_x, word pos_y){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "g";
		str_to_write << "K";
		str_to_write << "\\d" << anim_loc;
		str_to_write << "\\D" << pos_x;
		str_to_write << "\\D" << pos_y;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::SetAnimationCoordinatestoCursorPosition(byte_int anim_loc){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "g";
		str_to_write << "k";
		str_to_write << "\\d" << anim_loc;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::StartorRestartAnimation(byte_int anim_loc){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "g";
		str_to_write << "S";
		str_to_write << "\\d" << anim_loc;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::StopAnimationandSetFrameNumber(byte_int anim_loc, word frame){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "g";
		str_to_write << "F";
		str_to_write << "\\d" << anim_loc;
		str_to_write << "\\D" << frame;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::StopAnimation(byte_int anim_loc){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "g";
		str_to_write << "B";
		str_to_write << "\\d" << anim_loc;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::SetAnimationRepetitions(byte_int anim_loc, word repeat){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "g";
		str_to_write << "R";
		str_to_write << "\\d" << anim_loc;
		str_to_write << "\\D" << repeat;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::EraseAnimationImageArea(byte_int anim_loc){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "g";
		str_to_write << "E";
		str_to_write << "\\d" << anim_loc;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::EraseAnimationFrameArea(byte_int anim_loc){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "g";
		str_to_write << "e";
		str_to_write << "\\d" << anim_loc;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::SuspendAnimationEngine(){
	if (out_file.is_open()){
		std::string str_to_write;
		str_to_write = "\\i";
		str_to_write += "g";
		str_to_write += "s";
		str_to_write += "\n";
		out_file.write(str_to_write.c_str(), str_to_write.size());
	}
}

void Screen::ResumeAnimationEngine(){
	if (out_file.is_open()){
		std::string str_to_write;
		str_to_write = "\\i";
		str_to_write += "g";
		str_to_write += "r";
		str_to_write += "\n";
		out_file.write(str_to_write.c_str(), str_to_write.size());
	}
}

void Screen::MoveAnimation(byte_int anim_loc, word frame_idx, bool run_backwards){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "g";
		str_to_write << "M";
		str_to_write << "\\d" << anim_loc;
		str_to_write << "\\D" << frame_idx;
		str_to_write << "\\" << run_backwards;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::SetAnimationBackgroundColor(byte_int anim_loc, color color_value){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "g";
		str_to_write << "b";
		str_to_write << "C";
		str_to_write << "\\d" << anim_loc;
		str_to_write << "\\#" << std::hex << color_value;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}
void Screen::SetAnimationBackgroundColorRGB(byte_int anim_loc, unsigned RedVal, unsigned GreenVal, unsigned BlueVal){
	if (RedVal > 255 || GreenVal > 255 || BlueVal > 255){
		cout << "color values out of boundaries " << endl;
		return;
	}
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "g";
		str_to_write << "b";
		str_to_write << "C";
		str_to_write << "\\d" << anim_loc;
		str_to_write << "\\#" << std::hex << RedVal << std::hex << GreenVal << std::hex << BlueVal;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::SetAnimationBackgroundFrame(byte_int anim_loc, word frame){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "g";
		str_to_write << "b";
		str_to_write << "F";
		str_to_write << "\\d" << anim_loc;
		str_to_write << "\\D" << frame;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::SetAnimationBackgroundGraphicbyindex(byte_int anim_loc, word offset_x, word offset_y, word graphic_index){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "g";
		str_to_write << "b";
		str_to_write << "G";
		str_to_write << "\\d" << anim_loc;
		str_to_write << "\\D" << offset_x;
		str_to_write << "\\D" << offset_y;
		str_to_write << "\\D" << graphic_index;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::SetAnimationBackgroundGraphicbyname(byte_int anim_loc, word offset_x, word offset_y, by_name graphic_name){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "g";
		str_to_write << "b";
		str_to_write << "G";
		str_to_write << "\\d" << anim_loc;
		str_to_write << "\\D" << offset_x;
		str_to_write << "\\D" << offset_y;
		str_to_write << "\\m" << graphic_name << "\\0";
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::SetAnimationBackgroundGraphicbyfilename(byte_int anim_loc, word offset_x, word offset_y, by_file graphic_filename){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "g";
		str_to_write << "b";
		str_to_write << "G";
		str_to_write << "\\d" << anim_loc;
		str_to_write << "\\D" << offset_x;
		str_to_write << "\\D" << offset_y;
		str_to_write << "\\f" << graphic_filename << "\\0";
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::SetAnimationBackgroundScreen(byte_int anim_loc, word bg_offset_x, word bg_offset_y, byte_int screen){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "g";
		str_to_write << "b";
		str_to_write << "S";
		str_to_write << "\\d" << anim_loc;
		str_to_write << "\\D" << bg_offset_x;
		str_to_write << "\\D" << bg_offset_y;
		str_to_write << "\\d" << screen;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::RemoveAnimationBackground(byte_int anim_loc){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "g";
		str_to_write << "b";
		str_to_write << "N";
		str_to_write << "\\d" << anim_loc;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::GetNumberofScreens(){
	if (out_file.is_open()){
		std::string str_to_write;
		str_to_write = "\\i";
		str_to_write += "M";
		str_to_write += "S";
		str_to_write += "?";
		str_to_write += "\n";
		out_file.write(str_to_write.c_str(), str_to_write.size());
	}
}

void Screen::SetViewScreen(byte_int index){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "M";
		str_to_write << "V";
		str_to_write << "\\d" << index;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::GetViewScreenParameters(){
	if (out_file.is_open()){
		std::string str_to_write;
		str_to_write = "\\i";
		str_to_write += "M";
		str_to_write += "?";
		str_to_write += "V";
		str_to_write += "\n";
		out_file.write(str_to_write.c_str(), str_to_write.size());
	}
}

void Screen::SetDrawScreen(byte_int screen){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "M";
		str_to_write << "D";
		str_to_write << "\\d" << screen;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::GetDrawScreenParameters(){
	if (out_file.is_open()){
		std::string str_to_write;
		str_to_write = "\\i";
		str_to_write += "M";
		str_to_write += "?";
		str_to_write += "D";
		str_to_write += "\n";
		out_file.write(str_to_write.c_str(), str_to_write.size());
	}
}

void Screen::CopyScreenArea(word width, word height, byte_int screen, word pos_x, word pos_y){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "M";
		str_to_write << "A";
		str_to_write << "\\D" << width;
		str_to_write << "\\D" << height;
		str_to_write << "\\d" << screen;
		str_to_write << "\\D" << pos_x;
		str_to_write << "\\D" << pos_y;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::CopyScreenTo(byte_int screen){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "M";
		str_to_write << "S";
		str_to_write << "S";
		str_to_write << "\\d" << screen;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::CopyScreenFrom(byte_int screen){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "M";
		str_to_write << "S";
		str_to_write << "C";
		str_to_write << "\\d" << screen;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::PaintScreenFrom(byte_int screen){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "M";
		str_to_write << "S";
		str_to_write << "P";
		str_to_write << "\\d" << screen;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::InvertScreen(byte_int screen){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "M";
		str_to_write << "S";
		str_to_write << "I";
		str_to_write << "\\d" << screen;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::ScrollUpScreen(byte_int screen, word scroll_y){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "M";
		str_to_write << "S";
		str_to_write << "U";
		str_to_write << "\\d" << screen;
		str_to_write << "\\D" << scroll_y;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::ScrollDownScreen(byte_int screen, word scroll_y){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "M";
		str_to_write << "S";
		str_to_write << "D";
		str_to_write << "\\d" << screen;
		str_to_write << "\\D" << scroll_y;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::ScrollLeftScreen(byte_int screen, word scroll_x){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "M";
		str_to_write << "S";
		str_to_write << "L";
		str_to_write << "\\d" << screen;
		str_to_write << "\\D" << scroll_x;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::ScrollRightScreen(byte_int screen, word scroll_x){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "M";
		str_to_write << "S";
		str_to_write << "R";
		str_to_write << "\\d" << screen;
		str_to_write << "\\D" << scroll_x;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::SetHeightofScreen(byte_int screen, word height){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "M";
		str_to_write << "S";
		str_to_write << "H";
		str_to_write << "\\d" << screen;
		str_to_write << "\\D" << height;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::SetWidthofScreen(byte_int screen, word width){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "M";
		str_to_write << "S";
		str_to_write << "W";
		str_to_write << "\\d" << screen;
		str_to_write << "\\D" << width;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::SaveCursorAttributestoMemory(byte_int index){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "M";
		str_to_write << "C";
		str_to_write << "S";
		str_to_write << "\\d" << index;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::RestoreCursorAttributesfromMemory(byte_int index){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "M";
		str_to_write << "C";
		str_to_write << "C";
		str_to_write << "\\d" << index;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::ExecuteMacrobyindex(word macro_index){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "O";
		str_to_write << "E";
		str_to_write << "\\D" << macro_index;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::ExecuteMacrobyname(by_name macro_name){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "O";
		str_to_write << "E";
		str_to_write << "\\m" << macro_name << "\\0";
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::ExecuteProtectedMacrobyindex(word macro_index){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "O";
		str_to_write << "e";
		str_to_write << "\\D" << macro_index;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::ExecuteProtectedMacrobyname(by_name macro_name){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "O";
		str_to_write << "e";
		str_to_write << "\\m" << macro_name << "\\0";
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::JumptoMacrobyindex(word macro_index){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "O";
		str_to_write << "J";
		str_to_write << "\\D" << macro_index;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::JumptoMacrobyname(by_name macro_name){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "O";
		str_to_write << "J";
		str_to_write << "\\m" << macro_name << "\\0";
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::DelayMacroExecution(word delay){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "O";
		str_to_write << "D";
		str_to_write << "\\D" << delay;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::SetMacroExecutionSpeed(word speed){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "O";
		str_to_write << "S";
		str_to_write << "\\D" << speed;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::AllowKeyboardTouchEventstobeProcessed(){
	if (out_file.is_open()){
		std::string str_to_write;
		str_to_write = "\\i";
		str_to_write += "O";
		str_to_write += "K";
		str_to_write += "\n";
		out_file.write(str_to_write.c_str(), str_to_write.size());
	}
}

void Screen::SetMacroTimer(byte_int time){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "O";
		str_to_write << "T";
		str_to_write << "\\d" << time;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::CalibrateTouchScreen(){
	if (out_file.is_open()){
		std::string str_to_write;
		str_to_write = "\\i";
		str_to_write += "T";
		str_to_write += "C";
		str_to_write += "\n";
		out_file.write(str_to_write.c_str(), str_to_write.size());
	}
}

void Screen::CalibrateTouchScreenandReport(){
	if (out_file.is_open()){
		std::string str_to_write;
		str_to_write = "\\i";
		str_to_write += "T";
		str_to_write += "c";
		str_to_write += "\n";
		out_file.write(str_to_write.c_str(), str_to_write.size());
	}
}

void Screen::VerifyTouchScreenCalibration(){
	if (out_file.is_open()){
		std::string str_to_write;
		str_to_write = "\\i";
		str_to_write += "T";
		str_to_write += "V";
		str_to_write += "\n";
		out_file.write(str_to_write.c_str(), str_to_write.size());
	}
}

void Screen::SetTouchFieldWidth(word width){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "T";
		str_to_write << "W";
		str_to_write << "\\D" << width;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::SetTouchFieldHeight(word height){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "T";
		str_to_write << "H";
		str_to_write << "\\D" << height;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::SetTouchFieldMakeMacrobyindex(word macro_index){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "T";
		str_to_write << "M";
		str_to_write << "\\D" << macro_index;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::SetTouchFieldMakeMacrobyname(by_name macro_name){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "T";
		str_to_write << "M";
		str_to_write << "\\m" << macro_name << "\\0";
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::SetTouchFieldBreakMacrobyindex(word macro_index){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "T";
		str_to_write << "B";
		str_to_write << "\\D" << macro_index;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::SetTouchFieldBreakMacrobyname(by_name macro_name){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "T";
		str_to_write << "B";
		str_to_write << "\\m" << macro_name << "\\0";
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::EnableDisableAutomaticTouchMacroExecuting(bool on_off){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "T";
		str_to_write << "E";
		str_to_write << "A";
		str_to_write << "\\" << on_off;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::SetTouchFieldTextMessagebyindex(word message_index){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "T";
		str_to_write << "T";
		str_to_write << "\\D" << message_index;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::SetTouchFieldTextMessagebyname(by_name message_name){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "T";
		str_to_write << "T";
		str_to_write << "\\m" << message_name << "\\0";
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::CreateDefineTouchField(byte_int field_idx, byte_int key){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "T";
		str_to_write << "A";
		str_to_write << "\\d" << field_idx;
		str_to_write << "\\d" << key;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::RemoveTouchField(byte_int field_idx){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "T";
		str_to_write << "R";
		str_to_write << "\\d" << field_idx;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::GlobalEnableDisableTouchFields(bool on_off){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "T";
		str_to_write << "G";
		str_to_write << "\\" << on_off;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::SetCurrentTouchFieldIndex(byte_int field_idx){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "T";
		str_to_write << "I";
		str_to_write << "\\d" << field_idx;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::ExecuteTouchMakeMacro(byte_int field_idx){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "T";
		str_to_write << "E";
		str_to_write << "M";
		str_to_write << "\\d" << field_idx;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::ExecuteTouchBreakMacro(byte_int field_idx){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "T";
		str_to_write << "E";
		str_to_write << "B";
		str_to_write << "\\d" << field_idx;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::DrawTouchFieldTextMessage(byte_int field_idx){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "T";
		str_to_write << "D";
		str_to_write << "\\d" << field_idx;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::SetCursortoTouchField(byte_int field_idx){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "T";
		str_to_write << "E";
		str_to_write << "C";
		str_to_write << "\\d" << field_idx;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::EnableDisableTouchFieldReporting(bool on_off){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "T";
		str_to_write << "P";
		str_to_write << "\\" << on_off;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::EnableDisableReportingTouchCoordinates(bool on_off){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "T";
		str_to_write << "K";
		str_to_write << "\\" << on_off;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::EnableDisableReportingMovements(bool on_off){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "T";
		str_to_write << "O";
		str_to_write << "\\" << on_off;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::RetrieveLastTouchScreenEvent(){
	if (out_file.is_open()){
		std::string str_to_write;
		str_to_write = "\\i";
		str_to_write += "T";
		str_to_write += "?";
		str_to_write += "\n";
		out_file.write(str_to_write.c_str(), str_to_write.size());
	}
}

void Screen::SetNumberofTouchFingers(byte_int fingers){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "T";
		str_to_write << "S";
		str_to_write << "N";
		str_to_write << "\\d" << fingers;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::SetThresholdforMovementReporting(byte_int threshold){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "T";
		str_to_write << "S";
		str_to_write << "M";
		str_to_write << "\\d" << threshold;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::EnableDisableTouchFieldQueue(bool on_off){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "T";
		str_to_write << "Q";
		str_to_write << "\\" << on_off;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::StartDemonstrationModebyindex(byte_int mode, word timeout, word macro_index){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "T";
		str_to_write << "v";
		str_to_write << "\\d" << mode;
		str_to_write << "\\D" << timeout;
		str_to_write << "\\D" << macro_index;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::StartDemonstrationModebyname(byte_int mode, word timeout, by_name macro_name){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "T";
		str_to_write << "v";
		str_to_write << "\\d" << mode;
		str_to_write << "\\D" << timeout;
		str_to_write << "\\m" << macro_name << "\\0";
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::SetOutput(byte_int out_no, OutputMode mode){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "I";
		str_to_write << "L";
		str_to_write << "S";
		str_to_write << "\\d" << out_no;
		str_to_write << "\\d" << mode;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::SetMultipleOutputs(wbits out_mask, wbits blink_mask){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "I";
		str_to_write << "L";
		str_to_write << "s";
		str_to_write << "\\X" << std::hex << out_mask;
		str_to_write << "\\X" << std::hex <<blink_mask;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::SetOutputBlinkFrequency(byte_int period){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "I";
		str_to_write << "L";
		str_to_write << "F";
		str_to_write << "\\d" << period;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::SetRelaysOnOffPWM(byte_int relay_no, RelayMode mode){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "I";
		str_to_write << "R";
		str_to_write << "\\d" << relay_no;
		str_to_write << "\\d" << mode;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::RelaysOneShot(byte_int relay_no, bool on_off, word time){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "I";
		str_to_write << "r";
		str_to_write << "\\d" << relay_no;
		str_to_write << "\\" << on_off;
		str_to_write << "\\D" << time;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::EnableDisableRotaryEncoderReporting(bool on_off){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "I";
		str_to_write << "E";
		str_to_write << "\\" << on_off;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::EnableDisableKeyboard(bool on_off){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "I";
		str_to_write << "K";
		str_to_write << "E";
		str_to_write << "\\" << on_off;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::EnableDisableKeyboardReporting(bool on_off){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "I";
		str_to_write << "K";
		str_to_write << "R";
		str_to_write << "\\" << on_off;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::GetKeyboardState(){
	if (out_file.is_open()){
		std::string str_to_write;
		str_to_write = "\\i";
		str_to_write += "I";
		str_to_write += "K";
		str_to_write += "?";
		str_to_write += "\n";
		out_file.write(str_to_write.c_str(), str_to_write.size());
	}
}

void Screen::SetBaudRate(byte_int port_no, Long baud){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "I";
		str_to_write << "B";
		str_to_write << "\\d" << port_no;
		str_to_write << "\\L" << baud;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::GetCurrentCommunicationPort(){
	if (out_file.is_open()){
		std::string str_to_write;
		str_to_write = "\\i";
		str_to_write += "I";
		str_to_write += "?";
		str_to_write += "C";
		str_to_write += "\n";
		out_file.write(str_to_write.c_str(), str_to_write.size());
	}
}

void Screen::EnableDisableCommunicationPorts(PortNumbers port_mask, word timeout){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "I";
		str_to_write << "C";
		str_to_write << "D";
		str_to_write << "\\d" << port_mask;
		str_to_write << "\\D" << timeout;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::GetEnabledCommunicationPorts(){
	if (out_file.is_open()){
		std::string str_to_write;
		str_to_write = "\\i";
		str_to_write += "I";
		str_to_write += "C";
		str_to_write += "?";
		str_to_write += "\n";
		out_file.write(str_to_write.c_str(), str_to_write.size());
	}
}

void Screen::GetInputsState(){
	if (out_file.is_open()){
		std::string str_to_write;
		str_to_write = "\\i";
		str_to_write += "I";
		str_to_write += "?";
		str_to_write += "I";
		str_to_write += "\n";
		out_file.write(str_to_write.c_str(), str_to_write.size());
	}
}

void Screen::GetADCValue(byte_int port){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "I";
		str_to_write << "?";
		str_to_write << "A";
		str_to_write << "\\d" << port;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::RequestDiskStatus(){
	if (out_file.is_open()){
		std::string str_to_write;
		str_to_write = "\\i";
		str_to_write += "S";
		str_to_write += "?";
		str_to_write += "\n";
		out_file.write(str_to_write.c_str(), str_to_write.size());
	}
}

void Screen::MakeDirectory(file dirname){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "S";
		str_to_write << "M";
		str_to_write << dirname << "\\0";
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::GetFileStatus(file filename){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "S";
		str_to_write << "G";
		str_to_write << filename << "\\0";
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::OpenDirectoryandReadFirstEntry(file dirname){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "S";
		str_to_write << "F";
		str_to_write << dirname << "\\0";
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::ReadNextEntry(){
	if (out_file.is_open()){
		std::string str_to_write;
		str_to_write = "\\i";
		str_to_write += "S";
		str_to_write += "N";
		str_to_write += "\n";
		out_file.write(str_to_write.c_str(), str_to_write.size());
	}
}

void Screen::DeleteFile(file filename){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "S";
		str_to_write << "K";
		str_to_write << filename << "\\0";
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::OpenFile(byte_int handle, FileAccessMode mode, file filename){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "S";
		str_to_write << "O";
		str_to_write << "\\d" << handle;
		str_to_write << "\\d" << mode;
		str_to_write << filename << "\\0";
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::CloseFile(byte_int handle){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "S";
		str_to_write << "C";
		str_to_write << "\\d" << handle;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::TellPositioninFile(byte_int handle){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "S";
		str_to_write << "P";
		str_to_write << "\\d" << handle;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::SetPositioninFile(byte_int handle, Long position){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "S";
		str_to_write << "S";
		str_to_write << "\\d" << handle;
		str_to_write << "\\L" << position;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::ReadFile(byte_int handle, word count){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "S";
		str_to_write << "R";
		str_to_write << "\\d" << handle;
		str_to_write << "\\D" << count;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::ReadStringfromFile(byte_int handle, byte_int endchar){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "S";
		str_to_write << "r";
		str_to_write << "\\d" << handle;
		str_to_write << "\\d" << endchar;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::WriteFile(byte_int handle, word count, byte_int b0){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "S";
		str_to_write << "W";
		str_to_write << "\\d" << handle;
		str_to_write << "\\D" << count;
		str_to_write << "\\d" << b0;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::WriteStringtoFile(byte_int handle, string text_string){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "S";
		str_to_write << "w";
		str_to_write << "\\d" << handle;
		str_to_write << text_string << "\\0";
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::TruncateFile(byte_int handle){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "S";
		str_to_write << "T";
		str_to_write << "\\d" << handle;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::WriteApplicationDatatoFlash(FlashUpdateFlags flags, file filename){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "S";
		str_to_write << "A";
		str_to_write << "\\d" << flags;
		str_to_write << filename << "\\0";
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::UnmountMicroSDCard(){
	if (out_file.is_open()){
		std::string str_to_write;
		str_to_write = "\\i";
		str_to_write += "S";
		str_to_write += "U";
		str_to_write += "\n";
		out_file.write(str_to_write.c_str(), str_to_write.size());
	}
}

void Screen::SetTime(byte_int hour, byte_int minute, byte_int second){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "I";
		str_to_write << "T";
		str_to_write << "\\d" << hour;
		str_to_write << "\\d" << minute;
		str_to_write << "\\d" << second;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::GetTime(){
	if (out_file.is_open()){
		std::string str_to_write;
		str_to_write = "\\i";
		str_to_write += "I";
		str_to_write += "?";
		str_to_write += "T";
		str_to_write += "\n";
		out_file.write(str_to_write.c_str(), str_to_write.size());
	}
}

void Screen::SetDate(byte_int year, byte_int month, byte_int day, byte_int weekday){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "I";
		str_to_write << "D";
		str_to_write << "\\d" << year;
		str_to_write << "\\d" << month;
		str_to_write << "\\d" << day;
		str_to_write << "\\d" << weekday;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::GetDate(){
	if (out_file.is_open()){
		std::string str_to_write;
		str_to_write = "\\i";
		str_to_write += "I";
		str_to_write += "?";
		str_to_write += "D";
		str_to_write += "\n";
		out_file.write(str_to_write.c_str(), str_to_write.size());
	}
}

void Screen::SetPWMNumber0(Long freq, word duty_cycle){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "I";
		str_to_write << "P";
		str_to_write << "\\L" << freq;
		str_to_write << "\\D" << duty_cycle;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::SetPWMNumber1(word duty_cycle){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "I";
		str_to_write << "P";
		str_to_write << "\\D" << duty_cycle;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::GetEEPROMSize(){
	if (out_file.is_open()){
		std::string str_to_write;
		str_to_write = "\\i";
		str_to_write += "E";
		str_to_write += "?";
		str_to_write += "\n";
		out_file.write(str_to_write.c_str(), str_to_write.size());
	}
}

void Screen::EraseEEPROM(){
	if (out_file.is_open()){
		std::string str_to_write;
		str_to_write = "\\i";
		str_to_write += "E";
		str_to_write += "E";
		str_to_write += "=";
		str_to_write += "\n";
		out_file.write(str_to_write.c_str(), str_to_write.size());
	}
}

void Screen::ReadEEPROM(word address){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "E";
		str_to_write << "R";
		str_to_write << "\\D" << address;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::WriteEEPROM(word address, byte_int data){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "E";
		str_to_write << "W";
		str_to_write << "\\D" << address;
		str_to_write << "\\d" << data;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::SetPCAPConfigurationtoFactoryDefault(){
	if (out_file.is_open()){
		std::string str_to_write;
		str_to_write = "\\i";
		str_to_write += "E";
		str_to_write += "P";
		str_to_write += "D";
		str_to_write += "\n";
		out_file.write(str_to_write.c_str(), str_to_write.size());
	}
}

void Screen::SetWatchdogInterval(word interval){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "P";
		str_to_write << "W";
		str_to_write << "\\D" << interval;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::FeedWatchdog(){
	if (out_file.is_open()){
		std::string str_to_write;
		str_to_write = "\\i";
		str_to_write += "P";
		str_to_write += "w";
		str_to_write += "\n";
		out_file.write(str_to_write.c_str(), str_to_write.size());
	}
}

void Screen::Shutdown(){
	if (out_file.is_open()){
		std::string str_to_write;
		str_to_write = "\\i";
		str_to_write += "P";
		str_to_write += "U";
		str_to_write += "=";
		str_to_write += "\n";
		out_file.write(str_to_write.c_str(), str_to_write.size());
	}
}

void Screen::HardShutdown(){
	if (out_file.is_open()){
		std::string str_to_write;
		str_to_write = "\\i";
		str_to_write += "P";
		str_to_write += "u";
		str_to_write += "=";
		str_to_write += "\n";
		out_file.write(str_to_write.c_str(), str_to_write.size());
	}
}

void Screen::CancelShutdown(){
	if (out_file.is_open()){
		std::string str_to_write;
		str_to_write = "\\i";
		str_to_write += "P";
		str_to_write += "U";
		str_to_write += "C";
		str_to_write += "\n";
		out_file.write(str_to_write.c_str(), str_to_write.size());
	}
}

void Screen::GetPowerState(){
	if (out_file.is_open()){
		std::string str_to_write;
		str_to_write = "\\i";
		str_to_write += "P";
		str_to_write += "?";
		str_to_write += "\n";
		out_file.write(str_to_write.c_str(), str_to_write.size());
	}
}

void Screen::ResetMotherboard(){
	if (out_file.is_open()){
		std::string str_to_write;
		str_to_write = "\\i";
		str_to_write += "P";
		str_to_write += "!";
		str_to_write += "=";
		str_to_write += "\n";
		out_file.write(str_to_write.c_str(), str_to_write.size());
	}
}

void Screen::SetSmartPowerOffMode(bool on_off){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "P";
		str_to_write << "S";
		str_to_write << "\\" << on_off;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::SetPowerOffNotificationOnOff(bool on_off){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "P";
		str_to_write << "N";
		str_to_write << "\\" << on_off;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::SetMessageOffset(word offset){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "X";
		str_to_write << "O";
		str_to_write << "T";
		str_to_write << "\\D" << offset;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::SetGraphicOffset(word offset){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "X";
		str_to_write << "O";
		str_to_write << "G";
		str_to_write << "\\D" << offset;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::SetMacroOffset(word offset){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "X";
		str_to_write << "O";
		str_to_write << "O";
		str_to_write << "\\D" << offset;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::SetFontOffset(word offset){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "X";
		str_to_write << "O";
		str_to_write << "F";
		str_to_write << "\\D" << offset;
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::SetMessageNamePrefix(string prefix){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "X";
		str_to_write << "P";
		str_to_write << "T";
		str_to_write << prefix << "\\0";
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::SetGraphicNamePrefix(string prefix){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "X";
		str_to_write << "P";
		str_to_write << "G";
		str_to_write << prefix << "\\0";
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::SetMacroNamePrefix(string prefix){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "X";
		str_to_write << "P";
		str_to_write << "O";
		str_to_write << prefix << "\\0";
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::SetFontNamePrefix(string prefix){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "X";
		str_to_write << "P";
		str_to_write << "F";
		str_to_write << prefix << "\\0";
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::SetMessageNameSuffix(string suffix){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "X";
		str_to_write << "S";
		str_to_write << "T";
		str_to_write << suffix << "\\0";
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::SetGraphicNameSuffix(string suffix){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "X";
		str_to_write << "S";
		str_to_write << "G";
		str_to_write << suffix << "\\0";
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::SetMacroNameSuffix(string suffix){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "X";
		str_to_write << "S";
		str_to_write << "O";
		str_to_write << suffix << "\\0";
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

void Screen::SetFontNameSuffix(string suffix){
	if (out_file.is_open()){
		std::ostringstream str_to_write;

		str_to_write << "\\i";
		str_to_write << "X";
		str_to_write << "S";
		str_to_write << "F";
		str_to_write << suffix << "\\0";
		str_to_write << "\n";

		std::string str_to_write_tmp = str_to_write.str();
		out_file.write(str_to_write_tmp.c_str(), str_to_write_tmp.size());
	}
}

