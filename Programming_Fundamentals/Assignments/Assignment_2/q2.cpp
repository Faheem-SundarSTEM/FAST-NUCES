#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    cout<< setfill(' ') << setw(17) << "/\\" << "\n"
        << setw(15) << "/" << setw(4) << "\\\n"
        << setw(14) << "/" << setw(6) << "\\\n"
        << setw(14) << "|" << setw(3) << "vv" << setw(3) << "|\n"
        << setw(14) << "|" << setw(3) << "!!" << setw(3) << "|\n"
        << setw(14) << "|" << setw(3) << "!!" << setw(3) << "|\n"
        << setw(14) << "|" << setw(3) << "!!" << setw(3) << "|\n"
        << setw(14) << "|" << setw(3) << "!!" << setw(3) << "|\n"
        << setw(14) << "|" << setw(3) << "!!" << setw(3) << "|\n"
        << setw(14) << "|" << setw(3) << "!!" << setw(3) << "|\n"
        << setw(14) << "|" << setw(3) << "!!" << setw(3) << "|\n"
        << setw(14) << "|" << setw(3) << "!!" << setw(3) << "|\n"
        << setw(14) << "|" << setw(3) << "!!" << setw(3) << "|\n"
        << setw(14) << "|" << setw(3) << "!!" << setw(3) << "|\n"
        << setw(14) << "|" << setw(3) << "!!" << setw(3) << "|\n"
        << setw(14) << "|" << setw(3) << "^^" << setw(3) << "|\n"
        << "|\\" << setw(11) << "/" << setw(4)<< "__"<< setw(3) << "\\" << setw(12) << "/|\n"
        << "|\'\\" << setfill('_') << setw(9) << "/" << setfill(' ') << setw(3) << "/" << setw(3) << "\\" <<setw(3)<< "\\" << setfill('_') << setw(9) << "/'" << setfill(' ') << setw(1) << "|" << "\n"
        << "|" << setw(6) << "[]" << setw(12) << "| /\\ |" << setw(7) << "[]" << setw(6) << "|\n"
        << "|. " << setfill('_')<<setw(8)<<"" <<setw(10)<< "  | \\/ |  " << setw(11) << " .|\n"
        << setw(1) << "\\_/" << setfill(' ') << setw(9) << "\\" << setfill(' ') << setw(9) << "\\__/  /" <<setw(10)<< "\\_/"<< "\n"
        << setfill(' ') << setw(13) << "\\" << setw(7) << "/" <<"\n"
        << setw(14) << "|" << setfill('X') << setw(6) << "|\n"
        << setfill(' ') << setw(14) << "|" << setfill('X') << setw(6) << "|\n"
        << setfill(' ') << setw(14) << "|" << setfill('X') << setw(6) << "|\n"
        << setfill(' ') << setw(14) << "|" << setfill('X') << setw(6) << "|\n"
        << setfill(' ') << setw(14) << "|" << setfill('X') << setw(6) << "|\n"
        << setfill(' ') << setw(11)<<"djf"<<setw(3) << "|" << setfill('X') << setw(6) <<"| " <<  " Darknessslayer121" << "\n"
        << setfill(' ') << setw(14) << "|" << setfill('X') << setw(6) << "|\n"
        << setfill(' ') << setw(14) << "|" << setfill('X') << setw(6) << "|\n"
        << setfill(' ') << setw(13) << "/" << setw(4) << "/\\" << setw(4) << "\\\n"
        << setfill(' ') << setw(12) << "/" <<setw(5) <<"--" << setw(5) << "\\\n"
        << setw(12) << "\\" << setfill('_') << setw(10) << "/\n";

    return 0;
}