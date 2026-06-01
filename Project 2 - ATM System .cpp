#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct stClient {
    string AccountNumber = "";
    string PinCode = "";
    string Name = "";
    string Phone = "";
    double AccountBalance = 0.0;

};

const string ClientFile = "Client.txt";
      





stClient  Client;
vector<string > Spliting(string Line, string Del="#//#") {
    vector<string>vLine;
    short pos = 0;
    string s = "";
    while ((pos = Line.find(Del)) != string::npos) {
        s = Line.substr(0, pos);
        vLine.push_back(s);
        Line.erase(0, pos + Del.length());

    }
    if (Line != "") {
        vLine.push_back(Line);
    }
    return vLine;
}

stClient ChangeFromFileToRecord(string Line) {
    vector<string>vsLine = Spliting(Line);
    stClient Client;
    Client.AccountNumber = vsLine[0];
    Client.PinCode = vsLine[1];
    Client.Name = vsLine[2];
    Client.Phone = vsLine[3];
    Client.AccountBalance = stoi(vsLine[4]);
    return Client;

}

vector <stClient> UploadFromFile() {
    fstream MyFile;
    MyFile.open(ClientFile, ios::in);
    string Line = "";
    stClient Client;
    vector<stClient>vsClient;
    if (MyFile.is_open()){
    
        while (getline(MyFile, Line)) {
            Client = ChangeFromFileToRecord(Line);
            vsClient.push_back(Client);
        }

    }
    MyFile.close();
    return vsClient;
}

vector<stClient>vsClient = UploadFromFile();

/////////////////////////////////////////////////////////
string joinTheRecord(stClient Client, string Del="#//#") {
    string Line = "";
    Line += Client.AccountNumber + Del;
    Line += Client.PinCode + Del;
    Line += Client.Name + Del;
    Line += Client.Phone + Del;
    Line += to_string(Client.AccountBalance);
    return Line;

}

void UploadFromRecordToFile() {
    fstream MyFile;
    MyFile.open(ClientFile, ios::out);
    if (MyFile.is_open()) {
        for (stClient& Client : vsClient) {
            MyFile << joinTheRecord(Client)<<endl;
        }
    }
    MyFile.close();
}

void Login();

void Tocontune();

void UploadTheTrans() {
   
    for (stClient & tClient : vsClient) {
        if (tClient.AccountNumber == Client.AccountNumber) {
            tClient.AccountBalance = Client.AccountBalance;
            break;
        }
    }

}
///////////////////////////////////////////////////////////////////
//Quick 

void QuickBannar() {
    cout << "\n===================================================\n";
    cout << "                   Quick Withdraw ";
    cout << "\n===================================================\n";

}

double CanNotCashOu() {
    cout << "\nYour Enter an Execced Amount ................\n";
    return 0.0;
}
double CanInCashOu(int num) {
    Client.AccountBalance -= num;
    cout << "\n\nDone Succefully Your balance is : " << Client.AccountBalance << "\n\n";
    UploadTheTrans();
    UploadFromRecordToFile();

    return 0.0;
}
bool canQuick(int Num) {
    if (Num <= Client.AccountBalance)return false;
    return true;
}

void QuickWithdraw(short Num) {
    switch (Num) {
    case 1: {
        canQuick(20) ? CanNotCashOu() : CanInCashOu(20);    break;
    }
    case 2: {
        canQuick(50) ? CanNotCashOu() : CanInCashOu(50);        break;
    }
    case 3: {
        canQuick(100) ? CanNotCashOu() : CanInCashOu(100);       break;
    }
    case 4: {
        canQuick(200) ? CanNotCashOu() : CanInCashOu(200);       break;
    }
    case 5: {
        canQuick(400) ? CanNotCashOu() : CanInCashOu(400);       break;
    }
    case 6: {
        canQuick(600) ? CanNotCashOu() : CanInCashOu(600);      break;
    }
    case 7: {
        canQuick(800) ? CanNotCashOu() : CanInCashOu(800);       break;
    }
    case 8: {
        canQuick(1000) ? CanNotCashOu() : CanInCashOu(1000);     break;
    }
    case 9: {
        Tocontune();
    }
    }
}

