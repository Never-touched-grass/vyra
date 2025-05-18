#include <iostream>
#include <string>
#include <vector>
using namespace std;
class vars {
public:
    vector<string> names;
    vector<int> intVals;
    vector<char> charVals;
    vector<float> floatVals;
    vector<string> stringVals;
};
class funcs {
public:
    vector<string> names;
    vector<vector<string>> codes;
};
int main() {
    vector<string> functionCode;
    string retrieveVarName;
    string retrieveFuncName;
    string retrieveVarType;
    string newFname;
    string fBlock;
    string fName;
    vector<string> codes;
    string codeBlock;
    vars varProps;
    funcs funcProps;
    string cmd;
    string type;
    string name;
    while (cmd != "break") {
        cout << ">";
        cin >> cmd;
        cin.ignore();
        int intPush;
        char charPush;
        float floatPush;
        string stringPush;
        if (cmd == "print") {
            cout << ":";
            getline(cin, cmd);
            if (cmd != "access") {
                cout << cmd << "\n";
            }
            else if (cmd == "access") {
                cout << "var name:";
                getline(cin, cmd);
                cout << "var type:";
                cin >> type;
                if (type == "int") {
                    for (int i = 0; i < varProps.names.size(); i++) {
                        if (varProps.names[i] == cmd) {
                            cout << varProps.intVals[i] << "\n";
                        }
                    }
                }
                else if (type == "char") {
                    for (int i = 0; i < varProps.names.size(); i++) {
                        if (varProps.names[i] == cmd) {
                            cout << varProps.charVals[i] << "\n";
                        }
                    }
                }
                else if (type == "float") {
                    for (int i = 0; i < varProps.names.size(); i++) {
                        if (varProps.names[i] == cmd) {
                            cout << varProps.floatVals[i] << "\n";
                        }
                    }
                }
                else if (type == "string") {
                    for (int i = 0; i < varProps.names.size(); i++) {
                        if (varProps.names[i] == cmd) {
                            cout << varProps.stringVals[i] << "\n";
                        }
                    }
                }
            }
        }
        else if (cmd == "var") {
            cout << "name:";
            getline(cin, name);
            varProps.names.push_back(name);
            cout << "type:";
            cin >> type;
            if (type == "int") {
                cout << "value:";
                cin >> intPush;
                varProps.intVals.push_back(intPush);
            }
            else if (type == "float") {
                cout << "value:";
                cin >> floatPush;
                varProps.floatVals.push_back(floatPush);
            }
            else if (type == "char") {
                cout << "char:";
                cin >> charPush;
                varProps.charVals.push_back(charPush);
            }
            else if (type == "string") {
                cout << "string:";
                cin.ignore();
                getline(cin, stringPush);
                varProps.stringVals.push_back(stringPush);
            }
        }
        else if (cmd == "func") {
            cout << "name:";
            getline(cin, newFname);
            cmd.erase(0, cmd.find_first_not_of(" "));
            cmd.erase(cmd.find_last_not_of(" ") + 1);
            funcProps.names.push_back(newFname);
            while (true) {
                cout << "code:";
                getline(cin, codeBlock);
                if (codeBlock == "endFunc") {
                    break;
                }
                functionCode.push_back(codeBlock);
            }
            funcProps.codes.push_back(functionCode);
        }
        else if (cmd == "callFunc") {
            cout << "name:";
            getline(cin, fName);
            fName.erase(0, fName.find_first_not_of(" "));
            fName.erase(fName.find_last_not_of(" ") + 1);
            for (int i = 0; i < funcProps.names.size(); i++) {
                if (funcProps.names[i] == fName) {
                    for (string line : funcProps.codes[i]) {
                        size_t x = line.find("print ");
                        if (x != std::string::npos) {
                            cout << line.substr(x + 6) << "\n";
                        }
                    }
                }
            }
        }
        else if (cmd == "edit") {
            cout << "func/var:";
            cin >> cmd;
            if (cmd == "var") {
                cout << "name:";
                cin.ignore();
                getline(cin, retrieveVarName);
                cout << "type:";
                cin >> retrieveVarType;
                if (retrieveVarType == "int") {
                    for (int i = 0; i < varProps.names.size(); i++) {
                        if (varProps.names[i] == retrieveVarName) {
                            cout << "new value:";
                            cin.ignore();
                            cin >> intPush;
                            varProps.intVals[i] = intPush;
                        }
                    }
                }
                else if (retrieveVarType == "float") {
                    for (int i = 0; i < varProps.names.size(); i++) {
                        if (varProps.names[i] == retrieveVarName) {
                            cout << "new value:";
                            cin.ignore();
                            cin >> floatPush;
                            varProps.floatVals[i] = floatPush;
                        }
                    }
                }
                else if (retrieveVarType == "char") {
                    for (int i = 0; i < varProps.names.size(); i++) {
                        if (varProps.names[i] == retrieveVarName) {
                            cout << "new char:";
                            cin.ignore();
                            cin >> charPush;
                            varProps.charVals[i] = charPush;
                        }
                    }
                }
                else if (retrieveVarType == "string") {
                    for (int i = 0; i < varProps.names.size(); i++) {
                        if (varProps.names[i] == retrieveVarName) {
                            cout << "new string:";
                            cin.ignore();
                            getline(cin, stringPush);
                            varProps.stringVals[i] = stringPush;
                        }
                    }
                }
            }
            else if (cmd == "func") {
                cout << "name:";
                cin.ignore();
                getline(cin, retrieveFuncName);
                for(int i = 0; i < funcProps.names.size(); i++){
                if(funcProps.names[i] == retrieveFuncName){
                    functionCode.clear();
                while(true){
                cout << "code:";
                getline(cin, codeBlock);
                if(codeBlock == "endFunc"){
                    break;
                }
                functionCode.push_back(codeBlock);
            }
				funcProps.codes[i] = functionCode;
            }
            }
            }
        }
        else {
            cout << cmd << " is not a valid command\n";
        }
    }
} // sheesh. 206 lines of code.