void DisplayQuickMenue() {
    QuickBannar();
    short Choice=0;
    char is = 'y';
    cout << "[1] 20         [2] 50\n";
    cout << "[3] 100        [4] 200\n";
    cout << "[5] 400        [6] 600\n";
    cout << "[7] 800        [8] 1000\n";
    cout << "[9] Exist\n";
    cout << "=====================================\n";
    cout << "Your Balance  is " << Client.AccountBalance<<"\n\n";
    cout << "Choose What to Withdraw From [1] to [8]  : ";
    cin >> Choice;
    cout << "\n\n\t\tAre You Want To Perform The Transaction (y/n)  ?  ";
    cin >> is;
    if (tolower(is) == 'y') {
        cout << "\n\n";
        QuickWithdraw(Choice);
        
    }

}

/////////////////////////////////////////////////////////////////////////
//Normal 
void NormalBannar() {
    cout << "\n===================================================\n";
    cout << "                   Normal Withdraw ";
    cout << "\n===================================================\n";

}

bool IsMultipleOf5(int num) {
    return (num % 5) == 0;
}

void NormalTake() {
    int num = 0;
    do {
        cout << "\nEnter Multiple Of 5 : ";
        cin >> num;

    } while (!IsMultipleOf5(num));
    if (!canQuick((num))) {
        Client.AccountBalance -= num;
        cout << "\n\nYou Sucssefully Withdraw . \n ";
        cout << "\nYour Current Value is " << Client.AccountBalance<<endl;
        UploadTheTrans();
        UploadFromRecordToFile();

    }
    else {
      
            cout << "\nYour Enter an Execced Amount ................\n\n\n\n";
        }

}
/////////////////////////////////////////////////////////////////////////////
// deposite 
int AskMoney() {
    int num = 0;
    cout << "\n\t\tEnter a Postive Number :  ";
    cin >> num;
    while (num < 0) {
        cout << "\n\t\tEnter a Postive Number :  ";
        cin >> num;
    }
    return num;
}
void Deposit() {
    cout << "\n======================================================\n";
    cout << "                          Deposite Menue         ";
    cout << "\n======================================================\n";
    Client.AccountBalance += AskMoney();
    UploadTheTrans();
    UploadFromRecordToFile();
    cout << "\n\nYou Add Secssfuly Ypur Balance is  :" << Client.AccountBalance<<endl;

}
///////////////////////////////////////////////////////////////////
// check
void CheckBalance() {
    cout << "\n======================================================\n";
    cout << "                    Check Balance ";
    cout << "\n======================================================\n";
    cout << "\tYour Current Balance is :  " << Client.AccountBalance<<endl;

}
///////////////////////////////////////////////////////////////////

//Main Menue 
void SelectOptions(int Num) {
    switch (Num) {
    case 1: {
        system("cls");
        DisplayQuickMenue();
        Tocontune();
    }
    case 2: {
        system("cls");
        NormalTake();
        Tocontune();
    }
    case 3: {
        system("cls");
        Deposit();
        Tocontune();
    }
    case 4: {
        system("cls");
        CheckBalance();
        Tocontune();
    }case 5: {
        Login();
    }
    }
}

void MainMenueScreen() {
    int num = 0;
    cout << "=================================================\n";
    cout << "             ATM Main Menue Screen \n";
    cout << "=================================================\n";
    cout << "\t\t[1] Quick Withdrw.\n";
    cout << "\t\t[2] Normal Withdrw.\n";
    cout << "\t\t[3] Deposite.\n";
    cout << "\t\t[4] Check Balance.\n ";
    cout << "\t\t[5] Logout.\n";
    cout << "=================================================\n";
    cout << "Chooise What Do You Want To Do [1 to 5] ?";
    cin >> num;
    SelectOptions(num);



}

void Tocontune() {
    system("pause");
    system("cls");
    MainMenueScreen();
}
bool CheckClient(string Name, string Pass) {
    vector<stClient>vsClient = UploadFromFile();
    for (stClient& Client1 : vsClient) {
        if (Client1.AccountNumber == Name && Client1.PinCode == Pass) {

            Client = Client1;
            return true;
        }
    }
    return false;
}
void Login() {
   
    stClient Client1;
    do {
        system("cls");
        cout << "===================================\n";
        cout << "            Login Screen      \n";
        cout << "===================================\n";
        cout << "\nEnter Yor Account Number : ";
        cin >> Client1.AccountNumber;
        cout << "\nEnter Your Password : ";
        cin >> Client1.PinCode;

        if (!CheckClient(Client1.AccountNumber, Client1.PinCode)) {
          cout<<"\nInValid Acc/Pass ------------------ \n";
          system("pause");
        }
        else {
            system("cls");
            MainMenueScreen();
        }
    }while(!CheckClient(Client1.AccountNumber,Client1.PinCode));
    
}
int main()
{
    Login();
}
